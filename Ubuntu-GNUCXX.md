# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Dec 20, 2024)
#### Using the following commits:
----
| Jsonifier: [b0f0b08](https://github.com/RealTimeChris/Jsonifier/commit/b0f0b08)  
| Glaze: [2a19fd5](https://github.com/stephenberry/glaze/commit/2a19fd5)  
| Simdjson: [e7f2463](https://github.com/simdjson/simdjson/commit/e7f2463)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1810.05 | 1.18106 | 1.35133e+06 | 2.09377e+06 | 5.5158e+07 | 1746.34 | 4.76196 | 1.40065e+06 | 2.09377e+06 | 5.71704e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1367.83 | 0.840678 | 1.78823e+06 | 2.09377e+06 | 7.29905e+07 | 1969.48 | 2.83815 | 1.24208e+06 | 2.09377e+06 | 5.0693e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 943.731 | 7.95115 | 2.59155e+06 | 2.09377e+06 | 1.05792e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1519.76 | 1.1748 | 1.60937e+06 | 1.60735e+06 | 5.04318e+07 | 1743.01 | 1.15064 | 1.40333e+06 | 1.60735e+06 | 4.39725e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1294.32 | 0.826256 | 1.88977e+06 | 1.60735e+06 | 5.92157e+07 | 1734.38 | 1.82782 | 1.41039e+06 | 1.60735e+06 | 4.41911e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 808.5 | 1.89695 | 3.02483e+06 | 1.60735e+06 | 9.47981e+07 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 124.117 | 1.1725 | 1.97132e+07 | 72301 | 2.77768e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 79.2054 | 1.9046 | 3.08851e+07 | 72301 | 4.35271e+07 | 2597.04 | 5.47667 | 951899 | 72301 | 1.3275e+06 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 106.781 | 1.59084 | 2.29154e+07 | 53693 | 2.39769e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 78.8452 | 2.2546 | 3.103e+07 | 53693 | 3.24723e+07 | 2390.76 | 5.55678 | 1.03695e+06 | 53693 | 1.07091e+06 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1782.99 | 0.988526 | 1.37186e+06 | 2.09377e+06 | 5.59953e+07 | 1913.74 | 1.82506 | 1.27813e+06 | 2.09377e+06 | 5.21696e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1375.83 | 0.63947 | 1.77774e+06 | 2.09377e+06 | 7.25664e+07 | 1923.75 | 4.07193 | 1.27145e+06 | 2.09377e+06 | 5.1898e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 402.684 | 1.12015 | 6.07298e+06 | 2.09377e+06 | 2.47934e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1465.65 | 4.47117 | 1.66892e+06 | 1.60735e+06 | 5.22937e+07 | 1627.35 | 1.71424 | 1.50311e+06 | 1.60735e+06 | 4.70976e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1300.74 | 0.853441 | 1.88047e+06 | 1.60735e+06 | 5.89237e+07 | 1710.81 | 2.3548 | 1.42984e+06 | 1.60735e+06 | 4.47999e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 315.779 | 1.28528 | 7.74435e+06 | 1.60735e+06 | 2.42715e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1716.18 | 3.79698 | 1.43146e+06 | 138774 | 3.8558e+06 | 2384.6 | 4.34408 | 1.03137e+06 | 138774 | 2.775e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 1143.61 | 2.67801 | 2.14462e+06 | 138482 | 5.77413e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1140.47 | 1.66495 | 2.15043e+06 | 138774 | 5.8022e+06 | 1890.9 | 3.59252 | 1.29927e+06 | 138774 | 3.49952e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1275.98 | 4.08308 | 1.92866e+06 | 69037 | 2.57994e+06 | 1881.38 | 2.94899 | 1.31242e+06 | 69037 | 1.74975e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 688.866 | 1.65387 | 3.5622e+06 | 69037 | 4.77878e+06 | 1542.03 | 3.30057 | 1.59954e+06 | 69037 | 2.13481e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 582.127 | 4.6004 | 4.21208e+06 | 68745 | 5.6311e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2500.24 | 0.634882 | 978204 | 6.6619e+06 | 1.27053e+08 | 1403.6 | 0.491147 | 1.74237e+06 | 6.6619e+06 | 2.2632e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2285.78 | 1.54706 | 1.06998e+06 | 6.6619e+06 | 1.38974e+08 | 1538.77 | 1.50254 | 1.58933e+06 | 6.6619e+06 | 2.0644e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 979.344 | 1.39131 | 2.49713e+06 | 6.6619e+06 | 3.24364e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 952.658 | 0.631802 | 2.56731e+06 | 2.09023e+06 | 1.04623e+08 | 566.382 | 0.747004 | 4.31802e+06 | 2.09023e+06 | 1.75977e+08 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 947.565 | 0.625354 | 2.58118e+06 | 2.09023e+06 | 1.05186e+08 | 560.491 | 0.359147 | 4.36349e+06 | 2.09023e+06 | 1.77826e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 314.268 | 1.69061 | 7.78177e+06 | 2.09023e+06 | 3.1715e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2836.5 | 1.55053 | 862583 | 1.43956e+06 | 2.42001e+07 | 2755.74 | 1.53808 | 887853 | 1.43956e+06 | 2.49093e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1764.14 | 0.707363 | 1.38668e+06 | 1.43958e+06 | 3.89111e+07 | 2294.94 | 2.65636 | 1.06604e+06 | 1.43958e+06 | 2.99113e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 1691.36 | 1.26298 | 1.4463e+06 | 1.42342e+06 | 4.01296e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1811.91 | 2.064 | 1.35097e+06 | 500299 | 1.31663e+07 | 2052.13 | 2.18362 | 1.19308e+06 | 500299 | 1.1625e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 950.729 | 0.899008 | 2.57349e+06 | 500299 | 2.50924e+07 | 1991.18 | 2.49699 | 1.22949e+06 | 500299 | 1.19809e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 635.969 | 1.4668 | 3.84685e+06 | 492910 | 3.69574e+07 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 179.617 | 2.15648 | 1.36311e+07 | 44653 | 1.18542e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 154.064 | 1.71183 | 1.58878e+07 | 44653 | 1.38204e+07 | 4280.75 | 6.84447 | 586743 | 44653 | 497394 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 167.565 | 1.78757 | 1.46119e+07 | 37543 | 1.06835e+07 | 5991.95 | 10.9671 | 426870 | 37543 | 298766 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 163.431 | 2.75252 | 1.49818e+07 | 37543 | 1.09538e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1980.83 | 2.62894 | 1.2358e+06 | 719139 | 1.73115e+07 | 2783.41 | 1.58886 | 879759 | 719139 | 1.23198e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1355.98 | 1.53447 | 1.80463e+06 | 719139 | 2.52889e+07 | 2307.18 | 4.65541 | 1.06112e+06 | 719139 | 1.48628e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 1040.88 | 1.93373 | 2.35039e+06 | 723784 | 3.31572e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1915.54 | 2.84713 | 1.27844e+06 | 477706 | 1.18916e+07 | 2674.99 | 2.87204 | 915897 | 477706 | 8.51547e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1077.99 | 1.34141 | 2.27043e+06 | 477706 | 2.11307e+07 | 2539.04 | 4.32971 | 965002 | 477706 | 8.97144e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 709.642 | 1.90985 | 3.44786e+06 | 479183 | 3.21982e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1260.03 | 1.56716 | 1.94265e+06 | 466906 | 1.76693e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 991.087 | 1.00196 | 2.46922e+06 | 466906 | 2.2464e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 904.642 | 1.5867 | 2.70461e+06 | 631514 | 3.32871e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2009.82 | 1.76129 | 1.218e+06 | 699405 | 1.65937e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1354.62 | 1.61658 | 1.80648e+06 | 699405 | 2.46196e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2279.85 | 1.01402 | 1.07398e+06 | 631514 | 1.32083e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 986.617 | 1.86626 | 2.48003e+06 | 631514 | 3.05214e+07 | 