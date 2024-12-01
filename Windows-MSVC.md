# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.42.34433.0 compiler).  

Latest Results: (Dec 02, 2024)
#### Using the following commits:
----
| Jsonifier: [c68f3d5](https://github.com/RealTimeChris/Jsonifier/commit/c68f3d5)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [3f87f95](https://github.com/simdjson/simdjson/commit/3f87f95)  

 > 100 iterations on a (AMD EPYC 7763 64-Core Processor).



### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1577.21 | 4.99135 | 1.55034e+06 | 2118091 | 6.5317e+07 | 1893.15 | 0.982954 | 1.29164e+06 | 2118091 | 5.33494e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1161.89 | 3.33146 | 2.10463e+06 | 2118091 | 8.69259e+07 | 1646.31 | 4.37388 | 1.48528e+06 | 2118091 | 6.13483e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 354.366 | 2.75298 | 6.90067e+06 | 2118091 | 2.85011e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1340.4 | 4.92736 | 1.8243e+06 | 1630178 | 6.9591e+07 | 1644.49 | 1.02309 | 1.48696e+06 | 1630178 | 4.72686e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1000.04 | 4.63736 | 2.44511e+06 | 1630178 | 7.77296e+07 | 1426.11 | 4.59006 | 1.71422e+06 | 1630178 | 5.45069e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 276.128 | 3.20436 | 8.85586e+06 | 1630178 | 2.81511e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 4808.63 | 2.4453 | 508478 | 89979 | 2.10036e+07 | 2547.22 | 2.9328 | 958944 | 89979 | 1.6844e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3408.16 | 0.773766 | 717459 | 89979 | 2.96343e+07 | 2105.63 | 7.24609 | 1.16016e+06 | 89979 | 4.0753e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 2029.16 | 1.01158 | 1.20506e+06 | 89979 | 4.97735e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 5131.23 | 2.00673 | 476480 | 68060 | 1.5149e+07 | 2226.66 | 3.94511 | 1.09649e+06 | 68060 | 1.4575e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3583.19 | 1.16992 | 682393 | 68060 | 2.16938e+07 | 1927.31 | 4.98131 | 1.26697e+06 | 68060 | 1.9533e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 1673.52 | 3.40978 | 1.4611e+06 | 68060 | 4.64488e+07 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

  This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

  In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1555.99 | 4.95195 | 1.57153e+06 | 2118091 | 7.14002e+07 | 1884.89 | 0.854934 | 1.2973e+06 | 2118091 | 5.35831e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1159.32 | 3.41935 | 2.10927e+06 | 2118091 | 8.71189e+07 | 1632.68 | 4.76137 | 1.49769e+06 | 2118091 | 6.18604e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 101.64 | 3.76323 | 2.40593e+07 | 2118091 | 9.9369e+08 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1307.32 | 4.9948 | 1.87045e+06 | 1630178 | 6.18383e+07 | 1635.96 | 1.21056 | 1.49472e+06 | 1630178 | 4.75152e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 997.996 | 4.74907 | 2.45021e+06 | 1630178 | 7.7889e+07 | 1419.72 | 4.21407 | 1.72232e+06 | 1630178 | 5.47523e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 80.8753 | 1.04886 | 3.02364e+07 | 1630178 | 9.61146e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1250.58 | 15.3843 | 1.95398e+06 | 138774 | 9.3836e+06 | 2096.82 | 8.10717 | 1.16546e+06 | 138774 | 6.3117e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 990.685 | 10.6819 | 2.46731e+06 | 138774 | 1.18453e+07 | 1787.65 | 5.04235 | 1.36662e+06 | 138774 | 7.4033e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 309.496 | 2.23228 | 7.89986e+06 | 138482 | 1.89582e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 931.637 | 18.7774 | 2.62336e+06 | 69037 | 7.067e+06 | 1737.68 | 4.98568 | 1.4058e+06 | 69037 | 3.1069e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 803.824 | 11.6071 | 3.04009e+06 | 69037 | 8.1907e+06 | 1221.72 | 4.99249 | 1.99966e+06 | 69037 | 3.3951e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 174.716 | 3.90994 | 1.39945e+07 | 68745 | 1.88417e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 486.399 | 4.07848 | 5.02747e+06 | 6661897 | 2.2068e+08 | 1211.72 | 1.44763 | 2.01808e+06 | 6661897 | 2.6216e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 356.512 | 2.79181 | 6.85916e+06 | 6661897 | 3.01081e+08 | 1055.25 | 3.41412 | 2.31725e+06 | 6661897 | 3.01033e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 151.084 | 4.99393 | 1.61854e+07 | 6661897 | 9.80435e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 475.413 | 3.97306 | 5.14362e+06 | 2090234 | 2.0965e+08 | 453.927 | 0.935087 | 5.38709e+06 | 2090234 | 2.19573e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 268.283 | 2.264 | 9.1148e+06 | 2090234 | 3.71511e+08 | 416.895 | 1.89989 | 5.86558e+06 | 2090234 | 2.39077e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 142.903 | 4.95584 | 1.7112e+07 | 2090234 | 1.102e+09 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2903.38 | 4.42053 | 842169 | 1439562 | 2.91956e+07 | 2452.55 | 3.26453 | 996969 | 1439562 | 2.79887e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1963.26 | 3.49985 | 1.24551e+06 | 1439584 | 4.31761e+07 | 2182.3 | 4.96022 | 1.12045e+06 | 1439584 | 3.77463e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 723.49 | 1.17162 | 3.37992e+06 | 1423437 | 1.17163e+08 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1788.46 | 7.1891 | 1.36701e+06 | 500299 | 2.66779e+07 | 1740.13 | 1.01682 | 1.40508e+06 | 500299 | 1.37094e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1171.56 | 4.94903 | 2.08701e+06 | 500299 | 2.36208e+07 | 1222.26 | 4.96001 | 2.00035e+06 | 500299 | 1.95181e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 219.618 | 2.03037 | 1.11345e+07 | 492910 | 1.08626e+08 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1567.02 | 4.96656 | 1.56013e+06 | 719107 | 3.85881e+07 | 2553.27 | 2.34331 | 957538 | 719107 | 1.34297e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 915.403 | 4.96182 | 2.67109e+06 | 719139 | 4.65091e+07 | 2224.62 | 4.99153 | 1.09893e+06 | 719139 | 2.89791e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 287.262 | 2.0319 | 8.51245e+06 | 723784 | 1.07397e+08 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1475.54 | 5.75635 | 1.65678e+06 | 477674 | 3.01771e+07 | 2620.13 | 2.74007 | 932961 | 477674 | 8.6932e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 849.042 | 4.98532 | 2.87968e+06 | 477706 | 2.77956e+07 | 2017.04 | 4.98709 | 1.2119e+06 | 477706 | 2.01019e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 212.379 | 1.5795 | 1.1514e+07 | 479183 | 1.04831e+08 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 948.082 | 2.78073 | 2.57903e+06 | 466906 | 2.3483e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 817.307 | 4.97587 | 2.99172e+06 | 466906 | 5.44809e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3f87f95) | 551.657 | 7.983 | 4.43251e+06 | 466906 | 1.11849e+08 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 1128.37 | 1.99993 | 2.16703e+06 | 699405 | 2.95561e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1099.21 | 2.52207 | 2.22441e+06 | 699405 | 3.03402e+07 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c68f3d5) | 2586.1 | 1.12829 | 945376 | 646995 | 1.19296e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1087.05 | 8.88174 | 2.2493e+06 | 646995 | 5.67614e+07 | 