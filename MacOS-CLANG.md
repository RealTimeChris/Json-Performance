# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.4 compiler).  

Latest Results: (Dec 09, 2024)
#### Using the following commits:
----
| Jsonifier: [f8a6ebe](https://github.com/RealTimeChris/Jsonifier/commit/f8a6ebe)  
| Glaze: [57311d9](https://github.com/stephenberry/glaze/commit/57311d9)  
| Simdjson: [6bbcbfb](https://github.com/simdjson/simdjson/commit/6bbcbfb)  

 > 100 iterations on a (Apple M1 (Virtual)).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1978.63 | 2.13916 | 2185644 | 2.1069e+07 | 2811.14 | 0.699012 | 2185644 | 1.48295e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1712.5 | 0.773136 | 2185644 | 2.43432e+07 | 2621.33 | 0.806957 | 2185644 | 1.59033e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 811.257 | 12.3769 | 2185644 | 5.13868e+07 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1654.78 | 0.580405 | 1676721 | 1.93263e+07 | 2304.6 | 0.470714 | 1676721 | 1.3877e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1604.99 | 0.757176 | 1676721 | 1.99259e+07 | 2538.34 | 3.1215 | 1676721 | 1.25991e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 802.151 | 1.27868 | 1676721 | 3.9869e+07 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 5131.05 | 1.75965 | 75518 | 8.12462e+06 | 4286.88 | 3.52381 | 75518 | 336000 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4846.84 | 0.583662 | 75518 | 8.60104e+06 | 3469.08 | 1.25455 | 75518 | 415209 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3664.35 | 2.3433 | 75518 | 1.13766e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 5101.91 | 1.95547 | 58664 | 6.26842e+06 | 4584.17 | 2.00955 | 58664 | 244085 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4251.79 | 0.477442 | 58664 | 7.52175e+06 | 3263.78 | 2.77454 | 58664 | 342832 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3499.71 | 1.42991 | 58664 | 9.13817e+06 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1982.96 | 0.989383 | 2185644 | 2.1023e+07 | 2805.59 | 0.721555 | 2185644 | 1.48589e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1717.25 | 3.76989 | 2185644 | 2.4276e+07 | 2532.72 | 3.41566 | 2185644 | 1.64597e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 455.714 | 1.48186 | 2185644 | 9.14781e+07 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1591.93 | 3.89606 | 1676721 | 2.00894e+07 | 2162.83 | 2.90753 | 1676721 | 1.47866e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1451.04 | 3.11534 | 1676721 | 2.204e+07 | 2341 | 3.30283 | 1676721 | 1.36612e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 353.52 | 2.75979 | 1676721 | 9.04641e+07 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 2048.78 | 1.93154 | 138774 | 1.10213e+06 | 4113.83 | 0.661469 | 138774 | 643416 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1541.26 | 2.56239 | 138774 | 1.46504e+06 | 3171.52 | 5.44054 | 138774 | 834586 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1210.11 | 2.41801 | 138482 | 1.86596e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1558.7 | 1.25818 | 69037 | 844789 | 4378.31 | 3.5744 | 69037 | 300750 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1515.65 | 2.16267 | 69037 | 868789 | 2929.68 | 0.618741 | 69037 | 449461 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 779.272 | 2.40106 | 68745 | 1.68975e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1385.24 | 0.39832 | 6661897 | 4.3382e+07 | 2304.39 | 0.939571 | 6661897 | 5.51406e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1330.58 | 1.18059 | 6661897 | 4.5164e+07 | 2176.98 | 1.78961 | 6661897 | 5.83679e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 511.373 | 2.57138 | 6661897 | 1.17516e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1263.37 | 1.82539 | 2090234 | 3.15569e+07 | 916.017 | 2.67459 | 2090234 | 4.35232e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1098.22 | 2.63699 | 2090234 | 3.63023e+07 | 937.816 | 0.923099 | 2090234 | 4.25116e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 370.025 | 3.05817 | 2090234 | 1.07744e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 2718.02 | 1.01247 | 1439562 | 8.0835e+06 | 4467.84 | 0.294228 | 1439562 | 6.14558e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2087.97 | 1.15035 | 1439584 | 1.05227e+07 | 4041.22 | 0.200428 | 1439584 | 6.79446e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1480.51 | 1.8433 | 1423437 | 1.48402e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1705.44 | 1.50938 | 500299 | 5.59529e+06 | 3135.39 | 0.879952 | 500299 | 3.04346e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1379.35 | 3.04396 | 500299 | 6.91808e+06 | 2219.09 | 2.21312 | 500299 | 4.30017e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 680.289 | 3.07419 | 492910 | 1.4027e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 2792.57 | 0.984236 | 719139 | 4.31329e+06 | 4839.97 | 1.34654 | 719139 | 2.834e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2030.33 | 1.65967 | 719139 | 5.93262e+06 | 4029.82 | 0.918105 | 719139 | 3.40375e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1153.92 | 1.57415 | 723784 | 1.04385e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 2492.86 | 3.89311 | 477706 | 3.57242e+06 | 5931.5 | 1.15778 | 477706 | 1.53612e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2141.31 | 2.15823 | 477706 | 4.15892e+06 | 4044.55 | 2.01044 | 477706 | 2.25279e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 908.376 | 2.55462 | 479183 | 9.80379e+06 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1516.11 | 0.719333 | 466906 | 5.87391e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1265.44 | 2.07233 | 466906 | 7.0375e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 878.301 | 5.53566 | 466906 | 1.37142e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2090.27 | 1.58511 | 699405 | 6.382e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 1582.82 | 1.14361 | 699405 | 8.42804e+06 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f8a6ebe) | 3327.13 | 2.49403 | 631514 | 3.62029e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1909.03 | 1.9349 | 631514 | 6.30958e+06 | 