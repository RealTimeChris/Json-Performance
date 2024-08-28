# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.41.34123.0 compiler).  

Latest Results: (Oct 20, 2024)
#### Using the following commits:
----
| Jsonifier: [74b35c0](https://github.com/RealTimeChris/Jsonifier/commit/74b35c0)  
| Glaze: [df960ee](https://github.com/stephenberry/glaze/commit/df960ee)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1298.04 | 1.8839e+06 | 850119 | 1.60154e+06 | 300 | 1285.46 | 1.90237e+06 | 850119 | 1.61724e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 767.358 | 3.18678e+06 | 850010 | 2.70879e+06 | 300 | 1295.62 | 1.88746e+06 | 850010 | 1.60436e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 300.124 | 8.14798e+06 | 850010 | 6.92587e+06 | 300 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 954.519 | 2.56191e+06 | 576473 | 1.47687e+06 | 300 | 1015.74 | 2.40753e+06 | 576473 | 1.38788e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 614.644 | 3.97857e+06 | 576364 | 2.2931e+06 | 300 | 1063.66 | 2.29906e+06 | 576364 | 1.3251e+06 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 195.81 | 1.24887e+07 | 576364 | 7.19803e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1382.04 | 1.76942e+06 | 850119 | 1.50421e+06 | 194 | 1328.36 | 1.84093e+06 | 850119 | 1.56501e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 833.623 | 2.93347e+06 | 850010 | 2.49348e+06 | 289 | 1426.75 | 1.71399e+06 | 850010 | 1.4569e+06 | 174 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 84.4709 | 2.89497e+07 | 850010 | 2.46075e+07 | 234 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1033.75 | 2.36558e+06 | 576473 | 1.36369e+06 | 96 | 1124.65 | 2.17438e+06 | 576473 | 1.25347e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 638.638 | 3.82909e+06 | 576364 | 2.20695e+06 | 178 | 1079.11 | 2.26616e+06 | 576364 | 1.30613e+06 | 290 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 57.5933 | 4.24597e+07 | 576364 | 2.44723e+07 | 97 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1432.78 | 1.70676e+06 | 138774 | 236854 | 96 | 1967.12 | 1.24315e+06 | 138774 | 172517 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1109.22 | 2.20462e+06 | 138774 | 305944 | 298 | 1922.62 | 1.27192e+06 | 138774 | 176510 | 200 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 90.9161 | 2.68975e+07 | 47820 | 1.28624e+06 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 892.935 | 2.73863e+06 | 69037 | 189066 | 99 | 1391.1 | 1.75791e+06 | 69037 | 121360 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 747.982 | 3.26935e+06 | 69037 | 225706 | 299 | 1283.8 | 1.90483e+06 | 69037 | 131504 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 44.8144 | 5.45676e+07 | 23197 | 1.2658e+06 | 161 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1520.94 | 1.60782e+06 | 6661897 | 1.07112e+07 | 97 | 1089.69 | 2.24415e+06 | 6661897 | 1.49503e+07 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1113.64 | 2.19585e+06 | 6661897 | 1.46285e+07 | 178 | 1118.67 | 2.18602e+06 | 6661897 | 1.4563e+07 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 448.211 | 5.45593e+06 | 6661897 | 3.63468e+07 | 242 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 490.237 | 4.98821e+06 | 2090234 | 1.04265e+07 | 97 | 450.386 | 5.42962e+06 | 2090234 | 1.13492e+07 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 362.827 | 6.73986e+06 | 2090234 | 1.40879e+07 | 96 | 432.123 | 5.65911e+06 | 2090234 | 1.18289e+07 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 143.21 | 1.70756e+07 | 2090234 | 3.56921e+07 | 165 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2792.75 | 875626 | 1439556 | 1.26051e+06 | 97 | 2246.18 | 1.08871e+06 | 1439556 | 1.56725e+06 | 159 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1991.08 | 1.22818e+06 | 1439584 | 1.76807e+06 | 98 | 2432.1 | 1.00548e+06 | 1439584 | 1.44747e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 629.774 | 3.88295e+06 | 1425381 | 5.53468e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1684.4 | 1.4518e+06 | 500293 | 726326 | 97 | 1599.12 | 1.52923e+06 | 500293 | 765062 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1084.28 | 2.25532e+06 | 500299 | 1.12834e+06 | 97 | 1383.28 | 1.76784e+06 | 500299 | 884450 | 180 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 226.501 | 1.07964e+07 | 494854 | 5.34267e+06 | 228 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1568.97 | 1.55861e+06 | 719230 | 1.121e+06 | 98 | 2238.49 | 1.09244e+06 | 719230 | 785715 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1068.52 | 2.28859e+06 | 719139 | 1.64581e+06 | 96 | 2404.75 | 1.01691e+06 | 719139 | 731300 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 321.184 | 7.61374e+06 | 657230 | 5.00398e+06 | 97 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1297.54 | 1.88464e+06 | 477797 | 900473 | 99 | 2286.71 | 1.06941e+06 | 477797 | 510960 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 856.838 | 2.85398e+06 | 477706 | 1.36336e+06 | 161 | 2028.85 | 1.20532e+06 | 477706 | 575786 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 207.424 | 1.17893e+07 | 416843 | 4.91431e+06 | 96 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 517.4 | 4.72631e+06 | 69037 | 326290 | 298 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 474.899 | 5.14934e+06 | 69037 | 355495 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 285.942 | 8.55212e+06 | 69037 | 590413 | 98 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1282.22 | 1.90716e+06 | 850119 | 1.62131e+06 | 173 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1243.37 | 1.96674e+06 | 850119 | 1.67197e+06 | 167 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2241.84 | 1.0908e+06 | 123050 | 134224 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1343.47 | 1.82023e+06 | 123050 | 223979 | 99 | 