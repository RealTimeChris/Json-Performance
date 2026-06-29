# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.6.87.2-microsoft-standard-WSL2 using the GCC 16.0.1 compiler).  

Latest Results: (Jun 29, 2026)
#### Using the following commits:
----
| Jsonifier: [4c33df9](https://github.com/RealTimeChris/Jsonifier/commit/4c33df9)  
| Simdjson (On Demand): [9b33047](https://github.com/simdjson/simdjson/commit/9b33047)  

> Adaptive sampling on (Intel(R) Core(TM) i9-14900KF): iterations begin at 80 and double each epoch (e.g. 80 → 160 → 320 → ...) up to a maximum of 100000 iterations. Each epoch runs all iterations and evaluates a trailing window of max(iterations/10, 30) samples, capped at 100000. Convergence requires RSE < 2.5% AND mean shift < 1% epoch-over-epoch simultaneously. The first epoch satisfying both conditions is retained as the canonical result. If convergence is never reached before 10 seconds elapse or the iteration cap is hit, the result is marked non-converged and excluded from all rankings — only converged results participate in win/tie/loss tallying. All results use Bessel-corrected variance and Welch's t-test for statistical tie detection. Additionally, all tests besides the ABC (Out of Order) test were run with all of the members being parsed in the order in which they came in on the json data.

#### Note:
  These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/realtimechris/benchmarksuite).
  
----
### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2222.04 | 0.432926 | 22.3214ms | 33713 | 64 | 251130 | 14469.2 | 1(Win) |
| jsonifier | 2009.14 | 2.06629 | 16.1299ms | 33713 | 32 | 3.49872e+06 | 16002.5 | 2(Loss) |

----
### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 2715.91 | 0.296954 | 6.16797ms | 49505 | 30 | 79940.5 | 17383.4 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 2647.38 | 1.38908 | 4.76888ms | 49505 | 30 | 1.84094e+06 | 17833.3 | 1(Tie) |

----
### Abc (In Order) Partial Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 7054.94 | 0.172368 | 2.69981ms | 33713 | 30 | 1851.17 | 4557.27 | 1(Win) |
| simdjson | 5209.04 | 0.228989 | 1.94866ms | 33713 | 30 | 5992.79 | 6172.2 | 2(Loss) |

----
### Abc (In Order) Partial Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Abc%20%28In%20Order%29%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8266.12 | 0.158065 | 1.7289ms | 48024 | 30 | 2300.94 | 5540.6 | 1(Win) |
| simdjson | 6595.04 | 0.26878 | 4.52187ms | 48024 | 32 | 11148.8 | 6944.5 | 2(Loss) |

----
### Apache Builds Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1322.25 | 0.872266 | 19.4548ms | 94651 | 30 | 1.06376e+07 | 68267.2 | 1(Win) |
| simdjson | 1270.56 | 0.792997 | 91.5203ms | 94651 | 64 | 2.03133e+07 | 71044.2 | 2(Loss) |

----
### Apache Builds Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Apache%20Builds%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2100.82 | 0.317167 | 177.01ms | 140436 | 128 | 5.23321e+06 | 63751.5 | 1(Win) |
| simdjson | 1896.51 | 1.10418 | 18.2473ms | 140436 | 30 | 1.8241e+07 | 70619.3 | 2(Loss) |

----
### Canada Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Canada%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson **STATISTICAL TIE** | 2041.68 | 1.34916 | 8529.01ms | 6885124 | 128 | 2.40983e+11 | 3.21605e+06 | 1(Tie) |
| jsonifier **STATISTICAL TIE** | 1964.99 | 1.96811 | 4242.61ms | 6885124 | 64 | 2.76809e+11 | 3.34157e+06 | 1(Tie) |

----
### CitmCatalog Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/CitmCatalog%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1399.18 | 1.75317 | 936.642ms | 500299 | 128 | 4.57482e+09 | 341002 | 1(Win) |
| simdjson | 1213.68 | 1.51334 | 101.197ms | 500299 | 30 | 1.06181e+09 | 393122 | 2(Loss) |

----
### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3623.16 | 0.51324 | 108.827ms | 1490030 | 30 | 1.21556e+08 | 392200 | 1(Win) |
| simdjson | 3062.89 | 1.61805 | 1239.98ms | 1490030 | 128 | 7.21308e+09 | 463942 | 2(Loss) |

----
### Discord Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Discord%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1781.43 | 1.0112 | 9.31585ms | 56369 | 30 | 2.79341e+06 | 30176.6 | 1(Win) |
| simdjson | 1339.28 | 0.5309 | 10.2539ms | 56369 | 30 | 1.36235e+06 | 40139.4 | 2(Loss) |

----
### Discord Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Discord%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2923.41 | 0.855343 | 9.39892ms | 98048 | 30 | 2.24543e+06 | 31985.2 | 1(Win) |
| simdjson | 2135.65 | 1.59737 | 60.6912ms | 98048 | 30 | 1.46741e+07 | 43783.4 | 2(Loss) |

----
### Github Events Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Github%20Events%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 1713.23 | 1.24782 | 7.72866ms | 52708 | 30 | 4.02112e+06 | 29340.1 | 1(Win) |
| jsonifier | 1640.06 | 1.30698 | 10.2067ms | 52708 | 30 | 4.81383e+06 | 30649 | 2(Loss) |

----
### Github Events Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Github%20Events%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Github%20Events%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2279.91 | 0.218039 | 7.98342ms | 71665 | 30 | 128164 | 29977 | 1(Win) |
| jsonifier | 2022.91 | 1.8255 | 12.9505ms | 71665 | 30 | 1.14116e+07 | 33785.5 | 2(Loss) |

----
### Google Maps Response Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1614.6 | 0.120244 | 5.20694ms | 11812 | 32 | 2252.14 | 6976.84 | 1(Win) |
| simdjson | 1154.54 | 0.171486 | 6.96479ms | 11812 | 32 | 8958.55 | 9756.97 | 2(Loss) |

----
### Google Maps Response Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Google%20Maps%20Response%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3474.38 | 1.44921 | 13.5696ms | 32403 | 64 | 1.06331e+06 | 8894.22 | 1(Win) |
| simdjson | 2850.41 | 0.0735369 | 3.50951ms | 32403 | 30 | 1906.72 | 10841.2 | 2(Loss) |

----
### Instruments Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Instruments%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 2187.45 | 0.231342 | 17.968ms | 108313 | 30 | 358028 | 47221.9 | 1(Win) |
| simdjson | 1648.17 | 0.612256 | 81.1321ms | 108313 | 64 | 9.42333e+06 | 62672.9 | 2(Loss) |

----
### Instruments Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Instruments%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Instruments%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 3901.01 | 0.978677 | 15.1505ms | 222373 | 30 | 8.492e+06 | 54363.2 | 1(Win) |
| simdjson | 2962.09 | 1.72926 | 417.874ms | 222373 | 256 | 3.92399e+08 | 71595.3 | 2(Loss) |

----
### Marine IK Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Marine%20IK%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Marine%20IK%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 557.259 | 2.46184 | 1866.27ms | 1834197 | 32 | 1.91094e+11 | 3.13899e+06 | 1(Win) |
| jsonifier | 484.869 | 2.06293 | 4436.04ms | 1834197 | 64 | 3.5448e+11 | 3.60762e+06 | 2(Loss) |

----
### Mesh Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Mesh%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1078.86 | 0.435448 | 348.804ms | 642697 | 32 | 1.9584e+08 | 568120 | 1(Win) |
| simdjson | 995.007 | 2.35144 | 1605.34ms | 642697 | 128 | 2.68558e+10 | 615999 | 2(Loss) |

----
### Mesh Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Mesh%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Mesh%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2134.5 | 1.85064 | 199.079ms | 1306201 | 30 | 3.49939e+09 | 583597 | 1(Win) |
| jsonifier | 1963.85 | 1.7843 | 846.8ms | 1306201 | 64 | 8.19825e+09 | 634310 | 2(Loss) |

----
### Random Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Random%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1121.46 | 0.403633 | 90.8173ms | 409725 | 30 | 5.93354e+07 | 348426 | 1(Win) |
| simdjson | 1058.64 | 0.860211 | 143.649ms | 409725 | 30 | 3.02427e+08 | 369101 | 2(Loss) |

----
### Random Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Random%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Random%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier **STATISTICAL TIE** | 1875.31 | 2.19621 | 1087.42ms | 814756 | 128 | 1.05991e+10 | 414338 | 1(Tie) |
| simdjson **STATISTICAL TIE** | 1816.21 | 1.89134 | 1105.05ms | 814756 | 128 | 8.38048e+09 | 427820 | 1(Tie) |

----
### Twitter Partial Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 6732.56 | 0.985759 | 25.7646ms | 264040 | 32 | 4.34981e+06 | 37401.6 | 1(Win) |
| simdjson | 6021.76 | 2.07801 | 26.0046ms | 264040 | 32 | 2.41624e+07 | 41816.4 | 2(Loss) |

----
### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 8305.12 | 0.735104 | 14.9873ms | 399947 | 30 | 3.41926e+06 | 45925.8 | 1(Win) |
| simdjson | 7932.12 | 1.56001 | 30.9919ms | 399947 | 32 | 1.80065e+07 | 48085.4 | 2(Loss) |

----
### Twitter Test (Minified) Results [(View the data used in the following test)](./json/Linux-GCC/Twitter%20Test%20%28Minified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| jsonifier | 1755.83 | 0.910214 | 41.5891ms | 264040 | 30 | 5.1119e+07 | 143413 | 1(Win) |
| simdjson | 1567.22 | 2.38576 | 381.301ms | 264040 | 128 | 1.88081e+09 | 160672 | 2(Loss) |

----
### Twitter Test (Prettified) Results [(View the data used in the following test)](./json/Linux-GCC/Twitter%20Test%20%28Prettified%29.json):

<p align="left"><a href="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="./graphs/Linux-GCC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>

| Library | Throughput (MB/s) | RSE (%) | Window Duration | File Size (Bytes) | Window Samples (k) | Variance | Latency / Run (ns) | Position |
| ------- | ----------- | ------- | --------- | --------------- | -------------------- | ---------- | ---- | -------- |
| simdjson | 2588.52 | 0.84423 | 39.1862ms | 409612 | 30 | 4.8695e+07 | 150911 | 1(Win) |
| jsonifier | 2466.08 | 1.08042 | 43.971ms | 409612 | 30 | 8.78699e+07 | 158404 | 2(Loss) |
