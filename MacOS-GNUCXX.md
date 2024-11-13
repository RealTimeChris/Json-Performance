# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Nov 24, 2024)
#### Using the following commits:
----
| Jsonifier: [eb8e1f4](https://github.com/RealTimeChris/Jsonifier/commit/eb8e1f4)  
| Glaze: [8f35df4](https://github.com/stephenberry/glaze/commit/8f35df4)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1971.4 | 2147023 | 1.08908e+06 | 98 | 3021.76 | 2147023 | 710521 | 95 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1703.73 | 2147023 | 1.26019e+06 | 300 | 2628 | 2147023 | 816979 | 181 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 929.506 | 2147023 | 2.30985e+06 | 300 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1669.01 | 1655758 | 992062 | 98 | 2553.87 | 1655758 | 648333 | 196 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1639.63 | 1655758 | 1.00983e+06 | 98 | 2296.74 | 1655758 | 720916 | 219 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 791.542 | 1655758 | 2.09181e+06 | 296 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 258.411 | 100705 | 389708 | 271 | 4134.96 | 100705 | 24354.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 224.246 | 100705 | 449084 | 206 | 3290.58 | 100705 | 30604 | 197 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 177.2 | 100705 | 568313 | 273 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 263.207 | 78474 | 298146 | 100 | 3911.48 | 78474 | 20062.5 | 299 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 200.029 | 78474 | 392312 | 184 | 3269.75 | 78474 | 24000 | 229 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 162.669 | 78474 | 482416 | 300 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1963.7 | 2147023 | 1.09335e+06 | 294 | 2732.16 | 2147023 | 785834 | 297 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1794.79 | 2147023 | 1.19625e+06 | 195 | 2522.01 | 2147023 | 851313 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 497.904 | 2147023 | 4.31212e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1636.63 | 1655758 | 1.01169e+06 | 199 | 2437.55 | 1655758 | 679270 | 97 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1634.14 | 1655758 | 1.01323e+06 | 99 | 2549.61 | 1655758 | 649417 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 371.757 | 1655758 | 4.45388e+06 | 300 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3065.41 | 138774 | 45271 | 98 | 4000.69 | 138774 | 34687.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1813.06 | 138774 | 76541.5 | 98 | 3498.52 | 138774 | 39666.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1651.47 | 138482 | 83854 | 96 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1942.43 | 69037 | 35541.5 | 99 | 4720.48 | 69037 | 14625 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1265.76 | 69037 | 54542 | 173 | 3068.31 | 69037 | 22500 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 786.408 | 68745 | 87416.5 | 300 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 3335.26 | 6661897 | 1.99742e+06 | 95 | 2275.27 | 6661897 | 2.92796e+06 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2251.1 | 6661897 | 2.9594e+06 | 99 | 2345.1 | 6661897 | 2.84077e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1193.93 | 6661897 | 5.57981e+06 | 98 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1352.74 | 2090234 | 1.54519e+06 | 97 | 942.724 | 2090234 | 2.21723e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1292.68 | 2090234 | 1.61698e+06 | 98 | 962.475 | 2090234 | 2.17173e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 397.649 | 2090234 | 5.25648e+06 | 169 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3288.24 | 1439562 | 437791 | 165 | 4552.87 | 1439562 | 316188 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2150.04 | 1439584 | 669562 | 298 | 4126.12 | 1439584 | 348896 | 297 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1682.34 | 1423437 | 846104 | 99 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2637.21 | 500299 | 189708 | 98 | 3417.44 | 500299 | 146396 | 201 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1447.17 | 500299 | 345708 | 98 | 2308.18 | 500299 | 216750 | 93 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 770.599 | 492910 | 639646 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3913.68 | 719139 | 183750 | 186 | 5083.01 | 719139 | 141479 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2300.02 | 719139 | 312667 | 95 | 4306.75 | 719139 | 166980 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1440.9 | 659630 | 457792 | 99 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3224.56 | 477706 | 148146 | 253 | 6077.38 | 477706 | 78604 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2197.19 | 477706 | 217417 | 95 | 4494.32 | 477706 | 106291 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 991.501 | 425643 | 429292 | 97 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 872.958 | 69037 | 79084 | 97 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 586.715 | 69037 | 117667 | 177 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 535.775 | 69037 | 128854 | 300 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2274.59 | 2147023 | 943916 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1754.4 | 2147023 | 1.22379e+06 | 97 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2120.34 | 118385 | 55833 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1773.56 | 118385 | 66750 | 98 | 