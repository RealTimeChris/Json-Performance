# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 25.4.0 using the Clang 22.1.8 compiler).  

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
### Double Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 815.942 | 0.447308 | 8.17479ms | 1811 | 30 | 2689.39 | 2116.7 | 1(Win) |
| glaze | 517.293 | 0.115983 | 1.01862ms | 1811 | 30 | 449.857 | 3338.73 | 2(Loss) |
| simdjson | 187.424 | 0.179305 | 5.44871ms | 1811 | 32 | 8736.12 | 9214.94 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 402.952 | 0.566682 | 1.19196ms | 1811 | 30 | 17698.3 | 4286.13 | 1(Tie) |
| glaze **STATISTICAL TIE** | 396.592 | 0.135716 | 1.35304ms | 1798 | 30 | 1032.94 | 4323.6 | 1(Tie) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1655.94 | 0.194661 | 0.686625ms | 3873 | 30 | 565.569 | 2230.5 | 1(Win) |
| glaze | 954.2 | 0.0790285 | 1.06508ms | 3873 | 30 | 280.74 | 3870.87 | 2(Loss) |
| simdjson | 426.864 | 0.233656 | 2.22292ms | 3873 | 30 | 12262.9 | 8652.83 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1820.25 | 0.199827 | 0.684625ms | 3873 | 30 | 493.247 | 2029.17 | 1(Win) |
| glaze | 1185.63 | 0.227995 | 0.874375ms | 3873 | 30 | 1513.46 | 3115.3 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1745.73 | 0.200422 | 0.692833ms | 3862 | 30 | 536.392 | 2109.77 | 1(Win) |
| glaze | 1001.07 | 0.123343 | 1.02721ms | 3862 | 30 | 617.799 | 3679.17 | 2(Loss) |
| simdjson | 434.158 | 0.076699 | 2.26021ms | 3862 | 30 | 1270.08 | 8483.3 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1801.49 | 0.609271 | 0.702333ms | 3862 | 30 | 4654.81 | 2044.47 | 1(Win) |
| glaze | 1089.05 | 0.480243 | 0.905333ms | 3862 | 30 | 7913.58 | 3381.93 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 407.213 | 0.180235 | 0.636083ms | 905 | 30 | 437.775 | 2119.47 | 1(Win) |
| glaze | 355.297 | 0.186812 | 0.68325ms | 905 | 30 | 617.799 | 2429.17 | 2(Loss) |
| simdjson | 190.909 | 0.0963574 | 1.21212ms | 905 | 30 | 569.292 | 4520.87 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 724.259 | 0.319235 | 0.466333ms | 905 | 30 | 434.161 | 1191.67 | 1(Win) |
| glaze | 345.401 | 0.303727 | 0.746625ms | 905 | 30 | 1727.98 | 2498.77 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/String%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2277.5 | 0.140067 | 1.05804ms | 8813 | 30 | 801.54 | 3690.33 | 1(Win) |
| glaze | 1614.16 | 0.0813084 | 1.44637ms | 8813 | 30 | 537.706 | 5206.87 | 2(Loss) |
| simdjson | 754.201 | 0.29927 | 14.9065ms | 8813 | 64 | 71183.7 | 11143.9 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/String%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2250.42 | 0.155614 | 1.0135ms | 8813 | 30 | 1013.31 | 3734.73 | 1(Win) |
| glaze | 2034.78 | 0.150672 | 1.191ms | 8813 | 30 | 1161.98 | 4130.53 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1413.41 | 2.35067 | 5.72187ms | 33713 | 30 | 8.57749e+06 | 22747.2 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1403.72 | 1.43943 | 5.77992ms | 33713 | 30 | 3.26088e+06 | 22904.2 | 1(Tie) |
| simdjson | 273.77 | 0.203962 | 28.5077ms | 33713 | 30 | 1.72125e+06 | 117439 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3125.25 | 0.0654873 | 2.67537ms | 33713 | 30 | 1361.63 | 10287.6 | 1(Win) |
| glaze | 2490.56 | 0.114655 | 3.38583ms | 33689 | 30 | 6562.82 | 12900.1 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1818.26 | 0.0353402 | 6.53662ms | 49505 | 30 | 2526.08 | 25965.3 | 1(Win) |
| jsonifier | 1127.14 | 1.73828 | 10.0879ms | 49505 | 30 | 1.59039e+07 | 41886.2 | 2(Loss) |
| simdjson | 393.207 | 0.238503 | 29.2458ms | 49505 | 30 | 2.46017e+06 | 120068 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3115 | 0.0466139 | 3.73846ms | 48024 | 30 | 1409.13 | 14702.8 | 1(Win) |
| glaze | 2393.36 | 0.0857593 | 4.8745ms | 48000 | 30 | 8071.42 | 19126.4 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 3341.34 | 0.899001 | 2.42783ms | 33713 | 30 | 224490 | 9622.27 | 1(Win) |
| jsonifier | 3210.65 | 0.245353 | 2.623ms | 33713 | 30 | 18109.7 | 10013.9 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 4337.74 | 0.0486158 | 2.71625ms | 48024 | 30 | 790.437 | 10558.3 | 1(Win) |
| jsonifier | 3793.75 | 0.0403936 | 3.19583ms | 48024 | 30 | 713.39 | 12072.3 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 836.014 | 0.144008 | 26.4255ms | 94651 | 30 | 725305 | 107972 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 803.369 | 1.92628 | 27.6077ms | 94651 | 30 | 1.40533e+08 | 112360 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 797.718 | 1.59623 | 28.8913ms | 94651 | 30 | 9.78727e+07 | 113156 | 1(Tie) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3292.56 | 0.0452662 | 10.4052ms | 94651 | 30 | 4620.12 | 27415.2 | 1(Win) |
| glaze | 3044.26 | 0.112984 | 7.34925ms | 94651 | 30 | 33670.2 | 29651.3 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1179.5 | 0.0392734 | 27.555ms | 140436 | 30 | 59659.8 | 113549 | 1(Win) |
| simdjson | 1129.47 | 0.16809 | 28.6659ms | 140436 | 30 | 1.19182e+06 | 118578 | 2(Loss) |
| jsonifier | 959.671 | 0.139109 | 34.109ms | 140436 | 30 | 1.13069e+06 | 139558 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2726.9 | 1.1627 | 11.4049ms | 136046 | 30 | 9.18101e+06 | 47579.2 | 1(Win) |
| jsonifier | 2483.98 | 1.55666 | 12.4526ms | 136024 | 30 | 1.98263e+07 | 52223.6 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 521.572 | 0.60157 | 910.131ms | 2090234 | 30 | 1.58582e+10 | 3.82191e+06 | 1(Win) |
| simdjson **STATISTICAL TIE** | 356.658 | 0.329482 | 1338.03ms | 2090234 | 30 | 1.01735e+10 | 5.58911e+06 | 2(Tie) |
| jsonifier **STATISTICAL TIE** | 342.235 | 1.98052 | 1402.49ms | 2090234 | 30 | 3.99228e+11 | 5.82466e+06 | 2(Tie) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1577.59 | 0.816476 | 742.092ms | 2090234 | 32 | 3.40595e+09 | 1.26357e+06 | 1(Win) |
| glaze | 1513.3 | 0.449958 | 316.37ms | 2090234 | 30 | 1.05391e+09 | 1.31725e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1348.58 | 0.214596 | 1173.35ms | 6885124 | 30 | 3.27519e+09 | 4.86896e+06 | 1(Win) |
| simdjson | 1075.15 | 0.519443 | 1508.73ms | 6885124 | 30 | 3.01916e+10 | 6.10724e+06 | 2(Loss) |
| jsonifier | 655.377 | 0.649365 | 2294.7ms | 6885124 | 30 | 1.26981e+11 | 1.00189e+07 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2741.13 | 0.491923 | 561.345ms | 6661897 | 30 | 3.8999e+09 | 2.31776e+06 | 1(Win) |
| jsonifier | 2704.2 | 0.111731 | 579.381ms | 6661897 | 30 | 2.06724e+08 | 2.34941e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1130.63 | 0.820698 | 104.407ms | 500299 | 30 | 3.59838e+08 | 421997 | 1(Win) |
| glaze | 1015.7 | 0.813808 | 110.708ms | 500299 | 30 | 4.38424e+08 | 469747 | 2(Loss) |
| simdjson | 666.458 | 1.96965 | 412.189ms | 500299 | 32 | 6.36272e+09 | 715908 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2895.3 | 0.143067 | 40.1307ms | 500299 | 30 | 1.66753e+06 | 164792 | 1(Win) |
| glaze | 1868.06 | 0.125106 | 61.8565ms | 500299 | 30 | 3.06307e+06 | 255411 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2127.71 | 0.202601 | 161.178ms | 1490030 | 30 | 5.49251e+07 | 667857 | 1(Win) |
| simdjson | 1821.77 | 0.233645 | 181.165ms | 1490030 | 30 | 9.9641e+07 | 780014 | 2(Loss) |
| jsonifier | 1403.08 | 0.552622 | 240.647ms | 1490030 | 30 | 9.3973e+08 | 1.01278e+06 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3888.63 | 0.248798 | 84.992ms | 1439562 | 30 | 2.31465e+07 | 353048 | 1(Win) |
| glaze | 2747.69 | 0.143917 | 121.394ms | 1439584 | 30 | 1.55126e+07 | 499654 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1800.67 | 0.0858844 | 7.90392ms | 56369 | 30 | 19722.5 | 29854.3 | 1(Win) |
| glaze | 1216.24 | 0.155542 | 11.0062ms | 56369 | 30 | 141795 | 44200 | 2(Loss) |
| simdjson | 970.134 | 1.31567 | 13.2303ms | 56369 | 30 | 1.59452e+07 | 55412.6 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2769.24 | 0.860807 | 4.80804ms | 56369 | 30 | 837709 | 19412.4 | 1(Win) |
| glaze | 2617.35 | 0.0721734 | 5.19517ms | 56369 | 30 | 6592.24 | 20539 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1739.42 | 0.174653 | 13.273ms | 98048 | 30 | 264447 | 53756.9 | 1(Win) |
| simdjson | 1628.82 | 0.276232 | 13.9019ms | 98048 | 30 | 754397 | 57407.1 | 2(Loss) |
| jsonifier | 1447.55 | 0.0312823 | 16.3393ms | 98048 | 30 | 12249.8 | 64595.8 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3382.88 | 0.598256 | 6.56658ms | 94370 | 30 | 759961 | 26604.1 | 1(Win) |
| glaze | 2583.89 | 0.101358 | 8.78388ms | 94370 | 30 | 37390.3 | 34830.5 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1671.22 | 0.055509 | 8.39762ms | 52708 | 30 | 8362.51 | 30077.7 | 1(Win) |
| glaze | 1286.36 | 0.0811765 | 9.90233ms | 52708 | 30 | 30186.5 | 39076.5 | 2(Loss) |
| simdjson | 1238.89 | 0.123483 | 10.0687ms | 52708 | 30 | 75305 | 40573.7 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3764.12 | 0.586864 | 7.65487ms | 52708 | 32 | 196540 | 13354.1 | 1(Win) |
| glaze | 3185.34 | 0.869767 | 4.16338ms | 52708 | 30 | 565157 | 15780.5 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1615.56 | 0.0960398 | 10.6163ms | 71665 | 30 | 49520.9 | 42304.1 | 1(Win) |
| glaze | 1573.77 | 0.0540318 | 10.883ms | 71665 | 30 | 16517.9 | 43427.7 | 2(Loss) |
| jsonifier | 1412.82 | 0.304922 | 12.8533ms | 71665 | 30 | 652742 | 48375 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4128.73 | 0.0630318 | 9.47125ms | 70103 | 32 | 3333.56 | 16192.7 | 1(Win) |
| glaze | 3488.6 | 0.727144 | 4.77146ms | 70103 | 30 | 582550 | 19164 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1042.36 | 0.134015 | 2.93254ms | 11812 | 30 | 6292.79 | 10807 | 1(Win) |
| glaze | 862.743 | 0.0621565 | 3.37904ms | 11812 | 30 | 1975.96 | 13057 | 2(Loss) |
| simdjson | 748.424 | 0.0472042 | 3.88808ms | 11812 | 30 | 1514.38 | 15051.4 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1954.81 | 0.0859954 | 1.56658ms | 11812 | 30 | 736.731 | 5762.6 | 1(Win) |
| glaze | 1563.63 | 0.0976125 | 1.91837ms | 11812 | 30 | 1483.58 | 7204.27 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1829.57 | 0.0522127 | 4.25679ms | 32403 | 30 | 2333.18 | 16890.3 | 1(Win) |
| simdjson | 1801.27 | 0.0493608 | 4.32487ms | 32403 | 30 | 2151.28 | 17155.6 | 2(Loss) |
| jsonifier | 1359.4 | 0.0436557 | 5.73571ms | 32403 | 30 | 2954.45 | 22732 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3422.26 | 0.0419342 | 2.30362ms | 31235 | 30 | 399.683 | 8704.2 | 1(Win) |
| glaze | 2518.18 | 0.0568859 | 3.06292ms | 31235 | 30 | 1358.44 | 11829.2 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2340.31 | 0.0955314 | 11.9429ms | 108313 | 30 | 53336.9 | 44137.4 | 1(Win) |
| glaze | 1244.17 | 0.152934 | 20.4034ms | 108313 | 30 | 483651 | 83023.7 | 2(Loss) |
| simdjson | 1092.14 | 0.210798 | 23.0223ms | 108313 | 30 | 1.19249e+06 | 94580.5 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2629.96 | 0.0826509 | 9.69658ms | 108313 | 30 | 31614 | 39276.4 | 1(Win) |
| glaze | 1769.94 | 0.0912345 | 14.5345ms | 108313 | 30 | 85052.2 | 58361 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2150.52 | 0.258248 | 23.93ms | 222373 | 30 | 1.94568e+06 | 98613.9 | 1(Win) |
| simdjson | 1954.48 | 0.138245 | 26.1975ms | 222373 | 30 | 675033 | 108506 | 2(Loss) |
| jsonifier | 1664.16 | 1.48746 | 30.9915ms | 222373 | 30 | 1.07792e+08 | 127435 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4071.86 | 0.0182999 | 12.376ms | 213963 | 30 | 2522.95 | 50112.5 | 1(Win) |
| glaze | 1836.48 | 1.33641 | 30.7929ms | 213963 | 30 | 6.6146e+07 | 111110 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 467.238 | 0.336344 | 895.468ms | 1834197 | 30 | 4.75669e+09 | 3.74376e+06 | 1(Win) |
| simdjson **STATISTICAL TIE** | 362.608 | 0.25571 | 1192.7ms | 1834197 | 30 | 4.56493e+09 | 4.82402e+06 | 2(Tie) |
| jsonifier **STATISTICAL TIE** | 362.004 | 2.0607 | 1158.61ms | 1834197 | 30 | 2.97452e+11 | 4.83207e+06 | 2(Tie) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 852.719 | 0.10573 | 494.451ms | 1834197 | 30 | 1.41122e+08 | 2.05135e+06 | 1(Win) |
| glaze | 780.015 | 0.41989 | 559.457ms | 1833577 | 30 | 2.65819e+09 | 2.2418e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1801.09 | 0.559218 | 1245.66ms | 10252236 | 30 | 2.7647e+10 | 5.42853e+06 | 1(Win) |
| simdjson | 1683.32 | 0.471333 | 1416.84ms | 10252236 | 30 | 2.24844e+10 | 5.80834e+06 | 2(Loss) |
| jsonifier | 1206.83 | 0.471683 | 1967.01ms | 10252236 | 30 | 4.3809e+10 | 8.10161e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2734.19 | 0.149503 | 855.339ms | 9930848 | 30 | 8.04524e+08 | 3.46384e+06 | 1(Win) |
| glaze | 2305.82 | 0.0921524 | 1027.72ms | 9930228 | 30 | 4.29738e+08 | 4.10709e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1045.9 | 0.0598552 | 142.848ms | 642697 | 30 | 3.69113e+06 | 586026 | 1(Win) |
| jsonifier | 730.992 | 0.949866 | 187.875ms | 642697 | 30 | 1.90298e+09 | 838482 | 2(Loss) |
| simdjson | 625.5 | 0.376624 | 230.237ms | 642697 | 30 | 4.08597e+08 | 979893 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1315.43 | 0.298986 | 113.779ms | 642697 | 30 | 5.82237e+07 | 465949 | 1(Win) |
| glaze | 1062.18 | 0.26915 | 138.483ms | 642692 | 30 | 7.23638e+07 | 577040 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1852.82 | 0.233536 | 162.989ms | 1306201 | 30 | 7.39572e+07 | 672321 | 1(Win) |
| simdjson | 1268.33 | 0.0705801 | 238.528ms | 1306201 | 30 | 1.44159e+07 | 982149 | 2(Loss) |
| jsonifier | 1175.29 | 0.129606 | 255.826ms | 1306201 | 30 | 5.66109e+07 | 1.0599e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2103.87 | 0.777794 | 143.166ms | 1225964 | 30 | 5.60491e+08 | 555724 | 1(Win) |
| glaze | 1663.54 | 0.289403 | 171.055ms | 1225970 | 30 | 1.24113e+08 | 702822 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 933.759 | 0.411454 | 101.951ms | 409725 | 30 | 8.89366e+07 | 418464 | 1(Win) |
| simdjson | 740.617 | 0.0858615 | 128.165ms | 409725 | 30 | 6.15625e+06 | 527593 | 2(Loss) |
| glaze | 722.478 | 0.0680795 | 131.087ms | 409725 | 30 | 4.06714e+06 | 540839 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2019.86 | 0.130404 | 46.5568ms | 409725 | 30 | 1.90918e+06 | 193451 | 1(Win) |
| glaze | 1685.77 | 0.44301 | 56.1272ms | 409725 | 30 | 3.16329e+07 | 231790 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1313.77 | 0.834849 | 142.1ms | 814756 | 30 | 7.31396e+08 | 591436 | 1(Win) |
| glaze | 1271.05 | 0.279046 | 147.725ms | 814756 | 30 | 8.72981e+07 | 611317 | 2(Loss) |
| jsonifier | 1070.74 | 0.381031 | 173.461ms | 814756 | 30 | 2.29365e+08 | 725676 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2701.67 | 0.367636 | 68.8767ms | 785750 | 30 | 3.11932e+07 | 277365 | 1(Win) |
| glaze | 2280.79 | 0.143059 | 79.8281ms | 785750 | 30 | 6.6275e+06 | 328549 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3827.68 | 0.219347 | 16.1893ms | 264040 | 30 | 624677 | 65786.2 | 1(Win) |
| simdjson | 3217.48 | 1.69399 | 19.3066ms | 264040 | 30 | 5.2729e+07 | 78262.6 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4072.45 | 0.242335 | 22.7874ms | 399947 | 30 | 1.54542e+06 | 93658.4 | 1(Win) |
| simdjson | 3971.46 | 0.363467 | 23.6015ms | 399947 | 30 | 3.65557e+06 | 96040.1 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2087.67 | 1.39552 | 30.3535ms | 264040 | 30 | 8.49983e+07 | 120617 | 1(Win) |
| glaze **STATISTICAL TIE** | 1338.08 | 0.99204 | 44.4068ms | 264040 | 30 | 1.04557e+08 | 188186 | 2(Tie) |
| simdjson **STATISTICAL TIE** | 1337.45 | 0.288986 | 45.965ms | 264040 | 30 | 8.88094e+06 | 188275 | 2(Tie) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3495.11 | 2.40468 | 17.544ms | 264040 | 30 | 9.00441e+07 | 72045.9 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3350.74 | 0.305844 | 18.4164ms | 263923 | 30 | 1.58342e+06 | 75116.7 | 1(Tie) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1920.1 | 0.140603 | 49.3413ms | 409612 | 30 | 2.45474e+06 | 203446 | 1(Win) |
| glaze | 1822.51 | 0.134318 | 52.0913ms | 409612 | 30 | 2.48655e+06 | 214340 | 2(Loss) |
| jsonifier | 1697.23 | 0.149801 | 56.5127ms | 409612 | 30 | 3.56625e+06 | 230161 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4433.32 | 0.0242586 | 21.9354ms | 399947 | 30 | 13067.7 | 86034.7 | 1(Win) |
| glaze | 3279.28 | 0.521744 | 28.2405ms | 399830 | 30 | 1.10416e+07 | 116278 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1865.52 | 0.0941413 | 57.5486ms | 466906 | 30 | 1.51475e+06 | 238688 | 1(Win) |
| jsonifier | 1573.38 | 0.32679 | 68.3926ms | 466906 | 30 | 2.56597e+07 | 283007 | 2(Loss) |
| simdjson | 824.255 | 0.128207 | 131.134ms | 466906 | 30 | 1.43907e+07 | 540217 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/macOS-Clang/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-Clang/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2312.03 | 0.14913 | 71.0638ms | 699405 | 30 | 5.55292e+06 | 288493 | 1(Win) |
| glaze | 2175.45 | 0.14082 | 76.4279ms | 699405 | 30 | 5.59251e+06 | 306606 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/macOS-Clang/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-Clang/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2646.08 | 0.148055 | 55.6523ms | 631514 | 30 | 3.40664e+06 | 227604 | 1(Win) |
| glaze | 2396.07 | 0.107664 | 61.1124ms | 631514 | 30 | 2.19698e+06 | 251353 | 2(Loss) |
