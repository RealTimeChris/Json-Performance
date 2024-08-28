# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.41.34120.0 compiler).  

Latest Results: (Aug 29, 2024)
#### Using the following commits:
----
| Jsonifier: [ed68533](https://github.com/RealTimeChris/Jsonifier/commit/ed68533)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2010.93 | 1955244 | 972308 | 97 | 1941.77 | 1953106 | 1.00584e+06 | 154 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1377.17 | 1955244 | 1.41975e+06 | 165 | 2063.65 | 1955162 | 947428 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 254.087 | 1616864 | 6.36342e+06 | 208 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1757.4 | 1614748 | 918829 | 97 | 1974.22 | 1612610 | 816833 | 190 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1357.96 | 1614748 | 1.1891e+06 | 97 | 1879.7 | 1614666 | 859002 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 271.543 | 1616864 | 5.95435e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 2024.81 | 1955244 | 965643 | 97 | 1935.72 | 1953106 | 1.00898e+06 | 186 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1379.55 | 1955244 | 1.41731e+06 | 98 | 2054.82 | 1955162 | 951499 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 185.428 | 1616864 | 8.71966e+06 | 95 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1771.7 | 1614748 | 911413 | 97 | 1992.71 | 1612610 | 809254 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1352.74 | 1614748 | 1.19369e+06 | 98 | 1879.36 | 1614666 | 859156 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 194.511 | 1616864 | 8.31244e+06 | 168 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1166.88 | 123050 | 105453 | 94 | 1883.4 | 138774 | 73682.7 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 940.394 | 123050 | 130849 | 99 | 1994.59 | 138774 | 69575 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 37.9001 | 53246 | 1.4049e+06 | 298 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 855.453 | 69037 | 80702.3 | 96 | 1360.21 | 69037 | 50754.8 | 251 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 638.865 | 69037 | 108062 | 174 | 1362.89 | 69037 | 50654.7 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 38.9748 | 53246 | 1.36617e+06 | 99 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1008.7 | 6885124 | 6.82576e+06 | 98 | 1119.03 | 6661897 | 5.95329e+06 | 195 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 652.572 | 6885124 | 1.05507e+07 | 98 | 1064.72 | 6661897 | 6.25692e+06 | 224 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 141.062 | 2090234 | 1.48178e+07 | 97 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 382.827 | 2090234 | 5.46e+06 | 97 | 450.907 | 2090234 | 4.63562e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 359.194 | 2090234 | 5.81923e+06 | 97 | 429.692 | 2090234 | 4.86449e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 217.275 | 2090234 | 9.62024e+06 | 98 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1960.74 | 1189390 | 606604 | 165 | 2241.66 | 1439562 | 642186 | 217 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1449.06 | 1189390 | 820801 | 99 | 2432.83 | 1439584 | 591732 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.155874 | 222 | 1.42422e+06 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1272.2 | 500299 | 393256 | 179 | 1523.99 | 500299 | 328283 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 944.697 | 500299 | 529587 | 97 | 1299.66 | 500299 | 384946 | 159 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.283047 | 222 | 784321 | 97 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1114.6 | 647860 | 581248 | 241 | 2360.77 | 722038 | 305849 | 295 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 930.298 | 647860 | 696400 | 163 | 2296.65 | 724019 | 315250 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 75.9872 | 426533 | 5.61322e+06 | 96 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 976.114 | 467771 | 479218 | 97 | 2233.62 | 478986 | 214443 | 165 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 889.329 | 467771 | 525982 | 268 | 1989.5 | 480967 | 241752 | 186 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 77.7597 | 426533 | 5.48527e+06 | 96 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 508.19 | 69037 | 135849 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 409.667 | 69037 | 168520 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 151.324 | 69037 | 456218 | 99 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2015.64 | 1955244 | 970038 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 1604.56 | 1955244 | 1.21856e+06 | 164 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1315.7 | 123050 | 93524.6 | 99 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/ed68533) | 745.335 | 123050 | 165093 | 168 | 