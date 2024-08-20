# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (Aug 20, 2024)
#### Using the following commits:
----
| Jsonifier: [f3e6654](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a 6 core (Intel i7 8700k), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 2337.32 | 1628455 | 696719 | 96 | 3041.01 | 1626800 | 534954 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1915.43 | 1628455 | 850177 | 160 | 2690.62 | 1628402 | 605215 | 295 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1408.91 | 1628455 | 1.15582e+06 | 211 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 2386.11 | 1349806 | 565692 | 164 | 2940.63 | 1348151 | 458457 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2031.73 | 1349806 | 664362 | 170 | 2486.44 | 1349753 | 542846 | 194 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1155.6 | 1349806 | 1.16806e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 2335.46 | 1628455 | 697272 | 99 | 2959.84 | 1626800 | 549625 | 298 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1912.18 | 1628455 | 851621 | 96 | 2691.29 | 1628402 | 605063 | 294 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1369.21 | 1628455 | 1.18934e+06 | 100 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 2484.5 | 1349806 | 543291 | 263 | 2776.47 | 1348151 | 485563 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2029.13 | 1349806 | 665214 | 297 | 2538.51 | 1349753 | 531711 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1145.59 | 1349806 | 1.17826e+06 | 300 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1886.08 | 143439 | 76051.4 | 300 | 3341.95 | 138774 | 41524.9 | 300 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1763.89 | 143439 | 81319.5 | 300 | 3901.28 | 138774 | 35571.4 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 211.287 | 143439 | 678883 | 298 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1574.42 | 69037 | 43849.3 | 96 | 2944.63 | 69037 | 23445.1 | 296 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1557.29 | 69037 | 44331.4 | 297 | 2456.82 | 69037 | 28100.1 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 96.8459 | 69037 | 712854 | 297 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1787.4 | 6885124 | 3.85203e+06 | 96 | 1797.59 | 6661897 | 3.70601e+06 | 166 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1701.43 | 6885124 | 4.04667e+06 | 300 | 1653.97 | 6661897 | 4.02783e+06 | 186 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1479.92 | 6885124 | 4.65236e+06 | 297 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1142.84 | 2090234 | 1.82898e+06 | 300 | 757.729 | 2090234 | 2.75855e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1010.03 | 2090234 | 2.06948e+06 | 249 | 753.66 | 2090234 | 2.77344e+06 | 257 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 520.719 | 2090234 | 4.01413e+06 | 247 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1145.12 | 696898 | 608583 | 300 | 1794.3 | 763115 | 425298 | 298 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1007.47 | 696898 | 691733 | 298 | 1764.06 | 763734 | 432942 | 246 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 356.977 | 696898 | 1.95222e+06 | 300 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1232.88 | 520063 | 421827 | 300 | 1509.58 | 520063 | 344507 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1004.72 | 520063 | 517622 | 300 | 1552.01 | 520682 | 335488 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 266.633 | 520063 | 1.95048e+06 | 97 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 625.57 | 69037 | 110358 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 625.563 | 69037 | 110360 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 457.078 | 69037 | 151040 | 300 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 3051.14 | 1628455 | 533721 | 296 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3013.28 | 1628455 | 540426 | 268 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1579.83 | 143439 | 90793.8 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/f3e6654) | 1399.49 | 143439 | 102494 | 297 | 