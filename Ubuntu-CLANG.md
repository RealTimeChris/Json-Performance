# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 19.1.0 compiler).  

Latest Results: (Aug 29, 2024)
#### Using the following commits:
----
| Jsonifier: [ed68533](https://github.com/RealTimeChris/Jsonifier/commit/ed68533)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 3309.92 | 1958003 | 591556 | 95 | 3337.04 | 1956027 | 586156 | 169 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2337.11 | 1958003 | 837787 | 98 | 3095.16 | 1957919 | 632575 | 198 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1029.55 | 1623515 | 1.57692e+06 | 298 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2983.5 | 1621384 | 543451 | 97 | 3119.17 | 1619408 | 519179 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2343.06 | 1621384 | 691993 | 99 | 2853.93 | 1621300 | 568094 | 195 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1060.35 | 1623515 | 1.53111e+06 | 299 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 3311.71 | 1958003 | 591236 | 96 | 3335.77 | 1956027 | 586380 | 188 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2323.28 | 1958003 | 842776 | 97 | 3100.9 | 1957919 | 631404 | 182 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 553.507 | 1623515 | 2.93314e+06 | 299 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2967.4 | 1621384 | 546399 | 96 | 3102.34 | 1619408 | 521995 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2354.83 | 1621384 | 688537 | 97 | 2850.11 | 1621300 | 568856 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 541.05 | 1623515 | 3.00067e+06 | 300 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2010.68 | 118385 | 58878.2 | 98 | 2125.18 | 138774 | 65299.9 | 195 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1243.9 | 118385 | 95172.3 | 97 | 1853.92 | 138774 | 74854.5 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 103.493 | 53246 | 514488 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1544.23 | 69037 | 44706.4 | 99 | 1566.7 | 69037 | 44065.2 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1255.77 | 69037 | 54975.9 | 183 | 1580.48 | 69037 | 43681 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 78.3649 | 53246 | 679462 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2259.15 | 6661897 | 2.94885e+06 | 98 | 1736.77 | 6661897 | 3.83579e+06 | 192 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1725.26 | 6661897 | 3.86138e+06 | 167 | 1603.89 | 6661897 | 4.15359e+06 | 221 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 377.836 | 2090234 | 5.53212e+06 | 100 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 961.909 | 2090234 | 2.17301e+06 | 97 | 588.639 | 2090234 | 3.55096e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 927.405 | 2090234 | 2.25385e+06 | 97 | 610.596 | 2090234 | 3.42327e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 409.828 | 2090234 | 5.10027e+06 | 97 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2195.21 | 1140454 | 519519 | 97 | 2503.67 | 1439562 | 574982 | 261 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2110.74 | 1140454 | 540311 | 97 | 2330.66 | 1439584 | 617672 | 160 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2149.04 | 500299 | 232801 | 236 | 1732.29 | 500299 | 288808 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1519.59 | 500299 | 329232 | 99 | 1639.71 | 500299 | 305114 | 181 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1549.36 | 632379 | 408156 | 162 | 2587.44 | 722038 | 279055 | 266 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1505.83 | 632379 | 419953 | 214 | 2426.22 | 724019 | 298415 | 263 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 179.559 | 426533 | 2.37544e+06 | 300 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1610.61 | 467771 | 290431 | 97 | 2331.65 | 478986 | 205428 | 171 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1585.99 | 467771 | 294940 | 165 | 2336.51 | 480967 | 205849 | 171 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 177.883 | 426533 | 2.39783e+06 | 300 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 798.842 | 69037 | 86421.3 | 97 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 686.073 | 69037 | 100626 | 214 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 442.146 | 69037 | 156141 | 95 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2389.45 | 1958003 | 819438 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2364.6 | 1958003 | 828049 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1992.86 | 118385 | 59404.6 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1243.47 | 118385 | 95205.6 | 98 | 