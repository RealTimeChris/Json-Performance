$ErrorActionPreference = "Continue"

$CompilerTag  = "Windows-MSVC"
$CsvPath      = ".\csv\$CompilerTag\Results.csv"
$SweepDir     = ".\sweep_results\$CompilerTag"
$SummaryFile  = "$SweepDir\summary.txt"

New-Item -ItemType Directory -Force -Path $SweepDir | Out-Null
Set-Content -Path $SummaryFile -Value ""

$Results = @{}
$CurrentCpu = "Unknown CPU"

function Print-Leaderboard {
    Write-Host ""
    Write-Host "================================================================"
    Write-Host " LIVE LEADERBOARD for $($script:CurrentCpu) (sorted by Wins desc, Losses asc)"
    Write-Host "================================================================"
    Write-Host ("{0,-40}  {1,6}  {2,6}  {3,6}" -f "CONFIG", "WINS", "TIES", "LOSSES")
    Write-Host "--------------------------------------------------------------------------------"

    $Sorted = $script:Results.GetEnumerator() | Sort-Object `
        @{ Expression = { $_.Value.Wins   }; Descending = $true  }, `
        @{ Expression = { $_.Value.Losses }; Descending = $false }

    foreach ($Entry in $Sorted) {
        Write-Host ("{0,-40}  {1,6}  {2,6}  {3,6}" -f `
            $Entry.Key, $Entry.Value.Wins, $Entry.Value.Ties, $Entry.Value.Losses)
    }
}

function Invoke-Config {
    param([int]$TapeMax, [int]$TapeStep, [int]$BlocksPerStep)

    $Key = "MAX=${TapeMax}_STEP=${TapeStep}_BLOCKS=${BlocksPerStep}"

    Write-Host ""
    Write-Host "================================================================"
    Write-Host " CONFIG: TAPE_MAX=$TapeMax  TAPE_STEP=$TapeStep  BLOCKS_PER_STEP=$BlocksPerStep$(if ($script:CurrentCpu -ne 'Unknown CPU') { " | CPU=$($script:CurrentCpu)" })"
    Write-Host "================================================================"

    if (Test-Path .\Build) {
        Remove-Item -Recurse -Force .\Build
    }

    $CmakeArgs = @(
        "-S", ".",
        "-B", ".\Build",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DCMAKE_INSTALL_PREFIX=.\Install",
        "-DJSONIFIER_TAPE_MAX=$($TapeMax)",
        "-DJSONIFIER_TAPE_STEP=$($TapeStep)",
        "-DJSONIFIER_BLOCKS_PER_STEP=$($BlocksPerStep)"
    )
    Write-Host "Running: cmake $($CmakeArgs -join ' ')"
    & cmake @CmakeArgs

    if ($LASTEXITCODE -ne 0) {
        Write-Host "[!] CMake configure failed for $Key, skipping."
        $script:Results[$Key] = @{ Wins = -1; Ties = -1; Losses = -1 }
        Print-Leaderboard
        return
    }

    cmake --build .\Build --config=Release --parallel -v

    if ($LASTEXITCODE -ne 0) {
        Write-Host "[!] Build failed for $Key, skipping."
        $script:Results[$Key] = @{ Wins = -1; Ties = -1; Losses = -1 }
        Print-Leaderboard
        return
    }

    cmake --install .\Build --config=Release

    $BinPath = ".\Install\bin\Json-Performance.exe"
    if (-not (Test-Path $BinPath)) {
        $BinPath = ".\Build\Release\Json-Performance.exe"
    }
    if (-not (Test-Path $BinPath)) {
        $BinPath = ".\Build\Json-Performance.exe"
    }

    & $BinPath

    if (-not (Test-Path $CsvPath)) {
        Write-Host "[!] Results.csv not found at $CsvPath for $Key"
        $script:Results[$Key] = @{ Wins = -1; Ties = -1; Losses = -1 }
        Print-Leaderboard
        return
    }

    Copy-Item $CsvPath "$SweepDir\Results_$Key.csv" -Force

    $Lines = Get-Content $CsvPath

    if ($script:CurrentCpu -eq "Unknown CPU") {
        foreach ($Line in $Lines) {
            if ($Line -match "^#\*\*CPU:\*\*\s*(.*)") {
                $script:CurrentCpu = $Matches[1].Trim()
                if (-not (Select-String -Path $SummaryFile -Pattern "^# CPU:" -Quiet)) {
                    Add-Content -Path $SummaryFile -Value "# CPU: $($script:CurrentCpu)"
                }
                break
            }
        }
    }

    $Wins = 0; $Ties = 0; $Losses = 0
    foreach ($Line in $Lines) {
        if ($Line -match "^#")        { continue }
        if ($Line -match "^Library") { continue }
        $Parts = $Line -split ","
        if ($Parts.Length -ge 4 -and $Parts[0].Trim() -eq "jsonifier") {
            $Wins   = [int]$Parts[1]
            $Ties   = [int]$Parts[2]
            $Losses = [int]$Parts[3]
            $break
        }
    }

    $script:Results[$Key] = @{ Wins = $Wins; Ties = $Ties; Losses = $Losses }

    Write-Host ""
    Write-Host ">>> $Key`: Wins=$Wins Ties=$Ties Losses=$Losses$(if ($script:CurrentCpu -ne 'Unknown CPU') { " | CPU=$($script:CurrentCpu)" })"
    Add-Content -Path $SummaryFile -Value "$Key,$Wins,$Ties,$Losses"

    Print-Leaderboard
}

$BlockValues   = @(8, 4, 2)
$TapeStepValues = @(8, 4, 2, 1)

$StepCount = $TapeStepValues.Length
$BlockCount = $BlockValues.Length

for ($i = 0; $i -lt $BlockCount; $i += 1) {
    for ($j = 0; $j -lt $StepCount; $j += 1) {        
        $TapeMax = 1
        $BlocksPerStep = $BlockValues[$i]
    
        $TapeStep = $TapeStepValues[$j]
        Invoke-Config $TapeMax $TapeStep $BlocksPerStep
    }
}

Write-Host ""
Write-Host "Sweep finished.$(if ($script:CurrentCpu -ne 'Unknown CPU') { " CPU: $($script:CurrentCpu)" })"
Write-Host "Per-config CSVs saved to: $SweepDir\"
Write-Host "Summary CSV: $SummaryFile"