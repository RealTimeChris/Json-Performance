# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.6.87.2-microsoft-standard-WSL2 using the Clang 23.0.0 compiler).  

Latest Results: (Jun 27, 2026)
#### Using the following commits:
----
| Jsonifier: [66437c1](https://github.com/RealTimeChris/Jsonifier/commit/66437c1)  
| Glaze: [c60d5f6](https://github.com/stephenberry/glaze/commit/c60d5f6)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1161.08 | 0.0242818 | 1.60257ms | 1811 | 30 | 3.91379 | 1487.5 | 1(Win) |
| glaze | 867.049 | 0.110249 | 0.809699ms | 1811 | 30 | 144.685 | 1991.93 | 2(Loss) |
| simdjson | 258.538 | 0.0377879 | 2.59853ms | 1811 | 30 | 191.168 | 6680.27 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 680.793 | 0.276382 | 0.913128ms | 1811 | 30 | 1474.85 | 2536.9 | 1(Win) |
| glaze | 496.055 | 0.51677 | 3.10246ms | 1798 | 32 | 10210.9 | 3456.69 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1961.64 | 0.0668087 | 0.795581ms | 3873 | 30 | 47.4724 | 1882.9 | 1(Win) |
| glaze | 1476.13 | 0.138341 | 0.899825ms | 3873 | 30 | 359.476 | 2502.2 | 2(Loss) |
| simdjson | 461.78 | 0.0594189 | 2.94813ms | 3873 | 30 | 677.633 | 7998.57 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2964.35 | 0.188553 | 0.604038ms | 3873 | 30 | 165.586 | 1246 | 1(Win) |
| glaze | 857.172 | 0.445361 | 2.58542ms | 3873 | 32 | 11785.1 | 4309.03 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2221.87 | 0.0622776 | 1.45017ms | 3862 | 32 | 34.1038 | 1657.66 | 1(Win) |
| glaze | 1640.31 | 0.0437867 | 0.834599ms | 3862 | 30 | 28.9989 | 2245.37 | 2(Loss) |
| simdjson | 467.232 | 1.28449 | 10.5765ms | 3862 | 64 | 656149 | 7882.78 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3270.56 | 0.187998 | 0.689219ms | 3862 | 30 | 134.464 | 1126.13 | 1(Win) |
| glaze | 1452.3 | 0.215342 | 0.974148ms | 3862 | 30 | 894.723 | 2536.03 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1649.08 | 0.0296619 | 0.457075ms | 905 | 30 | 0.722989 | 523.367 | 1(Win) |
| glaze | 523.774 | 0.203959 | 0.851599ms | 905 | 30 | 338.855 | 1647.8 | 2(Loss) |
| simdjson | 230.457 | 0.221426 | 4.09741ms | 905 | 32 | 2200.51 | 3745.06 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1596.71 | 0.0362847 | 0.462211ms | 905 | 30 | 1.15402 | 540.533 | 1(Win) |
| glaze | 404.661 | 0.133394 | 0.777669ms | 905 | 30 | 242.833 | 2132.83 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4295.43 | 0.124449 | 0.801436ms | 8813 | 30 | 177.885 | 1956.67 | 1(Win) |
| glaze | 2539.78 | 0.105683 | 5.55672ms | 8813 | 64 | 782.785 | 3309.23 | 2(Loss) |
| simdjson | 1430.44 | 0.123104 | 1.88379ms | 8813 | 30 | 1569.55 | 5875.63 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4158.97 | 0.121018 | 0.784962ms | 8813 | 30 | 179.43 | 2020.87 | 1(Win) |
| glaze | 3226.88 | 0.221991 | 0.966477ms | 8813 | 30 | 1002.94 | 2604.6 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2534.75 | 0.861197 | 6.08496ms | 33713 | 30 | 357972 | 12684.2 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2506.12 | 0.306486 | 3.53132ms | 33713 | 30 | 46380.3 | 12829.1 | 1(Tie) |
| simdjson | 1596.37 | 0.271849 | 54.3775ms | 33713 | 30 | 89930.1 | 20140.2 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5275.07 | 0.163892 | 4.01381ms | 33713 | 32 | 3193.03 | 6094.94 | 1(Win) |
| glaze | 4981.21 | 0.732764 | 36.5648ms | 33689 | 256 | 571841 | 6449.91 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3197.91 | 0.0778345 | 4.2336ms | 49505 | 30 | 3961.24 | 14763.3 | 1(Win) |
| glaze | 2763.85 | 2.22916 | 5.54486ms | 49505 | 30 | 4.34984e+06 | 17081.8 | 2(Loss) |
| simdjson | 2122.14 | 2.19359 | 54.5703ms | 49505 | 30 | 7.14464e+06 | 22247.2 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5288.8 | 0.129378 | 2.4848ms | 48024 | 30 | 3765.68 | 8659.67 | 1(Win) |
| glaze | 4668.99 | 0.230668 | 4.03481ms | 48000 | 30 | 15343.7 | 9804.33 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6871.43 | 0.0818878 | 3.31394ms | 33713 | 32 | 469.773 | 4678.97 | 1(Win) |
| simdjson | 6440.55 | 0.548433 | 1.51945ms | 33713 | 30 | 22486.3 | 4992 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8510.34 | 0.0490708 | 1.6594ms | 48024 | 30 | 209.214 | 5381.6 | 1(Win) |
| simdjson | 7863.43 | 0.400926 | 1.70636ms | 48024 | 30 | 16358.4 | 5824.33 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1520.94 | 1.72021 | 35.0008ms | 94651 | 32 | 3.33534e+07 | 59349 | 1(Win) |
| glaze | 1330.37 | 1.0621 | 18.8242ms | 94651 | 30 | 1.55798e+07 | 67850.6 | 2(Loss) |
| simdjson | 1001 | 0.930037 | 24.6865ms | 94651 | 30 | 2.11012e+07 | 90176.5 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 5189.74 | 1.15272 | 4.63722ms | 94651 | 30 | 1.20594e+06 | 17393.2 | 1(Win) |
| jsonifier | 4377.01 | 0.582113 | 5.66548ms | 94651 | 30 | 432346 | 20622.8 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1950.42 | 0.464773 | 45.1644ms | 140436 | 32 | 3.25936e+06 | 68667.3 | 1(Win) |
| glaze | 1643.56 | 1.61241 | 21.8092ms | 140436 | 30 | 5.17915e+07 | 81488 | 2(Loss) |
| simdjson | 1451.59 | 0.755009 | 25.1914ms | 140436 | 30 | 1.45578e+07 | 92264.7 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4620.48 | 0.194758 | 57.803ms | 136024 | 30 | 89694.9 | 28075.6 | 1(Win) |
| glaze | 4127.24 | 2.18922 | 37.6848ms | 136046 | 64 | 3.03119e+07 | 31435.9 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 704.402 | 2.1862 | 3587.87ms | 2090234 | 64 | 2.44967e+11 | 2.82992e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 698.942 | 1.99028 | 3550.17ms | 2090234 | 64 | 2.06214e+11 | 2.85203e+06 | 1(Tie) |
| simdjson | 433.977 | 2.02515 | 1137.26ms | 2090234 | 30 | 2.59594e+11 | 4.59334e+06 | 3(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1861.12 | 1.41588 | 9926.82ms | 6885124 | 128 | 3.19403e+11 | 3.52808e+06 | 1(Win) |
| jsonifier | 1456.56 | 1.68052 | 6022.72ms | 6885124 | 64 | 3.67312e+11 | 4.508e+06 | 2(Loss) |
| simdjson | 1273.13 | 1.69857 | 1320.02ms | 6885124 | 30 | 2.30232e+11 | 5.1575e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2649.82 | 1.64526 | 7616.56ms | 6661897 | 128 | 1.99178e+11 | 2.39762e+06 | 1(Win) |
| glaze | 1771.16 | 1.86271 | 4404.54ms | 6661897 | 64 | 2.85729e+11 | 3.58708e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1971.96 | 0.509804 | 146.903ms | 500299 | 32 | 4.86877e+07 | 241953 | 1(Win) |
| jsonifier | 1715.59 | 0.40444 | 72.3484ms | 500299 | 30 | 3.79543e+07 | 278109 | 2(Loss) |
| simdjson | 1005.28 | 0.780407 | 341.461ms | 500299 | 32 | 4.39011e+08 | 474615 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 5684.12 | 1.22386 | 21.715ms | 500299 | 30 | 3.16605e+07 | 83939.5 | 1(Win) |
| jsonifier | 5418.94 | 1.10082 | 23.1112ms | 500299 | 30 | 2.81827e+07 | 88047.2 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3047.93 | 1.09795 | 121.047ms | 1490030 | 30 | 7.86085e+08 | 466220 | 1(Win) |
| glaze | 2928.78 | 1.58303 | 1331.29ms | 1490030 | 128 | 7.55105e+09 | 485186 | 2(Loss) |
| simdjson | 2721.59 | 0.495729 | 323.932ms | 1490030 | 32 | 2.14379e+08 | 522122 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6040.27 | 0.837433 | 137.607ms | 1439562 | 32 | 1.15931e+08 | 227287 | 1(Win) |
| glaze | 5317.17 | 0.967243 | 66.8083ms | 1439584 | 30 | 1.87114e+08 | 258200 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2108.58 | 0.989922 | 8.30128ms | 56369 | 30 | 1.91084e+06 | 25494.7 | 1(Win) |
| glaze | 1874.53 | 2.41288 | 17.6285ms | 56369 | 32 | 1.5322e+07 | 28677.9 | 2(Loss) |
| simdjson | 1146.23 | 1.4792 | 29.8676ms | 56369 | 32 | 1.54006e+07 | 46899.4 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 6611.17 | 0.253259 | 2.72716ms | 56369 | 30 | 12722.6 | 8131.33 | 1(Win) |
| jsonifier | 5409.59 | 0.0663788 | 7.52879ms | 56369 | 32 | 1392.39 | 9937.47 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2651.87 | 0.9769 | 22.1815ms | 98048 | 32 | 3.79684e+06 | 35260.3 | 1(Win) |
| jsonifier | 2493.25 | 0.759213 | 11.6156ms | 98048 | 30 | 2.43218e+06 | 37503.7 | 2(Loss) |
| simdjson | 1851.64 | 1.07673 | 65.6065ms | 98048 | 64 | 1.89215e+07 | 50499 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6054.66 | 0.0938806 | 4.03048ms | 94370 | 30 | 5842.01 | 14864.3 | 1(Win) |
| glaze | 5336.31 | 0.173752 | 4.79708ms | 94370 | 30 | 25761.2 | 16865.3 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2338.59 | 0.353109 | 6.2386ms | 52708 | 30 | 172816 | 21494.3 | 1(Win) |
| glaze | 1627.58 | 0.45788 | 22.5853ms | 52708 | 32 | 639916 | 30884.1 | 2(Loss) |
| simdjson | 1396.59 | 1.32377 | 9.34984ms | 52708 | 30 | 6.81016e+06 | 35992 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 6897.06 | 0.423892 | 2.42031ms | 52708 | 30 | 28632.3 | 7288.07 | 1(Win) |
| jsonifier | 6427.99 | 0.60285 | 5.08629ms | 52708 | 32 | 71116.8 | 7819.91 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2267.72 | 0.784749 | 97.063ms | 71665 | 64 | 3.57997e+06 | 30138.3 | 1(Win) |
| simdjson | 1929.81 | 0.249835 | 24.6633ms | 71665 | 32 | 250519 | 35415.4 | 2(Loss) |
| glaze | 1805.82 | 0.631083 | 9.9646ms | 71665 | 30 | 1.71144e+06 | 37847.2 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6522.78 | 0.1249 | 3.21332ms | 70103 | 30 | 4916.46 | 10249.5 | 1(Win) |
| glaze | 5771.48 | 1.65473 | 3.25716ms | 70103 | 30 | 1.10223e+06 | 11583.8 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1700.6 | 0.1558 | 1.96707ms | 11812 | 30 | 3195.21 | 6624.03 | 1(Win) |
| glaze | 1420.66 | 0.146197 | 2.34815ms | 11812 | 30 | 4031.53 | 7929.3 | 2(Loss) |
| simdjson | 978.286 | 0.120707 | 3.19438ms | 11812 | 30 | 5795.66 | 11514.8 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 4381.32 | 0.214092 | 0.918ms | 11812 | 30 | 908.99 | 2571.1 | 1(Win) |
| jsonifier | 4216.45 | 0.302798 | 1.39142ms | 11812 | 30 | 1963.27 | 2671.63 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2539.7 | 2.20774 | 3.2943ms | 32403 | 30 | 2.16482e+06 | 12167.5 | 1(Win) |
| glaze | 2409.42 | 0.30587 | 3.46825ms | 32403 | 30 | 46167.9 | 12825.5 | 2(Loss) |
| simdjson | 2391.21 | 0.133506 | 3.46954ms | 32403 | 30 | 8930.12 | 12923.1 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 6041.39 | 0.169807 | 3.26893ms | 31235 | 32 | 2243.2 | 4930.66 | 1(Win) |
| jsonifier | 5912.85 | 0.0669358 | 3.31818ms | 31235 | 32 | 363.878 | 5037.84 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3664.06 | 0.906742 | 7.76173ms | 108313 | 30 | 1.96031e+06 | 28191.5 | 1(Win) |
| glaze | 2225.75 | 1.23967 | 61.9702ms | 108313 | 64 | 2.11835e+07 | 46409.1 | 2(Loss) |
| simdjson | 1427.7 | 1.50425 | 18.1023ms | 108313 | 30 | 3.55346e+07 | 72350.9 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 6906.91 | 0.380618 | 5.26234ms | 108313 | 30 | 97206 | 14955.4 | 1(Win) |
| jsonifier | 6350.93 | 0.375508 | 11.4084ms | 108313 | 32 | 119365 | 16264.6 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3477.71 | 0.442948 | 15.3595ms | 222373 | 30 | 2.18879e+06 | 60980.3 | 1(Win) |
| glaze **STATISTICAL TIE** | 2928.36 | 1.89675 | 376.881ms | 222373 | 256 | 4.83032e+08 | 72419.8 | 2(Tie) |
| simdjson **STATISTICAL TIE** | 2870.65 | 0.823563 | 20.7797ms | 222373 | 30 | 1.1105e+07 | 73875.7 | 2(Tie) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6492.13 | 0.088309 | 9.16959ms | 213963 | 30 | 23111.8 | 31430.5 | 1(Win) |
| glaze | 6021.1 | 0.202853 | 12.2021ms | 213963 | 30 | 141778 | 33889.3 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 657.912 | 1.77484 | 3496.64ms | 1834197 | 64 | 1.42513e+11 | 2.65876e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 637.207 | 2.32615 | 1569.65ms | 1834197 | 32 | 1.30484e+11 | 2.74515e+06 | 1(Tie) |
| simdjson | 374.697 | 1.64248 | 1162.67ms | 1834197 | 30 | 1.76382e+11 | 4.66837e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 943.268 | 2.33245 | 2323.72ms | 1834197 | 64 | 1.19736e+11 | 1.85443e+06 | 1(Win) |
| glaze | 558.878 | 2.09746 | 819.055ms | 1833577 | 30 | 1.29203e+11 | 3.12883e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2525.54 | 1.96874 | 1002.79ms | 10252236 | 30 | 1.74273e+11 | 3.87137e+06 | 1(Win) |
| jsonifier | 2120.75 | 2.35911 | 1177.95ms | 10252236 | 30 | 3.54876e+11 | 4.61031e+06 | 2(Loss) |
| simdjson | 1714.84 | 1.98924 | 1511.62ms | 10252236 | 30 | 3.85908e+11 | 5.70157e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2168.95 | 2.12833 | 5538.73ms | 9930848 | 64 | 5.52753e+11 | 4.36654e+06 | 1(Win) |
| glaze | 1301.51 | 2.08812 | 1828.83ms | 9930228 | 30 | 6.92559e+11 | 7.27634e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1424.86 | 2.37475 | 252.66ms | 642697 | 32 | 3.3393e+09 | 430165 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1365.18 | 1.6965 | 306.342ms | 642697 | 32 | 1.85649e+09 | 448969 | 1(Tie) |
| simdjson | 624.125 | 1.74865 | 622.947ms | 642697 | 32 | 9.43681e+09 | 982052 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1841.5 | 2.17863 | 410.771ms | 642697 | 64 | 3.36523e+09 | 332839 | 1(Win) |
| glaze | 878.925 | 2.21789 | 864.771ms | 642692 | 64 | 1.53095e+10 | 697351 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 2344.22 | 1.96521 | 1358.03ms | 1306201 | 128 | 1.39588e+10 | 531387 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 2260.17 | 2.13003 | 1494.39ms | 1306201 | 128 | 1.76407e+10 | 551148 | 1(Tie) |
| simdjson | 1238.66 | 1.55557 | 253.49ms | 1306201 | 30 | 7.34202e+09 | 1.00568e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2606.74 | 0.397894 | 326.734ms | 1225964 | 32 | 1.01917e+08 | 448518 | 1(Win) |
| glaze | 1610.73 | 1.98126 | 179.013ms | 1225970 | 30 | 6.20466e+09 | 725866 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1486.18 | 0.813952 | 68.9608ms | 409725 | 30 | 1.37391e+08 | 262918 | 1(Win) |
| glaze | 1004.28 | 1.20138 | 97.7512ms | 409725 | 30 | 6.55482e+08 | 389079 | 2(Loss) |
| simdjson | 838.924 | 0.526422 | 276.036ms | 409725 | 32 | 1.92379e+08 | 465768 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3337.13 | 0.923983 | 30.8184ms | 409725 | 30 | 3.51146e+07 | 117090 | 1(Win) |
| jsonifier | 2943.46 | 1.02725 | 399.329ms | 409725 | 128 | 2.38027e+08 | 132750 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1820.94 | 1.63513 | 1088.43ms | 814756 | 128 | 6.23125e+09 | 426709 | 1(Win) |
| glaze | 1632.32 | 0.599296 | 127.231ms | 814756 | 30 | 2.44146e+08 | 476018 | 2(Loss) |
| simdjson | 1422.79 | 1.67598 | 1371.82ms | 814756 | 128 | 1.07231e+10 | 546119 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3920.14 | 1.51394 | 252.984ms | 785750 | 64 | 5.35997e+08 | 191154 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3813.99 | 2.23297 | 50.0422ms | 785750 | 30 | 5.77427e+08 | 196474 | 1(Tie) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6076.98 | 2.17992 | 10.1495ms | 264040 | 30 | 2.44774e+07 | 41436.4 | 1(Win) |
| simdjson | 5622.28 | 2.13651 | 13.4852ms | 264040 | 30 | 2.74692e+07 | 44787.5 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 7734.2 | 1.51785 | 12.4767ms | 399947 | 30 | 1.68093e+07 | 49315.9 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 7371.57 | 2.44141 | 15.2845ms | 399947 | 30 | 4.78725e+07 | 51741.9 | 1(Tie) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2549.26 | 1.10533 | 264.224ms | 264040 | 128 | 1.52582e+08 | 98777 | 1(Win) |
| glaze | 2109.06 | 1.04045 | 32.3578ms | 264040 | 30 | 4.6294e+07 | 119394 | 2(Loss) |
| simdjson | 1517.35 | 1.53152 | 45.9292ms | 264040 | 30 | 1.9379e+08 | 165953 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 6156.76 | 1.54589 | 10.9432ms | 263923 | 30 | 1.19819e+07 | 40881.3 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 6013.12 | 1.16317 | 10.9726ms | 264040 | 30 | 7.11779e+06 | 41876.5 | 1(Tie) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2558.97 | 1.22614 | 40.3148ms | 409612 | 30 | 1.05103e+08 | 152654 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2524.13 | 0.804291 | 99.6558ms | 409612 | 32 | 4.95791e+07 | 154761 | 1(Tie) |
| simdjson | 2089.91 | 1.40149 | 49.7748ms | 409612 | 30 | 2.05869e+08 | 186915 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6627.37 | 2.31117 | 15.5585ms | 399947 | 30 | 5.3077e+07 | 57552.1 | 1(Win) |
| glaze | 5883.64 | 1.53714 | 18.2204ms | 399830 | 30 | 2.97721e+07 | 64808.2 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 2747.66 | 1.05272 | 43.3412ms | 466906 | 30 | 8.73134e+07 | 162056 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 2693.41 | 1.39131 | 43.7737ms | 466906 | 30 | 1.58718e+08 | 165321 | 1(Tie) |
| simdjson | 1220.58 | 1.89554 | 1909.63ms | 466906 | 256 | 1.22415e+10 | 364808 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3832.67 | 0.682561 | 46.0257ms | 699405 | 30 | 4.23311e+07 | 174032 | 1(Win) |
| jsonifier | 3171.01 | 1.95143 | 58.9398ms | 699405 | 30 | 5.05462e+08 | 210345 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4855.34 | 0.385839 | 32.4519ms | 631514 | 30 | 6.87162e+06 | 124040 | 1(Win) |
| glaze | 3931.02 | 0.828028 | 40.4163ms | 631514 | 30 | 4.82799e+07 | 153207 | 2(Loss) |
