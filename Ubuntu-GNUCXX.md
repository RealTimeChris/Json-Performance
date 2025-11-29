# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.11.0-1018-azure using the GNU 14.2.0 compiler).  

Latest Results: (Dec 07, 2025)
#### Using the following commits:
----
| Jsonifier: [142ebb1](https://github.com/RealTimeChris/Jsonifier/commit/142ebb1)  
| Glaze: [5954d42](https://github.com/stephenberry/glaze/commit/5954d42)  
| Simdjson: [ae32422](https://github.com/simdjson/simdjson/commit/ae32422)  

 > 1400 iterations on a (AMD EPYC 7763 64-Core Processor), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 559.453 | 2.08727 | 4.33105e+06 | 2195 | 3743.05 | 484.633 | 2.2829 | 5.00638e+06 | 2196 | 4322.5 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 329.003 | 2.66959 | 7.35422e+06 | 2192 | 6359.45 | 289.822 | 1.65303 | 8.39107e+06 | 2197 | 7230.35 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 228.863 | 4.45616 | 1.06516e+07 | 2192 | 9146.05 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 655.703 | 3.54252 | 3.70662e+06 | 4321 | 6284.9 | 839.983 | 3.04128 | 2.88982e+06 | 4296 | 4880.15 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 301.609 | 2.412 | 8.08702e+06 | 4212 | 13321.9 | 584.979 | 3.27788 | 4.15368e+06 | 4245 | 6923 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 221.586 | 6.05634 | 1.10259e+07 | 4277 | 18426.5 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 543.218 | 4.5619 | 4.41441e+06 | 1065 | 1869.95 | 386.422 | 5.19599 | 6.23627e+06 | 1028 | 2539.65 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 243.514 | 6.5952 | 9.93493e+06 | 1043 | 4091.1 | 188.405 | 5.17523 | 1.29104e+07 | 1043 | 5288.75 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 144.507 | 3.8422 | 1.6851e+07 | 1036 | 6844.4 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 483.016 | 3.10563 | 4.97818e+06 | 1046 | 2065.95 | 402.902 | 4.60854 | 5.97547e+06 | 1040 | 2464.05 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 226.928 | 4.89304 | 1.05978e+07 | 1046 | 4400.8 | 190.161 | 4.47463 | 1.27716e+07 | 1067 | 5355.1 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 143.341 | 4.13592 | 1.69639e+07 | 1046 | 6958.9 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 391.764 | 4.27596 | 6.05541e+06 | 448 | 1093.15 | 427.576 | 1.51984 | 5.52891e+06 | 450 | 1005.85 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 310.42 | 10.6013 | 7.71567e+06 | 449 | 1386.05 | 94.5633 | 3.664 | 2.56532e+07 | 452 | 4562.95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 95.1132 | 1.89584 | 2.55187e+07 | 450 | 4513.4 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 927.991 | 1.67756 | 2.63164e+06 | 46535 | 47793.7 | 1280.49 | 2.52539 | 1.90655e+06 | 46191 | 34380.2 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 667.438 | 11.3703 | 3.66525e+06 | 46020 | 65838.9 | 1356.42 | 1.37648 | 1.80014e+06 | 46873 | 32945.6 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 528.186 | 8.32291 | 4.67529e+06 | 49029 | 89431.9 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 803.972 | 0.839882 | 3.03831e+06 | 33715 | 39983.6 | 1182.25 | 2.85433 | 2.06853e+06 | 32146 | 25969.4 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 765.793 | 1.23647 | 3.18999e+06 | 32457 | 40416.4 | 1198.61 | 1.84221 | 2.03746e+06 | 32623 | 25959.5 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 466.63 | 7.39399 | 5.24377e+06 | 34120 | 69811.8 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 714.773 | 13.3022 | 3.24427e+06 | 839 | 1095.55 | 1449.4 | 12.8622 | 1.56082e+06 | 962 | 627.1 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 519.61 | 16.1608 | 4.5638e+06 | 1049 | 1901.1 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 431.26 | 14.5993 | 5.29877e+06 | 455 | 977.4 | 1250.13 | 15.4839 | 1.72492e+06 | 662 | 497.5 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 360.975 | 12.8293 | 6.72005e+06 | 704 | 1885 | 

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
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 909 | 3.3213 | 2.6865e+06 | 46269 | 48514 | 1318.06 | 2.43735 | 1.85194e+06 | 46030 | 33283.6 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 702.533 | 13.0829 | 3.48511e+06 | 45490 | 61889.6 | 1428.08 | 1.81116 | 1.71052e+06 | 47893 | 31993.3 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 520.153 | 7.038 | 4.74534e+06 | 47425 | 87803.9 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 792.511 | 1.49771 | 3.08303e+06 | 31442 | 37837.6 | 1146.79 | 3.0415 | 2.12977e+06 | 31478 | 26183.9 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 769.061 | 1.09073 | 3.1765e+06 | 32687 | 40527.1 | 1219.18 | 1.26034 | 2.00273e+06 | 32403 | 25346.7 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 377.223 | 5.62903 | 6.47907e+06 | 31828 | 80460 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1126.97 | 7.94566 | 2.17214e+06 | 92442 | 78351.8 | 766.196 | 5.15569 | 3.1921e+06 | 92442 | 115128 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 899.287 | 6.5963 | 2.71846e+06 | 92442 | 98068.1 | 1890.17 | 1.13791 | 1.29258e+06 | 92442 | 46642.7 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 657.668 | 4.20362 | 3.71907e+06 | 92442 | 134127 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1118.98 | 0.928591 | 2.18391e+06 | 55353 | 47177.2 | 1579.58 | 1.04682 | 1.54643e+06 | 55353 | 33423.4 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1016.47 | 12.9828 | 2.40757e+06 | 55353 | 52008.2 | 1872.39 | 1.12139 | 1.30435e+06 | 55353 | 28195.7 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 489.635 | 6.05738 | 4.99623e+06 | 55353 | 107896 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1000.78 | 0.230337 | 2.44349e+06 | 6661897 | 6.34835e+06 | 740.691 | 2.19105 | 3.30184e+06 | 6661897 | 8.57846e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 799.123 | 0.300708 | 3.06008e+06 | 6661897 | 7.95034e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 769.713 | 5.67323 | 3.18192e+06 | 6661897 | 8.26703e+06 | 1247.32 | 3.40533 | 1.96579e+06 | 6661897 | 5.10733e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 443.859 | 0.213852 | 5.50938e+06 | 2090234 | 4.49108e+06 | 519.648 | 0.86365 | 4.70582e+06 | 2090234 | 3.8361e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 399.75 | 0.211862 | 6.11731e+06 | 2090234 | 4.98663e+06 | 498.598 | 0.463272 | 4.90435e+06 | 2090234 | 3.99804e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 267.137 | 0.283329 | 9.15411e+06 | 2090234 | 7.46211e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1558.93 | 0.563264 | 1.56859e+06 | 1439584 | 880685 | 1775.67 | 0.980783 | 1.37714e+06 | 1439584 | 773227 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1366.14 | 0.327775 | 1.78981e+06 | 1439562 | 1.00493e+06 | 2536.11 | 1.10033 | 964092 | 1439562 | 541364 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1037.67 | 0.638271 | 2.35656e+06 | 1423415 | 1.30821e+06 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1089.72 | 1.51419 | 2.24406e+06 | 500299 | 437895 | 1594.88 | 2.12717 | 1.53329e+06 | 500299 | 299223 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1069.24 | 1.40702 | 2.28701e+06 | 500299 | 446268 | 1835.22 | 2.45226 | 1.33248e+06 | 500299 | 260032 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 387.321 | 0.417219 | 6.31347e+06 | 492910 | 1.21367e+06 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1732.44 | 2.0577 | 1.40961e+06 | 44653 | 24584.8 | 3256.69 | 2.08929 | 748648 | 44653 | 13078.9 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1616.52 | 2.43253 | 1.51084e+06 | 44653 | 26345.6 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1631.04 | 1.5672 | 1.49691e+06 | 37543 | 21954.9 | 3866.38 | 2.91162 | 629886 | 37543 | 9263.8 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1399.48 | 2.23672 | 1.745e+06 | 37543 | 25587.2 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1205.11 | 1.8844 | 2.02912e+06 | 414021 | 327693 | 1908.05 | 2.75484 | 1.2817e+06 | 414021 | 207009 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 990.18 | 1.24009 | 2.46954e+06 | 418582 | 403192 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 499.037 | 1.16378 | 4.89948e+06 | 414021 | 791294 | 2481.73 | 4.22048 | 985470 | 414021 | 159172 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1196.11 | 3.33921 | 2.04442e+06 | 277014 | 220932 | 2415.03 | 6.1897 | 1.01263e+06 | 277014 | 109441 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1145 | 2.80071 | 2.13581e+06 | 277014 | 230783 | 2044.53 | 4.49268 | 1.19628e+06 | 277014 | 129294 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 688.081 | 1.37012 | 3.55387e+06 | 278407 | 385917 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1218.24 | 1.38284 | 2.00724e+06 | 466906 | 365544 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 966.47 | 1.10448 | 2.53006e+06 | 466906 | 460759 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 654.008 | 0.609604 | 3.739e+06 | 466906 | 680866 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1610.02 | 1.26289 | 1.51888e+06 | 699405 | 414328 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1364.6 | 1.01233 | 1.7919e+06 | 699405 | 488825 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-GNUCXX/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 2181.03 | 2.04008 | 1.12124e+06 | 631515 | 276188 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1836.79 | 1.54744 | 1.33132e+06 | 631515 | 327934 | 