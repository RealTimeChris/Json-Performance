# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 19.1.0 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [da428c0](https://github.com/RealTimeChris/Jsonifier/commit/da428c0)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor              ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 3215.17 | 1814187 | 564259 | 97 | 3294.51 | 1814187 | 550669 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2334.79 | 1816020 | 777809 | 98 | 3091.78 | 1816020 | 587370 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1217.01 | 1818294 | 1.49407e+06 | 268 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2957.29 | 1492095 | 504548 | 98 | 2352.42 | 1492095 | 634282 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2330.96 | 1493928 | 640907 | 98 | 2836.72 | 1493928 | 526639 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1007.96 | 1496202 | 1.48438e+06 | 100 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2436.02 | 1814187 | 744733 | 98 | 3319.43 | 1814187 | 546536 | 168 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1762.3 | 1816020 | 1.03049e+06 | 97 | 3061.33 | 1816020 | 593213 | 178 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1197.97 | 1818294 | 1.51782e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2337.24 | 1493928 | 639185 | 98 | 2131.36 | 1493928 | 700926 | 100 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2275.78 | 1492095 | 655642 | 164 | 3112.64 | 1492095 | 479366 | 176 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1017.03 | 1496202 | 1.47115e+06 | 98 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1421.47 | 138774 | 97626.8 | 169 | 1891.64 | 138774 | 73361.8 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1240.79 | 138774 | 111843 | 97 | 1996.33 | 138774 | 69514.7 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 208.227 | 138774 | 666457 | 99 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2082.96 | 69037 | 33143.7 | 99 | 1808.66 | 69037 | 38170.3 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1131.41 | 69037 | 61018.6 | 98 | 1977.09 | 69037 | 34918.4 | 242 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 137.801 | 69037 | 500991 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2852.33 | 6661897 | 2.3356e+06 | 97 | 1476.58 | 6661897 | 4.5117e+06 | 498 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2429.22 | 6661897 | 2.7424e+06 | 98 | 1609.4 | 6661897 | 4.13935e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1544.5 | 6661897 | 4.31329e+06 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1473.36 | 2090234 | 1.41869e+06 | 98 | 798.037 | 2090234 | 2.61922e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1238.94 | 2090234 | 1.68711e+06 | 99 | 803.04 | 2090234 | 2.6029e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 520.051 | 2090234 | 4.01929e+06 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 3238.62 | 1439562 | 444499 | 99 | 3361.69 | 1439562 | 428226 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2703.71 | 1439584 | 532447 | 99 | 3300.78 | 1439584 | 436134 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.954492 | 222 | 232584 | 200 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2719.25 | 500299 | 183984 | 98 | 2345.37 | 500299 | 213313 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1557.46 | 500299 | 321227 | 100 | 2227.87 | 500299 | 224564 | 162 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.33313 | 222 | 166526 | 94 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2233.78 | 724019 | 324122 | 98 | 3052.41 | 724019 | 237196 | 212 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2072.95 | 722038 | 348314 | 193 | 3427.86 | 722038 | 210638 | 204 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 409.264 | 721000 | 1.7617e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2366.93 | 478986 | 202366 | 196 | 3093.28 | 478986 | 154847 | 188 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2183.48 | 480967 | 220275 | 98 | 3102.44 | 480967 | 155029 | 188 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 270.587 | 477948 | 1.76634e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2570.46 | 1493995 | 581216 | 168 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1634.9 | 1493995 | 913813 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 459.951 | 1498308 | 3.25754e+06 | 98 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3140.94 | 1816087 | 578199 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2339.79 | 1816087 | 776177 | 97 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1866.57 | 1816087 | 972953 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1253.24 | 1816087 | 1.44912e+06 | 99 | 