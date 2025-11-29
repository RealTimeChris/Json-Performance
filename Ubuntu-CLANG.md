# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.11.0-1018-azure using the Clang 20.1.8 compiler).  

Latest Results: (Dec 07, 2025)
#### Using the following commits:
----
| Jsonifier: [142ebb1](https://github.com/RealTimeChris/Jsonifier/commit/142ebb1)  
| Glaze: [5954d42](https://github.com/stephenberry/glaze/commit/5954d42)  
| Simdjson: [ae32422](https://github.com/simdjson/simdjson/commit/ae32422)  

 > 1400 iterations on a (AMD EPYC 7763 64-Core Processor), where the most stable 20 subsequent iterations are sampled.

#### Note:
These benchmarks were executed using the CPU benchmark library [benchmarksuite](https://github.com/RealTimeChris/benchmarksuite).

### Double Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Double%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Double%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Double%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Double%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Double Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 539.414 | 2.28271 | 4.4967e+06 | 2195 | 3882.75 | 464.789 | 2.03106 | 5.22193e+06 | 2190 | 4495.4 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 336.94 | 4.06445 | 7.22413e+06 | 2197 | 6224.15 | 379.767 | 3.95102 | 6.39502e+06 | 2194 | 5518.9 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 157.383 | 5.57213 | 1.55e+07 | 2196 | 13331.5 | 

### String Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/String%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/String%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/String%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/String%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/String Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 617.152 | 3.47217 | 3.94153e+06 | 4293 | 6635.85 | 863.483 | 2.86599 | 2.81121e+06 | 4334 | 4787.85 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 297.369 | 2.84428 | 8.20025e+06 | 4214 | 13515.2 | 753.437 | 4.47277 | 3.22366e+06 | 4252 | 5385 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 232.236 | 6.18047 | 1.05266e+07 | 4356 | 17917.2 | 

### Uint Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Uint%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Uint%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Uint%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Uint%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Uint Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 547.1 | 4.38323 | 4.38165e+06 | 1036 | 1806.75 | 391.459 | 4.69739 | 6.15147e+06 | 1009 | 2460.55 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 246.634 | 6.60412 | 9.83432e+06 | 1044 | 4045 | 319.148 | 5.69267 | 7.57746e+06 | 1050 | 3143.95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 165.301 | 5.27449 | 1.47085e+07 | 1052 | 6073.8 | 

### Int Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Int%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Int%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Int%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Int%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Int Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 449.889 | 4.26097 | 5.35151e+06 | 1041 | 2209.1 | 407.841 | 4.97248 | 5.90295e+06 | 1046 | 2446.15 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 229.556 | 6.57839 | 1.05734e+07 | 1054 | 4387.5 | 297.852 | 7.14048 | 8.11212e+06 | 1053 | 3378.3 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 163.898 | 4.32454 | 1.48373e+07 | 1051 | 6118.95 | 

### Bool Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Bool%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Bool%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Bool%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Bool%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Bool Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 386.739 | 3.31309 | 6.12457e+06 | 448 | 1107.05 | 427.804 | 1.43753 | 5.50816e+06 | 451 | 1006.3 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 146.139 | 7.75693 | 1.65902e+07 | 449 | 2940.5 | 139.798 | 7.76361 | 1.72894e+07 | 450 | 3083.2 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 111.356 | 1.14769 | 2.17994e+07 | 448 | 3843.2 | 

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1023.54 | 1.43193 | 2.38707e+06 | 47584 | 44331 | 1430.61 | 1.60665 | 1.70741e+06 | 46644 | 31100.1 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 882.104 | 1.61464 | 2.76967e+06 | 45489 | 49172.1 | 1182.19 | 2.00819 | 2.06544e+06 | 46712 | 37660.9 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 502.274 | 5.72485 | 4.88936e+06 | 47608 | 90817 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Json%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Json Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 774.777 | 1.19734 | 3.15321e+06 | 31946 | 39323.1 | 1232.07 | 1.27254 | 1.98077e+06 | 31866 | 24659.8 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 760.979 | 1.35738 | 3.21049e+06 | 32585 | 40836.2 | 1100.14 | 3.25291 | 2.22303e+06 | 31621 | 27447.9 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 374.322 | 6.24828 | 6.53137e+06 | 33291 | 84838.8 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 771.96 | 15.9144 | 3.02661e+06 | 1033 | 1252.8 | 1522.48 | 13.9751 | 1.45663e+06 | 949 | 584.15 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 539.875 | 11.1108 | 4.35325e+06 | 915 | 1590.85 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 564.198 | 14.2184 | 4.16812e+06 | 767 | 1283.45 | 1407.96 | 12.6106 | 1.56691e+06 | 696 | 470.4 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 385.166 | 11.0875 | 6.16839e+06 | 688 | 1693.5 | 

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
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1066.94 | 1.22952 | 2.28909e+06 | 47659 | 42579.7 | 1457.44 | 1.2219 | 1.67525e+06 | 50161 | 32811.8 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 704.789 | 7.86539 | 3.47753e+06 | 46169 | 62650.2 | 1205.53 | 2.41936 | 2.02582e+06 | 47328 | 37427.5 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 512.282 | 6.03184 | 4.78852e+06 | 50300 | 93972.4 | 

### Abc (Out of Order) Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc%20%28Out%20of%20Order%29%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Abc (Out of Order) Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 799.143 | 1.3244 | 3.05823e+06 | 32975 | 39362.6 | 1254.71 | 1.74178 | 1.94612e+06 | 32898 | 25007.2 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 735.93 | 1.28412 | 3.31984e+06 | 32310 | 41865.2 | 1089.33 | 2.60894 | 2.24268e+06 | 31647 | 27716.3 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 375.496 | 5.02365 | 6.50843e+06 | 33244 | 84420 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1593.52 | 1.2867 | 1.53361e+06 | 92442 | 55326.6 | 1891.5 | 1.46024 | 1.29158e+06 | 92442 | 46611.2 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1112.08 | 7.6273 | 2.19984e+06 | 92442 | 79346.5 | 720.387 | 5.06778 | 3.39579e+06 | 92442 | 122477 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 725.877 | 5.43287 | 3.36987e+06 | 92442 | 121528 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Discord%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Discord Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1117.76 | 1.27912 | 2.18614e+06 | 55353 | 47229 | 1593.15 | 1.62775 | 1.53322e+06 | 55353 | 33137.5 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 951.995 | 12.0083 | 2.57228e+06 | 55353 | 55566.6 | 1443.73 | 1.89111 | 1.69223e+06 | 55353 | 36570.8 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 447.297 | 5.98111 | 5.46847e+06 | 55353 | 118101 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1062.89 | 0.225796 | 2.30069e+06 | 6661897 | 5.97738e+06 | 735.479 | 2.46976 | 3.32514e+06 | 6661897 | 8.63913e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 706.34 | 0.391558 | 3.46206e+06 | 6661897 | 8.99474e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 704.35 | 3.31791 | 3.47328e+06 | 6661897 | 9.02394e+06 | 1249.6 | 3.65318 | 1.96186e+06 | 6661897 | 5.0972e+06 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Canada%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Canada Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 489.713 | 0.18311 | 4.9935e+06 | 2090234 | 4.07056e+06 | 482.979 | 0.610137 | 5.063e+06 | 2090234 | 4.12734e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 456.263 | 0.201049 | 5.35958e+06 | 2090234 | 4.36899e+06 | 550.278 | 1.02899 | 4.44393e+06 | 2090234 | 3.6226e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 269.772 | 0.315542 | 9.06464e+06 | 2090234 | 7.38922e+06 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1828.5 | 0.72378 | 1.33733e+06 | 1439562 | 750840 | 2566.58 | 1.32839 | 952651 | 1439562 | 534933 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1593.82 | 0.498554 | 1.53424e+06 | 1439584 | 861400 | 1830.31 | 0.686492 | 1.33594e+06 | 1439584 | 750109 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1075.06 | 0.515485 | 2.27458e+06 | 1423415 | 1.26271e+06 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/CitmCatalog Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1085.92 | 1.37399 | 2.25189e+06 | 500299 | 439421 | 1912.46 | 2.41988 | 1.27874e+06 | 500299 | 249539 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1051.82 | 1.34903 | 2.32491e+06 | 500299 | 453660 | 1512.2 | 2.0416 | 1.61702e+06 | 500299 | 315559 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 402.443 | 0.584092 | 6.07623e+06 | 492910 | 1.16807e+06 | 

### Twitter Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Partial Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 2049.65 | 1.99353 | 1.19113e+06 | 44653 | 20780 | 3348.1 | 2.34949 | 728249 | 44653 | 12722.4 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1530.79 | 1.88453 | 1.59565e+06 | 44653 | 27822.1 | 

### Twitter Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Partial%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Partial Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1923.85 | 2.5936 | 1.2687e+06 | 37543 | 18614 | 4168.24 | 2.45659 | 584004 | 37543 | 8593.05 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 1337.87 | 1.43318 | 1.82533e+06 | 37543 | 26764.5 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Prettified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1538.71 | 2.75808 | 1.58939e+06 | 414021 | 256684 | 2445.19 | 3.80494 | 1.00021e+06 | 414021 | 161544 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1230.32 | 1.90592 | 1.98763e+06 | 414021 | 320983 | 1886.31 | 2.75665 | 1.29639e+06 | 414021 | 209376 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 920.196 | 1.26345 | 2.65737e+06 | 418582 | 433852 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter%20Test%20%28Minified%29_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Twitter Test (Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | -------------------------------- | -----------------| ------------------- | -------------- | ------------ | --------------------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1292.91 | 3.12599 | 1.89126e+06 | 277014 | 204386 | 2345.21 | 6.01298 | 1.04312e+06 | 277014 | 112736 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1140.19 | 2.89123 | 2.1447e+06 | 277014 | 231747 | 1867.54 | 4.43661 | 1.30955e+06 | 277014 | 141528 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 634.613 | 1.21629 | 3.85332e+06 | 278407 | 418427 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Minify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Minify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1149.63 | 1.45356 | 2.12709e+06 | 466906 | 387370 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1078.16 | 1.25142 | 2.26813e+06 | 466906 | 413039 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/ae32422) | 621.384 | 0.597802 | 3.93496e+06 | 466906 | 716612 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Prettify%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Prettify Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Percentage Deviation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | --------------------------------- | ----------------- | -------------------- | --------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 1565.12 | 1.21226 | 1.56241e+06 | 699405 | 426208 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 1509.9 | 1.18127 | 1.6194e+06 | 699405 | 441796 | 

### Validate Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/Validate%20Test.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Ubuntu-CLANG/Validate Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Percentage Deviation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | -------------------------------- | ---------------- | ------------------- | -------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/142ebb1) | 2514.84 | 2.32317 | 972438 | 631515 | 239549 | 
| [glaze](https://github.com/stephenberry/glaze/commit/5954d42) | 2286.33 | 2.14564 | 1.06958e+06 | 631515 | 263471 | 