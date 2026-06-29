# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 24.6.0 using the GCC 16.1.0 compiler).  

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

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7358.83 | 2.26381 | 5.43309ms | 33713 | 30 | 293481 | 4369.07 | 1(Win) |
| simdjson | 6117.05 | 1.49907 | 12.34ms | 33713 | 32 | 198656 | 5256 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6907.13 | 1.07969 | 2.24102ms | 49505 | 30 | 163388 | 6835.2 | 1(Win) |
| simdjson | 6410.91 | 1.30903 | 3.40582ms | 49505 | 30 | 278792 | 7364.27 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7358.83 | 2.19298 | 4.02099ms | 33713 | 30 | 275402 | 4369.07 | 1(Win) |
| simdjson | 6126.38 | 1.38527 | 3.95392ms | 33713 | 32 | 169125 | 5248 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6675.5 | 1.56375 | 4.384ms | 48024 | 30 | 345307 | 6860.8 | 1(Win) |
| simdjson | 6389.41 | 0.937903 | 2.20698ms | 48024 | 30 | 135592 | 7168 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7715.59 | 0.757646 | 3.88787ms | 94651 | 30 | 235704 | 11699.2 | 1(Win) |
| simdjson | 6135.55 | 0.703118 | 10.814ms | 94651 | 32 | 342412 | 14712 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7239.37 | 0.542798 | 5.46022ms | 140436 | 30 | 302520 | 18500.3 | 1(Win) |
| simdjson | 6562.63 | 0.998448 | 13.226ms | 140436 | 32 | 1.32862e+06 | 20408 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 5009.76 | 0.227749 | 267.534ms | 2090234 | 32 | 2.62797e+07 | 397904 | 1(Win) |
| jsonifier | 4811.36 | 1.18752 | 283.76ms | 2090234 | 32 | 7.74614e+08 | 414312 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6129.82 | 1.8255 | 12384ms | 6885124 | 512 | 1.95776e+11 | 1.07118e+06 | 1(Win) |
| simdjson | 5394.01 | 1.50255 | 12397.4ms | 6885124 | 512 | 1.71287e+11 | 1.21731e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4944.09 | 1.62954 | 25.2772ms | 500299 | 30 | 7.41889e+07 | 96503.5 | 1(Win) |
| simdjson | 4292.07 | 2.41369 | 28.4009ms | 500299 | 30 | 2.15978e+08 | 111164 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6421.79 | 1.59419 | 2918.4ms | 1490030 | 512 | 6.3713e+09 | 221278 | 1(Win) |
| simdjson | 5955.57 | 1.65539 | 60.159ms | 1490030 | 30 | 4.6802e+08 | 238601 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5887.6 | 0.752482 | 3.42912ms | 56369 | 30 | 141618 | 9130.67 | 1(Win) |
| simdjson | 4970.2 | 0.663689 | 10.8099ms | 56369 | 32 | 164897 | 10816 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6222.44 | 0.617484 | 10.5231ms | 98048 | 30 | 258302 | 15027.2 | 1(Win) |
| simdjson | 5523.04 | 1.27799 | 4.544ms | 98048 | 30 | 1.40443e+06 | 16930.1 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8284.92 | 0.787433 | 2.07104ms | 52708 | 30 | 68473.8 | 6067.2 | 1(Win) |
| simdjson | 6794.21 | 1.35138 | 2.27405ms | 52708 | 30 | 299884 | 7398.4 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7170.27 | 0.986463 | 3.48006ms | 71665 | 30 | 265232 | 9531.73 | 1(Win) |
| simdjson | 6787.45 | 0.477324 | 2.912ms | 71665 | 30 | 69302.4 | 10069.3 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5074.23 | 2.46414 | 6.17805ms | 11812 | 64 | 191521 | 2220 | 1(Win) |
| simdjson | 4757.1 | 1.84993 | 7.07507ms | 11812 | 128 | 245631 | 2368 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6669.09 | 1.91662 | 3.51104ms | 32403 | 30 | 236608 | 4633.6 | 1(Win) |
| simdjson | 6297.94 | 1.22763 | 1.70496ms | 32403 | 30 | 108850 | 4906.67 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5266.95 | 1.14626 | 27.7798ms | 108313 | 64 | 3.23439e+06 | 19612 | 1(Win) |
| simdjson | 4840.03 | 1.971 | 6.19699ms | 108313 | 30 | 5.30834e+06 | 21341.9 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6149.85 | 1.83741 | 63.458ms | 222373 | 64 | 2.56936e+07 | 34484 | 1(Win) |
| simdjson | 5657.65 | 0.402322 | 139.628ms | 222373 | 128 | 2.91105e+06 | 37484 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 3807.3 | 1.65266 | 640.45ms | 1834197 | 64 | 3.68981e+09 | 459440 | 1(Win) |
| jsonifier | 2793.57 | 0.656014 | 3535.82ms | 1834197 | 256 | 4.31954e+09 | 626161 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 6301.13 | 0.715435 | 991.853ms | 10252236 | 32 | 3.94357e+09 | 1.55167e+06 | 1(Win) |
| jsonifier | 5394.92 | 2.04907 | 18982.3ms | 10252236 | 512 | 7.06076e+11 | 1.81232e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5110.79 | 0.534341 | 55.798ms | 642697 | 30 | 1.23196e+07 | 119927 | 1(Win) |
| simdjson | 4384.24 | 0.465274 | 43.582ms | 642697 | 30 | 1.2693e+07 | 139802 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 6065.18 | 1.08086 | 126.59ms | 1306201 | 32 | 1.57698e+08 | 205384 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 5955.45 | 0.985983 | 336.309ms | 1306201 | 64 | 2.72213e+08 | 209168 | 1(Tie) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6060.93 | 0.723249 | 25.783ms | 409725 | 30 | 6.52234e+06 | 64469.3 | 1(Win) |
| simdjson | 5020.32 | 0.165761 | 21.1359ms | 409725 | 30 | 499354 | 77832.5 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6306.1 | 0.484516 | 92.2929ms | 814756 | 32 | 1.14051e+07 | 123216 | 1(Win) |
| simdjson | 5772.91 | 1.58295 | 34.3539ms | 814756 | 30 | 1.36182e+08 | 134596 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7668.6 | 0.261483 | 11.4798ms | 264040 | 30 | 221165 | 32836.3 | 1(Win) |
| simdjson | 5943.36 | 2.32086 | 12.789ms | 264040 | 30 | 2.90065e+07 | 42368 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7219.76 | 0.557355 | 13.7759ms | 399947 | 30 | 2.60103e+06 | 52829.9 | 1(Win) |
| simdjson | 6576.07 | 0.242843 | 15.5461ms | 399947 | 30 | 595172 | 58001.1 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7523.91 | 0.798413 | 9.20602ms | 264040 | 30 | 2.14205e+06 | 33467.7 | 1(Win) |
| simdjson | 4600.81 | 2.06125 | 1113.46ms | 264040 | 1024 | 1.30326e+09 | 54731.2 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json//Users/runner/work/Json-Performance/Json-Performance/json/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6914.41 | 2.18524 | 35.8538ms | 409612 | 32 | 4.87733e+07 | 56496 | 1(Win) |
| simdjson | 5428.56 | 2.39816 | 807.153ms | 409612 | 512 | 1.52476e+09 | 71959.5 | 2(Loss) |
