# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Aug 28, 2024)
#### Using the following commits:
----
| Jsonifier: [da428c0](https://github.com/RealTimeChris/Jsonifier/commit/da428c0)  
| Glaze: [7b85e5d](https://github.com/stephenberry/glaze/commit/7b85e5d)  
| Simdjson: [9f546d2](https://github.com/simdjson/simdjson/commit/9f546d2)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2295.86 | 2095450 | 912709 | 500 | 1093.68 | 2095450 | 1.91596e+06 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1648.24 | 2097553 | 1.2726e+06 | 500 | 2679.15 | 2097553 | 782916 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1173.83 | 2100082 | 1.78908e+06 | 500 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2024.35 | 1738154 | 858625 | 500 | 2288.05 | 1738154 | 759666 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2010.84 | 1740257 | 865437 | 500 | 2866.39 | 1740257 | 607125 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 984.266 | 1742786 | 1.77065e+06 | 500 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2388.66 | 2095450 | 877250 | 97 | 2429.45 | 2095450 | 862520 | 95 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2130.35 | 2097553 | 984604 | 500 | 3039.47 | 2097553 | 690104 | 498 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1227.24 | 2100082 | 1.71123e+06 | 444 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GCC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2033.31 | 1740257 | 855876 | 500 | 2855.02 | 1740257 | 609542 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2012.92 | 1738154 | 863500 | 500 | 2499.89 | 1738154 | 695292 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 999.71 | 1742786 | 1.74329e+06 | 500 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1971.92 | 138774 | 70375 | 99 | 3335.59 | 138774 | 41604 | 99 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1809.59 | 138774 | 76688 | 500 | 2750.26 | 138774 | 50458.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 226.147 | 138774 | 613646 | 500 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1656.08 | 69037 | 41687 | 240 | 2881.58 | 69037 | 23958 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1543.43 | 69037 | 44729.5 | 98 | 2340.24 | 69037 | 29500 | 496 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 134.493 | 69037 | 513312 | 500 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2178.02 | 6661897 | 3.05869e+06 | 500 | 2168.38 | 6661897 | 3.07229e+06 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2091.5 | 6661897 | 3.18523e+06 | 500 | 1671.69 | 6661897 | 3.98512e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1783.91 | 6661897 | 3.73444e+06 | 500 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1228.15 | 2090234 | 1.70194e+06 | 500 | 637.489 | 2090234 | 3.27885e+06 | 500 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1146.72 | 2090234 | 1.82279e+06 | 500 | 846.856 | 2090234 | 2.46823e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 672.953 | 2090234 | 3.10606e+06 | 500 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | inf | 222 | 0 | 499 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | inf | 1439562 | 0 | 499 | 2537.7 | 1439562 | 567270 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2465.39 | 1439584 | 583916 | 500 | 3930.82 | 1439584 | 366230 | 500 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2368.51 | 500299 | 211229 | 499 | 2385.22 | 500299 | 209750 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1469.49 | 500299 | 340458 | 500 | 2183.52 | 500299 | 229124 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 1.55676 | 222 | 142604 | 500 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2343.96 | 722038 | 308042 | 500 | 3446.48 | 722038 | 209500 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2279.78 | 724019 | 317583 | 500 | 3939.35 | 724019 | 183792 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 388.662 | 721000 | 1.85508e+06 | 500 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 2238.69 | 478986 | 213958 | 244 | 2669.38 | 478986 | 179438 | 500 | 
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2222.63 | 480967 | 216396 | 500 | 3519.28 | 480967 | 136666 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 304.26 | 477948 | 1.57085e+06 | 500 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2388.33 | 1740351 | 728688 | 491 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1448.23 | 1740351 | 1.20171e+06 | 500 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9f546d2) | 356.347 | 1744950 | 4.89677e+06 | 500 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/s) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 2799.82 | 2097647 | 749208 | 498 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1714.64 | 2097647 | 1.22338e+06 | 500 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/s) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/7b85e5d) | 1612.02 | 2097647 | 1.30125e+06 | 497 | 
| [jsonifier](https://github.com/RealTimeChris/Jsonifier/commit/da428c0) | 1033.5 | 2097647 | 2.02965e+06 | 500 | 