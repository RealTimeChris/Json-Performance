# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.3 compiler).  

Latest Results: (Nov 24, 2024)
#### Using the following commits:
----
| Jsonifier: [eb8e1f4](https://github.com/RealTimeChris/Jsonifier/commit/eb8e1f4)  
| Glaze: [8f35df4](https://github.com/stephenberry/glaze/commit/8f35df4)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2322.08 | 2121562 | 913646 | 300 | 2942.95 | 2121562 | 720896 | 171 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1864.9 | 2121562 | 1.13762e+06 | 98 | 2797.74 | 2121562 | 758312 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 961.969 | 2121562 | 2.20544e+06 | 200 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1868.99 | 1630696 | 872500 | 98 | 2559.8 | 1630696 | 637042 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1742.04 | 1630696 | 936084 | 294 | 2459.73 | 1630696 | 662958 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 768.547 | 1630696 | 2.12179e+06 | 97 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 270.784 | 95914 | 354209 | 98 | 4070.53 | 95914 | 23563 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 209.267 | 95914 | 458334 | 99 | 3525.08 | 95914 | 27209 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 176.292 | 95914 | 544062 | 300 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 274.679 | 74850 | 272500 | 273 | 4318.35 | 74850 | 17333 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 196.253 | 74850 | 381396 | 98 | 3326.67 | 74850 | 22500 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 161.547 | 74850 | 463333 | 99 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2154.74 | 2121562 | 984604 | 299 | 2741.4 | 2121562 | 773896 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1793.44 | 2121562 | 1.18296e+06 | 174 | 2705.93 | 2121562 | 784042 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 452.582 | 2121562 | 4.68769e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1782.06 | 1630696 | 915062 | 251 | 2450.41 | 1630696 | 665480 | 173 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1627.85 | 1630696 | 1.00175e+06 | 300 | 2244.91 | 1630696 | 726396 | 222 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 353.462 | 1630696 | 4.6135e+06 | 298 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3469.35 | 138774 | 40000 | 255 | 3964.97 | 138774 | 35000 | 192 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1690.22 | 138774 | 82104 | 96 | 3487.57 | 138774 | 39791 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1525.97 | 138482 | 90750 | 162 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2140.68 | 69037 | 32250 | 171 | 4442.25 | 69037 | 15541 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1233.73 | 69037 | 55958 | 97 | 2948.28 | 69037 | 23416 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 847.61 | 68745 | 81104.5 | 157 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3357.63 | 6661897 | 1.9841e+06 | 300 | 2270.84 | 6661897 | 2.93367e+06 | 296 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 3312.18 | 6661897 | 2.01133e+06 | 256 | 2183.33 | 6661897 | 3.05125e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1112.61 | 6661897 | 5.98762e+06 | 300 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1425.34 | 2090234 | 1.46648e+06 | 182 | 922.747 | 2090234 | 2.26523e+06 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1243.65 | 2090234 | 1.68073e+06 | 98 | 915.397 | 2090234 | 2.28342e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 372.944 | 2090234 | 5.60469e+06 | 296 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3268.95 | 1439562 | 440375 | 297 | 4580.95 | 1439562 | 314250 | 216 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2080.07 | 1439584 | 692084 | 187 | 4162.66 | 1439584 | 345833 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1671.85 | 1423437 | 851416 | 218 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2928.59 | 500299 | 170833 | 209 | 3617.7 | 500299 | 138292 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1527.82 | 500299 | 327458 | 98 | 2296.93 | 500299 | 217812 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 761.226 | 492910 | 647521 | 300 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 4096.2 | 719139 | 175562 | 298 | 5253.98 | 719139 | 136875 | 196 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2348.85 | 719139 | 306167 | 161 | 4197.83 | 719139 | 171312 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1360.06 | 659630 | 485000 | 196 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3448.1 | 477706 | 138542 | 297 | 6045.34 | 477706 | 79020.5 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2080.37 | 477706 | 229625 | 229 | 4467.17 | 477706 | 106937 | 187 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 951.29 | 425643 | 447438 | 161 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 900.972 | 69037 | 76625 | 163 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 705.806 | 69037 | 97813 | 179 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 455.253 | 69037 | 151646 | 300 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2523.54 | 2121562 | 840708 | 300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1955.51 | 2121562 | 1.08492e+06 | 300 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2335.59 | 118385 | 50687.5 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2233.68 | 118385 | 53000 | 98 | 