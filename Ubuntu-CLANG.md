# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Dec 02, 2024)
#### Using the following commits:
----
| Jsonifier: [c68f3d5](https://github.com/RealTimeChris/Jsonifier/commit/c68f3d5)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [3f87f95](https://github.com/simdjson/simdjson/commit/3f87f95)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1644.88 | 12.5816 | 1.48647e+06 | 2094936 | 1.21461e+08 | 2231.75 | 0.94764 | 1.09566e+06 | 2094936 | 4.47605e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1411.47 | 2.60316 | 1.73243e+06 | 2094936 | 7.07733e+07 | 2016.54 | 4.98132 | 1.21258e+06 | 2094936 | 5.9445e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 701.575 | 2.55937 | 3.48549e+06 | 2094936 | 1.42386e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1472.04 | 6.83852 | 1.66105e+06 | 1614091 | 1.0457e+08 | 1988.14 | 1.1846 | 1.22991e+06 | 1614091 | 3.87124e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1289.79 | 5.26125 | 1.89581e+06 | 1614091 | 1.19347e+08 | 1698.06 | 6.50107 | 1.44e+06 | 1614091 | 9.06515e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 549.551 | 3.80268 | 4.44965e+06 | 1614091 | 1.40052e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5350.23 | 1.32786 | 456993 | 78240 | 1.8671e+07 | 3110.82 | 4.4769 | 784908 | 78240 | 1.19929e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4266.63 | 0.902642 | 573079 | 78240 | 2.34129e+07 | 2793.83 | 4.67768 | 874017 | 78240 | 1.33536e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 3129.84 | 4.10667 | 781230 | 78240 | 3.19167e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5679.33 | 1.82581 | 430492 | 57885 | 1.35519e+07 | 2813.38 | 3.65279 | 867628 | 57885 | 981087 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3905.77 | 1.45502 | 626012 | 57885 | 1.97057e+07 | 2415.95 | 3.66983 | 1.0105e+06 | 57885 | 1.14248e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 2787.08 | 2.15644 | 877314 | 57885 | 2.76153e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

  This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

  In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1830.37 | 2.17168 | 1.33594e+06 | 2094936 | 5.45761e+07 | 2217.32 | 1.00515 | 1.10279e+06 | 2094936 | 4.50517e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1420.93 | 1.63235 | 1.72091e+06 | 2094936 | 7.0302e+07 | 1994.88 | 5.35763 | 1.22577e+06 | 2094936 | 1.00151e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 376.294 | 3.19524 | 6.4985e+06 | 2094936 | 2.65468e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1498.34 | 2.60532 | 1.63198e+06 | 1614091 | 5.13673e+07 | 1967.13 | 1.22986 | 1.24306e+06 | 1614091 | 3.91259e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1338.34 | 1.7086 | 1.82709e+06 | 1614091 | 5.75083e+07 | 1697.63 | 5.97759 | 1.44041e+06 | 1614091 | 9.06747e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 300.116 | 0.951393 | 8.14814e+06 | 1614091 | 2.56454e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2085.26 | 5.79259 | 1.1717e+06 | 138774 | 5.41422e+06 | 2691.39 | 2.75246 | 907782 | 138774 | 2.45867e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1190.52 | 4.98161 | 2.05313e+06 | 138774 | 4.74166e+06 | 1924.05 | 4.97593 | 1.27005e+06 | 138774 | 5.91548e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 535.618 | 4.98658 | 4.56448e+06 | 138482 | 1.79168e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1794.33 | 7.57539 | 1.36133e+06 | 69037 | 3.66926e+06 | 1966.68 | 2.22875 | 1.24209e+06 | 69037 | 1.67386e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1240.43 | 4.99943 | 1.96962e+06 | 69037 | 3.39696e+06 | 1390.14 | 4.19421 | 1.75724e+06 | 69037 | 2.36807e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 327.562 | 2.55756 | 7.46395e+06 | 68745 | 1.00498e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 844.84 | 2.25707 | 2.89443e+06 | 6661897 | 1.27052e+08 | 1544.48 | 0.839465 | 1.58327e+06 | 6661897 | 2.05677e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 825.232 | 2.37293 | 2.96322e+06 | 6661897 | 1.30071e+08 | 1499.75 | 2.60351 | 1.63051e+06 | 6661897 | 2.11811e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 254.07 | 7.28212 | 9.62483e+06 | 6661897 | 8.44952e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 943.969 | 2.84608 | 2.59046e+06 | 2090234 | 1.05586e+08 | 598.149 | 0.574758 | 4.08817e+06 | 2090234 | 1.66631e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 883.008 | 2.81167 | 2.7693e+06 | 2090234 | 1.12876e+08 | 577.477 | 0.775058 | 4.23453e+06 | 2090234 | 1.72596e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 238.484 | 5.99461 | 1.02538e+07 | 2090234 | 8.35864e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 3173.82 | 2.37795 | 770407 | 1439562 | 2.59497e+07 | 3391.13 | 1.1614 | 721023 | 1439562 | 2.02421e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2038.59 | 2.23529 | 1.19946e+06 | 1439584 | 4.04002e+07 | 2325.54 | 5.68828 | 1.05144e+06 | 1439584 | 5.90356e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1010.11 | 1.38749 | 2.42083e+06 | 1423437 | 8.15348e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1945.22 | 4.69256 | 1.25682e+06 | 500299 | 1.22639e+07 | 2098.36 | 2.35785 | 1.16512e+06 | 500299 | 1.13689e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1258.12 | 13.0675 | 1.94316e+06 | 500299 | 3.79236e+07 | 1287.84 | 19.9482 | 1.89849e+06 | 500299 | 3.70481e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 315.778 | 2.17781 | 7.74367e+06 | 492910 | 7.5547e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2439.47 | 8.82134 | 1.00212e+06 | 719107 | 2.46881e+07 | 3415.94 | 1.90901 | 715688 | 719107 | 1.00381e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1288.29 | 3.58297 | 1.89792e+06 | 719139 | 2.33743e+07 | 2405.79 | 4.03017 | 1.01623e+06 | 719139 | 1.42536e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 633.588 | 2.4808 | 3.85931e+06 | 723784 | 4.75276e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2521.05 | 4.94757 | 969509 | 477674 | 1.0774e+07 | 3054.12 | 1.94684 | 800435 | 477674 | 7.45789e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1180.66 | 11.7239 | 2.07071e+06 | 477706 | 3.77142e+07 | 2432.89 | 3.13785 | 1.00484e+06 | 477706 | 9.36284e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 476.952 | 2.40438 | 5.1268e+06 | 479183 | 4.66794e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1279.34 | 3.21521 | 1.91111e+06 | 466906 | 1.74026e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1041.71 | 7.8599 | 2.34692e+06 | 466906 | 4.27447e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 749.753 | 4.73056 | 3.26138e+06 | 466906 | 4.01638e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1722 | 2.95035 | 1.41988e+06 | 699405 | 1.93672e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1587.6 | 2.29989 | 1.54005e+06 | 699405 | 2.10067e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 3973.57 | 2.17542 | 615180 | 631514 | 7.57831e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1479.5 | 2.42044 | 1.65264e+06 | 631514 | 2.03534e+07 | 