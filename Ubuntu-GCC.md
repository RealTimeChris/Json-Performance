# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Aug 26, 2024)
#### Using the following commits:
----
| Jsonifier: [59d6a55](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor                ), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 332.838 | 1473067 | 4.42578e+06 | 99 | 283.749 | 1473067 | 5.19144e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 284.343 | 1474598 | 5.18598e+06 | 99 | 472.17 | 1474598 | 3.12303e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 98.0839 | 1476331 | 1.50517e+07 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 315.257 | 1213370 | 3.84883e+06 | 99 | 396.897 | 1213370 | 3.05714e+06 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 303.107 | 1211839 | 3.99806e+06 | 96 | 295.423 | 1211839 | 4.10205e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 72.603 | 1215103 | 1.67363e+07 | 98 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 353.405 | 1474598 | 4.17255e+06 | 99 | 470.81 | 1474598 | 3.13205e+06 | 101 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 333.642 | 1473067 | 4.41511e+06 | 99 | 280.008 | 1473067 | 5.2608e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 73.8401 | 1476331 | 1.99936e+07 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 330.306 | 1211839 | 3.66883e+06 | 98 | 298.029 | 1211839 | 4.06618e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 314.585 | 1213370 | 3.85706e+06 | 98 | 420.754 | 1213370 | 2.8838e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 60.9497 | 1215103 | 1.99361e+07 | 98 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 206.486 | 138774 | 672073 | 98 | 422.524 | 138774 | 328440 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 202.005 | 138774 | 686981 | 98 | 478.659 | 138774 | 289922 | 101 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 3.29739 | 138774 | 4.20861e+07 | 98 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 118.363 | 69037 | 583264 | 101 | 233.492 | 69037 | 295672 | 95 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 98.1737 | 69037 | 703213 | 97 | 215.591 | 69037 | 320223 | 101 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 2.17368 | 69037 | 3.17604e+07 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 232.536 | 6661897 | 2.86488e+07 | 99 | 198.838 | 6661897 | 3.35042e+07 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 217.089 | 6661897 | 3.06873e+07 | 98 | 190.712 | 6661897 | 3.49317e+07 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 124.602 | 6661897 | 5.34653e+07 | 97 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 133.274 | 2090234 | 1.56838e+07 | 99 | 96.4054 | 2090234 | 2.16817e+07 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 109.126 | 2090234 | 1.91544e+07 | 100 | 86.3138 | 2090234 | 2.42167e+07 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 39.157 | 2090234 | 5.33808e+07 | 96 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 342.79 | 1439562 | 4.19955e+06 | 97 | 449.88 | 1439562 | 3.19988e+06 | 101 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 314.525 | 1439584 | 4.57701e+06 | 98 | 561.317 | 1439584 | 2.56465e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 0.686518 | 222 | 323371 | 101 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 212.443 | 500299 | 2.35498e+06 | 97 | 262.941 | 500299 | 1.9027e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 153.817 | 500299 | 3.25256e+06 | 98 | 249.187 | 500299 | 2.00772e+06 | 101 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.07888 | 222 | 205769 | 101 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 194.685 | 722038 | 3.70875e+06 | 99 | 328.547 | 722038 | 2.19767e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 194.604 | 724019 | 3.72047e+06 | 99 | 391.685 | 724019 | 1.84847e+06 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 10.1873 | 721000 | 7.07741e+07 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 209.23 | 478986 | 2.28928e+06 | 98 | 273.534 | 478986 | 1.7511e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 189.444 | 480967 | 2.53884e+06 | 98 | 425.833 | 480967 | 1.12947e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 6.75246 | 477948 | 7.07813e+07 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 270.051 | 1213426 | 4.49332e+06 | 101 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 167.54 | 1213426 | 7.24262e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 57.5963 | 1216959 | 2.11291e+07 | 97 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 612.179 | 1474654 | 2.40886e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 316.386 | 1474654 | 4.66093e+06 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 450.696 | 1474654 | 3.27195e+06 | 98 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 266.478 | 1474654 | 5.53386e+06 | 99 | 