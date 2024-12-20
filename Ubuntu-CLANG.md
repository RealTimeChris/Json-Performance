# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Dec 20, 2024)
#### Using the following commits:
----
| Jsonifier: [b0f0b08](https://github.com/RealTimeChris/Jsonifier/commit/b0f0b08)  
| Glaze: [2a19fd5](https://github.com/stephenberry/glaze/commit/2a19fd5)  
| Simdjson: [e7f2463](https://github.com/simdjson/simdjson/commit/e7f2463)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1771.5 | 1.01196 | 1.38049e+06 | 1.98863e+06 | 5.35283e+07 | 2024.3 | 2.0541 | 1.20809e+06 | 1.98863e+06 | 4.68435e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1441.56 | 0.907235 | 1.69646e+06 | 1.98863e+06 | 6.57797e+07 | 2014.86 | 2.874 | 1.21374e+06 | 1.98863e+06 | 4.70631e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 790.025 | 1.75681 | 3.09541e+06 | 1.98863e+06 | 1.20028e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1555.58 | 1.39096 | 1.5721e+06 | 1.53702e+06 | 4.71147e+07 | 1827.05 | 1.2729 | 1.33852e+06 | 1.53702e+06 | 4.01142e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1379.79 | 1.15978 | 1.77241e+06 | 1.53702e+06 | 5.31172e+07 | 1760.19 | 2.80204 | 1.38936e+06 | 1.53702e+06 | 4.16379e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 640.706 | 1.49058 | 3.8169e+06 | 1.53702e+06 | 1.1439e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 105.942 | 2.2685 | 2.30846e+07 | 61215 | 2.75524e+07 | 3109.82 | 5.5853 | 787881 | 61215 | 938625 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 104.087 | 1.93094 | 2.34966e+07 | 61215 | 2.80435e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 110.418 | 3.35308 | 2.21503e+07 | 47919 | 2.06938e+07 | 2924.97 | 6.05987 | 839428 | 47919 | 781189 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 94.4306 | 2.04731 | 2.58999e+07 | 47919 | 2.41972e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1761.23 | 0.851537 | 1.38856e+06 | 1.98863e+06 | 5.38403e+07 | 1996.9 | 1.98518 | 1.22468e+06 | 1.98863e+06 | 4.74862e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1427.86 | 0.773039 | 1.7127e+06 | 1.98863e+06 | 6.64106e+07 | 1967.7 | 4.28026 | 1.24289e+06 | 1.98863e+06 | 4.8191e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 393.333 | 1.18526 | 6.21722e+06 | 1.98863e+06 | 2.41082e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1536.27 | 1.00184 | 1.59192e+06 | 1.53702e+06 | 4.77068e+07 | 1796.33 | 1.42883 | 1.36148e+06 | 1.53702e+06 | 4.08002e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1383.41 | 0.818439 | 1.76781e+06 | 1.53702e+06 | 5.29784e+07 | 1733.27 | 3.03637 | 1.41094e+06 | 1.53702e+06 | 4.22846e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 310.319 | 1.31481 | 7.8804e+06 | 1.53702e+06 | 2.36178e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1938.26 | 2.74656 | 1.26265e+06 | 138774 | 3.41402e+06 | 2508.78 | 2.76163 | 975641 | 138774 | 2.63764e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1597.3 | 2.82981 | 1.53185e+06 | 138774 | 4.14278e+06 | 1969.46 | 2.31505 | 1.24257e+06 | 138774 | 3.35993e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 651.726 | 1.34097 | 3.75333e+06 | 138482 | 1.01321e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1423.79 | 3.89011 | 1.71985e+06 | 69037 | 2.31209e+06 | 1883.97 | 2.52652 | 1.29979e+06 | 69037 | 1.74735e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1194.64 | 3.47062 | 2.04958e+06 | 69037 | 2.75559e+06 | 1381.68 | 2.27578 | 1.77198e+06 | 69037 | 2.38257e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 329.499 | 1.53983 | 7.42437e+06 | 68745 | 9.94849e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2405.97 | 0.550656 | 1.01642e+06 | 6.6619e+06 | 1.32032e+08 | 1468.08 | 0.497427 | 1.66576e+06 | 6.6619e+06 | 2.16381e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2197.35 | 0.697568 | 1.11292e+06 | 6.6619e+06 | 1.44567e+08 | 1501.84 | 1.29786 | 1.62831e+06 | 6.6619e+06 | 2.11517e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 741.45 | 1.43081 | 3.29818e+06 | 6.6619e+06 | 4.28436e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 964.645 | 0.653397 | 2.53514e+06 | 2.09023e+06 | 1.03323e+08 | 557.687 | 0.695543 | 4.38497e+06 | 2.09023e+06 | 1.78721e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 897.468 | 0.531197 | 2.72488e+06 | 2.09023e+06 | 1.11057e+08 | 575.827 | 0.605849 | 4.24685e+06 | 2.09023e+06 | 1.73091e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 236.421 | 0.987309 | 1.03436e+07 | 2.09023e+06 | 4.21579e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2707.47 | 1.10667 | 903341 | 1.43956e+06 | 2.53535e+07 | 2354.75 | 2.92492 | 1.03864e+06 | 1.43956e+06 | 2.91511e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2216.01 | 0.660618 | 1.10366e+06 | 1.43958e+06 | 3.09767e+07 | 2315.2 | 4.8626 | 1.05638e+06 | 1.43958e+06 | 2.96495e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 879.038 | 0.787853 | 2.78206e+06 | 1.42342e+06 | 7.72136e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1956.36 | 1.30437 | 1.25025e+06 | 500299 | 1.21941e+07 | 1976.99 | 2.49741 | 1.23715e+06 | 500299 | 1.20669e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1462.55 | 1.0339 | 1.67228e+06 | 500299 | 1.63113e+07 | 1554.92 | 2.8643 | 1.57291e+06 | 500299 | 1.53423e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 314.499 | 0.927221 | 7.77588e+06 | 492910 | 7.47339e+07 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 202.061 | 1.76145 | 1.21066e+07 | 44653 | 1.05375e+07 | 4235.38 | 4.73879 | 581356 | 44653 | 502723 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 196.325 | 1.92237 | 1.24601e+07 | 44653 | 1.08454e+07 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 178.262 | 1.82216 | 1.37233e+07 | 37543 | 1.00424e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 173.152 | 17.142 | 1.41295e+07 | 37543 | 1.03388e+07 | 5906.54 | 11.4113 | 418671 | 37543 | 303086 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2231.46 | 1.83467 | 1.0961e+06 | 719139 | 1.53671e+07 | 1787.93 | 1.89834 | 1.36791e+06 | 719139 | 1.91793e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1734.64 | 4.22936 | 1.40993e+06 | 719139 | 1.97685e+07 | 2648.81 | 3.26355 | 923411 | 719139 | 1.29459e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 751.587 | 1.70054 | 3.25389e+06 | 723784 | 4.59198e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 2075.31 | 2.56181 | 1.17861e+06 | 477706 | 1.09761e+07 | 2681.03 | 2.76625 | 912307 | 477706 | 8.49628e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1651.48 | 2.36523 | 1.48096e+06 | 477706 | 1.37929e+07 | 2293.77 | 5.08315 | 1.06629e+06 | 477706 | 9.93074e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 509.382 | 1.56392 | 4.80094e+06 | 479183 | 4.48568e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1221.64 | 2.15735 | 2.00198e+06 | 466906 | 1.82245e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1216.55 | 1.40137 | 2.01047e+06 | 466906 | 1.83007e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/e7f2463) | 770.049 | 2.36617 | 3.17591e+06 | 631514 | 3.91052e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 1851.57 | 1.93598 | 1.32066e+06 | 699405 | 1.80119e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1230.03 | 2.21206 | 1.98832e+06 | 699405 | 2.71134e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/2a19fd5) | 2310.84 | 1.03596 | 1.05853e+06 | 631514 | 1.30311e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/b0f0b08) | 1007.26 | 0.918211 | 2.4281e+06 | 631514 | 2.9896e+07 | 