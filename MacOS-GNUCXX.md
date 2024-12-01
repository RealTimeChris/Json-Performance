# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Dec 02, 2024)
#### Using the following commits:
----
| Jsonifier: [c68f3d5](https://github.com/RealTimeChris/Jsonifier/commit/c68f3d5)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [3f87f95](https://github.com/simdjson/simdjson/commit/3f87f95)  

 > 100 iterations on a (Apple M1 (Virtual)).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1424.15 | 25.6902 | 2062266 | 1.38099e+08 | 1692.99 | 36.9168 | 2062266 | 1.16169e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1213.58 | 27.1256 | 2062266 | 1.6206e+08 | 1660.98 | 34.7171 | 2062266 | 1.18408e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 688.229 | 19.6358 | 2062266 | 2.85767e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1495.24 | 7.38062 | 1579248 | 1.00726e+08 | 2369.13 | 3.17964 | 1579248 | 3.17857e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1371 | 9.48927 | 1579248 | 1.09853e+08 | 2168.03 | 5.87983 | 1579248 | 6.9468e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 472.646 | 30.0656 | 1579248 | 3.1865e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 4967.59 | 3.76662 | 83724 | 1.97956e+07 | 3877.88 | 6.3088 | 83724 | 2.059e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4609.13 | 2.53768 | 83724 | 2.13352e+07 | 3197.39 | 8.56578 | 83724 | 2.49720e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3252.98 | 9.06422 | 83724 | 6.04594e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 4207.31 | 14.5528 | 63592 | 3.5797e+07 | 2091.13 | 50.7235 | 63592 | 2.90016e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3874.26 | 2.64513 | 63592 | 1.94371e+07 | 3082.72 | 5.32671 | 63592 | 1.96729e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 2682.76 | 17.5046 | 63592 | 5.61395e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

  This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

  In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1677.14 | 12.1482 | 2062266 | 1.17267e+08 | 2273.68 | 14.205 | 2062266 | 8.64998e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1232.35 | 25.9023 | 2062266 | 1.59592e+08 | 1562.64 | 36.4667 | 2062266 | 1.25859e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 323.242 | 28.4747 | 2062266 | 6.08439e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1377.64 | 10.9031 | 1579248 | 1.09324e+08 | 2274.49 | 5.22898 | 1579248 | 6.62165e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1277.6 | 15.7008 | 1579248 | 1.17884e+08 | 2097.23 | 4.99094 | 1579248 | 5.17056e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 305.172 | 9.37331 | 1579248 | 4.93522e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2014.02 | 17.4205 | 138774 | 5.60575e+06 | 3622.8 | 4.9908 | 138774 | 2.59372e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1337.5 | 9.07656 | 138774 | 8.44117e+06 | 1771.68 | 45.2265 | 138774 | 7.47004e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 905.23 | 27.9388 | 138482 | 1.2472e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1109.8 | 4.97224 | 69037 | 5.16126e+06 | 2584.9 | 8.22716 | 69037 | 2.54705e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 970.858 | 46.1152 | 69037 | 6.78151e+06 | 3145.16 | 28.1435 | 69037 | 2.09334e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 669.437 | 14.082 | 68745 | 9.83496e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1006.29 | 9.82098 | 6661897 | 2.13335e+08 | 1793.77 | 17.0868 | 6661897 | 3.54186e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 894.386 | 13.7355 | 6661897 | 2.40027e+08 | 1810.26 | 13.7697 | 6661897 | 3.5096e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 332.475 | 11.8963 | 6661897 | 6.45693e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1163.41 | 11.9664 | 2090234 | 1.71341e+08 | 850.15 | 2.5596 | 2090234 | 1.17238e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1004.02 | 15.2952 | 2090234 | 1.98542e+08 | 762.34 | 17.4474 | 2090234 | 2.61485e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 331.951 | 12.4593 | 2090234 | 6.00511e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 3586.94 | 4.49375 | 1439562 | 2.2961e+07 | 4057.36 | 5.32938 | 1439562 | 3.38366e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1884.83 | 13.8172 | 1439584 | 8.73918e+07 | 3753.57 | 4.946 | 1439584 | 3.10894e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1795.11 | 4.45191 | 1423437 | 4.588e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1609.23 | 33.7949 | 500299 | 2.96491e+07 | 3110.6 | 4.78787 | 500299 | 7.6693e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1320.64 | 4.14906 | 500299 | 1.80641e+07 | 2020.96 | 4.97808 | 500299 | 1.20404e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 682.262 | 5.48012 | 492910 | 6.99324e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1755.89 | 8.67181 | 719139 | 3.42994e+07 | 3417.06 | 14.1781 | 719139 | 2.00706e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 931.946 | 20.5142 | 723784 | 6.46238e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 749.294 | 76.3302 | 719139 | 8.03768e+07 | 3426.36 | 25.1648 | 719139 | 2.00161e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2015.75 | 30.134 | 477706 | 2.20899e+07 | 3438.88 | 37.8198 | 477706 | 1.32478e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1573.27 | 20.9735 | 477706 | 2.83027e+07 | 3809.88 | 8.32305 | 477706 | 1.19578e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 647.968 | 27.8278 | 479183 | 6.87188e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1453.68 | 4.95745 | 466906 | 2.2667e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 908.34 | 7.87897 | 466906 | 6.63032e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 890.65 | 7.04806 | 466906 | 4.99945e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1340.02 | 33.9116 | 699405 | 4.97756e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1009.84 | 27.5179 | 699405 | 6.60508e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1908.11 | 3.92282 | 631514 | 1.57816e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1728.6 | 4.99661 | 631514 | 2.50854e+07 | 