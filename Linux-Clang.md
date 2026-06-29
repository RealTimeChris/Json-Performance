# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.6.87.2-microsoft-standard-WSL2 using the Clang 23.0.0 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [0b08cd8](https://github.com/RealTimeChris/Jsonifier/commit/0b08cd8)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Both libraries are executing only 'stage-1' parsing, where they identify the structural indices, and neither of them are performing utf-8 validation in these tests. Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 15186.9 | 0.382109 | 1.70581ms | 33713 | 30 | 1963.14 | 2117.03 | 1(Win) |
| simdjson | 13559.8 | 0.0611989 | 0.841559ms | 33713 | 30 | 63.1678 | 2371.07 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17552.1 | 0.0902316 | 0.94101ms | 49505 | 30 | 176.717 | 2689.8 | 1(Win) |
| simdjson | 15384.9 | 0.037795 | 1.0921ms | 49505 | 30 | 40.3552 | 3068.7 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16081 | 0.0991769 | 0.807416ms | 33713 | 30 | 117.954 | 1999.33 | 1(Win) |
| simdjson | 13716.2 | 0.0420433 | 0.982262ms | 33713 | 30 | 29.1368 | 2344.03 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17131.9 | 0.0734753 | 0.974252ms | 48024 | 30 | 115.747 | 2673.33 | 1(Win) |
| simdjson | 15078.3 | 0.0780317 | 1.08483ms | 48024 | 30 | 168.53 | 3037.43 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16515.5 | 0.0554247 | 1.7357ms | 94651 | 30 | 275.292 | 5465.53 | 1(Win) |
| simdjson | 14155.6 | 0.0834296 | 1.90181ms | 94651 | 30 | 849.099 | 6376.73 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17980.7 | 0.0634155 | 2.18848ms | 140436 | 30 | 669.357 | 7448.57 | 1(Win) |
| simdjson | 15938 | 0.105543 | 5.20297ms | 140436 | 32 | 2517.08 | 8403.22 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 10499.6 | 0.496484 | 247.104ms | 2090234 | 64 | 5.68642e+07 | 189856 | 1(Win) |
| jsonifier | 10053.1 | 0.808418 | 53.0973ms | 2090234 | 30 | 7.70878e+07 | 198288 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17747.7 | 2.33912 | 222.198ms | 6885124 | 32 | 2.39658e+09 | 369972 | 1(Win) |
| simdjson | 15154.9 | 1.45665 | 4532.11ms | 6885124 | 512 | 2.0394e+10 | 433271 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 9769.67 | 0.407808 | 31.0996ms | 500299 | 32 | 1.26929e+06 | 48837.1 | 1(Win) |
| jsonifier | 9137.1 | 0.388642 | 14.8053ms | 500299 | 30 | 1.23556e+06 | 52218.1 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16523.9 | 0.866205 | 23.4328ms | 1490030 | 30 | 1.66466e+07 | 85996.6 | 1(Win) |
| simdjson | 14673.4 | 0.565739 | 26.4447ms | 1490030 | 30 | 9.00498e+06 | 96842.2 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 11336.5 | 0.0750669 | 1.45195ms | 56369 | 30 | 380.138 | 4742 | 1(Win) |
| simdjson | 10071.4 | 0.060753 | 2.04421ms | 56369 | 30 | 315.471 | 5337.67 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14907 | 0.0582213 | 1.84193ms | 98048 | 30 | 400.11 | 6272.6 | 1(Win) |
| simdjson | 13368.8 | 0.0321151 | 4.3321ms | 98048 | 32 | 161.459 | 6994.34 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17034.8 | 0.171154 | 1.02709ms | 52708 | 30 | 765.2 | 2950.8 | 1(Win) |
| simdjson | 14942.1 | 0.048999 | 1.12511ms | 52708 | 30 | 81.5126 | 3364.07 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 18011.3 | 0.0822031 | 2.62736ms | 71665 | 32 | 311.351 | 3794.56 | 1(Win) |
| simdjson | 16104.8 | 0.0530369 | 1.53351ms | 71665 | 30 | 151.978 | 4243.77 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 9521.7 | 0.0518895 | 0.581729ms | 11812 | 30 | 11.3057 | 1183.07 | 1(Win) |
| jsonifier | 4723.19 | 0.941197 | 1.66844ms | 11812 | 30 | 15116.8 | 2385 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 17255.9 | 0.0638877 | 0.725979ms | 32403 | 30 | 39.269 | 1790.8 | 1(Win) |
| simdjson | 14146.2 | 0.0695721 | 0.962163ms | 32403 | 30 | 69.292 | 2184.47 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10787.5 | 0.0733407 | 5.65795ms | 108313 | 32 | 1578.19 | 9575.47 | 1(Win) |
| simdjson | 9136.44 | 2.3159 | 5.02391ms | 108313 | 30 | 2.05669e+06 | 11305.9 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 15830.7 | 0.323086 | 3.54633ms | 222373 | 30 | 56198.2 | 13396.2 | 1(Win) |
| simdjson | 14304.5 | 0.0972572 | 3.94199ms | 222373 | 30 | 6237.09 | 14825.5 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 7314.86 | 0.565623 | 65.0442ms | 1834197 | 30 | 5.48852e+07 | 239133 | 1(Win) |
| jsonifier | 5820.85 | 2.46036 | 804.376ms | 1834197 | 128 | 6.99722e+09 | 300510 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14900.1 | 2.32155 | 3494.1ms | 10252236 | 256 | 5.94091e+10 | 656189 | 1(Win) |
| simdjson | 13626.9 | 1.82972 | 4023.38ms | 10252236 | 256 | 4.41216e+10 | 717500 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 12475.7 | 0.808693 | 13.7493ms | 642697 | 30 | 4.73553e+06 | 49129.2 | 1(Win) |
| simdjson | 10202.3 | 0.793179 | 16.0871ms | 642697 | 30 | 6.81205e+06 | 60076.9 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16578.3 | 0.550994 | 19.8933ms | 1306201 | 30 | 5.14229e+06 | 75139.9 | 1(Win) |
| simdjson | 13853.2 | 1.14036 | 54.5789ms | 1306201 | 32 | 3.36478e+07 | 89921 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 11619.4 | 0.768763 | 9.91271ms | 409725 | 30 | 2.00504e+06 | 33628.6 | 1(Win) |
| simdjson | 11168.6 | 1.61507 | 8.97948ms | 409725 | 30 | 9.5784e+06 | 34986 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 14778.5 | 0.354859 | 32.9086ms | 814756 | 32 | 1.11393e+06 | 52577.3 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 14618.8 | 1.23991 | 14.6719ms | 814756 | 30 | 1.30296e+07 | 53151.4 | 1(Tie) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16379.9 | 0.0872167 | 6.2894ms | 264040 | 30 | 5393.07 | 15373 | 1(Win) |
| simdjson | 13644.1 | 1.50622 | 4.71612ms | 264040 | 30 | 2.31818e+06 | 18455.4 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16442.4 | 1.23388 | 7.12496ms | 399947 | 30 | 2.45775e+06 | 23197.3 | 1(Win) |
| simdjson | 15309.2 | 1.18539 | 16.4442ms | 399947 | 32 | 2.79109e+06 | 24914.4 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16641.9 | 0.0667138 | 5.18589ms | 264040 | 30 | 3056.93 | 15131 | 1(Win) |
| simdjson | 14157.7 | 0.033327 | 4.67321ms | 264040 | 30 | 1054.06 | 17785.9 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/json-performance/json/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 18018.6 | 0.0745215 | 8.53177ms | 409612 | 30 | 7830.46 | 21679.6 | 1(Win) |
| simdjson | 16147.9 | 0.0976042 | 6.52778ms | 409612 | 30 | 16725.3 | 24191.2 | 2(Loss) |
