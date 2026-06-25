# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.6.87.2-microsoft-standard-WSL2 using the GCC 16.0.1 compiler).  

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
### Double Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1183.11 | 0.137688 | 2.73427ms | 1811 | 30 | 121.2 | 1459.8 | 1(Win) |
| glaze | 943.79 | 0.324671 | 0.826297ms | 1811 | 30 | 1059 | 1829.97 | 2(Loss) |
| simdjson | 254.307 | 0.0472287 | 5.59681ms | 1811 | 32 | 329.217 | 6791.41 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 504.701 | 0.0355694 | 1.0239ms | 1811 | 30 | 44.4471 | 3422.03 | 1(Win) |
| glaze | 263.451 | 0.0980926 | 3.56603ms | 1798 | 32 | 1304.37 | 6508.62 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2088.58 | 0.0466239 | 0.830572ms | 3873 | 30 | 20.3954 | 1768.47 | 1(Win) |
| glaze | 1970.12 | 0.0642618 | 0.864582ms | 3873 | 30 | 43.5448 | 1874.8 | 2(Loss) |
| simdjson | 467.384 | 0.48575 | 2.59735ms | 3873 | 30 | 44207.4 | 7902.67 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3231.57 | 0.0740354 | 0.668175ms | 3873 | 30 | 21.4816 | 1142.97 | 1(Win) |
| glaze | 1401.65 | 0.121757 | 1.00337ms | 3873 | 30 | 308.833 | 2635.17 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2130.31 | 0.0361957 | 0.855268ms | 3862 | 30 | 11.7483 | 1728.9 | 1(Win) |
| glaze | 1843.97 | 0.0673197 | 0.804672ms | 3862 | 30 | 54.2402 | 1997.37 | 2(Loss) |
| simdjson | 482.495 | 0.523989 | 2.24396ms | 3862 | 30 | 47996 | 7633.43 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3203.71 | 0.299483 | 0.671188ms | 3862 | 30 | 355.62 | 1149.63 | 1(Win) |
| glaze | 1421.44 | 0.139843 | 0.985541ms | 3862 | 30 | 393.886 | 2591.1 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1781.37 | 0.0353359 | 1.10769ms | 905 | 30 | 0.87931 | 484.5 | 1(Win) |
| glaze | 702.03 | 0.0306092 | 0.627701ms | 905 | 30 | 4.24828 | 1229.4 | 2(Loss) |
| simdjson | 192.562 | 0.197218 | 1.43188ms | 905 | 30 | 2344.06 | 4482.07 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1389.96 | 0.0344747 | 0.447467ms | 905 | 30 | 1.37471 | 620.933 | 1(Win) |
| glaze | 373.292 | 0.164728 | 0.885058ms | 905 | 30 | 435.168 | 2312.07 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4881.55 | 0.13005 | 0.789302ms | 8813 | 30 | 150.409 | 1721.73 | 1(Win) |
| glaze | 2500.91 | 0.255339 | 1.23921ms | 8813 | 30 | 2209.06 | 3360.67 | 2(Loss) |
| simdjson | 1282.21 | 0.0897069 | 1.8898ms | 8813 | 30 | 1037.29 | 6554.87 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4317.28 | 0.248844 | 0.873153ms | 8813 | 30 | 704.047 | 1946.77 | 1(Win) |
| glaze | 2964.11 | 0.174434 | 1.03926ms | 8813 | 30 | 733.914 | 2835.5 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2455.98 | 0.363659 | 10.0727ms | 33713 | 32 | 72524.4 | 13091 | 1(Win) |
| glaze | 2380.31 | 0.951137 | 17.2964ms | 33713 | 64 | 1.05632e+06 | 13507.2 | 2(Loss) |
| simdjson | 2137.59 | 0.144195 | 21.6321ms | 33713 | 64 | 30104.3 | 15040.9 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5221.84 | 0.105745 | 2.01047ms | 33713 | 30 | 1271.72 | 6157.07 | 1(Win) |
| glaze | 5084.37 | 0.190456 | 1.96648ms | 33689 | 30 | 4345.21 | 6319.03 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 3088.18 | 0.31663 | 9.74809ms | 49505 | 32 | 74980.3 | 15287.9 | 1(Win) |
| glaze | 3045.51 | 0.210024 | 5.31806ms | 49505 | 30 | 31800.7 | 15502.1 | 2(Loss) |
| jsonifier | 2247.17 | 2.40155 | 6.66705ms | 49505 | 30 | 7.63713e+06 | 21009.4 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 5307 | 0.553215 | 2.54304ms | 48024 | 30 | 68379.6 | 8629.97 | 1(Win) |
| glaze | 5058.7 | 0.298381 | 11.5506ms | 48000 | 64 | 46658.2 | 9049.03 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6776.43 | 0.100344 | 1.66097ms | 33713 | 30 | 679.978 | 4744.57 | 1(Win) |
| simdjson | 4906.84 | 0.10821 | 1.9219ms | 33713 | 30 | 1508.16 | 6552.33 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7759.82 | 0.196273 | 1.8477ms | 48024 | 30 | 4025.82 | 5902.1 | 1(Win) |
| simdjson | 6217.88 | 0.0962506 | 2.13046ms | 48024 | 30 | 1507.86 | 7365.73 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1554.58 | 1.13625 | 14.5477ms | 94651 | 30 | 1.30586e+07 | 58064.7 | 1(Win) |
| glaze | 1305.59 | 1.96489 | 18.4221ms | 94651 | 30 | 5.53653e+07 | 69138.5 | 2(Loss) |
| simdjson | 1243.13 | 0.914648 | 18.3853ms | 94651 | 30 | 1.32326e+07 | 72611.8 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6533.71 | 0.162223 | 3.7599ms | 94651 | 30 | 15068.7 | 13815.5 | 1(Win) |
| glaze | 6061.49 | 0.145354 | 4.35136ms | 94651 | 30 | 14056.3 | 14891.8 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1782.32 | 0.679771 | 21.0302ms | 140436 | 30 | 7.82769e+06 | 75143.9 | 1(Win) |
| glaze | 1602.3 | 0.719468 | 21.168ms | 140436 | 30 | 1.08496e+07 | 83586.2 | 2(Loss) |
| jsonifier | 1556.63 | 1.06476 | 69.2552ms | 140436 | 32 | 2.68558e+07 | 86038.6 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6350.09 | 1.17222 | 7.23984ms | 136024 | 30 | 1.72033e+06 | 20428.5 | 1(Win) |
| glaze | 5700.63 | 2.24061 | 6.27924ms | 136046 | 30 | 7.80152e+06 | 22759.5 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 710.907 | 2.11307 | 733.19ms | 2090234 | 30 | 1.05321e+11 | 2.80403e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 706.367 | 2.29351 | 721.033ms | 2090234 | 30 | 1.25675e+11 | 2.82205e+06 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 692.833 | 1.85915 | 1772.72ms | 2090234 | 32 | 9.15614e+10 | 2.87718e+06 | 1(Tie) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1501.16 | 2.35227 | 371.401ms | 2090234 | 30 | 2.92707e+10 | 1.32791e+06 | 1(Win) |
| glaze | 1374.88 | 1.69824 | 1900.98ms | 2090234 | 64 | 3.88005e+10 | 1.44987e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2021.56 | 1.82473 | 885.304ms | 6885124 | 30 | 1.05382e+11 | 3.24807e+06 | 1(Win) |
| jsonifier **STATISTICAL TIE** | 1820.46 | 1.97494 | 921.285ms | 6885124 | 30 | 1.52227e+11 | 3.60687e+06 | 2(Tie) |
| glaze **STATISTICAL TIE** | 1787.53 | 1.81818 | 942.884ms | 6885124 | 30 | 1.33817e+11 | 3.67332e+06 | 2(Tie) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2657.57 | 2.49173 | 1482.02ms | 6661897 | 32 | 1.13548e+11 | 2.39063e+06 | 1(Win) |
| jsonifier | 2373.71 | 2.3727 | 694.044ms | 6661897 | 30 | 1.2099e+11 | 2.67652e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2058.78 | 0.383436 | 60.283ms | 500299 | 30 | 2.36891e+07 | 231750 | 1(Win) |
| jsonifier | 1722.23 | 0.677782 | 73.4104ms | 500299 | 30 | 1.05774e+08 | 277037 | 2(Loss) |
| simdjson | 1138.27 | 2.28128 | 560.649ms | 500299 | 64 | 5.85196e+09 | 419163 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 5713.68 | 0.930431 | 22.3158ms | 500299 | 30 | 1.811e+07 | 83505.3 | 1(Win) |
| jsonifier | 5351.21 | 1.52676 | 22.4948ms | 500299 | 30 | 5.55931e+07 | 89161.6 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 3066.06 | 1.6774 | 616.411ms | 1490030 | 64 | 3.86798e+09 | 463463 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2958.19 | 0.818678 | 328.237ms | 1490030 | 32 | 4.94896e+08 | 480363 | 1(Tie) |
| jsonifier | 2377.32 | 1.54341 | 353.782ms | 1490030 | 32 | 2.72349e+09 | 597733 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7403.63 | 0.638292 | 48.0725ms | 1439562 | 30 | 4.20273e+07 | 185433 | 1(Win) |
| glaze | 5028.87 | 0.702473 | 121.507ms | 1439584 | 30 | 1.10335e+08 | 273003 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2117.85 | 0.76451 | 17.1108ms | 56369 | 32 | 1.20505e+06 | 25383.1 | 1(Win) |
| glaze | 2015.89 | 1.32393 | 7.2303ms | 56369 | 30 | 3.73938e+06 | 26667 | 2(Loss) |
| simdjson | 1376.75 | 0.90008 | 10.2199ms | 56369 | 30 | 3.70557e+06 | 39046.8 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 7064.36 | 0.128454 | 2.25324ms | 56369 | 30 | 2866.49 | 7609.7 | 1(Win) |
| jsonifier | 5830.42 | 0.0923627 | 2.74484ms | 56369 | 30 | 2175.68 | 9220.2 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 2528.08 | 1.06673 | 11.1883ms | 98048 | 30 | 4.67012e+06 | 36986.9 | 1(Win) |
| simdjson | 2206.72 | 0.658491 | 102.145ms | 98048 | 64 | 4.98268e+06 | 42373.2 | 2(Loss) |
| jsonifier | 1818.49 | 1.22011 | 15.6224ms | 98048 | 30 | 1.1808e+07 | 51419.6 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6959.4 | 0.0511062 | 3.7364ms | 94370 | 30 | 1310.37 | 12931.9 | 1(Win) |
| glaze | 5116.09 | 0.655947 | 5.40809ms | 94370 | 30 | 399439 | 17591.2 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1922.67 | 1.13193 | 9.60118ms | 52708 | 30 | 2.62729e+06 | 26144 | 1(Win) |
| simdjson | 1727.59 | 0.345194 | 18.8247ms | 52708 | 32 | 322809 | 29096.1 | 2(Loss) |
| glaze | 1420.38 | 1.42477 | 25.795ms | 52708 | 32 | 8.13556e+06 | 35389.4 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 6727.52 | 0.48236 | 2.26711ms | 52708 | 30 | 38967.9 | 7471.73 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 6678.3 | 0.184899 | 2.31394ms | 52708 | 30 | 5810.44 | 7526.8 | 1(Tie) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2174.16 | 1.65057 | 19.4446ms | 71665 | 32 | 8.61486e+06 | 31435.1 | 1(Win) |
| glaze | 1672.31 | 1.5922 | 11.8935ms | 71665 | 30 | 1.27028e+07 | 40868.7 | 2(Loss) |
| jsonifier | 1362.42 | 1.99595 | 16.9666ms | 71665 | 30 | 3.00756e+07 | 50164.6 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6541.22 | 1.85953 | 2.91826ms | 70103 | 30 | 1.08363e+06 | 10220.6 | 1(Win) |
| glaze | 5974.07 | 0.886302 | 3.17112ms | 70103 | 30 | 295132 | 11190.9 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1609.85 | 0.181376 | 4.92912ms | 11812 | 32 | 5154.51 | 6997.44 | 1(Win) |
| glaze | 1476.54 | 0.101925 | 2.29678ms | 11812 | 30 | 1814.03 | 7629.2 | 2(Loss) |
| simdjson | 1147.48 | 0.134677 | 2.77164ms | 11812 | 30 | 5244.07 | 9817 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6201.26 | 0.0825742 | 0.827581ms | 11812 | 30 | 67.4989 | 1816.53 | 1(Win) |
| glaze | 5006.21 | 0.189857 | 0.853052ms | 11812 | 30 | 547.523 | 2250.17 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2786.25 | 0.0833213 | 3.05623ms | 32403 | 30 | 2561.91 | 11090.9 | 1(Win) |
| jsonifier | 2624.95 | 0.152164 | 3.40666ms | 32403 | 30 | 9626.59 | 11772.4 | 2(Loss) |
| glaze | 2468.16 | 0.319584 | 3.4626ms | 32403 | 30 | 48030.3 | 12520.2 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7704.57 | 0.106315 | 2.82208ms | 31235 | 32 | 540.66 | 3866.28 | 1(Win) |
| glaze | 6815.6 | 0.174157 | 3.93954ms | 31235 | 32 | 1854 | 4370.56 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3070.14 | 1.00409 | 9.84337ms | 108313 | 30 | 3.42381e+06 | 33645.1 | 1(Win) |
| glaze | 2017.75 | 1.73201 | 12.7739ms | 108313 | 30 | 2.35859e+07 | 51193.4 | 2(Loss) |
| simdjson | 1588.39 | 1.63144 | 16.0433ms | 108313 | 30 | 3.37687e+07 | 65031.6 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6206.84 | 0.713399 | 11.5614ms | 108313 | 32 | 451062 | 16642.2 | 1(Win) |
| glaze | 5810.9 | 1.22886 | 6.05582ms | 108313 | 30 | 1.43152e+06 | 17776.1 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 3071.09 | 1.23548 | 17.3451ms | 222373 | 30 | 2.18359e+07 | 69054.1 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3064.06 | 0.835012 | 18.5072ms | 222373 | 30 | 1.00202e+07 | 69212.6 | 1(Tie) |
| jsonifier | 1989.7 | 0.855292 | 28.8434ms | 222373 | 30 | 2.4931e+07 | 106585 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8075.73 | 0.0976491 | 6.61312ms | 213963 | 30 | 18263 | 25267.2 | 1(Win) |
| glaze | 5554.28 | 1.73798 | 44.4461ms | 213963 | 64 | 2.60909e+07 | 36737.6 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 637.835 | 2.22437 | 661.859ms | 1834197 | 30 | 1.11638e+11 | 2.74244e+06 | 1(Tie) |
| glaze **STATISTICAL TIE** | 625.426 | 1.33953 | 3564.86ms | 1834197 | 64 | 8.98313e+10 | 2.79686e+06 | 1(Tie) |
| simdjson | 564.65 | 1.92847 | 1847.96ms | 1834197 | 32 | 1.14212e+11 | 3.0979e+06 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1013.19 | 2.28797 | 417.876ms | 1834197 | 30 | 4.68092e+10 | 1.72645e+06 | 1(Win) |
| glaze | 919.603 | 2.47305 | 462.414ms | 1833577 | 30 | 6.63416e+10 | 1.90151e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 2549.15 | 2.11449 | 1016.43ms | 10252236 | 30 | 1.97323e+11 | 3.8355e+06 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2444.75 | 2.3169 | 1052.84ms | 10252236 | 30 | 2.57576e+11 | 3.9993e+06 | 1(Tie) |
| jsonifier | 2107.18 | 2.08061 | 1170.06ms | 10252236 | 30 | 2.796e+11 | 4.64e+06 | 3(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1326.84 | 2.29529 | 604.059ms | 642697 | 64 | 7.19502e+09 | 461943 | 1(Win) |
| simdjson **STATISTICAL TIE** | 1134.44 | 0.400423 | 138.925ms | 642697 | 30 | 1.40415e+08 | 540290 | 2(Tie) |
| glaze **STATISTICAL TIE** | 1132.42 | 1.53409 | 719.015ms | 642697 | 64 | 4.41245e+09 | 541252 | 2(Tie) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1740.18 | 0.741152 | 138.941ms | 642697 | 30 | 2.04438e+08 | 352219 | 1(Win) |
| glaze | 1566.24 | 0.466702 | 101.88ms | 642692 | 30 | 1.00067e+08 | 391332 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 2055.84 | 2.33326 | 781.566ms | 1306201 | 64 | 1.27923e+10 | 605928 | 1(Tie) |
| glaze **STATISTICAL TIE** | 2040.92 | 2.36204 | 395.004ms | 1306201 | 32 | 6.65112e+09 | 610359 | 1(Tie) |
| jsonifier | 1887.8 | 1.74998 | 1729.51ms | 1306201 | 128 | 1.70681e+10 | 659865 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2680.23 | 0.404024 | 309.698ms | 1225964 | 32 | 9.93974e+07 | 436220 | 1(Win) |
| glaze | 2372.79 | 0.650296 | 125.742ms | 1225970 | 30 | 3.08024e+08 | 492743 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1506.11 | 0.537223 | 119.836ms | 409725 | 30 | 5.82774e+07 | 259439 | 1(Win) |
| simdjson | 1037.5 | 1.74513 | 510.392ms | 409725 | 64 | 2.76465e+09 | 376620 | 2(Loss) |
| glaze | 960.286 | 0.533512 | 102.246ms | 409725 | 30 | 1.41382e+08 | 406904 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3873.67 | 1.10453 | 26.9273ms | 409725 | 30 | 3.72409e+07 | 100872 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3823.02 | 1.25909 | 26.7802ms | 409725 | 30 | 4.96831e+07 | 102208 | 1(Tie) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1950.68 | 0.574779 | 231.346ms | 814756 | 32 | 1.67739e+08 | 398328 | 1(Win) |
| glaze | 1601.32 | 0.601763 | 281.525ms | 814756 | 32 | 2.72835e+08 | 485232 | 2(Loss) |
| jsonifier | 1484.36 | 1.93734 | 693.748ms | 814756 | 64 | 6.58219e+09 | 523467 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 4633.82 | 1.02007 | 42.5736ms | 785750 | 30 | 8.16341e+07 | 161713 | 1(Win) |
| glaze | 4324.82 | 0.913675 | 102.562ms | 785750 | 32 | 8.01985e+07 | 173267 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6058.84 | 0.770747 | 26.2848ms | 264040 | 32 | 3.28348e+06 | 41560.4 | 1(Win) |
| simdjson | 5340.57 | 0.812754 | 12.1678ms | 264040 | 30 | 4.40559e+06 | 47150.1 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7705.21 | 0.756485 | 12.6687ms | 399947 | 30 | 4.20686e+06 | 49501.4 | 1(Win) |
| simdjson | 7199.1 | 1.13772 | 13.2672ms | 399947 | 30 | 1.09004e+07 | 52981.5 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2125.79 | 1.50397 | 38.0211ms | 264040 | 30 | 9.52134e+07 | 118454 | 1(Win) |
| glaze | 1916.12 | 0.963563 | 34.0919ms | 264040 | 30 | 4.81034e+07 | 131416 | 2(Loss) |
| simdjson | 1810.75 | 0.995081 | 36.1137ms | 264040 | 30 | 5.7446e+07 | 139063 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 6323.07 | 1.46075 | 10.5701ms | 263923 | 30 | 1.01432e+07 | 39806.1 | 1(Win) |
| jsonifier | 5654.73 | 1.84354 | 13.3993ms | 264040 | 30 | 2.02183e+07 | 44530.6 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2674.74 | 0.591486 | 38.7079ms | 409612 | 30 | 2.23868e+07 | 146047 | 1(Win) |
| glaze | 2306.84 | 0.854752 | 95.7529ms | 409612 | 30 | 6.28509e+07 | 169338 | 2(Loss) |
| jsonifier | 1298.84 | 2.31302 | 818.329ms | 409612 | 128 | 6.19444e+09 | 300758 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 6173.47 | 0.805094 | 17.4554ms | 399830 | 30 | 7.41833e+06 | 61765.5 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 6077.28 | 1.6104 | 16.7661ms | 399947 | 30 | 3.0646e+07 | 62761.5 | 1(Tie) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2607.96 | 0.815167 | 102.109ms | 466906 | 32 | 6.19868e+07 | 170737 | 1(Win) |
| glaze | 2477.97 | 0.526451 | 150.062ms | 466906 | 32 | 2.86374e+07 | 179694 | 2(Loss) |
| simdjson | 1359.53 | 0.895141 | 193.511ms | 466906 | 32 | 2.75053e+08 | 327523 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Linux-GCC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 3834.18 | 1.00515 | 44.8682ms | 699405 | 30 | 9.17273e+07 | 173963 | 1(Tie) |
| glaze **STATISTICAL TIE** | 3783.09 | 0.69914 | 44.6027ms | 699405 | 30 | 4.55841e+07 | 176312 | 1(Tie) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Linux-GCC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3999.5 | 1.54495 | 230.774ms | 631514 | 64 | 3.4639e+08 | 150583 | 1(Win) |
| glaze | 3349.66 | 0.576903 | 45.6534ms | 631514 | 30 | 3.2277e+07 | 179797 | 2(Loss) |
