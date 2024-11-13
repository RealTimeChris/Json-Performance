# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Nov 24, 2024)
#### Using the following commits:
----
| Jsonifier: [eb8e1f4](https://github.com/RealTimeChris/Jsonifier/commit/eb8e1f4)  
| Glaze: [8f35df4](https://github.com/stephenberry/glaze/commit/8f35df4)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2538.78 | 1.27749e+06 | 2087065 | 2.66621e+06 | 100 | 2960.77 | 1.09542e+06 | 2087065 | 2.2862e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1890.69 | 1.71567e+06 | 2087065 | 3.58071e+06 | 98 | 2733.73 | 1.18658e+06 | 2087065 | 2.47647e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1197.81 | 2.70705e+06 | 2087065 | 5.6498e+06 | 214 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1578.41 | 1.5493e+06 | 1599309 | 2.47781e+06 | 98 | 1941.59 | 1.2595e+06 | 1599309 | 2.01433e+06 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1382.3 | 1.7691e+06 | 1599309 | 2.82933e+06 | 99 | 1838.56 | 1.33008e+06 | 1599309 | 2.12721e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 714.78 | 3.42123e+06 | 1599309 | 5.47161e+06 | 98 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 282.726 | 8.64946e+06 | 118028 | 1.02088e+06 | 98 | 3492.67 | 700160 | 118028 | 82638.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 258.225 | 1.25577e+07 | 118028 | 1.48216e+06 | 159 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 205.108 | 1.19226e+07 | 118028 | 1.40721e+06 | 166 | 3014.92 | 811108 | 118028 | 95733.5 | 223 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 322.04 | 7.59355e+06 | 91803 | 697110 | 98 | 3260.32 | 750057 | 91803 | 68857.5 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 229.386 | 1.40796e+07 | 91803 | 1.29255e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 210.599 | 1.16118e+07 | 91803 | 1.066e+06 | 99 | 2832.49 | 863349 | 91803 | 79258 | 99 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1880.38 | 1.3005e+06 | 2087065 | 2.71422e+06 | 97 | 2242.25 | 1.09062e+06 | 2087065 | 2.27618e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1428.25 | 1.71219e+06 | 2087065 | 3.57345e+06 | 98 | 2053.52 | 1.19085e+06 | 2087065 | 2.48538e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 435.101 | 5.62038e+06 | 2087065 | 1.17301e+07 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1561.84 | 1.56574e+06 | 1599309 | 2.5041e+06 | 97 | 1936.21 | 1.263e+06 | 1599309 | 2.01993e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1388.76 | 1.76087e+06 | 1599309 | 2.81618e+06 | 98 | 1827.65 | 1.33802e+06 | 1599309 | 2.1399e+06 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 339.122 | 7.21106e+06 | 1599309 | 1.15327e+07 | 97 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2076.69 | 1.17756e+06 | 138774 | 163415 | 99 | 2751.32 | 888819 | 138774 | 123345 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1618.11 | 2.00448e+06 | 138482 | 277585 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1508.3 | 1.62131e+06 | 138774 | 224996 | 195 | 2060.62 | 1.18674e+06 | 138774 | 164689 | 185 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1537.27 | 1.59076e+06 | 69037 | 109822 | 99 | 2104.71 | 1.16188e+06 | 69037 | 80213 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1091.62 | 2.24019e+06 | 69037 | 154656 | 98 | 1648.13 | 1.48376e+06 | 69037 | 102434 | 156 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 633.874 | 3.85791e+06 | 68745 | 265212 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2698.7 | 906152 | 6661897 | 6.03669e+06 | 98 | 1609.58 | 1.5193e+06 | 6661897 | 1.01214e+07 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2631.07 | 929442 | 6661897 | 6.19185e+06 | 97 | 1630.95 | 1.49939e+06 | 6661897 | 9.98876e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1232.76 | 2.6346e+06 | 6661897 | 1.75514e+07 | 100 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1309.14 | 2.47832e+06 | 2090234 | 5.18027e+06 | 98 | 790.115 | 4.10631e+06 | 2090234 | 8.58316e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 999.088 | 2.44766e+06 | 2090234 | 5.11619e+06 | 99 | 600.679 | 4.07111e+06 | 2090234 | 8.50957e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 292.977 | 8.34684e+06 | 2090234 | 1.74469e+07 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2545.92 | 960531 | 1439562 | 1.38274e+06 | 98 | 3306.62 | 739555 | 1439562 | 1.06464e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2493.7 | 1.29665e+06 | 1439584 | 1.86664e+06 | 99 | 3215.11 | 1.00571e+06 | 1439584 | 1.4478e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1628.76 | 1.99212e+06 | 1423437 | 2.83565e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2541.07 | 1.27654e+06 | 500299 | 638654 | 200 | 3295.17 | 984408 | 500299 | 492498 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2090.29 | 1.55183e+06 | 500299 | 776380 | 98 | 2789.14 | 1.163e+06 | 500299 | 581850 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 483.45 | 5.05828e+06 | 492910 | 2.49328e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2426.32 | 1.00788e+06 | 719107 | 724772 | 165 | 3432.15 | 712507 | 719107 | 512369 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1429.42 | 1.71078e+06 | 719139 | 1.23029e+06 | 98 | 2655.66 | 920838 | 719139 | 662210 | 195 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1067.27 | 2.29129e+06 | 659630 | 1.5114e+06 | 97 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2925.52 | 1.11036e+06 | 477674 | 530388 | 173 | 4336.55 | 749068 | 477674 | 357810 | 212 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1238.26 | 1.9749e+06 | 477706 | 943422 | 99 | 2802.32 | 872646 | 477706 | 416868 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 709.856 | 3.44496e+06 | 425643 | 1.46632e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 756.943 | 3.23067e+06 | 69037 | 223036 | 300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 660.357 | 3.7032e+06 | 69037 | 255658 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 493.188 | 4.95841e+06 | 69037 | 342314 | 186 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2177.62 | 1.12299e+06 | 2087065 | 2.34374e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1984.27 | 1.23241e+06 | 2087065 | 2.57212e+06 | 99 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3646.49 | 670626 | 118385 | 79392 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1854.14 | 1.3189e+06 | 118385 | 156138 | 98 | 