# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Dec 01, 2024)
#### Using the following commits:
----
| Jsonifier: [2da8dd0](https://github.com/RealTimeChris/Jsonifier/commit/2da8dd0)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [cab383e](https://github.com/simdjson/simdjson/commit/cab383e)  

 > 100 iterations on a ().


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1886.19 | 4.59524 | 5.29963e+07 | 2082789 | 1.1038e+08 | 2258.39 | 3.332 | 4.36836e+07 | 2082789 | 9.09836e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1441.88 | 0.666573 | 6.65847e+07 | 2082789 | 1.38682e+08 | 2110.1 | 4.575 | 4.73625e+07 | 2082789 | 9.86461e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 801.432 | 3.25773 | 1.23003e+08 | 2082789 | 2.5619e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1597.16 | 1.55374 | 6.06529e+07 | 1605615 | 9.73852e+07 | 2026.21 | 0.8814 | 4.74854e+07 | 1605615 | 7.62432e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1355.5 | 1.83077 | 7.16677e+07 | 1605615 | 1.15071e+08 | 1817.48 | 0.8786 | 5.29375e+07 | 1605615 | 8.49972e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 627.934 | 2.29081 | 1.55436e+08 | 1605615 | 2.4957e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5603.71 | 1.41239 | 4.47239e+08 | 80391 | 3.5954e+07 | 3428.6 | 2.368 | 2.84899e+07 | 80391 | 2.29033e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4400.87 | 0.793155 | 5.65923e+08 | 80391 | 4.54951e+07 | 3063.36 | 4.202 | 3.24971e+07 | 80391 | 2.61248e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3326.44 | 2.07068 | 7.58482e+08 | 80391 | 6.09751e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5926.91 | 1.69311 | 4.25075e+08 | 61825 | 2.62803e+07 | 3214.18 | 3.382 | 3.07095e+07 | 61825 | 1.89861e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3969.81 | 1.09874 | 6.30821e+08 | 61825 | 3.90005e+07 | 2715.84 | 2.636 | 3.60659e+07 | 61825 | 2.22977e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 2941.78 | 1.56288 | 8.55281e+08 | 61825 | 5.28777e+07 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1882.71 | 1.97426 | 5.16744e+07 | 2082789 | 1.07627e+08 | 2247.63 | 1.026 | 4.28698e+07 | 2082789 | 8.92888e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1438.79 | 1.11038 | 6.70275e+07 | 2082789 | 1.39604e+08 | 2102.45 | 0.9073 | 4.57754e+07 | 2082789 | 9.53405e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 416.099 | 1.68396 | 2.3312e+08 | 2082789 | 4.85539e+08 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1571.59 | 1.67794 | 6.17177e+07 | 1605615 | 9.90949e+07 | 2024.63 | 0.9818 | 4.75707e+07 | 1605615 | 7.63802e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1355.08 | 1.60998 | 7.15291e+07 | 1605615 | 1.14848e+08 | 1815.51 | 1.289 | 5.32149e+07 | 1605615 | 8.54427e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 326.941 | 2.10197 | 2.97959e+08 | 1605615 | 4.78407e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2194.51 | 0.948161 | 3.74274e+07 | 138774 | 5.19395e+06 | 2785.1 | 1.672 | 3.48242e+07 | 138774 | 4.83269e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1267.02 | 3.13961 | 6.62914e+07 | 138774 | 9.19953e+06 | 2032.27 | 3.754 | 4.87568e+07 | 138774 | 6.76618e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 670.974 | 1.89305 | 1.23851e+08 | 138482 | 1.71511e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1893.28 | 1.06413 | 5.09133e+07 | 69037 | 3.5149e+06 | 2006.61 | 1.735 | 4.8366e+07 | 69037 | 3.33905e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1299.26 | 0.937936 | 7.40962e+07 | 69037 | 5.11538e+06 | 1423.67 | 2.936 | 6.90132e+07 | 69037 | 4.76446e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 400.119 | 2.45945 | 2.45395e+08 | 68745 | 1.68697e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 865.392 | 1.58287 | 3.78359e+07 | 6661897 | 2.52059e+08 | 1561.04 | 1.015 | 6.17187e+07 | 6661897 | 4.11164e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 821.956 | 1.58879 | 3.98377e+07 | 6661897 | 2.65395e+08 | 1563.73 | 1.614 | 6.19877e+07 | 6661897 | 4.12956e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 263.56 | 4.35534 | 1.27834e+08 | 6661897 | 8.5162e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 961.214 | 2.80162 | 1.02075e+08 | 2090234 | 2.13361e+08 | 601.527 | 0.898 | 1.59979e+08 | 2090234 | 3.34393e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 902.892 | 1.68277 | 1.07432e+08 | 2090234 | 2.24559e+08 | 581.697 | 1.371 | 1.66227e+08 | 2090234 | 3.47453e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 240.765 | 2.00829 | 4.04219e+08 | 2090234 | 8.44912e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3232.17 | 1.70557 | 3.60155e+07 | 1439562 | 5.18466e+07 | 3283.66 | 1.385 | 2.9451e+07 | 1439562 | 4.23966e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2164.13 | 1.24083 | 5.3536e+07 | 1439584 | 7.70696e+07 | 2491.28 | 4.571 | 4.0114e+07 | 1439584 | 5.77475e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1198.59 | 0.980316 | 9.75017e+07 | 1423437 | 1.38788e+08 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2174.47 | 3.00622 | 4.52171e+07 | 500299 | 2.26221e+07 | 2142.48 | 0.7524 | 4.485e+07 | 500299 | 2.24384e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1450.78 | 1.96868 | 6.70556e+07 | 500299 | 3.35478e+07 | 1610.52 | 1.565 | 6.01568e+07 | 500299 | 3.00964e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 384.053 | 0.982414 | 2.54541e+08 | 492910 | 1.25466e+08 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2614.07 | 3.03443 | 3.30411e+07 | 719107 | 2.37601e+07 | 3498.29 | 1.23 | 2.76007e+07 | 719107 | 1.98478e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1323.93 | 3.02743 | 6.52312e+07 | 719139 | 4.69103e+07 | 2504.09 | 2.759 | 3.91654e+07 | 719139 | 2.81654e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 822.884 | 2.35043 | 1.13625e+08 | 659630 | 7.49505e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2659.11 | 4.18959 | 3.65888e+07 | 477674 | 1.74775e+07 | 3113.48 | 2.037 | 3.12674e+07 | 477674 | 1.49356e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1361.11 | 3.50594 | 7.097e+07 | 477706 | 3.39028e+07 | 2519.25 | 1.823 | 3.85585e+07 | 477706 | 1.84196e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 622.54 | 1.4498 | 1.70514e+08 | 425643 | 7.25779e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 713.839 | 2.79 | 1.37433e+08 | 69037 | 9.48796e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 687.635 | 1.424 | 2.41261e+08 | 69037 | 1.6656e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 661.856 | 2.789 | 1.48226e+08 | 69037 | 1.0233e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2073.78 | 3.548 | 4.76791e+07 | 2082789 | 9.93055e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1956.38 | 2.05 | 4.97674e+07 | 2082789 | 1.03655e+08 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-CLANG/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3468.43 | 4.3399 | 2.87433e+07 | 118385 | 3.40278e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1549.62 | 4.67946 | 6.45637e+07 | 118385 | 7.64337e+06 | 