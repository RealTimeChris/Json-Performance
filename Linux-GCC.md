# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.17.0-1018-azure using the GCC 16.0.1 compiler).  

Latest Results: (Jul 02, 2026)
#### Using the following commits:
----
| Jsonifier: [6a2069c](https://github.com/RealTimeChris/Jsonifier/commit/6a2069c)  
| Glaze: [4fab045](https://github.com/stephenberry/glaze/commit/4fab045)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 457.257 | 0.122425 | 1.20145ms | 1811 | 30 | 641.472 | 3777.1 | 1(Win) |
| jsonifier | 301.804 | 0.340403 | 2.39059ms | 1811 | 30 | 11384 | 5722.6 | 2(Loss) |
| simdjson | 139.068 | 0.0931287 | 3.34102ms | 1811 | 30 | 4013.02 | 12419.1 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 420.571 | 0.0802618 | 1.28329ms | 1811 | 30 | 325.909 | 4106.57 | 1(Win) |
| glaze | 283.903 | 0.272323 | 1.7453ms | 1798 | 30 | 8115.77 | 6039.77 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1286.81 | 0.129695 | 0.977509ms | 3873 | 30 | 415.747 | 2870.33 | 1(Win) |
| glaze | 1166.21 | 0.110232 | 1.03698ms | 3873 | 30 | 365.661 | 3167.17 | 2(Loss) |
| simdjson | 302.058 | 2.46034 | 3.17409ms | 3873 | 30 | 2.71536e+06 | 12228.1 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1756.36 | 0.127475 | 1.57287ms | 3873 | 32 | 229.967 | 2102.97 | 1(Win) |
| glaze | 1097.68 | 0.379743 | 1.10387ms | 3873 | 30 | 4898.3 | 3364.9 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1344.85 | 0.107499 | 0.946191ms | 3862 | 30 | 260.023 | 2738.67 | 1(Win) |
| glaze | 941.421 | 0.111571 | 1.22914ms | 3862 | 30 | 571.582 | 3912.27 | 2(Loss) |
| simdjson | 290.98 | 2.31704 | 3.31559ms | 3862 | 30 | 2.58039e+06 | 12657.5 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1611.88 | 0.260992 | 0.813974ms | 3862 | 30 | 1066.93 | 2284.97 | 1(Win) |
| glaze | 1070.87 | 0.273457 | 1.10793ms | 3862 | 30 | 2653.68 | 3439.33 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 969.058 | 0.111305 | 0.438456ms | 905 | 30 | 29.4816 | 890.633 | 1(Win) |
| glaze | 535.639 | 0.433944 | 0.664556ms | 905 | 30 | 1466.7 | 1611.3 | 2(Loss) |
| simdjson | 101.092 | 0.0722907 | 2.33575ms | 905 | 30 | 1142.74 | 8537.5 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 818.598 | 0.148638 | 0.503306ms | 905 | 30 | 73.6782 | 1054.33 | 1(Win) |
| glaze | 319.307 | 0.589544 | 0.932164ms | 905 | 30 | 7617.9 | 2702.97 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2152.85 | 0.114339 | 2.62761ms | 8813 | 32 | 637.613 | 3904 | 1(Win) |
| glaze | 1193.73 | 0.101316 | 2.08883ms | 8813 | 30 | 1526.55 | 7040.73 | 2(Loss) |
| simdjson | 576.068 | 0.0870723 | 3.84373ms | 8813 | 30 | 4841.52 | 14589.8 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2188.24 | 0.14183 | 1.21035ms | 8813 | 30 | 890.257 | 3840.87 | 1(Win) |
| glaze | 1855.54 | 0.364574 | 1.40509ms | 8813 | 30 | 8180.88 | 4529.53 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1265.78 | 0.179815 | 6.67878ms | 33713 | 30 | 62582 | 25400.2 | 1(Win) |
| jsonifier | 1135.74 | 1.2559 | 7.33192ms | 33713 | 30 | 3.79201e+06 | 28308.7 | 2(Loss) |
| simdjson | 199.368 | 0.371609 | 39.2419ms | 33713 | 30 | 1.0774e+07 | 161266 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2087.56 | 0.917114 | 19.3559ms | 33689 | 64 | 1.27504e+06 | 15390.4 | 1(Win) |
| jsonifier | 2003 | 0.178841 | 4.27156ms | 33713 | 30 | 24722.1 | 16051.5 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1415.98 | 0.843964 | 19.532ms | 49505 | 32 | 2.53386e+06 | 33342.1 | 1(Win) |
| jsonifier | 712.85 | 0.829641 | 16.5347ms | 49505 | 30 | 9.0574e+06 | 66229.5 | 2(Loss) |
| simdjson | 289.501 | 0.465308 | 39.6232ms | 49505 | 30 | 1.72743e+07 | 163080 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2497.33 | 1.64146 | 10.6884ms | 48024 | 32 | 2.89986e+06 | 18339.3 | 1(Win) |
| glaze | 1811.85 | 1.69822 | 6.31356ms | 48000 | 30 | 5.52263e+06 | 25264.9 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3206.23 | 0.0618628 | 2.7306ms | 33713 | 30 | 1154.48 | 10027.7 | 1(Win) |
| simdjson | 2670.26 | 2.38936 | 3.12837ms | 33713 | 30 | 2.48296e+06 | 12040.5 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3836.53 | 2.3953 | 3.17134ms | 48024 | 30 | 2.4529e+06 | 11937.7 | 1(Win) |
| simdjson | 3395.94 | 2.07756 | 3.49075ms | 48024 | 30 | 2.35519e+06 | 13486.5 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 752.685 | 0.5573 | 68.2503ms | 94651 | 32 | 1.42939e+07 | 119926 | 1(Win) |
| glaze | 667.565 | 0.528455 | 32.8292ms | 94651 | 30 | 1.53179e+07 | 135217 | 2(Loss) |
| simdjson | 652.905 | 0.561377 | 33.8362ms | 94651 | 30 | 1.80709e+07 | 138253 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3039.01 | 1.23773 | 7.47763ms | 94651 | 30 | 4.05471e+06 | 29702.5 | 1(Win) |
| glaze | 2604.32 | 1.7157 | 8.67326ms | 94651 | 30 | 1.06087e+07 | 34660.1 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 930.24 | 0.489824 | 34.9619ms | 140436 | 30 | 1.492e+07 | 143974 | 1(Win) |
| glaze | 852.542 | 0.516813 | 38.3664ms | 140436 | 30 | 1.97749e+07 | 157095 | 2(Loss) |
| jsonifier | 524.416 | 1.71501 | 59.9466ms | 140436 | 30 | 5.75516e+08 | 255389 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3127.76 | 1.19758 | 10.4661ms | 136024 | 30 | 7.40113e+06 | 41474.6 | 1(Win) |
| glaze | 1670.45 | 0.981696 | 19.0757ms | 136046 | 30 | 1.74413e+07 | 77669.8 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 358.446 | 0.115461 | 1336.92ms | 2090234 | 30 | 1.23689e+09 | 5.56124e+06 | 1(Win) |
| jsonifier | 325.118 | 0.100193 | 1475.75ms | 2090234 | 30 | 1.13215e+09 | 6.13132e+06 | 2(Loss) |
| simdjson | 321.536 | 0.114887 | 1494.76ms | 2090234 | 30 | 1.52194e+09 | 6.19963e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 905.321 | 0.179818 | 535.237ms | 2090234 | 30 | 4.70299e+08 | 2.20187e+06 | 1(Win) |
| glaze | 726.521 | 0.0956781 | 660.04ms | 2090234 | 30 | 2.06748e+08 | 2.74377e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 981.536 | 0.622371 | 1597.16ms | 6885124 | 30 | 5.20034e+10 | 6.68969e+06 | 1(Win) |
| glaze | 903.399 | 0.226843 | 1742.18ms | 6885124 | 30 | 8.15523e+09 | 7.26829e+06 | 2(Loss) |
| jsonifier | 683.399 | 0.0846591 | 2306.7ms | 6885124 | 30 | 1.98492e+09 | 9.6081e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1719.14 | 0.208693 | 895.343ms | 6661897 | 30 | 1.78447e+09 | 3.69562e+06 | 1(Win) |
| glaze | 1537.97 | 0.143025 | 997.861ms | 6661897 | 30 | 1.04725e+09 | 4.13096e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 945.551 | 0.262739 | 121.64ms | 500299 | 30 | 5.27303e+07 | 504597 | 1(Win) |
| jsonifier | 763.261 | 0.522244 | 149.798ms | 500299 | 30 | 3.19728e+08 | 625110 | 2(Loss) |
| simdjson | 565.843 | 0.196688 | 202.128ms | 500299 | 30 | 8.25175e+07 | 843206 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1854.13 | 0.498395 | 62.3419ms | 500299 | 30 | 4.93458e+07 | 257330 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1836.57 | 0.447979 | 63.1385ms | 500299 | 30 | 4.0633e+07 | 259789 | 1(Tie) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 1508.82 | 0.19755 | 225.958ms | 1490030 | 30 | 1.03847e+08 | 941799 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1506.54 | 0.277681 | 225.326ms | 1490030 | 30 | 2.05799e+08 | 943224 | 1(Tie) |
| jsonifier | 795.594 | 0.148286 | 428.327ms | 1490030 | 30 | 2.10441e+08 | 1.78609e+06 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3455.73 | 0.4437 | 100.405ms | 1439562 | 30 | 9.3214e+07 | 397274 | 1(Win) |
| glaze | 1948 | 0.267648 | 175.707ms | 1439584 | 30 | 1.06745e+08 | 704770 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 908.9 | 0.891581 | 14.7583ms | 56369 | 30 | 8.3424e+06 | 59145.8 | 1(Win) |
| glaze | 836.98 | 0.826442 | 16.0907ms | 56369 | 30 | 8.45273e+06 | 64228.2 | 2(Loss) |
| simdjson | 678.459 | 0.73454 | 19.5157ms | 56369 | 30 | 1.01621e+07 | 79234.9 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1860.14 | 1.10026 | 7.28409ms | 56369 | 30 | 3.03318e+06 | 28899.8 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1830.38 | 0.0436335 | 7.43348ms | 56369 | 30 | 4926.75 | 29369.7 | 1(Tie) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1209.74 | 0.699326 | 19.2152ms | 98048 | 30 | 8.76546e+06 | 77294.3 | 1(Win) |
| simdjson | 1116.23 | 0.573717 | 20.5483ms | 98048 | 30 | 6.92924e+06 | 83769.2 | 2(Loss) |
| jsonifier | 493.982 | 0.718796 | 46.4545ms | 98048 | 30 | 5.55377e+07 | 189290 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2005.71 | 1.0275 | 11.0752ms | 94370 | 30 | 6.37705e+06 | 44871.1 | 1(Win) |
| glaze | 1720.69 | 0.707643 | 13.1144ms | 94370 | 30 | 4.10972e+06 | 52303.5 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 862.134 | 0.909126 | 14.6266ms | 52708 | 30 | 8.42895e+06 | 58304.5 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 851.083 | 1.32768 | 14.9672ms | 52708 | 30 | 1.84467e+07 | 59061.5 | 1(Tie) |
| glaze | 720.124 | 0.920541 | 17.4683ms | 52708 | 30 | 1.23864e+07 | 69802.2 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 2566.59 | 1.90026 | 5.07286ms | 52708 | 30 | 4.15516e+06 | 19584.9 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 2465.68 | 1.65614 | 5.22935ms | 52708 | 30 | 3.41976e+06 | 20386.3 | 1(Tie) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1112.45 | 0.987311 | 15.254ms | 71665 | 30 | 1.10378e+07 | 61436.6 | 1(Win) |
| glaze | 831.797 | 0.728789 | 49.5947ms | 71665 | 32 | 1.14745e+07 | 82165.6 | 2(Loss) |
| jsonifier | 347.937 | 2.03624 | 47.6928ms | 71665 | 30 | 4.79947e+08 | 196429 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2337.37 | 1.29203 | 7.28832ms | 70103 | 30 | 4.09719e+06 | 28602.9 | 1(Win) |
| glaze | 2256.79 | 1.12278 | 7.56418ms | 70103 | 30 | 3.31895e+06 | 29624.1 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 745.898 | 0.0463671 | 4.07273ms | 11812 | 30 | 1471.06 | 15102.3 | 1(Win) |
| glaze | 683.877 | 0.288193 | 4.4383ms | 11812 | 30 | 67605 | 16472 | 2(Loss) |
| simdjson | 546.4 | 0.0545597 | 5.3749ms | 11812 | 30 | 3795.7 | 20616.4 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2117.19 | 0.0934603 | 1.58071ms | 11812 | 30 | 741.826 | 5320.63 | 1(Win) |
| glaze | 1233.44 | 1.40872 | 11.3768ms | 11812 | 64 | 1.05935e+06 | 9132.8 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1367.78 | 0.0332905 | 5.82421ms | 32403 | 30 | 1697.06 | 22592.7 | 1(Win) |
| glaze | 1151.96 | 1.38723 | 6.81245ms | 32403 | 30 | 4.15448e+06 | 26825.5 | 2(Loss) |
| jsonifier | 722.245 | 0.794811 | 10.6332ms | 32403 | 30 | 3.46937e+06 | 42785.9 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2796.17 | 0.0813514 | 2.89112ms | 31235 | 30 | 2253.25 | 10653.2 | 1(Win) |
| glaze | 1906.17 | 0.325091 | 9.3015ms | 31235 | 32 | 82588.5 | 15627.2 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1372.74 | 0.671462 | 18.6527ms | 108313 | 30 | 7.65854e+06 | 75247.3 | 1(Win) |
| glaze | 982.158 | 0.572409 | 25.0752ms | 108313 | 30 | 1.08726e+07 | 105172 | 2(Loss) |
| simdjson | 766.813 | 1.01785 | 32.6846ms | 108313 | 30 | 5.6399e+07 | 134707 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1957.85 | 0.885041 | 13.1314ms | 108313 | 30 | 6.54111e+06 | 52759.6 | 1(Win) |
| glaze | 1645.32 | 0.845201 | 15.4184ms | 108313 | 30 | 8.44704e+06 | 62781.5 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1454.9 | 0.534687 | 35.557ms | 222373 | 30 | 1.82228e+07 | 145763 | 1(Win) |
| glaze | 1388.38 | 0.486998 | 37.6291ms | 222373 | 30 | 1.66005e+07 | 152747 | 2(Loss) |
| jsonifier | 538.831 | 0.778968 | 94.9996ms | 222373 | 30 | 2.8198e+08 | 393577 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3118.82 | 0.82588 | 16.3594ms | 213963 | 30 | 8.75894e+06 | 65425.7 | 1(Win) |
| glaze | 1656.72 | 0.50945 | 30.1954ms | 213963 | 30 | 1.18114e+07 | 123165 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 330.758 | 0.0594127 | 1267.42ms | 1834197 | 30 | 2.96178e+08 | 5.28855e+06 | 1(Win) |
| jsonifier | 286.531 | 0.177631 | 1468.97ms | 1834197 | 30 | 3.52784e+09 | 6.10484e+06 | 2(Loss) |
| simdjson | 279.762 | 0.117289 | 1505.88ms | 1834197 | 30 | 1.61342e+09 | 6.25255e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 557.238 | 0.188823 | 752.006ms | 1834197 | 30 | 1.054e+09 | 3.1391e+06 | 1(Win) |
| glaze | 350.478 | 0.074961 | 1197.31ms | 1833577 | 30 | 4.19633e+08 | 4.98929e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1372.79 | 0.205941 | 1711.79ms | 10252236 | 30 | 6.45413e+09 | 7.12222e+06 | 1(Win) |
| glaze | 1313.95 | 0.0918171 | 1788.85ms | 10252236 | 30 | 1.40038e+09 | 7.44112e+06 | 2(Loss) |
| jsonifier | 749.488 | 0.11154 | 3146.39ms | 10252236 | 30 | 6.35169e+09 | 1.30453e+07 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1999.3 | 0.200697 | 1181.05ms | 9930848 | 30 | 2.71156e+09 | 4.73705e+06 | 1(Win) |
| glaze | 1210.86 | 0.126505 | 1902.68ms | 9930228 | 30 | 2.93676e+09 | 7.82105e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 594.485 | 0.0487852 | 248.034ms | 642697 | 30 | 7.58978e+06 | 1.03102e+06 | 1(Win) |
| jsonifier | 546.964 | 0.152463 | 269.286ms | 642697 | 30 | 8.75673e+07 | 1.12059e+06 | 2(Loss) |
| simdjson | 475.218 | 0.0975379 | 310.533ms | 642697 | 30 | 4.74783e+07 | 1.28977e+06 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 895.724 | 1.20574 | 164.812ms | 642697 | 30 | 2.04217e+09 | 684278 | 1(Win) |
| glaze | 600.909 | 0.143346 | 244.594ms | 642692 | 30 | 6.41329e+07 | 1.01999e+06 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1007.01 | 0.187314 | 297.22ms | 1306201 | 30 | 1.61069e+08 | 1.23702e+06 | 1(Win) |
| simdjson | 918.735 | 0.957364 | 323.549ms | 1306201 | 30 | 5.05493e+09 | 1.35588e+06 | 2(Loss) |
| jsonifier | 713.395 | 0.0827507 | 420.91ms | 1306201 | 30 | 6.26361e+07 | 1.74614e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1375.75 | 0.182337 | 204.194ms | 1225964 | 30 | 7.20353e+07 | 849841 | 1(Win) |
| glaze | 972.665 | 0.149669 | 289.348ms | 1225970 | 30 | 9.71003e+07 | 1.20203e+06 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 653.525 | 0.14728 | 144.075ms | 409725 | 30 | 2.32634e+07 | 597903 | 1(Win) |
| simdjson | 512.329 | 0.169276 | 182.891ms | 409725 | 30 | 5.00037e+07 | 762683 | 2(Loss) |
| glaze | 410.755 | 0.346642 | 228.292ms | 409725 | 30 | 3.26215e+08 | 951283 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1417.73 | 0.355659 | 67.4855ms | 409725 | 30 | 2.88263e+07 | 275613 | 1(Win) |
| jsonifier | 1238.71 | 0.346068 | 76.5029ms | 409725 | 30 | 3.5751e+07 | 315444 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 968.633 | 0.148892 | 192.811ms | 814756 | 30 | 4.27956e+07 | 802174 | 1(Win) |
| glaze | 705.437 | 0.142539 | 265.307ms | 814756 | 30 | 7.39483e+07 | 1.10146e+06 | 2(Loss) |
| jsonifier | 501.204 | 0.0841793 | 372.766ms | 814756 | 30 | 5.10926e+07 | 1.55029e+06 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1954.68 | 0.430358 | 92.4244ms | 785750 | 30 | 8.16576e+07 | 383361 | 1(Win) |
| glaze | 1453.29 | 0.364186 | 124.395ms | 785750 | 30 | 1.05787e+08 | 515622 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3523.9 | 0.655713 | 17.5458ms | 264040 | 30 | 6.58632e+06 | 71457.3 | 1(Win) |
| simdjson | 2617.8 | 0.620315 | 23.5369ms | 264040 | 30 | 1.06811e+07 | 96190.9 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4217.25 | 1.53013 | 21.8795ms | 399947 | 30 | 5.74546e+07 | 90442.7 | 1(Win) |
| simdjson | 3414.8 | 0.789489 | 27.1549ms | 399947 | 30 | 2.33285e+07 | 111696 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1070.27 | 0.567548 | 57.8621ms | 264040 | 30 | 5.3491e+07 | 235276 | 1(Win) |
| simdjson | 905.997 | 0.326791 | 68.2827ms | 264040 | 30 | 2.47485e+07 | 277935 | 2(Loss) |
| glaze | 862.835 | 0.323231 | 70.3575ms | 264040 | 30 | 2.66951e+07 | 291838 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2366.5 | 0.594543 | 26.0609ms | 264040 | 30 | 1.20065e+07 | 106405 | 1(Win) |
| glaze | 2319.15 | 0.743662 | 26.5712ms | 263923 | 30 | 1.95421e+07 | 108530 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1289.08 | 0.364873 | 73.3757ms | 409612 | 30 | 3.66771e+07 | 303036 | 1(Win) |
| glaze | 1040.42 | 0.361677 | 91.4443ms | 409612 | 30 | 5.53208e+07 | 375459 | 2(Loss) |
| jsonifier | 348.918 | 0.508704 | 267.421ms | 409612 | 30 | 9.73083e+08 | 1.11956e+06 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2821.45 | 0.639947 | 33.0295ms | 399947 | 30 | 2.24527e+07 | 135185 | 1(Win) |
| glaze | 2016.02 | 0.582225 | 46.7327ms | 399830 | 30 | 3.63802e+07 | 189139 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1320.91 | 0.332979 | 81.4365ms | 466906 | 30 | 3.7798e+07 | 337099 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1309.88 | 0.271533 | 82.0907ms | 466906 | 30 | 2.55601e+07 | 339937 | 1(Tie) |
| simdjson | 662.126 | 0.158004 | 162.858ms | 466906 | 30 | 3.38714e+07 | 672494 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1922.33 | 0.600722 | 83.8508ms | 699405 | 30 | 1.30338e+08 | 346977 | 1(Win) |
| glaze | 1607.5 | 0.460107 | 99.3149ms | 699405 | 30 | 1.09344e+08 | 414933 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1928.09 | 0.291292 | 75.5665ms | 631514 | 30 | 2.48366e+07 | 312361 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1922.27 | 1.49428 | 73.8265ms | 631514 | 30 | 6.57544e+08 | 313306 | 1(Tie) |
