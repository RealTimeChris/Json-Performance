# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.41.34123.0 compiler).  

Latest Results: (Oct 25, 2024)
#### Using the following commits:
----
| Jsonifier: [55f790d](https://github.com/RealTimeChris/Jsonifier/commit/55f790d)  
| Glaze: [98fa3bc](https://github.com/stephenberry/glaze/commit/98fa3bc)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1419.16 | 1.72313e+06 | 835610 | 1.43986e+06 | 237 | 1376.97 | 1.77592e+06 | 835610 | 1.48398e+06 | 209 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 743.794 | 3.28773e+06 | 835512 | 2.74694e+06 | 175 | 1428.71 | 1.71163e+06 | 835512 | 1.43009e+06 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 305.859 | 7.99518e+06 | 835512 | 6.68007e+06 | 94 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1026.36 | 2.3826e+06 | 563081 | 1.3416e+06 | 300 | 1121.7 | 2.1801e+06 | 563081 | 1.22757e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 561.982 | 4.35138e+06 | 562983 | 2.44976e+06 | 97 | 1103.73 | 2.21558e+06 | 562983 | 1.24733e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 210.053 | 1.16418e+07 | 562983 | 6.55414e+06 | 161 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1393.42 | 1.75496e+06 | 835610 | 1.46646e+06 | 96 | 1374.81 | 1.77874e+06 | 835610 | 1.48633e+06 | 238 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 744.095 | 3.2864e+06 | 835512 | 2.74582e+06 | 96 | 1436.96 | 1.70181e+06 | 835512 | 1.42188e+06 | 232 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 83.2238 | 2.93834e+07 | 835512 | 2.45502e+07 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1034.91 | 2.36291e+06 | 563081 | 1.33051e+06 | 97 | 1120.4 | 2.1826e+06 | 563081 | 1.22898e+06 | 296 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 560.758 | 4.36087e+06 | 562983 | 2.4551e+06 | 220 | 1104.19 | 2.21468e+06 | 562983 | 1.24683e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 56.5506 | 4.32426e+07 | 562983 | 2.43449e+07 | 202 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1441.64 | 1.69625e+06 | 138774 | 235396 | 99 | 1726.78 | 1.41617e+06 | 138774 | 196527 | 94 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1089.44 | 2.24461e+06 | 138774 | 311493 | 224 | 1925.69 | 1.2699e+06 | 138774 | 176228 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 368.971 | 6.62762e+06 | 138482 | 917806 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 887.751 | 2.7546e+06 | 69037 | 190169 | 191 | 1452.37 | 1.68373e+06 | 69037 | 116240 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 703.71 | 3.47501e+06 | 69037 | 239904 | 299 | 1277.49 | 1.91423e+06 | 69037 | 132153 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 186.982 | 1.30783e+07 | 68745 | 899064 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1514.36 | 1.6148e+06 | 6661897 | 1.07576e+07 | 97 | 1095.8 | 2.23163e+06 | 6661897 | 1.48669e+07 | 166 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1080.08 | 2.26408e+06 | 6661897 | 1.5083e+07 | 97 | 1109.58 | 2.2039e+06 | 6661897 | 1.46822e+07 | 161 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 423.56 | 5.77343e+06 | 6661897 | 3.8462e+07 | 299 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 487.707 | 5.01407e+06 | 2090234 | 1.04806e+07 | 96 | 443.589 | 5.51281e+06 | 2090234 | 1.15231e+07 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 350.825 | 6.97038e+06 | 2090234 | 1.45697e+07 | 97 | 438.882 | 5.57193e+06 | 2090234 | 1.16466e+07 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 136.786 | 1.78774e+07 | 2090234 | 3.73679e+07 | 171 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2838.22 | 861599 | 1439562 | 1.24032e+06 | 97 | 1809.98 | 1.35108e+06 | 1439562 | 1.94496e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1435.53 | 1.70348e+06 | 1439584 | 2.4523e+06 | 98 | 2422.76 | 1.00935e+06 | 1439584 | 1.45305e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 640.711 | 3.81669e+06 | 1425381 | 5.44024e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1679.98 | 1.4556e+06 | 500299 | 728238 | 98 | 1647.43 | 1.48438e+06 | 500299 | 742632 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 717.207 | 3.40959e+06 | 500299 | 1.70581e+06 | 98 | 1295.46 | 1.88767e+06 | 500299 | 944402 | 176 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 231.492 | 1.05636e+07 | 494854 | 5.22745e+06 | 296 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1632.15 | 1.49826e+06 | 719230 | 1.0776e+06 | 98 | 2295.36 | 1.06537e+06 | 719230 | 766250 | 237 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1037.3 | 2.35747e+06 | 719139 | 1.69535e+06 | 97 | 2388.59 | 1.02379e+06 | 719139 | 736250 | 212 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 323.612 | 7.55657e+06 | 659630 | 4.98454e+06 | 97 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1329.45 | 1.83941e+06 | 477797 | 878864 | 98 | 2341.71 | 1.04428e+06 | 477797 | 498955 | 162 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 830.177 | 2.94563e+06 | 477706 | 1.40714e+06 | 207 | 2029.41 | 1.20498e+06 | 477706 | 575627 | 166 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 175.604 | 1.39257e+07 | 351043 | 4.88851e+06 | 175 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 529.263 | 4.62038e+06 | 69037 | 318978 | 94 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 517.263 | 4.72756e+06 | 69037 | 326376 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 286.534 | 8.53438e+06 | 69037 | 589188 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1415.58 | 1.72747e+06 | 835610 | 1.44349e+06 | 211 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1226.23 | 1.99424e+06 | 835610 | 1.6664e+06 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2343.21 | 1.04361e+06 | 123050 | 128416 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1386.22 | 1.76408e+06 | 123050 | 217070 | 98 | 