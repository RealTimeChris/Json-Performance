# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Oct 17, 2024)
#### Using the following commits:
----
| Jsonifier: [c81734c](https://github.com/RealTimeChris/Jsonifier/commit/c81734c)  
| Glaze: [293eb5e](https://github.com/stephenberry/glaze/commit/293eb5e)  
| Simdjson: [36f5dbc](https://github.com/simdjson/simdjson/commit/36f5dbc)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2539.64 | 2008751 | 790958 | 98 | 2665.53 | 2008751 | 753604 | 216 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2252.41 | 2008680 | 891791 | 97 | 3332.99 | 2008680 | 602666 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1100.42 | 2008680 | 1.82538e+06 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2195.35 | 1663118 | 757562 | 97 | 3096.09 | 1663118 | 537167 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1734.78 | 1663189 | 958730 | 249 | 2667.86 | 1663189 | 623416 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 953.406 | 1663118 | 1.7444e+06 | 238 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2301.74 | 2008751 | 872708 | 300 | 2328.09 | 2008751 | 862834 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2179.79 | 2008680 | 921500 | 236 | 2985.41 | 2008680 | 672833 | 257 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 625.789 | 2008680 | 3.20983e+06 | 100 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2024.49 | 1663118 | 821500 | 300 | 2851.26 | 1663118 | 583292 | 300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1720.35 | 1663189 | 966771 | 297 | 2375.07 | 1663189 | 700270 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 437.622 | 1663118 | 3.80035e+06 | 300 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3075.32 | 138774 | 45125 | 297 | 2650.66 | 138774 | 52354.5 | 94 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1846.21 | 138774 | 75167 | 219 | 3354.05 | 138774 | 41375 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 568.298 | 47820 | 84146 | 241 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1900.09 | 69037 | 36333.5 | 98 | 1980.75 | 69037 | 34854 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1494.05 | 69037 | 46208 | 97 | 2529.57 | 69037 | 27292 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 324.622 | 23197 | 71458.5 | 96 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3214.2 | 6661897 | 2.07265e+06 | 173 | 1658.3 | 6661897 | 4.01731e+06 | 175 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 3072.24 | 6661897 | 2.16842e+06 | 95 | 2363.51 | 6661897 | 2.81865e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1188.64 | 6661897 | 5.60465e+06 | 97 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1108.07 | 2090234 | 1.88638e+06 | 295 | 1040.17 | 2090234 | 2.00952e+06 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1067.8 | 2090234 | 1.95752e+06 | 96 | 775.711 | 2090234 | 2.6946e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 376.297 | 2090234 | 5.55475e+06 | 181 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 4551.36 | 1439556 | 316292 | 297 | 2623.04 | 1439556 | 548812 | 94 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2983.47 | 1439584 | 482520 | 96 | 4210.08 | 1439584 | 341938 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 2054.28 | 1425624 | 693979 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3178.56 | 500293 | 157396 | 98 | 2131.75 | 500293 | 234687 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1719.86 | 500299 | 290896 | 99 | 2359.9 | 500299 | 212000 | 171 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 804.654 | 495097 | 615292 | 266 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3183.91 | 719230 | 225896 | 97 | 3363.18 | 719230 | 213854 | 287 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2482.47 | 719139 | 289687 | 98 | 4327.81 | 719139 | 166167 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1480.69 | 659030 | 445083 | 300 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2603.21 | 477797 | 183542 | 96 | 3130.96 | 477797 | 152604 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2253.11 | 477706 | 212020 | 286 | 3838.29 | 477706 | 124458 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1030.25 | 425043 | 412562 | 293 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 893.683 | 69037 | 77250 | 296 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 631.438 | 69037 | 109333 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 563.758 | 69037 | 122458 | 300 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2777.64 | 2008751 | 723188 | 300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1704.59 | 2008751 | 1.17844e+06 | 293 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2133.06 | 118385 | 55500 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2063.36 | 118385 | 57375 | 96 | 