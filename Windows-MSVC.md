# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Windows 10.0.20348 using the MSVC 19.42.34433.0 compiler).  

Latest Results: (Nov 24, 2024)
#### Using the following commits:
----
| Jsonifier: [eb8e1f4](https://github.com/RealTimeChris/Jsonifier/commit/eb8e1f4)  
| Glaze: [8f35df4](https://github.com/stephenberry/glaze/commit/8f35df4)  
| Simdjson: [9b31492](https://github.com/simdjson/simdjson/commit/9b31492)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1729.8 | 1.41369e+06 | 2197175 | 3.10612e+06 | 180 | 1961.36 | 1.2468e+06 | 2197175 | 2.73943e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1262.32 | 1.93722e+06 | 2197175 | 4.25642e+06 | 98 | 1782.66 | 1.37179e+06 | 2197175 | 3.01406e+06 | 173 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 389.861 | 6.27248e+06 | 2197175 | 1.37817e+07 | 98 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1454.43 | 1.68134e+06 | 1699227 | 2.85698e+06 | 193 | 1735.21 | 1.40929e+06 | 1699227 | 2.3947e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1094.56 | 2.23415e+06 | 1699227 | 3.79632e+06 | 167 | 1553.76 | 1.57388e+06 | 1699227 | 2.67437e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 306.496 | 7.97858e+06 | 1699227 | 1.35574e+07 | 181 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 216.881 | 1.12754e+07 | 80138 | 903584 | 97 | 2990.2 | 817808 | 80138 | 65537.5 | 157 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 147.191 | 1.66137e+07 | 80138 | 1.33139e+06 | 97 | 2628.6 | 930314 | 80138 | 74553.5 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 85.1219 | 2.87283e+07 | 80138 | 2.30223e+06 | 99 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 229.604 | 1.06505e+07 | 63483 | 676126 | 96 | 2781.58 | 879149 | 63483 | 55811 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 138.196 | 1.76951e+07 | 63483 | 1.12334e+06 | 97 | 2425.87 | 1.00805e+06 | 63483 | 63994 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 74.6639 | 3.27521e+07 | 63483 | 2.0792e+06 | 194 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1687.37 | 1.44924e+06 | 2197175 | 3.18423e+06 | 98 | 1957.4 | 1.24932e+06 | 2197175 | 2.74497e+06 | 182 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1257.81 | 1.94417e+06 | 2197175 | 4.27168e+06 | 162 | 1782.62 | 1.37181e+06 | 2197175 | 3.0141e+06 | 160 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 115.015 | 2.12616e+07 | 2197175 | 4.67154e+07 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Windows-MSVC/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1421.75 | 1.71999e+06 | 1699227 | 2.92265e+06 | 193 | 1724.91 | 1.41772e+06 | 1699227 | 2.40902e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1092.63 | 2.23809e+06 | 1699227 | 3.80302e+06 | 98 | 1543.94 | 1.58388e+06 | 1699227 | 2.69137e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 89.7437 | 2.72487e+07 | 1699227 | 4.63018e+07 | 99 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1718.63 | 1.42287e+06 | 138774 | 197458 | 99 | 2237.53 | 1.09291e+06 | 138774 | 151668 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1218.99 | 2.00609e+06 | 138774 | 278394 | 97 | 1966.98 | 1.24324e+06 | 138774 | 172529 | 166 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 370.34 | 6.60313e+06 | 138482 | 914414 | 203 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1180.83 | 2.07092e+06 | 69037 | 142970 | 97 | 1876.84 | 1.30295e+06 | 69037 | 89951.5 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 902.049 | 2.71094e+06 | 69037 | 187156 | 96 | 1335.3 | 1.83137e+06 | 69037 | 126432 | 165 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 186.776 | 1.30927e+07 | 68745 | 900057 | 97 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2313.97 | 1.05679e+06 | 6661897 | 7.04026e+06 | 97 | 1258.07 | 1.9438e+06 | 6661897 | 1.29494e+07 | 187 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1124.81 | 2.17405e+06 | 6661897 | 1.44833e+07 | 98 | 1111 | 2.20109e+06 | 6661897 | 1.46634e+07 | 157 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 504.131 | 4.85072e+06 | 6661897 | 3.2315e+07 | 207 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 747.366 | 3.27202e+06 | 2090234 | 6.8393e+06 | 98 | 468.197 | 5.22305e+06 | 2090234 | 1.09174e+07 | 96 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 358.84 | 6.81474e+06 | 2090234 | 1.42444e+07 | 98 | 434.607 | 5.62674e+06 | 2090234 | 1.17612e+07 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 158.864 | 1.53931e+07 | 2090234 | 3.21751e+07 | 98 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2251.44 | 1.08615e+06 | 1439562 | 1.56358e+06 | 98 | 2673.78 | 914596 | 1439562 | 1.31662e+06 | 275 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1677.67 | 1.45762e+06 | 1439584 | 2.09836e+06 | 166 | 2375.47 | 1.02945e+06 | 1439584 | 1.48198e+06 | 96 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 585.205 | 4.1787e+06 | 1423437 | 5.94812e+06 | 97 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2025.1 | 1.20754e+06 | 500299 | 604133 | 99 | 1773.28 | 1.37904e+06 | 500299 | 689932 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1278.29 | 1.91302e+06 | 500299 | 957080 | 98 | 1327.74 | 1.84179e+06 | 500299 | 921445 | 216 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 220.317 | 1.10995e+07 | 492910 | 5.47105e+06 | 97 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1896.47 | 1.28945e+06 | 719107 | 927252 | 98 | 2718.85 | 899432 | 719107 | 646788 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1116.9 | 2.18945e+06 | 719139 | 1.57452e+06 | 98 | 2451.87 | 997373 | 719139 | 717250 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 323.418 | 7.5611e+06 | 659630 | 4.98753e+06 | 96 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1667.05 | 1.4669e+06 | 477674 | 700700 | 298 | 2772.95 | 881883 | 477674 | 421252 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 944.588 | 2.58885e+06 | 477706 | 1.23671e+06 | 205 | 2220.61 | 1.10123e+06 | 477706 | 526064 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 212.943 | 1.14838e+07 | 425643 | 4.88802e+06 | 98 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 552.939 | 4.42253e+06 | 69037 | 305318 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 544.979 | 4.48713e+06 | 69037 | 309778 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/9b31492) | 297.373 | 8.22333e+06 | 69037 | 567714 | 99 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 1692.26 | 1.44505e+06 | 2197175 | 3.17503e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1655.58 | 1.47706e+06 | 2197175 | 3.24537e+06 | 99 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/eb8e1f4) | 2363.51 | 1.03465e+06 | 123050 | 127314 | 167 | 
| [glaze](https://github.com/stephenberry/glaze/commit/8f35df4) | 1315.41 | 1.85905e+06 | 123050 | 228756 | 99 | 