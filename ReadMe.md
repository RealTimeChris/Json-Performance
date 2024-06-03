# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (Jul 09, 2024)

 > At least 40 iterations on a 6 core (Intel i7 8700k), until Median Absolute Percentage Error (Mape) reduced below 5.0%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1300.8 | 2691581 | 2.06917e+06 | 0.4732 | 1770.36 | 2687794 | 1.51822e+06 | 0.7271 |
| [glaze](https://github.com/stephenberry/glaze) | 1106.13 | 2691581 | 2.43334e+06 | 0.6753 | 1485.35 | 2691153 | 1.8118e+06 | 0.7151 |
| [simdjson](https://github.com/simdjson/simdjson) | 905.147 | 2691581 | 2.97364e+06 | 3.056 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1306.22 | 1832180 | 1.40266e+06 | 0.672 | 1384.77 | 1828393 | 1.32036e+06 | 0.7768 |
| [glaze](https://github.com/stephenberry/glaze) | 849.959 | 1832180 | 2.15561e+06 | 2.011 | 1110.63 | 1831752 | 1.64929e+06 | 1.131 |
| [simdjson](https://github.com/simdjson/simdjson) | 613.336 | 1832180 | 2.98724e+06 | 2.752 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1303.66 | 2691581 | 2.06464e+06 | 1.138 | 1793.22 | 2687794 | 1.49886e+06 | 0.6846 |
| [glaze](https://github.com/stephenberry/glaze) | 1117.15 | 2691581 | 2.40933e+06 | 0.4935 | 1493.92 | 2691153 | 1.8014e+06 | 0.7834 |
| [simdjson](https://github.com/simdjson/simdjson) | 334.702 | 2691581 | 8.04173e+06 | 0.8612 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1281.61 | 1832180 | 1.42959e+06 | 0.5625 | 1443.65 | 1828393 | 1.26651e+06 | 0.4835 |
| [glaze](https://github.com/stephenberry/glaze) | 870.263 | 1832180 | 2.10532e+06 | 0.3858 | 1134.12 | 1831752 | 1.61514e+06 | 0.6157 |
| [simdjson](https://github.com/simdjson/simdjson) | 230.057 | 1832180 | 7.96404e+06 | 1.232 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1439.2 | 139414 | 96869 | 0.82 | 3197.72 | 139414 | 43598 | 0.4698 |
| [glaze](https://github.com/stephenberry/glaze) | 1391.51 | 139414 | 100189 | 0.3947 | 3169.8 | 139414 | 43982 | 0.7127 |
| [simdjson](https://github.com/simdjson/simdjson) | 1198.46 | 139414 | 116328 | 3.129 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1053.78 | 69397 | 65855 | 0.6838 | 2317.17 | 69397 | 29949 | 0.2604 |
| [glaze](https://github.com/stephenberry/glaze) | 1014.03 | 69397 | 68437 | 0.4549 | 2047.53 | 69397 | 33893 | 2.351 |
| [simdjson](https://github.com/simdjson/simdjson) | 547.831 | 69397 | 126676 | 0.4553 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1828.05 | 6661897 | 3.64426e+06 | 1.177 | 1838.2 | 6661897 | 3.62414e+06 | 1.249 |
| [glaze](https://github.com/stephenberry/glaze) | 1792.89 | 6661897 | 3.71574e+06 | 1.424 | 1715.67 | 6661897 | 3.88297e+06 | 1.85 |
| [simdjson](https://github.com/simdjson/simdjson) | 805.891 | 6661897 | 8.2665e+06 | 0.9601 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1271.99 | 2090234 | 1.64327e+06 | 0.7688 | 704.404 | 2090234 | 2.96738e+06 | 1.149 |
| [glaze](https://github.com/stephenberry/glaze) | 989.474 | 2090234 | 2.11247e+06 | 1.221 | 666.764 | 2090234 | 3.1349e+06 | 0.6582 |
| [simdjson](https://github.com/simdjson/simdjson) | 307.611 | 2090234 | 6.79505e+06 | 1.018 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1353.76 | 705864 | 521410 | 1.896 | 3680.51 | 722038 | 196179 | 0.6816 |
| [glaze](https://github.com/stephenberry/glaze) | 1157.78 | 705864 | 609671 | 2.515 | 3553.82 | 721479 | 203015 | 0.8604 |
| [simdjson](https://github.com/simdjson/simdjson) | 1026.86 | 705864 | 687401 | 0.4638 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1411.41 | 478986 | 339366 | 0.673 | 3025.45 | 478986 | 158319 | 0.1767 |
| [glaze](https://github.com/stephenberry/glaze) | 1313.89 | 478986 | 364555 | 0.198 | 2708.73 | 478427 | 176624 | 1.818 |
| [simdjson](https://github.com/simdjson/simdjson) | 733.915 | 478986 | 652645 | 0.4389 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 791.11 | 69397 | 87721 | 0.2756 |
| [glaze](https://github.com/stephenberry/glaze) | 750.66 | 69397 | 92448 | 0.7319 |
| [simdjson](https://github.com/simdjson/simdjson) | 465.674 | 69397 | 149025 | 0.6036 |

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 2455.79 | 2691581 | 1.09602e+06 | 0.877 |
| [glaze](https://github.com/stephenberry/glaze) | 1986.93 | 2691581 | 1.35464e+06 | 0.6419 |

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1359.23 | 139414 | 102568 | 0.2638 | 