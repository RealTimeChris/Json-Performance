# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (Jul 31, 2024)
#### Using the following commits:
----
| Jsonifier: [dfb86bb](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb)  
| Glaze: [e0b7ea2](https://github.com/stephenberry/glaze/commit/e0b7ea2)  
| Simdjson: [ba1819f](https://github.com/simdjson/simdjson/commit/ba1819f)  

 > At least 40 iterations on a 6 core (Intel i7 8700k), until Median Absolute Percentage Error (MAPE) reduced below 5.0%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1284.29 | 3103764 | 2.41672e+06 | 0.02702 | 1854.73 | 3099358 | 1.67106e+06 | 0.003983 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1132.47 | 3103764 | 2.74071e+06 | 0.0002567 | 1596.12 | 3103239 | 1.94424e+06 | 0.04095 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 355.247 | 3103764 | 8.73691e+06 | 0.6849 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1340.87 | 2123013 | 1.58331e+06 | 0.08488 | 1501.88 | 2118607 | 1.41064e+06 | 0.01621 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 968.184 | 2123013 | 2.19278e+06 | 0.002332 | 1253.98 | 2122488 | 1.6926e+06 | 0.02389 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 251.817 | 2123013 | 8.43077e+06 | 0.03458 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1301.11 | 3103764 | 2.38547e+06 | 0.4915 | 1874.84 | 3099358 | 1.65313e+06 | 0.1068 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1113.7 | 3103764 | 2.7869e+06 | 0.2576 | 1663.07 | 3103239 | 1.86597e+06 | 0.005728 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 789.975 | 3103764 | 3.92894e+06 | 0.01416 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1411.32 | 2123013 | 1.50428e+06 | 0.01439 | 1475.93 | 2118607 | 1.43544e+06 | 0.0104 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 981.127 | 2123013 | 2.16385e+06 | 0.01051 | 1264.74 | 2122488 | 1.6782e+06 | 0.03919 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 552.308 | 2123013 | 3.84389e+06 | 0.05245 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1796.14 | 138774 | 77262.5 | 0.06518 | 3860.84 | 138774 | 35944 | 0.02711 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1121.9 | 138774 | 123696 | 0.01356 | 3113.59 | 138774 | 44570.4 | 1.064 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 191.486 | 138774 | 724720 | 0.03422 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1425.63 | 69037 | 48425.6 | 0.0313 | 2934.63 | 69037 | 23524.9 | 0.01841 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 762.19 | 69037 | 90577.2 | 0.01703 | 2238.45 | 69037 | 30841.5 | 2.418 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 94.6416 | 69037 | 729458 | 0.04911 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1953.91 | 6661897 | 3.40953e+06 | 0.5942 | 2092.64 | 6661897 | 3.18349e+06 | 0.6196 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1620.93 | 6661897 | 4.10992e+06 | 0.5407 | 2090.16 | 6661897 | 3.18726e+06 | 0.87 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 946.449 | 6661897 | 7.03883e+06 | 0.01539 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1175.17 | 2090234 | 1.77866e+06 | 0.6049 | 800.899 | 2090234 | 2.60986e+06 | 0.5418 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 860.637 | 2090234 | 2.42871e+06 | 0.5052 | 808.85 | 2090234 | 2.58421e+06 | 0.02735 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 325.444 | 2090234 | 6.42271e+06 | 0.5447 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1606.16 | 722038 | 449542 | 0.01649 | 3350.21 | 722415 | 215632 | 0.05298 |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1460.9 | 722038 | 494242 | 0.5713 | 4384.79 | 722038 | 164669 | 0.0921 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 340.269 | 722038 | 2.12196e+06 | 0.5255 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1635.27 | 478986 | 292909 | 1.652 | 3780.8 | 478986 | 126689 | 0.04209 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1480.84 | 478986 | 323455 | 0.01991 | 2877.34 | 479363 | 166599 | 0.9676 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 223.349 | 478986 | 2.14457e+06 | 0.7065 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 763.506 | 69037 | 90421.1 | 0.01077 |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 750.088 | 69037 | 92038.5 | 0.05324 |
| [simdjson](https://github.com/simdjson/simdjson/commit/ba1819f) | 456.602 | 69037 | 151197 | 0.05367 |

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 2334.81 | 3103764 | 1.32934e+06 | 0.6683 |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 2150.7 | 3103764 | 1.44314e+06 | 0.01333 |

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [glaze](https://github.com/stephenberry/glaze/commit/e0b7ea2) | 1644.7 | 138774 | 84376.4 | 0.03817 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/dfb86bb) | 1601.4 | 138774 | 86658.1 | 0.2868 | 