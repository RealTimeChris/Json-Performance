# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.40.33813.0 compiler).  

Latest Results: (Aug 27, 2024)
#### Using the following commits:
----
| Jsonifier: [39a1062](https://github.com/RealTimeChris/Jsonifier/commit/39a1062)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor              ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1992.56 | 1812025 | 909397 | 97 | 1940.37 | 1812025 | 933855 | 330 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1450.19 | 1813786 | 1.25072e+06 | 98 | 2051.57 | 1813786 | 884095 | 161 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 295.939 | 1815884 | 6.13601e+06 | 97 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1779.3 | 1502143 | 844235 | 185 | 1999.48 | 1502143 | 751267 | 268 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1368.62 | 1503904 | 1.09885e+06 | 175 | 1879.06 | 1503904 | 800349 | 171 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 262.431 | 1506002 | 5.73865e+06 | 95 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1992.99 | 1812025 | 909199 | 160 | 1893.07 | 1812025 | 957187 | 171 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1457.43 | 1813786 | 1.24451e+06 | 98 | 2034.58 | 1813786 | 891481 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 307.452 | 1815884 | 5.90623e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1777.79 | 1502143 | 844948 | 95 | 1996.32 | 1502143 | 752456 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1373.86 | 1503904 | 1.09466e+06 | 98 | 1872.73 | 1503904 | 803054 | 247 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 273.445 | 1506002 | 5.50752e+06 | 97 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1302.62 | 138774 | 106534 | 96 | 1879.3 | 138774 | 73843.3 | 95 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1083.25 | 138774 | 128109 | 99 | 1987.44 | 138774 | 69825.6 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 87.508 | 138774 | 1.58584e+06 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 863.505 | 69037 | 79949.8 | 99 | 1353.12 | 69037 | 51020.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 732.669 | 69037 | 94226.7 | 98 | 1356.85 | 69037 | 50880.4 | 496 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 45.4357 | 69037 | 1.51944e+06 | 170 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 929.054 | 6661897 | 7.17062e+06 | 99 | 1117.55 | 6661897 | 5.96116e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 739.298 | 6661897 | 9.01112e+06 | 98 | 1092.47 | 6661897 | 6.09803e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 444.032 | 6661897 | 1.50032e+07 | 163 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 367.944 | 2090234 | 5.68085e+06 | 290 | 448.275 | 2090234 | 4.66284e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 356.396 | 2090234 | 5.86491e+06 | 98 | 432.67 | 2090234 | 4.83101e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 218.843 | 2090234 | 9.5513e+06 | 98 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 2376.09 | 1439562 | 605853 | 159 | 2236.37 | 1439562 | 643704 | 157 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1752.73 | 1439584 | 821336 | 98 | 2437.94 | 1439584 | 590493 | 180 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.156806 | 222 | 1.41576e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1264.2 | 500299 | 395742 | 172 | 1529.82 | 500299 | 327032 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 950.644 | 500299 | 526274 | 96 | 1306.22 | 500299 | 383014 | 163 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.281513 | 222 | 788595 | 96 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1319.47 | 722038 | 547217 | 497 | 2354.29 | 722038 | 306690 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1061.38 | 724019 | 682146 | 176 | 2253 | 724019 | 321358 | 212 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 125.521 | 721000 | 5.74405e+06 | 96 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1044.5 | 478986 | 458577 | 184 | 2151.7 | 478986 | 222608 | 198 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 918.419 | 480967 | 523690 | 99 | 1977.84 | 480967 | 243177 | 189 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 85.6095 | 477948 | 5.58289e+06 | 95 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1339.86 | 1503961 | 1.12248e+06 | 169 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1215.19 | 1503961 | 1.23763e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 166.054 | 1507995 | 9.08136e+06 | 206 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2074.38 | 1813843 | 874404 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 1540.15 | 1813843 | 1.17771e+06 | 156 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1101.14 | 1813843 | 1.64724e+06 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/39a1062) | 874.412 | 1813843 | 2.07436e+06 | 500 | 