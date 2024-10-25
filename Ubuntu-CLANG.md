# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Oct 25, 2024)
#### Using the following commits:
----
| Jsonifier: [55f790d](https://github.com/RealTimeChris/Jsonifier/commit/55f790d)  
| Glaze: [98fa3bc](https://github.com/stephenberry/glaze/commit/98fa3bc)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1775.6 | 1.37724e+06 | 762713 | 1.05044e+06 | 97 | 1659.51 | 1.47359e+06 | 762713 | 1.12393e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1185.53 | 2.06273e+06 | 762594 | 1.57302e+06 | 254 | 1755.69 | 1.39286e+06 | 762594 | 1.06219e+06 | 250 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 731.597 | 3.34259e+06 | 762594 | 2.54904e+06 | 99 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1411.58 | 1.73241e+06 | 513715 | 889962 | 157 | 1434.24 | 1.70503e+06 | 513715 | 875900 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 982.48 | 2.48904e+06 | 513596 | 1.27836e+06 | 99 | 1404.68 | 1.74092e+06 | 513596 | 894128 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 509.629 | 4.79846e+06 | 513596 | 2.46447e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2343.89 | 1.3831e+06 | 762713 | 1.05491e+06 | 173 | 2194.89 | 1.47699e+06 | 762713 | 1.12652e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1578.33 | 2.05441e+06 | 762594 | 1.56668e+06 | 98 | 2319.57 | 1.3979e+06 | 762594 | 1.06603e+06 | 183 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 390.63 | 6.69172e+06 | 762594 | 5.10307e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1877.41 | 1.72668e+06 | 513715 | 887022 | 162 | 1891.02 | 1.71426e+06 | 513715 | 880640 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1304.87 | 2.48539e+06 | 513596 | 1.27649e+06 | 99 | 1880.24 | 1.72484e+06 | 513596 | 885871 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 337.721 | 9.60094e+06 | 513596 | 4.931e+06 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2927.16 | 1.10765e+06 | 138774 | 153713 | 98 | 2483.6 | 1.30547e+06 | 138774 | 181166 | 187 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2375.02 | 1.36497e+06 | 138774 | 189422 | 98 | 2465.76 | 1.31474e+06 | 138774 | 182452 | 166 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1647.26 | 1.96892e+06 | 138482 | 272660 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2548.6 | 1.27208e+06 | 69037 | 87820.5 | 99 | 1973.31 | 1.64293e+06 | 69037 | 113423 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1698.23 | 1.90873e+06 | 69037 | 131773 | 98 | 1956.72 | 1.65658e+06 | 69037 | 114366 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 851.824 | 3.8066e+06 | 68745 | 261685 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 3001.59 | 1.08028e+06 | 6661897 | 7.19674e+06 | 97 | 2142.32 | 1.51358e+06 | 6661897 | 1.00833e+07 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2470.82 | 989724 | 6661897 | 6.59344e+06 | 98 | 1384.56 | 1.76622e+06 | 6661897 | 1.17663e+07 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1235.05 | 2.6255e+06 | 6661897 | 1.74908e+07 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1087.43 | 2.98278e+06 | 2090234 | 6.2347e+06 | 98 | 834.368 | 3.88746e+06 | 2090234 | 8.12569e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1058.15 | 3.06377e+06 | 2090234 | 6.40399e+06 | 99 | 814.639 | 3.97958e+06 | 2090234 | 8.31825e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 296.615 | 8.24446e+06 | 2090234 | 1.72328e+07 | 100 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 4561.68 | 710503 | 1439562 | 1.02281e+06 | 98 | 2971.2 | 1.09084e+06 | 1439562 | 1.57033e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 3297.33 | 983389 | 1439584 | 1.41567e+06 | 99 | 3208.56 | 1.01059e+06 | 1439584 | 1.45483e+06 | 165 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 2167.53 | 1.49598e+06 | 1426839 | 2.13453e+06 | 97 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 3545.69 | 914234 | 500299 | 457390 | 170 | 2359.5 | 1.37385e+06 | 500299 | 687336 | 187 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1910.52 | 1.6973e+06 | 500299 | 849158 | 97 | 2200.36 | 1.47372e+06 | 500299 | 737303 | 179 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 803.657 | 4.03468e+06 | 496312 | 2.00246e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 3706.61 | 874684 | 719230 | 629099 | 176 | 3261.87 | 993943 | 719230 | 714874 | 255 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2417.2 | 1.34087e+06 | 719139 | 964271 | 98 | 3401.36 | 952896 | 719139 | 685265 | 175 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1650.93 | 1.96357e+06 | 731130 | 1.43563e+06 | 98 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 3669.95 | 882990 | 477797 | 421890 | 180 | 3372.55 | 960855 | 477797 | 459094 | 183 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2027.76 | 1.59894e+06 | 477706 | 763824 | 99 | 3495.44 | 927574 | 477706 | 443108 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1148.28 | 2.82379e+06 | 497143 | 1.40383e+06 | 169 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 906.793 | 3.57597e+06 | 69037 | 246874 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 903.497 | 3.58768e+06 | 69037 | 247683 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 544.217 | 5.95723e+06 | 69037 | 411269 | 191 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2377.07 | 1.3641e+06 | 762713 | 1.04042e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1988.73 | 1.63068e+06 | 762713 | 1.24374e+06 | 164 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 4776.23 | 678904 | 118385 | 80372 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2265.57 | 1.43107e+06 | 118385 | 169418 | 100 | 