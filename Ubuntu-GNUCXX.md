# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Nov 12, 2024)
#### Using the following commits:
----
| Jsonifier: [f34dc2e](https://github.com/RealTimeChris/Jsonifier/commit/f34dc2e)  
| Glaze: [952e960](https://github.com/stephenberry/glaze/commit/952e960)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1979.9 | 1.23513e+06 | 2150711 | 2.6564e+06 | 98 | 2284.11 | 1.07063e+06 | 2150711 | 2.30261e+06 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1455.21 | 1.68047e+06 | 2150711 | 3.6142e+06 | 98 | 2111.17 | 1.15833e+06 | 2150711 | 2.49123e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 912.566 | 2.67973e+06 | 2150711 | 5.76332e+06 | 94 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2193.28 | 1.47847e+06 | 1660617 | 2.45517e+06 | 98 | 2690.48 | 1.20525e+06 | 1660617 | 2.00145e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1384.83 | 1.76587e+06 | 1660617 | 2.93243e+06 | 98 | 1894.77 | 1.29062e+06 | 1660617 | 2.14322e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 728.711 | 3.35583e+06 | 1660617 | 5.57275e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2608.63 | 1.24305e+06 | 2150711 | 2.67344e+06 | 99 | 3009 | 1.07766e+06 | 2150711 | 2.31772e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1928.2 | 1.68239e+06 | 2150711 | 3.61834e+06 | 99 | 2789.68 | 1.16285e+06 | 2150711 | 2.50096e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 601.459 | 5.39305e+06 | 2150711 | 1.15989e+07 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2199.16 | 1.47507e+06 | 1660617 | 2.44953e+06 | 97 | 2675.42 | 1.21249e+06 | 1660617 | 2.01348e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1838.42 | 1.76375e+06 | 1660617 | 2.92891e+06 | 99 | 2492.8 | 1.30075e+06 | 1660617 | 2.16006e+06 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 473.054 | 6.85736e+06 | 1660617 | 1.13874e+07 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2901.33 | 1.11807e+06 | 138774 | 155158 | 98 | 3556.74 | 912037 | 138774 | 126567 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2235.58 | 1.45103e+06 | 138774 | 201366 | 98 | 2742.22 | 1.18294e+06 | 138774 | 164162 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1600.05 | 2.02739e+06 | 138482 | 280758 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2124.81 | 1.52671e+06 | 69037 | 105400 | 99 | 2786.89 | 1.16401e+06 | 69037 | 80360 | 177 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2044.51 | 1.58668e+06 | 69037 | 109540 | 167 | 2187.64 | 1.48287e+06 | 69037 | 102373 | 229 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 830.374 | 3.90674e+06 | 68745 | 268569 | 222 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3569.91 | 908669 | 6661897 | 6.05346e+06 | 98 | 2070.32 | 1.56685e+06 | 6661897 | 1.04382e+07 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 3188.1 | 1.01751e+06 | 6661897 | 6.77855e+06 | 96 | 2186.11 | 1.48388e+06 | 6661897 | 9.88544e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1171.03 | 2.76812e+06 | 6661897 | 1.84409e+07 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 1200.58 | 2.7019e+06 | 2090234 | 5.6476e+06 | 99 | 804.804 | 4.03062e+06 | 2090234 | 8.42494e+06 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 1193.07 | 2.71795e+06 | 2090234 | 5.68116e+06 | 96 | 819.569 | 3.95661e+06 | 2090234 | 8.27024e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 368.43 | 8.80288e+06 | 2090234 | 1.84001e+07 | 100 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 4339.12 | 747588 | 1439562 | 1.0762e+06 | 98 | 4352.6 | 745273 | 1439562 | 1.07287e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 3370.72 | 962371 | 1439584 | 1.38541e+06 | 98 | 3261.93 | 994468 | 1439584 | 1.43162e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1763.47 | 1.83948e+06 | 1423437 | 2.61839e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2886.51 | 1.12295e+06 | 500299 | 561809 | 192 | 3258.05 | 994889 | 500299 | 497742 | 176 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2682.62 | 1.20921e+06 | 500299 | 604966 | 98 | 2812.7 | 1.15329e+06 | 500299 | 576988 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 651.595 | 4.97836e+06 | 492910 | 2.45388e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3325.19 | 975545 | 719107 | 701521 | 176 | 4497.28 | 721296 | 719107 | 518689 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2359.76 | 1.37463e+06 | 719139 | 988550 | 98 | 3541.79 | 915865 | 719139 | 658634 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1389.24 | 2.33497e+06 | 645230 | 1.50659e+06 | 161 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 3037.37 | 1.06802e+06 | 477674 | 510164 | 174 | 4284.31 | 757172 | 477674 | 361682 | 174 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2564.14 | 1.26465e+06 | 477706 | 604133 | 97 | 3731.57 | 869003 | 477706 | 415128 | 225 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 923.196 | 3.51258e+06 | 416843 | 1.46419e+06 | 173 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 982.169 | 3.30288e+06 | 69037 | 228021 | 212 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 864.062 | 3.75199e+06 | 69037 | 259026 | 245 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 629.069 | 5.15697e+06 | 69037 | 356022 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2691.88 | 1.2051e+06 | 2150711 | 2.59182e+06 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 2450.84 | 1.32309e+06 | 2150711 | 2.84559e+06 | 99 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/f34dc2e) | 4861.57 | 667006 | 118385 | 78963.5 | 181 | 
| [glaze](https://github.com/stephenberry/glaze/commit/952e960) | 2497.85 | 1.29873e+06 | 118385 | 153750 | 99 | 