# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 19.1.0 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [c146b5e](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor              ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2811 | 1995479 | 709881 | 163 | 2589.48 | 1995479 | 770611 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1802.86 | 1997420 | 1.10792e+06 | 99 | 2563.83 | 1997420 | 779077 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 965.768 | 1999684 | 2.07056e+06 | 224 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2257.01 | 1658730 | 734925 | 98 | 2433.01 | 1658730 | 681761 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1765.62 | 1660671 | 940558 | 99 | 2226.11 | 1660671 | 745996 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 753.684 | 1662935 | 2.20641e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2495.08 | 1995479 | 799766 | 99 | 2578.85 | 1995479 | 773788 | 162 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1802.5 | 1997420 | 1.10814e+06 | 98 | 2558.48 | 1997420 | 780706 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 935.795 | 1999684 | 2.13688e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2262.85 | 1658730 | 733027 | 98 | 2568.67 | 1658730 | 645755 | 159 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1885.91 | 1660671 | 880565 | 98 | 2211.04 | 1660671 | 751080 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 766.526 | 1662935 | 2.16944e+06 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1920.49 | 138774 | 72259.6 | 98 | 2001.67 | 138774 | 69329.2 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1381.97 | 138774 | 100417 | 98 | 1884.17 | 138774 | 73652.4 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 193.736 | 138774 | 716305 | 99 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1704 | 69037 | 40514.7 | 206 | 1589.41 | 69037 | 43435.5 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1304.88 | 69037 | 52906.6 | 229 | 1495.08 | 69037 | 46176.1 | 204 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 111.248 | 69037 | 620568 | 99 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2093.62 | 6661897 | 3.18199e+06 | 100 | 1594.08 | 6661897 | 4.17915e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2070.17 | 6661897 | 3.21804e+06 | 98 | 1483.99 | 6661897 | 4.48919e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1354.54 | 6661897 | 4.91819e+06 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 962.297 | 2090234 | 2.17213e+06 | 97 | 606.046 | 2090234 | 3.44897e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 926.269 | 2090234 | 2.25662e+06 | 95 | 605.293 | 2090234 | 3.45326e+06 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 490.101 | 2090234 | 4.2649e+06 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2759.09 | 1439562 | 521753 | 296 | 2530.76 | 1439562 | 568825 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2673.21 | 1439584 | 538523 | 99 | 2583.22 | 1439584 | 557284 | 159 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.22756 | 222 | 180847 | 166 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1958.76 | 500299 | 255416 | 94 | 1770.21 | 500299 | 282622 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1252.7 | 500299 | 399378 | 204 | 1644.65 | 500299 | 304197 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.990882 | 222 | 224043 | 97 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1982.81 | 722038 | 364149 | 173 | 2597.14 | 722038 | 278013 | 183 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1731.32 | 724019 | 418190 | 189 | 2334.05 | 724019 | 310198 | 159 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 287.893 | 721000 | 2.5044e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1768.68 | 478986 | 270815 | 159 | 2321.91 | 478986 | 206289 | 215 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1631.03 | 480967 | 294885 | 97 | 2360.11 | 480967 | 203790 | 166 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 190.259 | 477948 | 2.5121e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2033.22 | 1660742 | 816803 | 161 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1592.42 | 1660742 | 1.0429e+06 | 162 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 422.316 | 1664946 | 3.94241e+06 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2490.84 | 1997491 | 801935 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2469.64 | 1997491 | 808818 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1409.67 | 1997491 | 1.417e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1078.73 | 1997491 | 1.85171e+06 | 98 | 