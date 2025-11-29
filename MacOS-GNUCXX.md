# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 24.6.0 using the GNU 15.2.0 compiler).  

Latest Results: (Dec 04, 2025)
#### Using the following commits:
----
| Jsonifier: [37f6e29](https://github.com/RealTimeChris/Jsonifier/commit/37f6e29)  
| Glaze: [7e8ca82](https://github.com/stephenberry/glaze/commit/7e8ca82)  
| Simdjson: [ae32422](https://github.com/simdjson/simdjson/commit/ae32422)  

 > 1400 iterations on a (Apple M1 (Virtual)), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 628.503 | 16.7341 | 2197 | 3400 | 434.606 | 4.15115 | 2196 | 4850 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 221.725 | 5.9767 | 2191 | 9450 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 103.416 | 8.20161 | 2194 | 20300 | 548.697 | 5.92683 | 2192 | 3850 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 668.257 | 36.7649 | 4258 | 6350 | 854.964 | 7.99726 | 4269 | 4800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 381.029 | 16.7308 | 4316 | 10900 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 354.838 | 15.2245 | 4307 | 11700 | 1028.98 | 5.30255 | 4315 | 4000 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 234.932 | 15.5653 | 1064 | 4400 | 205.15 | 9.35081 | 1026 | 4800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 146.513 | 7.66298 | 1041 | 6800 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 70.0188 | 6.87149 | 1059 | 14450 | 391.769 | 19.2632 | 1055 | 2650 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 510.406 | 5.54933 | 1070 | 2000 | 363.247 | 14.4989 | 1038 | 2800 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 181.888 | 9.81701 | 1060 | 5600 | 373.348 | 16.3012 | 1044 | 2750 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 43.8935 | 4.77902 | 1060 | 23050 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 430.679 | 0.797166 | 450 | 750 | 310.731 | 31.5584 | 449 | 1550 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 110.674 | 5.21327 | 449 | 3900 | 89.9887 | 6.74014 | 449 | 4800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 87.1348 | 2.59118 | 451 | 4950 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1093.48 | 5.48088 | 45851 | 40050 | 1923.8 | 3.40684 | 46793 | 23200 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 891.891 | 4.53217 | 48404 | 51750 | 1838.04 | 1.93192 | 46815 | 24300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 704.344 | 7.93729 | 46907 | 63700 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 979.499 | 4.73243 | 33403 | 32600 | 1587.52 | 3.50724 | 33165 | 19950 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 840.049 | 2.16119 | 33203 | 37700 | 1660.75 | 3.01052 | 31872 | 18300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 631.428 | 4.05161 | 31302 | 47300 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 607.512 | 22.7656 | 1029 | 1500 | 1284.6 | 6.68151 | 871 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 297.148 | 31.9201 | 942 | 3100 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 549.571 | 25.2082 | 593 | 1000 | 679.334 | 8.18905 | 570 | 150 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 388.363 | 25.1034 | 739 | 1800 | 

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
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1185.3 | 3.61702 | 48960 | 39400 | 1928.4 | 2.61836 | 47319 | 23400 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 910.556 | 4.917 | 46942 | 49200 | 1823.78 | 2.33361 | 46867 | 24500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 762.781 | 10.1697 | 46874 | 58950 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 999.117 | 5.08093 | 32721 | 31250 | 1697.82 | 2.16165 | 30871 | 17350 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 659.973 | 4.77318 | 32451 | 46950 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 417.123 | 3.50528 | 32786 | 75050 | 1707.48 | 2.40649 | 33663 | 18800 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1530.66 | 0.696864 | 92442 | 57600 | 2470.25 | 3.54436 | 92442 | 35700 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1281.76 | 1.74299 | 92442 | 68800 | 2031.25 | 9.57994 | 92442 | 43500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1251.82 | 3.5272 | 92442 | 70450 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1276.16 | 8.07678 | 55353 | 41450 | 2463.9 | 6.84827 | 55353 | 21450 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1106.51 | 2.63788 | 55353 | 47750 | 2902.74 | 4.28527 | 55353 | 18200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 826.931 | 1.78932 | 55353 | 63850 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1258.73 | 2.57956 | 6661897 | 5.0488e+06 | 1410.05 | 3.92969 | 6661897 | 4.50835e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1216.2 | 2.42999 | 6661897 | 5.22505e+06 | 537.272 | 25.3844 | 6661897 | 1.21593e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1021.87 | 1.95036 | 6661897 | 6.21805e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 545.431 | 1.0898 | 2090234 | 3.65495e+06 | 791.83 | 2.53727 | 2090234 | 2.5182e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 496.574 | 2.518 | 2090234 | 4.0153e+06 | 712.08 | 1.49866 | 2090234 | 2.79985e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 308.195 | 1.23693 | 2090234 | 6.4685e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1913 | 1.28556 | 1439562 | 717700 | 2519.58 | 3.21807 | 1439562 | 545150 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1625.86 | 1.46873 | 1439584 | 844500 | 2199.6 | 2.4754 | 1439584 | 624400 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1505.17 | 1.64966 | 1423415 | 901950 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1087.62 | 2.29724 | 500299 | 438800 | 2870 | 3.34626 | 500299 | 166350 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 994.968 | 2.92805 | 500299 | 479700 | 2125.49 | 4.88267 | 500299 | 224650 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 598.789 | 1.50013 | 492910 | 785150 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1681.27 | 2.58159 | 44653 | 25350 | 3111.94 | 2.25564 | 44653 | 13700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1622.94 | 2.81827 | 44653 | 26250 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1565.57 | 4.71066 | 37543 | 22900 | 2024.2 | 1.7341 | 37543 | 17700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1466.3 | 2.32917 | 37543 | 24450 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1532.24 | 2.39085 | 414021 | 257750 | 2926.15 | 1.50688 | 414021 | 134950 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1459.33 | 2.67524 | 414021 | 270650 | 2715.84 | 3.07701 | 414021 | 145450 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1410.44 | 2.74042 | 418582 | 283100 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1530.37 | 2.47132 | 277014 | 172700 | 3266.08 | 1.35802 | 277014 | 80900 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1128.99 | 3.30645 | 277014 | 234100 | 2745.93 | 4.74432 | 277014 | 96300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1008.07 | 2.45037 | 278407 | 263450 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1316.39 | 1.95462 | 466906 | 338300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1064.77 | 0.902879 | 466906 | 418200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 736.075 | 0.830621 | 466906 | 604950 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 1837.1 | 1.33862 | 699405 | 363100 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 1534.8 | 1.23042 | 699405 | 434600 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/37f6e29) | 2332.13 | 1.43333 | 631515 | 258250 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7e8ca82) | 2145.31 | 1.15039 | 631515 | 280750 | 