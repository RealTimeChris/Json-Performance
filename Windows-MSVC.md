# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.42.34435.0 compiler).  

Latest Results: (Dec 08, 2024)
#### Using the following commits:
----
| Jsonifier: [07fec97](https://github.com/RealTimeChris/Jsonifier/commit/07fec97)  
| Glaze: [57311d9](https://github.com/stephenberry/glaze/commit/57311d9)  
| Simdjson: [6bbcbfb](https://github.com/simdjson/simdjson/commit/6bbcbfb)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1564.54 | 1.26962 | 1.5629e+06 | 2004765 | 2.44403e+07 | 1855.26 | 2.59334 | 1.31799e+06 | 2004765 | 2.06105e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1205.03 | 0.516515 | 2.02928e+06 | 2004765 | 3.17319e+07 | 1654.58 | 3.40238 | 1.47784e+06 | 2004765 | 2.31103e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 480.635 | 1.31352 | 5.0876e+06 | 2004765 | 7.9557e+07 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1288.42 | 1.16248 | 1.89784e+06 | 1541039 | 2.28132e+07 | 1639.4 | 0.865074 | 1.49154e+06 | 1541039 | 1.79291e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1062.45 | 1.44332 | 2.30149e+06 | 1541039 | 2.76653e+07 | 1430.08 | 3.12065 | 1.7098e+06 | 1541039 | 2.05534e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 380.028 | 0.362277 | 6.43472e+06 | 1541039 | 7.73442e+07 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 4383.47 | 2.37528 | 557793 | 73479 | 8.7232e+06 | 2839.35 | 2.35008 | 859587 | 73479 | 493600 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 3807.34 | 0.430142 | 642213 | 73479 | 1.00432e+07 | 2485.81 | 1.02873 | 982973 | 73479 | 563800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 2294.17 | 1.34034 | 1.06582e+06 | 73479 | 1.66674e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 5509.15 | 1.59879 | 443769 | 56970 | 5.3353e+06 | 2615.83 | 3.22581 | 933044 | 56970 | 415400 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 3689.67 | 0.706727 | 662678 | 56970 | 7.9663e+06 | 2206.78 | 3.33063 | 1.10645e+06 | 56970 | 492400 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 1960.12 | 1.05032 | 1.24749e+06 | 56970 | 1.49955e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1548.96 | 1.3781 | 1.57866e+06 | 2004765 | 2.46862e+07 | 1847.98 | 2.43431 | 1.32317e+06 | 2004765 | 2.06917e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1199.44 | 1.21017 | 2.03864e+06 | 2004765 | 3.18798e+07 | 1648.5 | 3.292 | 1.48328e+06 | 2004765 | 2.31956e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 101.513 | 1.23771 | 2.40891e+07 | 2004765 | 3.76678e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1277.37 | 1.54103 | 1.91429e+06 | 1541039 | 2.30106e+07 | 1598.71 | 2.79243 | 1.5295e+06 | 1541039 | 1.83854e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1065.01 | 0.908376 | 2.29595e+06 | 1541039 | 2.75987e+07 | 1431.42 | 0.906297 | 1.70815e+06 | 1541039 | 2.05341e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 78.6291 | 0.963115 | 3.11e+07 | 1541039 | 3.73818e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1066.96 | 3.07769 | 2.29042e+06 | 138774 | 2.1997e+06 | 2075.84 | 1.18422 | 1.17747e+06 | 138774 | 1.2751e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1062.56 | 2.57153 | 2.30058e+06 | 138774 | 2.2088e+06 | 1871.13 | 0.749328 | 1.30609e+06 | 138774 | 1.4146e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 311.243 | 0.804965 | 7.85607e+06 | 138482 | 7.5407e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 849.588 | 0.896832 | 2.87608e+06 | 69037 | 1.5499e+06 | 1772.48 | 0.659577 | 1.37811e+06 | 69037 | 742900 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 797.321 | 3.60279 | 3.0649e+06 | 69037 | 1.6515e+06 | 1283.28 | 1.37414 | 1.9036e+06 | 69037 | 1.0261e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 177.791 | 1.40826 | 1.37514e+07 | 68745 | 7.4063e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1279.72 | 3.55521 | 1.91063e+06 | 249 | 3.35508e+07 | 1158.37 | 2.43902 | 1.73289e+06 | 249 | 4100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 369.495 | 0.993541 | 6.61794e+06 | 6661897 | 1.162e+08 | 1058.15 | 3.67305 | 2.31092e+06 | 6661897 | 1.20083e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 150.344 | 3.78642 | 1.62648e+07 | 6661897 | 2.85581e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1394.99 | 2.93708 | 1.75265e+06 | 125 | 2.85794e+07 | 953.674 | 20 | 2.16804e+06 | 125 | 2500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 379.1 | 2.05667 | 6.45027e+06 | 2090234 | 1.05165e+08 | 421.079 | 1.02956 | 5.80739e+06 | 2090234 | 9.46808e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 142.29 | 3.60146 | 1.71854e+07 | 2090234 | 2.80189e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2124.95 | 3.47386 | 1.15065e+06 | 1439562 | 1.59563e+07 | 2632.04 | 2.1089 | 928924 | 1439562 | 1.0432e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 2000.96 | 0.525816 | 1.22201e+06 | 1439584 | 1.69451e+07 | 2228.6 | 2.48931 | 1.09711e+06 | 1439584 | 1.23207e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 714.047 | 1.72434 | 3.42451e+06 | 1423437 | 4.74848e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1409.04 | 0.919924 | 1.7338e+06 | 500299 | 6.7723e+06 | 1974.07 | 0.659923 | 1.23811e+06 | 500299 | 4.8339e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1285.63 | 1.51433 | 1.90163e+06 | 500299 | 7.4224e+06 | 1185.78 | 2.99973 | 2.06195e+06 | 500299 | 8.0474e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 219.667 | 0.788663 | 1.1132e+07 | 492910 | 4.34406e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1337.95 | 1.09938 | 1.82741e+06 | 719139 | 9.2234e+06 | 2579.01 | 0.723888 | 947978 | 719139 | 5.3185e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 921.122 | 2.78566 | 2.65452e+06 | 719139 | 1.33972e+07 | 2304.25 | 1.52368 | 1.06093e+06 | 719139 | 5.9527e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 287.974 | 1.91027 | 8.4912e+06 | 723784 | 4.28526e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1201.81 | 2.64639 | 2.0343e+06 | 477706 | 7.4101e+06 | 2639.64 | 1.09508 | 926056 | 477706 | 3.4518e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 901.588 | 1.59553 | 2.71193e+06 | 477706 | 9.8776e+06 | 2114.29 | 0.498898 | 1.15599e+06 | 477706 | 4.3095e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 212.163 | 1.98905 | 1.15255e+07 | 479183 | 4.19749e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 981.552 | 3.2283 | 2.49082e+06 | 466906 | 9.0729e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 909.404 | 0.80366 | 2.68858e+06 | 466906 | 9.7927e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/6bbcbfb) | 534.276 | 10.8042 | 4.57651e+06 | 466906 | 2.30975e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1225.39 | 0.830394 | 1.99536e+06 | 699405 | 1.08864e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 1114.32 | 2.91943 | 2.19428e+06 | 699405 | 1.19715e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/07fec97) | 2573.72 | 0.642363 | 950019 | 646995 | 4.7948e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/57311d9) | 1164.54 | 0.724747 | 2.09969e+06 | 646995 | 1.05968e+07 | 