param(
    [Parameter(Mandatory = $false)]
    [string]$Project,

    [Parameter(Mandatory = $false)]
    [ValidateSet("main", "stage-1-parsing-main", "full-parsing-utf8-main", "correctness-validation-main")]
    [string]$Branch,

    [Parameter(Mandatory = $false)]
    [string]$CsvPath = ".\csv",

    [Parameter(Mandatory = $false)]
    [string]$RepoRoot = ".",

    [Parameter(Mandatory = $false)]
    [string[]]$CorrectnessFiles = @(
        "macOS-Clang.md",
        "macOS-GCC.md",
        "Linux-Clang.md",
        "Linux-GCC.md",
        "Windows-MSVC.md"
    ),

    [Parameter(Mandatory = $false)]
    [string]$KeyPath = "$env:USERPROFILE\downloads\NihilusKey.pem",

    [Parameter(Mandatory = $false)]
    [string]$RemoteHost = "ubuntu@18.217.89.240",

    [Parameter(Mandatory = $false)]
    [string]$RemoteRoot = "/var/www/html/csv-data"
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path $KeyPath)) {
    Write-Error "SSH key not found at '$KeyPath'. Pass -KeyPath explicitly if it's somewhere else."
    exit 1
}

if (-not $Project) {

    $folderName = Split-Path -Leaf (Resolve-Path $RepoRoot)

    $repoToProjectMap = @{
        "json-performance"     = "jsonifier"
        "stringint-benchmarks" = "void-numerics"
        "rtc-digit-count"      = "rtc-digit-count"
    }

    if ($repoToProjectMap.ContainsKey($folderName)) {
        $Project = $repoToProjectMap[$folderName]
        Write-Host "Auto-detected project from folder name '$folderName': $Project"
    } else {
        $validNames = $repoToProjectMap.Keys -join ', '
        Write-Error "Folder name '$folderName' does not match a known repo ($validNames). Pass -Project explicitly to override."
        exit 1
    }

} else {
    Write-Host "Using explicitly provided project: $Project"
}

if (-not $Branch) {

    $gitDir = Join-Path $RepoRoot ".git"
    if (-not (Test-Path $gitDir)) {
        Write-Error "No .git folder found under '$RepoRoot' and -Branch was not supplied. Either run this from inside the repo, pass -RepoRoot, or pass -Branch explicitly."
        exit 1
    }

    $headPath = Join-Path $gitDir "HEAD"
    if (-not (Test-Path $headPath)) {
        Write-Error "Found '$gitDir' but no HEAD file inside it - is this a valid git repo?"
        exit 1
    }

    $headContent = Get-Content $headPath -Raw

    if ($headContent -match '^ref:\s*refs/heads/(.+?)\s*$') {
        $detectedBranch = $Matches[1]
    } else {
        Write-Error "HEAD is detached (not pointing at a branch ref). Checked out a commit directly? Pass -Branch explicitly."
        exit 1
    }

    $validBranches = @("main", "stage-1-parsing-main", "full-parsing-utf8-main", "correctness-validation-main")
    if ($validBranches -notcontains $detectedBranch) {
        Write-Error "Detected git branch '$detectedBranch' is not one of the valid options ($($validBranches -join ', ')). Checkout the right branch, or pass -Branch explicitly to override."
        exit 1
    }

    $Branch = $detectedBranch
    Write-Host "Auto-detected branch from .git: $Branch"

} else {
    Write-Host "Using explicitly provided branch: $Branch"
}

if ($Branch -eq "correctness-validation-main") {

    Write-Host "Pushing correctness-validation-main .md files..."

    $correctnessRemoteDir = "$RemoteRoot/$Project/correctness-validation-main"
    $missing = @()
    $foundFiles = @()

    foreach ($fileName in $CorrectnessFiles) {
        $localFilePath = Join-Path $RepoRoot $fileName
        if (Test-Path $localFilePath) {
            $foundFiles += $localFilePath
        } else {
            $missing += $fileName
        }
    }

    if ($missing.Count -gt 0) {
        Write-Warning "Missing correctness files (skipped): $($missing -join ', ')"
    }

    if ($foundFiles.Count -eq 0) {
        Write-Error "No correctness .md files found under '$RepoRoot' - nothing to push."
        exit 1
    }

    Write-Host "Ensuring remote directory '$correctnessRemoteDir' exists..."
    ssh -i $KeyPath $RemoteHost "mkdir -p '$correctnessRemoteDir'"

    foreach ($filePath in $foundFiles) {
        $fileName = Split-Path $filePath -Leaf
        Write-Host "  Uploading $fileName..."
        scp -i $KeyPath $filePath "${RemoteHost}:${correctnessRemoteDir}/$fileName"
    }

    Write-Host "Done. $($foundFiles.Count) correctness file(s) pushed to $RemoteHost`:$correctnessRemoteDir"

} else {

    if (-not (Test-Path $CsvPath)) {
        Write-Error "CSV folder not found at '$CsvPath'. Run this from the repo root, or pass -CsvPath explicitly."
        exit 1
    }

    if ($Project -eq "void-numerics") {
        Write-Host "Generating bench-data.json for each platform folder under '$CsvPath'..."

        $platformDirs = Get-ChildItem -Path $CsvPath -Directory
        foreach ($platformDir in $platformDirs) {

            $subDirs = Get-ChildItem -Path $platformDir.FullName -Directory

            $typesObj = [ordered]@{}

            foreach ($subDir in $subDirs) {

                $resultsPath = Join-Path $subDir.FullName "Results.csv"
                $wtl = $null
                if (Test-Path -LiteralPath $resultsPath) {
                    $rawLines = Get-Content -LiteralPath $resultsPath
                    $headerLineIdx = -1
                    for ($i = 0; $i -lt $rawLines.Count; $i++) {
                        if ($rawLines[$i] -match '^Library,') {
                            $headerLineIdx = $i
                            break
                        }
                    }
                    if ($headerLineIdx -ge 0) {
                        $csvLines = $rawLines[$headerLineIdx..($rawLines.Count - 1)]
                        $resultsRows = $csvLines | ConvertFrom-Csv
                        $vnRow = $resultsRows | Where-Object { $_.Library -like "vn::*" } | Select-Object -First 1
                        if ($vnRow) {
                            $wtl = [ordered]@{
                                wins   = [int]$vnRow.Wins
                                ties   = [int]$vnRow.Ties
                                losses = [int]$vnRow.Losses
                            }
                        }
                    }
                }

                $testFiles = Get-ChildItem -Path $subDir.FullName -Filter "*.csv" -File | Where-Object { $_.Name -ne "Results.csv" }

                $tests = @()
                foreach ($testFile in $testFiles) {
                    $rows = Import-Csv -LiteralPath $testFile.FullName
                    $testName = [System.IO.Path]::GetFileNameWithoutExtension($testFile.Name)

                    $parsedRows = @()
                    foreach ($row in $rows) {
                        $parsedRows += [ordered]@{
                            lib           = $row.Library
                            throughput    = [double]$row.'Throughput (MB/s)'
                            rse           = [double]$row.'RSE (%)'
                            cyclesPerByte = if ($row.'Cycles/Byte') { [double]$row.'Cycles/Byte' } else { $null }
                            position      = $row.Position
                        }
                    }

                    $tests += [ordered]@{
                        name = $testName
                        rows = $parsedRows
                    }
                }

                $typesObj[$subDir.Name] = [ordered]@{
                    wtl   = $wtl
                    tests = $tests
                }
            }

            $benchData = [ordered]@{
                project      = "void-numerics"
                platform     = $platformDir.Name
                generatedAt  = (Get-Date).ToUniversalTime().ToString("o")
                types        = $typesObj
            }

            $benchDataPath = Join-Path $platformDir.FullName "bench-data.json"
            $benchJson = ConvertTo-Json -InputObject $benchData -Depth 10
            $utf8NoBom = New-Object System.Text.UTF8Encoding($false)
            [System.IO.File]::WriteAllText($benchDataPath, $benchJson, $utf8NoBom)
            Write-Host "  $($platformDir.Name): $($subDirs.Count) sub-benchmark(s) -> bench-data.json"
        }
    } else {
        Write-Host "Generating manifest.json for each platform folder under '$CsvPath'..."

        $platformDirs = Get-ChildItem -Path $CsvPath -Directory
        foreach ($platformDir in $platformDirs) {
            $csvFiles = Get-ChildItem -Path $platformDir.FullName -Filter "*.csv" -File | Select-Object -ExpandProperty Name
            $manifestPath = Join-Path $platformDir.FullName "manifest.json"
            $manifestJson = ConvertTo-Json -InputObject @($csvFiles)
            $utf8NoBom = New-Object System.Text.UTF8Encoding($false)
            [System.IO.File]::WriteAllText($manifestPath, $manifestJson, $utf8NoBom)
            Write-Host "  $($platformDir.Name): $($csvFiles.Count) csv file(s) -> manifest.json"
        }
    }

    $remoteDir = "$RemoteRoot/$Project/$Branch"
    $tarName   = "csv-push-$Project-$Branch-$(Get-Date -Format 'yyyyMMdd-HHmmss').tar.gz"
    $tarPath   = Join-Path $env:TEMP $tarName

    Write-Host "Packing '$CsvPath' into '$tarPath'..."

    tar -czf $tarPath -C $CsvPath .

    if (-not (Test-Path $tarPath)) {
        Write-Error "Tar creation failed - '$tarPath' was not produced."
        exit 1
    }

    Write-Host "Ensuring remote directory '$remoteDir' exists..."
    ssh -i $KeyPath $RemoteHost "mkdir -p '$remoteDir'"

    Write-Host "Uploading archive to server..."
    $remoteTarPath = "/tmp/$tarName"
    scp -i $KeyPath $tarPath "${RemoteHost}:${remoteTarPath}"

    Write-Host "Extracting on server into '$remoteDir'..."
    ssh -i $KeyPath $RemoteHost "rm -rf '$remoteDir' && mkdir -p '$remoteDir' && tar -xzf '$remoteTarPath' -C '$remoteDir'"
    ssh -i $KeyPath $RemoteHost "rm -f '$remoteTarPath'"

    Write-Host "Aggregating stats server-side..."
    ssh -i $KeyPath $RemoteHost "node /var/www/html/aggregate-stats.js"

    Write-Host "Cleaning up local temp archive..."
    Remove-Item $tarPath -Force

    Write-Host "Done. '$CsvPath' pushed to $RemoteHost`:$remoteDir"
}