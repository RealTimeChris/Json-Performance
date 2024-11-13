# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the Clang 20.0.0 compiler).  

Latest Results: (Nov 24, 2024)
#### Using the following commits:
----
| Jsonifier: [eb8e1f4](https://github.com/RealTimeChris/Jsonifier/commit/eb8e1f4)  
| Glaze: [8f35df4](https://github.com/stephenberry/glaze/commit/8f35df4)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1958.92 | 1.24836e+06 | 2135663 | 2.66608e+06 | 258 | 2334.07 | 1.04771e+06 | 2135663 | 2.23756e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1503.72 | 1.62625e+06 | 2135663 | 3.47313e+06 | 98 | 2172.75 | 1.1255e+06 | 2135663 | 2.4037e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 818.249 | 2.98862e+06 | 2135663 | 6.38268e+06 | 298 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2219.81 | 1.46137e+06 | 1637703 | 2.39328e+06 | 98 | 2748.87 | 1.1801e+06 | 1637703 | 1.93266e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1856.75 | 1.74644e+06 | 1637703 | 2.86015e+06 | 97 | 2523.99 | 1.28476e+06 | 1637703 | 2.10405e+06 | 100 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 855.941 | 3.78713e+06 | 1637703 | 6.20219e+06 | 99 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 340.219 | 9.52931e+06 | 92086 | 877516 | 99 | 5002.31 | 648112 | 92086 | 59682 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 253.424 | 1.27985e+07 | 92086 | 1.17856e+06 | 98 | 4469.61 | 725664 | 92086 | 66823.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 196.844 | 1.6446e+07 | 92086 | 1.51444e+06 | 98 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 361.647 | 8.9671e+06 | 72532 | 650402 | 98 | 4652.57 | 697016 | 72532 | 50556 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 238.664 | 1.35888e+07 | 72532 | 985622 | 97 | 4081.31 | 794635 | 72532 | 57636.5 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 176.988 | 1.82954e+07 | 72532 | 1.32701e+06 | 97 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2577.57 | 1.25851e+06 | 2135663 | 2.68775e+06 | 100 | 3079.17 | 1.05349e+06 | 2135663 | 2.24991e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1992.63 | 1.62787e+06 | 2135663 | 3.47659e+06 | 98 | 2873.02 | 1.12904e+06 | 2135663 | 2.41124e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 560.175 | 5.79076e+06 | 2135663 | 1.23671e+07 | 207 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-CLANG/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2158.44 | 1.50286e+06 | 1637703 | 2.46125e+06 | 100 | 2741.67 | 1.18316e+06 | 1637703 | 1.93767e+06 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1863.36 | 1.74088e+06 | 1637703 | 2.85105e+06 | 98 | 2513.31 | 1.29069e+06 | 1637703 | 2.11376e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 438.575 | 7.39526e+06 | 1637703 | 1.21112e+07 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3599.94 | 901091 | 138774 | 125048 | 99 | 3849.61 | 842651 | 138774 | 116938 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2058.5 | 1.57559e+06 | 138774 | 218650 | 98 | 2833.29 | 1.14473e+06 | 138774 | 158858 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1075.85 | 3.01363e+06 | 138482 | 417333 | 95 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2677 | 1.21156e+06 | 69037 | 83642.5 | 97 | 2791.87 | 1.16171e+06 | 69037 | 80201 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1621.57 | 1.99941e+06 | 69037 | 138033 | 99 | 1943.2 | 1.66847e+06 | 69037 | 115186 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 551.986 | 5.87633e+06 | 68745 | 403968 | 96 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3639.58 | 890926 | 6661897 | 5.93526e+06 | 99 | 2129.22 | 1.5229e+06 | 6661897 | 1.01454e+07 | 100 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 3429.08 | 945817 | 6661897 | 6.30093e+06 | 99 | 2134.41 | 1.51952e+06 | 6661897 | 1.01229e+07 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1038.42 | 3.12268e+06 | 6661897 | 2.0803e+07 | 100 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1478.86 | 2.19353e+06 | 2090234 | 4.58499e+06 | 98 | 811.635 | 3.99677e+06 | 2090234 | 8.35419e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1235.72 | 2.62541e+06 | 2090234 | 5.48772e+06 | 99 | 837.065 | 3.87578e+06 | 2090234 | 8.10128e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 327.354 | 9.90526e+06 | 2090234 | 2.07043e+07 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3680.72 | 880966 | 1439562 | 1.26821e+06 | 156 | 4662.13 | 695518 | 1439562 | 1.00124e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2541.56 | 1.27629e+06 | 1439584 | 1.83733e+06 | 97 | 3154.37 | 1.02834e+06 | 1439584 | 1.48039e+06 | 207 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1361.88 | 2.38176e+06 | 1423437 | 3.39029e+06 | 100 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3086.2 | 1.05113e+06 | 500299 | 525880 | 97 | 3000.71 | 1.08103e+06 | 500299 | 540838 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2014.38 | 1.60972e+06 | 500299 | 805340 | 98 | 2195.3 | 1.47705e+06 | 500299 | 738969 | 160 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 519.629 | 6.24126e+06 | 492910 | 3.07638e+06 | 98 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 4128.64 | 785604 | 719107 | 564934 | 96 | 4814.91 | 673632 | 719107 | 484414 | 158 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2072.92 | 1.56465e+06 | 719139 | 1.1252e+06 | 169 | 3446.1 | 941177 | 719139 | 676837 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 1224.06 | 2.64845e+06 | 659630 | 1.747e+06 | 97 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3681.01 | 881115 | 477674 | 420886 | 96 | 4337.92 | 747684 | 477674 | 357149 | 168 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1880.37 | 1.72375e+06 | 477706 | 823445 | 159 | 3453.36 | 938831 | 477706 | 448485 | 154 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 813.657 | 3.98433e+06 | 425643 | 1.6959e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 998.172 | 3.25001e+06 | 69037 | 224371 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 944.253 | 3.43419e+06 | 69037 | 237086 | 188 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 554.91 | 5.84579e+06 | 69037 | 403576 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 3077.05 | 1.05409e+06 | 2135663 | 2.25117e+06 | 291 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2642.72 | 1.22695e+06 | 2135663 | 2.62036e+06 | 100 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 4737.63 | 684702 | 118385 | 81058.5 | 193 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 2132.12 | 1.5212e+06 | 118385 | 180087 | 98 | 