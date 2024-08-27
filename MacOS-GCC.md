# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Aug 27, 2024)
#### Using the following commits:
----
| Jsonifier: [39a1062](https://github.com/RealTimeChris/Jsonifier/commit/39a1062)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2417.45 | 1748221 | 723167 | 99 | 2593.48 | 1748221 | 674084 | 184 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2194.06 | 1749990 | 797604 | 97 | 3161.56 | 1749990 | 553521 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1209.26 | 1751859 | 1.44871e+06 | 193 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2247.12 | 1453276 | 646730 | 410 | 2996.58 | 1453276 | 484979 | 218 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2150.65 | 1451507 | 674916 | 216 | 2703.2 | 1451507 | 536958 | 319 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1079.99 | 1455145 | 1.34737e+06 | 167 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2589.16 | 1748221 | 675208 | 498 | 2487.47 | 1748221 | 702812 | 197 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2368.72 | 1749990 | 738792 | 98 | 3311.24 | 1749990 | 528500 | 292 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1294.6 | 1751859 | 1.35321e+06 | 460 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2304.44 | 1451507 | 629875 | 99 | 2805.75 | 1451507 | 517334 | 497 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2300.02 | 1453276 | 631854 | 99 | 3143.35 | 1453276 | 462334 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1125.71 | 1455145 | 1.29265e+06 | 493 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2663.4 | 138774 | 52104 | 98 | 2948.72 | 138774 | 47062.5 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2066.12 | 138774 | 67166.5 | 95 | 3622.16 | 138774 | 38312.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 275.824 | 138774 | 503124 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1648.64 | 69037 | 41875 | 262 | 2911.91 | 69037 | 23708.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1543.43 | 69037 | 44729.5 | 307 | 2373.75 | 69037 | 29083.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 141.336 | 69037 | 488458 | 204 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2628.27 | 6661897 | 2.53471e+06 | 379 | 1823.83 | 6661897 | 3.65269e+06 | 454 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2401.6 | 6661897 | 2.77394e+06 | 182 | 2351.15 | 6661897 | 2.83346e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1973.16 | 6661897 | 3.37625e+06 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1316.94 | 2090234 | 1.58719e+06 | 100 | 1021.31 | 2090234 | 2.04662e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1278.14 | 2090234 | 1.63538e+06 | 98 | 998.967 | 2090234 | 2.0924e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 734.903 | 2090234 | 2.84423e+06 | 100 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 3442.9 | 1439562 | 418125 | 307 | 2820.6 | 1439562 | 510375 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2839.42 | 1439584 | 507000 | 180 | 4253.35 | 1439584 | 338458 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.06051 | 222 | 209334 | 168 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2435.78 | 500299 | 205396 | 95 | 2597.82 | 500299 | 192584 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1625.01 | 500299 | 307875 | 98 | 2385.69 | 500299 | 209708 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.80488 | 222 | 123000 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2976.96 | 722038 | 242542 | 272 | 3861.17 | 722038 | 187000 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2641.8 | 724019 | 274062 | 387 | 4214.52 | 724019 | 171792 | 355 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 493.188 | 721000 | 1.46192e+06 | 247 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2406.84 | 480967 | 199834 | 98 | 3749.03 | 480967 | 128291 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2371.71 | 478986 | 201958 | 99 | 4096.82 | 478986 | 116916 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 337.967 | 477948 | 1.41419e+06 | 99 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2533.6 | 1453338 | 573626 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1592.19 | 1453338 | 912792 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 407.951 | 1457312 | 3.57227e+06 | 212 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2960.65 | 1750052 | 591104 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2076.44 | 1750052 | 842813 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1643.72 | 1750052 | 1.06469e+06 | 495 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1202.41 | 1750052 | 1.45546e+06 | 419 | 