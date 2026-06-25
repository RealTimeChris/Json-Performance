# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.26200 using the MSVC 19.44.35228.0 compiler).  

Latest Results: (Jun 27, 2026)
#### Using the following commits:
----
| Jsonifier: [ece766e](https://github.com/RealTimeChris/Jsonifier/commit/ece766e)  
| Glaze: [c60d5f6](https://github.com/stephenberry/glaze/commit/c60d5f6)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 679.962 | 0.358157 | 1.9035ms | 1811 | 30 | 2482.76 | 2540 | 1(Win) |
| glaze | 359.564 | 0.0693963 | 2.4183ms | 1811 | 30 | 333.333 | 4803.33 | 2(Loss) |
| simdjson | 191.9 | 0.150681 | 3.4556ms | 1811 | 30 | 5517.24 | 9000 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 658.362 | 0.39553 | 1.8622ms | 1811 | 30 | 3229.89 | 2623.33 | 1(Win) |
| glaze | 401.688 | 0.155431 | 7.9319ms | 1798 | 64 | 2817.46 | 4268.75 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2352.6 | 0.542015 | 1.6057ms | 3873 | 30 | 2172.41 | 1570 | 1(Win) |
| glaze | 1411.56 | 0.264476 | 1.8711ms | 3873 | 30 | 1436.78 | 2616.67 | 2(Loss) |
| simdjson | 397.017 | 0.0358295 | 3.4907ms | 3873 | 30 | 333.333 | 9303.33 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3230.54 | 0.804828 | 1.4951ms | 3873 | 30 | 2540.23 | 1143.33 | 1(Win) |
| glaze | 1487.35 | 0.390147 | 1.7859ms | 3873 | 30 | 2816.09 | 2483.33 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2360.96 | 0.583152 | 1.6157ms | 3862 | 30 | 2482.76 | 1560 | 1(Win) |
| glaze | 1321.68 | 0.226523 | 1.9689ms | 3862 | 30 | 1195.4 | 2786.67 | 2(Loss) |
| simdjson | 393.256 | 0.0910832 | 7.1966ms | 3862 | 32 | 2328.63 | 9365.62 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3060.74 | 0.277008 | 1.5519ms | 3862 | 30 | 333.333 | 1203.33 | 1(Win) |
| glaze | 1413.18 | 1.38832 | 3.4148ms | 3862 | 32 | 41895.2 | 2606.25 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1250.83 | 0.807371 | 1.3927ms | 905 | 30 | 931.034 | 690 | 1(Win) |
| glaze | 398.342 | 0.40402 | 1.7043ms | 905 | 30 | 2298.85 | 2166.67 | 2(Loss) |
| simdjson | 153.754 | 0.112454 | 2.5292ms | 905 | 30 | 1195.4 | 5613.33 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 892.836 | 0.905562 | 1.5615ms | 905 | 30 | 2298.85 | 966.667 | 1(Win) |
| glaze | 305.694 | 0.278183 | 1.8828ms | 905 | 30 | 1850.57 | 2823.33 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3659.2 | 0.308127 | 3.3457ms | 8813 | 32 | 1602.82 | 2296.88 | 1(Win) |
| glaze | 1888.7 | 0.208646 | 2.329ms | 8813 | 30 | 2586.21 | 4450 | 2(Loss) |
| simdjson | 712.064 | 0.0951203 | 4.0885ms | 8813 | 30 | 3781.61 | 11803.3 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3212 | 0.264476 | 1.9506ms | 8813 | 30 | 1436.78 | 2616.67 | 1(Win) |
| glaze | 2945.58 | 0.324677 | 1.9037ms | 8813 | 30 | 2574.71 | 2853.33 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1383.64 | 1.3536 | 7.3606ms | 33713 | 30 | 2.96792e+06 | 23236.7 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1382.45 | 1.47037 | 6.8896ms | 33713 | 30 | 3.50806e+06 | 23256.7 | 1(Tie) |
| simdjson | 775.788 | 1.28915 | 11.3499ms | 33713 | 30 | 8.56323e+06 | 41443.3 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3827.84 | 0.139146 | 6.1323ms | 33689 | 30 | 4091.95 | 8393.33 | 1(Win) |
| jsonifier | 1684.19 | 2.04635 | 6.6497ms | 33713 | 30 | 4.57817e+06 | 19090 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1754.31 | 1.45922 | 7.579ms | 48024 | 30 | 4.35375e+06 | 26106.7 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1718.33 | 2.25125 | 7.7198ms | 48024 | 30 | 1.08012e+07 | 26653.3 | 1(Tie) |
| simdjson | 1060.41 | 1.317 | 11.7381ms | 48024 | 30 | 9.70645e+06 | 43190 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3975.99 | 1.75283 | 134.091ms | 48024 | 512 | 2.08726e+07 | 11518.9 | 1(Win) |
| glaze | 3650.25 | 1.18508 | 18.2408ms | 48000 | 64 | 1.41356e+06 | 12540.6 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5320.11 | 0.189139 | 2.9614ms | 33713 | 30 | 3919.54 | 6043.33 | 1(Win) |
| simdjson | 1498.66 | 1.59819 | 6.3651ms | 33713 | 30 | 3.52671e+06 | 21453.3 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6778.01 | 1.67225 | 20.2239ms | 48024 | 128 | 1.63428e+06 | 6757.03 | 1(Win) |
| simdjson | 2058.68 | 1.50713 | 14.5773ms | 48024 | 32 | 3.59741e+06 | 22246.9 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 803.818 | 2.4386 | 321.496ms | 94651 | 128 | 9.59903e+08 | 112297 | 1(Win) |
| glaze | 719.06 | 2.15207 | 308.354ms | 94651 | 128 | 9.34202e+08 | 125534 | 2(Loss) |
| simdjson | 601.142 | 1.50834 | 193.469ms | 94651 | 64 | 3.28301e+08 | 150158 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4835.96 | 1.44447 | 100.109ms | 94651 | 256 | 1.86098e+07 | 18665.6 | 1(Win) |
| jsonifier | 3591.97 | 1.45218 | 7.4041ms | 94651 | 30 | 3.99528e+06 | 25130 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1153.96 | 2.04579 | 68.2819ms | 136024 | 32 | 1.69249e+08 | 112416 | 1(Win) |
| glaze | 1022.67 | 2.11089 | 31.9948ms | 136024 | 30 | 2.15085e+08 | 126847 | 2(Loss) |
| simdjson | 867.652 | 1.61973 | 37.9501ms | 136024 | 30 | 1.75932e+08 | 149510 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4656.43 | 1.32527 | 8.1995ms | 136046 | 30 | 4.09068e+06 | 27863.3 | 1(Win) |
| jsonifier | 3348.54 | 1.02557 | 10.8436ms | 136024 | 30 | 4.73559e+06 | 38740 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 385.785 | 0.845607 | 1251.8ms | 2090234 | 30 | 5.72741e+10 | 5.16713e+06 | 1(Win) |
| glaze | 362.301 | 0.682916 | 1268.56ms | 2090234 | 30 | 4.23553e+10 | 5.50207e+06 | 2(Loss) |
| simdjson | 276.208 | 0.48033 | 1746.49ms | 2090234 | 30 | 3.60509e+10 | 7.21702e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1014.38 | 0.531114 | 476.471ms | 2090234 | 30 | 3.26801e+09 | 1.96514e+06 | 1(Win) |
| glaze | 741.76 | 0.530849 | 639.687ms | 2090234 | 30 | 6.10557e+09 | 2.6874e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1069.79 | 0.609439 | 1465.92ms | 6661897 | 30 | 3.92987e+10 | 5.93879e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1061.28 | 0.676324 | 1443.45ms | 6661897 | 30 | 4.91773e+10 | 5.98642e+06 | 1(Tie) |
| simdjson | 822.815 | 0.43383 | 1867.84ms | 6661897 | 30 | 3.36629e+10 | 7.72139e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1761.92 | 0.741346 | 2075.21ms | 6661897 | 32 | 2.28673e+10 | 3.60588e+06 | 1(Win) |
| glaze | 1130.84 | 1.14692 | 1380.18ms | 6661897 | 30 | 1.24559e+11 | 5.61818e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 890.563 | 0.478381 | 132.285ms | 500299 | 30 | 1.97061e+08 | 535753 | 1(Win) |
| glaze | 870.73 | 0.935288 | 133.04ms | 500299 | 30 | 7.87961e+08 | 547957 | 2(Loss) |
| simdjson | 457.772 | 0.34779 | 253.338ms | 500299 | 30 | 3.94199e+08 | 1.04227e+06 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4704.27 | 2.09405 | 25.7082ms | 500299 | 30 | 1.35323e+08 | 101423 | 1(Win) |
| glaze | 4377 | 1.68202 | 27.8185ms | 500299 | 30 | 1.00854e+08 | 109007 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1938.43 | 0.653874 | 168.984ms | 1439562 | 30 | 6.43384e+08 | 708240 | 1(Win) |
| jsonifier | 1854.52 | 0.670506 | 178.073ms | 1439562 | 30 | 7.39141e+08 | 740287 | 2(Loss) |
| simdjson | 1231.69 | 0.446974 | 269.762ms | 1439562 | 30 | 7.44632e+08 | 1.11462e+06 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2506.48 | 1.24907 | 130.093ms | 1439562 | 30 | 1.40419e+09 | 547730 | 1(Win) |
| glaze | 1343 | 0.951986 | 250.294ms | 1439584 | 30 | 2.84122e+09 | 1.02226e+06 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1380.39 | 1.1801 | 24.0508ms | 56369 | 32 | 6.75867e+06 | 38943.8 | 1(Win) |
| glaze | 1261.32 | 1.48421 | 11.9839ms | 56369 | 30 | 1.20044e+07 | 42620 | 2(Loss) |
| simdjson | 565.553 | 1.15635 | 24.2246ms | 56369 | 30 | 3.6244e+07 | 95053.3 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5008.48 | 0.237777 | 3.9083ms | 56369 | 30 | 19540.2 | 10733.3 | 1(Win) |
| glaze | 4383.91 | 2.09861 | 8.9763ms | 56369 | 32 | 2.11919e+06 | 12262.5 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1819.98 | 2.13345 | 13.1742ms | 94370 | 30 | 3.33902e+07 | 49450 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1818.27 | 1.05147 | 13.0929ms | 94370 | 30 | 8.12585e+06 | 49496.7 | 1(Tie) |
| simdjson | 933.172 | 1.04601 | 24.7712ms | 94370 | 30 | 3.05308e+07 | 96443.3 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4512.7 | 1.8804 | 5.9683ms | 94370 | 30 | 4.21909e+06 | 19943.3 | 1(Win) |
| glaze | 4038.21 | 2.01628 | 6.9142ms | 94370 | 30 | 6.05775e+06 | 22286.7 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1254.04 | 1.40955 | 11.5538ms | 52708 | 30 | 9.57661e+06 | 40083.3 | 1(Win) |
| glaze | 1029.58 | 1.36266 | 30.0739ms | 52708 | 32 | 1.41631e+07 | 48821.9 | 2(Loss) |
| simdjson | 810.049 | 0.998403 | 16.3569ms | 52708 | 30 | 1.1515e+07 | 62053.3 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5742.67 | 1.39165 | 6.9946ms | 52708 | 32 | 474829 | 8753.12 | 1(Win) |
| glaze | 4681.38 | 1.97181 | 29.5715ms | 52708 | 128 | 5.7378e+06 | 10737.5 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1478.69 | 1.02458 | 28.5334ms | 70103 | 32 | 6.86694e+06 | 45212.5 | 1(Win) |
| glaze | 1246.84 | 1.09917 | 14.4168ms | 70103 | 30 | 1.0421e+07 | 53620 | 2(Loss) |
| simdjson | 1097.79 | 0.929543 | 16.6582ms | 70103 | 30 | 9.61379e+06 | 60900 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4947.37 | 1.68962 | 4.6708ms | 70103 | 30 | 1.56395e+06 | 13513.3 | 1(Win) |
| glaze | 3935.76 | 1.96342 | 5.8709ms | 70103 | 30 | 3.33706e+06 | 16986.7 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 944.885 | 1.08945 | 8.7926ms | 11812 | 32 | 539829 | 11921.9 | 1(Win) |
| glaze | 805.204 | 1.65833 | 4.5773ms | 11812 | 30 | 1.61472e+06 | 13990 | 2(Loss) |
| simdjson | 478.946 | 1.51572 | 7.0329ms | 11812 | 30 | 3.81269e+06 | 23520 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3455.46 | 0.31544 | 2.0349ms | 11812 | 30 | 3172.41 | 3260 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3451.93 | 0.274215 | 2.1403ms | 11812 | 30 | 2402.3 | 3263.33 | 1(Tie) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1733.21 | 0.138741 | 5.4417ms | 31235 | 30 | 17057.5 | 17186.7 | 1(Win) |
| glaze | 1631.92 | 2.13181 | 5.6716ms | 31235 | 30 | 4.54257e+06 | 18253.3 | 2(Loss) |
| simdjson | 1188.04 | 1.65968 | 7.4684ms | 31235 | 30 | 5.19513e+06 | 25073.3 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 5063.12 | 0.38297 | 2.7188ms | 31235 | 30 | 15229.9 | 5883.33 | 1(Win) |
| jsonifier | 4483.62 | 2.18282 | 10.5261ms | 31235 | 64 | 1.34599e+06 | 6643.75 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1978.71 | 0.781252 | 14.0315ms | 108313 | 30 | 4.98999e+06 | 52203.3 | 1(Win) |
| glaze | 1312.85 | 0.960073 | 20.507ms | 108313 | 30 | 1.71182e+07 | 78680 | 2(Loss) |
| simdjson | 626.615 | 0.771404 | 41.1638ms | 108313 | 30 | 4.85115e+07 | 164847 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4682.47 | 1.68993 | 6.4975ms | 108313 | 30 | 4.16938e+06 | 22060 | 1(Win) |
| glaze | 4284.93 | 1.96118 | 7.4597ms | 108313 | 30 | 6.70547e+06 | 24106.7 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2336.37 | 1.30193 | 22.5054ms | 213963 | 30 | 3.87872e+07 | 87336.7 | 1(Win) |
| glaze | 2018.44 | 0.765043 | 25.8639ms | 213963 | 30 | 1.79448e+07 | 101093 | 2(Loss) |
| simdjson | 1185.24 | 0.752171 | 43.1464ms | 213963 | 30 | 5.03059e+07 | 172160 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5263.57 | 1.25328 | 10.7764ms | 213963 | 30 | 7.08161e+06 | 38766.7 | 1(Win) |
| glaze | 4105.38 | 2.04746 | 13.2818ms | 213963 | 30 | 3.10686e+07 | 49703.3 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 350.099 | 0.845438 | 1188.3ms | 1834197 | 30 | 5.35297e+10 | 4.99638e+06 | 1(Win) |
| glaze | 300.441 | 0.925183 | 1423.11ms | 1834197 | 30 | 8.70463e+10 | 5.8222e+06 | 2(Loss) |
| simdjson | 231.681 | 0.743872 | 1806.74ms | 1834197 | 30 | 9.46301e+10 | 7.55016e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 679.264 | 0.814813 | 600.27ms | 1834197 | 30 | 1.32085e+10 | 2.57518e+06 | 1(Win) |
| glaze | 536.742 | 0.427773 | 783.013ms | 1833577 | 30 | 5.8266e+09 | 3.25787e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1565.39 | 0.713155 | 1465.9ms | 9930848 | 30 | 5.58495e+10 | 6.05013e+06 | 1(Win) |
| glaze | 1364.51 | 0.841124 | 1666.08ms | 9930848 | 30 | 1.02249e+11 | 6.94078e+06 | 2(Loss) |
| simdjson | 1165.48 | 0.657546 | 1961.85ms | 9930848 | 30 | 8.56518e+10 | 8.12608e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1735.24 | 0.741418 | 1323.8ms | 9930848 | 30 | 4.91249e+10 | 5.45791e+06 | 1(Win) |
| glaze | 873.241 | 1.99399 | 2610.83ms | 9930228 | 30 | 1.40287e+12 | 1.08449e+07 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1034.35 | 1.65335 | 144.5ms | 642697 | 30 | 2.87959e+09 | 592570 | 1(Win) |
| glaze | 676.763 | 1.89776 | 214.742ms | 642697 | 30 | 8.86221e+09 | 905670 | 2(Loss) |
| simdjson | 512.267 | 0.237839 | 291.534ms | 642697 | 30 | 2.42944e+08 | 1.19649e+06 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1446.72 | 0.637271 | 102.608ms | 642697 | 30 | 2.18681e+08 | 423663 | 1(Win) |
| glaze | 603.435 | 0.531069 | 245.806ms | 642692 | 30 | 8.72906e+08 | 1.01572e+06 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1597.16 | 1.64316 | 175.343ms | 1225964 | 30 | 4.34052e+09 | 732030 | 1(Win) |
| glaze | 1238.1 | 1.39702 | 229.087ms | 1225964 | 30 | 5.22124e+09 | 944330 | 2(Loss) |
| simdjson | 939.636 | 0.422261 | 300.202ms | 1225964 | 30 | 8.28169e+08 | 1.24428e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1428.45 | 0.616689 | 194.674ms | 1225964 | 30 | 7.64322e+08 | 818487 | 1(Win) |
| glaze | 1171.51 | 0.588547 | 242.304ms | 1225970 | 30 | 1.03502e+09 | 998007 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 819.984 | 0.635493 | 116.344ms | 409725 | 30 | 2.75117e+08 | 476527 | 1(Win) |
| glaze | 599.592 | 0.474256 | 157.357ms | 409725 | 30 | 2.86564e+08 | 651683 | 2(Loss) |
| simdjson | 476.475 | 0.369599 | 198.797ms | 409725 | 30 | 2.75605e+08 | 820073 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2805.19 | 1.33236 | 34.8703ms | 409725 | 30 | 1.0333e+08 | 139293 | 1(Win) |
| jsonifier | 2515.41 | 0.58157 | 39.1466ms | 409725 | 30 | 2.44846e+07 | 155340 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1252.83 | 0.541592 | 144.809ms | 785750 | 30 | 3.14812e+08 | 598127 | 1(Win) |
| glaze | 1001.37 | 0.356291 | 182.064ms | 785750 | 30 | 2.13262e+08 | 748327 | 2(Loss) |
| simdjson | 881.93 | 0.29835 | 205.227ms | 785750 | 30 | 1.92786e+08 | 849670 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3071.48 | 0.92432 | 59.1644ms | 785750 | 30 | 1.52559e+08 | 243970 | 1(Win) |
| glaze | 1665.13 | 1.09483 | 109.895ms | 785750 | 30 | 7.28252e+08 | 450023 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5151.91 | 0.956514 | 13.2133ms | 264040 | 30 | 6.55702e+06 | 48876.7 | 1(Win) |
| simdjson | 1944.01 | 0.698234 | 32.4361ms | 264040 | 30 | 2.45394e+07 | 129530 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6800.53 | 0.864921 | 15.0489ms | 399947 | 30 | 7.05982e+06 | 56086.7 | 1(Win) |
| simdjson | 2792.44 | 0.691841 | 34.4394ms | 399947 | 30 | 2.67899e+07 | 136590 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1591.34 | 0.839148 | 39.6767ms | 264040 | 30 | 5.28948e+07 | 158237 | 1(Win) |
| glaze | 1011.62 | 0.753263 | 60.9613ms | 264040 | 30 | 1.05468e+08 | 248917 | 2(Loss) |
| simdjson | 772.9 | 1.95297 | 78.7011ms | 264040 | 30 | 1.21452e+09 | 325797 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5460.24 | 1.54664 | 12.386ms | 264040 | 30 | 1.52621e+07 | 46116.7 | 1(Win) |
| glaze | 4386.23 | 1.36043 | 15.241ms | 263923 | 30 | 1.82828e+07 | 57383.3 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1822.85 | 0.585521 | 51.8528ms | 399947 | 30 | 4.50308e+07 | 209243 | 1(Win) |
| glaze | 1351.7 | 0.678949 | 69.7652ms | 399947 | 30 | 1.10113e+08 | 282177 | 2(Loss) |
| simdjson | 1202.43 | 0.554698 | 78.2313ms | 399947 | 30 | 9.28793e+07 | 317207 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5487.52 | 1.17596 | 18.1143ms | 399947 | 30 | 2.00427e+07 | 69506.7 | 1(Win) |
| glaze | 3456.07 | 1.58548 | 134.167ms | 399830 | 64 | 1.95832e+08 | 110330 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2535.55 | 0.974696 | 43.8049ms | 466906 | 30 | 8.78971e+07 | 175613 | 1(Win) |
| glaze | 2182.66 | 0.629235 | 50.23ms | 466906 | 30 | 4.94351e+07 | 204007 | 2(Loss) |
| simdjson | 1158.6 | 2.23623 | 90.7736ms | 466906 | 30 | 2.21588e+09 | 384323 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3179.39 | 1.17219 | 51.37ms | 699405 | 30 | 1.81422e+08 | 209790 | 1(Win) |
| glaze | 2856.31 | 0.477237 | 57.4605ms | 699405 | 30 | 3.72596e+07 | 233520 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4357.98 | 0.464651 | 34.9333ms | 631514 | 30 | 1.237e+07 | 138197 | 1(Win) |
| glaze | 3678.81 | 1.35325 | 39.8562ms | 631514 | 30 | 1.47241e+08 | 163710 | 2(Loss) |
