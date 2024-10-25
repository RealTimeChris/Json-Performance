# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.1 compiler).  

Latest Results: (Oct 25, 2024)
#### Using the following commits:
----
| Jsonifier: [55f790d](https://github.com/RealTimeChris/Jsonifier/commit/55f790d)  
| Glaze: [98fa3bc](https://github.com/stephenberry/glaze/commit/98fa3bc)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1995.09 | 546822 | 274084 | 208 | 2164.74 | 546822 | 252604 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1475.02 | 546741 | 370666 | 177 | 2419.43 | 546741 | 225979 | 295 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 710.669 | 546741 | 769333 | 299 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1330.48 | 282394 | 212250 | 298 | 1713.65 | 282394 | 164791 | 194 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 940.521 | 282313 | 300166 | 300 | 1750.55 | 282313 | 161271 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 386.036 | 282313 | 731313 | 267 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1979.6 | 546822 | 276229 | 296 | 2158.15 | 546822 | 253376 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1416.5 | 546741 | 385980 | 241 | 2352.84 | 546741 | 232375 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 272.163 | 546741 | 2.00888e+06 | 300 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1212.1 | 282394 | 232980 | 175 | 1695.42 | 282394 | 166562 | 195 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 944.388 | 282313 | 298938 | 300 | 1675.04 | 282313 | 168542 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 153.296 | 282313 | 1.84162e+06 | 230 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 3003.18 | 132014 | 43958 | 194 | 2246.24 | 132014 | 58771 | 234 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1792.08 | 138774 | 77437.5 | 299 | 3505.9 | 138774 | 39583 | 299 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1618.09 | 138482 | 85583.5 | 299 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1780.41 | 62277 | 34979 | 298 | 1822.72 | 62277 | 34167 | 212 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1246.72 | 69037 | 55375 | 171 | 2452.86 | 69037 | 28145.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 847.396 | 68745 | 81125 | 299 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2979.21 | 6661880 | 2.23612e+06 | 99 | 2065.63 | 6661880 | 3.2251e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2765.71 | 6661897 | 2.40875e+06 | 100 | 2179.64 | 6661897 | 3.05642e+06 | 298 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1056.81 | 6661897 | 6.30375e+06 | 98 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1006.32 | 2090234 | 2.0771e+06 | 159 | 951.413 | 2090234 | 2.19698e+06 | 216 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 948.446 | 2090217 | 2.20383e+06 | 100 | 920.057 | 2090217 | 2.27183e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 339.365 | 2090234 | 6.15925e+06 | 185 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 4281.96 | 1420987 | 331854 | 98 | 2363.14 | 1420987 | 601313 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2661.79 | 1439584 | 540833 | 173 | 4075.49 | 1439584 | 353230 | 279 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1915.26 | 1423437 | 743208 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2901.22 | 481724 | 166042 | 203 | 1838.5 | 481724 | 262020 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1632.08 | 500299 | 306542 | 294 | 2200.93 | 500299 | 227312 | 178 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 721.971 | 492910 | 682728 | 283 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2596.18 | 524969 | 202208 | 99 | 2596.71 | 524969 | 202167 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2236.53 | 719139 | 321542 | 300 | 4245.83 | 719139 | 169376 | 198 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1366.84 | 659130 | 482230 | 177 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1962.17 | 477706 | 243458 | 298 | 3682.32 | 477706 | 129730 | 169 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1668.67 | 283536 | 169917 | 172 | 2255.14 | 283536 | 125729 | 182 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 947.219 | 425143 | 448833 | 161 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 838.932 | 69037 | 82291.5 | 156 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 641.212 | 69037 | 107666 | 168 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 512.334 | 69037 | 134750 | 298 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 1346.12 | 546778 | 406187 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 1341.92 | 546778 | 407458 | 98 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/55f790d) | 2176.35 | 118385 | 54396 | 178 | 
| [glaze](https://github.com/stephenberry/glaze/commit/98fa3bc) | 2077.68 | 118385 | 56979.5 | 98 | 