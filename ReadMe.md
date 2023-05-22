# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (Jan 01, 2024)

### Single Iteration Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/JsonData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Single%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Single%20Test_Results.png?raw=true" 
alt="SingleCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - simd](https://github.com/realtimechris/Jsonifier) | 826.725 | 872.979 |
| [simdjson](https://github.com/simdjson/simdjson) | 697.923 | N/A |
| [glaze](https://github.com/stephenberry/glaze) | 684.835 | 839.95 |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | 181.501 | 904.916 |

### Multi Iteration Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/JsonData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Multi%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Multi%20Test_Results.png?raw=true" 
alt="MinifyCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | 1391.68 | 1133.04 |
| [jsonifier - simd](https://github.com/realtimechris/Jsonifier) | 1249.19 | 1127.2 |
| [glaze](https://github.com/stephenberry/glaze) | 998.753 | 1021.79 |
| [simdjson](https://github.com/simdjson/simdjson) | 855.698 | N/A |
> 400 iterations on a 6 core (Intel i7 8700k)

### ABC Test (Out of Sequence Performance) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/JsonData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Abc%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Abc%20Test_Results.png?raw=true" 
alt="AbcCoreAPI WebSite" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | 1418.04 | 1144.95 |
| [jsonifier - simd](https://github.com/realtimechris/Jsonifier) | 1320.69 | 1144.35 |
| [glaze](https://github.com/stephenberry/glaze) | 1002.22 | 1042.54 |
| [simdjson](https://github.com/simdjson/simdjson) | 388.683 | N/A |
> 400 iterations on a 6 core (Intel i7 8700k)

### Discord Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/DiscordData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Discord%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Discord%20Test_Results.png?raw=true" 
alt="DiscordCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - simd](https://github.com/realtimechris/Jsonifier) | 1935.13 | 1914.83 |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | 1415.12 | 1929.76 |
| [glaze](https://github.com/stephenberry/glaze) | 1174.71 | 2048.1 |
| [simdjson](https://github.com/simdjson/simdjson) | 222.758 | N/A |
> 400 iterations on a 6 core (Intel i7 8700k)

### Twitter Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/twitter.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Twitter%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Twitter%20Test_Results.png?raw=true" 
alt="TwitterCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - simd](https://github.com/realtimechris/Jsonifier) | 1598.77 | 2650.6 |
| [glaze](https://github.com/stephenberry/glaze) | 1453.76 | 2504.09 |
| [simdjson](https://github.com/simdjson/simdjson) | 1211.19 | N/A |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | 1154.29 | 2602.63 |
> 400 iterations on a 6 core (Intel i7 8700k)

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/DiscordData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Minify%20Test_Results.png?raw=true" 
alt="MinifyCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/Jsonifier) | N/A | 1819.23 |
| [simdjson](https://github.com/simdjson/simdjson) | N/A | 1013.69 |
> 400 iterations on a 6 core (Intel i7 8700k)

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="PrettifyCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier - serial](https://github.com/realtimechris/Jsonifier) | N/A | 866.743 |
| [glaze](https://github.com/stephenberry/glaze) | N/A | 235.332 |
> 400 iterations on a 6 core (Intel i7 8700k)

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/Testing/Json/DiscordData.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/Testing/Graphs/Validate%20Test_Results.png?raw=true" 
alt="ValidateCoreAPI WebSite" width="400"/></p>


| Library | Read (MB/s) | Write (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [jsonifier](https://github.com/realtimechris/Jsonifier) | 1139.3 | N/A |
> 400 iterations on a 6 core (Intel i7 8700k)