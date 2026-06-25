# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 24.6.0 using the GCC 16.1.0 compiler).  

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
### Double Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 892.099 | 1.85969 | 13.1612ms | 1811 | 64 | 82960.3 | 1936 | 1(Win) |
| glaze | 684.815 | 1.81579 | 7.84998ms | 1811 | 128 | 268429 | 2522 | 2(Loss) |
| simdjson | 154.147 | 2.45862 | 3.31904ms | 1811 | 30 | 2.27651e+06 | 11204.3 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 551.485 | 2.2061 | 1.97606ms | 1811 | 30 | 143200 | 3131.73 | 1(Win) |
| glaze | 418.629 | 1.27137 | 1.55699ms | 1798 | 30 | 81355 | 4096 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1482.18 | 1.87401 | 7.74195ms | 3873 | 128 | 279157 | 2492 | 1(Win) |
| jsonifier | 1349.99 | 2.05109 | 4.13798ms | 3873 | 64 | 201549 | 2736 | 2(Loss) |
| simdjson | 358.609 | 0.839991 | 3.01594ms | 3873 | 30 | 224555 | 10299.7 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1841.88 | 0.883463 | 0.967168ms | 3873 | 30 | 9416.09 | 2005.33 | 1(Win) |
| glaze | 1258.26 | 2.20201 | 1.08518ms | 3873 | 30 | 125347 | 2935.47 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1412.23 | 2.46249 | 4.04582ms | 3862 | 64 | 263964 | 2608 | 1(Tie) |
| glaze **STATISTICAL TIE** | 1351.1 | 1.03854 | 15.584ms | 3862 | 256 | 205181 | 2726 | 1(Tie) |
| simdjson | 353.201 | 1.18256 | 3.65594ms | 3862 | 30 | 456191 | 10427.7 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1473.24 | 1.84368 | 7.58502ms | 3862 | 128 | 271932 | 2500 | 1(Win) |
| glaze | 1229.66 | 0.727319 | 1.21216ms | 3862 | 30 | 14237.1 | 2995.2 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1252.19 | 2.30317 | 15.606ms | 905 | 1024 | 258050 | 689.25 | 1(Win) |
| glaze | 917.189 | 1.63606 | 5.79712ms | 905 | 256 | 60676 | 941 | 2(Loss) |
| simdjson | 186.265 | 2.05786 | 1.68909ms | 905 | 30 | 272765 | 4633.6 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 763.783 | 1.92252 | 7.29114ms | 905 | 256 | 120820 | 1130 | 1(Win) |
| glaze | 375.904 | 1.79193 | 6.67494ms | 905 | 128 | 216669 | 2296 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2382.29 | 2.41046 | 2.68314ms | 8813 | 32 | 231424 | 3528 | 1(Win) |
| glaze | 1840.99 | 2.15226 | 1.57005ms | 8813 | 30 | 289639 | 4565.33 | 2(Loss) |
| simdjson | 645.009 | 0.317348 | 3.60986ms | 8813 | 30 | 51298.9 | 13030.4 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2654.8 | 2.14059 | 1.32608ms | 8813 | 30 | 137776 | 3165.87 | 1(Win) |
| jsonifier | 2298.89 | 1.6242 | 5.11411ms | 8813 | 64 | 225670 | 3656 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1656.87 | 0.98481 | 5.36294ms | 33713 | 30 | 1.09558e+06 | 19404.8 | 1(Win) |
| glaze | 1599.88 | 0.284849 | 5.34886ms | 33713 | 30 | 98304 | 20096 | 2(Loss) |
| simdjson | 787.403 | 0.230409 | 12.1792ms | 33713 | 30 | 265534 | 40832 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2518.53 | 0.90059 | 4.37018ms | 33713 | 30 | 396530 | 12765.9 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2490.11 | 0.481332 | 4.544ms | 33689 | 30 | 115705 | 12902.4 | 1(Tie) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1720.88 | 0.899355 | 8.18099ms | 49505 | 30 | 1.82635e+06 | 27434.7 | 1(Win) |
| jsonifier | 1658.46 | 0.346014 | 8.90394ms | 49505 | 30 | 291070 | 28467.2 | 2(Loss) |
| simdjson | 1144.99 | 0.190453 | 11.6349ms | 49505 | 30 | 185007 | 41233.1 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2254.9 | 0.725921 | 5.824ms | 48000 | 30 | 651518 | 20300.8 | 1(Win) |
| jsonifier | 2117.98 | 1.67423 | 12.2619ms | 48024 | 32 | 4.19424e+06 | 21624 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4068.81 | 0.818025 | 2.4169ms | 33713 | 30 | 125347 | 7901.87 | 1(Win) |
| simdjson | 2957.25 | 2.2378 | 7.01978ms | 33713 | 32 | 1.89414e+06 | 10872 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4579.44 | 0.118568 | 2.97882ms | 48024 | 30 | 4218.41 | 10001.1 | 1(Win) |
| simdjson | 3633.78 | 0.726706 | 3.55482ms | 48024 | 30 | 251673 | 12603.7 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 834.562 | 0.123665 | 27.191ms | 94651 | 30 | 536717 | 108160 | 1(Win) |
| glaze | 775.064 | 0.367202 | 28.7439ms | 94651 | 30 | 5.48664e+06 | 116463 | 2(Loss) |
| simdjson | 624.075 | 0.870929 | 35.9969ms | 94651 | 30 | 4.76063e+07 | 144640 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 3779.68 | 1.77355 | 61.292ms | 94651 | 128 | 2.29636e+07 | 23882 | 1(Win) |
| jsonifier | 3290.23 | 0.473659 | 8.03277ms | 94651 | 30 | 506586 | 27434.7 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 998.724 | 0.229571 | 33.89ms | 140436 | 30 | 2.84328e+06 | 134101 | 1(Win) |
| simdjson | 977.513 | 0.151609 | 33.8941ms | 140436 | 30 | 1.29445e+06 | 137011 | 2(Loss) |
| glaze | 961.7 | 0.463703 | 35.3152ms | 140436 | 30 | 1.25106e+07 | 139264 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2966.7 | 2.19421 | 11.1818ms | 136046 | 30 | 2.76249e+07 | 43733.3 | 1(Win) |
| jsonifier | 2765.99 | 0.507756 | 12.3121ms | 136024 | 30 | 1.70122e+06 | 46899.2 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 491.041 | 0.178972 | 934.287ms | 2090234 | 30 | 1.5836e+09 | 4.05955e+06 | 1(Win) |
| glaze | 472.096 | 1.63279 | 996.297ms | 2090234 | 30 | 1.42598e+11 | 4.22246e+06 | 2(Loss) |
| simdjson | 394.452 | 0.137366 | 1211.47ms | 2090234 | 30 | 1.44571e+09 | 5.05359e+06 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1428.93 | 0.115805 | 917.364ms | 2090234 | 32 | 8.35166e+07 | 1.39503e+06 | 1(Win) |
| glaze | 1204.16 | 1.33677 | 393.069ms | 2090234 | 30 | 1.46912e+10 | 1.65543e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1272.99 | 0.528398 | 1217.16ms | 6885124 | 30 | 2.22853e+10 | 5.15807e+06 | 1(Win) |
| glaze | 1252 | 0.31158 | 1346.49ms | 6885124 | 30 | 8.01077e+09 | 5.24453e+06 | 2(Loss) |
| simdjson | 1139.31 | 0.314409 | 1374.79ms | 6885124 | 30 | 9.85029e+09 | 5.76326e+06 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1894.9 | 0.775784 | 840.99ms | 6661897 | 30 | 2.02967e+10 | 3.35283e+06 | 1(Win) |
| glaze | 1843.76 | 0.461357 | 826.772ms | 6661897 | 30 | 7.58202e+09 | 3.44584e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1219.21 | 0.746821 | 92.9661ms | 500299 | 30 | 2.56247e+08 | 391339 | 1(Win) |
| glaze | 1088.9 | 0.536641 | 107.479ms | 500299 | 30 | 1.65872e+08 | 438170 | 2(Loss) |
| simdjson | 666.183 | 0.416105 | 172.336ms | 500299 | 30 | 2.66439e+08 | 716203 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1853.63 | 0.261826 | 62.8928ms | 500299 | 30 | 1.36258e+07 | 257399 | 1(Win) |
| glaze | 1551.45 | 2.49803 | 74.7279ms | 500299 | 30 | 1.77051e+09 | 307533 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1934.31 | 0.414238 | 424.295ms | 1490030 | 32 | 2.96339e+08 | 734632 | 1(Win) |
| simdjson | 1705.75 | 0.247722 | 200.682ms | 1490030 | 30 | 1.27764e+08 | 833067 | 2(Loss) |
| glaze | 1630.35 | 2.09979 | 215.306ms | 1490030 | 30 | 1.00485e+10 | 871595 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2885.75 | 0.96233 | 114.236ms | 1439562 | 30 | 6.288e+08 | 475742 | 1(Win) |
| glaze | 1674.26 | 0.419496 | 198.018ms | 1439584 | 30 | 3.54982e+08 | 820002 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1485.08 | 0.302526 | 13.3038ms | 56369 | 30 | 359770 | 36198.4 | 1(Win) |
| glaze | 1198.12 | 0.35345 | 11.563ms | 56369 | 30 | 754493 | 44868.3 | 2(Loss) |
| simdjson | 792.917 | 0.223999 | 16.7759ms | 56369 | 30 | 691894 | 67797.3 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4960.41 | 1.36539 | 3.26784ms | 56369 | 30 | 656867 | 10837.3 | 1(Win) |
| glaze | 2729.52 | 0.453425 | 5.248ms | 56369 | 30 | 239244 | 19694.9 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1616.9 | 0.43308 | 15.51ms | 98048 | 30 | 1.88179e+06 | 57830.4 | 1(Win) |
| glaze | 1514.75 | 2.06951 | 15.799ms | 98048 | 30 | 4.8961e+07 | 61730.1 | 2(Loss) |
| simdjson | 1281.01 | 0.237052 | 18.0982ms | 98048 | 30 | 898220 | 72994.1 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2919.09 | 0.277779 | 8.03584ms | 94370 | 30 | 220035 | 30830.9 | 1(Win) |
| glaze | 1745.57 | 2.11592 | 263.792ms | 94370 | 256 | 3.04671e+08 | 51558 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1315.73 | 1.59713 | 99.7181ms | 52708 | 128 | 4.7655e+07 | 38204 | 1(Win) |
| glaze | 914.73 | 2.19109 | 63.486ms | 52708 | 64 | 9.27828e+07 | 54952 | 2(Loss) |
| simdjson | 662.034 | 2.39993 | 385.544ms | 52708 | 256 | 8.5002e+08 | 75927 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4145.38 | 0.540229 | 4.04403ms | 52708 | 30 | 128737 | 12125.9 | 1(Win) |
| glaze | 3203.14 | 1.56461 | 4.31795ms | 52708 | 30 | 1.80857e+06 | 15692.8 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1346.31 | 0.947962 | 12.9221ms | 71665 | 30 | 6.94749e+06 | 50764.8 | 1(Win) |
| glaze | 1221.1 | 2.26182 | 14.6752ms | 71665 | 30 | 4.80785e+07 | 55970.1 | 2(Loss) |
| jsonifier | 720.658 | 2.33788 | 524.974ms | 71665 | 256 | 1.25846e+09 | 94837 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3587.28 | 0.639897 | 5.17402ms | 70103 | 30 | 426662 | 18636.8 | 1(Win) |
| glaze | 3304.35 | 1.25284 | 5.888ms | 70103 | 30 | 1.92759e+06 | 20232.5 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 842.972 | 0.677461 | 4.29594ms | 11812 | 30 | 245873 | 13363.2 | 1(Win) |
| glaze | 720.575 | 0.642351 | 4.43802ms | 11812 | 30 | 302520 | 15633.1 | 2(Loss) |
| simdjson | 576.712 | 0.466663 | 5.63789ms | 11812 | 30 | 249263 | 19532.8 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4028.9 | 2.03209 | 4.22886ms | 11812 | 64 | 206604 | 2796 | 1(Win) |
| glaze | 1594.32 | 0.769085 | 2.3529ms | 11812 | 30 | 88586.6 | 7065.6 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1517.1 | 0.453682 | 5.2841ms | 32403 | 30 | 256193 | 20369.1 | 1(Win) |
| jsonifier | 1483.54 | 0.644114 | 8.30515ms | 32403 | 30 | 540032 | 20829.9 | 2(Loss) |
| simdjson | 1341.73 | 0.172553 | 5.99219ms | 32403 | 30 | 47381.8 | 23031.5 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3359.75 | 1.04045 | 2.75814ms | 31235 | 30 | 255289 | 8866.13 | 1(Win) |
| glaze | 2441.11 | 0.597906 | 3.85792ms | 31235 | 30 | 159697 | 12202.7 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2361.94 | 0.219353 | 11.8909ms | 108313 | 30 | 276080 | 43733.3 | 1(Win) |
| glaze | 1233.18 | 0.501099 | 21.2401ms | 108313 | 30 | 5.28537e+06 | 83763.2 | 2(Loss) |
| simdjson | 1052.97 | 0.101956 | 24.2678ms | 108313 | 30 | 300110 | 98099.2 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1663.22 | 0.477444 | 15.564ms | 108313 | 30 | 2.63771e+06 | 62105.6 | 1(Win) |
| glaze | 1118.04 | 2.30787 | 457.638ms | 108313 | 256 | 1.16389e+09 | 92390 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2152.82 | 0.517115 | 25.387ms | 222373 | 30 | 7.78477e+06 | 98508.8 | 1(Win) |
| glaze | 1822 | 0.393066 | 28.9359ms | 222373 | 30 | 6.2794e+06 | 116395 | 2(Loss) |
| simdjson | 1760.69 | 0.287825 | 29.6369ms | 222373 | 30 | 3.60561e+06 | 120448 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2758.68 | 0.137776 | 18.8902ms | 213963 | 30 | 311560 | 73966.9 | 1(Win) |
| glaze | 1772.06 | 0.568743 | 652.947ms | 213963 | 256 | 1.09797e+08 | 115149 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 430.831 | 0.288192 | 976.249ms | 1834197 | 30 | 4.10737e+09 | 4.06013e+06 | 1(Win) |
| jsonifier | 427.123 | 0.300671 | 986.561ms | 1834197 | 30 | 4.54873e+09 | 4.09537e+06 | 2(Loss) |
| simdjson | 363.658 | 0.435064 | 1169.41ms | 1834197 | 30 | 1.31381e+10 | 4.81009e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 647.852 | 0.314588 | 664.864ms | 1834197 | 30 | 2.16444e+09 | 2.70004e+06 | 1(Win) |
| glaze | 599.052 | 0.438606 | 672.503ms | 1833577 | 30 | 4.91746e+09 | 2.91901e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1797.37 | 0.334635 | 1368.57ms | 10252236 | 30 | 9.94097e+09 | 5.43979e+06 | 1(Win) |
| simdjson | 1601.79 | 0.274889 | 1524.7ms | 10252236 | 30 | 8.44617e+09 | 6.10397e+06 | 2(Loss) |
| jsonifier | 1567.94 | 0.645044 | 1495.91ms | 10252236 | 30 | 4.85377e+10 | 6.23577e+06 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2233.48 | 0.304294 | 1039.87ms | 9930848 | 30 | 4.99481e+09 | 4.24038e+06 | 1(Win) |
| glaze | 1482.81 | 0.754681 | 1684.88ms | 9930228 | 30 | 6.96944e+10 | 6.38667e+06 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 791.997 | 0.370098 | 192.524ms | 642697 | 30 | 2.46106e+08 | 773897 | 1(Win) |
| jsonifier | 727.826 | 1.14908 | 194.594ms | 642697 | 30 | 2.8092e+09 | 842129 | 2(Loss) |
| simdjson | 678.112 | 0.0813076 | 218.298ms | 642697 | 30 | 1.62029e+07 | 903868 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 963.254 | 0.210363 | 155.827ms | 642697 | 30 | 5.37516e+07 | 636305 | 1(Win) |
| glaze | 821.973 | 0.296649 | 178.462ms | 642692 | 30 | 1.4679e+08 | 745668 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1375.28 | 1.63949 | 214.625ms | 1306201 | 30 | 6.61566e+09 | 905771 | 1(Win) |
| simdjson | 1255.62 | 0.103486 | 239.758ms | 1306201 | 30 | 3.16222e+07 | 992094 | 2(Loss) |
| jsonifier | 1237.9 | 0.420311 | 243.119ms | 1306201 | 30 | 5.36677e+08 | 1.00629e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1885.04 | 0.218954 | 149.598ms | 1225964 | 30 | 5.53278e+07 | 620237 | 1(Win) |
| glaze | 1131.28 | 0.404847 | 253.714ms | 1225970 | 30 | 5.25198e+08 | 1.0335e+06 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 699.377 | 0.494716 | 132.207ms | 409725 | 30 | 2.29189e+08 | 558703 | 1(Win) |
| simdjson | 521.803 | 0.0629884 | 180.894ms | 409725 | 30 | 6.67443e+06 | 748834 | 2(Loss) |
| glaze | 478.809 | 0.728778 | 1071ms | 409725 | 64 | 2.26377e+09 | 816076 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3353.62 | 0.736571 | 29.666ms | 409725 | 30 | 2.20957e+07 | 116514 | 1(Win) |
| glaze | 1589.94 | 2.15275 | 60.1352ms | 409725 | 30 | 8.39715e+08 | 245760 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 977.615 | 1.92567 | 180.489ms | 814756 | 30 | 7.02756e+09 | 794803 | 1(Win) |
| glaze | 929.182 | 0.328138 | 204.307ms | 814756 | 30 | 2.25886e+08 | 836233 | 2(Loss) |
| simdjson | 877.454 | 1.96349 | 203.795ms | 814756 | 30 | 9.06957e+09 | 885530 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2529 | 0.404219 | 71.125ms | 785750 | 30 | 4.30354e+07 | 296303 | 1(Win) |
| glaze | 1461.84 | 1.9895 | 273.719ms | 785750 | 32 | 3.32818e+09 | 512608 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3139.9 | 0.0954997 | 20.3699ms | 264040 | 30 | 175968 | 80196.3 | 1(Win) |
| simdjson | 2687.26 | 0.670925 | 23.1091ms | 264040 | 30 | 1.18574e+07 | 93704.5 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3986.94 | 0.185106 | 24.8261ms | 399947 | 30 | 940781 | 95667.2 | 1(Win) |
| simdjson | 3602.9 | 0.189003 | 26.199ms | 399947 | 30 | 1.20104e+06 | 105865 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1911.07 | 0.198955 | 33.9789ms | 264040 | 30 | 2.06167e+06 | 131763 | 1(Win) |
| glaze | 1120.64 | 2.12434 | 54.8549ms | 264040 | 30 | 6.83554e+08 | 224700 | 2(Loss) |
| simdjson | 993.695 | 1.77978 | 62.057ms | 264040 | 30 | 6.1022e+08 | 253406 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3110.11 | 2.36774 | 21.5498ms | 264040 | 30 | 1.10249e+08 | 80964.3 | 1(Win) |
| glaze | 2832.31 | 2.06668 | 22.5992ms | 263923 | 30 | 1.01191e+08 | 88866.1 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1633.28 | 0.111132 | 58.209ms | 409612 | 30 | 2.11945e+06 | 239172 | 1(Win) |
| glaze | 1408.41 | 1.84845 | 69.8401ms | 409612 | 30 | 7.88532e+08 | 277359 | 2(Loss) |
| jsonifier | 1298.07 | 1.12416 | 171.319ms | 409612 | 32 | 3.66228e+08 | 300936 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3487.37 | 0.634512 | 28.5179ms | 399947 | 30 | 1.44481e+07 | 109372 | 1(Win) |
| glaze | 2431.13 | 2.44492 | 401.126ms | 399830 | 128 | 1.88224e+09 | 156844 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1626.89 | 0.256162 | 66.7249ms | 466906 | 30 | 1.47467e+07 | 273698 | 1(Win) |
| jsonifier | 1366.17 | 0.346015 | 77.119ms | 466906 | 30 | 3.81559e+07 | 325931 | 2(Loss) |
| simdjson | 799.045 | 0.412849 | 134.991ms | 466906 | 30 | 1.58789e+08 | 557261 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/macOS-GCC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/macOS-GCC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2047.86 | 0.410265 | 79.554ms | 699405 | 30 | 5.35684e+07 | 325709 | 1(Win) |
| jsonifier | 2022.27 | 0.199766 | 81.8701ms | 699405 | 30 | 1.3024e+07 | 329830 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/macOS-GCC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/macOS-GCC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/macOS-GCC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2345.85 | 0.398304 | 62.8541ms | 631514 | 30 | 3.13702e+07 | 256734 | 1(Win) |
| jsonifier | 2319.02 | 0.126266 | 64.319ms | 631514 | 30 | 3.22588e+06 | 259703 | 2(Loss) |
