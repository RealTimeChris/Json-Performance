# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.26100 using the MSVC 19.51.36248.0 compiler).  

Latest Results: (Jul 02, 2026)
#### Using the following commits:
----
| Jsonifier: [6a2069c](https://github.com/RealTimeChris/Jsonifier/commit/6a2069c)  
| Glaze: [4fab045](https://github.com/stephenberry/glaze/commit/4fab045)  
| Simdjson: [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (AMD EPYC 7763 64-Core Processor): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Double Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Double%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Double%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Double%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 426.797 | 0.228932 | 2.1955ms | 1811 | 30 | 2574.71 | 4046.67 | 1(Win) |
| glaze | 160.016 | 0.0617665 | 3.8558ms | 1811 | 30 | 1333.33 | 10793.3 | 2(Loss) |
| simdjson | 97.4664 | 0.073605 | 5.7975ms | 1811 | 30 | 5103.45 | 17720 | 3(Loss) |

----
### Double Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Double%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Double%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 306.768 | 0.497671 | 2.6251ms | 1811 | 30 | 23551.7 | 5630 | 1(Win) |
| glaze | 212.831 | 0.15385 | 3.3346ms | 1798 | 30 | 4609.2 | 8056.67 | 2(Loss) |

----
### Uint64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1054.3 | 0.166684 | 2.0502ms | 3873 | 30 | 1022.99 | 3503.33 | 1(Win) |
| glaze | 616.239 | 0.128395 | 5.4629ms | 3873 | 32 | 1895.16 | 5993.75 | 2(Loss) |
| simdjson | 231.331 | 0.0625104 | 5.1513ms | 3873 | 30 | 2988.51 | 15966.7 | 3(Loss) |

----
### Uint64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Uint64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Uint64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1582.96 | 0.375161 | 1.9397ms | 3873 | 30 | 2298.85 | 2333.33 | 1(Win) |
| glaze | 924.165 | 0.724611 | 2.3202ms | 3873 | 30 | 25160.9 | 3996.67 | 2(Loss) |

----
### Int64 Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1146.19 | 0.879372 | 2.0839ms | 3862 | 30 | 23954 | 3213.33 | 1(Win) |
| glaze | 571.908 | 0.141261 | 2.886ms | 3862 | 30 | 2482.76 | 6440 | 2(Loss) |
| simdjson | 233.407 | 0.783329 | 21.6567ms | 3862 | 64 | 977835 | 15779.7 | 3(Loss) |

----
### Int64 Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Int64%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Int64%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1601.34 | 0.361067 | 1.7725ms | 3862 | 30 | 2068.97 | 2300 | 1(Win) |
| glaze | 881.825 | 0.3182 | 2.3445ms | 3862 | 30 | 5298.85 | 4176.67 | 2(Loss) |

----
### Bool Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 725.273 | 0.61765 | 1.4314ms | 905 | 30 | 1620.69 | 1190 | 1(Win) |
| glaze | 141.333 | 0.0758524 | 2.7484ms | 905 | 30 | 643.678 | 6106.67 | 2(Loss) |
| simdjson | 68.3534 | 0.221197 | 4.3828ms | 905 | 30 | 23402.3 | 12626.7 | 3(Loss) |

----
### Bool Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Bool%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Bool%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 430.82 | 0.166389 | 1.7171ms | 905 | 30 | 333.333 | 2003.33 | 1(Win) |
| glaze | 163.668 | 0.180323 | 2.5285ms | 905 | 30 | 2712.64 | 5273.33 | 2(Loss) |

----
### String Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1456.63 | 0.169279 | 2.7157ms | 8813 | 30 | 2862.07 | 5770 | 1(Win) |
| glaze | 783.78 | 0.0858116 | 3.8686ms | 8813 | 30 | 2540.23 | 10723.3 | 2(Loss) |
| simdjson | 340.824 | 0.0570179 | 7.3781ms | 8813 | 30 | 5931.03 | 24660 | 3(Loss) |

----
### String Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/String%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/String%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/String%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1779.96 | 0.206907 | 4.6164ms | 8813 | 32 | 3054.44 | 4721.88 | 1(Win) |
| glaze | 1537.45 | 0.521345 | 2.646ms | 8813 | 30 | 24367.8 | 5466.67 | 2(Loss) |

----
### Abc (Out of Order) Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 769.782 | 0.0577792 | 12.5902ms | 33713 | 30 | 17471.3 | 41766.7 | 1(Win) |
| glaze | 733.99 | 1.65363 | 12.0428ms | 33713 | 30 | 1.57403e+07 | 43803.3 | 2(Loss) |
| simdjson | 105.836 | 0.689829 | 74.5707ms | 33713 | 30 | 1.31744e+08 | 303783 | 3(Loss) |

----
### Abc (Out of Order) Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1686.25 | 0.298953 | 5.9148ms | 33713 | 30 | 97471.3 | 19066.7 | 1(Win) |
| glaze | 1385.64 | 0.173912 | 7.1029ms | 33689 | 30 | 48781.6 | 23186.7 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in these two tests feature keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.
This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently locate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.
In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.  

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 937.869 | 1.48774 | 13.2109ms | 48024 | 30 | 1.58347e+07 | 48833.3 | 1(Win) |
| jsonifier | 615.003 | 1.17688 | 19.5323ms | 48024 | 30 | 2.30436e+07 | 74470 | 2(Loss) |
| simdjson | 148.218 | 0.889358 | 75.1297ms | 48024 | 30 | 2.26564e+08 | 309000 | 3(Loss) |

----
### Abc (Out of Order) Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1122.83 | 2.16306 | 253.597ms | 48000 | 256 | 1.99082e+08 | 40768.8 | 1(Win) |
| jsonifier | 972.383 | 2.19164 | 11.7512ms | 48024 | 30 | 3.19669e+07 | 47100 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2755.82 | 0.0855499 | 4.1942ms | 33713 | 30 | 2988.51 | 11666.7 | 1(Win) |
| simdjson | 1737.02 | 0.129186 | 12.5239ms | 33713 | 32 | 18296.4 | 18509.4 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3366.77 | 0.0746295 | 4.6173ms | 48024 | 30 | 3091.95 | 13603.3 | 1(Win) |
| simdjson | 2147.18 | 0.0815131 | 6.51ms | 48024 | 30 | 9068.97 | 21330 | 2(Loss) |

----
### Apache Builds Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 453.453 | 1.73161 | 262.499ms | 94651 | 64 | 7.60443e+08 | 199064 | 1(Win) |
| glaze | 396.111 | 1.91773 | 289.676ms | 94651 | 64 | 1.22229e+09 | 227881 | 2(Loss) |
| simdjson | 328.659 | 1.64528 | 170.245ms | 94651 | 32 | 6.53412e+08 | 274650 | 3(Loss) |

----
### Apache Builds Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1636.54 | 1.58293 | 14.8712ms | 94651 | 30 | 2.28687e+07 | 55156.7 | 1(Win) |
| jsonifier | 1495.55 | 1.43914 | 15.8648ms | 94651 | 30 | 2.2635e+07 | 60356.7 | 2(Loss) |

----
### Apache Builds Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 527.965 | 2.26395 | 140.528ms | 136024 | 32 | 9.9016e+08 | 245703 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 513.848 | 2.21617 | 61.5736ms | 136024 | 30 | 9.39052e+08 | 252453 | 1(Tie) |
| simdjson | 470.959 | 0.463998 | 68.833ms | 136024 | 30 | 4.90025e+07 | 275443 | 3(Loss) |

----
### Apache Builds Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Apache%20Builds%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1930.3 | 1.1189 | 17.7781ms | 136024 | 30 | 1.69624e+07 | 67203.3 | 1(Win) |
| glaze | 1283.32 | 0.671289 | 26.0344ms | 136046 | 30 | 1.38179e+07 | 101100 | 2(Loss) |

----
### Canada Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze **STATISTICAL TIE** | 210.116 | 0.665426 | 2284.93ms | 2090234 | 30 | 1.19561e+11 | 9.48714e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 205.76 | 1.29121 | 2369.53ms | 2090234 | 30 | 4.69443e+11 | 9.68801e+06 | 1(Tie) |
| simdjson | 171.587 | 0.604037 | 2796.91ms | 2090234 | 30 | 1.4773e+11 | 1.16174e+07 | 3(Loss) |

----
### Canada Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 542.883 | 2.06752 | 2124.83ms | 2090234 | 32 | 1.84427e+11 | 3.67188e+06 | 1(Win) |
| glaze | 466.006 | 0.328993 | 1030.52ms | 2090234 | 30 | 5.94156e+09 | 4.27763e+06 | 2(Loss) |

----
### Canada Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 598.14 | 0.534137 | 2579.3ms | 6661897 | 30 | 9.65642e+10 | 1.06217e+07 | 1(Win) |
| jsonifier | 533.566 | 0.641686 | 2850.27ms | 6661897 | 30 | 1.75141e+11 | 1.19072e+07 | 2(Loss) |
| simdjson | 510.228 | 0.542294 | 2988.05ms | 6661897 | 30 | 1.36791e+11 | 1.24518e+07 | 3(Loss) |

----
### Canada Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1252.96 | 0.208763 | 1217.73ms | 6661897 | 30 | 3.36167e+09 | 5.07064e+06 | 1(Win) |
| glaze | 761.876 | 0.21581 | 2008.8ms | 6661897 | 30 | 9.71612e+09 | 8.33899e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 467.662 | 0.851005 | 245.603ms | 500299 | 30 | 2.26142e+09 | 1.02023e+06 | 1(Win) |
| jsonifier | 453.951 | 0.766923 | 253.173ms | 500299 | 30 | 1.94925e+09 | 1.05104e+06 | 2(Loss) |
| simdjson | 261.133 | 0.185174 | 440.163ms | 500299 | 30 | 3.43415e+08 | 1.82713e+06 | 3(Loss) |

----
### CitmCatalog Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1643.32 | 0.671399 | 70.9464ms | 500299 | 30 | 1.13998e+08 | 290340 | 1(Win) |
| glaze | 1283.25 | 1.00408 | 90.8827ms | 500299 | 30 | 4.18114e+08 | 371807 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 1001.66 | 0.510042 | 331.649ms | 1439562 | 30 | 1.46608e+09 | 1.3706e+06 | 1(Win) |
| simdjson **STATISTICAL TIE** | 687.296 | 0.417183 | 479.12ms | 1439562 | 30 | 2.08328e+09 | 1.9975e+06 | 2(Tie) |
| jsonifier **STATISTICAL TIE** | 686.751 | 0.350535 | 480.509ms | 1439562 | 30 | 1.47315e+09 | 1.99908e+06 | 2(Tie) |

----
### CitmCatalog Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1935.55 | 1.83893 | 172.053ms | 1439562 | 30 | 5.1039e+09 | 709293 | 1(Win) |
| glaze | 929.683 | 0.547247 | 359.305ms | 1439584 | 30 | 1.95926e+09 | 1.47673e+06 | 2(Loss) |

----
### Discord Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 690.973 | 1.24221 | 20.3818ms | 56369 | 30 | 2.802e+07 | 77800 | 1(Win) |
| glaze | 625.817 | 0.929742 | 22.6008ms | 56369 | 30 | 1.91352e+07 | 85900 | 2(Loss) |
| simdjson | 293.768 | 0.595302 | 45.5957ms | 56369 | 30 | 3.56013e+07 | 182993 | 3(Loss) |

----
### Discord Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1393.53 | 1.258 | 10.4232ms | 56369 | 30 | 7.0653e+06 | 38576.7 | 1(Win) |
| glaze | 1220.1 | 1.99992 | 11.831ms | 56369 | 30 | 2.32935e+07 | 44060 | 2(Loss) |

----
### Discord Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 925.686 | 1.16655 | 25.0934ms | 94370 | 30 | 3.85894e+07 | 97223.3 | 1(Win) |
| jsonifier | 592.536 | 0.962554 | 38.6052ms | 94370 | 30 | 6.41226e+07 | 151887 | 2(Loss) |
| simdjson | 477.377 | 0.644271 | 46.9201ms | 94370 | 30 | 4.42593e+07 | 188527 | 3(Loss) |

----
### Discord Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2196.33 | 1.49023 | 11.1571ms | 94370 | 30 | 1.11867e+07 | 40976.7 | 1(Win) |
| glaze | 1131.53 | 1.00495 | 20.4432ms | 94370 | 30 | 1.91665e+07 | 79536.7 | 2(Loss) |

----
### Github Events Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 660.587 | 1.43043 | 21.1408ms | 52708 | 30 | 3.55427e+07 | 76093.3 | 1(Win) |
| glaze | 490.77 | 1.77279 | 26.4402ms | 52708 | 30 | 9.89087e+07 | 102423 | 2(Loss) |
| simdjson | 421.123 | 0.826721 | 70.0142ms | 52708 | 32 | 3.11605e+07 | 119362 | 3(Loss) |

----
### Github Events Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2369.56 | 0.283863 | 6.5142ms | 52708 | 30 | 108782 | 21213.3 | 1(Win) |
| glaze | 1899.71 | 1.64372 | 7.9ms | 52708 | 30 | 5.6749e+06 | 26460 | 2(Loss) |

----
### Github Events Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 608.071 | 1.25088 | 28.2863ms | 70103 | 30 | 5.67433e+07 | 109947 | 1(Win) |
| simdjson | 539.577 | 1.30075 | 31.2453ms | 70103 | 30 | 7.79245e+07 | 123903 | 2(Loss) |
| jsonifier | 449.398 | 2.12407 | 37.9602ms | 70103 | 30 | 2.99552e+08 | 148767 | 3(Loss) |

----
### Github Events Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Github%20Events%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2815.36 | 0.488655 | 7.2446ms | 70103 | 30 | 403954 | 23746.7 | 1(Win) |
| glaze | 1694.69 | 0.25832 | 11.0862ms | 70103 | 30 | 311552 | 39450 | 2(Loss) |

----
### Google Maps Response Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 510.798 | 0.160845 | 7.0805ms | 11812 | 30 | 37747.1 | 22053.3 | 1(Win) |
| glaze | 397.394 | 2.26315 | 8.109ms | 11812 | 30 | 1.23467e+07 | 28346.7 | 2(Loss) |
| simdjson | 245.849 | 2.05019 | 12.1883ms | 11812 | 30 | 2.64741e+07 | 45820 | 3(Loss) |

----
### Google Maps Response Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1057.07 | 0.451453 | 3.9095ms | 11812 | 30 | 69436.8 | 10656.7 | 1(Win) |
| glaze | 1011.81 | 0.20352 | 4.0589ms | 11812 | 30 | 15402.3 | 11133.3 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 804.429 | 1.92665 | 10.2276ms | 31235 | 30 | 1.52698e+07 | 37030 | 1(Win) |
| jsonifier | 644.855 | 1.30456 | 12.497ms | 31235 | 30 | 1.08944e+07 | 46193.3 | 2(Loss) |
| simdjson | 609.994 | 1.31593 | 13.0463ms | 31235 | 30 | 1.23885e+07 | 48833.3 | 3(Loss) |

----
### Google Maps Response Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Google%20Maps%20Response%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2462.5 | 0.442227 | 4.3107ms | 31235 | 30 | 85850.6 | 12096.7 | 1(Win) |
| glaze | 1466.67 | 0.266407 | 6.2679ms | 31235 | 30 | 87827.6 | 20310 | 2(Loss) |

----
### Instruments Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1036.06 | 0.865925 | 25.8524ms | 108313 | 30 | 2.236e+07 | 99700 | 1(Win) |
| glaze | 561.581 | 0.792753 | 46.1909ms | 108313 | 30 | 6.37872e+07 | 183937 | 2(Loss) |
| simdjson | 325.302 | 0.735501 | 77.4398ms | 108313 | 30 | 1.63635e+08 | 317537 | 3(Loss) |

----
### Instruments Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1554.56 | 0.849278 | 17.2873ms | 108313 | 30 | 9.55361e+06 | 66446.7 | 1(Win) |
| glaze | 1302.1 | 0.680179 | 20.5396ms | 108313 | 30 | 8.73459e+06 | 79330 | 2(Loss) |

----
### Instruments Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 914.248 | 1.13671 | 55.1158ms | 213963 | 30 | 1.93095e+08 | 223190 | 1(Win) |
| jsonifier | 711.243 | 0.904722 | 71.1501ms | 213963 | 30 | 2.02112e+08 | 286893 | 2(Loss) |
| simdjson | 612.147 | 0.806868 | 81.3584ms | 213963 | 30 | 2.17016e+08 | 333337 | 3(Loss) |

----
### Instruments Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Instruments%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2829.2 | 1.10075 | 18.9754ms | 213963 | 30 | 1.89081e+07 | 72123.3 | 1(Win) |
| glaze | 1292.2 | 0.704412 | 91.0849ms | 213963 | 32 | 3.95931e+07 | 157909 | 2(Loss) |

----
### Marine IK Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 189.319 | 0.821894 | 2217.81ms | 1834197 | 30 | 1.73005e+11 | 9.23959e+06 | 1(Tie) |
| glaze **STATISTICAL TIE** | 187.232 | 1.28225 | 2238.27ms | 1834197 | 30 | 4.30529e+11 | 9.34258e+06 | 1(Tie) |
| simdjson | 143.689 | 0.470381 | 2946.44ms | 1834197 | 30 | 9.83705e+10 | 1.21737e+07 | 3(Loss) |

----
### Marine IK Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 324.62 | 1.83273 | 1295.88ms | 1834197 | 30 | 2.92589e+11 | 5.38853e+06 | 1(Win) |
| glaze | 278.785 | 0.148917 | 1510.08ms | 1833577 | 30 | 2.61741e+09 | 6.27234e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Marine%20IK%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 825.392 | 0.428463 | 2760.3ms | 9930848 | 30 | 7.25102e+10 | 1.14743e+07 | 1(Win) |
| simdjson | 685.648 | 0.449599 | 3321.49ms | 9930848 | 30 | 1.15702e+11 | 1.38129e+07 | 2(Loss) |
| jsonifier | 660.102 | 0.753095 | 3433.42ms | 9930848 | 30 | 3.50245e+11 | 1.43475e+07 | 3(Loss) |

----
### Mesh Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 461.915 | 1.0865 | 321.283ms | 642697 | 30 | 6.23544e+09 | 1.32692e+06 | 1(Win) |
| glaze | 431.83 | 1.03334 | 342.12ms | 642697 | 30 | 6.45344e+09 | 1.41936e+06 | 2(Loss) |
| simdjson | 291.126 | 0.971743 | 505.811ms | 642697 | 30 | 1.25567e+10 | 2.10536e+06 | 3(Loss) |

----
### Mesh Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 616.911 | 0.285901 | 240.767ms | 642697 | 30 | 2.42058e+08 | 993537 | 1(Win) |
| glaze | 409.916 | 0.455223 | 361.754ms | 642692 | 30 | 1.38991e+09 | 1.49523e+06 | 2(Loss) |

----
### Mesh Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 713.361 | 1.65423 | 390.31ms | 1225964 | 30 | 2.20522e+10 | 1.63896e+06 | 1(Win) |
| jsonifier | 678.949 | 0.163412 | 419.099ms | 1225964 | 30 | 2.37559e+08 | 1.72203e+06 | 2(Loss) |
| simdjson | 536.147 | 0.535591 | 525.563ms | 1225964 | 30 | 4.09238e+09 | 2.18069e+06 | 3(Loss) |

----
### Mesh Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Mesh%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 811.616 | 0.497887 | 349.712ms | 1225964 | 30 | 1.54325e+09 | 1.44055e+06 | 1(Win) |
| glaze | 700.592 | 0.549509 | 401.877ms | 1225970 | 30 | 2.5229e+09 | 1.66884e+06 | 2(Loss) |

----
### Random Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 457.489 | 0.574175 | 207.697ms | 409725 | 30 | 7.21497e+08 | 854107 | 1(Win) |
| glaze | 307.046 | 0.303459 | 308.265ms | 409725 | 30 | 4.47404e+08 | 1.27259e+06 | 2(Loss) |
| simdjson | 261.102 | 0.274666 | 361.1ms | 409725 | 30 | 5.06868e+08 | 1.49652e+06 | 3(Loss) |

----
### Random Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1082.95 | 0.407891 | 88.0184ms | 409725 | 30 | 6.49791e+07 | 360813 | 1(Win) |
| glaze | 1034.4 | 0.482716 | 92.8739ms | 409725 | 30 | 9.97502e+07 | 377750 | 2(Loss) |

----
### Random Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 512.469 | 0.178683 | 353.926ms | 785750 | 30 | 2.04796e+08 | 1.46223e+06 | 1(Win) |
| jsonifier | 494.366 | 0.171341 | 366.059ms | 785750 | 30 | 2.02355e+08 | 1.51578e+06 | 2(Loss) |
| simdjson | 482.05 | 0.174464 | 374.568ms | 785750 | 30 | 2.20657e+08 | 1.55451e+06 | 3(Loss) |

----
### Random Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Random%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1798.34 | 0.499366 | 101.276ms | 785750 | 30 | 1.29893e+08 | 416690 | 1(Win) |
| glaze | 870.824 | 0.703884 | 208.125ms | 785750 | 30 | 1.10061e+09 | 860507 | 2(Loss) |

----
### Twitter Partial Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3180.73 | 0.889491 | 20.5237ms | 264040 | 30 | 1.48761e+07 | 79166.7 | 1(Win) |
| simdjson | 1445.57 | 0.576878 | 43.6605ms | 264040 | 30 | 3.02937e+07 | 174193 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3936.08 | 0.663132 | 24.7911ms | 399947 | 30 | 1.23879e+07 | 96903.3 | 1(Win) |
| simdjson | 1901.83 | 0.730127 | 49.7719ms | 399947 | 30 | 6.43246e+07 | 200553 | 2(Loss) |

----
### Twitter Test (Minified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 813.15 | 1.45928 | 76.2041ms | 264040 | 30 | 6.1263e+08 | 309670 | 1(Win) |
| glaze | 510.446 | 0.670478 | 121.454ms | 264040 | 30 | 3.28194e+08 | 493310 | 2(Loss) |
| simdjson | 410.767 | 0.906264 | 148.247ms | 264040 | 30 | 9.25935e+08 | 613020 | 3(Loss) |

----
### Twitter Test (Minified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2144.93 | 0.837491 | 29.662ms | 264040 | 30 | 2.89996e+07 | 117397 | 1(Win) |
| glaze | 1632.94 | 0.828397 | 43.0245ms | 263923 | 30 | 4.89114e+07 | 154137 | 2(Loss) |

----
### Twitter Test (Prettified) Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| glaze | 690.731 | 0.5792 | 135.61ms | 399947 | 30 | 3.06878e+08 | 552197 | 1(Win) |
| simdjson **STATISTICAL TIE** | 607.259 | 0.431688 | 153.165ms | 399947 | 30 | 2.20556e+08 | 628100 | 2(Tie) |
| jsonifier **STATISTICAL TIE** | 597.586 | 0.796691 | 154.976ms | 399947 | 30 | 7.75721e+08 | 638267 | 2(Tie) |

----
### Twitter Test (Prettified) Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2738.7 | 0.69318 | 35.3068ms | 399947 | 30 | 2.79594e+07 | 139270 | 1(Win) |
| glaze | 1546.66 | 0.598859 | 60.82ms | 399830 | 30 | 6.53934e+07 | 246537 | 2(Loss) |

----
### Minify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Minify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Minify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1232.99 | 0.519263 | 89.0776ms | 466906 | 30 | 1.05497e+08 | 361137 | 1(Win) |
| glaze | 998.4 | 0.429181 | 109.077ms | 466906 | 30 | 1.09914e+08 | 445990 | 2(Loss) |
| simdjson | 541.844 | 0.366785 | 198.663ms | 466906 | 30 | 2.72556e+08 | 821780 | 3(Loss) |

----
### Prettify Test Write Results [(View the data used in the following test)](./Json/Windows-MSVC/Prettify%20Test%20Write.json):

<p align="left"><a href="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Prettify%20Test%20Write_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1425.62 | 0.5488 | 113.793ms | 699405 | 30 | 1.97788e+08 | 467870 | 1(Win) |
| glaze | 1257.86 | 0.394635 | 130.81ms | 699405 | 30 | 1.31373e+08 | 530270 | 2(Loss) |

----
### Validate Test Read Results [(View the data used in the following test)](./Json/Windows-MSVC/Validate%20Test%20Read.json):

<p align="left"><a href="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png" target="_blank"><img src="./graphs/Windows-MSVC/Validate%20Test%20Read_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2338.29 | 0.700651 | 63.6229ms | 631514 | 30 | 9.76996e+07 | 257563 | 1(Win) |
| glaze | 2039.48 | 0.763624 | 72.2454ms | 631514 | 30 | 1.52548e+08 | 295300 | 2(Loss) |
