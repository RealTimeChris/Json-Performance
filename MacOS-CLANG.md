# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.4 compiler).  

Latest Results: (Dec 01, 2024)
#### Using the following commits:
----
| Jsonifier: [2da8dd0](https://github.com/RealTimeChris/Jsonifier/commit/2da8dd0)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [cab383e](https://github.com/simdjson/simdjson/commit/cab383e)  

 > 100 iterations on a (Apple M1 (Virtual)).


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2218.67 | 4.99835 | 2124722 | 9.61343e+07 | 2829.52 | 1.743 | 2124722 | 7.28827e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1657.27 | 3.84392 | 2124722 | 1.27154e+08 | 2626.01 | 1.422 | 2124722 | 7.82752e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 927.277 | 2.75157 | 2124722 | 2.24704e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1712.95 | 4.35124 | 1646556 | 9.58411e+07 | 2452.28 | 4.022 | 1646556 | 6.67168e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1566.1 | 3.24739 | 1646556 | 1.03632e+08 | 2192.49 | 3.534 | 1646556 | 7.42447e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 709.503 | 4.39885 | 1646556 | 2.31504e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5540.1 | 4.10456 | 96558 | 3.81405e+07 | 3932.56 | 2.228 | 96558 | 2.39496e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4422.21 | 0.603322 | 96558 | 4.60989e+07 | 3231.05 | 2.577 | 96558 | 2.92538e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3423.27 | 4.53176 | 96558 | 6.20015e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5933.03 | 2.47485 | 72657 | 2.71383e+07 | 4106.14 | 4.733 | 72657 | 1.77133e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3930.61 | 2.38172 | 72657 | 4.09247e+07 | 3001.82 | 4.279 | 72657 | 2.41149e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3181.92 | 4.19484 | 72657 | 5.15108e+07 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2211.51 | 2.26054 | 2124722 | 9.37441e+07 | 2583.18 | 4.362 | 2124722 | 8.20198e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1655.41 | 3.8708 | 2124722 | 1.27333e+08 | 2548.93 | 3.359 | 2124722 | 8.2259e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 425.979 | 3.91912 | 2124722 | 4.95082e+08 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1797.69 | 4.77319 | 1646556 | 9.17284e+07 | 2614.22 | 4.086 | 1646556 | 6.26257e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1576.58 | 2.72321 | 1646556 | 1.02388e+08 | 2384.93 | 3.085 | 1646556 | 6.79377e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 358.238 | 4.53884 | 1646556 | 4.59175e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2834.35 | 3.6375 | 138774 | 4.13366e+06 | 3960.53 | 4.214 | 138774 | 3.48862e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1447.45 | 2.47512 | 138774 | 7.99796e+06 | 3456.21 | 1.883 | 138774 | 3.9027e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1351.42 | 4.1546 | 138482 | 8.71633e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2073.66 | 1.34166 | 69037 | 3.21818e+06 | 4270.53 | 3.561 | 69037 | 1.59863e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1154.22 | 3.34944 | 69037 | 5.90188e+06 | 2857.34 | 1.705 | 69037 | 2.34417e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 808.255 | 3.3981 | 68745 | 8.43234e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1049.23 | 3.4258 | 6661897 | 2.11862e+08 | 2176.09 | 3.898 | 6661897 | 3.03801e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1035.73 | 3.0136 | 6661897 | 2.13711e+08 | 2147.22 | 2.851 | 6661897 | 3.04566e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 354.596 | 4.06191 | 6661897 | 6.31045e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1234.24 | 2.44584 | 2090234 | 1.65558e+08 | 879.168 | 4.973 | 2090234 | 2.38604e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1187.49 | 3.57588 | 2090234 | 1.74092e+08 | 878.038 | 1.919 | 2090234 | 2.3147e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 363.191 | 4.6983 | 2090234 | 5.75917e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3611.27 | 4.40403 | 1439562 | 4.77138e+07 | 4080.37 | 2.401 | 1439562 | 3.44736e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2492.12 | 4.66542 | 1439584 | 6.93305e+07 | 3844.75 | 1.171 | 1439584 | 3.61313e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 2049.27 | 2.10904 | 1423437 | 8.2111e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2595.41 | 4.46095 | 500299 | 1.92417e+07 | 3326.82 | 4.426 | 500299 | 1.50059e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1584.69 | 3.30017 | 500299 | 3.11358e+07 | 2272.91 | 1.691 | 500299 | 2.13527e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 756.837 | 3.97879 | 492910 | 6.56538e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3317.46 | 4.48322 | 719139 | 1.90063e+07 | 4848.22 | 4.032 | 719139 | 1.47403e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1985.47 | 2.93421 | 719139 | 3.12502e+07 | 4303.21 | 4.981 | 719139 | 1.67729e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1316.29 | 4.59106 | 659630 | 4.79559e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3054.21 | 2.26081 | 477706 | 1.49163e+07 | 5578.46 | 4.045 | 477706 | 8.51100e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1955.83 | 2.99786 | 477706 | 2.34702e+07 | 4104.29 | 2.642 | 477706 | 1.14013e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 956.982 | 4.34226 | 425643 | 4.86413e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |   
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 844.648 | 3.877 | 69037 | 1.39057e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 802.511 | 3.745 | 69037 | 8.52329e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 663.083 | 3.068 | 69037 | 1.02435e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2283.25 | 2.481 | 2124722 | 9.10033e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1960.45 | 3.294 | 2124722 | 1.06879e+08 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2217.35 | 4.57767 | 118385 | 5.33596e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1980.71 | 4.85589 | 118385 | 5.99091e+06 | 