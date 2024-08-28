# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 18.1.8 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [da428c0](https://github.com/RealTimeChris/Jsonifier/commit/da428c0)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | inf | 1826516 | 0 | 494 | 3110.51 | 1826516 | 587208 | 375 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2361.01 | 1824715 | 772854 | 98 | 2567.91 | 1824715 | 710583 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1193.04 | 1828626 | 1.53275e+06 | 500 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2147.93 | 1514113 | 704916 | 500 | 2902.8 | 1514113 | 521604 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2074.68 | 1512312 | 728938 | 500 | 2542.5 | 1512312 | 594813 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1033.73 | 1516223 | 1.46675e+06 | 500 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2293.13 | 1824715 | 795730 | 500 | 2625.88 | 1824715 | 694896 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2117.09 | 1826516 | 862750 | 500 | 3046.95 | 1826516 | 599458 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1184.26 | 1828626 | 1.5441e+06 | 500 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2092.34 | 1514113 | 723646 | 500 | 2825.16 | 1514113 | 535938 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2056.81 | 1512312 | 735271 | 500 | 2390.69 | 1512312 | 632584 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1023.5 | 1516223 | 1.48142e+06 | 500 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1897.76 | 138774 | 73125 | 500 | 3467.57 | 138774 | 40020.5 | 188 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1799.83 | 138774 | 77104 | 491 | 2414.36 | 138774 | 57478.5 | 292 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 235.635 | 138774 | 588938 | 500 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1646.17 | 69037 | 41938 | 493 | 3488.13 | 69037 | 19792 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1522.16 | 69037 | 45354.5 | 352 | 2510.44 | 69037 | 27500 | 287 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 109.691 | 69037 | 629376 | 500 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2105.99 | 6661897 | 3.16331e+06 | 491 | 2066.17 | 6661897 | 3.22427e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1782.69 | 6661897 | 3.737e+06 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1446.73 | 6661897 | 4.60479e+06 | 500 | 1881.25 | 6661897 | 3.54121e+06 | 500 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1201.66 | 2090234 | 1.73946e+06 | 492 | 911.1 | 2090234 | 2.29419e+06 | 470 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1102.31 | 2090234 | 1.89623e+06 | 500 | 823.535 | 2090234 | 2.53812e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 650.332 | 2090234 | 3.2141e+06 | 499 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2446.88 | 1439584 | 588334 | 500 | 3983.4 | 1439584 | 361396 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2349.19 | 1439562 | 612792 | 500 | 2617.68 | 1439562 | 549938 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.03226 | 222 | 215063 | 500 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2285.12 | 500299 | 218938 | 500 | 2626.24 | 500299 | 190500 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1502.21 | 500299 | 333042 | 500 | 2208.83 | 500299 | 226500 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.62539 | 222 | 136583 | 500 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2261.97 | 724019 | 320084 | 500 | 2928.54 | 724019 | 247229 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2248.75 | 722038 | 321084 | 500 | 2498.94 | 722038 | 288938 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 410.5 | 721000 | 1.7564e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2229.07 | 480967 | 215770 | 500 | 3639.68 | 480967 | 132146 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1707.86 | 478986 | 280459 | 500 | 4018.05 | 478986 | 119208 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 259.329 | 477948 | 1.84302e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2368.76 | 1514178 | 639229 | 308 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1497.95 | 1514178 | 1.01083e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 368.652 | 1518193 | 4.11823e+06 | 477 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3005.48 | 1826581 | 607750 | 374 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1969.32 | 1826581 | 927520 | 477 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | inf | 1826581 | 0 | 496 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1025.03 | 1826581 | 1.78198e+06 | 500 | 