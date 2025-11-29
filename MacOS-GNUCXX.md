# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 24.6.0 using the GNU 15.2.0 compiler).  

Latest Results: (Dec 07, 2025)
#### Using the following commits:
----
| Jsonifier: [142ebb1](https://github.com/RealTimeChris/Jsonifier/commit/142ebb1)  
| Glaze: [5954d42](https://github.com/stephenberry/glaze/commit/5954d42)  
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
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 610.328 | 15.192 | 2193 | 3500 | 423.51 | 2.00019 | 2192 | 4950 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 272.958 | 4.74883 | 2195 | 7700 | 531.864 | 3.21858 | 2194 | 3950 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 215.805 | 4.1486 | 2189 | 9700 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 643.482 | 44.4904 | 4309 | 6950 | 845.006 | 7.70299 | 4272 | 4850 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 366.671 | 9.79218 | 4273 | 11150 | 1070.42 | 7.40961 | 4280 | 3850 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 360.833 | 31.6089 | 4281 | 11800 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 650.167 | 26.1459 | 1051 | 1700 | 362.881 | 15.2012 | 1040 | 2800 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 208.948 | 8.62516 | 1057 | 4850 | 380.834 | 18.8648 | 1043 | 2700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 123.778 | 8.14248 | 1055 | 8150 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 500.607 | 4.84355 | 1049 | 2000 | 382.805 | 18.0369 | 1048 | 2700 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 153.946 | 9.90885 | 1053 | 6550 | 358.16 | 14.5273 | 1046 | 2850 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 136.757 | 7.60112 | 1059 | 7400 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 428.772 | 0.578292 | 450 | 750 | 288.82 | 27.3568 | 449 | 1650 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 111.985 | 6.53609 | 447 | 3850 | 163.73 | 14.3772 | 448 | 2700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 87.9025 | 5.61176 | 449 | 4900 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1191.32 | 3.60967 | 45889 | 36750 | 1930.48 | 2.65303 | 47884 | 23650 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 923.721 | 3.75145 | 45620 | 47150 | 1821.22 | 2.34485 | 46106 | 24150 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 780.646 | 6.76005 | 47065 | 57700 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 872.093 | 5.56392 | 31998 | 35000 | 1625.37 | 2.64823 | 32809 | 19250 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 760.079 | 4.24704 | 32665 | 41050 | 1681.17 | 2.78365 | 32709 | 18550 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 631.652 | 5.08926 | 31696 | 47900 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 660.96 | 25.2597 | 912 | 1250 | 1474.38 | 8.92626 | 977 | 200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 630.379 | 36.3086 | 853 | 1250 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 478.781 | 18.333 | 565 | 950 | 820.16 | 8.25581 | 605 | 200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 406.223 | 31.683 | 576 | 1300 | 

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
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1225.57 | 2.53307 | 46211 | 35950 | 1970.95 | 2.17374 | 46886 | 22700 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 956.667 | 2.62475 | 45591 | 45450 | 1830.3 | 2.04516 | 44687 | 23300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 798.842 | 10.6131 | 47435 | 57050 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 907.349 | 8.02583 | 31137 | 32800 | 1750.66 | 2.93978 | 32729 | 17850 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 714.379 | 8.03368 | 31652 | 42450 | 1708 | 2.78353 | 33055 | 18450 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 699.767 | 6.41708 | 33066 | 45050 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1447.8 | 1.78715 | 92442 | 60900 | 1952.36 | 5.92608 | 92442 | 45200 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1443.89 | 7.4896 | 92442 | 61250 | 2202.19 | 4.68412 | 92442 | 40100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1295.03 | 2.74987 | 92442 | 68100 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1281.63 | 1.93147 | 55353 | 41200 | 2667.22 | 1.04167 | 55353 | 19800 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1278.33 | 1.67866 | 55353 | 41300 | 3310.29 | 0.332226 | 55353 | 15950 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 855.169 | 2.01743 | 55353 | 61750 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1137.62 | 2.90841 | 6661897 | 5.58595e+06 | 785.322 | 31.4055 | 6661897 | 8.50155e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1134.45 | 3.10867 | 6661897 | 5.60195e+06 | 184.11 | 31.3913 | 6661897 | 3.69914e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 950.524 | 2.7644 | 6661897 | 6.68715e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 494.923 | 3.55111 | 2090234 | 4.029e+06 | 727.472 | 6.12609 | 2090234 | 2.74275e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 482.255 | 3.35513 | 2090234 | 4.13465e+06 | 692.601 | 22.5265 | 2090234 | 2.89755e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 315.398 | 1.76747 | 2090234 | 6.32085e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1847.7 | 2.23448 | 1439562 | 743200 | 2644.35 | 3.49972 | 1439562 | 519350 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1590.96 | 1.82787 | 1439584 | 863050 | 2289.03 | 4.49523 | 1439584 | 600300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1372.36 | 2.25783 | 1423415 | 989300 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1052.95 | 3.58971 | 500299 | 453400 | 2727.41 | 2.81325 | 500299 | 175000 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 940.198 | 3.52285 | 500299 | 507750 | 2226.3 | 3.02624 | 500299 | 214450 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 609.231 | 1.33142 | 492910 | 771650 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1645.14 | 4.12979 | 44653 | 25900 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 621.743 | 2.15428 | 44653 | 68500 | 3088.54 | 1.51515 | 44653 | 13800 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1558.16 | 4.25733 | 37543 | 23000 | 3051.46 | 2.22222 | 37543 | 11750 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1427.56 | 3.53698 | 37543 | 25100 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1436.83 | 4.58301 | 414021 | 274900 | 2987.39 | 2.09682 | 414021 | 132200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1430.79 | 3.46007 | 418582 | 279150 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1430.39 | 2.80385 | 414021 | 276150 | 2696.55 | 2.38375 | 414021 | 146450 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1340.19 | 5.22993 | 277014 | 197350 | 2996.09 | 4.15713 | 277014 | 88250 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1248.08 | 2.45585 | 277014 | 211700 | 2704.52 | 2.31855 | 277014 | 97700 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1012.54 | 3.94853 | 278407 | 262400 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1364.14 | 1.682 | 466906 | 326450 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1042.85 | 1.39068 | 466906 | 427000 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 741.529 | 1.07353 | 466906 | 600500 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1793.85 | 1.6328 | 699405 | 371850 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1513.93 | 1.4368 | 699405 | 440600 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/MacOS-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 2239.81 | 1.86544 | 631515 | 268900 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 2166.97 | 2.13846 | 631515 | 277950 | 