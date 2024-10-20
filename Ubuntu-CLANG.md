# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Oct 20, 2024)
#### Using the following commits:
----
| Jsonifier: [74b35c0](https://github.com/RealTimeChris/Jsonifier/commit/74b35c0)  
| Glaze: [df960ee](https://github.com/stephenberry/glaze/commit/df960ee)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2302.61 | 1.40866e+06 | 963533 | 1.35729e+06 | 162 | 2226.29 | 1.45694e+06 | 963533 | 1.40381e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1597.01 | 2.03086e+06 | 963397 | 1.95652e+06 | 98 | 2262.65 | 1.43341e+06 | 963397 | 1.38094e+06 | 297 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 679.441 | 3.59919e+06 | 963397 | 3.46745e+06 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1783.34 | 1.81808e+06 | 647457 | 1.17713e+06 | 99 | 1769.95 | 1.83183e+06 | 647457 | 1.18603e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1310.53 | 2.4739e+06 | 647321 | 1.60141e+06 | 98 | 1731.39 | 1.87254e+06 | 647321 | 1.21214e+06 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 626.246 | 5.17998e+06 | 647321 | 3.35311e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2291.6 | 1.41514e+06 | 963533 | 1.36354e+06 | 98 | 2200.81 | 1.47352e+06 | 963533 | 1.41979e+06 | 160 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1598.1 | 2.02904e+06 | 963397 | 1.95477e+06 | 98 | 2216.31 | 1.46306e+06 | 963397 | 1.40951e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 445.585 | 7.28023e+06 | 963397 | 7.01375e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1784.93 | 1.81611e+06 | 647457 | 1.17585e+06 | 185 | 1761.06 | 1.84073e+06 | 647457 | 1.19179e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1307.53 | 2.48005e+06 | 647321 | 1.60539e+06 | 98 | 1729.59 | 1.87485e+06 | 647321 | 1.21363e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 304.572 | 1.06506e+07 | 647321 | 6.89437e+06 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 3013.08 | 1.07658e+06 | 138774 | 149401 | 98 | 2889.65 | 1.12257e+06 | 138774 | 155783 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2316.35 | 1.40045e+06 | 138774 | 194346 | 236 | 2456.47 | 1.32056e+06 | 138774 | 183260 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 511.972 | 6.33609e+06 | 47820 | 302992 | 99 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2512.69 | 1.29106e+06 | 69037 | 89131 | 99 | 1958.05 | 1.65677e+06 | 69037 | 114378 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1748.3 | 1.85551e+06 | 69037 | 128098 | 98 | 1940.36 | 1.67184e+06 | 69037 | 115419 | 211 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 257.515 | 1.2597e+07 | 23197 | 292212 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 3297.21 | 983731 | 6661897 | 6.55352e+06 | 98 | 2108.13 | 1.5386e+06 | 6661897 | 1.025e+07 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2989.58 | 1.08449e+06 | 6661897 | 7.22478e+06 | 98 | 2103.39 | 1.54141e+06 | 6661897 | 1.02687e+07 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 991.924 | 3.26963e+06 | 6661897 | 2.17819e+07 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1103.55 | 2.95656e+06 | 2090234 | 6.17989e+06 | 99 | 818.376 | 3.98679e+06 | 2090234 | 8.33332e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1058.99 | 3.05986e+06 | 2090234 | 6.39582e+06 | 99 | 805.261 | 4.02398e+06 | 2090234 | 8.41106e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 236.832 | 1.03256e+07 | 2090234 | 2.1583e+07 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 3396.1 | 720071 | 1439556 | 1.03658e+06 | 98 | 2665.25 | 917527 | 1439556 | 1.32083e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 3335.76 | 975118 | 1439584 | 1.40376e+06 | 100 | 3421.24 | 950756 | 1439584 | 1.36869e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1098.94 | 2.22526e+06 | 1426596 | 3.17455e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2685.38 | 910646 | 500293 | 455590 | 207 | 1726.76 | 1.4162e+06 | 500293 | 708516 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1483.61 | 1.64831e+06 | 500299 | 824646 | 174 | 1618.93 | 1.51053e+06 | 500299 | 755715 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 527.401 | 6.12442e+06 | 496069 | 3.03814e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2772.79 | 881939 | 719230 | 634317 | 245 | 2847.98 | 858657 | 719230 | 617572 | 94 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1819.54 | 1.34399e+06 | 719139 | 966512 | 99 | 2543.63 | 961397 | 719139 | 691378 | 163 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1381.22 | 2.351e+06 | 752230 | 1.7685e+06 | 98 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2860.52 | 854891 | 477797 | 408464 | 177 | 2545.47 | 960700 | 477797 | 459020 | 178 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2117.12 | 1.53247e+06 | 477706 | 732072 | 98 | 3488.31 | 930086 | 477706 | 444308 | 184 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 743.872 | 3.28744e+06 | 518243 | 1.70369e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 920.521 | 3.53463e+06 | 69037 | 244020 | 189 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 908.504 | 3.53693e+06 | 69037 | 244179 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 409.146 | 5.97693e+06 | 69037 | 412629 | 95 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1957.29 | 1.6446e+06 | 963533 | 1.58462e+06 | 179 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1777.69 | 1.37563e+06 | 963533 | 1.32546e+06 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 4708.97 | 687908 | 118385 | 81438 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2164.95 | 1.49626e+06 | 118385 | 177135 | 98 | 