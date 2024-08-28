# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.40.33813.0 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [c5c935a](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor              ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1969.37 | 1831389 | 929936 | 182 | 1960.5 | 1831389 | 934144 | 199 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1382.09 | 1833148 | 1.32636e+06 | 97 | 2089.02 | 1833148 | 877517 | 179 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 305.263 | 1835304 | 6.01221e+06 | 174 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1750 | 1517875 | 867358 | 96 | 2001.16 | 1517875 | 758496 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1317.93 | 1519634 | 1.15305e+06 | 192 | 1922.73 | 1519634 | 790353 | 192 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 270.417 | 1521790 | 5.62757e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1971.15 | 1831389 | 929098 | 99 | 1962.03 | 1831389 | 933414 | 156 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1382.96 | 1833148 | 1.32553e+06 | 97 | 2077.75 | 1833148 | 882277 | 189 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 305.238 | 1835304 | 6.01269e+06 | 96 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1771.39 | 1517875 | 856882 | 98 | 2021.54 | 1517875 | 750851 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1325.96 | 1519634 | 1.14607e+06 | 97 | 1907.54 | 1519634 | 796645 | 176 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 271.96 | 1521790 | 5.59565e+06 | 96 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1106.57 | 138774 | 125410 | 99 | 1991.13 | 138774 | 69696.3 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1054.42 | 138774 | 131612 | 177 | 1883.15 | 138774 | 73692.4 | 261 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 88.6307 | 138774 | 1.56576e+06 | 162 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 895.369 | 69037 | 77104.5 | 98 | 1345.19 | 69037 | 51321.4 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 725.036 | 69037 | 95218.7 | 97 | 1363.7 | 69037 | 50624.8 | 157 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 46.1348 | 69037 | 1.49642e+06 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 946.116 | 6661897 | 7.04131e+06 | 99 | 1103.86 | 6661897 | 6.03512e+06 | 201 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 717.532 | 6661897 | 9.28446e+06 | 98 | 1055.25 | 6661897 | 6.3131e+06 | 178 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 441.494 | 6661897 | 1.50894e+07 | 99 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 383.468 | 2090234 | 5.45087e+06 | 94 | 445.88 | 2090234 | 4.68789e+06 | 175 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 362.64 | 2090234 | 5.76394e+06 | 96 | 435.6 | 2090234 | 4.79851e+06 | 238 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 215.546 | 2090234 | 9.69739e+06 | 96 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1759.46 | 1439584 | 818198 | 99 | 2420.17 | 1439584 | 594828 | 182 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 36.3488 | 83046 | 2.2847e+06 | 157 | 1791.45 | 83046 | 46356.9 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.155813 | 222 | 1.42478e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 938.871 | 500299 | 532873 | 98 | 1309.5 | 500299 | 382053 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 47.7262 | 45175 | 946545 | 292 | 1452.65 | 45175 | 31098.3 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.285425 | 222 | 777788 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1122.28 | 722038 | 643369 | 334 | 2338.02 | 722038 | 308825 | 166 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1065.34 | 724019 | 679610 | 222 | 2274.08 | 724019 | 318378 | 193 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 126.014 | 721000 | 5.72159e+06 | 252 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1075.44 | 478986 | 445385 | 156 | 2169.48 | 478986 | 220784 | 253 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 922.669 | 480967 | 521278 | 197 | 1989.53 | 480967 | 241749 | 321 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 85.2212 | 477948 | 5.60832e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1298.18 | 1519697 | 1.17064e+06 | 185 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1224.44 | 1519697 | 1.24113e+06 | 185 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 173.591 | 1523545 | 8.77664e+06 | 316 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2063.26 | 1833211 | 888503 | 195 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 1608.46 | 1833211 | 1.13973e+06 | 173 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1389.93 | 1833211 | 1.31892e+06 | 169 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c5c935a) | 809.763 | 1833211 | 2.26388e+06 | 98 | 