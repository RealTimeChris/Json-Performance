# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.17.0-1020-azure using the Clang 23.0.0 compiler).  

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

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 739.522 | 0.357379 | 1.9873ms | 1811 | 30 | 2089.84 | 2335.43 | 2.91309 | 1(Win) |
| glaze | 572.445 | 0.0658103 | 1.17064ms | 1811 | 30 | 118.271 | 3017.07 | 3.7795 | 2(Loss) |
| simdjson | 157.018 | 0.407086 | 3.20735ms | 1811 | 30 | 60149.8 | 10999.4 | 13.9096 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./json/Double%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 451.188 | 0.11364 | 1.89407ms | 1811 | 30 | 567.679 | 3827.9 | 4.79076 | 1(Win) |
| glaze | 216.333 | 0.709588 | 5.56189ms | 1798 | 32 | 101226 | 7926.22 | 10.0842 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./json/Uint64%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1245.87 | 0.0454082 | 1.5995ms | 3873 | 30 | 54.3678 | 2964.67 | 1.73454 | 1(Win) |
| glaze | 1149.74 | 0.0490386 | 2.92666ms | 3873 | 32 | 79.4183 | 3212.53 | 1.88197 | 2(Loss) |
| simdjson | 320.123 | 0.0459443 | 3.33235ms | 3873 | 30 | 843.034 | 11538 | 6.83184 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./json/Uint64%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1795.91 | 0.196924 | 1.45967ms | 3873 | 30 | 492.092 | 2056.67 | 1.20108 | 1(Win) |
| glaze | 847.722 | 0.18056 | 2.04447ms | 3873 | 30 | 1856.75 | 4357.07 | 2.56404 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./json/Int64%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1214.43 | 0.0499609 | 1.67336ms | 3862 | 30 | 68.8747 | 3032.77 | 1.77787 | 1(Win) |
| glaze | 1039.81 | 0.0546827 | 1.77977ms | 3862 | 30 | 112.547 | 3542.07 | 2.08037 | 2(Loss) |
| simdjson | 310.273 | 0.0423431 | 7.22976ms | 3862 | 32 | 808.452 | 11870.5 | 7.05049 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./json/Int64%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1727.5 | 0.153574 | 1.44885ms | 3862 | 30 | 321.62 | 2132.03 | 1.23093 | 1(Win) |
| glaze | 842.074 | 0.152085 | 2.05082ms | 3862 | 30 | 1327.45 | 4373.83 | 2.56586 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./json/Bool%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 849.846 | 0.0407999 | 1.18346ms | 905 | 30 | 5.15057 | 1015.57 | 2.50048 | 1(Win) |
| glaze | 631.657 | 0.0787373 | 1.23981ms | 905 | 30 | 34.723 | 1366.37 | 3.38814 | 2(Loss) |
| simdjson | 151.072 | 0.0255638 | 7.59856ms | 905 | 64 | 136.508 | 5713 | 14.4146 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./json/Bool%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 755.295 | 0.0358864 | 1.19564ms | 905 | 30 | 5.04483 | 1142.7 | 2.82018 | 1(Win) |
| glaze | 226.878 | 0.256314 | 1.87185ms | 905 | 30 | 2852.19 | 3804.13 | 9.5639 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./json/String%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2235.3 | 0.0931659 | 1.87014ms | 8813 | 30 | 368.138 | 3760 | 0.969205 | 1(Win) |
| glaze | 1639.17 | 0.0997151 | 3.48398ms | 8813 | 32 | 836.512 | 5127.44 | 1.32551 | 2(Loss) |
| simdjson | 663.914 | 1.69795 | 3.48291ms | 8813 | 30 | 1.3861e+06 | 12659.4 | 3.29309 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./json/String%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2674.51 | 0.0873898 | 1.98124ms | 8813 | 30 | 226.257 | 3142.53 | 0.808276 | 1(Win) |
| glaze | 1663.4 | 0.130971 | 1.75448ms | 8813 | 30 | 1313.79 | 5052.73 | 1.3069 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 4181.08 | 0.0648429 | 2.80748ms | 33713 | 30 | 745.872 | 7689.7 | 0.521935 | 1(Win) |
| jsonifier | 4019.09 | 0.0902355 | 2.49827ms | 33713 | 30 | 1563.21 | 7999.63 | 0.543074 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 4885.72 | 0.0658621 | 3.0116ms | 48024 | 30 | 1143.54 | 9374.1 | 0.446967 | 1(Win) |
| jsonifier | 4655.99 | 0.266103 | 2.90626ms | 48024 | 30 | 20554.8 | 9836.63 | 0.469132 | 2(Loss) |

----
### Abc (In Order) Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1555.02 | 1.20758 | 5.53738ms | 33713 | 30 | 1.87015e+06 | 20675.8 | 1.40777 | 1(Win) |
| glaze | 1453.55 | 1.22573 | 6.03111ms | 33713 | 30 | 2.20518e+06 | 22119.1 | 1.50645 | 2(Loss) |
| simdjson | 898.075 | 0.778232 | 9.56119ms | 33713 | 30 | 2.32868e+06 | 35800.1 | 2.43963 | 3(Loss) |

----
### Abc (In Order) Test (Minified) Write Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 2863.98 | 0.383753 | 7.05143ms | 33689 | 32 | 59304.6 | 11218.1 | 0.762799 | 1(Win) |
| jsonifier | 2802.89 | 0.177016 | 3.29784ms | 33713 | 30 | 12368.9 | 11470.7 | 0.779411 | 2(Loss) |

----
### Abc (In Order) Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze STATISTICAL TIE | 1766.24 | 1.40365 | 7.01351ms | 48024 | 30 | 3.97427e+06 | 25930.3 | 1.24006 | 1(Tie) |
| jsonifier STATISTICAL TIE | 1758.01 | 1.00282 | 6.90128ms | 48024 | 30 | 2.04758e+06 | 26051.7 | 1.24565 | 1(Tie) |
| simdjson | 1143.68 | 0.664787 | 10.2253ms | 48024 | 30 | 2.12616e+06 | 40045.6 | 1.91595 | 3(Loss) |

----
### Abc (In Order) Test (Prettified) Write Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28In%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2997.84 | 1.65343 | 4.20166ms | 48024 | 30 | 1.91424e+06 | 15277.4 | 0.725851 | 1(Win) |
| glaze | 2557.27 | 0.247837 | 4.82017ms | 48000 | 30 | 59045.1 | 17900.5 | 0.854612 | 2(Loss) |

----
### Abc (Out of Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3743.59 | 0.0947705 | 2.55903ms | 33713 | 30 | 1987.4 | 8588.33 | 0.583187 | 1(Win) |
| simdjson | 2373.05 | 1.01624 | 8.00897ms | 33713 | 32 | 606629 | 13548.5 | 0.921538 | 2(Loss) |

----
### Abc (Out of Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 5041.23 | 0.124324 | 2.72646ms | 48024 | 30 | 3827.17 | 9084.93 | 0.433238 | 1(Win) |
| simdjson | 3311.41 | 0.51595 | 3.93195ms | 48024 | 30 | 152766 | 13830.7 | 0.660543 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1333.12 | 0.422778 | 6.30279ms | 33713 | 30 | 311889 | 24117.2 | 1.6427 | 1(Win) |
| jsonifier | 1137.7 | 1.49112 | 7.34161ms | 33713 | 30 | 5.32703e+06 | 28259.8 | 1.9251 | 2(Loss) |
| simdjson | 219.907 | 0.351486 | 35.6602ms | 33713 | 30 | 7.92236e+06 | 146204 | 9.97132 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 2846.86 | 0.0671522 | 7.0953ms | 33689 | 32 | 1837.87 | 11285.5 | 0.767428 | 1(Win) |
| jsonifier | 2810.52 | 0.140301 | 3.31857ms | 33713 | 30 | 7727.97 | 11439.6 | 0.77099 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1645.89 | 0.513312 | 34.7589ms | 48024 | 64 | 1.30574e+06 | 27826.4 | 1.33079 | 1(Win) |
| jsonifier | 1177.63 | 2.08697 | 9.92506ms | 48024 | 30 | 1.97631e+07 | 38891.1 | 1.86054 | 2(Loss) |
| simdjson | 324.927 | 0.529985 | 34.4776ms | 48024 | 30 | 1.67414e+07 | 140952 | 6.74858 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the library parsing methods in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3035.82 | 0.163001 | 4.32567ms | 48024 | 30 | 18141.1 | 15086.3 | 0.720251 | 1(Win) |
| glaze | 2560.46 | 0.27029 | 4.9295ms | 48000 | 30 | 70052.9 | 17878.2 | 0.853976 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 810.153 | 0.419648 | 27.8468ms | 94651 | 30 | 6.55856e+06 | 111419 | 2.70628 | 1(Win) |
| glaze | 651.859 | 0.516383 | 34.2418ms | 94651 | 30 | 1.53394e+07 | 138475 | 3.36361 | 2(Loss) |
| simdjson | 523.938 | 0.372243 | 42.2044ms | 94651 | 30 | 1.23386e+07 | 172284 | 4.18498 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3185.69 | 1.15898 | 7.48818ms | 94651 | 30 | 3.23531e+06 | 28334.9 | 0.687407 | 1(Win) |
| jsonifier | 3012.14 | 1.10332 | 7.67918ms | 94651 | 30 | 3.27962e+06 | 29967.5 | 0.726745 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 947.19 | 0.355027 | 35.0296ms | 140436 | 30 | 7.5601e+06 | 141397 | 2.31486 | 1(Win) |
| glaze | 856.716 | 0.37285 | 38.7336ms | 140436 | 30 | 1.01923e+07 | 156330 | 2.55932 | 2(Loss) |
| simdjson | 755.575 | 0.436039 | 43.2009ms | 140436 | 30 | 1.79215e+07 | 177256 | 2.90202 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3106.36 | 0.549393 | 11.2399ms | 136046 | 30 | 1.57964e+06 | 41767.1 | 0.705358 | 1(Win) |
| jsonifier | 2424.01 | 0.630862 | 13.493ms | 136024 | 30 | 3.41943e+06 | 53515.7 | 0.902895 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./json/Canada%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 506.141 | 0.335689 | 942.877ms | 2090234 | 30 | 5.24375e+09 | 3.93843e+06 | 4.33346 | 1(Win) |
| glaze | 396.055 | 0.199974 | 1203.05ms | 2090234 | 30 | 3.0391e+09 | 5.03314e+06 | 5.53803 | 2(Loss) |
| simdjson | 263.535 | 0.612518 | 1833.31ms | 2090234 | 30 | 6.43982e+10 | 7.5641e+06 | 8.32304 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./json/Canada%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 920.845 | 0.348559 | 517.542ms | 2090234 | 30 | 1.70801e+09 | 2.16475e+06 | 2.38155 | 1(Win) |
| glaze | 525.168 | 0.314015 | 916.263ms | 2090234 | 30 | 4.26202e+09 | 3.79574e+06 | 4.17631 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./json/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1286.93 | 0.443791 | 1227.44ms | 6885124 | 30 | 1.53813e+10 | 5.1022e+06 | 1.70431 | 1(Win) |
| glaze | 1026.83 | 1.95135 | 1465.51ms | 6885124 | 30 | 4.67113e+11 | 6.39461e+06 | 2.13608 | 2(Loss) |
| simdjson | 810.26 | 0.283464 | 1931.68ms | 6885124 | 30 | 1.58304e+10 | 8.10377e+06 | 2.707 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./json/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1938.26 | 0.356418 | 799.881ms | 6661897 | 30 | 4.09463e+09 | 3.27783e+06 | 1.13156 | 1(Win) |
| glaze | 1167.82 | 0.425792 | 1309.71ms | 6661897 | 30 | 1.60977e+10 | 5.44031e+06 | 1.87807 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1061.05 | 0.238358 | 106.963ms | 500299 | 30 | 3.44644e+07 | 449671 | 2.06697 | 1(Win) |
| glaze | 997.976 | 0.498026 | 115.529ms | 500299 | 30 | 1.70076e+08 | 478090 | 2.19758 | 2(Loss) |
| simdjson | 629.217 | 0.500623 | 184.819ms | 500299 | 30 | 4.32315e+08 | 758279 | 3.48536 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze STATISTICAL TIE | 3071.84 | 0.44199 | 40.285ms | 500299 | 30 | 1.41387e+07 | 155321 | 0.713634 | 1(Tie) |
| jsonifier STATISTICAL TIE | 3015.15 | 1.68716 | 43.5805ms | 500299 | 30 | 2.13835e+08 | 158242 | 0.727081 | 1(Tie) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1958.56 | 0.286025 | 174.848ms | 1490030 | 30 | 1.29194e+08 | 725533 | 1.11968 | 1(Win) |
| glaze | 1697.48 | 0.484986 | 201.644ms | 1490030 | 30 | 4.94495e+08 | 837126 | 1.29185 | 2(Loss) |
| simdjson | 1665.47 | 0.474021 | 207.374ms | 1490030 | 30 | 4.90717e+08 | 853212 | 1.31659 | 3(Loss) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3258.59 | 0.35516 | 102.409ms | 1439562 | 30 | 6.71693e+07 | 421309 | 0.672684 | 1(Win) |
| glaze | 2977.83 | 0.891532 | 115.451ms | 1439584 | 30 | 5.06837e+08 | 461038 | 0.736229 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./json/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1175.65 | 0.67578 | 11.8162ms | 56369 | 30 | 2.86454e+06 | 45725.9 | 1.86361 | 1(Win) |
| glaze | 898.552 | 1.7203 | 15.3401ms | 56369 | 30 | 3.1778e+07 | 59827 | 2.43913 | 2(Loss) |
| simdjson | 676.272 | 1.04791 | 19.3949ms | 56369 | 30 | 2.08165e+07 | 79491.2 | 3.24127 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./json/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3515.15 | 0.733471 | 21.576ms | 56369 | 64 | 805268 | 15293.2 | 0.621857 | 1(Win) |
| jsonifier | 3002.19 | 1.72695 | 4.7413ms | 56369 | 30 | 2.86868e+06 | 17906.1 | 0.728184 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./json/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier STATISTICAL TIE | 1305.19 | 0.459816 | 18.4258ms | 98048 | 30 | 3.25552e+06 | 71641.7 | 1.67941 | 1(Tie) |
| glaze STATISTICAL TIE | 1292.62 | 0.496613 | 18.18ms | 98048 | 30 | 3.87162e+06 | 72338.3 | 1.69576 | 1(Tie) |
| simdjson | 1157.84 | 0.406512 | 20.5379ms | 98048 | 30 | 3.23334e+06 | 80759.1 | 1.89332 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./json/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3040.43 | 1.94042 | 7.57365ms | 94370 | 30 | 9.8972e+06 | 29600.5 | 0.719239 | 1(Win) |
| glaze | 2844.9 | 1.34514 | 8.14963ms | 94370 | 30 | 5.43238e+06 | 31634.9 | 0.76969 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1050.81 | 0.67512 | 12.6036ms | 52708 | 30 | 3.12889e+06 | 47835.9 | 2.08477 | 1(Win) |
| simdjson STATISTICAL TIE | 757.247 | 0.738705 | 16.8154ms | 52708 | 30 | 7.21342e+06 | 66380.3 | 2.89417 | 2(Tie) |
| glaze STATISTICAL TIE | 753.593 | 0.638302 | 16.3483ms | 52708 | 30 | 5.43817e+06 | 66702.2 | 2.90788 | 2(Tie) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3884.97 | 0.142248 | 3.90158ms | 52708 | 30 | 10162.3 | 12938.6 | 0.562318 | 1(Win) |
| jsonifier | 3135.77 | 1.77771 | 4.37478ms | 52708 | 30 | 2.43616e+06 | 16030 | 0.696551 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1044.08 | 0.734836 | 17.0176ms | 71665 | 30 | 6.94142e+06 | 65459.6 | 2.099 | 1(Win) |
| jsonifier | 1008.84 | 0.464759 | 17.5201ms | 71665 | 30 | 2.97405e+06 | 67746.2 | 2.17199 | 2(Loss) |
| glaze | 923.875 | 0.547006 | 18.786ms | 71665 | 30 | 4.91239e+06 | 73976.5 | 2.37216 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3830.86 | 0.63677 | 5.11595ms | 70103 | 30 | 370482 | 17451.8 | 0.570844 | 1(Win) |
| jsonifier | 3128.51 | 0.986014 | 5.7726ms | 70103 | 30 | 1.33194e+06 | 21369.7 | 0.698042 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1025.7 | 0.145422 | 3.25325ms | 11812 | 30 | 7652.32 | 10982.6 | 2.13144 | 1(Win) |
| glaze | 691.557 | 0.31595 | 4.43362ms | 11812 | 30 | 79460 | 16289 | 3.16396 | 2(Loss) |
| simdjson | 549.544 | 1.09474 | 5.60409ms | 11812 | 30 | 1.51073e+06 | 20498.5 | 3.98378 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2848.56 | 0.153619 | 1.46716ms | 11812 | 30 | 1107.15 | 3954.57 | 0.758675 | 1(Win) |
| glaze | 2687.32 | 0.158143 | 1.50951ms | 11812 | 30 | 1318.35 | 4191.83 | 0.807783 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1643.28 | 1.12207 | 5.06147ms | 32403 | 30 | 1.33571e+06 | 18805 | 1.33202 | 1(Win) |
| simdjson | 1351.4 | 0.21132 | 6.20041ms | 32403 | 30 | 70049.3 | 22866.6 | 1.62027 | 2(Loss) |
| glaze | 1274.01 | 0.923907 | 6.39304ms | 32403 | 30 | 1.50663e+06 | 24255.7 | 1.71846 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 3808.72 | 0.132101 | 2.42424ms | 31235 | 30 | 3202.28 | 7821 | 0.5728 | 1(Win) |
| jsonifier | 3329.16 | 1.09085 | 2.74834ms | 31235 | 30 | 285799 | 8947.6 | 0.651756 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2128.16 | 0.456019 | 12.6548ms | 108313 | 30 | 1.46975e+06 | 48537.5 | 1.02949 | 1(Win) |
| glaze | 1277.63 | 0.97961 | 20.432ms | 108313 | 30 | 1.88181e+07 | 80849 | 1.71575 | 2(Loss) |
| simdjson | 940.206 | 0.510664 | 26.933ms | 108313 | 30 | 9.44292e+06 | 109865 | 2.33178 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 2474.8 | 0.712634 | 10.5405ms | 108313 | 30 | 2.6542e+06 | 41738.8 | 0.885205 | 1(Win) |
| jsonifier | 1958.53 | 2.34527 | 25.1306ms | 108313 | 32 | 4.89598e+07 | 52741.3 | 1.11759 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze STATISTICAL TIE | 1817.23 | 0.576264 | 29.323ms | 222373 | 30 | 1.35678e+07 | 116701 | 1.20647 | 1(Tie) |
| simdjson STATISTICAL TIE | 1808.99 | 0.363493 | 28.7479ms | 222373 | 30 | 5.44757e+06 | 117232 | 1.21195 | 1(Tie) |
| jsonifier | 1729.92 | 0.39919 | 29.7772ms | 222373 | 30 | 7.18446e+06 | 122591 | 1.2674 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3467.4 | 1.21025 | 14.8803ms | 213963 | 30 | 1.52173e+07 | 58848.4 | 0.631421 | 1(Win) |
| glaze | 3054.9 | 1.35478 | 16.0303ms | 213963 | 30 | 2.45663e+07 | 66794.7 | 0.717408 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 530.59 | 0.603769 | 795.148ms | 1834197 | 30 | 1.1886e+10 | 3.29676e+06 | 4.13369 | 1(Win) |
| glaze | 367.275 | 0.347916 | 1146.42ms | 1834197 | 30 | 8.23719e+09 | 4.76272e+06 | 5.97204 | 2(Loss) |
| simdjson | 232.002 | 0.450501 | 1791.56ms | 1834197 | 30 | 3.46117e+10 | 7.53971e+06 | 9.45437 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 611.147 | 0.625073 | 683.613ms | 1834197 | 30 | 9.60247e+09 | 2.8622e+06 | 3.58864 | 1(Win) |
| glaze | 341.562 | 0.399319 | 1237.15ms | 1833577 | 30 | 1.25378e+10 | 5.11953e+06 | 6.42167 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1855.75 | 0.334247 | 1280.32ms | 10252236 | 30 | 9.30364e+09 | 5.26864e+06 | 1.18195 | 1(Win) |
| glaze | 1560.8 | 0.332331 | 1524.02ms | 10252236 | 30 | 1.30019e+10 | 6.26428e+06 | 1.40531 | 2(Loss) |
| simdjson | 1224.58 | 0.464738 | 1934.99ms | 10252236 | 30 | 4.13049e+10 | 7.98421e+06 | 1.79119 | 3(Loss) |

----
### Marine IK Test (Prettified) Write Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Marine%20IK%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1768.45 | 0.297891 | 1279.58ms | 9930848 | 30 | 7.63524e+09 | 5.35542e+06 | 1.24027 | 1(Win) |
| glaze | 1140.26 | 0.61245 | 1968.84ms | 9930228 | 30 | 7.76199e+10 | 8.3053e+06 | 1.92361 | 2(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 955.514 | 0.509916 | 154.225ms | 642697 | 30 | 3.20964e+08 | 641460 | 2.29514 | 1(Win) |
| glaze | 806.389 | 0.416772 | 187.16ms | 642697 | 30 | 3.01052e+08 | 760084 | 2.71945 | 2(Loss) |
| simdjson | 356.125 | 0.491083 | 417.997ms | 642697 | 30 | 2.14308e+09 | 1.72109e+06 | 6.15829 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1117.53 | 0.467426 | 133.263ms | 642697 | 30 | 1.9717e+08 | 548463 | 1.96211 | 1(Win) |
| glaze | 820.465 | 0.491192 | 178.269ms | 642692 | 30 | 4.03932e+08 | 747038 | 2.6724 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1394.74 | 0.556566 | 215.685ms | 1306201 | 30 | 7.41296e+08 | 893137 | 1.57213 | 1(Win) |
| jsonifier | 1265.32 | 0.340005 | 234.192ms | 1306201 | 30 | 3.36133e+08 | 984488 | 1.73303 | 2(Loss) |
| simdjson | 706.342 | 0.529179 | 428.949ms | 1306201 | 30 | 2.61286e+09 | 1.76358e+06 | 3.10487 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1308.48 | 0.444825 | 217.581ms | 1225964 | 30 | 4.7394e+08 | 893536 | 1.67576 | 1(Win) |
| glaze | 1179.75 | 0.369265 | 237.23ms | 1225970 | 30 | 4.01769e+08 | 991037 | 1.8587 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./json/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 764.438 | 0.377015 | 122.391ms | 409725 | 30 | 1.11414e+08 | 511152 | 2.86885 | 1(Win) |
| simdjson STATISTICAL TIE | 469.446 | 0.436666 | 199.584ms | 409725 | 30 | 3.9631e+08 | 832352 | 4.67139 | 2(Tie) |
| glaze STATISTICAL TIE | 466.527 | 0.582714 | 201.09ms | 409725 | 30 | 7.14601e+08 | 837559 | 4.70049 | 2(Tie) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./json/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1807.24 | 1.02702 | 52.0632ms | 409725 | 30 | 1.47922e+08 | 216211 | 1.21303 | 1(Win) |
| jsonifier | 1708.67 | 0.341949 | 57.0625ms | 409725 | 30 | 1.83447e+07 | 228683 | 1.28333 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./json/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1021.65 | 0.478623 | 186.735ms | 814756 | 30 | 3.97523e+08 | 760550 | 2.14652 | 1(Win) |
| simdjson | 911.887 | 0.539458 | 208.584ms | 814756 | 30 | 6.33883e+08 | 852092 | 2.40481 | 2(Loss) |
| glaze | 782.665 | 0.458606 | 236.209ms | 814756 | 30 | 6.21876e+08 | 992777 | 2.80196 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./json/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2354.13 | 0.357786 | 78.092ms | 785750 | 30 | 3.89112e+07 | 318313 | 0.931068 | 1(Win) |
| glaze | 2127.87 | 1.61609 | 84.6503ms | 785750 | 30 | 9.71705e+08 | 352160 | 1.0303 | 2(Loss) |

----
### Semanticscholar Corpus Test (Minified) Read Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 834.153 | 0.43173 | 2384.1ms | 8587914 | 30 | 5.39052e+10 | 9.81843e+06 | 2.62956 | 1(Win) |
| glaze | 667.403 | 0.426323 | 2983.12ms | 8587914 | 30 | 8.21104e+10 | 1.22716e+07 | 3.28655 | 2(Loss) |
| simdjson | 589.309 | 0.597133 | 3391.87ms | 8587914 | 30 | 2.06611e+11 | 1.38978e+07 | 3.722 | 3(Loss) |

----
### Semanticscholar Corpus Test (Minified) Write Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2278.35 | 0.338924 | 863.886ms | 8563074 | 30 | 4.42736e+09 | 3.58434e+06 | 0.962658 | 1(Win) |
| glaze | 2196.52 | 0.442418 | 898.453ms | 8588126 | 30 | 8.16419e+09 | 3.72875e+06 | 0.998553 | 2(Loss) |

----
### Semanticscholar Corpus Test (Prettified) Read Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 819.368 | 0.517659 | 2712.08ms | 9976912 | 30 | 1.08404e+11 | 1.16123e+07 | 2.67694 | 1(Win) |
| glaze | 699.876 | 0.379189 | 3253.75ms | 9976912 | 30 | 7.9723e+10 | 1.35949e+07 | 3.13398 | 2(Loss) |
| simdjson | 669.874 | 0.356824 | 3417.69ms | 9976912 | 30 | 7.70613e+10 | 1.42038e+07 | 3.27436 | 3(Loss) |

----
### Semanticscholar Corpus Test (Prettified) Write Results [(View the data used in the following test)](./json/Semanticscholar%20Corpus%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Semanticscholar%20Corpus%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 2312.04 | 0.302084 | 1097.49ms | 11078090 | 30 | 5.71629e+09 | 4.5695e+06 | 0.948645 | 1(Win) |
| jsonifier | 2249.51 | 0.290231 | 1118.42ms | 11048723 | 30 | 5.54443e+09 | 4.68407e+06 | 0.975016 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 4512.54 | 0.551092 | 13.8881ms | 264040 | 30 | 2.83705e+06 | 55801.9 | 0.48572 | 1(Win) |
| jsonifier | 4031.7 | 0.566057 | 15.4564ms | 264040 | 30 | 3.74978e+06 | 62457.1 | 0.543623 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 5933.39 | 0.55365 | 40.6941ms | 399947 | 32 | 4.0534e+06 | 64283.5 | 0.36945 | 1(Win) |
| jsonifier | 5092.21 | 0.57401 | 18.5339ms | 399947 | 30 | 5.54566e+06 | 74902.5 | 0.430437 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 1414.59 | 0.476701 | 44.2702ms | 264040 | 30 | 2.1602e+07 | 178008 | 1.54995 | 1(Win) |
| glaze | 955.341 | 0.396611 | 65.9739ms | 264040 | 30 | 3.27848e+07 | 263579 | 2.29542 | 2(Loss) |
| simdjson | 834.475 | 0.505102 | 72.8234ms | 264040 | 30 | 6.96936e+07 | 301756 | 2.62784 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 3927.21 | 0.827293 | 16.5259ms | 264040 | 30 | 8.44132e+06 | 64118.8 | 0.558097 | 1(Win) |
| glaze | 3085.45 | 1.70681 | 20.9711ms | 263923 | 30 | 5.81577e+07 | 81575.4 | 0.710366 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| simdjson | 1362.1 | 0.39624 | 72.6653ms | 409612 | 30 | 3.87404e+07 | 286790 | 1.61003 | 1(Win) |
| jsonifier STATISTICAL TIE | 1266.36 | 1.34992 | 74.2501ms | 409612 | 30 | 5.20196e+08 | 308472 | 1.73157 | 2(Tie) |
| glaze STATISTICAL TIE | 1232.16 | 0.356807 | 75.4762ms | 409612 | 30 | 3.83881e+07 | 317033 | 1.77975 | 2(Tie) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier STATISTICAL TIE | 3652.89 | 0.411485 | 25.8102ms | 399947 | 30 | 5.53811e+06 | 104416 | 0.600155 | 1(Tie) |
| glaze STATISTICAL TIE | 3645.21 | 0.91814 | 27.011ms | 399830 | 30 | 2.76722e+07 | 104605 | 0.601295 | 1(Tie) |

----
### Minify Test Write Results [(View the data used in the following test)](./json/Minify%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| glaze | 1799.49 | 0.401099 | 60.9431ms | 466906 | 30 | 2.95517e+07 | 247445 | 1.21867 | 1(Win) |
| jsonifier | 1762.91 | 0.261907 | 59.9804ms | 466906 | 30 | 1.31284e+07 | 252580 | 1.24382 | 2(Loss) |
| simdjson | 809.291 | 0.410986 | 128.79ms | 466906 | 30 | 1.534e+08 | 550205 | 2.70892 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./json/Prettify%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier STATISTICAL TIE | 2083.36 | 0.340678 | 78.0148ms | 699405 | 30 | 3.56894e+07 | 320158 | 1.05241 | 1(Tie) |
| glaze STATISTICAL TIE | 2079.82 | 0.351628 | 78.3772ms | 699405 | 30 | 3.81501e+07 | 320703 | 1.05447 | 1(Tie) |

----
### Validate Test Read Results [(View the data used in the following test)](./json/Validate%20Test.json):

<p align="left"><a href="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Linux-Clang/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Cycles/Byte | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | ----------- | -------- |
| jsonifier | 2650.07 | 0.350312 | 54.4971ms | 631514 | 30 | 1.90143e+07 | 227261 | 0.827466 | 1(Win) |
| glaze | 2215.2 | 0.371954 | 66.2011ms | 631514 | 30 | 3.06789e+07 | 271875 | 0.989939 | 2(Loss) |
