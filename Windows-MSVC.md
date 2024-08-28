# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.40.33813.0 compiler).  

Latest Results: (Aug 27, 2024)
#### Using the following commits:
----
| Jsonifier: [59d6a55](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor               ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2046.33 | 2008912 | 981716 | 185 | 1948.94 | 2008912 | 1.03077e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1490.58 | 2010833 | 1.34903e+06 | 203 | 2103.71 | 2010833 | 955850 | 157 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 307.591 | 2013065 | 6.54461e+06 | 97 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1808.21 | 1673873 | 925709 | 94 | 2032.94 | 1673873 | 823376 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1391.89 | 1675794 | 1.20397e+06 | 98 | 1921.29 | 1675794 | 872223 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 273.015 | 1678026 | 6.14629e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2045.33 | 2008912 | 982193 | 95 | 1939.9 | 2008912 | 1.03558e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1491.51 | 2010833 | 1.34818e+06 | 97 | 2091.13 | 2010833 | 961603 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 305.287 | 2013065 | 6.59401e+06 | 239 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1650.18 | 1673873 | 1.01436e+06 | 99 | 2027.2 | 1673873 | 825706 | 225 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1392.66 | 1675794 | 1.2033e+06 | 97 | 1907.52 | 1675794 | 878519 | 459 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 274.188 | 1678026 | 6.11997e+06 | 189 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1310.76 | 138774 | 105873 | 97 | 1895.76 | 138774 | 73202.2 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1104.09 | 138774 | 125691 | 98 | 1995.59 | 138774 | 69540.2 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 87.0482 | 138774 | 1.59422e+06 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 848.877 | 69037 | 81327.4 | 99 | 1350.47 | 69037 | 51120.6 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 752.269 | 69037 | 91771.7 | 98 | 1351.66 | 69037 | 51075.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 45.3305 | 69037 | 1.52297e+06 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 922.452 | 6661897 | 7.22194e+06 | 97 | 1115.44 | 6661897 | 5.97244e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 718.208 | 6661897 | 9.27572e+06 | 100 | 1019.32 | 6661897 | 6.53563e+06 | 201 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 443.228 | 6661897 | 1.50304e+07 | 175 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 363.045 | 2090234 | 5.75751e+06 | 98 | 431.919 | 2090234 | 4.83941e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 359.383 | 2090234 | 5.81617e+06 | 99 | 441.793 | 2090234 | 4.73126e+06 | 156 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 211.108 | 2090234 | 9.90124e+06 | 163 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2313.4 | 1439562 | 622272 | 96 | 2203.38 | 1439562 | 653343 | 187 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1752.52 | 1439584 | 821437 | 99 | 2414.47 | 1439584 | 596231 | 163 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.156762 | 222 | 1.41616e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1272.71 | 500299 | 393098 | 98 | 1496.38 | 500299 | 334339 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 960.057 | 500299 | 521114 | 97 | 1290.56 | 500299 | 387660 | 168 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.284442 | 222 | 780477 | 171 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1325.9 | 722038 | 544564 | 220 | 2340.11 | 722038 | 308549 | 173 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1055.82 | 724019 | 685742 | 98 | 2265.54 | 724019 | 319579 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 126.321 | 721000 | 5.7077e+06 | 98 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1067.15 | 478986 | 448845 | 98 | 2153.49 | 478986 | 222423 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 948.754 | 480967 | 506946 | 97 | 1970.79 | 480967 | 244048 | 170 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 85.62 | 477948 | 5.5822e+06 | 211 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1347.57 | 1675869 | 1.24362e+06 | 96 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1229.09 | 1675869 | 1.3635e+06 | 157 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 171.978 | 1679882 | 9.76803e+06 | 237 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2096.35 | 2010908 | 959243 | 185 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1598.48 | 2010908 | 1.25802e+06 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1098.92 | 2010908 | 1.8299e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 906.845 | 2010908 | 2.21748e+06 | 500 | 