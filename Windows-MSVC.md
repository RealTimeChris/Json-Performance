# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.41.34120.0 compiler).  

Latest Results: (Oct 17, 2024)
#### Using the following commits:
----
| Jsonifier: [c81734c](https://github.com/RealTimeChris/Jsonifier/commit/c81734c)  
| Glaze: [293eb5e](https://github.com/stephenberry/glaze/commit/293eb5e)  
| Simdjson: [36f5dbc](https://github.com/simdjson/simdjson/commit/36f5dbc)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1688.19 | 1.44853e+06 | 1611349 | 2.33409e+06 | 300 | 2060.97 | 1.18654e+06 | 1611349 | 1.91193e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1352.94 | 1.80747e+06 | 1611275 | 2.91233e+06 | 232 | 2286.95 | 1.06929e+06 | 1611275 | 1.72291e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 475.422 | 5.14357e+06 | 1611275 | 8.28771e+06 | 300 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1762.18 | 1.38771e+06 | 1339034 | 1.85819e+06 | 297 | 2184.52 | 1.11943e+06 | 1339034 | 1.49896e+06 | 255 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1194.25 | 2.04764e+06 | 1338960 | 2.74171e+06 | 298 | 2106.32 | 1.16099e+06 | 1338960 | 1.55452e+06 | 184 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 377.956 | 6.47006e+06 | 1338960 | 8.66315e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1971.57 | 1.24033e+06 | 1611349 | 1.99861e+06 | 96 | 2106.33 | 1.16099e+06 | 1611349 | 1.87076e+06 | 295 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1355.29 | 1.80435e+06 | 1611275 | 2.9073e+06 | 98 | 2250.17 | 1.08677e+06 | 1611275 | 1.75109e+06 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 146.407 | 1.67028e+07 | 1611275 | 2.69128e+07 | 196 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1764.96 | 1.38553e+06 | 1339034 | 1.85528e+06 | 98 | 2120.81 | 1.15306e+06 | 1339034 | 1.54399e+06 | 192 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1191.93 | 2.05163e+06 | 1338960 | 2.74705e+06 | 98 | 2083.03 | 1.17398e+06 | 1338960 | 1.57191e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 121.257 | 2.01671e+07 | 1338960 | 2.70029e+07 | 299 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1439.33 | 1.69899e+06 | 138774 | 235776 | 99 | 1941.08 | 1.25983e+06 | 138774 | 174832 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1062.1 | 2.30242e+06 | 138774 | 319516 | 300 | 1905.28 | 1.28349e+06 | 138774 | 178114 | 212 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 90.755 | 2.69451e+07 | 47820 | 1.28852e+06 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 906.856 | 2.69657e+06 | 69037 | 186163 | 99 | 1395.59 | 1.75223e+06 | 69037 | 120968 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 808.63 | 3.02413e+06 | 69037 | 208777 | 99 | 1267.74 | 1.92896e+06 | 69037 | 133170 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 44.7658 | 5.46267e+07 | 23197 | 1.26718e+06 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1423.71 | 1.71763e+06 | 6661897 | 1.14427e+07 | 299 | 963.667 | 2.53759e+06 | 6661897 | 1.69052e+07 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1052.79 | 2.32279e+06 | 6661897 | 1.54742e+07 | 300 | 1025.49 | 2.38464e+06 | 6661897 | 1.58862e+07 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 422.176 | 5.79235e+06 | 6661897 | 3.85881e+07 | 300 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 453.352 | 5.39404e+06 | 2090234 | 1.12748e+07 | 300 | 429.426 | 5.69466e+06 | 2090234 | 1.19032e+07 | 299 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 344.232 | 7.10393e+06 | 2090234 | 1.48489e+07 | 299 | 400.54 | 6.1053e+06 | 2090234 | 1.27615e+07 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 133.312 | 1.83434e+07 | 2090234 | 3.83421e+07 | 300 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2884.09 | 847893 | 1439556 | 1.22059e+06 | 199 | 2283.33 | 1.07099e+06 | 1439556 | 1.54175e+06 | 297 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1926.97 | 1.26904e+06 | 1439584 | 1.82689e+06 | 168 | 2419.21 | 1.01083e+06 | 1439584 | 1.45518e+06 | 239 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 631.052 | 3.87511e+06 | 1425381 | 5.52351e+06 | 168 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1574.56 | 1.55305e+06 | 500293 | 776980 | 181 | 1597.13 | 1.53114e+06 | 500293 | 766016 | 296 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1165.25 | 2.09862e+06 | 500299 | 1.04994e+06 | 99 | 1301.45 | 1.87901e+06 | 500299 | 940065 | 198 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 232.033 | 1.05391e+07 | 494854 | 5.2153e+06 | 298 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1344.48 | 1.81884e+06 | 719230 | 1.30817e+06 | 194 | 2267.24 | 1.07859e+06 | 719230 | 775756 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1069.95 | 2.28554e+06 | 719139 | 1.64362e+06 | 236 | 2406.94 | 1.01599e+06 | 719139 | 730640 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 321.057 | 7.6167e+06 | 657230 | 5.00593e+06 | 299 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1425.56 | 1.7154e+06 | 477797 | 819611 | 97 | 2326.31 | 1.0512e+06 | 477797 | 502262 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 921.708 | 2.65312e+06 | 477706 | 1.26741e+06 | 297 | 2050.03 | 1.19288e+06 | 477706 | 569845 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 209.255 | 1.16862e+07 | 421643 | 4.92742e+06 | 97 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 513.984 | 4.75772e+06 | 69037 | 328459 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 440.458 | 5.55196e+06 | 69037 | 383290 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 290.045 | 8.43112e+06 | 69037 | 582059 | 194 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2064.62 | 1.18443e+06 | 1611349 | 1.90852e+06 | 194 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1123.22 | 2.17714e+06 | 1611349 | 3.50813e+06 | 208 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2257.7 | 1.08314e+06 | 123050 | 133280 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1375.35 | 1.77802e+06 | 123050 | 218785 | 97 | 