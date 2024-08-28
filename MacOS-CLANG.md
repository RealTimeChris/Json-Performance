# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 18.1.8 compiler).  

Latest Results: (Aug 27, 2024)
#### Using the following commits:
----
| Jsonifier: [59d6a55](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2574.09 | 1609557 | 625292 | 496 | 2861.75 | 1609557 | 562438 | 203 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2327.83 | 1611146 | 692125 | 497 | 3325.24 | 1611146 | 484520 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1312.42 | 1612911 | 1.22896e+06 | 494 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2352.13 | 1336699 | 568292 | 99 | 2810.03 | 1336699 | 475688 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2232.18 | 1338288 | 599542 | 342 | 3215.75 | 1338288 | 416167 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1138.53 | 1340053 | 1.177e+06 | 242 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2585.37 | 1609557 | 622562 | 497 | 2930.91 | 1609557 | 549166 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2345.69 | 1611146 | 686854 | 499 | 3378.99 | 1611146 | 476813 | 259 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1312.98 | 1612911 | 1.22844e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2311.38 | 1336699 | 578312 | 256 | 2837.5 | 1336699 | 471083 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2257.05 | 1338288 | 592938 | 178 | 3080.36 | 1338288 | 434458 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1117.14 | 1340053 | 1.19954e+06 | 495 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2479.94 | 138774 | 55958.5 | 492 | 2507.03 | 138774 | 55354 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2045.19 | 138774 | 67854 | 177 | 3680.18 | 138774 | 37708.5 | 169 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 251.023 | 138774 | 552834 | 182 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1733.16 | 69037 | 39833 | 500 | 3384.83 | 69037 | 20396 | 498 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1597.78 | 69037 | 43208 | 417 | 2685.32 | 69037 | 25709 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 128.396 | 69037 | 537688 | 397 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2634.88 | 6661897 | 2.52835e+06 | 451 | 2127.98 | 6661897 | 3.13062e+06 | 495 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2311.57 | 6661897 | 2.88198e+06 | 97 | 2195.81 | 6661897 | 3.03392e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1942.89 | 6661897 | 3.42885e+06 | 192 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1317.24 | 2090234 | 1.58683e+06 | 99 | 982.667 | 2090234 | 2.1271e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1286.99 | 2090234 | 1.62412e+06 | 98 | 972.334 | 2090234 | 2.14971e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 692.776 | 2090234 | 3.01719e+06 | 210 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 3297.33 | 1439562 | 436584 | 99 | 2852.62 | 1439562 | 504646 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2723.48 | 1439584 | 528584 | 99 | 4317.4 | 1439584 | 333438 | 271 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.05967 | 222 | 209500 | 96 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | inf | 500299 | 0 | 499 | 3084.7 | 500299 | 162188 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1559.78 | 500299 | 320750 | 100 | 2381.2 | 500299 | 210104 | 260 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.81318 | 222 | 122437 | 248 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2977.73 | 722038 | 242479 | 94 | 3363.53 | 722038 | 214667 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2560.06 | 724019 | 282813 | 95 | 4430.51 | 724019 | 163416 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 467.127 | 721000 | 1.54348e+06 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2406.09 | 480967 | 199896 | 96 | 3949.1 | 480967 | 121792 | 237 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2363.42 | 478986 | 202666 | 451 | 3900.81 | 478986 | 122792 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 308.271 | 477948 | 1.55042e+06 | 215 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2554.84 | 1338365 | 523854 | 218 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1654.94 | 1338365 | 808708 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 415.503 | 1341710 | 3.22912e+06 | 500 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3085.16 | 1611223 | 522250 | 201 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 2134.42 | 1611223 | 754874 | 170 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1522.45 | 1611223 | 1.05831e+06 | 100 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/59d6a55) | 1122.58 | 1611223 | 1.43529e+06 | 422 | 