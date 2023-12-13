# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Ubuntu-22.04 using the Clang++18 compiler)

Latest Results: (May 17, 2024

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1069.59 | 2519465 | 2.35555e+06 | 1367.68 | 2519465 | 1.84215e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 827.315 | 2519465 | 3.04535e+06 | 951.621 | 2519465 | 2.64755e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 670.534 | 2519465 | 3.7574e+06 | N/A | N/A | N/A |

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 750.145 | 1714268 | 2.28525e+06 | 987.027 | 1714268 | 1.7368e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 655.226 | 1714268 | 2.6163e+06 | 831.16 | 1714268 | 2.0625e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 486.124 | 1714268 | 3.5264e+06 | N/A | N/A | N/A |

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.
> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1044.75 | 2519465 | 2.41155e+06 | 1110.17 | 2519465 | 2.26945e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 967.147 | 2519465 | 2.60505e+06 | 1071.36 | 2519465 | 2.35165e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 218.662 | 2519465 | 1.15222e+07 | N/A | N/A | N/A |

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 807.722 | 1714268 | 2.12235e+06 | 1186.88 | 1714268 | 1.44435e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 661.458 | 1714268 | 2.59165e+06 | 792.597 | 1714268 | 2.16285e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 149.744 | 1714268 | 1.1448e+07 | N/A | N/A | N/A |

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1498.85 | 136695 | 91200 | 2391.86 | 136695 | 57150 |
| [simdjson](https://github.com/simdjson/simdjson) | 851.417 | 136695 | 160550 | N/A | N/A | N/A |
| [glaze](https://github.com/stephenberry/glaze) | 816.09 | 136695 | 167500 | 1396.45 | 136712 | 97900 |

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 969.788 | 73025 | 75300 | 1947.33 | 73025 | 37500 |
| [glaze](https://github.com/stephenberry/glaze) | 579.563 | 73025 | 126000 | 1213.04 | 73025 | 60200 |
| [simdjson](https://github.com/simdjson/simdjson) | 476.664 | 73025 | 153200 | N/A | N/A | N/A |

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1222.2 | 6661897 | 5.45075e+06 | 1179.82 | 6661897 | 5.64655e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 1170.77 | 6661897 | 5.6902e+06 | 1061.44 | 6661897 | 6.2763e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 1068.69 | 6661897 | 6.2337e+06 | N/A | N/A | N/A |

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 670.85 | 2090234 | 3.1158e+06 | 613.944 | 2090234 | 3.4046e+06 |
| [glaze](https://github.com/stephenberry/glaze) | 595.958 | 2090234 | 3.50735e+06 | 377.711 | 2090234 | 5.53395e+06 |
| [simdjson](https://github.com/simdjson/simdjson) | 366.178 | 2090234 | 5.70825e+06 | N/A | N/A | N/A |

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1368.75 | 399674 | 292000 | 3008.46 | 399674 | 132850 |
| [simdjson](https://github.com/simdjson/simdjson) | 1298.28 | 399674 | 307850 | N/A | N/A | N/A |
| [glaze](https://github.com/stephenberry/glaze) | 838.242 | 399674 | 476800 | 2302.27 | 399674 | 173600 |

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 878.109 | 268921 | 306250 | 2592.01 | 268921 | 103750 |
| [glaze](https://github.com/stephenberry/glaze) | 592.598 | 268921 | 453800 | 1586.55 | 268921 | 169500 |
| [simdjson](https://github.com/simdjson/simdjson) | 385.743 | 268921 | 697150 | N/A | N/A | N/A |

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | N/A | N/A | N/A | 771.934 | 73025 | 94600 |
| [glaze](https://github.com/stephenberry/glaze) | N/A | N/A | N/A | 612.112 | 73025 | 119300 |
| [simdjson](https://github.com/simdjson/simdjson) | N/A | N/A | N/A | 233.531 | 73025 | 312700 |

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | N/A | N/A | N/A | 1557.39 | 2519465 | 1.61775e+06 |
| [glaze](https://github.com/stephenberry/glaze) | N/A | N/A | N/A | 1533.87 | 2519465 | 1.64255e+06 |

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>

> 100 iterations on a 6 core (Intel i7 8700k)

| Library | Read (MB/s) | ReadLength (Bytes) | ReadTime (ns) | Write (MB/s) | WriteLength (Bytes) | WriteTime (ns)
| ------------------------------------------------- | ---------- | ----------- | ---------- | ----------- | ---------- | ---------- |
| [jsonifier](https://github.com/realtimechris/jsonifier) | 1239.86 | 136695 | 110250 | N/A | N/A | N/A |