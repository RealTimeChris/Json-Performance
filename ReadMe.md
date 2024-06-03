# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (Jul 01, 2024)

 > At least 40 iterations on a 6 core (Intel i7 8700k), until Median Absolute Percentage Error (Mape) reduced below 5.0%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1314.75 | 2101890 | 1.5987e+06 | 0.7169 | 1804.7 | 2098863 | 1.163e+06 | 0.4941 |
| [glaze](https://github.com/stephenberry/glaze) | 1116.36 | 2101890 | 1.8828e+06 | 0.575 | 1549.61 | 2101575 | 1.3562e+06 | 1.144 |
| [simdjson](https://github.com/simdjson/simdjson) | 848.186 | 2101890 | 2.4781e+06 | 2.182 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1220.21 | 1422890 | 1.1661e+06 | 0.974 | 1346.61 | 1419863 | 1.0544e+06 | 1.435 |
| [glaze](https://github.com/stephenberry/glaze) | 882.686 | 1422890 | 1.612e+06 | 0.6194 | 1101.06 | 1422575 | 1.292e+06 | 0.3095 |
| [simdjson](https://github.com/simdjson/simdjson) | 587.219 | 1422890 | 2.4231e+06 | 0.7142 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1263.84 | 2101890 | 1.6631e+06 | 1.127 | 1809.52 | 2098863 | 1.1599e+06 | 0.5596 |
| [glaze](https://github.com/stephenberry/glaze) | 1090.76 | 2101890 | 1.927e+06 | 1.249 | 1567.29 | 2101575 | 1.3409e+06 | 1.221 |
| [simdjson](https://github.com/simdjson/simdjson) | 320.342 | 2101890 | 6.5614e+06 | 0.9187 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1198.22 | 1422890 | 1.1875e+06 | 0.6854 | 1399.71 | 1419863 | 1.0144e+06 | 0.3871 |
| [glaze](https://github.com/stephenberry/glaze) | 874.44 | 1422890 | 1.6272e+06 | 0.4671 | 1136.79 | 1422575 | 1.2514e+06 | 0.3987 |
| [simdjson](https://github.com/simdjson/simdjson) | 200.624 | 1422890 | 7.0923e+06 | 0.8102 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1611.72 | 139414 | 86500 | 0.2312 | 3494.09 | 139414 | 39900 | 0.25 |
| [glaze](https://github.com/stephenberry/glaze) | 1452.23 | 139414 | 96000 | 0.1041 | 3408.66 | 139414 | 40900 | 2.499 |
| [simdjson](https://github.com/simdjson/simdjson) | 1204.96 | 139414 | 115700 | 0.3008 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1117.5 | 69397 | 62100 | 0.161 | 2487.35 | 69397 | 27900 | 1.246 |
| [glaze](https://github.com/stephenberry/glaze) | 1008.68 | 69397 | 68800 | 0.1453 | 2090.27 | 69397 | 33200 | 1.529 |
| [simdjson](https://github.com/simdjson/simdjson) | 607.68 | 69397 | 114200 | 0.3055 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1945.59 | 6661897 | 3.4241e+06 | 1.123 | 1880.88 | 6661897 | 3.5419e+06 | 0.8807 |
| [glaze](https://github.com/stephenberry/glaze) | 1836.14 | 6661897 | 3.6282e+06 | 1.523 | 1833.41 | 6661897 | 3.6336e+06 | 1.007 |
| [simdjson](https://github.com/simdjson/simdjson) | 945.231 | 6661897 | 7.0479e+06 | 0.6345 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1198.87 | 2090234 | 1.7435e+06 | 0.7154 | 704.85 | 2090234 | 2.9655e+06 | 2.267 |
| [glaze](https://github.com/stephenberry/glaze) | 1039.3 | 2090234 | 2.01119e+06 | 1.502 | 665.489 | 2090234 | 3.1409e+06 | 0.6352 |
| [simdjson](https://github.com/simdjson/simdjson) | 290.819 | 2090234 | 7.1874e+06 | 0.4425 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1440.24 | 705864 | 490100 | 3.898 | 3804.2 | 722038 | 189800 | 0.5762 |
| [glaze](https://github.com/stephenberry/glaze) | 1381.07 | 705864 | 511100 | 1.754 | 3235.33 | 721479 | 223000 | 1.118 |
| [simdjson](https://github.com/simdjson/simdjson) | 1073.56 | 705864 | 657500 | 0.5491 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1505.3 | 478986 | 318200 | 0.2044 | 3265.07 | 478986 | 146700 | 0.06807 |
| [glaze](https://github.com/stephenberry/glaze) | 1237.05 | 478986 | 387200 | 1.801 | 2955.08 | 478427 | 161900 | 1.605 |
| [simdjson](https://github.com/simdjson/simdjson) | 713.839 | 478986 | 671000 | 2.173 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 805.07 | 69397 | 86200 | 0.4689 |
| [glaze](https://github.com/stephenberry/glaze) | 779.742 | 69397 | 89000 | 0.5028 |
| [simdjson](https://github.com/simdjson/simdjson) | 472.732 | 69397 | 146800 | 0.4749 |

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns) | WriteMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 2461.81 | 2101890 | 853800 | 0.439 |
| [glaze](https://github.com/stephenberry/glaze) | 2097.69 | 2101890 | 1.002e+06 | 0.5114 |

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | ReadMape (%) |
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1426.96 | 139414 | 97700 | 0.2047 | 