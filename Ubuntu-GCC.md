# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Aug 27, 2024)
#### Using the following commits:
----
| Jsonifier: [39a1062](https://github.com/RealTimeChris/Jsonifier/commit/39a1062)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor              ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2520.54 | 1765826 | 700575 | 98 | 2530.16 | 1765826 | 697910 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1768.44 | 1767516 | 999477 | 98 | 2394.93 | 1767516 | 738025 | 489 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1292.18 | 1769455 | 1.36935e+06 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2473.08 | 1473939 | 595993 | 99 | 2609.19 | 1473939 | 564902 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1884.61 | 1475629 | 782991 | 98 | 2202.68 | 1475629 | 669923 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 887.935 | 1477568 | 1.66405e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2502.64 | 1765826 | 705585 | 98 | 2539.29 | 1765826 | 695401 | 174 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1771.51 | 1767516 | 997744 | 99 | 2389.96 | 1767516 | 739558 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 969.229 | 1769455 | 1.82563e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2308.66 | 1473939 | 638440 | 99 | 2462.25 | 1473939 | 598615 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1782.56 | 1475629 | 827812 | 99 | 2189.42 | 1475629 | 673981 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 825.653 | 1477568 | 1.78957e+06 | 97 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1972.95 | 138774 | 70338.5 | 98 | 2318.44 | 138774 | 59856.6 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1616.19 | 138774 | 85865.1 | 98 | 2236.18 | 138774 | 62058.4 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 183.091 | 138774 | 757952 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1555.97 | 69037 | 44369.2 | 170 | 1740.1 | 69037 | 39674.1 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1313.8 | 69037 | 52547.7 | 98 | 2083.41 | 69037 | 33136.6 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 91.1306 | 69037 | 757562 | 171 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2001.01 | 6661897 | 3.32926e+06 | 99 | 1638.1 | 6661897 | 4.06683e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1994.93 | 6661897 | 3.33942e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1885.11 | 6661897 | 3.53395e+06 | 97 | 1733.95 | 6661897 | 3.84204e+06 | 98 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 992.446 | 2090234 | 2.10614e+06 | 99 | 579.889 | 2090234 | 3.60454e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 972.086 | 2090234 | 2.15026e+06 | 97 | 612.305 | 2090234 | 3.41372e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 817.841 | 2090234 | 2.55579e+06 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3274.69 | 1439584 | 439609 | 96 | 2535.99 | 1439584 | 567662 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2676 | 1439562 | 537952 | 99 | 2866.79 | 1439562 | 502151 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.30975 | 222 | 169498 | 211 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1854.87 | 500299 | 269723 | 160 | 2079.96 | 500299 | 240533 | 158 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1482.26 | 500299 | 337524 | 98 | 2471.96 | 500299 | 202389 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.84204 | 222 | 120519 | 500 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2012.27 | 722038 | 358817 | 189 | 2886.64 | 722038 | 250131 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1677.79 | 724019 | 431531 | 98 | 2426.66 | 724019 | 298361 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 330.675 | 721000 | 2.18039e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1813.39 | 478986 | 264138 | 177 | 2575.17 | 478986 | 186001 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1811.66 | 480967 | 265485 | 171 | 2449.22 | 480967 | 196376 | 206 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 202.093 | 477948 | 2.36499e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1988.78 | 1475701 | 742013 | 160 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1810.5 | 1475701 | 815079 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 419.735 | 1479375 | 3.52455e+06 | 98 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2539.63 | 1767588 | 696002 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2519.66 | 1767588 | 701517 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1030.38 | 1767588 | 1.71548e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 922.71 | 1767588 | 1.91565e+06 | 97 | 