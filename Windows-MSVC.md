# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.42.34433.0 compiler).  

Latest Results: (Dec 01, 2024)
#### Using the following commits:
----
| Jsonifier: [2da8dd0](https://github.com/RealTimeChris/Jsonifier/commit/2da8dd0)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [cab383e](https://github.com/simdjson/simdjson/commit/cab383e)  

 > 100 iterations on a ().


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1655.91 | 3.72574 | 5.98209e+07 | 2087785 | 1.24893e+08 | 1885.3 | 1.458 | 5.13331e+07 | 2087785 | 1.07172e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1199.58 | 1.65197 | 8.08359e+07 | 2087785 | 1.68768e+08 | 1705.7 | 2.135 | 5.71307e+07 | 2087785 | 1.19277e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 371.544 | 3.65638 | 2.6642e+08 | 2087785 | 5.56228e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1406.87 | 3.59905 | 7.03176e+07 | 1609751 | 1.13194e+08 | 1650.37 | 1.814 | 5.88531e+07 | 1609751 | 9.47389e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1088.24 | 3.31453 | 9.06389e+07 | 1609751 | 1.45906e+08 | 1491.77 | 2.517 | 6.55795e+07 | 1609751 | 1.05567e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 290.974 | 1.27356 | 3.31981e+08 | 1609751 | 5.34406e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5197.25 | 3.50685 | 4.3105e+08 | 92106 | 3.97023e+07 | 2753.58 | 2.336 | 3.54624e+07 | 92106 | 3.2663e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3741.9 | 2.31822 | 5.91414e+08 | 92106 | 5.44728e+07 | 2399.98 | 3.77 | 4.12937e+07 | 92106 | 3.8034e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 2095.2 | 1.44202 | 1.04684e+09 | 92106 | 9.64204e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 4783.98 | 2.42286 | 4.62634e+08 | 71086 | 3.28868e+07 | 2510.85 | 1.996 | 3.87559e+07 | 71086 | 2.755e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3659.54 | 1.62627 | 5.99886e+08 | 71086 | 4.26435e+07 | 2222.72 | 2.649 | 4.40734e+07 | 71086 | 3.133e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1786.34 | 1.24495 | 1.2242e+09 | 71086 | 8.70234e+07 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1641.98 | 3.89904 | 6.04372e+07 | 2087785 | 1.2618e+08 | 1887.27 | 1.045 | 5.10656e+07 | 2087785 | 1.06614e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1197.99 | 3.13534 | 8.21826e+07 | 2087785 | 1.7158e+08 | 1695.54 | 3.335 | 5.81865e+07 | 2087785 | 1.21481e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 109.836 | 0.756014 | 8.74889e+08 | 2087785 | 1.82658e+09 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1381.05 | 3.02315 | 7.12069e+07 | 1609751 | 1.14625e+08 | 1646.83 | 0.8947 | 5.84324e+07 | 1609751 | 9.40616e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1089.24 | 2.94652 | 9.0212e+07 | 1609751 | 1.45219e+08 | 1492.93 | 2.118 | 6.52618e+07 | 1609751 | 1.05055e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 85.2825 | 0.815981 | 1.12745e+09 | 1609751 | 1.81492e+09 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1474.24 | 4.33497 | 5.99586e+07 | 138774 | 8.3207e+06 | 2166.04 | 3.143 | 4.54574e+07 | 138774 | 6.3083e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1051.52 | 4.32673 | 8.40554e+07 | 138774 | 1.16647e+07 | 1871.93 | 4.202 | 5.31807e+07 | 138774 | 7.3801e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 311.272 | 1.62103 | 2.76723e+08 | 138482 | 3.83212e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1159.13 | 1.17098 | 8.32496e+07 | 69037 | 5.7473e+06 | 1839.07 | 4.487 | 5.42926e+07 | 69037 | 3.7482e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 864.026 | 2.61234 | 1.13336e+08 | 69037 | 7.8244e+06 | 1301.16 | 4.846 | 7.70268e+07 | 69037 | 5.3177e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 178.813 | 1.79893 | 5.45414e+08 | 68745 | 3.74945e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 510.651 | 2.04597 | 6.44232e+07 | 6661897 | 4.29181e+08 | 1222.87 | 1.777 | 7.93977e+07 | 6661897 | 5.28939e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 363.854 | 1.93385 | 9.03113e+07 | 6661897 | 6.01645e+08 | 1076.75 | 1.854 | 9.02429e+07 | 6661897 | 6.01189e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 158.777 | 3.31527 | 2.09915e+08 | 6661897 | 1.39843e+09 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 493.465 | 2.3283 | 1.97868e+08 | 2090234 | 4.1359e+08 | 448.48 | 0.6478 | 2.14032e+08 | 2090234 | 4.47378e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 344.325 | 1.63463 | 2.81572e+08 | 2090234 | 5.88551e+08 | 422.887 | 1.111 | 2.28048e+08 | 2090234 | 4.76674e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 150.847 | 4.87591 | 6.64618e+08 | 2090234 | 1.38921e+09 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2960.74 | 2.81606 | 4.09286e+07 | 1439562 | 5.89192e+07 | 2613.01 | 3.126 | 3.76748e+07 | 1439562 | 5.42352e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1991.21 | 3.02321 | 6.09858e+07 | 1439584 | 8.77942e+07 | 2295.43 | 4.362 | 4.34419e+07 | 1439584 | 6.25382e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 715.174 | 1.25513 | 1.6865e+08 | 1423437 | 2.40063e+08 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1947.44 | 4.91456 | 5.15018e+07 | 500299 | 2.57663e+07 | 1769.74 | 3.081 | 5.56008e+07 | 500299 | 2.7817e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1225.91 | 3.28873 | 8.04389e+07 | 500299 | 4.02435e+07 | 1295.47 | 4.52 | 7.71011e+07 | 500299 | 3.85736e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 218.273 | 1.23619 | 4.49019e+08 | 492910 | 2.21326e+08 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1634.93 | 4.65363 | 5.50433e+07 | 719107 | 3.9582e+07 | 2624.55 | 2.829 | 3.73947e+07 | 719107 | 2.68908e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 962.443 | 4.33671 | 9.31896e+07 | 719139 | 6.70163e+07 | 2339.1 | 3.449 | 4.22273e+07 | 719139 | 3.03673e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 303.399 | 1.29869 | 3.12366e+08 | 659630 | 2.06046e+08 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1547.71 | 2.5786 | 6.18235e+07 | 477674 | 2.95315e+07 | 2690.76 | 2.258 | 3.62613e+07 | 477674 | 1.73211e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 896.469 | 2.64049 | 1.06796e+08 | 477706 | 5.10171e+07 | 2114.04 | 4.747 | 4.73597e+07 | 477706 | 2.2624e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 223.207 | 1.65218 | 4.76553e+08 | 425643 | 2.02841e+08 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 558.903 | 3.198 | 1.76271e+08 | 69037 | 1.21692e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 530.958 | 3.161 | 1.85477e+08 | 69037 | 1.28048e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 505.599 | 2.619 | 3.45238e+08 | 69037 | 2.38342e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1592.34 | 3.967 | 6.2365e+07 | 2087785 | 1.30205e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1561.25 | 2.93 | 6.29274e+07 | 2087785 | 1.31379e+08 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2305.49 | 1.12089 | 4.18342e+07 | 123050 | 5.1477e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1339.61 | 2.55081 | 7.3054e+07 | 123050 | 8.9893e+06 | 