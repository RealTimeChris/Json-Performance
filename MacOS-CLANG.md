# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.4 compiler).  

Latest Results: (Dec 08, 2024)
#### Using the following commits:
----
| Jsonifier: [07fec97](https://github.com/RealTimeChris/Jsonifier/commit/07fec97)  
| Glaze: [57311d9](https://github.com/stephenberry/glaze/commit/57311d9)  
| Simdjson: [6bbcbfb](https://github.com/simdjson/simdjson/commit/6bbcbfb)  

 > 100 iterations on a (Apple M1 (Virtual)).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1976.59 | 0.7126 | 2164460 | 2.08863e+07 | 2807.22 | 0.365782 | 2164460 | 1.47063e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1776.01 | 0.384899 | 2164460 | 2.32453e+07 | 2642.78 | 0.430161 | 2164460 | 1.56214e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 960.144 | 1.75205 | 2164460 | 4.29975e+07 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1660.33 | 1.2176 | 1669395 | 1.91777e+07 | 2237.92 | 3.11357 | 1669395 | 1.4228e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1552.04 | 0.503296 | 1669395 | 2.05158e+07 | 2636.24 | 0.972243 | 1669395 | 1.20782e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 804.437 | 1.81764 | 1669395 | 3.9582e+07 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 5492.85 | 0.522079 | 115376 | 7.51592e+06 | 3600.69 | 3.05432 | 115376 | 611167 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4709.67 | 0.3889 | 115376 | 8.76575e+06 | 3595.56 | 0.333149 | 115376 | 612039 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3594.86 | 0.761573 | 115376 | 1.14841e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 5237.25 | 3.83384 | 91668 | 6.07975e+06 | 5014.61 | 0.810802 | 91668 | 348667 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4085.96 | 0.517604 | 91668 | 7.79284e+06 | 3344.94 | 0.518262 | 91668 | 522709 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3320.05 | 0.796636 | 91668 | 9.59058e+06 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1963.68 | 0.410056 | 2164460 | 2.10237e+07 | 2790.24 | 0.506583 | 2164460 | 1.47958e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1638.64 | 2.72152 | 2164460 | 2.5194e+07 | 2477.11 | 2.92187 | 2164460 | 1.66661e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 461.345 | 0.866003 | 2164460 | 8.94858e+07 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1631.96 | 2.76427 | 1669395 | 1.9511e+07 | 2307.65 | 0.318334 | 1669395 | 1.37981e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1540.56 | 3.54539 | 1669395 | 2.06686e+07 | 2592.26 | 1.59298 | 1669395 | 1.22832e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 361.166 | 1.93167 | 1669395 | 8.81622e+07 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1952.67 | 3.36163 | 138774 | 1.15637e+06 | 4065.89 | 2.19999 | 138774 | 651002 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1623.01 | 1.40802 | 138774 | 1.39125e+06 | 3545.16 | 0.43998 | 138774 | 746625 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1280.11 | 0.883091 | 138482 | 1.76392e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1469.07 | 2.00985 | 69037 | 896335 | 2925.62 | 0.574115 | 69037 | 450084 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1376.36 | 3.83671 | 69037 | 956706 | 4616.22 | 2.13497 | 69037 | 285250 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 757.64 | 2.04246 | 68745 | 1.738e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1380.92 | 1.2387 | 249 | 3.10918e+07 | 2373.46 | 17.0415 | 249 | 2001 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1108.1 | 0.230772 | 6661897 | 3.87469e+07 | 2218.7 | 0.758677 | 6661897 | 5.72703e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 387.852 | 1.99304 | 6661897 | 1.107e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1255.36 | 2.40105 | 2090234 | 3.17584e+07 | 903.345 | 3.92096 | 2090234 | 4.41338e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1239.26 | 3.2247 | 125 | 3.21708e+07 | 1501.38 | 47.1033 | 125 | 1588 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 375.821 | 2.14863 | 2090234 | 1.06083e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2567.97 | 22.927 | 1439562 | 1.28287e+07 | 4503.62 | 0.260942 | 1439562 | 6.09675e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2546.53 | 1.35343 | 1439584 | 1.29368e+07 | 4037.48 | 0.709481 | 1439584 | 6.80075e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1927.3 | 1.5691 | 1423437 | 1.70932e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1859.61 | 1.78146 | 500299 | 5.13141e+06 | 3152.09 | 0.159711 | 500299 | 3.02734e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1550.38 | 14.8515 | 500299 | 6.15492e+06 | 2212.68 | 2.26373 | 500299 | 4.31263e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 711.327 | 2.08109 | 492910 | 1.3415e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2733.22 | 1.25436 | 719139 | 4.40696e+06 | 5009.67 | 1.02272 | 719139 | 2.738e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2030.83 | 1.69154 | 719139 | 5.93117e+06 | 4121.23 | 2.77711 | 719139 | 3.32825e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1173.35 | 3.48099 | 723784 | 1.02657e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2461 | 1.39079 | 477706 | 3.61867e+06 | 5976.07 | 1.17973 | 477706 | 1.52467e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2155.63 | 1.80648 | 477706 | 4.13129e+06 | 4288.78 | 0.407625 | 477706 | 2.1245e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 922.096 | 1.88543 | 479183 | 9.65791e+06 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1552.71 | 1.02511 | 466906 | 5.73546e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1308.19 | 1.33438 | 466906 | 6.8075e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 952.062 | 3.94546 | 466906 | 1.26517e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2169.5 | 1.6493 | 699405 | 6.14891e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1656.21 | 0.915553 | 699405 | 8.05458e+06 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 3451.67 | 1.61468 | 631514 | 3.48967e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1970.65 | 0.596683 | 631514 | 6.11229e+06 | 