# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.6.87.2-microsoft-standard-WSL2 using the GCC 16.0.1 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [0b08cd8](https://github.com/RealTimeChris/Jsonifier/commit/0b08cd8)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Both libraries are executing only 'stage-1' parsing, where they identify the structural indices, and neither of them are performing utf-8 validation in these tests. Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14186.4 | 0.0484435 | 1.69023ms | 33713 | 30 | 36.1609 | 2266.33 | 1(Win) |
| simdjson | 5736.61 | 0.0385319 | 2.14602ms | 33713 | 30 | 139.909 | 5604.57 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 14983.1 | 0.154398 | 1.17004ms | 49505 | 30 | 710.069 | 3151 | 1(Win) |
| jsonifier | 14835.2 | 0.0336753 | 1.17278ms | 49505 | 30 | 34.4552 | 3182.4 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 13947.5 | 0.24242 | 0.960218ms | 33713 | 30 | 936.833 | 2305.17 | 1(Win) |
| jsonifier | 13286 | 0.0757299 | 1.21693ms | 33713 | 30 | 100.754 | 2419.93 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 14287.7 | 0.0622447 | 1.16318ms | 48024 | 30 | 119.431 | 3205.5 | 1(Win) |
| jsonifier | 14257.3 | 0.0476767 | 1.11652ms | 48024 | 30 | 70.3678 | 3212.33 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14483.5 | 0.0497583 | 3.15194ms | 94651 | 30 | 288.506 | 6232.33 | 1(Win) |
| simdjson | 14159.1 | 0.127659 | 1.87951ms | 94651 | 30 | 1987.02 | 6375.13 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 15919.4 | 0.0357546 | 2.36981ms | 140436 | 30 | 271.448 | 8413 | 1(Win) |
| jsonifier | 15473 | 0.0302401 | 5.41066ms | 140436 | 32 | 219.241 | 8655.72 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 10523.9 | 0.522611 | 112.24ms | 2090234 | 32 | 3.13578e+07 | 189417 | 1(Win) |
| jsonifier | 9870.77 | 0.432292 | 175.59ms | 2090234 | 32 | 2.43889e+07 | 201950 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 17745.4 | 0.425095 | 234.555ms | 6885124 | 32 | 7.91719e+07 | 370020 | 1(Win) |
| jsonifier | 16216.2 | 2.45862 | 2215.31ms | 6885124 | 256 | 2.53716e+10 | 404913 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10448.8 | 1.29468 | 12.6786ms | 500299 | 30 | 1.04851e+07 | 45662.9 | 1(Win) |
| simdjson | 9614 | 2.4345 | 30.3263ms | 500299 | 32 | 4.67112e+07 | 49627.9 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 13767.5 | 1.12436 | 26.5849ms | 1490030 | 30 | 4.04031e+07 | 103214 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 13424.7 | 0.78271 | 28.5407ms | 1490030 | 30 | 2.05922e+07 | 105850 | 1(Tie) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 11832 | 0.0853749 | 3.36347ms | 56369 | 32 | 481.475 | 4543.41 | 1(Win) |
| simdjson | 11569.7 | 0.035546 | 1.44982ms | 56369 | 30 | 81.8345 | 4646.4 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 13743.7 | 0.0669081 | 4.22644ms | 98048 | 32 | 663.096 | 6803.53 | 1(Win) |
| jsonifier | 13104.5 | 0.0534099 | 4.44956ms | 98048 | 32 | 464.758 | 7135.38 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 16308.2 | 0.0522891 | 1.12785ms | 52708 | 30 | 77.9264 | 3082.27 | 1(Win) |
| simdjson | 13295.8 | 0.109049 | 1.46494ms | 52708 | 30 | 509.903 | 3780.6 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 15672 | 0.0389563 | 1.38426ms | 71665 | 30 | 86.5851 | 4360.97 | 1(Win) |
| simdjson | 13308.2 | 0.442237 | 2.4952ms | 71665 | 30 | 15474.2 | 5135.57 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 10940.2 | 0.200409 | 0.58914ms | 11812 | 30 | 127.747 | 1029.67 | 1(Win) |
| simdjson | 10093.9 | 0.0770937 | 0.586744ms | 11812 | 30 | 22.2069 | 1116 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14913.8 | 0.0444189 | 0.809727ms | 32403 | 30 | 25.4126 | 2072.03 | 1(Win) |
| simdjson | 14373.6 | 0.0664331 | 0.932274ms | 32403 | 30 | 61.1966 | 2149.9 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 11199.7 | 0.072448 | 2.63859ms | 108313 | 30 | 1339.44 | 9223.07 | 1(Win) |
| simdjson | 10501.9 | 0.0268757 | 2.71852ms | 108313 | 30 | 209.637 | 9835.87 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 14138 | 1.47067 | 11.525ms | 222373 | 32 | 1.5573e+06 | 15000.1 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 13996.6 | 0.271749 | 4.03092ms | 222373 | 30 | 50860.2 | 15151.7 | 1(Tie) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 7404.46 | 0.696791 | 63.9205ms | 1834197 | 30 | 8.12888e+07 | 236239 | 1(Win) |
| jsonifier | 6349.47 | 1.55307 | 216.904ms | 1834197 | 32 | 5.85799e+08 | 275492 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 12903 | 2.36973 | 4031.13ms | 10252236 | 256 | 8.25458e+10 | 757755 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 12737.1 | 2.16061 | 4134.86ms | 10252236 | 256 | 7.0419e+10 | 767624 | 1(Tie) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 12052 | 0.736579 | 31.0372ms | 642697 | 32 | 4.49041e+06 | 50856.8 | 1(Win) |
| simdjson | 9414.35 | 0.890323 | 41.8003ms | 642697 | 32 | 1.07517e+07 | 65105.2 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14307.5 | 0.964167 | 55.3572ms | 1306201 | 32 | 2.255e+07 | 87065.4 | 1(Win) |
| simdjson | 13559.7 | 0.346172 | 24.0484ms | 1306201 | 30 | 3.03408e+06 | 91867.2 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 12328.8 | 0.0511627 | 8.22532ms | 409725 | 30 | 7888.1 | 31693.6 | 1(Win) |
| simdjson | 10945.4 | 0.594543 | 22.8997ms | 409725 | 32 | 1.44158e+06 | 35699.3 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 14279.6 | 0.407177 | 15.2491ms | 814756 | 30 | 1.4727e+06 | 54414.3 | 1(Win) |
| jsonifier | 10636.7 | 0.930398 | 42.3081ms | 814756 | 32 | 1.47818e+07 | 73050 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 14749.7 | 1.84818 | 4.38581ms | 264040 | 30 | 2.98665e+06 | 17072.1 | 1(Win) |
| simdjson | 13342.4 | 0.990348 | 13.6019ms | 264040 | 32 | 1.11789e+06 | 18872.8 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 15091.5 | 0.985303 | 34.2495ms | 399947 | 64 | 3.96883e+06 | 25273.8 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 15059.6 | 1.73466 | 14.8672ms | 399947 | 32 | 6.1767e+06 | 25327.3 | 1(Tie) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 15015.6 | 1.36184 | 4.4704ms | 264040 | 30 | 1.56468e+06 | 16769.8 | 1(Win) |
| simdjson | 14055.5 | 0.091632 | 4.98043ms | 264040 | 30 | 8084.7 | 17915.3 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json//home/chris/jp/json/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 15708.1 | 1.12888 | 8.65044ms | 409612 | 30 | 2.36437e+06 | 24868.5 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 15298 | 0.76729 | 7.94532ms | 409612 | 30 | 1.15164e+06 | 25535.1 | 1(Tie) |
