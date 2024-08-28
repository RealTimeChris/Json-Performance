# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 18.1.8 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [c146b5e](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2611.14 | 1881053 | 720396 | 100 | 2885.05 | 1881053 | 652000 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2328.26 | 1882977 | 808750 | 188 | 3382.34 | 1882977 | 556708 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1270.24 | 1885067 | 1.48402e+06 | 259 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2314.46 | 1557003 | 672730 | 100 | 2789.5 | 1557003 | 558166 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2298.95 | 1558927 | 678104 | 230 | 3176.49 | 1558927 | 490770 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1077.18 | 1561017 | 1.44917e+06 | 488 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2586.67 | 1881053 | 727209 | 498 | 2886.25 | 1881053 | 651729 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2330.84 | 1882977 | 807854 | 210 | 3342.81 | 1882977 | 563292 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1310.95 | 1885067 | 1.43794e+06 | 98 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2309.52 | 1557003 | 674167 | 100 | 2643.84 | 1557003 | 588916 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2299.16 | 1558927 | 678042 | 100 | 3155.06 | 1558927 | 494104 | 212 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1129.35 | 1561017 | 1.38223e+06 | 159 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2400.42 | 138774 | 57812.5 | 496 | 2486.43 | 138774 | 55812.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1971.92 | 138774 | 70375 | 308 | 3610.38 | 138774 | 38437.5 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 254.262 | 138774 | 545792 | 304 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1733.12 | 69037 | 39834 | 97 | 3765.72 | 69037 | 18333 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1630.79 | 69037 | 42333.5 | 97 | 2687.57 | 69037 | 25687.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 119.605 | 69037 | 577208 | 393 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2641.12 | 6661897 | 2.52238e+06 | 97 | 2064.58 | 6661897 | 3.22675e+06 | 199 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2335.77 | 6661897 | 2.85212e+06 | 99 | 2340.12 | 6661897 | 2.84681e+06 | 192 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1945 | 6661897 | 3.42515e+06 | 172 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1342.58 | 2090234 | 1.55688e+06 | 100 | 982.455 | 2090234 | 2.12756e+06 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1289.44 | 2090234 | 1.62104e+06 | 98 | 973.135 | 2090234 | 2.14794e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 687.695 | 2090234 | 3.03948e+06 | 98 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 3281.99 | 1439562 | 438624 | 98 | 2853.21 | 1439562 | 504542 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2689.97 | 1439584 | 535167 | 96 | 4183.83 | 1439584 | 344083 | 187 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.07203 | 222 | 207084 | 96 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2228.09 | 500299 | 224542 | 97 | 3087.48 | 500299 | 162041 | 160 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1622.48 | 500299 | 308354 | 99 | 2382.84 | 500299 | 209959 | 270 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.71982 | 222 | 129084 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2965.25 | 722038 | 243500 | 98 | 3369.09 | 722038 | 214312 | 198 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2558.56 | 724019 | 282979 | 99 | 4435.03 | 724019 | 163250 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 468.334 | 721000 | 1.5395e+06 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2406.84 | 480967 | 199834 | 96 | 3933.61 | 480967 | 122271 | 95 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2392.19 | 478986 | 200229 | 214 | 4333.89 | 478986 | 110521 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 313.781 | 477948 | 1.52319e+06 | 97 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2530.07 | 1558999 | 616187 | 97 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1626.29 | 1558999 | 958625 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 407.891 | 1563064 | 3.83206e+06 | 99 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 3154.19 | 1883049 | 597000 | 100 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 2019.63 | 1883049 | 932375 | 202 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1801.57 | 1883049 | 1.04523e+06 | 100 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/c146b5e) | 1165.97 | 1883049 | 1.615e+06 | 495 | 