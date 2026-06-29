# Json-Performance
Performance profiling of JSON libraries (Compiled and run on macOS 24.6.0 using the Clang 22.1.8 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [4c33df9](https://github.com/RealTimeChris/Jsonifier/commit/4c33df9)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Apple M1 (Virtual)): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection. Additionally, all tests besides the ABC (Out of Order) test were run with all of the members being parsed in the order in which they came in on the json data.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1241.83 | 0.118896 | 25.6082ms | 33713 | 30 | 28427.1 | 25890.3 | 1(Win) |
| simdjson | 1074.39 | 0.263854 | 8.25483ms | 33713 | 30 | 187032 | 29925 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](./json/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1582.58 | 1.06619 | 374.632ms | 49505 | 512 | 5.17973e+07 | 29832 | 1(Win) |
| simdjson | 1547.14 | 0.180201 | 11.671ms | 49505 | 30 | 90713.3 | 30515.4 | 2(Loss) |

----
### Abc (In Order) Partial Test (Minified) Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3638.65 | 0.0712749 | 3.78229ms | 33713 | 30 | 1189.9 | 8836.03 | 1(Win) |
| simdjson | 3505.26 | 0.440402 | 3.16913ms | 33713 | 30 | 48952.3 | 9172.27 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Results [(View the data used in the following test)](./json/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 4168.82 | 0.459738 | 4.49725ms | 48024 | 30 | 76530.1 | 10986.1 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 4058.62 | 2.35292 | 14.6597ms | 48024 | 64 | 4.51185e+06 | 11284.4 | 1(Tie) |

----
### Apache Builds Test (Minified) Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 726.676 | 0.180718 | 32.3728ms | 94651 | 30 | 1.5118e+06 | 124218 | 1(Win) |
| simdjson | 670.716 | 1.19432 | 38.7358ms | 94651 | 30 | 7.75066e+07 | 134582 | 2(Loss) |

----
### Apache Builds Test (Prettified) Results [(View the data used in the following test)](./json/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Apache%20Builds%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1073.28 | 0.565754 | 33.0329ms | 140436 | 30 | 1.49523e+07 | 124786 | 1(Win) |
| jsonifier | 1011.6 | 0.304353 | 33.6576ms | 140436 | 30 | 4.87096e+06 | 132394 | 2(Loss) |

----
### Canada Test (Minified) Results [(View the data used in the following test)](./json/Canada%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 424.193 | 0.858302 | 2959.01ms | 2090234 | 32 | 5.20587e+10 | 4.69928e+06 | 1(Win) |
| simdjson | 321.992 | 1.11369 | 1535.2ms | 2090234 | 30 | 1.42609e+11 | 6.19084e+06 | 2(Loss) |

----
### Canada Test (Prettified) Results [(View the data used in the following test)](./json/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1136.04 | 0.695143 | 1329.03ms | 6885124 | 30 | 4.84292e+10 | 5.77988e+06 | 1(Win) |
| simdjson | 956.302 | 1.05762 | 3918.18ms | 6885124 | 32 | 1.68748e+11 | 6.8662e+06 | 2(Loss) |

----
### CitmCatalog Test (Minified) Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 811.889 | 2.01488 | 329.796ms | 500299 | 32 | 4.48657e+09 | 587669 | 1(Win) |
| simdjson | 656.429 | 0.760522 | 182.76ms | 500299 | 30 | 9.16705e+08 | 726846 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](./json/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1914.36 | 2.04872 | 443.623ms | 1490030 | 32 | 7.40045e+09 | 742286 | 1(Win) |
| simdjson | 1628.83 | 1.08809 | 225.066ms | 1490030 | 30 | 2.70328e+09 | 872405 | 2(Loss) |

----
### Discord Test (Minified) Results [(View the data used in the following test)](./json/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1203.16 | 0.668982 | 12.1581ms | 56369 | 30 | 2.68032e+06 | 44680.5 | 1(Win) |
| simdjson | 945.791 | 0.230584 | 15.5084ms | 56369 | 30 | 515311 | 56838.9 | 2(Loss) |

----
### Discord Test (Prettified) Results [(View the data used in the following test)](./json/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1868.92 | 0.992656 | 16.8528ms | 98048 | 30 | 7.39973e+06 | 50032.1 | 1(Win) |
| simdjson | 1534.77 | 0.307375 | 15.8813ms | 98048 | 30 | 1.05208e+06 | 60925 | 2(Loss) |

----
### Github Events Test (Minified) Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1204.18 | 1.29343 | 11.4801ms | 52708 | 30 | 8.74538e+06 | 41743.1 | 1(Win) |
| simdjson | 1167.74 | 0.543753 | 12.1608ms | 52708 | 30 | 1.64356e+06 | 43045.8 | 2(Loss) |

----
### Github Events Test (Prettified) Results [(View the data used in the following test)](./json/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Github%20Events%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1556.15 | 1.38486 | 12.4636ms | 71665 | 30 | 1.10979e+07 | 43919.3 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 1538.54 | 0.357612 | 11.5965ms | 71665 | 30 | 757087 | 44422.2 | 1(Tie) |

----
### Google Maps Response Test (Minified) Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 762.705 | 1.29674 | 22.6164ms | 11812 | 64 | 2.34757e+06 | 14769.5 | 1(Win) |
| simdjson | 686.648 | 0.133918 | 5.07ms | 11812 | 30 | 14480.3 | 16405.5 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Results [(View the data used in the following test)](./json/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Google%20Maps%20Response%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1791.99 | 0.717506 | 5.10321ms | 32403 | 30 | 459275 | 17244.5 | 1(Win) |
| simdjson | 1662.49 | 0.100404 | 5.07179ms | 32403 | 30 | 10449 | 18587.7 | 2(Loss) |

----
### Instruments Test (Minified) Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1510.2 | 0.113159 | 17.8279ms | 108313 | 30 | 179718 | 68398.6 | 1(Win) |
| simdjson | 1049.68 | 0.179686 | 24.213ms | 108313 | 30 | 937992 | 98406.9 | 2(Loss) |

----
### Instruments Test (Prettified) Results [(View the data used in the following test)](./json/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Instruments%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2532.11 | 0.475745 | 22.1109ms | 222373 | 30 | 4.76286e+06 | 83752.8 | 1(Win) |
| simdjson | 1857.58 | 1.25279 | 31.7708ms | 222373 | 30 | 6.13686e+07 | 114165 | 2(Loss) |

----
### Marine IK Test (Minified) Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 350.105 | 1.34258 | 1319.35ms | 1834197 | 30 | 1.34988e+11 | 4.99629e+06 | 1(Win) |
| simdjson | 313.392 | 1.62379 | 1344.6ms | 1834197 | 30 | 2.46432e+11 | 5.5816e+06 | 2(Loss) |

----
### Marine IK Test (Prettified) Results [(View the data used in the following test)](./json/Marine%20IK%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Marine%20IK%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1746.17 | 0.427802 | 1385.26ms | 10252236 | 30 | 1.72135e+10 | 5.59927e+06 | 1(Win) |
| simdjson | 1631.28 | 0.430462 | 1560.88ms | 10252236 | 30 | 1.99696e+10 | 5.99363e+06 | 2(Loss) |

----
### Mesh Test (Minified) Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 619.316 | 1.53896 | 1190.77ms | 642697 | 64 | 1.48465e+10 | 989679 | 1(Win) |
| simdjson | 548.724 | 1.05475 | 1730.97ms | 642697 | 64 | 8.88356e+09 | 1.117e+06 | 2(Loss) |

----
### Mesh Test (Prettified) Results [(View the data used in the following test)](./json/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Mesh%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1278.13 | 0.479228 | 258.858ms | 1306201 | 30 | 6.54448e+08 | 974618 | 1(Win) |
| simdjson | 1199.64 | 0.435446 | 253.831ms | 1306201 | 30 | 6.13351e+08 | 1.03839e+06 | 2(Loss) |

----
### Random Test (Minified) Results [(View the data used in the following test)](./json/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 699.867 | 0.992229 | 159.352ms | 409725 | 30 | 9.20661e+08 | 558312 | 1(Win) |
| simdjson | 648.744 | 0.498595 | 3502.29ms | 409725 | 256 | 2.30874e+09 | 602309 | 2(Loss) |

----
### Random Test (Prettified) Results [(View the data used in the following test)](./json/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Random%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1209 | 0.502916 | 191.395ms | 814756 | 30 | 3.13412e+08 | 642690 | 1(Win) |
| jsonifier | 1099.86 | 2.28676 | 177.491ms | 814756 | 30 | 7.82965e+09 | 706462 | 2(Loss) |

----
### Twitter Partial Test (Minified) Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 3303.37 | 0.400434 | 18.8905ms | 264040 | 30 | 2.79517e+06 | 76227.7 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 3285.35 | 0.516633 | 20.0919ms | 264040 | 30 | 4.70394e+06 | 76645.8 | 1(Tie) |

----
### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](./json/Twitter%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 4231.53 | 0.348585 | 22.359ms | 399947 | 30 | 2.96174e+06 | 90137.3 | 1(Win) |
| jsonifier | 3943.17 | 0.334415 | 24.5326ms | 399947 | 30 | 3.13911e+06 | 96729.1 | 2(Loss) |

----
### Twitter Test (Minified) Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1555.46 | 0.600302 | 40.542ms | 264040 | 30 | 2.83322e+07 | 161886 | 1(Win) |
| simdjson | 1401.54 | 0.584263 | 113.375ms | 264040 | 32 | 3.52611e+07 | 179665 | 2(Loss) |

----
### Twitter Test (Prettified) Results [(View the data used in the following test)](./json/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/macOS-Clang/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1879.99 | 1.92566 | 59.2598ms | 409612 | 30 | 4.80302e+08 | 207786 | 1(Win) |
| simdjson | 1795.49 | 0.968284 | 52.49ms | 409612 | 30 | 1.33139e+08 | 217565 | 2(Loss) |
