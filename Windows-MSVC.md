# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.41.34123.0 compiler).  

Latest Results: (Nov 12, 2024)
#### Using the following commits:
----
| Jsonifier: [f34dc2e](https://github.com/RealTimeChris/Jsonifier/commit/f34dc2e)  
| Glaze: [952e960](https://github.com/stephenberry/glaze/commit/952e960)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1695.46 | 1.44231e+06 | 1973086 | 2.8458e+06 | 258 | 1909.09 | 1.2809e+06 | 1973086 | 2.52733e+06 | 252 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1234.59 | 1.98073e+06 | 1973086 | 3.90814e+06 | 275 | 1751.97 | 1.39581e+06 | 1973086 | 2.75404e+06 | 278 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 386.743 | 6.32304e+06 | 1973086 | 1.24759e+07 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1399.45 | 1.74736e+06 | 1522565 | 2.66047e+06 | 299 | 1669.26 | 1.46492e+06 | 1522565 | 2.23044e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1118.44 | 2.18643e+06 | 1522565 | 3.32899e+06 | 300 | 1532.51 | 1.59568e+06 | 1522565 | 2.42953e+06 | 250 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 301.109 | 8.1213e+06 | 1522565 | 1.23652e+07 | 191 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1702.19 | 1.43661e+06 | 1973086 | 2.83456e+06 | 98 | 1890.68 | 1.29341e+06 | 1973086 | 2.55201e+06 | 178 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1234.22 | 1.98133e+06 | 1973086 | 3.90933e+06 | 295 | 1762.85 | 1.38719e+06 | 1973086 | 2.73704e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 108.001 | 2.26423e+07 | 1973086 | 4.46752e+07 | 183 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1401.28 | 1.74508e+06 | 1522565 | 2.657e+06 | 97 | 1655.62 | 1.47705e+06 | 1522565 | 2.2489e+06 | 235 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1120.83 | 2.18174e+06 | 1522565 | 3.32184e+06 | 161 | 1517.25 | 1.61173e+06 | 1522565 | 2.45397e+06 | 210 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 86.4907 | 2.82737e+07 | 1522565 | 4.30485e+07 | 226 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1452.84 | 1.68319e+06 | 138774 | 233583 | 98 | 2014.02 | 1.21419e+06 | 138774 | 168498 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1032.99 | 2.36731e+06 | 138774 | 328520 | 98 | 1970.05 | 1.2413e+06 | 138774 | 172260 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 366.426 | 6.67363e+06 | 138482 | 924177 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 961.321 | 2.5438e+06 | 69037 | 175616 | 98 | 1629.78 | 1.50044e+06 | 69037 | 103586 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 775.109 | 3.1549e+06 | 69037 | 217805 | 186 | 1350.08 | 1.81132e+06 | 69037 | 125048 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 186.756 | 1.30939e+07 | 68745 | 900142 | 294 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1894.63 | 1.29068e+06 | 6661897 | 8.59841e+06 | 99 | 1129.41 | 2.16523e+06 | 6661897 | 1.44245e+07 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1056.41 | 2.31482e+06 | 6661897 | 1.54211e+07 | 290 | 1022.36 | 2.39193e+06 | 6661897 | 1.59348e+07 | 293 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 394.929 | 6.19197e+06 | 6661897 | 4.12503e+07 | 300 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 654.326 | 3.73727e+06 | 2090234 | 7.81176e+06 | 291 | 453.882 | 5.38775e+06 | 2090234 | 1.12617e+07 | 184 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 354.231 | 6.90339e+06 | 2090234 | 1.44297e+07 | 189 | 419.572 | 5.82831e+06 | 2090234 | 1.21825e+07 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 121.695 | 2.00943e+07 | 2090234 | 4.20017e+07 | 300 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2893.15 | 845226 | 1439562 | 1.21676e+06 | 300 | 2619.22 | 933649 | 1439562 | 1.34405e+06 | 199 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1885.76 | 1.29675e+06 | 1439584 | 1.86678e+06 | 300 | 2410.57 | 1.01446e+06 | 1439584 | 1.4604e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 625.628 | 3.9087e+06 | 1425381 | 5.57139e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1776.13 | 1.37681e+06 | 500299 | 688818 | 174 | 1865.88 | 1.3106e+06 | 500299 | 655693 | 163 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1175.45 | 2.0804e+06 | 500299 | 1.04082e+06 | 97 | 1252.87 | 1.95185e+06 | 500299 | 976508 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 227.027 | 1.07713e+07 | 494854 | 5.33023e+06 | 99 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1622.86 | 1.50683e+06 | 719107 | 1.08357e+06 | 159 | 2550.87 | 958663 | 719107 | 689381 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1067.86 | 2.29e+06 | 719139 | 1.64683e+06 | 98 | 2398.47 | 1.01957e+06 | 719139 | 733212 | 158 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 320.129 | 7.63873e+06 | 657230 | 5.0204e+06 | 184 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1325.08 | 1.84547e+06 | 477674 | 881534 | 97 | 2638.8 | 926712 | 477674 | 442666 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 945.427 | 2.58654e+06 | 477706 | 1.23561e+06 | 161 | 2195.36 | 1.11387e+06 | 477706 | 532103 | 202 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 181.27 | 1.34903e+07 | 365943 | 4.93669e+06 | 99 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 559.195 | 4.37303e+06 | 69037 | 301901 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 540.527 | 4.52404e+06 | 69037 | 312326 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 292.566 | 8.35836e+06 | 69037 | 577036 | 182 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1643.69 | 1.4877e+06 | 1973086 | 2.93537e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1637.49 | 1.49338e+06 | 1973086 | 2.94657e+06 | 181 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2311.02 | 1.05815e+06 | 123050 | 130205 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1372.35 | 1.7819e+06 | 123050 | 219262 | 176 | 