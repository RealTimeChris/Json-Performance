# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 18.1.8 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [c5c935a](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | inf | 1719801 | 0 | 498 | 3008.94 | 1719801 | 571563 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2305.92 | 1718104 | 745083 | 500 | 2633.02 | 1718104 | 652521 | 497 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 744.092 | 1721845 | 2.31402e+06 | 500 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2094.49 | 1420935 | 678417 | 500 | 2491.41 | 1420935 | 570333 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2087.82 | 1422632 | 681396 | 500 | 2856.45 | 1422632 | 498042 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 982.422 | 1424676 | 1.45017e+06 | 500 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2411.23 | 1718104 | 712542 | 99 | 2662.78 | 1718104 | 645229 | 177 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2152.61 | 1719801 | 798938 | 442 | 3163.09 | 1719801 | 543708 | 499 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1203.02 | 1721845 | 1.43127e+06 | 499 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2128.89 | 1422632 | 668250 | 500 | 2924.72 | 1422632 | 486417 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2119.35 | 1420935 | 670458 | 493 | 2584.5 | 1420935 | 549792 | 329 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1024.64 | 1424676 | 1.39042e+06 | 500 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1897.22 | 138774 | 73146 | 97 | 3467.57 | 138774 | 40020.5 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1800.32 | 138774 | 77083 | 500 | 2422.22 | 138774 | 57292 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 236.077 | 138774 | 587834 | 99 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | inf | 69037 | 0 | 495 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1629.98 | 69037 | 42354.5 | 500 | 3484.52 | 69037 | 19812.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1437.03 | 69037 | 48041.5 | 500 | 2480.4 | 69037 | 27833 | 99 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2459.97 | 6661897 | 2.70812e+06 | 494 | 1963.81 | 6661897 | 3.39233e+06 | 495 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2231.64 | 6661897 | 2.98521e+06 | 494 | 2192.83 | 6661897 | 3.03804e+06 | 304 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1798.74 | 6661897 | 3.70365e+06 | 500 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1228.42 | 2090234 | 1.70156e+06 | 257 | 896.904 | 2090234 | 2.3305e+06 | 199 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1132.34 | 2090234 | 1.84594e+06 | 500 | 864.53 | 2090234 | 2.41777e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 655.725 | 2090234 | 3.18767e+06 | 500 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2463.9 | 1439584 | 584270 | 488 | 3795.04 | 1439584 | 379334 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 331.51 | 83050 | 250520 | 500 | 2510.28 | 83050 | 33084 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.991995 | 222 | 223792 | 500 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1481 | 500299 | 337812 | 500 | 2216.16 | 500299 | 225750 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 174.957 | 45179 | 258229 | 500 | 3097.95 | 45179 | 14583.5 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.59976 | 222 | 138770 | 500 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2406.79 | 722038 | 300000 | 389 | 3098.88 | 722038 | 233000 | 172 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2377.24 | 724019 | 304562 | 488 | 4090.99 | 724019 | 176979 | 202 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 387.344 | 721000 | 1.8614e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 2273.21 | 478986 | 210709 | 498 | 4003.36 | 478986 | 119646 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2228.21 | 480967 | 215854 | 500 | 3587.63 | 480967 | 134062 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 281.778 | 477948 | 1.69619e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2090.34 | 1422694 | 680604 | 493 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1446.44 | 1422694 | 983584 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 366.603 | 1426651 | 3.89154e+06 | 496 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2917.08 | 1719863 | 589583 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1905.44 | 1719863 | 902604 | 500 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1635.56 | 1719863 | 1.05154e+06 | 490 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1087.92 | 1719863 | 1.58088e+06 | 497 | 