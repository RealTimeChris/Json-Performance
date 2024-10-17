# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the Clang 19.1.1 compiler).  

Latest Results: (Oct 17, 2024)
#### Using the following commits:
----
| Jsonifier: [c81734c](https://github.com/RealTimeChris/Jsonifier/commit/c81734c)  
| Glaze: [293eb5e](https://github.com/stephenberry/glaze/commit/293eb5e)  
| Simdjson: [36f5dbc](https://github.com/simdjson/simdjson/commit/36f5dbc)  

 > At least 30 iterations on a (Apple M1 (Virtual)), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2592.57 | 1767650 | 681812 | 99 | 2885.76 | 1767650 | 612542 | 300 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2221.34 | 1767584 | 795729 | 229 | 3267.75 | 1767584 | 540917 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 711.85 | 1767584 | 2.48308e+06 | 300 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2281.6 | 1458036 | 639041 | 99 | 2695.39 | 1458036 | 540938 | 176 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2173.1 | 1457970 | 670917 | 97 | 3065.11 | 1457970 | 475667 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 929.692 | 1457970 | 1.56823e+06 | 197 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2586.41 | 1767650 | 683438 | 98 | 2878.81 | 1767650 | 614021 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2211.84 | 1767584 | 799146 | 99 | 3264.36 | 1767584 | 541479 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 581.997 | 1767584 | 3.0371e+06 | 99 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/MacOS-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2288.01 | 1458036 | 637250 | 96 | 2667.14 | 1458036 | 546666 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2171.89 | 1457970 | 671292 | 97 | 3013.51 | 1457970 | 483812 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 494.105 | 1457970 | 2.95073e+06 | 214 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3409.01 | 138774 | 40708 | 94 | 2817.75 | 138774 | 49250 | 196 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1935.81 | 138774 | 71688 | 97 | 3725.48 | 138774 | 37250 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 563.417 | 47820 | 84875 | 96 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 1979.56 | 69037 | 34875 | 99 | 2291.68 | 69037 | 30125 | 290 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1478.7 | 69037 | 46687.5 | 99 | 2663.77 | 69037 | 25917 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 290.871 | 23197 | 79750 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2988.23 | 6661897 | 2.22938e+06 | 298 | 2165.93 | 6661897 | 3.07577e+06 | 239 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2752.09 | 6661897 | 2.42067e+06 | 299 | 1972 | 6661897 | 3.37825e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1141.98 | 6661897 | 5.83365e+06 | 295 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1023.38 | 2090234 | 2.04248e+06 | 300 | 847.757 | 2090234 | 2.4656e+06 | 300 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 969.112 | 2090234 | 2.15685e+06 | 300 | 889.461 | 2090234 | 2.35e+06 | 300 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 311.384 | 2090234 | 6.71273e+06 | 300 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 4584.57 | 1439556 | 314000 | 167 | 3724.19 | 1439556 | 386542 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2880.61 | 1439584 | 499750 | 99 | 4188.39 | 1439584 | 343708 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1992.58 | 1427811 | 716562 | 300 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3241.63 | 500293 | 154334 | 95 | 2200.1 | 500293 | 227396 | 95 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 1834.14 | 500299 | 272770 | 98 | 2344.24 | 500299 | 213416 | 194 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 784.463 | 497284 | 633916 | 95 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 3223.14 | 719230 | 223146 | 232 | 3271.7 | 719230 | 219834 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2441.38 | 719139 | 294563 | 99 | 4420.37 | 719139 | 162688 | 95 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 1431.64 | 659030 | 460334 | 230 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- | ------------ | -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2695.93 | 477797 | 177229 | 163 | 3389.12 | 477797 | 140980 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2225.77 | 477706 | 214625 | 95 | 3915.62 | 477706 | 122000 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 970.74 | 425043 | 437854 | 97 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 899.505 | 69037 | 76750 | 207 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 712.331 | 69037 | 96917 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/36f5dbc) | 557.501 | 69037 | 123833 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | -------------------- | --------------- | --------------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 3093.22 | 1767650 | 571459 | 98 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2032.61 | 1767650 | 869646 | 97 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/c81734c) | 2487.97 | 118385 | 47583 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/293eb5e) | 2222.34 | 118385 | 53270.5 | 98 | 