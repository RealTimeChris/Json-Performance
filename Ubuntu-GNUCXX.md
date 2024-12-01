# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Dec 02, 2024)
#### Using the following commits:
----
| Jsonifier: [c68f3d5](https://github.com/RealTimeChris/Jsonifier/commit/c68f3d5)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [3f87f95](https://github.com/simdjson/simdjson/commit/3f87f95)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1762.33 | 4.63762 | 1.38747e+06 | 2044270 | 5.53123e+07 | 2084.1 | 3.20961 | 1.17325e+06 | 2044270 | 4.67724e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1346.63 | 1.61974 | 1.81587e+06 | 2044270 | 7.23871e+07 | 1906.89 | 6.09138 | 1.28222e+06 | 2044270 | 1.02238e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 838.386 | 5.32364 | 2.91668e+06 | 2044270 | 2.32538e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1511.8 | 2.68273 | 1.6174e+06 | 1571948 | 4.95808e+07 | 1907.15 | 0.954236 | 1.28213e+06 | 1571948 | 3.93028e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1304.79 | 1.70072 | 1.87406e+06 | 1571948 | 5.74471e+07 | 1694.28 | 5.70924 | 1.44321e+06 | 1571948 | 8.84816e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 668.958 | 5.60608 | 3.65538e+06 | 1571948 | 2.24099e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5570.92 | 1.53426 | 438879 | 72401 | 1.74977e+07 | 3140.61 | 4.25841 | 777435 | 72401 | 1.09926e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3563.03 | 0.83888 | 686268 | 72401 | 2.73583e+07 | 2776.61 | 4.95988 | 879373 | 72401 | 2.08886e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3395.04 | 4.97698 | 720207 | 72401 | 2.92862e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5742.78 | 4.73498 | 425665 | 55866 | 1.30523e+07 | 2876.85 | 4.73866 | 848318 | 55866 | 925979 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3553.4 | 0.680646 | 688090 | 55866 | 2.10942e+07 | 2556.55 | 4.47596 | 954854 | 55866 | 1.04199e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3080 | 3.75428 | 793858 | 55866 | 2.43365e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

  This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

  In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1798.33 | 2.26641 | 1.35974e+06 | 2044270 | 5.42051e+07 | 2087.42 | 1.13097 | 1.17142e+06 | 2044270 | 4.66979e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1232.75 | 9.98977 | 1.98362e+06 | 2044270 | 1.58148e+08 | 1914.53 | 5.43655 | 1.27718e+06 | 2044270 | 1.0183e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 428.897 | 2.52434 | 5.70149e+06 | 2044270 | 2.27277e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1490.52 | 2.33026 | 1.64053e+06 | 1571948 | 5.02887e+07 | 1886.21 | 1.27274 | 1.29637e+06 | 1571948 | 3.97391e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1297.05 | 1.92112 | 1.88524e+06 | 1571948 | 5.77897e+07 | 1700.46 | 5.18774 | 1.43797e+06 | 1571948 | 8.81598e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 342.046 | 1.22557 | 7.14919e+06 | 1571948 | 2.19141e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1704.84 | 6.35348 | 1.43347e+06 | 138774 | 6.62235e+06 | 2584.71 | 2.12897 | 945388 | 138774 | 2.56016e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1093.51 | 9.82221 | 2.23531e+06 | 138774 | 1.03246e+07 | 2027.83 | 4.96187 | 1.20497e+06 | 138774 | 3.72007e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 889.897 | 11.0022 | 2.74685e+06 | 138482 | 1.26869e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1460.01 | 7.66538 | 1.67323e+06 | 69037 | 4.50947e+06 | 1995.19 | 1.05368 | 1.22428e+06 | 69037 | 1.64994e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 925.334 | 4.96882 | 2.64128e+06 | 69037 | 5.69211e+06 | 1544.77 | 3.15215 | 1.58148e+06 | 69037 | 2.13102e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 546.546 | 10.6185 | 4.47274e+06 | 68745 | 1.20463e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 883.901 | 2.31345 | 2.76645e+06 | 6661897 | 1.21437e+08 | 1522.27 | 1.70262 | 1.60635e+06 | 6661897 | 2.08677e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 824.342 | 2.88771 | 2.96635e+06 | 6661897 | 1.30211e+08 | 1484.57 | 4.96382 | 1.64713e+06 | 6661897 | 2.48213e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 332.122 | 2.74863 | 7.36263e+06 | 6661897 | 3.2319e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 969.986 | 2.94654 | 2.52094e+06 | 2090234 | 1.02754e+08 | 590.822 | 0.715655 | 4.13882e+06 | 2090234 | 1.68697e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 928.069 | 3.04018 | 2.63485e+06 | 2090234 | 1.07395e+08 | 570.28 | 1.15774 | 4.28797e+06 | 2090234 | 1.74774e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 319.68 | 3.68895 | 7.64939e+06 | 2090234 | 3.11781e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2761.51 | 2.3476 | 885411 | 1439562 | 2.98241e+07 | 3333.26 | 1.84413 | 733510 | 1439562 | 2.05935e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2002.15 | 3.69608 | 1.22128e+06 | 1439584 | 4.11355e+07 | 2221.76 | 3.13169 | 1.10051e+06 | 1439584 | 3.08966e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1909.42 | 2.62363 | 1.28061e+06 | 1423437 | 4.31332e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1875.68 | 4.35515 | 1.30339e+06 | 500299 | 1.27187e+07 | 2365.88 | 1.06841 | 1.03329e+06 | 500299 | 1.00834e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1392.21 | 3.11878 | 1.75614e+06 | 500299 | 1.71355e+07 | 1976.18 | 2.19705 | 1.237e+06 | 500299 | 1.20718e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 651.985 | 3.82797 | 3.7504e+06 | 492910 | 3.659e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2040.27 | 4.88874 | 1.19825e+06 | 719107 | 1.47593e+07 | 3309.44 | 1.24083 | 738681 | 719107 | 1.03612e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1214.98 | 3.70612 | 2.01242e+06 | 719139 | 2.47847e+07 | 2471.34 | 3.60381 | 989158 | 719139 | 1.38755e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 896.415 | 4.98464 | 2.72764e+06 | 723784 | 4.29986e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2020.11 | 4.97695 | 1.21013e+06 | 477674 | 1.34458e+07 | 3134.25 | 1.40118 | 779839 | 477674 | 7.26723e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1120.34 | 3.26022 | 2.18235e+06 | 477706 | 1.98723e+07 | 2543.5 | 4.31218 | 960925 | 477706 | 8.95568e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 680.988 | 4.96079 | 3.59046e+06 | 479183 | 3.26934e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1251.33 | 2.29655 | 1.95393e+06 | 466906 | 1.77921e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1024.11 | 4.95429 | 2.38732e+06 | 466906 | 3.78271e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 832.676 | 4.99899 | 2.93647e+06 | 466906 | 3.68873e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1939.53 | 4.83249 | 1.26062e+06 | 699405 | 1.7195e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1609.86 | 1.88841 | 1.51868e+06 | 699405 | 2.07162e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 3812.55 | 3.16611 | 641116 | 631514 | 7.89837e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1326.94 | 3.42433 | 1.84267e+06 | 631514 | 2.26936e+07 | 