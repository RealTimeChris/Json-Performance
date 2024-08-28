# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Nov 12, 2024)
#### Using the following commits:
----
| Jsonifier: [f34dc2e](https://github.com/RealTimeChris/Jsonifier/commit/f34dc2e)  
| Glaze: [952e960](https://github.com/stephenberry/glaze/commit/952e960)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1995.95 | 2083236 | 1.04373e+06 | 98 | 2828.72 | 2083236 | 736458 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1762.37 | 2083236 | 1.18206e+06 | 99 | 2676.82 | 2083236 | 778250 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 902.99 | 2083236 | 2.30704e+06 | 299 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1607.17 | 1608380 | 1.00075e+06 | 98 | 2582.71 | 1608380 | 622750 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1587.18 | 1608380 | 1.01335e+06 | 99 | 2404.45 | 1608380 | 668917 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 715.054 | 1608380 | 2.24931e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1957.58 | 2083236 | 1.06419e+06 | 97 | 2803.03 | 2083236 | 743208 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1761.04 | 2083236 | 1.18296e+06 | 99 | 2648.25 | 2083236 | 786646 | 292 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 481.267 | 2083236 | 4.32865e+06 | 299 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1609.39 | 1608380 | 999376 | 98 | 2575.72 | 1608380 | 624438 | 298 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1588.88 | 1608380 | 1.01227e+06 | 99 | 2473.64 | 1608380 | 650208 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 387.507 | 1608380 | 4.15058e+06 | 294 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2836.93 | 138774 | 48917 | 250 | 3950.86 | 138774 | 35125 | 298 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1822.98 | 138774 | 76125 | 212 | 3388.12 | 138774 | 40959 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1577.02 | 138482 | 87812.5 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1804.89 | 69037 | 38250 | 157 | 4371.64 | 69037 | 15792 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1351.47 | 69037 | 51083 | 99 | 2919.67 | 69037 | 23645.5 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 840.917 | 68745 | 81750 | 298 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3462.94 | 6661897 | 1.92377e+06 | 299 | 2249.98 | 6661897 | 2.96087e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2873.62 | 6661897 | 2.31829e+06 | 299 | 2199.93 | 6661897 | 3.02823e+06 | 296 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1087.77 | 6661897 | 6.12435e+06 | 299 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1139.87 | 2090234 | 1.83375e+06 | 99 | 921.959 | 2090234 | 2.26717e+06 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1070.68 | 2090234 | 1.95225e+06 | 173 | 926.009 | 2090234 | 2.25725e+06 | 169 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 356.598 | 2090234 | 5.8616e+06 | 295 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3945.58 | 1439562 | 364854 | 99 | 4477.35 | 1439562 | 321521 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2706.3 | 1439584 | 531938 | 99 | 3980.64 | 1439584 | 361646 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1864.42 | 1425624 | 764646 | 229 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2655.28 | 500299 | 188417 | 95 | 3446.38 | 500299 | 145166 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1578.54 | 500299 | 316937 | 162 | 2224.58 | 500299 | 224896 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 730.119 | 495097 | 678104 | 99 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3522.68 | 719139 | 204146 | 95 | 4915.79 | 719139 | 146292 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2277.86 | 719139 | 315708 | 214 | 4155.88 | 719139 | 173042 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1430.6 | 659030 | 460666 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3016.3 | 477706 | 158375 | 98 | 5781.58 | 477706 | 82625.5 | 295 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2051.89 | 477706 | 232812 | 298 | 4356.8 | 477706 | 109646 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 931.218 | 425043 | 456438 | 99 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 842.346 | 69037 | 81958 | 97 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 580.143 | 69037 | 119000 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 514.56 | 69037 | 134167 | 97 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2206.67 | 2083236 | 944062 | 221 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1700.14 | 2083236 | 1.22533e+06 | 96 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2064.83 | 118385 | 57334 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1703.9 | 118385 | 69479 | 262 | 