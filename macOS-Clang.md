# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 24.6.0 using the Clang 22.1.8 compiler).  

Latest Results: (Jun 28, 2026)
#### Using the following commits:
----
| Jsonifier: [7b921fc](https://github.com/RealTimeChris/Jsonifier/commit/7b921fc)  
| Glaze: [c60d5f6](https://github.com/stephenberry/glaze/commit/c60d5f6)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Apple M1 (Virtual)): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 771.419 | 0.332752 | 5.11671ms | 1811 | 30 | 1665.02 | 2238.87 | 1(Win) |
| glaze | 478.626 | 0.196083 | 2.11554ms | 1811 | 30 | 1501.91 | 3608.47 | 2(Loss) |
| simdjson | 182.15 | 0.0519186 | 6.79288ms | 1811 | 32 | 775.484 | 9481.75 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 390.197 | 0.26342 | 1.62746ms | 1798 | 30 | 4020.05 | 4394.47 | 1(Win) |
| jsonifier | 375.351 | 0.52945 | 2.55754ms | 1811 | 30 | 17804.6 | 4601.3 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1545.26 | 0.195778 | 1.12029ms | 3873 | 30 | 656.961 | 2390.27 | 1(Win) |
| glaze | 877.398 | 0.301299 | 1.65029ms | 3873 | 30 | 4826.36 | 4209.7 | 2(Loss) |
| simdjson | 404.137 | 0.713172 | 6.413ms | 3873 | 32 | 135949 | 9139.44 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1701.41 | 0.29635 | 0.918958ms | 3873 | 30 | 1241.68 | 2170.9 | 1(Win) |
| glaze | 1226.03 | 0.318761 | 1.32204ms | 3873 | 30 | 2766.59 | 3012.63 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1438.82 | 0.643019 | 1.37138ms | 3862 | 30 | 8127.96 | 2559.8 | 1(Win) |
| glaze | 921.418 | 0.12149 | 1.87554ms | 3862 | 30 | 707.476 | 3997.2 | 2(Loss) |
| simdjson | 403.133 | 0.238339 | 2.81229ms | 3862 | 30 | 14224.6 | 9136.17 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1791.73 | 0.297787 | 1.06846ms | 3862 | 30 | 1124.11 | 2055.6 | 1(Win) |
| glaze | 1168.22 | 0.360038 | 1.86379ms | 3862 | 30 | 3865.37 | 3152.73 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1021.91 | 0.468783 | 0.657333ms | 905 | 30 | 470.254 | 844.567 | 1(Win) |
| glaze | 318.501 | 0.38666 | 1.27229ms | 905 | 30 | 3293.48 | 2709.8 | 2(Loss) |
| simdjson | 175.986 | 0.211848 | 1.65175ms | 905 | 30 | 3238.25 | 4904.23 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 732.786 | 0.290784 | 1.32075ms | 905 | 30 | 351.89 | 1177.8 | 1(Win) |
| glaze | 355.985 | 0.142977 | 2.13075ms | 905 | 32 | 384.515 | 2424.47 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/String%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2242.9 | 0.118828 | 1.50008ms | 8813 | 30 | 594.823 | 3747.27 | 1(Win) |
| glaze | 1556.02 | 0.130744 | 1.84104ms | 8813 | 30 | 1496.19 | 5401.43 | 2(Loss) |
| simdjson | 705.377 | 0.106701 | 3.36692ms | 8813 | 30 | 4849.15 | 11915.2 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/String%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2273.31 | 0.131269 | 1.35717ms | 8813 | 30 | 706.602 | 3697.13 | 1(Win) |
| jsonifier | 2159.51 | 0.365561 | 2.79396ms | 8813 | 32 | 6477.52 | 3891.97 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1637.82 | 0.0428958 | 5.34183ms | 33713 | 30 | 2127.22 | 19630.5 | 1(Win) |
| glaze | 1408.34 | 0.23408 | 6.04729ms | 33713 | 30 | 85671 | 22829.2 | 2(Loss) |
| simdjson | 1111.33 | 0.164605 | 9.57471ms | 33713 | 30 | 68033 | 28930.5 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2994.67 | 0.374862 | 3.58954ms | 33713 | 30 | 48591.4 | 10736.1 | 1(Win) |
| glaze | 2334.72 | 0.179346 | 4.49146ms | 33689 | 30 | 18273.1 | 13761.1 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1864.84 | 0.0798261 | 6.63008ms | 49505 | 30 | 12252.5 | 25316.7 | 1(Win) |
| jsonifier | 1583.32 | 0.739576 | 12.0108ms | 49505 | 30 | 1.45897e+06 | 29818.1 | 2(Loss) |
| simdjson | 1459.53 | 0.494632 | 8.59196ms | 49505 | 30 | 767996 | 32347.2 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3224.38 | 0.0474495 | 4.10708ms | 48024 | 30 | 1362.72 | 14204 | 1(Win) |
| glaze | 2183.44 | 1.85187 | 6.14404ms | 48000 | 30 | 4.52215e+06 | 20965.3 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3754.27 | 0.0896788 | 2.65983ms | 33713 | 30 | 1769.47 | 8563.9 | 1(Win) |
| simdjson | 3658.76 | 0.0571048 | 2.63417ms | 33713 | 30 | 755.43 | 8787.47 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4491.94 | 0.0591411 | 2.92121ms | 48024 | 30 | 1090.81 | 10195.9 | 1(Win) |
| simdjson | 4143.73 | 0.093732 | 3.09492ms | 48024 | 30 | 3219.82 | 11052.7 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 912.485 | 0.317259 | 25.2507ms | 94651 | 30 | 2.95494e+06 | 98923.6 | 1(Win) |
| simdjson **STATISTICAL TIE** | 807.272 | 0.397665 | 65.0048ms | 94651 | 32 | 6.32696e+06 | 111816 | 2(Tie) |
| glaze **STATISTICAL TIE** | 806.538 | 0.237896 | 30.4524ms | 94651 | 30 | 2.12666e+06 | 111918 | 2(Tie) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3167.06 | 0.102849 | 7.43617ms | 94651 | 30 | 25778.8 | 28501.6 | 1(Win) |
| glaze | 2987.23 | 0.906638 | 24.0012ms | 94651 | 32 | 2.40177e+06 | 30217.4 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1150.19 | 0.262497 | 29.6949ms | 140436 | 30 | 2.80278e+06 | 116442 | 1(Win) |
| glaze | 1070.05 | 0.654575 | 32.8867ms | 140436 | 30 | 2.01367e+07 | 125162 | 2(Loss) |
| jsonifier | 1010.47 | 0.961318 | 32.2673ms | 140436 | 30 | 4.87046e+07 | 132543 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2631.36 | 0.0233249 | 12.7498ms | 136024 | 30 | 3966.72 | 49298.6 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2529.04 | 2.27157 | 13.6357ms | 136046 | 30 | 4.07412e+07 | 51301.4 | 1(Tie) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 533.73 | 0.155385 | 922.572ms | 2090234 | 30 | 1.01038e+09 | 3.73485e+06 | 1(Win) |
| jsonifier | 499.311 | 0.517038 | 984.791ms | 2090234 | 30 | 1.27825e+10 | 3.99231e+06 | 2(Loss) |
| simdjson | 361.189 | 0.150148 | 1374.23ms | 2090234 | 30 | 2.06007e+09 | 5.519e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1376.89 | 0.599133 | 377.147ms | 2090234 | 30 | 2.25715e+09 | 1.44776e+06 | 1(Win) |
| glaze | 1115.86 | 1.92917 | 384.75ms | 2090234 | 30 | 3.5631e+10 | 1.78642e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1299.05 | 1.15187 | 1199.11ms | 6885124 | 30 | 1.01695e+11 | 5.05458e+06 | 1(Win) |
| jsonifier | 1121.05 | 1.25729 | 3370.13ms | 6885124 | 32 | 1.73539e+11 | 5.85715e+06 | 2(Loss) |
| simdjson | 920.845 | 1.57789 | 1592.26ms | 6885124 | 30 | 3.79775e+11 | 7.13059e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2243.27 | 0.279316 | 718.347ms | 6661897 | 30 | 1.87735e+09 | 2.83215e+06 | 1(Win) |
| glaze | 1970.14 | 0.633028 | 796.81ms | 6661897 | 30 | 1.25016e+10 | 3.22478e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1083.99 | 0.621518 | 109.073ms | 500299 | 30 | 2.24511e+08 | 440154 | 1(Win) |
| glaze | 1020.58 | 0.251134 | 112.943ms | 500299 | 30 | 4.13522e+07 | 467501 | 2(Loss) |
| simdjson | 740.064 | 0.140872 | 157.668ms | 500299 | 30 | 2.47452e+07 | 644704 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2866.79 | 0.642499 | 40.8108ms | 500299 | 30 | 3.43031e+07 | 166431 | 1(Win) |
| glaze | 1642.58 | 1.03192 | 169.957ms | 500299 | 32 | 2.87509e+08 | 290471 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2079.86 | 0.564578 | 197.078ms | 1490030 | 30 | 4.46365e+08 | 683219 | 1(Win) |
| jsonifier | 1884.24 | 2.31096 | 478.983ms | 1490030 | 32 | 9.7197e+09 | 754154 | 2(Loss) |
| simdjson | 1728.01 | 0.334779 | 203.862ms | 1490030 | 30 | 2.27372e+08 | 822336 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3542.91 | 0.532192 | 95.6922ms | 1439562 | 30 | 1.27585e+08 | 387499 | 1(Win) |
| glaze | 2197.83 | 0.683573 | 158.063ms | 1439584 | 30 | 5.46988e+08 | 624660 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1583.18 | 0.312268 | 9.11213ms | 56369 | 30 | 337287 | 33955.6 | 1(Win) |
| glaze | 1189.91 | 0.509967 | 11.121ms | 56369 | 30 | 1.59242e+06 | 45177.8 | 2(Loss) |
| simdjson | 975.448 | 0.49888 | 38.1543ms | 56369 | 32 | 2.41888e+06 | 55110.8 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2567.38 | 0.296708 | 6.16338ms | 56369 | 30 | 115792 | 20938.7 | 1(Win) |
| glaze | 2388.93 | 0.274865 | 6.28975ms | 56369 | 30 | 114772 | 22502.9 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1843.14 | 0.143906 | 12.5194ms | 98048 | 30 | 159898 | 50731.9 | 1(Win) |
| glaze | 1766.12 | 0.346894 | 13.1235ms | 98048 | 30 | 1.01194e+06 | 52944.4 | 2(Loss) |
| simdjson | 1606.97 | 0.611256 | 16.0619ms | 98048 | 30 | 3.79514e+06 | 58187.5 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3155.22 | 0.0896962 | 7.94238ms | 94370 | 30 | 19637.1 | 28523.6 | 1(Win) |
| glaze | 2174.78 | 1.9156 | 52.1307ms | 94370 | 64 | 4.02186e+07 | 41382.8 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1467.21 | 0.0496255 | 9.87033ms | 52708 | 30 | 8671.66 | 34259.8 | 1(Win) |
| glaze | 1293.63 | 1.10478 | 10.5863ms | 52708 | 30 | 5.52851e+06 | 38856.8 | 2(Loss) |
| simdjson | 1105.16 | 0.394837 | 28.3951ms | 52708 | 32 | 1.03201e+06 | 45483.1 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3762.51 | 0.15497 | 3.73096ms | 52708 | 30 | 12859.3 | 13359.8 | 1(Win) |
| glaze | 3086.72 | 0.492326 | 5.119ms | 52708 | 30 | 192835 | 16284.7 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1665.82 | 0.0822936 | 10.5422ms | 71665 | 30 | 34198.7 | 41027.8 | 1(Win) |
| glaze **STATISTICAL TIE** | 1572.81 | 1.71564 | 11.1642ms | 71665 | 30 | 1.66738e+07 | 43454.2 | 2(Tie) |
| jsonifier **STATISTICAL TIE** | 1518.97 | 1.21832 | 13.0869ms | 71665 | 30 | 9.01485e+06 | 44994.4 | 2(Tie) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4101.55 | 0.0665326 | 4.87533ms | 70103 | 30 | 3528.31 | 16300 | 1(Win) |
| glaze | 3253.96 | 0.393826 | 5.90625ms | 70103 | 30 | 196417 | 20545.9 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1075.54 | 0.0903394 | 2.95179ms | 11812 | 30 | 2685.77 | 10473.6 | 1(Win) |
| glaze | 791.132 | 0.357767 | 3.9305ms | 11812 | 30 | 77852 | 14238.8 | 2(Loss) |
| simdjson | 661.608 | 0.343635 | 4.84429ms | 11812 | 30 | 102698 | 17026.4 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1677.15 | 0.417052 | 2.83242ms | 11812 | 30 | 23540 | 6716.63 | 1(Win) |
| glaze | 1480.02 | 0.521196 | 2.55529ms | 11812 | 30 | 47210.3 | 7611.27 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1776.68 | 0.050942 | 4.94871ms | 32403 | 30 | 2355.2 | 17393.1 | 1(Win) |
| jsonifier | 1672 | 0.0722833 | 5.40804ms | 32403 | 30 | 5354.21 | 18482 | 2(Loss) |
| simdjson | 1651.41 | 0.0642719 | 4.92329ms | 32403 | 30 | 4339.36 | 18712.5 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3348.06 | 0.107003 | 12.8299ms | 31235 | 30 | 2718.99 | 8897.1 | 1(Win) |
| glaze | 2194.1 | 0.350416 | 3.96192ms | 31235 | 30 | 67898.7 | 13576.4 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2500.59 | 0.0765755 | 10.6835ms | 108313 | 30 | 30017.8 | 41308.4 | 1(Win) |
| glaze | 1218.51 | 0.710759 | 20.8153ms | 108313 | 30 | 1.08911e+07 | 84772.2 | 2(Loss) |
| simdjson | 985.853 | 1.01677 | 26.3734ms | 108313 | 30 | 3.40487e+07 | 104778 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2656.92 | 0.106359 | 9.72117ms | 108313 | 30 | 51295.3 | 38877.9 | 1(Win) |
| glaze | 1480.7 | 1.86888 | 18.1512ms | 108313 | 30 | 5.09931e+07 | 69761.2 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2495.3 | 0.298595 | 52.477ms | 222373 | 32 | 2.06078e+06 | 84988.2 | 1(Win) |
| glaze | 2031.71 | 0.568807 | 26.0495ms | 222373 | 30 | 1.05753e+07 | 104381 | 2(Loss) |
| simdjson | 1763.98 | 0.323724 | 31.9327ms | 222373 | 30 | 4.54413e+06 | 120224 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3606.11 | 0.467775 | 14.334ms | 213963 | 30 | 2.10181e+06 | 56584.7 | 1(Win) |
| glaze | 1869.12 | 1.39492 | 27.4112ms | 213963 | 30 | 6.95699e+07 | 109169 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 410.72 | 1.28402 | 2444.71ms | 1834197 | 32 | 9.5696e+10 | 4.25892e+06 | 1(Win) |
| jsonifier | 387.244 | 0.295659 | 1101.84ms | 1834197 | 30 | 5.35087e+09 | 4.51711e+06 | 2(Loss) |
| simdjson | 357.934 | 0.808055 | 1190.39ms | 1834197 | 30 | 4.67832e+10 | 4.88701e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 794.039 | 1.05738 | 531.381ms | 1834197 | 30 | 1.62776e+10 | 2.20295e+06 | 1(Win) |
| glaze | 646.155 | 1.93216 | 653.032ms | 1833577 | 30 | 8.20226e+10 | 2.70622e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1791.16 | 1.04688 | 3033.3ms | 10252236 | 32 | 1.04498e+11 | 5.45863e+06 | 1(Win) |
| simdjson | 1679.06 | 0.57905 | 1431.76ms | 10252236 | 30 | 3.41082e+10 | 5.82308e+06 | 2(Loss) |
| jsonifier | 1389.93 | 1.79874 | 3564.92ms | 10252236 | 32 | 5.12313e+11 | 7.03435e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2343.79 | 0.784421 | 995.55ms | 9930848 | 30 | 3.0141e+10 | 4.04081e+06 | 1(Win) |
| glaze | 1197.6 | 1.56682 | 1701.37ms | 9930228 | 30 | 4.60523e+11 | 7.90765e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 945.854 | 0.26174 | 152.316ms | 642697 | 30 | 8.63028e+07 | 648011 | 1(Win) |
| jsonifier | 738.446 | 0.693945 | 197.645ms | 642697 | 30 | 9.95284e+08 | 830018 | 2(Loss) |
| simdjson | 636.247 | 1.08326 | 241.644ms | 642697 | 30 | 3.26701e+09 | 963342 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1312.8 | 0.440808 | 116.52ms | 642697 | 30 | 1.27068e+08 | 466882 | 1(Win) |
| glaze | 880.805 | 0.516384 | 166.246ms | 642692 | 30 | 3.87358e+08 | 695862 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1789.1 | 0.547851 | 164.781ms | 1306201 | 30 | 4.36513e+08 | 696267 | 1(Win) |
| jsonifier | 1437.4 | 0.602307 | 201.279ms | 1306201 | 30 | 8.17371e+08 | 866625 | 2(Loss) |
| simdjson | 1073.6 | 2.11033 | 250.266ms | 1306201 | 30 | 1.79871e+10 | 1.1603e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2121.28 | 0.237246 | 132.526ms | 1225964 | 30 | 5.12954e+07 | 551163 | 1(Win) |
| glaze | 1505.46 | 0.526325 | 195.833ms | 1225970 | 30 | 5.01244e+08 | 776624 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 760.534 | 1.16481 | 153.462ms | 409725 | 30 | 1.07443e+09 | 513776 | 1(Win) |
| simdjson | 696.56 | 0.496166 | 138.618ms | 409725 | 30 | 2.32404e+08 | 560962 | 2(Loss) |
| glaze | 665.421 | 0.866748 | 139.89ms | 409725 | 30 | 7.77141e+08 | 587214 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1914.85 | 0.297297 | 50.096ms | 409725 | 30 | 1.10412e+07 | 204060 | 1(Win) |
| glaze | 1540.68 | 2.27251 | 61.716ms | 409725 | 30 | 9.96534e+08 | 253618 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1312.27 | 0.418964 | 146.992ms | 814756 | 30 | 1.84621e+08 | 592111 | 1(Win) |
| jsonifier | 1189.6 | 0.609669 | 148.009ms | 814756 | 30 | 4.75731e+08 | 653169 | 2(Loss) |
| glaze | 1120.97 | 0.929135 | 157.332ms | 814756 | 30 | 1.24436e+09 | 693161 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2720.49 | 0.317354 | 155.232ms | 785750 | 32 | 2.44519e+07 | 275447 | 1(Win) |
| glaze | 1547.91 | 0.563375 | 104.441ms | 785750 | 30 | 2.23147e+08 | 484103 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3365.29 | 1.39675 | 18.6663ms | 264040 | 30 | 3.27681e+07 | 74825.1 | 1(Win) |
| simdjson | 3146.45 | 0.220508 | 19.773ms | 264040 | 30 | 934256 | 80029.2 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3798.63 | 0.356519 | 25.9538ms | 399947 | 30 | 3.84448e+06 | 100410 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 3758.85 | 0.600266 | 25.3653ms | 399947 | 30 | 1.11302e+07 | 101472 | 1(Tie) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1627.49 | 0.811308 | 1026.34ms | 264040 | 256 | 4.03381e+08 | 154722 | 1(Win) |
| glaze | 1392.46 | 0.217128 | 46.481ms | 264040 | 30 | 4.62518e+06 | 180837 | 2(Loss) |
| simdjson | 1244.62 | 0.413013 | 46.3454ms | 264040 | 30 | 2.09468e+07 | 202318 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3886.85 | 0.281609 | 16.9432ms | 264040 | 30 | 998527 | 64784.6 | 1(Win) |
| glaze | 2886.63 | 2.15397 | 51.6576ms | 263923 | 32 | 1.12876e+08 | 87193.9 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1846.01 | 1.88674 | 53.5376ms | 409612 | 30 | 4.78213e+08 | 211611 | 1(Win) |
| simdjson **STATISTICAL TIE** | 1657.97 | 1.56152 | 53.6745ms | 409612 | 30 | 4.06076e+08 | 235611 | 2(Tie) |
| glaze **STATISTICAL TIE** | 1639.85 | 1.58107 | 55.8633ms | 409612 | 30 | 4.25562e+08 | 238215 | 2(Tie) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4071.43 | 0.679524 | 23.0795ms | 399947 | 30 | 1.21575e+07 | 93682 | 1(Win) |
| glaze | 2900.8 | 2.48729 | 345.828ms | 399830 | 128 | 1.36829e+09 | 131449 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1820.3 | 0.353817 | 60.181ms | 466906 | 30 | 2.24725e+07 | 244617 | 1(Win) |
| jsonifier | 1483.88 | 0.715288 | 72.1445ms | 466906 | 30 | 1.38212e+08 | 300076 | 2(Loss) |
| simdjson | 792.935 | 0.515869 | 799.549ms | 466906 | 64 | 5.37085e+08 | 561555 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2183.75 | 0.245742 | 79.2596ms | 699405 | 30 | 1.69018e+07 | 305440 | 1(Win) |
| glaze | 1991.31 | 0.180807 | 82.1362ms | 699405 | 30 | 1.10036e+07 | 334958 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2556.71 | 0.360292 | 136.606ms | 631514 | 32 | 2.30495e+07 | 235560 | 1(Win) |
| glaze | 2136.4 | 1.67663 | 70.6788ms | 631514 | 30 | 6.70192e+08 | 281904 | 2(Loss) |
