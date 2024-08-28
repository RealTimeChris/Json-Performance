# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.2 compiler).  

Latest Results: (Nov 12, 2024)
#### Using the following commits:
----
| Jsonifier: [f34dc2e](https://github.com/RealTimeChris/Jsonifier/commit/f34dc2e)  
| Glaze: [952e960](https://github.com/stephenberry/glaze/commit/952e960)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2331.96 | 2158128 | 925458 | 97 | 2964.88 | 2158128 | 727896 | 95 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1850.72 | 2158128 | 1.1661e+06 | 270 | 2782.74 | 2158128 | 775542 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 878.203 | 2158128 | 2.45744e+06 | 300 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1873.54 | 1678147 | 895708 | 98 | 2856.42 | 1678147 | 587500 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1776.68 | 1678147 | 944542 | 100 | 2484.61 | 1678147 | 675416 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 787.031 | 1678147 | 2.13225e+06 | 100 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2316.42 | 2158128 | 931666 | 98 | 2995.75 | 2158128 | 720396 | 226 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1843.77 | 2158128 | 1.1705e+06 | 99 | 2735.99 | 2158128 | 788792 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 510.729 | 2158128 | 4.22558e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1904.06 | 1678147 | 881354 | 298 | 2798.95 | 1678147 | 599562 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1776.64 | 1678147 | 944562 | 186 | 2013.68 | 1678147 | 833375 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 401.861 | 1678147 | 4.17594e+06 | 175 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3176.52 | 138774 | 43687.5 | 99 | 4237.37 | 138774 | 32750 | 298 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1804.7 | 138774 | 76896 | 208 | 3674.14 | 138774 | 37770.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1652.28 | 138482 | 83812.5 | 95 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1984.31 | 69037 | 34791.5 | 99 | 4371.78 | 69037 | 15791.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1422.83 | 69037 | 48521 | 267 | 3192.46 | 69037 | 21625 | 206 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 864.266 | 68745 | 79541.5 | 295 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3477.74 | 6661897 | 1.91558e+06 | 300 | 2122.12 | 6661897 | 3.13927e+06 | 299 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2686.75 | 6661897 | 2.47954e+06 | 300 | 1934.52 | 6661897 | 3.44369e+06 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1018.82 | 6661897 | 6.53881e+06 | 300 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1080.31 | 2090234 | 1.93485e+06 | 300 | 990.622 | 2090234 | 2.11002e+06 | 293 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1057.61 | 2090234 | 1.97638e+06 | 300 | 832.196 | 2090234 | 2.51171e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 317.459 | 2090234 | 6.58427e+06 | 300 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3878.04 | 1439562 | 371209 | 100 | 4433.4 | 1439562 | 324708 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2863.06 | 1439584 | 502812 | 300 | 4335.01 | 1439584 | 332083 | 295 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 2029.22 | 1427811 | 703624 | 300 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2724.26 | 500299 | 183646 | 168 | 3689.98 | 500299 | 135583 | 297 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1758.39 | 500299 | 284520 | 287 | 2384.75 | 500299 | 209791 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 734.608 | 497284 | 676938 | 300 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 4189.15 | 719139 | 171667 | 187 | 5295.89 | 719139 | 135792 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2250.24 | 719139 | 319583 | 95 | 4189.68 | 719139 | 171646 | 226 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1448.42 | 659030 | 455000 | 100 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3421.34 | 477706 | 139626 | 97 | 6225.85 | 477706 | 76729.5 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2170.98 | 477706 | 220042 | 99 | 4632.3 | 477706 | 103125 | 175 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 940.794 | 425043 | 451792 | 297 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 841.053 | 69037 | 82084 | 232 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 741.663 | 69037 | 93084 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 558.439 | 69037 | 123625 | 300 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2398.25 | 2158128 | 899874 | 182 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1839.08 | 2158128 | 1.17348e+06 | 211 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2336.58 | 118385 | 50666 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2073.91 | 118385 | 57083 | 99 | 