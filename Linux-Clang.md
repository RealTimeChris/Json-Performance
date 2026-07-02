# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.17.0-1018-azure using the Clang 23.0.0 compiler).  

Latest Results: (Jul 02, 2026)
#### Using the following commits:
----
| Jsonifier: [6a2069c](https://github.com/RealTimeChris/Jsonifier/commit/6a2069c)  
| Glaze: [4fab045](https://github.com/stephenberry/glaze/commit/4fab045)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (AMD EPYC 9V74 80-Core Processor): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 801.284 | 0.0493368 | 4.25773ms | 1811 | 64 | 72.3748 | 2155.42 | 1(Win) |
| glaze | 650.853 | 0.0803709 | 0.819492ms | 1811 | 30 | 136.455 | 2653.6 | 2(Loss) |
| simdjson | 157.351 | 0.049027 | 2.82476ms | 1811 | 30 | 868.74 | 10976.1 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 381.329 | 2.01344 | 1.15283ms | 1811 | 30 | 249479 | 4529.17 | 1(Tie) |
| glaze **STATISTICAL TIE** | 369.589 | 0.238834 | 2.84239ms | 1798 | 32 | 3929.03 | 4639.5 | 1(Tie) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1518.74 | 0.0695627 | 0.740233ms | 3873 | 30 | 85.8621 | 2432 | 1(Win) |
| glaze | 1252.03 | 0.041878 | 0.872823ms | 3873 | 30 | 45.7885 | 2950.07 | 2(Loss) |
| simdjson | 294.679 | 0.154015 | 3.15137ms | 3873 | 30 | 11180 | 12534.2 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2118.04 | 0.0448193 | 0.5657ms | 3873 | 30 | 18.3264 | 1743.87 | 1(Win) |
| glaze | 1331.76 | 0.598652 | 0.857319ms | 3873 | 30 | 8270.19 | 2773.47 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1587.93 | 0.0529323 | 0.710959ms | 3862 | 30 | 45.2195 | 2319.43 | 1(Win) |
| glaze | 1130.38 | 0.0263619 | 0.954595ms | 3862 | 30 | 22.1333 | 3258.27 | 2(Loss) |
| simdjson | 327.067 | 2.03239 | 2.82664ms | 3862 | 30 | 1.57139e+06 | 11261 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2073.42 | 0.0577859 | 0.582837ms | 3862 | 30 | 31.6092 | 1776.33 | 1(Win) |
| glaze | 1395.29 | 0.217726 | 0.794044ms | 3862 | 30 | 990.92 | 2639.67 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 936.327 | 0.0359185 | 0.357678ms | 905 | 30 | 3.28851 | 921.767 | 1(Win) |
| glaze | 658.233 | 0.0507211 | 0.442636ms | 905 | 30 | 13.269 | 1311.2 | 2(Loss) |
| simdjson | 113.912 | 0.0778338 | 1.97236ms | 905 | 30 | 1043.32 | 7576.7 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 829.986 | 0.0666152 | 0.392741ms | 905 | 30 | 14.3954 | 1039.87 | 1(Win) |
| glaze | 395.803 | 0.449947 | 0.656978ms | 905 | 30 | 2887.91 | 2180.57 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2223.26 | 0.107458 | 1.0728ms | 8813 | 30 | 495.068 | 3780.37 | 1(Win) |
| glaze | 1777.16 | 0.0521445 | 2.91196ms | 8813 | 32 | 194.609 | 4729.31 | 2(Loss) |
| simdjson | 641.028 | 0.17993 | 3.36196ms | 8813 | 30 | 16696.4 | 13111.3 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2812.39 | 0.0910085 | 0.872932ms | 8813 | 30 | 221.913 | 2988.47 | 1(Win) |
| glaze | 2345.9 | 0.161752 | 1.04135ms | 8813 | 30 | 1007.51 | 3582.73 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 1499.38 | 1.07551 | 5.54341ms | 33713 | 30 | 1.59558e+06 | 21443 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1472.4 | 1.19102 | 5.52848ms | 33713 | 30 | 2.02909e+06 | 21835.9 | 1(Tie) |
| simdjson | 310.446 | 0.378579 | 25.3099ms | 33713 | 30 | 4.61166e+06 | 103565 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3170.17 | 0.495314 | 5.96133ms | 33713 | 32 | 80749.8 | 10141.8 | 1(Win) |
| glaze | 2970.83 | 0.178408 | 2.79458ms | 33689 | 30 | 11167.9 | 10814.6 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2056.24 | 1.10605 | 5.82686ms | 49505 | 30 | 1.93475e+06 | 22960.2 | 1(Win) |
| jsonifier | 1439.45 | 0.694602 | 8.24282ms | 49505 | 30 | 1.55703e+06 | 32798.3 | 2(Loss) |
| simdjson | 456.268 | 0.398434 | 25.388ms | 49505 | 30 | 5.0991e+06 | 103474 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3454.38 | 2.16335 | 3.32692ms | 48024 | 30 | 2.46802e+06 | 13258.3 | 1(Win) |
| glaze | 3105.97 | 0.550546 | 3.74809ms | 48000 | 30 | 197514 | 14738.2 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 4756.63 | 0.322538 | 4.07494ms | 33713 | 32 | 15209.3 | 6759.25 | 1(Win) |
| jsonifier | 4047.01 | 0.0617482 | 4.71676ms | 33713 | 32 | 770.06 | 7944.44 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 5884.78 | 0.0573581 | 2.05517ms | 48024 | 30 | 597.816 | 7782.67 | 1(Win) |
| jsonifier | 5167.85 | 0.0386773 | 5.21473ms | 48024 | 32 | 375.975 | 8862.34 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 978.495 | 1.59383 | 22.2588ms | 94651 | 30 | 6.48539e+07 | 92250.1 | 1(Win) |
| glaze | 860.156 | 0.477721 | 25.8098ms | 94651 | 30 | 7.5399e+06 | 104942 | 2(Loss) |
| simdjson | 630.791 | 0.426666 | 34.7982ms | 94651 | 30 | 1.11835e+07 | 143100 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3842.76 | 1.05713 | 5.8271ms | 94651 | 30 | 1.84989e+06 | 23490 | 1(Win) |
| glaze | 3633.7 | 0.082604 | 6.23982ms | 94651 | 30 | 12632.1 | 24841.4 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1125.23 | 0.825229 | 29.1142ms | 140436 | 30 | 2.89429e+07 | 119024 | 1(Win) |
| jsonifier | 1028.83 | 0.424632 | 31.8007ms | 140436 | 30 | 9.16675e+06 | 130177 | 2(Loss) |
| simdjson | 914.502 | 0.339148 | 35.797ms | 140436 | 30 | 7.40094e+06 | 146452 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3576.07 | 2.2728 | 8.79377ms | 136024 | 30 | 2.03922e+07 | 36275.2 | 1(Win) |
| glaze | 3179.02 | 1.48597 | 9.83428ms | 136046 | 30 | 1.10338e+07 | 40812.4 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 478.064 | 0.123666 | 1002.57ms | 2090234 | 30 | 7.97703e+08 | 4.16974e+06 | 1(Win) |
| jsonifier | 423.369 | 0.0917196 | 1131.23ms | 2090234 | 30 | 5.59496e+08 | 4.70843e+06 | 2(Loss) |
| simdjson | 313.406 | 0.0592119 | 1526.14ms | 2090234 | 30 | 4.25513e+08 | 6.36044e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 776.029 | 0.0675151 | 617.691ms | 2090234 | 30 | 9.02313e+07 | 2.56872e+06 | 1(Win) |
| glaze | 758.34 | 0.0490904 | 632.077ms | 2090234 | 30 | 4.99547e+07 | 2.62864e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1258.64 | 0.0454302 | 1253ms | 6885124 | 30 | 1.68511e+08 | 5.21686e+06 | 1(Win) |
| simdjson | 973.718 | 0.048297 | 1621.43ms | 6885124 | 30 | 3.18213e+08 | 6.7434e+06 | 2(Loss) |
| jsonifier | 888.874 | 0.160582 | 1776.54ms | 6885124 | 30 | 4.22142e+09 | 7.38706e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2053.06 | 0.112314 | 742.98ms | 6661897 | 30 | 3.62392e+08 | 3.09454e+06 | 1(Win) |
| glaze | 1889.04 | 0.0565127 | 810.407ms | 6661897 | 30 | 1.08375e+08 | 3.36324e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1067.41 | 0.332839 | 108.371ms | 500299 | 30 | 6.64026e+07 | 446989 | 1(Win) |
| jsonifier | 1014.82 | 0.221385 | 112.661ms | 500299 | 30 | 3.25015e+07 | 470156 | 2(Loss) |
| simdjson | 685.173 | 0.158999 | 167.838ms | 500299 | 30 | 3.67762e+07 | 696353 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3397.27 | 2.05351 | 36.5294ms | 500299 | 30 | 2.49525e+08 | 140443 | 1(Win) |
| glaze | 2787.95 | 0.372161 | 41.426ms | 500299 | 30 | 1.21695e+07 | 171137 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2083.4 | 0.122925 | 163.765ms | 1490030 | 30 | 2.10885e+07 | 682061 | 1(Win) |
| simdjson | 1793.49 | 0.113009 | 190.223ms | 1490030 | 30 | 2.40512e+07 | 792312 | 2(Loss) |
| jsonifier | 1322.61 | 0.192539 | 256.6ms | 1490030 | 30 | 1.28376e+08 | 1.07439e+06 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4675.71 | 0.281959 | 70.9739ms | 1439562 | 30 | 2.05617e+07 | 293618 | 1(Win) |
| glaze | 4116.8 | 0.464276 | 80.5322ms | 1439584 | 30 | 7.19166e+07 | 333486 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1164.42 | 0.468025 | 11.5504ms | 56369 | 30 | 1.40063e+06 | 46167.1 | 1(Win) |
| glaze | 1026.59 | 0.642408 | 12.9723ms | 56369 | 30 | 3.39494e+06 | 52365.4 | 2(Loss) |
| simdjson | 766.764 | 0.594559 | 17.0737ms | 56369 | 30 | 5.21277e+06 | 70109.8 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4265.13 | 0.0867517 | 7.41397ms | 56369 | 32 | 3825.81 | 12604 | 1(Win) |
| glaze | 3283.85 | 0.166412 | 4.14928ms | 56369 | 30 | 22264 | 16370.3 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1550.2 | 0.567004 | 14.8014ms | 98048 | 30 | 3.50911e+06 | 60318.7 | 1(Win) |
| simdjson | 1289.44 | 0.776566 | 17.7466ms | 98048 | 30 | 9.51372e+06 | 72516.4 | 2(Loss) |
| jsonifier | 1096.27 | 0.582171 | 20.8738ms | 98048 | 30 | 7.39717e+06 | 85294.6 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3904.26 | 1.11827 | 5.71027ms | 94370 | 30 | 1.99344e+06 | 23051.3 | 1(Win) |
| glaze | 3236.67 | 0.900184 | 6.85713ms | 94370 | 30 | 1.87956e+06 | 27805.8 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1372.67 | 0.976309 | 9.29401ms | 52708 | 30 | 3.83457e+06 | 36619.3 | 1(Win) |
| glaze | 1021.58 | 0.788828 | 12.2378ms | 52708 | 30 | 4.51953e+06 | 49204.4 | 2(Loss) |
| simdjson | 834.431 | 0.611557 | 14.8305ms | 52708 | 30 | 4.07163e+06 | 60240.2 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 4096.55 | 0.279842 | 3.1719ms | 52708 | 30 | 35372.5 | 12270.4 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 4079.29 | 1.74345 | 7.24229ms | 52708 | 32 | 1.47691e+06 | 12322.3 | 1(Tie) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1264.29 | 0.749616 | 13.4865ms | 71665 | 30 | 4.92627e+06 | 54058 | 1(Win) |
| simdjson | 1103.58 | 0.535059 | 15.3189ms | 71665 | 30 | 3.29405e+06 | 61930.2 | 2(Loss) |
| jsonifier | 968.957 | 0.786434 | 17.6202ms | 71665 | 30 | 9.23105e+06 | 70534.7 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3941.87 | 1.73169 | 9.74239ms | 70103 | 32 | 2.7603e+06 | 16960.3 | 1(Win) |
| jsonifier | 3704.17 | 1.32343 | 10.464ms | 70103 | 32 | 1.82577e+06 | 18048.7 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1028.48 | 0.458657 | 6.4035ms | 11812 | 32 | 80757.5 | 10952.9 | 1(Win) |
| glaze | 748.136 | 2.05776 | 3.78531ms | 11812 | 30 | 2.88002e+06 | 15057.2 | 2(Loss) |
| simdjson | 532.308 | 1.29636 | 5.26573ms | 11812 | 30 | 2.25784e+06 | 21162.2 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3266.3 | 0.10362 | 0.982605ms | 11812 | 30 | 383.131 | 3448.8 | 1(Win) |
| glaze | 2338.01 | 0.216806 | 2.9335ms | 11812 | 32 | 3491.79 | 4818.12 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1649.31 | 0.177988 | 4.86936ms | 32403 | 30 | 33363.4 | 18736.3 | 1(Win) |
| simdjson | 1394.32 | 1.30641 | 5.49022ms | 32403 | 30 | 2.51491e+06 | 22162.7 | 2(Loss) |
| jsonifier | 1256.63 | 1.04899 | 6.0174ms | 32403 | 30 | 1.99626e+06 | 24591 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4202.69 | 0.0411828 | 4.22089ms | 31235 | 32 | 272.652 | 7087.84 | 1(Win) |
| glaze | 3546.49 | 0.179601 | 2.18843ms | 31235 | 30 | 6826.91 | 8399.3 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2018.87 | 0.721708 | 12.6243ms | 108313 | 30 | 4.09062e+06 | 51164.9 | 1(Win) |
| glaze | 1366.21 | 0.561941 | 18.3786ms | 108313 | 30 | 5.41536e+06 | 75607 | 2(Loss) |
| simdjson | 1059.31 | 1.65914 | 23.1504ms | 108313 | 30 | 7.85231e+07 | 97511.6 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3529.26 | 0.816889 | 7.19777ms | 108313 | 30 | 1.71491e+06 | 29268.3 | 1(Win) |
| glaze | 1818.81 | 1.55807 | 13.6748ms | 108313 | 30 | 2.34899e+07 | 56792.8 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2111 | 0.59354 | 24.3011ms | 222373 | 30 | 1.06661e+07 | 100460 | 1(Win) |
| simdjson | 1997.36 | 0.476303 | 25.6932ms | 222373 | 30 | 7.67253e+06 | 106176 | 2(Loss) |
| jsonifier | 1173.82 | 0.324462 | 43.7076ms | 222373 | 30 | 1.03088e+07 | 180667 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4391.32 | 0.511944 | 11.3849ms | 213963 | 30 | 1.69767e+06 | 46466.9 | 1(Win) |
| glaze | 2289.91 | 0.536434 | 21.6453ms | 213963 | 30 | 6.8548e+06 | 89108.7 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 454.281 | 0.139054 | 924.957ms | 1834197 | 30 | 8.6006e+08 | 3.85054e+06 | 1(Win) |
| jsonifier | 404.317 | 0.200697 | 1030.14ms | 1834197 | 30 | 2.26179e+09 | 4.32638e+06 | 2(Loss) |
| simdjson | 282.292 | 0.0579613 | 1491.77ms | 1834197 | 30 | 3.86985e+08 | 6.19652e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 493.89 | 0.0577534 | 850.923ms | 1833577 | 30 | 1.25434e+08 | 3.54053e+06 | 1(Win) |
| jsonifier | 473.662 | 0.099064 | 883.027ms | 1834197 | 30 | 4.01521e+08 | 3.69298e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1846.9 | 0.195672 | 1267.59ms | 10252236 | 30 | 3.21904e+09 | 5.29389e+06 | 1(Win) |
| simdjson | 1420.3 | 0.088822 | 1652.88ms | 10252236 | 30 | 1.1216e+09 | 6.88397e+06 | 2(Loss) |
| jsonifier | 1098.36 | 0.272222 | 2135.43ms | 10252236 | 30 | 1.76164e+10 | 8.90174e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1800.75 | 0.379096 | 1258.43ms | 9930848 | 30 | 1.19257e+10 | 5.25935e+06 | 1(Win) |
| glaze | 1676.59 | 0.0824392 | 1363.72ms | 9930228 | 30 | 6.50511e+08 | 5.6485e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 954.736 | 0.41117 | 155.114ms | 642697 | 30 | 2.09031e+08 | 641982 | 1(Win) |
| jsonifier | 777.578 | 0.131938 | 189.629ms | 642697 | 30 | 3.24477e+07 | 788247 | 2(Loss) |
| simdjson | 442.463 | 0.093414 | 334.08ms | 642697 | 30 | 5.02348e+07 | 1.38525e+06 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 850.63 | 0.100788 | 173.593ms | 642697 | 30 | 1.58223e+07 | 720553 | 1(Win) |
| glaze | 781.388 | 0.122848 | 188.553ms | 642692 | 30 | 2.78568e+07 | 784397 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1631.04 | 0.378326 | 183.115ms | 1306201 | 30 | 2.50464e+08 | 763742 | 1(Win) |
| jsonifier | 1015.88 | 0.308543 | 296.471ms | 1306201 | 30 | 4.29423e+08 | 1.22621e+06 | 2(Loss) |
| simdjson | 870.44 | 0.0704333 | 344.381ms | 1306201 | 30 | 3.04803e+07 | 1.4311e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1238.11 | 0.0535171 | 227.337ms | 1225970 | 30 | 7.66213e+06 | 944326 | 1(Win) |
| jsonifier | 1206.19 | 0.0702477 | 233.253ms | 1225964 | 30 | 1.39095e+07 | 969311 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 879.088 | 0.23216 | 107.189ms | 409725 | 30 | 3.19461e+07 | 444488 | 1(Win) |
| glaze | 519.411 | 0.137632 | 180.426ms | 409725 | 30 | 3.21604e+07 | 752284 | 2(Loss) |
| simdjson | 496.435 | 0.181509 | 190.614ms | 409725 | 30 | 6.12322e+07 | 787101 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2420.03 | 0.393314 | 39.752ms | 409725 | 30 | 1.20989e+07 | 161463 | 1(Win) |
| glaze | 2176.81 | 0.401978 | 43.8657ms | 409725 | 30 | 1.56195e+07 | 179503 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 948.409 | 0.291438 | 196.411ms | 814756 | 30 | 1.71032e+08 | 819279 | 1(Win) |
| jsonifier | 906.842 | 0.0997748 | 206.536ms | 814756 | 30 | 2.19258e+07 | 856833 | 2(Loss) |
| glaze | 883.116 | 0.189002 | 211.599ms | 814756 | 30 | 8.29607e+07 | 879852 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2897.61 | 0.267696 | 62.5497ms | 785750 | 30 | 1.43778e+07 | 258609 | 1(Win) |
| glaze | 2819.25 | 0.478842 | 64.1062ms | 785750 | 30 | 4.85967e+07 | 265797 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4573.19 | 0.752781 | 13.3705ms | 264040 | 30 | 5.15419e+06 | 55061.8 | 1(Win) |
| simdjson | 4185.03 | 0.728998 | 14.5983ms | 264040 | 30 | 5.77187e+06 | 60168.8 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5919.33 | 0.3481 | 15.7205ms | 399947 | 30 | 1.50935e+06 | 64436.2 | 1(Win) |
| simdjson | 5391.26 | 0.690863 | 17.1625ms | 399947 | 30 | 7.16687e+06 | 70747.7 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1615.26 | 0.469117 | 39.354ms | 264040 | 30 | 1.60448e+07 | 155893 | 1(Win) |
| glaze | 1297.89 | 0.44367 | 47.6442ms | 264040 | 30 | 2.22284e+07 | 194014 | 2(Loss) |
| simdjson | 901.52 | 0.543147 | 157.448ms | 264040 | 32 | 7.36501e+07 | 279315 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4406.38 | 0.773304 | 14.6736ms | 264040 | 30 | 5.85865e+06 | 57146.3 | 1(Win) |
| glaze | 3207.77 | 0.730299 | 19.0757ms | 263923 | 30 | 9.85081e+06 | 78464.7 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1561.47 | 0.379497 | 60.6003ms | 409612 | 30 | 2.70405e+07 | 250172 | 1(Win) |
| simdjson | 1330.72 | 0.404472 | 70.9853ms | 409612 | 30 | 4.22934e+07 | 293553 | 2(Loss) |
| jsonifier | 1126.75 | 0.354206 | 84.0649ms | 409612 | 30 | 4.52399e+07 | 346692 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3845.61 | 0.463794 | 24.5861ms | 399947 | 30 | 6.34814e+06 | 99183.1 | 1(Win) |
| glaze | 3458.27 | 0.477894 | 26.9373ms | 399830 | 30 | 8.32944e+06 | 110260 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2079.39 | 0.281689 | 51.7653ms | 466906 | 30 | 1.09156e+07 | 214138 | 1(Win) |
| jsonifier | 1983.01 | 0.324126 | 54.4589ms | 466906 | 30 | 1.58914e+07 | 224546 | 2(Loss) |
| simdjson | 866.621 | 0.170564 | 124.946ms | 466906 | 30 | 2.30408e+07 | 513808 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Linux-Clang/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2741.18 | 0.411391 | 58.3771ms | 699405 | 30 | 3.00617e+07 | 243327 | 1(Win) |
| jsonifier | 2326.36 | 0.400077 | 68.9835ms | 699405 | 30 | 3.94741e+07 | 286716 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Linux-Clang/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3595.04 | 0.352166 | 40.585ms | 631514 | 30 | 1.04418e+07 | 167525 | 1(Win) |
| glaze | 2772.76 | 0.286883 | 52.4703ms | 631514 | 30 | 1.16486e+07 | 217206 | 2(Loss) |
