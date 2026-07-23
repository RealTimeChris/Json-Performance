# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.17.0-1020-azure using the GCC 16.0.1 compiler).  

Latest Results: (Jul 23, 2026)
#### Using the following commits:
----
| Jsonifier: [eadd324](https://github.com/RealTimeChris/Jsonifier/commit/eadd324)  
| Glaze: [2dfb355](https://github.com/stephenberry/glaze/commit/2dfb355)  
| Simdjson: [8e6bac9](https://github.com/simdjson/simdjson/commit/8e6bac9)  

> Adaptive sampling on (INTEL(R) XEON(R) PLATINUM 8573C-AVX512): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

##### (None of the libraries are performing UTF8-validation in these tests. Jsonifier is only performing "structural indexing/stage-1 + stage-2" parsing for the 'partial' tests here, for the rest of them? We perform scalar iteration)

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./json/Double%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 876.213 | 0.0845557 | 2.24422ms | 1811 | 30 | 83.3345 | 1971.1 | 2.45084 | 1(Win) |
| glaze | 589.033 | 0.218321 | 1.16066ms | 1811 | 30 | 1229.33 | 2932.1 | 3.67057 | 2(Loss) |
| simdjson | 170.715 | 0.10543 | 2.96776ms | 1811 | 30 | 3413.06 | 10116.9 | 12.8014 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./json/Double%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 522.742 | 0.16161 | 1.6196ms | 1811 | 30 | 855.306 | 3303.93 | 4.13381 | 1(Win) |
| glaze | 292.501 | 0.228692 | 2.65673ms | 1798 | 30 | 5391.98 | 5862.23 | 7.41339 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./json/Uint64%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1415.38 | 0.153485 | 1.43264ms | 3873 | 30 | 481.283 | 2609.6 | 1.52767 | 1(Win) |
| glaze | 1314.54 | 0.096096 | 1.83294ms | 3873 | 30 | 218.717 | 2809.8 | 1.64362 | 2(Loss) |
| simdjson | 328.304 | 0.0779109 | 3.24027ms | 3873 | 30 | 2304.95 | 11250.5 | 6.65975 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./json/Uint64%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2026.4 | 0.0746761 | 1.21658ms | 3873 | 30 | 55.5816 | 1822.73 | 1.0641 | 1(Win) |
| glaze | 929.413 | 0.114076 | 2.15668ms | 3873 | 30 | 616.576 | 3974.1 | 2.33394 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./json/Int64%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1471.45 | 0.0490422 | 1.33833ms | 3862 | 30 | 45.2057 | 2503.03 | 1.46756 | 1(Win) |
| glaze | 1218.76 | 0.0466896 | 1.96782ms | 3862 | 30 | 59.7241 | 3022 | 1.78134 | 2(Loss) |
| simdjson | 321.929 | 0.0415554 | 3.25609ms | 3862 | 30 | 678.079 | 11440.7 | 6.79016 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./json/Int64%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1986.96 | 0.135655 | 1.19467ms | 3862 | 30 | 189.689 | 1853.63 | 1.07435 | 1(Win) |
| glaze | 910.162 | 0.176281 | 2.14185ms | 3862 | 30 | 1526.59 | 4046.63 | 2.38828 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./json/Bool%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1313.79 | 0.826826 | 0.927087ms | 905 | 30 | 885.099 | 656.933 | 1.5958 | 1(Win) |
| glaze | 469.905 | 0.0367463 | 1.5841ms | 905 | 30 | 13.6655 | 1836.7 | 4.52832 | 2(Loss) |
| simdjson | 134.023 | 0.127649 | 2.02027ms | 905 | 30 | 2027.17 | 6439.73 | 16.2768 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./json/Bool%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 821.742 | 0.672951 | 1.01487ms | 905 | 30 | 1498.7 | 1050.3 | 2.59337 | 1(Win) |
| glaze | 241.139 | 0.148689 | 2.06709ms | 905 | 30 | 849.661 | 3579.17 | 9.01208 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./json/String%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2939.71 | 0.29529 | 1.47043ms | 8813 | 30 | 2138.24 | 2859.03 | 0.732925 | 1(Win) |
| glaze | 1592.92 | 0.234629 | 1.78416ms | 8813 | 30 | 4597.73 | 5276.3 | 1.36614 | 2(Loss) |
| simdjson | 736.779 | 0.0988402 | 3.23786ms | 8813 | 30 | 3813.83 | 11407.4 | 2.96174 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./json/String%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2978.61 | 0.341502 | 1.70659ms | 8813 | 30 | 2785.67 | 2821.7 | 0.724059 | 1(Win) |
| glaze | 1771.9 | 1.87833 | 1.62858ms | 8813 | 30 | 238139 | 4743.33 | 1.22446 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 4362.82 | 0.127929 | 2.31284ms | 33713 | 30 | 2666.38 | 7369.37 | 0.500327 | 1(Win) |
| jsonifier | 3840.86 | 0.0942252 | 2.55916ms | 33713 | 30 | 1866.35 | 8370.83 | 0.568479 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 5324.55 | 0.149507 | 5.46097ms | 48024 | 32 | 5292.06 | 8601.53 | 0.410248 | 1(Win) |
| jsonifier | 4591.16 | 0.304408 | 2.94595ms | 48024 | 30 | 27663.4 | 9975.53 | 0.475879 | 2(Loss) |

----
### Abc (In Order) Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1799.53 | 1.06855 | 4.86653ms | 33713 | 30 | 1.09341e+06 | 17866.5 | 1.2166 | 1(Win) |
| glaze | 1687.91 | 0.275412 | 5.28449ms | 33713 | 30 | 82562.4 | 19047.9 | 1.29729 | 2(Loss) |
| simdjson | 1305.23 | 0.927728 | 6.58808ms | 33713 | 30 | 1.5667e+06 | 24632.7 | 1.6781 | 3(Loss) |

----
### Abc (In Order) Test (Minified) Write Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3545.95 | 0.0636963 | 2.7156ms | 33689 | 30 | 999.22 | 9060.57 | 0.61616 | 1(Win) |
| jsonifier | 3075.68 | 0.282142 | 6.60851ms | 33713 | 32 | 27835.4 | 10453.4 | 0.710166 | 2(Loss) |

----
### Abc (In Order) Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1983.37 | 0.95132 | 6.24916ms | 48024 | 30 | 1.44772e+06 | 23091.7 | 1.10417 | 1(Win) |
| glaze | 1901.86 | 1.35088 | 6.52032ms | 48024 | 30 | 3.17479e+06 | 24081.3 | 1.15164 | 2(Loss) |
| simdjson | 1774.08 | 1.36931 | 6.81547ms | 48024 | 30 | 3.74884e+06 | 25815.8 | 1.23463 | 3(Loss) |

----
### Abc (In Order) Test (Prettified) Write Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3341.13 | 0.0873792 | 3.84909ms | 48024 | 30 | 4303.94 | 13707.7 | 0.651907 | 1(Win) |
| glaze | 3002.73 | 1.25624 | 9.20055ms | 48000 | 32 | 1.17366e+06 | 15244.9 | 0.728094 | 2(Loss) |

----
### Abc (Out of Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3859.92 | 0.0861676 | 5.41031ms | 33713 | 32 | 1648.45 | 8329.5 | 0.565885 | 1(Win) |
| simdjson | 2467.63 | 1.52883 | 3.64316ms | 33713 | 30 | 1.19034e+06 | 13029.2 | 0.886426 | 2(Loss) |

----
### Abc (Out of Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4679.18 | 0.121112 | 6.21555ms | 48024 | 32 | 4496.76 | 9787.88 | 0.467026 | 1(Win) |
| simdjson | 3293.43 | 0.063047 | 4.00189ms | 48024 | 30 | 2306.06 | 13906.3 | 0.664426 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1616.62 | 1.05053 | 5.38418ms | 33713 | 30 | 1.30954e+06 | 19887.9 | 1.35435 | 1(Win) |
| jsonifier | 1224.08 | 0.840315 | 6.8898ms | 33713 | 30 | 1.46145e+06 | 26265.7 | 1.78943 | 2(Loss) |
| simdjson | 227.063 | 0.262156 | 34.7497ms | 33713 | 30 | 4.13371e+06 | 141596 | 9.65701 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3451.89 | 1.913 | 5.93137ms | 33689 | 32 | 1.01448e+06 | 9307.47 | 0.632898 | 1(Win) |
| jsonifier | 3100.03 | 0.101091 | 3.11017ms | 33713 | 30 | 3297.72 | 10371.3 | 0.703562 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1868.05 | 0.797257 | 6.67703ms | 48024 | 30 | 1.14619e+06 | 24517.1 | 1.17241 | 1(Win) |
| jsonifier | 1373.56 | 0.649208 | 8.84914ms | 48024 | 30 | 1.40576e+06 | 33343.5 | 1.5953 | 2(Loss) |
| simdjson | 317.125 | 0.280842 | 35.309ms | 48024 | 30 | 4.93515e+06 | 144420 | 6.91455 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3466.34 | 0.0907361 | 3.74341ms | 48024 | 30 | 4311.77 | 13212.6 | 0.628076 | 1(Win) |
| glaze | 2883.72 | 1.23516 | 4.31585ms | 48000 | 30 | 1.15331e+06 | 15874.1 | 0.758724 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 876.337 | 0.422024 | 25.439ms | 94651 | 30 | 5.66897e+06 | 103004 | 2.50185 | 1(Win) |
| simdjson | 803.154 | 0.342069 | 27.898ms | 94651 | 30 | 4.43406e+06 | 112390 | 2.72996 | 2(Loss) |
| glaze | 783.905 | 0.530317 | 28.6472ms | 94651 | 30 | 1.11871e+07 | 115150 | 2.79684 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 4093.05 | 0.0331067 | 6.03943ms | 94651 | 30 | 1599.22 | 22053.5 | 0.534843 | 1(Win) |
| jsonifier | 3848.09 | 0.944126 | 6.18949ms | 94651 | 30 | 1.47144e+06 | 23457.4 | 0.567708 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1183.46 | 0.361263 | 28.0524ms | 140436 | 30 | 5.01435e+06 | 113168 | 1.85271 | 1(Win) |
| glaze STATISTICAL TIE | 988.799 | 0.348126 | 33.4442ms | 140436 | 30 | 6.67017e+06 | 135447 | 2.21756 | 2(Tie) |
| jsonifier STATISTICAL TIE | 984.044 | 0.318223 | 33.3872ms | 140436 | 30 | 5.62746e+06 | 136102 | 2.22822 | 2(Tie) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4746.7 | 1.14269 | 7.18846ms | 136024 | 30 | 2.9257e+06 | 27329 | 0.46036 | 1(Win) |
| glaze | 4001.2 | 0.941352 | 8.37829ms | 136046 | 30 | 2.79522e+06 | 32426.1 | 0.547399 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json/Canada%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 524.416 | 0.138116 | 913.98ms | 2090234 | 30 | 8.26893e+08 | 3.80119e+06 | 4.18244 | 1(Win) |
| glaze | 443.932 | 0.149265 | 1079.37ms | 2090234 | 30 | 1.3477e+09 | 4.49033e+06 | 4.94079 | 2(Loss) |
| simdjson | 430.022 | 0.172696 | 1111.14ms | 2090234 | 30 | 1.92264e+09 | 4.63559e+06 | 5.10059 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./json/Canada%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1083.92 | 0.191776 | 442.72ms | 2090234 | 30 | 3.73169e+08 | 1.83907e+06 | 2.02322 | 1(Win) |
| glaze | 957.488 | 0.105749 | 502.686ms | 2090234 | 30 | 1.4541e+08 | 2.08191e+06 | 2.29055 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson STATISTICAL TIE | 1294.83 | 0.46756 | 1212.06ms | 6885124 | 30 | 1.68655e+10 | 5.07108e+06 | 1.69395 | 1(Tie) |
| jsonifier STATISTICAL TIE | 1282.57 | 0.116772 | 1227.3ms | 6885124 | 30 | 1.07217e+09 | 5.11955e+06 | 1.71016 | 1(Tie) |
| glaze | 1123.54 | 0.0743323 | 1397.7ms | 6885124 | 30 | 5.66143e+08 | 5.8442e+06 | 1.95222 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./json/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2091.14 | 0.144143 | 731.44ms | 6661897 | 30 | 5.75357e+08 | 3.03819e+06 | 1.04884 | 1(Win) |
| glaze | 1945.96 | 0.0529426 | 786.903ms | 6661897 | 30 | 8.96316e+07 | 3.26486e+06 | 1.12709 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1203.42 | 0.171502 | 95.8186ms | 500299 | 30 | 1.38703e+07 | 396472 | 1.82251 | 1(Win) |
| jsonifier | 1129.95 | 0.143136 | 102.036ms | 500299 | 30 | 1.09588e+07 | 422253 | 1.9412 | 2(Loss) |
| simdjson | 842.539 | 0.221133 | 137.041ms | 500299 | 30 | 4.70442e+07 | 566291 | 2.60311 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3289.68 | 1.5597 | 86.4153ms | 500299 | 32 | 1.63751e+08 | 145036 | 0.666442 | 1(Win) |
| jsonifier | 3126.25 | 1.61245 | 37.4925ms | 500299 | 30 | 1.8168e+08 | 152618 | 0.70126 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 2139.35 | 0.198706 | 160.837ms | 1490030 | 30 | 5.22599e+07 | 664221 | 1.025 | 1(Win) |
| jsonifier | 2100.16 | 0.215922 | 163.952ms | 1490030 | 30 | 6.40324e+07 | 676616 | 1.0442 | 2(Loss) |
| glaze | 1882.12 | 0.295669 | 181.707ms | 1490030 | 30 | 1.49496e+08 | 755002 | 1.16511 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4274.63 | 0.597421 | 77.7832ms | 1439562 | 30 | 1.10445e+08 | 321168 | 0.512806 | 1(Win) |
| glaze | 3055.53 | 0.5033 | 108.507ms | 1439584 | 30 | 1.53418e+08 | 449314 | 0.717545 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1472.94 | 0.55455 | 9.50882ms | 56369 | 30 | 1.22889e+06 | 36496.9 | 1.48757 | 1(Win) |
| glaze | 1083.09 | 0.704218 | 12.5664ms | 56369 | 30 | 3.66514e+06 | 49633.8 | 2.02372 | 2(Loss) |
| simdjson | 888.156 | 0.586516 | 14.9752ms | 56369 | 30 | 3.78079e+06 | 60527.3 | 2.468 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./json/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 4151.76 | 0.417261 | 3.6507ms | 56369 | 30 | 87569.6 | 12948.2 | 0.526741 | 1(Win) |
| jsonifier | 3414 | 0.0673735 | 4.44178ms | 56369 | 30 | 3376.39 | 15746.2 | 0.639897 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier STATISTICAL TIE | 1544.03 | 1.01133 | 15.2653ms | 98048 | 30 | 1.12531e+07 | 60559.6 | 1.41961 | 1(Tie) |
| glaze STATISTICAL TIE | 1526.42 | 0.463405 | 15.4633ms | 98048 | 30 | 2.41753e+06 | 61258.3 | 1.43614 | 1(Tie) |
| simdjson | 1494.37 | 0.437995 | 15.9116ms | 98048 | 30 | 2.25331e+06 | 62572.1 | 1.46681 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./json/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4271.6 | 0.0734485 | 5.71323ms | 94370 | 30 | 7184.14 | 21069 | 0.512231 | 1(Win) |
| glaze | 4009.72 | 0.11355 | 6.07591ms | 94370 | 30 | 19486.7 | 22445 | 0.545895 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1277.22 | 0.546646 | 10.76ms | 52708 | 30 | 1.38852e+06 | 39355.9 | 1.71513 | 1(Win) |
| simdjson | 1144.82 | 0.714874 | 11.2343ms | 52708 | 30 | 2.95571e+06 | 43907.7 | 1.91391 | 2(Loss) |
| glaze | 910.609 | 0.80062 | 14.2723ms | 52708 | 30 | 5.85955e+06 | 55200.7 | 2.40656 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 4956.05 | 0.237327 | 3.22392ms | 52708 | 30 | 17381.8 | 10142.4 | 0.440518 | 1(Win) |
| jsonifier | 3601.44 | 0.252907 | 3.77872ms | 52708 | 30 | 37380.3 | 13957.3 | 0.60448 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1551.46 | 0.599025 | 11.5655ms | 71665 | 30 | 2.08902e+06 | 44052 | 1.41251 | 1(Win) |
| glaze | 1019.11 | 1.65511 | 16.4885ms | 71665 | 30 | 3.69611e+07 | 67063.5 | 2.15058 | 2(Loss) |
| jsonifier | 963.931 | 1.10177 | 17.3407ms | 71665 | 30 | 1.83073e+07 | 70902.4 | 2.27329 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4460.51 | 0.197642 | 4.31556ms | 70103 | 30 | 26326.1 | 14988.3 | 0.489829 | 1(Win) |
| glaze | 3961.15 | 0.704337 | 4.71822ms | 70103 | 30 | 423949 | 16877.8 | 0.552289 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1010.22 | 0.193876 | 3.28551ms | 11812 | 30 | 14021.3 | 11150.9 | 2.16534 | 1(Win) |
| glaze | 885.08 | 0.389881 | 3.70038ms | 11812 | 30 | 73869.9 | 12727.4 | 2.47161 | 2(Loss) |
| simdjson | 757.199 | 1.33594 | 4.09481ms | 11812 | 30 | 1.18502e+06 | 14876.9 | 2.88976 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3629.32 | 0.677834 | 1.23457ms | 11812 | 30 | 13279 | 3103.83 | 0.593594 | 1(Win) |
| glaze | 2789.35 | 0.450463 | 1.46876ms | 11812 | 30 | 9928.4 | 4038.5 | 0.778101 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2026.77 | 1.62434 | 4.22662ms | 32403 | 30 | 1.84009e+06 | 15246.9 | 1.07981 | 1(Win) |
| simdjson | 1858.77 | 1.10865 | 4.47063ms | 32403 | 30 | 1.01914e+06 | 16624.9 | 1.17747 | 2(Loss) |
| glaze | 1490.92 | 0.179996 | 5.63779ms | 32403 | 30 | 41754.7 | 20726.7 | 1.46886 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 5262.09 | 0.257872 | 1.86182ms | 31235 | 30 | 6392.88 | 5660.87 | 0.410503 | 1(Win) |
| glaze | 4695.51 | 0.269448 | 2.0174ms | 31235 | 30 | 8765.72 | 6343.93 | 0.46415 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2223.09 | 0.455662 | 11.9423ms | 108313 | 30 | 1.34479e+06 | 46464.8 | 0.985931 | 1(Win) |
| glaze | 1445.6 | 0.469028 | 17.6877ms | 108313 | 30 | 3.36965e+06 | 71455.2 | 1.51626 | 2(Loss) |
| simdjson | 1149.84 | 0.725781 | 22.1473ms | 108313 | 30 | 1.27532e+07 | 89834.5 | 1.90663 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3064.23 | 1.08574 | 8.82393ms | 108313 | 30 | 4.01876e+06 | 33710 | 0.714654 | 1(Win) |
| jsonifier | 2538.78 | 0.829662 | 9.68773ms | 108313 | 30 | 3.41849e+06 | 40687 | 0.861897 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 2193.56 | 0.405947 | 23.8446ms | 222373 | 30 | 4.62086e+06 | 96678.9 | 0.999517 | 1(Win) |
| glaze STATISTICAL TIE | 1983.71 | 0.381085 | 26.4102ms | 222373 | 30 | 4.97935e+06 | 106907 | 1.10536 | 2(Tie) |
| jsonifier STATISTICAL TIE | 1976.93 | 0.293947 | 26.7283ms | 222373 | 30 | 2.98293e+06 | 107273 | 1.10914 | 2(Tie) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4114.68 | 0.494722 | 10.7449ms | 213963 | 30 | 1.80571e+06 | 49591 | 0.53267 | 1(Win) |
| glaze | 3498.78 | 1.28202 | 14.7156ms | 213963 | 30 | 1.67707e+07 | 58320.6 | 0.626425 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 555.923 | 0.162538 | 754.275ms | 1834197 | 30 | 7.84679e+08 | 3.14652e+06 | 3.94542 | 1(Win) |
| simdjson | 385.766 | 0.178135 | 1088.75ms | 1834197 | 30 | 1.95732e+09 | 4.53442e+06 | 5.68585 | 2(Loss) |
| glaze | 382.843 | 0.132591 | 1097.44ms | 1834197 | 30 | 1.10103e+09 | 4.56904e+06 | 5.72929 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 691.631 | 0.303187 | 611.239ms | 1834197 | 30 | 1.76395e+09 | 2.52913e+06 | 3.17107 | 1(Win) |
| glaze | 640.22 | 0.574916 | 654.65ms | 1833577 | 30 | 7.39726e+09 | 2.73131e+06 | 3.42585 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1898.78 | 0.0977569 | 1240.07ms | 10252236 | 30 | 7.60159e+08 | 5.14926e+06 | 1.15516 | 1(Win) |
| glaze | 1666.15 | 0.0915335 | 1410.78ms | 10252236 | 30 | 8.65551e+08 | 5.86821e+06 | 1.31648 | 2(Loss) |
| jsonifier | 1565.87 | 0.0648878 | 1502.09ms | 10252236 | 30 | 4.92462e+08 | 6.244e+06 | 1.40074 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1925.38 | 0.0954935 | 1183.09ms | 9930848 | 30 | 6.61922e+08 | 4.91891e+06 | 1.13919 | 1(Win) |
| glaze | 1744.02 | 0.260594 | 1306.32ms | 9930228 | 30 | 6.00712e+09 | 5.43011e+06 | 1.25767 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 948.615 | 0.435067 | 155.357ms | 642697 | 30 | 2.37064e+08 | 646125 | 2.31178 | 1(Win) |
| glaze | 716.843 | 0.158947 | 206.535ms | 642697 | 30 | 5.541e+07 | 855032 | 3.05928 | 2(Loss) |
| simdjson | 703.235 | 0.255106 | 209.945ms | 642697 | 30 | 1.48311e+08 | 871577 | 3.11821 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1148.03 | 0.824235 | 128.871ms | 642697 | 30 | 5.80941e+08 | 533893 | 1.90997 | 1(Win) |
| glaze | 920.36 | 0.479083 | 159.148ms | 642692 | 30 | 3.05374e+08 | 665955 | 2.38243 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1354.6 | 0.23106 | 221.4ms | 1306201 | 30 | 1.35447e+08 | 919598 | 1.6188 | 1(Win) |
| glaze | 1295.72 | 0.200878 | 228.619ms | 1306201 | 30 | 1.11888e+08 | 961391 | 1.69242 | 2(Loss) |
| jsonifier | 1206.34 | 0.135386 | 248.904ms | 1306201 | 30 | 5.86347e+07 | 1.03262e+06 | 1.81783 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1745.85 | 0.133393 | 161.486ms | 1225964 | 30 | 2.39402e+07 | 669685 | 1.25601 | 1(Win) |
| glaze | 1385.87 | 0.418213 | 203.518ms | 1225970 | 30 | 3.73447e+08 | 843639 | 1.58224 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 879.367 | 0.337708 | 107.585ms | 409725 | 30 | 6.75538e+07 | 444347 | 2.49407 | 1(Win) |
| simdjson | 690.196 | 0.234353 | 136.927ms | 409725 | 30 | 5.28082e+07 | 566135 | 3.17735 | 2(Loss) |
| glaze | 571.196 | 0.268173 | 164.905ms | 409725 | 30 | 1.00964e+08 | 684081 | 3.83939 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./json/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze STATISTICAL TIE | 2425.78 | 1.31575 | 41.6587ms | 409725 | 30 | 1.34757e+08 | 161080 | 0.903655 | 1(Tie) |
| jsonifier STATISTICAL TIE | 2303.44 | 2.42409 | 41.8521ms | 409725 | 30 | 5.07286e+08 | 169635 | 0.951788 | 1(Tie) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1295.23 | 0.257587 | 145.104ms | 814756 | 30 | 7.16358e+07 | 599903 | 1.69295 | 1(Win) |
| jsonifier | 1057.14 | 0.121196 | 180.872ms | 814756 | 30 | 2.3806e+07 | 735011 | 2.07446 | 2(Loss) |
| glaze | 919.79 | 0.244997 | 203.456ms | 814756 | 30 | 1.28505e+08 | 844771 | 2.38414 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./json/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2653.8 | 0.344139 | 69.2371ms | 785750 | 30 | 2.83285e+07 | 282369 | 0.826164 | 1(Win) |
| glaze | 2570.14 | 0.946644 | 71.2611ms | 785750 | 30 | 2.28533e+08 | 291559 | 0.852995 | 2(Loss) |

----
### Semanticscholar Corpus Test (Minified) Read Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 950.124 | 0.099579 | 2073.75ms | 8587914 | 30 | 2.21041e+09 | 8.62001e+06 | 2.3086 | 1(Win) |
| simdjson | 869.468 | 0.0761457 | 2269.73ms | 8587914 | 30 | 1.5434e+09 | 9.41963e+06 | 2.52274 | 2(Loss) |
| glaze | 753.144 | 0.119341 | 2615.68ms | 8587914 | 30 | 5.05268e+09 | 1.08745e+07 | 2.91239 | 3(Loss) |

----
### Semanticscholar Corpus Test (Minified) Write Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2633.91 | 0.316971 | 749.757ms | 8563074 | 30 | 2.89747e+09 | 3.10048e+06 | 0.83269 | 1(Win) |
| glaze | 2545.54 | 0.12596 | 777.008ms | 8588126 | 30 | 4.92745e+08 | 3.21749e+06 | 0.861588 | 2(Loss) |

----
### Semanticscholar Corpus Test (Prettified) Read Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 986.964 | 0.320795 | 2316.49ms | 9976912 | 30 | 2.86923e+10 | 9.6404e+06 | 2.22239 | 1(Win) |
| jsonifier | 917.965 | 0.0616458 | 2499.47ms | 9976912 | 30 | 1.22481e+09 | 1.0365e+07 | 2.38947 | 2(Loss) |
| glaze | 808.552 | 0.0915239 | 2822.94ms | 9976912 | 30 | 3.4799e+09 | 1.17676e+07 | 2.71282 | 3(Loss) |

----
### Semanticscholar Corpus Test (Prettified) Write Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2877.13 | 0.173409 | 915.647ms | 11048723 | 30 | 1.20997e+09 | 3.6623e+06 | 0.762295 | 1(Win) |
| glaze | 2545.85 | 0.190043 | 1002.06ms | 11078090 | 30 | 1.86592e+09 | 4.14986e+06 | 0.861506 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 4402.8 | 0.440797 | 14.3755ms | 264040 | 30 | 1.90669e+06 | 57192.8 | 0.497881 | 1(Win) |
| jsonifier | 4065.52 | 0.610444 | 15.5625ms | 264040 | 30 | 4.28866e+06 | 61937.5 | 0.53918 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 5670.69 | 0.470154 | 16.9682ms | 399947 | 30 | 3.00009e+06 | 67261.5 | 0.38659 | 1(Win) |
| jsonifier | 4958.6 | 0.352693 | 19.1364ms | 399947 | 30 | 2.20802e+06 | 76920.8 | 0.442124 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1451.11 | 0.267648 | 43.1526ms | 264040 | 30 | 6.47127e+06 | 173528 | 1.51098 | 1(Win) |
| simdjson | 1210.25 | 0.372931 | 50.1164ms | 264040 | 30 | 1.8062e+07 | 208062 | 1.81183 | 2(Loss) |
| glaze | 1106.27 | 0.313403 | 55.7156ms | 264040 | 30 | 1.52668e+07 | 227620 | 1.98227 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 4358.27 | 0.684167 | 14.631ms | 263923 | 30 | 4.68353e+06 | 57751.5 | 0.502914 | 1(Win) |
| jsonifier | 4072.71 | 0.577841 | 15.9804ms | 264040 | 30 | 3.82923e+06 | 61828.2 | 0.537887 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1901.15 | 0.258218 | 52.4043ms | 409612 | 30 | 8.44509e+06 | 205473 | 1.15344 | 1(Win) |
| glaze | 1375.95 | 0.5277 | 68.9076ms | 409612 | 30 | 6.73338e+07 | 283902 | 1.59381 | 2(Loss) |
| jsonifier | 1186.67 | 0.317534 | 80.5497ms | 409612 | 30 | 3.27782e+07 | 329186 | 1.84802 | 3(Loss) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 4543.39 | 0.894781 | 20.7156ms | 399947 | 30 | 1.69278e+07 | 83950.3 | 0.482344 | 1(Win) |
| glaze | 4043.96 | 0.727149 | 23.8143ms | 399830 | 30 | 1.41028e+07 | 94290.7 | 0.542105 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./json/Minify%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1815.8 | 0.466673 | 59.2571ms | 466906 | 30 | 3.92891e+07 | 245224 | 1.20751 | 1(Win) |
| glaze | 1641.03 | 0.418644 | 65.9462ms | 466906 | 30 | 3.87111e+07 | 271339 | 1.33637 | 2(Loss) |
| simdjson | 976.232 | 0.509645 | 109.808ms | 466906 | 30 | 1.6211e+08 | 456117 | 2.24554 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./json/Prettify%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2594.02 | 0.38316 | 62.3722ms | 699405 | 30 | 2.91201e+07 | 257132 | 0.845045 | 1(Win) |
| glaze | 2458.25 | 0.219812 | 65.8155ms | 699405 | 30 | 1.06716e+07 | 271333 | 0.89215 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./json/Validate%20Test.json):

<p align="left"><a href="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 2286.11 | 0.251425 | 63.8962ms | 631514 | 30 | 1.31617e+07 | 263443 | 0.959312 | 1(Win) |
| jsonifier | 2204.08 | 0.231821 | 66.661ms | 631514 | 30 | 1.20375e+07 | 273247 | 0.994982 | 2(Loss) |
