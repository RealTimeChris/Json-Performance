# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 25.4.0 using the GCC 16.1.0 compiler).  

Latest Results: (Jul 02, 2026)
#### Using the following commits:
----
| Jsonifier: [6a2069c](https://github.com/RealTimeChris/Jsonifier/commit/6a2069c)  
| Glaze: [4fab045](https://github.com/stephenberry/glaze/commit/4fab045)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Apple M1 (Virtual)): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 953.148 | 1.98598 | 32.331ms | 1811 | 128 | 165759 | 1812 | 1(Win) |
| glaze | 703.791 | 1.85689 | 7.26502ms | 1811 | 128 | 265784 | 2454 | 2(Loss) |
| simdjson | 157.181 | 1.97276 | 28.642ms | 1811 | 128 | 6.01446e+06 | 10988 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 562.208 | 1.59821 | 0.852992ms | 1811 | 30 | 72315.6 | 3072 | 1(Win) |
| glaze | 409.043 | 1.81371 | 2.55514ms | 1798 | 32 | 184981 | 4192 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1550.62 | 1.86803 | 6.27405ms | 3873 | 128 | 253432 | 2382 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1545.43 | 1.84165 | 6.25997ms | 3873 | 128 | 247981 | 2390 | 1(Tie) |
| simdjson | 358.609 | 0.839991 | 2.68698ms | 3873 | 30 | 224555 | 10299.7 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1907.84 | 1.6627 | 2.53491ms | 3873 | 64 | 66316.2 | 1936 | 1(Win) |
| glaze | 1163.55 | 2.10368 | 0.858112ms | 3873 | 30 | 133784 | 3174.4 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1597.18 | 1.81181 | 6.08896ms | 3862 | 128 | 223438 | 2306 | 1(Win) |
| glaze | 1346.16 | 2.1341 | 3.4281ms | 3862 | 64 | 218193 | 2736 | 2(Loss) |
| simdjson | 356.41 | 0.83553 | 2.62195ms | 3862 | 30 | 223651 | 10333.9 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1683.31 | 2.45737 | 2.7712ms | 3862 | 64 | 185019 | 2188 | 1(Win) |
| glaze | 1057.14 | 1.84872 | 4.30797ms | 3862 | 64 | 265509 | 3484 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1418.66 | 1.88254 | 26.7809ms | 905 | 2048 | 268635 | 608.375 | 1(Win) |
| glaze | 863.075 | 1.3402 | 0.75904ms | 905 | 32 | 5747.61 | 1000 | 2(Loss) |
| simdjson | 178.38 | 1.52949 | 1.29587ms | 905 | 30 | 164292 | 4838.4 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 765.138 | 1.91698 | 6.69312ms | 905 | 256 | 119700 | 1128 | 1(Win) |
| glaze | 345.783 | 2.48137 | 3.37101ms | 905 | 64 | 245500 | 2496 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2339.85 | 1.78857 | 4.92595ms | 8813 | 64 | 264159 | 3592 | 1(Win) |
| glaze | 2018.3 | 1.47179 | 1.31917ms | 8813 | 30 | 112692 | 4164.27 | 2(Loss) |
| simdjson | 535.288 | 0.549072 | 6.17498ms | 8813 | 30 | 222973 | 15701.3 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2429.11 | 1.3079 | 10.402ms | 8813 | 128 | 262128 | 3460 | 1(Win) |
| jsonifier | 2155.21 | 1.56373 | 1.09286ms | 8813 | 30 | 111562 | 3899.73 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1499.89 | 0.546033 | 5.76ms | 33713 | 30 | 410994 | 21435.7 | 1(Win) |
| jsonifier | 1414.31 | 0.375634 | 6.19622ms | 33713 | 30 | 218755 | 22732.8 | 2(Loss) |
| simdjson | 212.926 | 0.271322 | 37.121ms | 33713 | 30 | 5.03535e+06 | 150997 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2393.72 | 0.752096 | 3.41888ms | 33713 | 30 | 306136 | 13431.5 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2373.92 | 0.700942 | 3.6201ms | 33689 | 30 | 269978 | 13533.9 | 1(Tie) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1699.24 | 2.12249 | 18.4161ms | 49505 | 32 | 1.11284e+07 | 27784 | 1(Win) |
| jsonifier | 1029.06 | 0.55615 | 2423.76ms | 49505 | 2048 | 1.33332e+08 | 45878.6 | 2(Loss) |
| simdjson | 290.716 | 2.28679 | 40.7529ms | 49505 | 30 | 4.13747e+08 | 162398 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2484.77 | 0.480203 | 4.71706ms | 48024 | 30 | 235026 | 18432 | 1(Win) |
| glaze | 2221.29 | 0.320266 | 32.905ms | 48000 | 64 | 278788 | 20608 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3434.96 | 0.638511 | 12.0589ms | 33713 | 64 | 228596 | 9360 | 1(Win) |
| simdjson | 2969.05 | 0.652615 | 3.83078ms | 33713 | 30 | 149829 | 10828.8 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3597.25 | 0.660463 | 5.49709ms | 48024 | 30 | 212126 | 12731.7 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 3587.63 | 0.60607 | 3.20896ms | 48024 | 30 | 179584 | 12765.9 | 1(Tie) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 762.164 | 1.68036 | 28.4439ms | 94651 | 30 | 1.18817e+08 | 118434 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 748.799 | 1.57082 | 145.76ms | 94651 | 64 | 2.29484e+08 | 120548 | 1(Tie) |
| simdjson | 627.406 | 0.191529 | 36.8361ms | 94651 | 30 | 2.27794e+06 | 143872 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4284.36 | 0.952211 | 5.32813ms | 94651 | 30 | 1.20744e+06 | 21068.8 | 1(Win) |
| jsonifier | 3269.09 | 2.10759 | 36.15ms | 94651 | 64 | 2.16745e+07 | 27612 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1002.74 | 0.822883 | 32.6341ms | 140436 | 30 | 3.62388e+07 | 133564 | 1(Win) |
| simdjson | 875.199 | 1.08017 | 37.0319ms | 140436 | 30 | 8.19683e+07 | 153028 | 2(Loss) |
| jsonifier | 749.198 | 0.518208 | 44.608ms | 140436 | 30 | 2.5745e+07 | 178765 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3426.71 | 2.04346 | 10.177ms | 136046 | 30 | 1.79584e+07 | 37862.4 | 1(Win) |
| jsonifier | 2560.61 | 2.2462 | 2323.57ms | 136024 | 2048 | 2.65197e+09 | 50660.8 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 461.835 | 0.293318 | 976.234ms | 2090234 | 30 | 4.80854e+09 | 4.31626e+06 | 1(Win) |
| jsonifier | 419.34 | 1.12278 | 1198.67ms | 2090234 | 30 | 8.54617e+10 | 4.75366e+06 | 2(Loss) |
| simdjson | 393.831 | 0.219594 | 1203.47ms | 2090234 | 30 | 3.70623e+09 | 5.06156e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1462.35 | 0.370721 | 332.746ms | 2090234 | 30 | 7.66131e+08 | 1.36315e+06 | 1(Win) |
| glaze | 1244.21 | 2.21163 | 420.453ms | 2090234 | 30 | 3.7666e+10 | 1.60214e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1123.34 | 0.445368 | 8053.81ms | 6885124 | 64 | 4.33733e+10 | 5.84524e+06 | 1(Win) |
| glaze | 1074.22 | 1.99236 | 1404.59ms | 6885124 | 30 | 4.44932e+11 | 6.11249e+06 | 2(Loss) |
| jsonifier | 895 | 1.76167 | 1792.02ms | 6885124 | 30 | 5.01125e+11 | 7.3365e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2620.03 | 0.553676 | 619.632ms | 6661897 | 30 | 5.40777e+09 | 2.42489e+06 | 1(Win) |
| jsonifier | 2184.88 | 0.867541 | 754.547ms | 6661897 | 30 | 1.90915e+10 | 2.90784e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1058.23 | 1.44912 | 103.164ms | 500299 | 30 | 1.28065e+09 | 450867 | 1(Win) |
| jsonifier | 949.364 | 2.21861 | 117.886ms | 500299 | 30 | 3.72973e+09 | 502571 | 2(Loss) |
| simdjson | 657.251 | 1.03691 | 1011.57ms | 500299 | 64 | 3.62624e+09 | 725936 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1648.61 | 2.33355 | 182.049ms | 500299 | 32 | 1.4595e+09 | 289408 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1610 | 2.11651 | 942.099ms | 500299 | 128 | 5.03569e+09 | 296350 | 1(Tie) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1773.08 | 0.26631 | 197.127ms | 1490030 | 30 | 1.36657e+08 | 801434 | 1(Win) |
| simdjson | 1591.46 | 1.42246 | 201.313ms | 1490030 | 30 | 4.83948e+09 | 892894 | 2(Loss) |
| jsonifier | 1087.17 | 1.99385 | 336.034ms | 1490030 | 30 | 2.03752e+10 | 1.30707e+06 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2849.31 | 1.48059 | 112.718ms | 1439562 | 30 | 1.52677e+09 | 481826 | 1(Win) |
| glaze | 2514.16 | 2.01761 | 133.544ms | 1439584 | 30 | 3.64154e+09 | 546065 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1365.65 | 0.26029 | 10.7768ms | 56369 | 30 | 314949 | 39364.3 | 1(Win) |
| glaze | 1193.81 | 0.745163 | 10.9299ms | 56369 | 30 | 3.37782e+06 | 45030.4 | 2(Loss) |
| simdjson | 734.063 | 0.97369 | 17.9461ms | 56369 | 30 | 1.52538e+07 | 73233.1 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4649.24 | 0.84313 | 2.98496ms | 56369 | 30 | 285119 | 11562.7 | 1(Win) |
| glaze | 2602.12 | 1.01377 | 5.15507ms | 56369 | 30 | 1.31592e+06 | 20659.2 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1644.56 | 0.116953 | 14.2779ms | 98048 | 30 | 132654 | 56857.6 | 1(Win) |
| simdjson | 1342.69 | 0.394695 | 16.9139ms | 98048 | 30 | 2.26657e+06 | 69640.5 | 2(Loss) |
| jsonifier | 1019.32 | 0.584514 | 23.5671ms | 98048 | 30 | 8.62514e+06 | 91733.3 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2853.83 | 0.513457 | 19.359ms | 94370 | 32 | 839019 | 31536 | 1(Win) |
| jsonifier | 2766.7 | 0.322245 | 13.9789ms | 94370 | 30 | 329639 | 32529.1 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1398.77 | 2.36242 | 22.315ms | 52708 | 32 | 2.30634e+07 | 35936 | 1(Win) |
| glaze | 1164.38 | 0.408559 | 10.7771ms | 52708 | 30 | 933248 | 43170.1 | 2(Loss) |
| simdjson | 1084.02 | 0.462837 | 11.0372ms | 52708 | 30 | 1.38183e+06 | 46370.1 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3916.61 | 0.571697 | 3.37715ms | 52708 | 30 | 161505 | 12834.1 | 1(Win) |
| glaze | 3263.48 | 0.865952 | 4.19712ms | 52708 | 30 | 533704 | 15402.7 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1357.95 | 0.171756 | 12.278ms | 71665 | 30 | 224178 | 50329.6 | 1(Win) |
| glaze | 1307.62 | 0.305366 | 17.569ms | 71665 | 30 | 764210 | 52266.7 | 2(Loss) |
| jsonifier | 1067.32 | 0.636242 | 19.7609ms | 71665 | 30 | 4.97953e+06 | 64034.1 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3613.75 | 0.473498 | 4.80486ms | 70103 | 30 | 230205 | 18500.3 | 1(Win) |
| glaze | 3321.16 | 0.646685 | 5.13792ms | 70103 | 30 | 508394 | 20130.1 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 799.088 | 1.37375 | 3.70202ms | 11812 | 30 | 1.12511e+06 | 14097.1 | 1(Win) |
| glaze | 712.421 | 1.47432 | 24.8241ms | 11812 | 64 | 3.47807e+06 | 15812 | 2(Loss) |
| simdjson | 577.722 | 0.519411 | 4.85606ms | 11812 | 30 | 307718 | 19498.7 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4117.25 | 2.09301 | 3.44806ms | 11812 | 64 | 209871 | 2736 | 1(Win) |
| glaze | 1656.33 | 1.12248 | 1.76998ms | 11812 | 30 | 174838 | 6801.07 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 1400.9 | 0.229987 | 5.41389ms | 32403 | 30 | 77212 | 22058.7 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1393.89 | 1.46859 | 8.47283ms | 32403 | 30 | 3.18008e+06 | 22169.6 | 1(Tie) |
| jsonifier | 1032.3 | 0.178415 | 7.6201ms | 32403 | 30 | 85573.4 | 29934.9 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3321.59 | 1.84182 | 5.088ms | 31235 | 32 | 873043 | 8968 | 1(Win) |
| glaze | 2434.3 | 0.637556 | 3.104ms | 31235 | 30 | 182597 | 12236.8 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2087.96 | 0.271957 | 29.3678ms | 108313 | 32 | 579254 | 49472 | 1(Win) |
| glaze | 1264.88 | 0.748347 | 20.2102ms | 108313 | 30 | 1.12044e+07 | 81664 | 2(Loss) |
| simdjson | 955.249 | 0.524555 | 25.1571ms | 108313 | 30 | 9.65232e+06 | 108134 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1961.58 | 0.523361 | 12.8069ms | 108313 | 30 | 2.27862e+06 | 52659.2 | 1(Win) |
| glaze | 1599.79 | 2.06146 | 36.19ms | 108313 | 32 | 5.66939e+07 | 64568 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1918.05 | 0.395203 | 27.1301ms | 222373 | 30 | 5.72807e+06 | 110566 | 1(Win) |
| simdjson | 1702.56 | 0.620627 | 83.8671ms | 222373 | 32 | 1.91236e+07 | 124560 | 2(Loss) |
| jsonifier | 1343.65 | 0.184808 | 40.3978ms | 222373 | 30 | 2.55244e+06 | 157833 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2650.14 | 0.300224 | 19.4061ms | 213963 | 30 | 1.60307e+06 | 76996.3 | 1(Win) |
| glaze | 1907.03 | 0.169171 | 26.015ms | 213963 | 30 | 982965 | 106999 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 469.515 | 0.652095 | 890.929ms | 1834197 | 30 | 1.77066e+10 | 3.7256e+06 | 1(Win) |
| simdjson | 402.86 | 0.112312 | 1069.48ms | 1834197 | 30 | 7.13445e+08 | 4.34202e+06 | 2(Loss) |
| jsonifier | 376.552 | 0.836789 | 1386.49ms | 1834197 | 30 | 4.53309e+10 | 4.64538e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 690.095 | 0.292955 | 1629.24ms | 1833577 | 32 | 1.76332e+09 | 2.5339e+06 | 1(Win) |
| jsonifier | 681.728 | 0.53779 | 658.347ms | 1834197 | 30 | 5.71238e+09 | 2.56587e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1728.33 | 0.454621 | 1385.47ms | 10252236 | 30 | 1.98429e+10 | 5.65707e+06 | 1(Win) |
| simdjson | 1560.93 | 2.47695 | 1403.25ms | 10252236 | 30 | 7.22144e+11 | 6.26375e+06 | 2(Loss) |
| jsonifier | 1064.2 | 0.902816 | 2197.84ms | 10252236 | 30 | 2.06401e+11 | 9.18747e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2573.99 | 0.444011 | 955.007ms | 9930848 | 30 | 8.00695e+09 | 3.67942e+06 | 1(Win) |
| glaze | 2260.89 | 0.510678 | 1052.01ms | 9930228 | 30 | 1.37269e+10 | 4.1887e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 903.268 | 0.360275 | 161.159ms | 642697 | 30 | 1.79295e+08 | 678562 | 1(Win) |
| simdjson | 675.205 | 0.740272 | 215.889ms | 642697 | 30 | 1.35471e+09 | 907759 | 2(Loss) |
| jsonifier | 650.32 | 0.311496 | 566.155ms | 642697 | 32 | 2.75812e+08 | 942496 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1000.47 | 0.173491 | 155.295ms | 642697 | 30 | 3.38905e+07 | 612634 | 1(Win) |
| glaze | 913.532 | 0.762833 | 155.386ms | 642692 | 30 | 7.85849e+08 | 670933 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1624.39 | 0.123127 | 187.152ms | 1306201 | 30 | 2.67463e+07 | 766865 | 1(Win) |
| simdjson | 1191.27 | 0.336514 | 1442.17ms | 1306201 | 64 | 7.92477e+08 | 1.04568e+06 | 2(Loss) |
| jsonifier | 879.378 | 0.907452 | 334.355ms | 1306201 | 30 | 4.95722e+09 | 1.41656e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1831.62 | 0.84146 | 157.913ms | 1225964 | 30 | 8.65517e+08 | 638327 | 1(Win) |
| glaze | 1214.02 | 1.02389 | 233.053ms | 1225970 | 30 | 2.917e+09 | 963063 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 699.463 | 0.713945 | 135.845ms | 409725 | 30 | 4.77206e+08 | 558635 | 1(Win) |
| glaze **STATISTICAL TIE** | 515.703 | 1.07671 | 181.427ms | 409725 | 30 | 1.99666e+09 | 757692 | 2(Tie) |
| simdjson **STATISTICAL TIE** | 509.268 | 1.41779 | 173.19ms | 409725 | 30 | 3.55008e+09 | 767266 | 2(Tie) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3613.79 | 0.272558 | 26.5951ms | 409725 | 30 | 2.60555e+06 | 108126 | 1(Win) |
| glaze | 1753.28 | 1.06899 | 57.9169ms | 409725 | 30 | 1.70275e+08 | 222865 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 1024.35 | 0.316095 | 205.837ms | 814756 | 30 | 1.72472e+08 | 758545 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1016.07 | 0.438173 | 2246.99ms | 814756 | 128 | 1.43719e+09 | 764726 | 1(Tie) |
| jsonifier | 832.977 | 0.687279 | 223.881ms | 814756 | 30 | 1.23304e+09 | 932813 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2475.25 | 0.46447 | 75.7202ms | 785750 | 30 | 5.93154e+07 | 302737 | 1(Win) |
| glaze | 2349.11 | 0.23591 | 76.8389ms | 785750 | 30 | 1.69893e+07 | 318993 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3994.69 | 0.714564 | 15.3108ms | 264040 | 30 | 6.08664e+06 | 63035.7 | 1(Win) |
| simdjson | 2732.29 | 0.444524 | 22.6371ms | 264040 | 30 | 5.03497e+06 | 92160 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4036.26 | 0.31355 | 23.0252ms | 399947 | 30 | 2.63379e+06 | 94498.1 | 1(Win) |
| simdjson | 3552.5 | 0.185961 | 26.0951ms | 399947 | 30 | 1.19592e+06 | 107366 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1770.28 | 0.747129 | 39.4921ms | 264040 | 30 | 3.3882e+07 | 142242 | 1(Win) |
| glaze | 1309.93 | 0.148426 | 47.136ms | 264040 | 30 | 2.44223e+06 | 192230 | 2(Loss) |
| simdjson | 1190.35 | 0.18379 | 51.5461ms | 264040 | 30 | 4.53479e+06 | 211541 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 3454.23 | 0.438449 | 19.127ms | 263923 | 30 | 3.06204e+06 | 72866.1 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 3439.65 | 0.121465 | 18.327ms | 264040 | 30 | 237210 | 73207.5 | 1(Tie) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1686.41 | 0.279494 | 56.0812ms | 409612 | 30 | 1.25742e+07 | 231637 | 1(Win) |
| glaze | 1668.89 | 0.142584 | 56.885ms | 409612 | 30 | 3.34158e+06 | 234069 | 2(Loss) |
| jsonifier | 1153.64 | 0.6223 | 83.8321ms | 409612 | 30 | 1.33206e+08 | 338611 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3782.48 | 2.06836 | 23.9421ms | 399947 | 30 | 1.30504e+08 | 100838 | 1(Win) |
| glaze | 3592.87 | 0.528057 | 25.6678ms | 399830 | 30 | 9.42219e+06 | 106129 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1534.01 | 2.07475 | 67.6951ms | 466906 | 30 | 1.08807e+09 | 290270 | 1(Win) |
| jsonifier | 1413.88 | 0.307957 | 75.52ms | 466906 | 30 | 2.82184e+07 | 314931 | 2(Loss) |
| simdjson | 865.124 | 0.0916111 | 125.502ms | 466906 | 30 | 6.66991e+06 | 514697 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2232.25 | 0.124826 | 72.1441ms | 699405 | 30 | 4.17351e+06 | 298803 | 1(Win) |
| jsonifier | 2087.62 | 0.0891008 | 78.5372ms | 699405 | 30 | 2.43131e+06 | 319505 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2577.13 | 0.112125 | 56.5089ms | 631514 | 30 | 2.05979e+06 | 233694 | 1(Win) |
| glaze | 2272.65 | 0.486578 | 67.0981ms | 631514 | 30 | 4.98801e+07 | 265003 | 2(Loss) |
