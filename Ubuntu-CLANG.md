# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Oct 17, 2024)
#### Using the following commits:
----
| Jsonifier: [c81734c](https://github.com/RealTimeChris/Jsonifier/commit/c81734c)  
| Glaze: [293eb5e](https://github.com/stephenberry/glaze/commit/293eb5e)  
| Simdjson: [36f5dbc](https://github.com/simdjson/simdjson/commit/36f5dbc)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2454.32 | 996379 | 1893343 | 1.88649e+06 | 97 | 2629.14 | 930126 | 1893343 | 1.76105e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1794.23 | 1.36294e+06 | 1893260 | 2.5804e+06 | 96 | 2705.85 | 903755 | 1893260 | 1.71104e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 987.584 | 2.47617e+06 | 1893260 | 4.68804e+06 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2950.58 | 1.09918e+06 | 1584411 | 1.74155e+06 | 98 | 3245.84 | 999191 | 1584411 | 1.58313e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1782.37 | 1.37201e+06 | 1584328 | 2.17371e+06 | 99 | 2509.1 | 974624 | 1584328 | 1.54412e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1139.45 | 2.85867e+06 | 1584328 | 4.52907e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2364.69 | 1.03414e+06 | 1893343 | 1.95799e+06 | 99 | 2608.45 | 937502 | 1893343 | 1.77501e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1794.03 | 1.3631e+06 | 1893260 | 2.5807e+06 | 99 | 2685.28 | 910678 | 1893260 | 1.72415e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 528.126 | 4.63039e+06 | 1893260 | 8.76653e+06 | 184 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2951.98 | 1.0986e+06 | 1584411 | 1.74063e+06 | 97 | 3187.7 | 1.01736e+06 | 1584411 | 1.61192e+06 | 174 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2358.41 | 1.37489e+06 | 1584328 | 2.17827e+06 | 99 | 3260.34 | 994542 | 1584328 | 1.57568e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 458.206 | 5.33696e+06 | 1584328 | 8.4555e+06 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3006.51 | 1.07852e+06 | 138774 | 149670 | 181 | 2902.68 | 1.1171e+06 | 138774 | 155024 | 157 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2341.1 | 1.385e+06 | 138774 | 192202 | 97 | 2468.54 | 1.3135e+06 | 138774 | 182280 | 230 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 509.737 | 6.36299e+06 | 47820 | 304278 | 184 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2513.32 | 1.29e+06 | 69037 | 89057.5 | 300 | 1970.22 | 1.64559e+06 | 69037 | 113606 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1981.18 | 1.63654e+06 | 69037 | 112982 | 299 | 1993.07 | 1.62678e+06 | 69037 | 112308 | 164 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 255.812 | 1.26756e+07 | 23197 | 294037 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2423.74 | 1.00895e+06 | 6661897 | 6.7215e+06 | 98 | 1571.72 | 1.5559e+06 | 6661897 | 1.03652e+07 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2229.5 | 1.09685e+06 | 6661897 | 7.30711e+06 | 99 | 1580.49 | 1.54726e+06 | 6661897 | 1.03077e+07 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 749.156 | 3.26425e+06 | 6661897 | 2.17461e+07 | 98 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 835.239 | 2.92782e+06 | 2090234 | 6.11983e+06 | 98 | 601.481 | 4.06568e+06 | 2090234 | 8.49822e+06 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 806.547 | 3.03198e+06 | 2090234 | 6.33754e+06 | 98 | 611.9 | 3.99645e+06 | 2090234 | 8.35352e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 235.548 | 1.03819e+07 | 2090234 | 2.17005e+07 | 100 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3898.98 | 725092 | 1439556 | 1.04381e+06 | 164 | 3083.07 | 916982 | 1439556 | 1.32005e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2451.65 | 997464 | 1439584 | 1.43593e+06 | 98 | 2383.19 | 1.02611e+06 | 1439584 | 1.47718e+06 | 160 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1090.99 | 2.24148e+06 | 1426596 | 3.19769e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2594.88 | 942404 | 500293 | 471478 | 95 | 1713.86 | 1.42685e+06 | 500293 | 713844 | 161 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1731.62 | 1.41222e+06 | 500299 | 706531 | 173 | 1614.06 | 1.51508e+06 | 500299 | 757994 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 395.476 | 6.18351e+06 | 496069 | 3.06745e+06 | 100 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2368.41 | 1.03252e+06 | 719230 | 742620 | 99 | 2798.62 | 873798 | 719230 | 628462 | 193 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1815.23 | 1.34717e+06 | 719139 | 968804 | 188 | 2527.54 | 967512 | 719139 | 695776 | 155 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1011.98 | 2.41647e+06 | 750130 | 1.81267e+06 | 98 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2441.48 | 1.00162e+06 | 477797 | 478570 | 199 | 2499.77 | 978263 | 477797 | 467411 | 196 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1733.3 | 1.41085e+06 | 477706 | 673971 | 163 | 2580.31 | 947728 | 477706 | 452736 | 214 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 714.025 | 3.42485e+06 | 516143 | 1.76771e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 753.466 | 3.44626e+06 | 69037 | 237920 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 667.456 | 3.6638e+06 | 69037 | 252938 | 210 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 431.76 | 5.98172e+06 | 69037 | 412960 | 99 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2622.87 | 985458 | 1893343 | 1.86581e+06 | 273 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2323.58 | 1.05244e+06 | 1893343 | 1.99263e+06 | 97 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 4489.65 | 684808 | 118385 | 81071 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1706.7 | 1.51789e+06 | 118385 | 179696 | 98 | 