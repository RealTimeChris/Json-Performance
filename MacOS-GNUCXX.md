# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Dec 08, 2024)
#### Using the following commits:
----
| Jsonifier: [07fec97](https://github.com/RealTimeChris/Jsonifier/commit/07fec97)  
| Glaze: [57311d9](https://github.com/stephenberry/glaze/commit/57311d9)  
| Simdjson: [6bbcbfb](https://github.com/simdjson/simdjson/commit/6bbcbfb)  

 > 100 iterations on a (Apple M1 (Virtual)).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2001.29 | 0.646047 | 2084518 | 1.98667e+07 | 2798.72 | 0.788146 | 2084518 | 1.42061e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1771.04 | 0.491609 | 2084518 | 2.24495e+07 | 2712.65 | 0.75759 | 2084518 | 1.46569e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 990.19 | 0.62779 | 2084518 | 4.01529e+07 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1616.27 | 0.582453 | 1613080 | 1.90359e+07 | 2650.74 | 0.469167 | 1613080 | 1.1607e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1614.19 | 0.517907 | 1613080 | 1.90604e+07 | 2349.04 | 3.53915 | 1613080 | 1.30977e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 832.973 | 0.586041 | 1613080 | 3.69365e+07 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 5723.4 | 0.888933 | 63629 | 6.94675e+06 | 4221.96 | 3.17823 | 63629 | 287456 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4850.14 | 0.65065 | 63629 | 8.1975e+06 | 3726.58 | 0.97277 | 63629 | 325668 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3819.28 | 1.1616 | 63629 | 1.04101e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 5584.96 | 1.94697 | 49304 | 5.50892e+06 | 4873.57 | 1.53349 | 49304 | 192959 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 4299.05 | 0.675869 | 49304 | 7.15671e+06 | 3503.53 | 3.13507 | 49304 | 268415 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 3618.48 | 1.90422 | 49304 | 8.50275e+06 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1946.21 | 2.68304 | 2084518 | 2.0429e+07 | 2724.1 | 0.915466 | 2084518 | 1.45953e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1720.4 | 0.830947 | 2084518 | 2.31104e+07 | 2565.86 | 2.68592 | 2084518 | 1.54954e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 474.505 | 3.29054 | 2084518 | 8.37905e+07 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1616.5 | 0.563461 | 1613080 | 1.90331e+07 | 2406.16 | 0.411628 | 1613080 | 1.27868e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1590.73 | 1.71785 | 1613080 | 1.93414e+07 | 2631.88 | 0.749573 | 1613080 | 1.16901e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 384.729 | 1.59625 | 1613080 | 7.99707e+07 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2002.23 | 2.90401 | 138774 | 1.12775e+06 | 4027.74 | 2.48475 | 138774 | 657169 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1313.15 | 2.63913 | 138482 | 1.71954e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1080.26 | 1.32759 | 138774 | 2.09025e+06 | 3374.9 | 1.82228 | 138774 | 784292 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1524.86 | 1.47312 | 69037 | 863541 | 4635.18 | 1.7259 | 69037 | 284083 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 819.527 | 2.44294 | 68745 | 1.60675e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 768.211 | 1.06535 | 69037 | 1.71408e+06 | 2987.55 | 0.547698 | 69037 | 440754 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1390.87 | 1.38848 | 249 | 3.08695e+07 | 2426.83 | 15.1763 | 249 | 1957 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1091.42 | 2.2176 | 6661897 | 3.9339e+07 | 2175.64 | 2.61492 | 6661897 | 5.84039e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 399.149 | 1.15181 | 6661897 | 1.07567e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1276.5 | 3.31334 | 125 | 3.12323e+07 | 1846.77 | 36.4833 | 125 | 1291 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1273.9 | 0.411124 | 2090234 | 3.12962e+07 | 947.538 | 0.941778 | 2090234 | 4.20754e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 388.41 | 1.05879 | 2090234 | 1.02644e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 3253.45 | 1.46451 | 1439562 | 1.01258e+07 | 4557.04 | 0.488773 | 1439562 | 6.02529e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2096.31 | 0.79099 | 1439584 | 1.57151e+07 | 3914.17 | 0.594127 | 1439584 | 7.015e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 2008.94 | 1.49553 | 1423437 | 1.63986e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1862.44 | 1.58335 | 500299 | 5.12362e+06 | 3166.69 | 0.305239 | 500299 | 3.01338e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 993.785 | 0.725079 | 500299 | 9.60212e+06 | 2192.7 | 2.57167 | 500299 | 4.35192e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 718.535 | 3.24099 | 492910 | 1.32804e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2769.46 | 1.28648 | 719139 | 4.34929e+06 | 5022.28 | 0.865028 | 719139 | 2.73112e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1288.7 | 1.07085 | 719139 | 9.34675e+06 | 3966.55 | 3.6547 | 719139 | 3.45804e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1222.17 | 3.62456 | 723784 | 9.85554e+06 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2474.19 | 3.13152 | 477706 | 3.59938e+06 | 5951.51 | 3.27494 | 477706 | 1.53096e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1114.56 | 1.0659 | 477706 | 7.99017e+06 | 4357.59 | 0.921875 | 477706 | 2.09096e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 964.028 | 1.68147 | 479183 | 9.23783e+06 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1585.51 | 1.16032 | 466906 | 5.61683e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1200.74 | 0.764585 | 466906 | 7.41671e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 990.113 | 2.9904 | 466906 | 1.21655e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1996.37 | 2.01532 | 699405 | 6.68217e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1675.09 | 1.74278 | 699405 | 7.96379e+06 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 3220.67 | 2.00433 | 631514 | 3.73996e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1951.76 | 0.604331 | 631514 | 6.17146e+06 | 