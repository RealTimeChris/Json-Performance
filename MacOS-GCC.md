# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 24.6.0 using the GNU 15.2.0 compiler).  

Latest Results: (Dec 17, 2025)
#### Using the following commits:
----
| Jsonifier: [8ec3abc](https://github.com/RealTimeChris/Jsonifier/commit/8ec3abc)  
| Glaze: [930e7bd](https://github.com/stephenberry/glaze/commit/930e7bd)  
| Simdjson: [7987418](https://github.com/simdjson/simdjson/commit/7987418)  

 > 1400 iterations on a (Apple M1 (Virtual)), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 254.754 | 16.707 | 905 | 3450 | 171.871 | 6.89158 | 890 | 4950 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 119.913 | 10.3291 | 915 | 7300 | 213.408 | 5.48542 | 895 | 4000 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 90.0428 | 6.26655 | 905 | 9600 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 489.516 | 37.0282 | 4265 | 8550 | 813.37 | 4.93387 | 4264 | 5000 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 322.061 | 35.8909 | 4311 | 13450 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 300.566 | 18.6984 | 4306 | 13850 | 1022.61 | 5.76148 | 4217 | 3950 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 925.493 | 0.303983 | 1940 | 2000 | 740.123 | 17.0183 | 1940 | 2600 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 284.123 | 7.40719 | 1939 | 6550 | 709.144 | 13.7071 | 1939 | 2700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 266.295 | 1.41289 | 1938 | 6950 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 923.371 | 0.281443 | 1936 | 2000 | 693.711 | 11.604 | 1939 | 2750 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 285.993 | 8.01258 | 1937 | 6500 | 677.633 | 9.50672 | 1937 | 2800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 244.332 | 5.78682 | 1938 | 7600 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 112.355 | 5.99469 | 449 | 3850 | 167.108 | 15.9176 | 447 | 2650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 110.455 | 5.45742 | 448 | 3900 | 286.102 | 16.6667 | 500 | 1800 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 75.9919 | 7.1324 | 450 | 5700 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1167.84 | 7.5537 | 49539 | 40500 | 2036.32 | 2.50195 | 48183 | 22550 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 936.318 | 3.48516 | 48693 | 49600 | 1996.88 | 2.52166 | 48875 | 23350 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 916.129 | 10.7915 | 46557 | 48650 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1001.95 | 5.42887 | 34804 | 33150 | 1853.99 | 3.07893 | 35453 | 18250 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 937.592 | 7.05202 | 34975 | 35650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 692.889 | 4.636 | 33109 | 45600 | 1981.49 | 4.03628 | 33637 | 16200 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1062.8 | 25.1634 | 951 | 750 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 641.946 | 22.8975 | 1069 | 1550 | 1135.59 | 15.3475 | 869 | 400 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 764.187 | 23.6248 | 619 | 650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 485.522 | 30.2701 | 533 | 950 | 842.367 | 13.8444 | 643 | 350 | 

### Abc (Out of Order) Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc (Out of Order) Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z", where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations throughhashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1378.23 | 8.46821 | 46616 | 32300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1023.39 | 4.40204 | 48093 | 44850 | 2114.56 | 1.99228 | 48027 | 21650 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 982.39 | 10.2791 | 51096 | 50050 | 2144.27 | 2.96549 | 49210 | 21900 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1152.77 | 10.9641 | 35398 | 29300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1052.88 | 4.16063 | 34682 | 31400 | 1923.06 | 3.21589 | 35684 | 17700 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 814.371 | 3.93005 | 34536 | 40500 | 2040.36 | 3.89828 | 33914 | 15850 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1416.39 | 0.70922 | 94378 | 63550 | 1176.78 | 8.94639 | 94378 | 76900 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1285.27 | 2.23535 | 105406 | 78250 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1235.12 | 5.36062 | 94378 | 72950 | 2132.37 | 6.20172 | 94378 | 42400 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1208.36 | 1.1236 | 56377 | 44500 | 3058.34 | 2.33393 | 56377 | 17600 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 918.785 | 4.06917 | 56377 | 58600 | 2406.69 | 2.86976 | 56377 | 22350 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 827.736 | 5.32571 | 61629 | 71100 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1197.07 | 1.49644 | 6661897 | 5.30775e+06 | 785.891 | 25.9759 | 6661897 | 8.38905e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1189.18 | 2.09715 | 6661897 | 5.3438e+06 | 533.907 | 17.6897 | 6661897 | 1.20746e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1035.46 | 1.67156 | 6661897 | 6.13645e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 524.223 | 1.43629 | 2090234 | 3.80275e+06 | 781.883 | 1.48801 | 2090234 | 2.54995e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 506.16 | 1.76397 | 2090234 | 3.93875e+06 | 699.243 | 3.72166 | 2090234 | 2.85225e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 342.585 | 1.34438 | 2090234 | 5.8194e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1765.54 | 1.94118 | 1439584 | 777700 | 2610.16 | 3.13416 | 1439584 | 526200 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1044.75 | 0.824738 | 1439562 | 1.3141e+06 | 1011.85 | 0 | 1061 | 450 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 240.314 | 15.7895 | 1061 | 4250 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1084.12 | 2.19968 | 500299 | 440150 | 2832.45 | 2.63082 | 500299 | 168500 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 645.909 | 0.847779 | 500299 | 738700 | 802.04 | 0 | 841 | 400 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 188.479 | 14.8936 | 841 | 4300 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 3645.48 | 2.65487 | 44653 | 11700 | 505.447 | 0 | 530 | 200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1623.64 | 6.32956 | 44653 | 26250 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 4077.65 | 2.43902 | 37543 | 8800 | 428.2 | 0 | 449 | 200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1533.99 | 2.74841 | 37543 | 23350 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1445.56 | 2.37992 | 719139 | 474500 | 1784.82 | 3.69547 | 719139 | 384500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1442.86 | 3.35493 | 723784 | 478650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1422.35 | 2.78678 | 719139 | 482350 | 3146.87 | 3.13838 | 719139 | 218000 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1267.63 | 1.80561 | 477706 | 359450 | 3116.08 | 3.17775 | 477706 | 146300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 1143.68 | 2.06541 | 479183 | 399650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1126.12 | 2.98501 | 477706 | 404700 | 3470.75 | 2.04374 | 477706 | 131300 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1392.23 | 1.28686 | 466906 | 319850 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1095.43 | 1.09845 | 466906 | 406500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/7987418) | 749.718 | 1.01245 | 466906 | 593950 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 1781.16 | 1.45336 | 699405 | 374500 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1508.1 | 1.49623 | 699405 | 442350 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GCC/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/930e7bd) | 2346.73 | 1.29315 | 631515 | 256650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/8ec3abc) | 1159.31 | 0.66993 | 631515 | 519500 | 