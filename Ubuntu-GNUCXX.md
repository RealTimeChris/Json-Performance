# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Oct 17, 2024)
#### Using the following commits:
----
| Jsonifier: [c81734c](https://github.com/RealTimeChris/Jsonifier/commit/c81734c)  
| Glaze: [293eb5e](https://github.com/stephenberry/glaze/commit/293eb5e)  
| Simdjson: [36f5dbc](https://github.com/simdjson/simdjson/commit/36f5dbc)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3052.42 | 1.06215e+06 | 1772464 | 1.88263e+06 | 99 | 3241.15 | 1.0003e+06 | 1772464 | 1.773e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2319.21 | 1.39756e+06 | 1772396 | 2.47704e+06 | 98 | 3393.25 | 955204 | 1772396 | 1.693e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1441.86 | 2.24703e+06 | 1772396 | 3.98262e+06 | 293 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 4746.68 | 515187 | 1468205 | 756400 | 256 | 2450.55 | 997910 | 1468205 | 1.46514e+06 | 159 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2226.57 | 1.17385e+06 | 1468273 | 1.72354e+06 | 97 | 2479.73 | 1.05401e+06 | 1468273 | 1.54758e+06 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1232.35 | 2.62983e+06 | 1468205 | 3.86113e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2303.61 | 1.06157e+06 | 1772464 | 1.88159e+06 | 99 | 2401.27 | 1.01839e+06 | 1772464 | 1.80506e+06 | 161 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1837.52 | 1.39494e+06 | 1772396 | 2.47238e+06 | 98 | 2675.71 | 957961 | 1772396 | 1.69789e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 520.986 | 4.69385e+06 | 1772396 | 8.31937e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 4711.05 | 519084 | 1468205 | 762121 | 300 | 2426.47 | 1.00781e+06 | 1468205 | 1.47968e+06 | 96 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2079.49 | 1.17597e+06 | 1468273 | 1.72665e+06 | 98 | 2313.79 | 1.05689e+06 | 1468273 | 1.55181e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 437.883 | 5.58466e+06 | 1468205 | 8.19943e+06 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1972.44 | 1.2398e+06 | 138774 | 172052 | 97 | 2407.49 | 1.01576e+06 | 138774 | 140961 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1775.61 | 1.37724e+06 | 138774 | 191124 | 98 | 2069.09 | 1.18189e+06 | 138774 | 164016 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 506.926 | 5.5271e+06 | 47820 | 264306 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1553.39 | 1.57425e+06 | 69037 | 108682 | 99 | 1663.05 | 1.47045e+06 | 69037 | 101516 | 158 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1428.16 | 1.7123e+06 | 69037 | 118212 | 188 | 1768.01 | 1.38316e+06 | 69037 | 95489 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 253.491 | 1.08897e+07 | 23197 | 252608 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2722.17 | 1.0272e+06 | 6661897 | 6.84307e+06 | 97 | 1858.39 | 1.50464e+06 | 6661897 | 1.00237e+07 | 155 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2607.77 | 937746 | 6661897 | 6.24717e+06 | 97 | 1553.41 | 1.57423e+06 | 6661897 | 1.04874e+07 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 890.237 | 2.74694e+06 | 6661897 | 1.82999e+07 | 100 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 916.575 | 2.66801e+06 | 2090234 | 5.57676e+06 | 99 | 576.183 | 4.24419e+06 | 2090234 | 8.87135e+06 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 893.559 | 2.73673e+06 | 2090234 | 5.72041e+06 | 98 | 567.968 | 4.30557e+06 | 2090234 | 8.99966e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 278.91 | 8.76782e+06 | 2090234 | 1.83268e+07 | 100 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3313.39 | 784931 | 1439556 | 1.12995e+06 | 97 | 3064.33 | 848727 | 1439556 | 1.22179e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2465.59 | 991822 | 1439584 | 1.42781e+06 | 99 | 2398.13 | 1.01972e+06 | 1439584 | 1.46798e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1302.17 | 1.87796e+06 | 1423437 | 2.67316e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 3425.13 | 713968 | 500299 | 357198 | 300 | 2088.52 | 1.17089e+06 | 500299 | 585795 | 97 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1867.95 | 1.30915e+06 | 500293 | 654958 | 97 | 2078.85 | 1.17634e+06 | 500293 | 588514 | 165 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 471.766 | 5.18357e+06 | 492910 | 2.55503e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2141.26 | 1.14205e+06 | 719230 | 821399 | 161 | 2529.91 | 966606 | 719230 | 695212 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1782.88 | 1.37162e+06 | 719139 | 986382 | 159 | 2673.66 | 914638 | 719139 | 657752 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1203.34 | 2.33968e+06 | 658030 | 1.53958e+06 | 98 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 3495.2 | 699654 | 477706 | 334229 | 297 | 2724.27 | 897647 | 477706 | 428812 | 160 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1998.77 | 1.22347e+06 | 477797 | 584570 | 286 | 2295.46 | 1.06533e+06 | 477797 | 509012 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 686.215 | 3.56365e+06 | 419243 | 1.49403e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 838.056 | 3.13875e+06 | 69037 | 216690 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 730.386 | 3.34813e+06 | 69037 | 231145 | 206 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 489.092 | 4.99993e+06 | 69037 | 345180 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2478.87 | 986510 | 1772464 | 1.74855e+06 | 220 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2418.1 | 1.0113e+06 | 1772464 | 1.79249e+06 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3666.26 | 667010 | 118385 | 78964 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1725.27 | 1.41742e+06 | 118385 | 167801 | 99 | 