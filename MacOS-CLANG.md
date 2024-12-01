# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.4 compiler).  

Latest Results: (Dec 02, 2024)
#### Using the following commits:
----
| Jsonifier: [c68f3d5](https://github.com/RealTimeChris/Jsonifier/commit/c68f3d5)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [3f87f95](https://github.com/simdjson/simdjson/commit/3f87f95)  

 > 100 iterations on a (Apple M1 (Virtual)).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1340.89 | 34.5202 | 2078548 | 1.47832e+08 | 1392.99 | 46.3994 | 2078548 | 1.42302e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1130.42 | 31.5818 | 2078548 | 1.75355e+08 | 1365.32 | 44.3647 | 2078548 | 1.45187e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 477.825 | 41.6817 | 2078548 | 4.1485e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1557.5 | 12.2458 | 1610126 | 9.85898e+07 | 2027.12 | 17.5958 | 1610126 | 7.57496e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1376.48 | 12.1737 | 1610126 | 1.11555e+08 | 1462.94 | 32.8688 | 1610126 | 1.04962e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 507.595 | 24.2785 | 1610126 | 3.02512e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5982.7 | 3.82237 | 84132 | 1.65666e+07 | 3902.52 | 4.95467 | 84132 | 1.76813e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4220.41 | 5.83203 | 84132 | 4.69684e+07 | 3406.92 | 6.05267 | 84132 | 2.35504e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3266.8 | 5.795 | 84132 | 6.06788e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 6216.83 | 3.86184 | 64259 | 1.23498e+07 | 3968.71 | 9.59964 | 64259 | 1.54413e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3575.57 | 12.0972 | 64259 | 4.29452e+07 | 3099.16 | 7.28646 | 64259 | 1.97738e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3145.13 | 3.41739 | 64259 | 2.44113e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

  This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

  In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2025.44 | 4.99977 | 2078548 | 6.4593e+07 | 2686.87 | 0.949722 | 2078548 | 3.68878e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1462.72 | 16.4724 | 2078548 | 1.35519e+08 | 2334.36 | 9.76911 | 2078548 | 8.49164e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 397.279 | 14.2897 | 2078548 | 4.98958e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1422.72 | 16.3808 | 1610126 | 1.0793e+08 | 2069.33 | 14.2854 | 1610126 | 7.42045e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1343.29 | 14.5353 | 1610126 | 1.14311e+08 | 1995.05 | 7.91563 | 1610126 | 7.69675e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 328.125 | 13.4903 | 1610126 | 4.67973e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2146.08 | 20.1641 | 138774 | 5.26079e+06 | 3615.86 | 5.05794 | 138774 | 3.66013e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 950.149 | 21.4529 | 138482 | 1.18824e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 848.455 | 38.6584 | 138774 | 1.33066e+07 | 2536.44 | 23.8177 | 138774 | 5.21775e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1587.9 | 22.5211 | 69037 | 4.14629e+06 | 3832.76 | 10.2567 | 69037 | 1.71779e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1100.53 | 4.99914 | 69037 | 4.90563e+06 | 2751.69 | 2.82822 | 69037 | 1.19634e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 710.974 | 4.97143 | 68745 | 5.09320e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 878.134 | 18.3827 | 6661897 | 2.44469e+08 | 1926.37 | 17.2646 | 6661897 | 3.29806e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 869.382 | 17.0482 | 6661897 | 2.4693e+08 | 1960.26 | 12.8419 | 6661897 | 3.24104e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 349.831 | 11.8918 | 6661897 | 6.13658e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1047.3 | 13.704 | 2090234 | 1.90338e+08 | 883.216 | 6.62681 | 2090234 | 2.25698e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 894.385 | 27.8759 | 2090234 | 2.2288e+08 | 842.715 | 10.7606 | 2090234 | 2.36545e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 310.341 | 18.934 | 2090234 | 6.42326e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 3322.87 | 6.33869 | 1439562 | 4.95714e+07 | 3979.59 | 3.6293 | 1439562 | 1.72489e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2184.97 | 4.9632 | 1439584 | 4.44786e+07 | 3147.78 | 16.838 | 1439584 | 4.36146e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1779.67 | 4.08485 | 1423437 | 4.62779e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2574.71 | 7.85753 | 500299 | 1.85311e+07 | 3334.77 | 3.69247 | 500299 | 7.15375e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1515.16 | 4.46711 | 500299 | 1.5745e+07 | 2196.8 | 3.77056 | 500299 | 1.08595e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 639.787 | 9.15757 | 492910 | 7.45752e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2416.68 | 26.9355 | 719139 | 2.49209e+07 | 4201.51 | 9.81659 | 719139 | 1.63233e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1105.05 | 39.4882 | 719139 | 5.45004e+07 | 3379.67 | 14.9528 | 719139 | 2.02926e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1084.4 | 11.2847 | 723784 | 5.55382e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2429.28 | 18.824 | 477706 | 1.83295e+07 | 4954.47 | 10.506 | 477706 | 9.19525e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1708.7 | 12.9711 | 477706 | 2.60594e+07 | 2439.38 | 34.4743 | 477706 | 1.86759e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 752.763 | 14.8735 | 479183 | 5.91522e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1258.39 | 13.9456 | 466906 | 3.53846e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 720.101 | 23.4672 | 466906 | 8.36353e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 683.196 | 40.9927 | 466906 | 6.51755e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1895.95 | 7.51269 | 699405 | 3.51805e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1182.11 | 22.4041 | 699405 | 5.64249e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2144.43 | 26.6656 | 631514 | 2.80848e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1652.46 | 11.4563 | 631514 | 3.64462e+07 | 