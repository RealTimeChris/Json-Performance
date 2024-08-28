# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Nov 12, 2024)
#### Using the following commits:
----
| Jsonifier: [f34dc2e](https://github.com/RealTimeChris/Jsonifier/commit/f34dc2e)  
| Glaze: [952e960](https://github.com/stephenberry/glaze/commit/952e960)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2015.66 | 1.21322e+06 | 2091602 | 2.53756e+06 | 98 | 2354.83 | 1.03847e+06 | 2091602 | 2.17207e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1529.64 | 1.59869e+06 | 2091602 | 3.34383e+06 | 98 | 2175 | 1.12433e+06 | 2091602 | 2.35166e+06 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1095.5 | 2.95947e+06 | 2091602 | 6.19004e+06 | 94 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1707.8 | 1.43191e+06 | 1617824 | 2.31658e+06 | 99 | 2091.39 | 1.16928e+06 | 1617824 | 1.89169e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1419.11 | 1.72321e+06 | 1617824 | 2.78786e+06 | 98 | 1913.68 | 1.27786e+06 | 1617824 | 2.06736e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 657.559 | 3.71894e+06 | 1617824 | 6.01659e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2015.38 | 1.21338e+06 | 2091602 | 2.53791e+06 | 96 | 2336.94 | 1.04642e+06 | 2091602 | 2.1887e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1531.4 | 1.59686e+06 | 2091602 | 3.33999e+06 | 98 | 2147.96 | 1.13849e+06 | 2091602 | 2.38126e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 430.193 | 5.68448e+06 | 2091602 | 1.18897e+07 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1705.96 | 1.43346e+06 | 1617824 | 2.31908e+06 | 98 | 2075.06 | 1.17848e+06 | 1617824 | 1.90658e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1418 | 1.72455e+06 | 1617824 | 2.79002e+06 | 98 | 1904.02 | 1.28435e+06 | 1617824 | 2.07784e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 340.842 | 7.17465e+06 | 1617824 | 1.16073e+07 | 98 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3196.35 | 1.01408e+06 | 138774 | 140728 | 98 | 3670.87 | 882997 | 138774 | 122537 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1776.86 | 1.37626e+06 | 138774 | 190990 | 202 | 2125.11 | 1.15073e+06 | 138774 | 159691 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 812.839 | 3.0085e+06 | 138482 | 416622 | 161 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2187.76 | 1.4701e+06 | 69037 | 101491 | 171 | 2786.84 | 1.15408e+06 | 69037 | 79674 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2004.38 | 1.61648e+06 | 69037 | 111597 | 160 | 1944.4 | 1.66635e+06 | 69037 | 115040 | 178 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 554.579 | 5.8774e+06 | 68745 | 404042 | 96 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3051.37 | 801418 | 6661897 | 5.33897e+06 | 97 | 1644.08 | 1.48741e+06 | 6661897 | 9.909e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2292.57 | 1.06667e+06 | 6661897 | 7.10607e+06 | 98 | 1619.71 | 1.50979e+06 | 6661897 | 1.00581e+07 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 981.417 | 3.2776e+06 | 6661897 | 2.18351e+07 | 263 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1030.01 | 2.37417e+06 | 2090234 | 4.96257e+06 | 99 | 635.302 | 3.84923e+06 | 2090234 | 8.04579e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 845.916 | 2.89086e+06 | 2090234 | 6.04257e+06 | 99 | 599.074 | 4.082e+06 | 2090234 | 8.53235e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 236.936 | 1.0321e+07 | 2090234 | 2.15734e+07 | 98 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3497.1 | 699271 | 1439562 | 1.00664e+06 | 98 | 3361.3 | 727523 | 1439562 | 1.04731e+06 | 166 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2553.55 | 957657 | 1439584 | 1.37863e+06 | 98 | 2499.49 | 978369 | 1439584 | 1.40844e+06 | 192 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1439.79 | 2.25203e+06 | 1426596 | 3.21273e+06 | 97 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2965.9 | 1.09371e+06 | 500299 | 547183 | 162 | 3048.34 | 1.06413e+06 | 500299 | 532385 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2433.89 | 1.33257e+06 | 500299 | 666682 | 203 | 2193.25 | 1.47877e+06 | 500299 | 739826 | 179 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 522.873 | 6.2026e+06 | 496069 | 3.07692e+06 | 97 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3256.78 | 995629 | 719107 | 715964 | 99 | 4578.04 | 708282 | 719107 | 509330 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2491.15 | 1.30181e+06 | 719139 | 936182 | 98 | 3463.11 | 936441 | 719139 | 673432 | 158 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1381.87 | 2.34719e+06 | 748730 | 1.75741e+06 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2945.75 | 1.10087e+06 | 477674 | 525856 | 187 | 4384.61 | 739605 | 477674 | 353290 | 162 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2396.59 | 1.35295e+06 | 477706 | 646310 | 181 | 3433.93 | 944241 | 477706 | 451070 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 977.051 | 3.3195e+06 | 514743 | 1.70869e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 962.184 | 3.37138e+06 | 69037 | 232750 | 298 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 927.172 | 3.49807e+06 | 69037 | 241496 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 536.199 | 6.05056e+06 | 69037 | 417712 | 97 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3002.21 | 1.07989e+06 | 2091602 | 2.2587e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2606.73 | 1.24441e+06 | 2091602 | 2.60282e+06 | 97 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 4720.89 | 687291 | 118385 | 81365 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2281.61 | 1.42176e+06 | 118385 | 168315 | 98 | 