# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.42.34435.0 compiler).  

Latest Results: (Dec 20, 2024)
#### Using the following commits:
----
| Jsonifier: [b0f0b08](https://github.com/RealTimeChris/Jsonifier/commit/b0f0b08)  
| Glaze: [2a19fd5](https://github.com/stephenberry/glaze/commit/2a19fd5)  
| Simdjson: [e7f2463](https://github.com/simdjson/simdjson/commit/e7f2463)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1547.82 | 2.59203 | 1.57997e+06 | 2.04175e+06 | 6.29004e+07 | 1707.75 | 2.04299 | 1.43202e+06 | 2.04175e+06 | 5.70097e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1162.26 | 3.01589 | 2.10408e+06 | 2.04175e+06 | 8.37663e+07 | 1639.95 | 4.12959 | 1.49121e+06 | 2.04175e+06 | 5.93666e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 466.822 | 4.25575 | 5.23852e+06 | 2.04175e+06 | 2.08556e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1309.71 | 1.43772 | 1.86722e+06 | 1.57171e+06 | 5.72227e+07 | 1476.76 | 3.50644 | 1.656e+06 | 1.57171e+06 | 5.07495e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1028.65 | 2.0212 | 2.37738e+06 | 1.57171e+06 | 7.28576e+07 | 1422 | 5.34856 | 1.71977e+06 | 1.57171e+06 | 5.27039e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 376.758 | 1.99376 | 6.49078e+06 | 1.57171e+06 | 1.98921e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 96.9751 | 1.58703 | 2.52182e+07 | 89356 | 4.39373e+07 | 2429.07 | 5.64962 | 1.00761e+06 | 89356 | 1.7541e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 95.2529 | 2.30642 | 2.56742e+07 | 89356 | 4.47317e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 90.2657 | 3.84118 | 2.70929e+07 | 69591 | 3.67621e+07 | 2227.98 | 10.0309 | 1.09917e+06 | 69591 | 1.4894e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 82.8093 | 1.86488 | 2.95321e+07 | 69591 | 4.00723e+07 | 

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
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1556.24 | 2.54971 | 1.57142e+06 | 2.04175e+06 | 6.25601e+07 | 1705.23 | 1.64448 | 1.43413e+06 | 2.04175e+06 | 5.70939e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1167.72 | 3.25037 | 2.09423e+06 | 2.04175e+06 | 8.3375e+07 | 1584.72 | 5.34005 | 1.54319e+06 | 2.04175e+06 | 6.14357e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 99.2751 | 2.38741 | 2.46329e+07 | 2.04175e+06 | 9.80693e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1317.88 | 1.02483 | 1.85563e+06 | 1.57171e+06 | 5.68678e+07 | 1478.87 | 2.14515 | 1.65363e+06 | 1.57171e+06 | 5.06771e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1032.95 | 1.18463 | 2.36749e+06 | 1.57171e+06 | 7.25545e+07 | 1425.15 | 4.18808 | 1.71598e+06 | 1.57171e+06 | 5.25874e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 77.4723 | 2.25285 | 3.15652e+07 | 1.57171e+06 | 9.67379e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1260.05 | 4.6005 | 1.94161e+06 | 138774 | 5.2516e+06 | 1818.18 | 8.50392 | 1.34579e+06 | 138774 | 3.6395e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 874.639 | 25.6513 | 2.7967e+06 | 138774 | 7.5657e+06 | 1710.77 | 15.4602 | 1.43019e+06 | 138774 | 3.868e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 346.303 | 2.79577 | 7.0623e+06 | 138482 | 1.90681e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 830.355 | 15.3739 | 2.94621e+06 | 69037 | 3.9645e+06 | 1541.46 | 2.83761 | 1.58826e+06 | 69037 | 2.1356e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 803.187 | 6.79744 | 3.04591e+06 | 69037 | 4.0986e+06 | 1275.75 | 10.0915 | 1.91836e+06 | 69037 | 2.5804e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 178.151 | 1.11521 | 1.37282e+07 | 68745 | 1.84002e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1493.11 | 1.16012 | 1.63782e+06 | 6.6619e+06 | 2.12753e+08 | 1109.7 | 1.22109 | 2.20369e+06 | 6.6619e+06 | 2.8626e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1045.21 | 0.580408 | 2.33966e+06 | 6.6619e+06 | 3.03924e+08 | 1052.53 | 2.89538 | 2.32338e+06 | 6.6619e+06 | 3.01808e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 441.351 | 4.79592 | 5.54079e+06 | 6.6619e+06 | 7.19754e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 569.474 | 1.0321 | 4.29423e+06 | 2.09023e+06 | 1.75021e+08 | 418.525 | 1.51432 | 5.84302e+06 | 2.09023e+06 | 2.38146e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 382.143 | 1.07898 | 6.39929e+06 | 2.09023e+06 | 2.60819e+08 | 407.332 | 3.31852 | 6.00356e+06 | 2.09023e+06 | 2.4469e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 141.683 | 7.48604 | 1.72599e+07 | 2.09023e+06 | 7.03472e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2168.93 | 3.36096 | 1.12756e+06 | 1.43956e+06 | 3.16487e+07 | 2169.97 | 4.23127 | 1.12709e+06 | 1.43956e+06 | 3.16335e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1164.01 | 1.23396 | 2.10093e+06 | 1.43958e+06 | 5.89727e+07 | 2230.86 | 4.71393 | 1.09624e+06 | 1.43958e+06 | 3.07705e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 605.842 | 0.885461 | 4.03648e+06 | 1.42342e+06 | 1.12032e+08 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1465.35 | 4.63876 | 1.66899e+06 | 500299 | 1.62802e+07 | 1652.84 | 3.83416 | 1.47973e+06 | 500299 | 1.44334e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1291.34 | 2.6735 | 1.89395e+06 | 500299 | 1.84739e+07 | 1205.28 | 5.69898 | 2.02914e+06 | 500299 | 1.9793e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 216.403 | 1.96232 | 1.13006e+07 | 492910 | 1.08611e+08 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 134.741 | 1.88137 | 1.81514e+07 | 44653 | 1.58023e+07 | 3283.3 | 12.8759 | 746546 | 44653 | 648500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 64.0433 | 3.67436 | 3.81874e+07 | 44653 | 3.32466e+07 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 137.244 | 2.17575 | 1.78211e+07 | 37543 | 1.30438e+07 | 4589.05 | 8.99769 | 535645 | 37543 | 390100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 57.1389 | 3.24125 | 4.28005e+07 | 37543 | 3.13305e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1493.85 | 3.02724 | 1.63719e+06 | 719139 | 2.29549e+07 | 2157.87 | 4.63275 | 1.13337e+06 | 719139 | 1.58912e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1042.85 | 2.86508 | 2.34509e+06 | 719139 | 3.28821e+07 | 2195.83 | 5.26046 | 1.11383e+06 | 719139 | 1.56165e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 322.646 | 1.3347 | 7.57947e+06 | 723784 | 1.06968e+08 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1368.12 | 4.65294 | 1.78767e+06 | 477706 | 1.66497e+07 | 2166.27 | 5.56528 | 1.12909e+06 | 477706 | 1.05152e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 882.314 | 2.62268 | 2.77182e+06 | 477706 | 2.58171e+07 | 1951.31 | 6.45559 | 1.25345e+06 | 477706 | 1.16736e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 215.228 | 2.68276 | 1.13623e+07 | 479183 | 1.06163e+08 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 970.604 | 3.74094 | 2.51969e+06 | 466906 | 2.29381e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 905.552 | 1.73229 | 2.7007e+06 | 466906 | 2.45859e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 544.301 | 7.26055 | 4.4929e+06 | 646995 | 5.66803e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1277.16 | 1.67695 | 1.91489e+06 | 699405 | 2.61129e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1241.8 | 3.70974 | 1.96941e+06 | 699405 | 2.68563e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2015.99 | 2.86345 | 1.21315e+06 | 646995 | 1.53032e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 687.382 | 2.29958 | 3.55774e+06 | 646995 | 4.48821e+07 | 