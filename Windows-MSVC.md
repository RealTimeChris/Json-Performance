# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.26200 using the MSVC 19.44.35228.0 compiler).  

Latest Results: (Jun 28, 2026)
#### Using the following commits:
----
| Jsonifier: [7b921fc](https://github.com/RealTimeChris/Jsonifier/commit/7b921fc)  
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
| jsonifier | 700.177 | 0.354882 | 1.858ms | 1811 | 30 | 2298.85 | 2466.67 | 1(Win) |
| glaze | 355.371 | 0.187185 | 2.4597ms | 1811 | 30 | 2482.76 | 4860 | 2(Loss) |
| simdjson | 188.206 | 0.124558 | 3.4929ms | 1811 | 30 | 3919.54 | 9176.67 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 636.72 | 0.274508 | 3.6186ms | 1811 | 32 | 1774.19 | 2712.5 | 1(Win) |
| glaze | 392.681 | 0.253574 | 2.2704ms | 1798 | 30 | 3678.16 | 4366.67 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2333.56 | 0.300299 | 4.2871ms | 3873 | 64 | 1445.93 | 1582.81 | 1(Win) |
| glaze | 1431.62 | 0.2879 | 1.8417ms | 3873 | 30 | 1655.17 | 2580 | 2(Loss) |
| simdjson | 395.176 | 0.0991167 | 3.5707ms | 3873 | 30 | 2574.71 | 9346.67 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3239.98 | 0.797998 | 1.6442ms | 3873 | 30 | 2482.76 | 1140 | 1(Win) |
| glaze | 1479.4 | 0.30263 | 1.8834ms | 3873 | 30 | 1712.64 | 2496.67 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2371.41 | 0.577076 | 2.6105ms | 3862 | 32 | 2570.56 | 1553.12 | 1(Win) |
| glaze | 1342.56 | 0.335426 | 1.8451ms | 3862 | 30 | 2540.23 | 2743.33 | 2(Loss) |
| simdjson | 382.063 | 2.34798 | 3.6069ms | 3862 | 30 | 1.53697e+06 | 9640 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3121.26 | 0.629476 | 1.4412ms | 3862 | 30 | 1655.17 | 1180 | 1(Win) |
| glaze | 1475.08 | 0.283446 | 3.5415ms | 3862 | 32 | 1602.82 | 2496.88 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1266.9 | 1.02902 | 2.1544ms | 905 | 32 | 1572.58 | 681.25 | 1(Win) |
| glaze | 387.609 | 0.368791 | 1.779ms | 905 | 30 | 2022.99 | 2226.67 | 2(Loss) |
| simdjson | 153.846 | 0.131017 | 2.5451ms | 905 | 30 | 1620.69 | 5610 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 775.217 | 0.566985 | 1.4485ms | 905 | 30 | 1195.4 | 1113.33 | 1(Win) |
| glaze | 303.9 | 0.320323 | 1.8936ms | 905 | 30 | 2482.76 | 2840 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3514.27 | 1.09018 | 32.9022ms | 8813 | 512 | 348051 | 2391.6 | 1(Win) |
| glaze | 1929.17 | 0.238165 | 2.3546ms | 8813 | 30 | 3229.89 | 4356.67 | 2(Loss) |
| simdjson | 700.978 | 0.108413 | 4.2374ms | 8813 | 30 | 5068.97 | 11990 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3308.14 | 0.347198 | 3.9238ms | 8813 | 32 | 2489.92 | 2540.62 | 1(Win) |
| glaze | 2894.86 | 0.308217 | 2.0245ms | 8813 | 30 | 2402.3 | 2903.33 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1453.93 | 1.38744 | 8.0888ms | 33713 | 30 | 2.82395e+06 | 22113.3 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1423.46 | 1.81937 | 8.7599ms | 33713 | 30 | 5.06602e+06 | 22586.7 | 1(Tie) |
| simdjson | 65.5595 | 0.384657 | 306.777ms | 33713 | 32 | 1.13873e+08 | 490412 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3856.58 | 2.35746 | 59.589ms | 33713 | 256 | 9.88822e+06 | 8336.72 | 1(Win) |
| glaze | 3423.88 | 2.48582 | 64.5718ms | 33689 | 256 | 1.3929e+07 | 9383.59 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1798.25 | 1.5965 | 17.72ms | 48024 | 32 | 5.2906e+06 | 25468.8 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1776.08 | 1.79653 | 9.0753ms | 48024 | 30 | 6.43844e+06 | 25786.7 | 1(Tie) |
| simdjson | 91.4139 | 0.818341 | 139.99ms | 48024 | 30 | 5.04293e+08 | 501010 | 3(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4943.81 | 0.451376 | 2.8455ms | 33713 | 30 | 25850.6 | 6503.33 | 1(Win) |
| simdjson | 2448.74 | 1.34207 | 18.3252ms | 33713 | 64 | 1.9872e+06 | 13129.7 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6061.11 | 0.805913 | 7.7672ms | 48024 | 32 | 118669 | 7556.25 | 1(Win) |
| simdjson | 3327.63 | 2.22856 | 4.5375ms | 48024 | 30 | 2.8224e+06 | 13763.3 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 757.774 | 2.29211 | 2522.62ms | 94651 | 1024 | 7.63379e+09 | 119120 | 1(Win) |
| glaze | 636.511 | 1.55201 | 5910.23ms | 94651 | 2048 | 9.92103e+09 | 141814 | 2(Loss) |
| simdjson | 515.027 | 1.64439 | 7466.42ms | 94651 | 2048 | 1.7011e+10 | 175265 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4606.71 | 2.17219 | 114.1ms | 94651 | 256 | 4.63774e+07 | 19594.5 | 1(Win) |
| jsonifier | 3638.3 | 1.43547 | 8.804ms | 94651 | 30 | 3.80507e+06 | 24810 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1143.86 | 1.42168 | 328.739ms | 136024 | 128 | 3.32738e+08 | 113408 | 1(Win) |
| glaze **STATISTICAL TIE** | 890.504 | 2.18753 | 6150.1ms | 136024 | 2048 | 2.07969e+10 | 145673 | 2(Tie) |
| simdjson **STATISTICAL TIE** | 858.484 | 2.41194 | 40.6048ms | 136024 | 30 | 3.98493e+08 | 151107 | 2(Tie) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4532.26 | 1.46425 | 18.5424ms | 136046 | 30 | 5.27099e+06 | 28626.7 | 1(Win) |
| jsonifier | 3386.42 | 0.896822 | 10.6786ms | 136024 | 30 | 3.54064e+06 | 38306.7 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 946.434 | 1.48846 | 16800.7ms | 6661897 | 128 | 1.27791e+12 | 6.71286e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 937.841 | 2.30577 | 15921.6ms | 6661897 | 64 | 1.56153e+12 | 6.77437e+06 | 1(Tie) |
| simdjson | 738.488 | 2.37144 | 10447.8ms | 6661897 | 64 | 2.66388e+12 | 8.60309e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1485.32 | 2.30045 | 10621.1ms | 6661897 | 128 | 1.23935e+12 | 4.27739e+06 | 1(Win) |
| glaze | 1015.28 | 2.18524 | 15205.7ms | 6661897 | 128 | 2.39352e+12 | 6.25769e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 829.94 | 2.01368 | 6038.65ms | 500299 | 512 | 6.86148e+10 | 574888 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 817.352 | 1.65204 | 12131ms | 500299 | 1024 | 9.52314e+10 | 583742 | 1(Tie) |
| simdjson | 401.439 | 2.35405 | 12087.9ms | 500299 | 512 | 4.00795e+11 | 1.18853e+06 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4785.9 | 1.66772 | 27.5878ms | 500299 | 30 | 8.29275e+07 | 99693.3 | 1(Win) |
| glaze | 4432.16 | 1.90692 | 32.514ms | 500299 | 30 | 1.2642e+08 | 107650 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1823.34 | 2.00142 | 7820.03ms | 1439562 | 512 | 1.16271e+11 | 752945 | 1(Win) |
| jsonifier | 1647.72 | 2.45004 | 16679.3ms | 1439562 | 1024 | 4.26717e+11 | 833197 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2257.07 | 2.40789 | 3241.63ms | 1439562 | 256 | 5.49141e+10 | 608254 | 1(Win) |
| glaze | 1206.36 | 2.40041 | 6009.85ms | 1439584 | 256 | 1.91043e+11 | 1.13805e+06 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1349.9 | 1.61107 | 13.1513ms | 56369 | 30 | 1.23487e+07 | 39823.3 | 1(Win) |
| glaze | 1238.09 | 1.14306 | 11.9592ms | 56369 | 30 | 7.38993e+06 | 43420 | 2(Loss) |
| simdjson | 561.017 | 0.750913 | 64.329ms | 56369 | 32 | 1.65676e+07 | 95821.9 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4910.78 | 1.09907 | 8.1296ms | 56369 | 32 | 463216 | 10946.9 | 1(Win) |
| glaze | 4290.32 | 0.304082 | 4.4741ms | 56369 | 30 | 43551.7 | 12530 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1782.38 | 2.20549 | 13.9421ms | 94370 | 30 | 3.72048e+07 | 50493.3 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1762.02 | 1.54377 | 15.4419ms | 94370 | 30 | 1.86522e+07 | 51076.7 | 1(Tie) |
| simdjson | 889.194 | 1.0255 | 30.8343ms | 94370 | 30 | 3.23198e+07 | 101213 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4533.92 | 1.86595 | 6.2718ms | 94370 | 30 | 4.11569e+06 | 19850 | 1(Win) |
| glaze | 4124.22 | 1.54593 | 14.6941ms | 94370 | 32 | 3.64176e+06 | 21821.9 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1242.88 | 2.36108 | 22.1744ms | 52708 | 30 | 2.7355e+07 | 40443.3 | 1(Win) |
| glaze | 1051.45 | 1.08101 | 14.9934ms | 52708 | 30 | 8.01237e+06 | 47806.7 | 2(Loss) |
| simdjson | 801.675 | 1.52282 | 174.253ms | 52708 | 128 | 1.16698e+08 | 62701.6 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5820.59 | 0.0942899 | 13.8385ms | 52708 | 64 | 4243.55 | 8635.94 | 1(Win) |
| glaze | 4892.09 | 2.20975 | 7.952ms | 52708 | 32 | 1.64968e+06 | 10275 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1440.13 | 1.28316 | 14.8911ms | 70103 | 30 | 1.06453e+07 | 46423.3 | 1(Win) |
| glaze | 1246.53 | 1.1086 | 18.9698ms | 70103 | 30 | 1.06057e+07 | 53633.3 | 2(Loss) |
| simdjson | 1094.67 | 0.865027 | 16.5896ms | 70103 | 30 | 8.37306e+06 | 61073.3 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5055.87 | 0.112831 | 4.7707ms | 70103 | 30 | 6678.16 | 13223.3 | 1(Win) |
| glaze | 4261.28 | 2.31887 | 25.6104ms | 70103 | 64 | 8.47083e+06 | 15689.1 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 866.968 | 2.34049 | 4.63ms | 11812 | 30 | 2.77444e+06 | 12993.3 | 1(Win) |
| glaze | 777.218 | 2.38724 | 11.3245ms | 11812 | 32 | 3.83093e+06 | 14493.8 | 2(Loss) |
| simdjson | 477.659 | 0.469845 | 10.8182ms | 11812 | 30 | 368333 | 23583.3 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3427.42 | 0.378543 | 2.0406ms | 11812 | 30 | 4643.68 | 3286.67 | 1(Win) |
| glaze | 3096.85 | 0.269031 | 5.8498ms | 11812 | 32 | 3064.52 | 3637.5 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1670.67 | 0.0897928 | 5.8045ms | 31235 | 30 | 7689.66 | 17830 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1669.42 | 0.214433 | 5.8047ms | 31235 | 30 | 43919.5 | 17843.3 | 1(Tie) |
| simdjson | 1165.44 | 1.60508 | 16.7785ms | 31235 | 32 | 5.38572e+06 | 25559.4 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 5006.39 | 0.226393 | 5.3263ms | 31235 | 32 | 5806.45 | 5950 | 1(Win) |
| jsonifier | 4479.4 | 0.69437 | 2.9297ms | 31235 | 30 | 63965.5 | 6650 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1985.81 | 1.97175 | 14.5771ms | 108313 | 30 | 3.1558e+07 | 52016.7 | 1(Win) |
| glaze | 1305.28 | 0.899575 | 21.802ms | 108313 | 30 | 1.52038e+07 | 79136.7 | 2(Loss) |
| simdjson | 627.503 | 0.748519 | 44.3187ms | 108313 | 30 | 4.55467e+07 | 164613 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4547.78 | 1.87716 | 6.4898ms | 108313 | 30 | 5.45361e+06 | 22713.3 | 1(Win) |
| glaze | 4155.08 | 2.11455 | 7.1958ms | 108313 | 30 | 8.29007e+06 | 24860 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2326.07 | 0.710862 | 24.3096ms | 213963 | 30 | 1.1666e+07 | 87723.3 | 1(Win) |
| glaze | 2026.12 | 0.72919 | 28.5831ms | 213963 | 30 | 1.61789e+07 | 100710 | 2(Loss) |
| simdjson | 1151.72 | 0.942908 | 45.2527ms | 213963 | 30 | 8.37222e+07 | 177170 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5182.47 | 2.44404 | 10.8574ms | 213963 | 30 | 2.77806e+07 | 39373.3 | 1(Win) |
| glaze | 4297.02 | 2.31608 | 14.9578ms | 213963 | 30 | 3.62888e+07 | 47486.7 | 2(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 621.801 | 2.20691 | 14226.5ms | 1834197 | 256 | 9.86725e+11 | 2.81316e+06 | 1(Win) |
| glaze | 471.873 | 2.0089 | 18356ms | 1833577 | 256 | 1.41875e+12 | 3.70574e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1450.47 | 1.74634 | 8225.46ms | 9930848 | 64 | 8.32138e+11 | 6.52949e+06 | 1(Win) |
| glaze | 1245.05 | 1.17995 | 19000ms | 9930848 | 128 | 1.03118e+12 | 7.60676e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1549.81 | 2.06448 | 7577.89ms | 9930848 | 64 | 1.01863e+12 | 6.11095e+06 | 1(Win) |
| glaze | 832.264 | 1.97974 | 2875.15ms | 9930228 | 30 | 1.52242e+12 | 1.13788e+07 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 967.388 | 1.36283 | 13230ms | 642697 | 1024 | 7.63477e+10 | 633586 | 1(Win) |
| glaze | 669.376 | 1.68266 | 9544.91ms | 642697 | 512 | 1.21545e+11 | 915664 | 2(Loss) |
| simdjson | 478.664 | 1.54303 | 6650.78ms | 642697 | 256 | 9.99401e+10 | 1.28049e+06 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1456.81 | 0.581357 | 113.27ms | 642697 | 30 | 1.79479e+08 | 420730 | 1(Win) |
| glaze | 540.348 | 1.7278 | 5688.88ms | 642692 | 256 | 9.83302e+10 | 1.1343e+06 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1483.37 | 1.73396 | 16179.9ms | 1225964 | 1024 | 1.91266e+11 | 788187 | 1(Win) |
| glaze | 1172.38 | 1.44726 | 10433.7ms | 1225964 | 512 | 1.06655e+11 | 997262 | 2(Loss) |
| simdjson | 860.691 | 2.03551 | 13829.9ms | 1225964 | 512 | 3.91452e+11 | 1.35841e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1314.51 | 2.13664 | 9146.71ms | 1225964 | 512 | 1.84911e+11 | 889437 | 1(Win) |
| glaze | 1033.89 | 2.49922 | 5800.56ms | 1225970 | 256 | 2.04484e+11 | 1.13085e+06 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 632.8 | 0.414287 | 388.023ms | 409725 | 32 | 2.09413e+08 | 617484 | 1(Win) |
| glaze | 598.325 | 1.47637 | 167.226ms | 409725 | 30 | 2.78884e+09 | 653063 | 2(Loss) |
| simdjson | 446.606 | 1.27261 | 9121.43ms | 409725 | 512 | 6.34738e+10 | 874918 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2817.33 | 1.28685 | 38.1538ms | 409725 | 30 | 9.55627e+07 | 138693 | 1(Win) |
| jsonifier | 2439.76 | 0.93813 | 41.1042ms | 409725 | 30 | 6.77232e+07 | 160157 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 918.328 | 1.67579 | 8397.45ms | 785750 | 512 | 9.57378e+10 | 815994 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 901.696 | 2.10944 | 8364.5ms | 785750 | 512 | 1.57345e+11 | 831045 | 1(Tie) |
| simdjson | 837.383 | 2.24161 | 2289.48ms | 785750 | 128 | 5.15051e+10 | 894870 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3127.72 | 0.762559 | 63.7923ms | 785750 | 30 | 1.00134e+08 | 239583 | 1(Win) |
| glaze | 1722.47 | 1.22564 | 119.023ms | 785750 | 30 | 8.52923e+08 | 435043 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5047.27 | 1.29866 | 15.8123ms | 264040 | 30 | 1.25933e+07 | 49890 | 1(Win) |
| simdjson | 1976.95 | 0.543915 | 78.7935ms | 264040 | 32 | 1.53589e+07 | 127372 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6968.26 | 0.83415 | 14.9582ms | 399947 | 30 | 6.25413e+06 | 54736.7 | 1(Win) |
| simdjson | 2801.33 | 0.785548 | 37.2072ms | 399947 | 30 | 3.43198e+07 | 136157 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1576.53 | 1.11651 | 43.6909ms | 264040 | 30 | 9.54081e+07 | 159723 | 1(Win) |
| glaze | 1011.24 | 0.84265 | 68.4861ms | 264040 | 30 | 1.32084e+08 | 249010 | 2(Loss) |
| simdjson | 804.67 | 0.861064 | 82.9916ms | 264040 | 30 | 2.17819e+08 | 312933 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5639.6 | 1.63072 | 12.1498ms | 264040 | 30 | 1.59047e+07 | 44650 | 1(Win) |
| glaze | 4271.47 | 2.31341 | 37.6293ms | 263923 | 32 | 5.94639e+07 | 58925 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1820.18 | 0.861302 | 55.2241ms | 399947 | 30 | 9.77253e+07 | 209550 | 1(Win) |
| glaze | 1329.47 | 0.610236 | 84.7308ms | 399947 | 30 | 9.19534e+07 | 286897 | 2(Loss) |
| simdjson | 1174.92 | 0.831774 | 83.949ms | 399947 | 30 | 2.18735e+08 | 324633 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5504.68 | 1.07396 | 19.518ms | 399947 | 30 | 1.66127e+07 | 69290 | 1(Win) |
| glaze | 3553.76 | 1.49083 | 143.288ms | 399830 | 64 | 1.63761e+08 | 107297 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2480.15 | 0.762596 | 250.271ms | 466906 | 64 | 1.1997e+08 | 179536 | 1(Win) |
| glaze | 2180.89 | 0.656577 | 135.9ms | 466906 | 32 | 5.7506e+07 | 204172 | 2(Loss) |
| simdjson | 1196.33 | 0.677414 | 99.7075ms | 466906 | 30 | 1.90718e+08 | 372203 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3222.71 | 0.824551 | 57.5584ms | 699405 | 30 | 8.73718e+07 | 206970 | 1(Win) |
| glaze | 2873.43 | 0.600498 | 149.002ms | 699405 | 32 | 6.21769e+07 | 232128 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4203.56 | 1.40949 | 40.0473ms | 631514 | 30 | 1.22342e+08 | 143273 | 1(Win) |
| glaze | 3652.19 | 1.07633 | 46.1301ms | 631514 | 30 | 9.45093e+07 | 164903 | 2(Loss) |
