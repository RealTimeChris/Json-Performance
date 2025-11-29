# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.26100 using the MSVC 19.44.35221.0 compiler).  

Latest Results: (Dec 07, 2025)
#### Using the following commits:
----
| Jsonifier: [142ebb1](https://github.com/RealTimeChris/Jsonifier/commit/142ebb1)  
| Glaze: [5954d42](https://github.com/stephenberry/glaze/commit/5954d42)  
| Simdjson: [ae32422](https://github.com/simdjson/simdjson/commit/ae32422)  

 > 1400 iterations on a (AMD EPYC 7763 64-Core Processor), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 355.498 | 6.91648 | 6.8398e+06 | 2195 | 5905 | 267.885 | 35.2135 | 9.20694e+06 | 2194 | 7905 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 129.562 | 2.79377 | 1.88317e+07 | 2193 | 16150 | 99.0692 | 55.1321 | 3.03693e+07 | 2195 | 26025 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 103.12 | 3.02627 | 2.36989e+07 | 2194 | 20305 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 252.833 | 7.56591 | 9.68595e+06 | 4286 | 16215 | 273.142 | 9.17928 | 8.9558e+06 | 4278 | 14995 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 239.775 | 3.20962 | 1.01871e+07 | 4348 | 17295 | 221.437 | 12.7831 | 1.10753e+07 | 4275 | 18515 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 173.501 | 2.92271 | 1.4071e+07 | 4280 | 23540 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 373.503 | 11.7168 | 6.56054e+06 | 1035 | 2680 | 264.198 | 5.06485 | 9.16041e+06 | 1057 | 3820 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 74.1084 | 5.69545 | 3.29254e+07 | 1043 | 13430 | 88.2785 | 29.2624 | 2.81155e+07 | 1046 | 11570 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 53.5932 | 6.0988 | 4.55926e+07 | 1054 | 18775 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 217.724 | 14.1804 | 1.12188e+07 | 1060 | 4690 | 256.978 | 3.61133 | 9.44836e+06 | 1032 | 3830 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 72.5141 | 5.74701 | 3.3668e+07 | 1034 | 13630 | 85.0836 | 23.7208 | 2.90405e+07 | 1034 | 11765 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 43.4505 | 6.449 | 5.61867e+07 | 1042 | 22900 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 234.769 | 4.85923 | 1.02334e+07 | 450 | 1835 | 262.639 | 4.09569 | 9.02032e+06 | 449 | 1635 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 61.763 | 4.13793 | 3.93628e+07 | 447 | 6925 | 38.5302 | 25.2374 | 6.47184e+07 | 448 | 11345 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 28.1342 | 3.55655 | 8.69278e+07 | 448 | 15225 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 724.205 | 6.68255 | 3.381e+06 | 47304 | 62395 | 757.723 | 1.54503 | 3.22294e+06 | 45285 | 56970 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 610.431 | 4.90087 | 4.00264e+06 | 47410 | 74045 | 507.694 | 7.04944 | 4.81162e+06 | 47240 | 88690 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 408.095 | 12.7537 | 6.0701e+06 | 48791 | 115540 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 542.898 | 6.68124 | 4.50773e+06 | 33606 | 59115 | 459.457 | 20.8586 | 5.48276e+06 | 31388 | 67160 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 539.248 | 5.20516 | 4.53719e+06 | 31335 | 55500 | 657.263 | 2.83679 | 3.71566e+06 | 32219 | 46745 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 296.873 | 14.4852 | 8.33197e+06 | 32402 | 105325 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 491.259 | 13.0303 | 4.83981e+06 | 1064 | 2050 | 836.537 | 22.9476 | 2.90452e+06 | 919 | 1115 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 288.871 | 17.0986 | 8.18138e+06 | 696 | 2255 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 286.077 | 14.8537 | 8.51293e+06 | 695 | 2330 | 769.663 | 24.8291 | 2.90388e+06 | 656 | 795 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 235.943 | 13.3863 | 1.02964e+07 | 762 | 3095 | 

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
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 756.64 | 5.75522 | 3.23112e+06 | 46588 | 58750 | 759.522 | 2.44095 | 3.21823e+06 | 48585 | 61030 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 656.738 | 4.78325 | 3.72632e+06 | 46959 | 68280 | 518.484 | 6.13832 | 4.70687e+06 | 47555 | 87345 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 410.358 | 21.5819 | 6.03816e+06 | 45550 | 107310 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 568.041 | 5.01427 | 4.29991e+06 | 34150 | 57315 | 847.526 | 2.67438 | 2.88335e+06 | 32413 | 36500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 510.044 | 5.5456 | 4.79324e+06 | 32584 | 60945 | 619.574 | 7.88797 | 3.95445e+06 | 31727 | 48975 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 203.068 | 9.57701 | 1.2105e+07 | 33023 | 155960 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 727.387 | 9.88825 | 3.36757e+06 | 92442 | 121470 | 666.847 | 4.82108 | 3.67284e+06 | 92442 | 132460 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 500.713 | 12.578 | 4.89017e+06 | 92442 | 176370 | 937.411 | 2.13758 | 2.60806e+06 | 92442 | 94060 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 475.689 | 7.2422 | 5.14475e+06 | 92442 | 185510 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 685.517 | 5.16535 | 3.56906e+06 | 55353 | 77075 | 627.994 | 2.70921 | 3.89209e+06 | 55353 | 84090 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 683.58 | 4.89663 | 3.5766e+06 | 55353 | 77290 | 823.384 | 3.15417 | 2.96866e+06 | 55353 | 64140 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 287.425 | 8.35272 | 8.52863e+06 | 55353 | 184165 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 584.765 | 1.66825 | 4.18178e+06 | 6661897 | 1.08655e+07 | 1047.32 | 1.1433 | 2.33482e+06 | 6661897 | 6.06663e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 524.069 | 1.2215 | 4.66617e+06 | 6661897 | 1.21237e+07 | 604.442 | 3.09863 | 4.04631e+06 | 6661897 | 1.05137e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 372.632 | 6.36955 | 6.5869e+06 | 6661897 | 1.71144e+07 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 215.794 | 1.38977 | 1.13318e+07 | 2090234 | 9.23795e+06 | 480.613 | 1.19064 | 5.08823e+06 | 2090234 | 4.14808e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 204.167 | 1.19148 | 1.19768e+07 | 2090234 | 9.76428e+06 | 365.498 | 1.09995 | 6.69043e+06 | 2090234 | 5.4543e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 145.47 | 1.26522 | 1.68104e+07 | 2090234 | 1.3704e+07 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 969.99 | 3.35478 | 2.5214e+06 | 1439584 | 1.41568e+06 | 580.007 | 1.61554 | 4.21588e+06 | 1439584 | 2.36736e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 946.316 | 4.32892 | 2.58632e+06 | 1439562 | 1.4522e+06 | 1397.34 | 2.28861 | 1.75034e+06 | 1439562 | 982825 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 571.825 | 5.92688 | 4.28164e+06 | 1423415 | 2.37712e+06 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 477.707 | 4.73326 | 5.12104e+06 | 500299 | 999265 | 726.262 | 3.16088 | 3.36742e+06 | 500299 | 657230 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 459.818 | 6.16448 | 5.32958e+06 | 500299 | 1.04004e+06 | 365.705 | 2.52791 | 6.68738e+06 | 500299 | 1.305e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 237.392 | 1.65533 | 1.03012e+07 | 492910 | 1.98033e+06 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1267.12 | 8.92365 | 1.93117e+06 | 44653 | 33650 | 2149.31 | 5.65212 | 1.13659e+06 | 44653 | 19840 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1041.39 | 9.93014 | 2.35142e+06 | 44653 | 40985 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1079.38 | 7.85881 | 2.26779e+06 | 37543 | 33240 | 2147.17 | 3.05322 | 1.13629e+06 | 37543 | 16685 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 873.571 | 5.56327 | 2.79917e+06 | 37543 | 41040 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 794.796 | 6.53192 | 3.08051e+06 | 414021 | 497590 | 879.005 | 3.95746 | 2.78343e+06 | 414021 | 449590 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 566.091 | 4.98745 | 4.32314e+06 | 414021 | 698200 | 397.329 | 2.17184 | 6.15477e+06 | 414021 | 993935 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 551.607 | 3.98204 | 4.43559e+06 | 418582 | 724290 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 610.922 | 8.07187 | 4.0111e+06 | 277014 | 433490 | 787.868 | 4.98401 | 3.10753e+06 | 277014 | 335900 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 516.778 | 7.18815 | 4.73834e+06 | 277014 | 512035 | 326.475 | 3.34542 | 7.4926e+06 | 277014 | 809635 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 394.772 | 3.242 | 6.19741e+06 | 278407 | 673015 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 662.971 | 2.81608 | 3.68854e+06 | 466906 | 671790 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 568.899 | 2.72201 | 4.29781e+06 | 466906 | 782950 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 301.9 | 2.07081 | 8.1004e+06 | 466906 | 1.47516e+06 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 838.835 | 2.20693 | 2.9153e+06 | 699405 | 795310 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 733.33 | 1.70152 | 3.3345e+06 | 699405 | 909690 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Windows-MSVC/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1967.3 | 3.34653 | 1.24326e+06 | 646997 | 313750 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1607.92 | 2.50486 | 1.52098e+06 | 646997 | 383835 | 