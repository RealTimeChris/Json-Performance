# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 25.4.0 using the Clang 22.1.8 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [0b08cd8](https://github.com/RealTimeChris/Jsonifier/commit/0b08cd8)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Both libraries are executing only 'stage-1' parsing, where they identify the structural indices, and neither of them are performing utf-8 validation in these tests. Adaptive sampling on (Apple M1 (Virtual)): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7503.84 | 0.326416 | 5.46958ms | 33713 | 30 | 5868.03 | 4284.63 | 1(Win) |
| simdjson | 6595.21 | 0.129852 | 1.44346ms | 33713 | 30 | 1202.13 | 4874.93 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7359.96 | 0.0565821 | 16.7804ms | 49505 | 128 | 1686.22 | 6414.66 | 1(Win) |
| simdjson | 7023.28 | 0.176712 | 1.73113ms | 49505 | 30 | 4233.25 | 6722.17 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7447.87 | 2.3444 | 1.13296ms | 33713 | 30 | 307266 | 4316.83 | 1(Win) |
| simdjson | 6635.18 | 0.0842501 | 1.26025ms | 33713 | 30 | 499.978 | 4845.57 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7280.93 | 0.260654 | 1.67217ms | 48024 | 30 | 8064.77 | 6290.3 | 1(Win) |
| simdjson | 6855.59 | 0.196704 | 1.73063ms | 48024 | 30 | 5180.53 | 6680.57 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 6468.1 | 1.98418 | 3.47871ms | 94651 | 30 | 2.30027e+06 | 13955.6 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 6371.73 | 2.27779 | 3.51229ms | 94651 | 30 | 3.1238e+06 | 14166.7 | 1(Tie) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 7123.45 | 0.147856 | 4.73058ms | 140436 | 30 | 23183.4 | 18801.3 | 1(Win) |
| jsonifier | 6473.1 | 1.30266 | 5.20688ms | 140436 | 30 | 2.17929e+06 | 20690.3 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5176.92 | 0.100691 | 93.036ms | 2090234 | 30 | 4.50969e+06 | 385056 | 1(Win) |
| simdjson | 4497.19 | 0.21803 | 107.137ms | 2090234 | 30 | 2.80196e+07 | 443256 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 7724.98 | 0.10959 | 209.395ms | 6885124 | 30 | 2.60309e+07 | 849992 | 1(Win) |
| jsonifier | 7099.82 | 0.143004 | 218.522ms | 6885124 | 30 | 5.24743e+07 | 924836 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4817.32 | 0.307125 | 24.7991ms | 500299 | 30 | 2.77588e+06 | 99043.1 | 1(Win) |
| simdjson | 4355.18 | 1.90454 | 25.699ms | 500299 | 30 | 1.30602e+08 | 109553 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6329.99 | 0.368605 | 54.0649ms | 1490030 | 30 | 2.05413e+07 | 224488 | 1(Win) |
| simdjson | 6157.49 | 0.193817 | 55.6077ms | 1490030 | 30 | 6.00186e+06 | 230776 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5553.17 | 0.240116 | 2.47329ms | 56369 | 30 | 16209.2 | 9680.53 | 1(Win) |
| simdjson | 5146.98 | 0.0440355 | 2.61867ms | 56369 | 30 | 634.603 | 10444.5 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 6752.72 | 0.0417832 | 3.44825ms | 98048 | 30 | 1004.26 | 13847.1 | 1(Win) |
| jsonifier | 5889.09 | 1.07537 | 3.97679ms | 98048 | 30 | 874610 | 15877.8 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8219.71 | 0.230719 | 1.59083ms | 52708 | 30 | 5972.09 | 6115.33 | 1(Win) |
| simdjson | 7053.53 | 0.0441061 | 1.79979ms | 52708 | 30 | 296.386 | 7126.4 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7638.8 | 0.243404 | 2.29712ms | 71665 | 30 | 14227.9 | 8947.1 | 1(Win) |
| simdjson | 7556.53 | 0.0438453 | 2.25383ms | 71665 | 30 | 471.776 | 9044.5 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4865.61 | 0.497924 | 1.44817ms | 11812 | 32 | 4252.54 | 2315.19 | 1(Win) |
| simdjson | 4422.31 | 0.65069 | 0.710416ms | 11812 | 30 | 8241.72 | 2547.27 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 6501.97 | 0.281254 | 1.26271ms | 32403 | 30 | 5360.42 | 4752.7 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 6397.12 | 2.27797 | 1.45296ms | 32403 | 30 | 363263 | 4830.6 | 1(Tie) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4942.06 | 1.49959 | 5.03908ms | 108313 | 30 | 2.94721e+06 | 20901.3 | 1(Win) |
| simdjson | 4671.35 | 0.115098 | 5.53508ms | 108313 | 30 | 19432.7 | 22112.5 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 5838.38 | 1.68327 | 8.62742ms | 222373 | 30 | 1.12152e+07 | 36323.7 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 5672.24 | 0.11335 | 9.21012ms | 222373 | 30 | 53878.5 | 37387.6 | 1(Tie) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3284.31 | 0.268684 | 128.515ms | 1834197 | 30 | 6.14342e+07 | 532601 | 1(Win) |
| simdjson | 3239.8 | 0.355218 | 131.819ms | 1834197 | 30 | 1.10349e+08 | 539918 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7446.04 | 0.0540591 | 318.091ms | 10252236 | 30 | 1.51163e+07 | 1.31309e+06 | 1(Win) |
| simdjson | 6579.74 | 0.242977 | 361.703ms | 10252236 | 30 | 3.91085e+08 | 1.48597e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4770.56 | 0.155015 | 31.1993ms | 642697 | 30 | 1.19e+06 | 128481 | 1(Win) |
| simdjson | 4161.8 | 0.463832 | 35.614ms | 642697 | 30 | 1.39988e+07 | 147274 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 6882.95 | 0.132329 | 43.6082ms | 1306201 | 30 | 1.72068e+06 | 180982 | 1(Win) |
| jsonifier | 6753.54 | 0.749847 | 45.281ms | 1306201 | 30 | 5.73883e+07 | 184450 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5893.6 | 0.383939 | 16.5323ms | 409725 | 30 | 1.94388e+06 | 66299.8 | 1(Win) |
| simdjson | 5367.98 | 0.2252 | 17.6503ms | 409725 | 30 | 806161 | 72791.7 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 6033.22 | 0.197583 | 31.1936ms | 814756 | 30 | 1.94257e+06 | 128789 | 1(Win) |
| jsonifier | 5699.18 | 0.334636 | 32.9891ms | 814756 | 30 | 6.2445e+06 | 136338 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7567.8 | 0.0974854 | 8.26704ms | 264040 | 30 | 31564.7 | 33273.6 | 1(Win) |
| simdjson | 6603.61 | 0.444279 | 9.303ms | 264040 | 30 | 861014 | 38131.9 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7240.79 | 0.183414 | 13.0626ms | 399947 | 30 | 280040 | 52676.4 | 1(Win) |
| simdjson | 7040.67 | 0.867897 | 13.3879ms | 399947 | 30 | 6.63185e+06 | 54173.7 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7169.71 | 2.35147 | 19.6832ms | 264040 | 32 | 2.18256e+07 | 35121.1 | 1(Win) |
| simdjson | 6294.78 | 0.692233 | 22.8751ms | 264040 | 32 | 2.45377e+06 | 40002.7 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 7204.72 | 0.886742 | 14.212ms | 409612 | 30 | 6.93469e+06 | 54219.5 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 7091.92 | 0.560386 | 13.7044ms | 409612 | 30 | 2.85834e+06 | 55081.9 | 1(Tie) |
