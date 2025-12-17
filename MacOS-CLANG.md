# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 24.6.0 using the AppleClang 17.0.0.17000013 compiler).  

Latest Results: (Dec 17, 2025)
#### Using the following commits:
----
| Jsonifier: [8ec3abc](https://github.com/RealTimeChris/Jsonifier/commit/8ec3abc)  
| Glaze: [930e7bd](https://github.com/stephenberry/glaze/commit/930e7bd)  
| Simdjson: [7987418](https://github.com/simdjson/simdjson/commit/7987418)  

 > 1400 iterations on a (Apple M1 (Virtual)), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 257.309 | 5.03728 | 908 | 3366.7 | 180.635 | 5.12904 | 908 | 4793.6 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 117.414 | 5.73874 | 886 | 7204.15 | 92.961 | 11.3605 | 889 | 9137.5 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 89.7969 | 7.07057 | 886 | 9433.25 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 461.156 | 37.3014 | 4276 | 9539.5 | 632.592 | 8.21605 | 4218 | 6379.4 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 380.309 | 29.5122 | 4326 | 11341.7 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 349.534 | 22.5871 | 4273 | 11897.8 | 468.187 | 10.1202 | 4291 | 8768.95 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 981.99 | 2.17391 | 1938 | 1883.35 | 863.592 | 1.49356 | 1938 | 2141.6 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 343.73 | 4.92235 | 1938 | 5383.35 | 113.738 | 9.186 | 1938 | 16310.4 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 273.173 | 2.8974 | 1938 | 6770.75 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 880.066 | 3.14289 | 1938 | 2101.95 | 791.337 | 2.21852 | 1937 | 2335.4 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 279.678 | 6.84528 | 1938 | 6622.85 | 262.402 | 9.88632 | 1937 | 7062.5 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 276.633 | 2.71949 | 1937 | 6681.15 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 126.858 | 6.00311 | 451 | 3404.25 | 143.073 | 1.24937 | 500 | 3333.15 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 98.4431 | 4.23339 | 451 | 4375.1 | 17.4674 | 19.5455 | 448 | 25050.1 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 68.4447 | 5.64747 | 451 | 6293.75 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1293.17 | 7.43231 | 48423 | 35712.3 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1151.04 | 2.55544 | 48780 | 40393.6 | 1777.43 | 4.71087 | 49391 | 26510.4 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 996.592 | 3.7091 | 47256 | 45189.7 | 1409.4 | 4.16187 | 51764 | 35000 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1029.23 | 3.49431 | 36336 | 33702.1 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 810.064 | 6.91127 | 36391 | 42862.4 | 1626.73 | 4.96326 | 35590 | 20896 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 755.199 | 3.18786 | 34079 | 43085.5 | 1184.5 | 14.0943 | 33704 | 27689.5 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1234.73 | 26.0583 | 973 | 727.1 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 715.516 | 10.9119 | 1076 | 1412.55 | 1699.98 | 12.8566 | 1113 | 621 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1096.11 | 17.6346 | 777 | 662.5 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 486.707 | 11.7581 | 571 | 1100 | 1641.06 | 20.99 | 709 | 402.1 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1266.32 | 4.38945 | 51779 | 38998 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1094.16 | 5.04091 | 48415 | 42208.4 | 1678.15 | 3.38232 | 49191 | 27981.4 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 643.091 | 9.91436 | 51682 | 76933.4 | 1479.26 | 3.43047 | 49928 | 32147.9 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1040.73 | 5.99386 | 34285 | 31420.9 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 850.684 | 3.46216 | 36336 | 40708.2 | 1917.27 | 5.74004 | 34653 | 17245.8 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 765.017 | 4.61251 | 35760 | 44635.5 | 1174.43 | 13.3638 | 35395 | 29221 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1640.02 | 4.69264 | 94378 | 54904.2 | 2491.57 | 0.91568 | 94378 | 36125 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1386.38 | 3.16187 | 105406 | 72518.6 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1308.27 | 4.05987 | 94378 | 68833.4 | 1966.89 | 4.41695 | 94378 | 45775 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1138 | 2.16697 | 56377 | 47252.2 | 2238.87 | 6.58756 | 56377 | 24050 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1070.01 | 4.36711 | 56377 | 50285.4 | 2016.58 | 4.20874 | 56377 | 26693.7 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 890.048 | 2.65256 | 61629 | 66043.9 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1262.01 | 1.59488 | 6661897 | 5.03483e+06 | 711.069 | 29.0612 | 6661897 | 9.1246e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1184.6 | 0.917607 | 6661897 | 5.36336e+06 | 1300.45 | 3.33013 | 6661897 | 4.88744e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1045.68 | 8.44297 | 6661897 | 6.10315e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 459.129 | 2.44554 | 2090234 | 4.3426e+06 | 502.375 | 13.3508 | 2090234 | 3.97617e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 433.927 | 9.65919 | 2090234 | 4.60704e+06 | 604.776 | 3.55822 | 2090234 | 3.29748e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 373.129 | 3.30278 | 2090234 | 5.34415e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1345.25 | 3.20453 | 1439584 | 1.02107e+06 | 1218.78 | 10.5015 | 1439584 | 1.13035e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1186.32 | 1.14937 | 1439562 | 1.15729e+06 | 2219.14 | 15.8739 | 1061 | 460.35 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 150.619 | 21.7298 | 1061 | 6833.3 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 759.609 | 2.60517 | 500299 | 628408 | 1397.19 | 2.8023 | 500299 | 341569 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 541.389 | 0.409449 | 500299 | 881300 | 2406 | 0.194815 | 841 | 333.35 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 115.745 | 18.869 | 841 | 7047.95 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 3704.36 | 0.400789 | 44653 | 11495.8 | 2486.79 | 2.74972 | 530 | 204.15 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1294.62 | 11.6957 | 44653 | 33237.6 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 4011.71 | 0.370276 | 37543 | 8924.9 | 2567.93 | 0.150376 | 449 | 166.75 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1751.85 | 2.29122 | 37543 | 20441.6 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1506.55 | 2.73301 | 723784 | 458350 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1484.6 | 2.93308 | 719139 | 462131 | 1077.81 | 3.72291 | 719139 | 636515 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1300.33 | 3.79119 | 719139 | 527748 | 3056.55 | 3.16317 | 719139 | 224517 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1299 | 2.43264 | 477706 | 350788 | 1859.55 | 2.60396 | 477706 | 245029 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1241.68 | 2.82916 | 477706 | 367067 | 3151.2 | 3.91257 | 477706 | 144675 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1084.07 | 4.68154 | 479183 | 421958 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1268.36 | 1.2942 | 466906 | 351081 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1170.51 | 1.58527 | 466906 | 380436 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 661.542 | 1.66115 | 466906 | 673158 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1652.42 | 1.33722 | 699405 | 403679 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1648.24 | 1.04679 | 699405 | 404687 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 2149.79 | 1.37073 | 631515 | 280162 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1122.08 | 0.795999 | 631515 | 536742 | 