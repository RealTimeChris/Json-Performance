# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.26200 using the MSVC 19.44.35228.0 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [0b08cd8](https://github.com/RealTimeChris/Jsonifier/commit/0b08cd8)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Both libraries are executing only 'stage-1' parsing, where they identify the structural indices, and neither of them are performing utf-8 validation in these tests. Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13176.7 | 0.372835 | 1.8028ms | 33713 | 30 | 2482.76 | 2440 | 1(Win) |
| simdjson | 12591.9 | 0.362824 | 1.9545ms | 33713 | 30 | 2574.71 | 2553.33 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13657.8 | 0.276266 | 2.4431ms | 48024 | 30 | 2574.71 | 3353.33 | 1(Win) |
| simdjson | 13536.7 | 0.204546 | 2.0957ms | 48024 | 30 | 1436.78 | 3383.33 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13377.8 | 0.138696 | 2.0922ms | 33713 | 30 | 333.333 | 2403.33 | 1(Win) |
| simdjson | 12287.1 | 0.264476 | 1.9121ms | 33713 | 30 | 1436.78 | 2616.67 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 13510.1 | 1.16071 | 2.2694ms | 48024 | 30 | 46448.3 | 3390 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 13495.2 | 0.128105 | 3.7492ms | 48024 | 32 | 604.839 | 3393.75 | 1(Tie) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14118.8 | 0.166571 | 3.3198ms | 94651 | 30 | 3402.3 | 6393.33 | 1(Win) |
| simdjson | 12821.9 | 0.551613 | 3.1654ms | 94651 | 30 | 45241.4 | 7040 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14519.5 | 0.0954797 | 6.9485ms | 136024 | 32 | 2328.63 | 8934.38 | 1(Win) |
| simdjson | 13743.2 | 1.44137 | 14.1291ms | 136024 | 64 | 1.18464e+06 | 9439.06 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10714.5 | 1.00872 | 47.2214ms | 2090234 | 30 | 1.05658e+08 | 186047 | 1(Win) |
| simdjson | 9684.23 | 0.830273 | 51.1443ms | 2090234 | 30 | 8.76239e+07 | 205840 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16520 | 0.744671 | 95.355ms | 6661897 | 30 | 2.4605e+08 | 384580 | 1(Win) |
| simdjson | 14701.9 | 0.816724 | 105.73ms | 6661897 | 30 | 3.73698e+08 | 432140 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 9678.59 | 0.881297 | 13.332ms | 500299 | 30 | 5.6624e+06 | 49296.7 | 1(Win) |
| jsonifier | 9148.45 | 2.27358 | 13.9026ms | 500299 | 30 | 4.21798e+07 | 52153.3 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13339.7 | 1.15463 | 26.4668ms | 1439562 | 30 | 4.23621e+07 | 102917 | 1(Win) |
| simdjson | 12901.3 | 0.725157 | 27.6358ms | 1439562 | 30 | 1.7864e+07 | 106413 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10971 | 0.13838 | 2.8745ms | 56369 | 30 | 1379.31 | 4900 | 1(Win) |
| simdjson | 10589.2 | 0.154708 | 2.9386ms | 56369 | 30 | 1850.57 | 5076.67 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 12851.2 | 0.119682 | 5.869ms | 94370 | 32 | 2247.98 | 7003.12 | 1(Win) |
| simdjson | 12669.9 | 0.158058 | 3.2254ms | 94370 | 30 | 3781.61 | 7103.33 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14907.5 | 0.239488 | 3.8396ms | 52708 | 32 | 2086.69 | 3371.88 | 1(Win) |
| simdjson | 13784.2 | 0.254043 | 2.3321ms | 52708 | 30 | 2574.71 | 3646.67 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14934.2 | 0.205552 | 2.3256ms | 70103 | 30 | 2540.23 | 4476.67 | 1(Win) |
| simdjson | 14618.5 | 0.179557 | 2.3096ms | 70103 | 30 | 2022.99 | 4573.33 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10013.2 | 0.484929 | 4.921ms | 11812 | 64 | 1904.76 | 1125 | 1(Win) |
| simdjson | 9574.33 | 0.453606 | 3.8695ms | 11812 | 64 | 1822.92 | 1176.56 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 13540 | 0.435876 | 1.9725ms | 31235 | 30 | 2758.62 | 2200 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 13258.8 | 1.6494 | 2.434ms | 31235 | 30 | 41195.4 | 2246.67 | 1(Tie) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10469.1 | 0.657969 | 3.6763ms | 108313 | 30 | 126437 | 9866.67 | 1(Win) |
| simdjson | 9936.72 | 1.72299 | 15.1951ms | 108313 | 64 | 2.05315e+06 | 10395.3 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13301.3 | 0.082056 | 10.763ms | 213963 | 32 | 5070.56 | 15340.6 | 1(Win) |
| simdjson | 12999.6 | 0.107923 | 5.4716ms | 213963 | 30 | 8609.2 | 15696.7 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 6843.7 | 0.870019 | 62.9811ms | 1834197 | 30 | 1.48351e+08 | 255597 | 1(Win) |
| jsonifier | 6089.21 | 0.595231 | 71.7102ms | 1834197 | 30 | 8.77126e+07 | 287267 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13893.9 | 0.520472 | 164.065ms | 9930848 | 30 | 3.7761e+08 | 681653 | 1(Win) |
| simdjson | 12378.6 | 1.27996 | 188.376ms | 9930848 | 30 | 2.87704e+09 | 765093 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10409.1 | 1.09952 | 16.2728ms | 642697 | 30 | 1.25752e+07 | 58883.3 | 1(Win) |
| simdjson | 9668.07 | 0.914502 | 17.406ms | 642697 | 30 | 1.00838e+07 | 63396.7 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 12636 | 1.70894 | 23.1145ms | 1225964 | 30 | 7.50082e+07 | 92526.7 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 12416 | 0.903037 | 24.4092ms | 1225964 | 30 | 2.16933e+07 | 94166.7 | 1(Tie) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 10674.1 | 0.881441 | 10.1882ms | 409725 | 30 | 3.1234e+06 | 36606.7 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 10666.1 | 2.32568 | 22.3233ms | 409725 | 32 | 2.32288e+07 | 36634.4 | 1(Tie) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13474.3 | 0.781923 | 15.098ms | 785750 | 30 | 5.67292e+06 | 55613.3 | 1(Win) |
| simdjson | 12604.7 | 0.793315 | 16.4189ms | 785750 | 30 | 6.67293e+06 | 59450 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 13830.9 | 0.572011 | 12.7497ms | 264040 | 32 | 347056 | 18206.2 | 1(Win) |
| simdjson | 12353.6 | 1.18574 | 6.4628ms | 264040 | 30 | 1.75247e+06 | 20383.3 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14195 | 1.57806 | 7.9659ms | 399947 | 30 | 5.3939e+06 | 26870 | 1(Win) |
| simdjson | 13293 | 1.59865 | 8.2556ms | 399947 | 30 | 6.31237e+06 | 28693.3 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14012.7 | 1.57242 | 6.1506ms | 264040 | 30 | 2.39528e+06 | 17970 | 1(Win) |
| simdjson | 12605.1 | 1.49188 | 6.1434ms | 264040 | 30 | 2.66461e+06 | 19976.7 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json/C:/Users/Chris/source/repos/Json-Performance/json/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 14071 | 1.3817 | 8.2991ms | 399947 | 30 | 4.20823e+06 | 27106.7 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 13560.8 | 1.49427 | 8.4986ms | 399947 | 30 | 5.29926e+06 | 28126.7 | 1(Tie) |
