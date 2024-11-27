# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Dec 01, 2024)
#### Using the following commits:
----
| Jsonifier: [2da8dd0](https://github.com/RealTimeChris/Jsonifier/commit/2da8dd0)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [cab383e](https://github.com/simdjson/simdjson/commit/cab383e)  

 > 100 iterations on a ().


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1852.34 | 2.03441 | 5.2554e+07 | 2149858 | 1.12984e+08 | 2175.69 | 1.09 | 4.43165e+07 | 2149858 | 9.52741e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1388.06 | 3.43595 | 7.11503e+07 | 2149858 | 1.52963e+08 | 2010.62 | 2.032 | 4.84159e+07 | 2149858 | 1.04087e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 878.401 | 2.8591 | 1.11765e+08 | 2149858 | 2.40278e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1552.58 | 1.41846 | 6.23088e+07 | 1666038 | 1.03809e+08 | 1892.29 | 0.7966 | 5.08027e+07 | 1666038 | 8.46393e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1348.05 | 1.46111 | 7.17938e+07 | 1666038 | 1.19611e+08 | 1788.41 | 2.86 | 5.48953e+07 | 1666038 | 9.14576e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 705.246 | 3.12361 | 1.39586e+08 | 1666038 | 2.32556e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5503.22 | 1.50779 | 4.43588e+08 | 85273 | 3.7826e+07 | 3387.74 | 3.417 | 2.91467e+07 | 85273 | 2.48543e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3635.25 | 0.958765 | 6.67802e+08 | 85273 | 5.69455e+07 | 2989.8 | 3.634 | 3.31005e+07 | 85273 | 2.82258e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3512.16 | 2.1232 | 6.9943e+08 | 85273 | 5.96425e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5811.88 | 1.69535 | 4.09609e+08 | 67893 | 2.78096e+07 | 3191.43 | 2.709 | 3.07145e+07 | 67893 | 2.0853e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 3569.72 | 0.683445 | 6.60091e+08 | 67893 | 4.48156e+07 | 2772.45 | 3.397 | 3.56079e+07 | 67893 | 2.41752e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3132.62 | 2.20314 | 7.63884e+08 | 67893 | 5.18624e+07 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1837.62 | 1.69555 | 5.27924e+07 | 2149858 | 1.13496e+08 | 2164.8 | 0.7811 | 4.44005e+07 | 2149858 | 9.54547e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1387.1 | 1.08837 | 6.95097e+07 | 2149858 | 1.49436e+08 | 1999.89 | 4.02 | 4.96836e+07 | 2149858 | 1.06813e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 436.575 | 1.40188 | 2.21551e+08 | 2149858 | 4.76302e+08 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1539.67 | 1.80474 | 6.30788e+07 | 1666038 | 1.05092e+08 | 1886.72 | 1.167 | 5.11432e+07 | 1666038 | 8.52065e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1347.64 | 1.31668 | 7.17107e+07 | 1666038 | 1.19473e+08 | 1774.56 | 2.558 | 5.51523e+07 | 1666038 | 9.18858e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 346.415 | 1.88569 | 2.8059e+08 | 1666038 | 4.67473e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1664.54 | 1.30518 | 4.95222e+07 | 138774 | 6.8724e+06 | 2633.53 | 1.967 | 3.69394e+07 | 138774 | 5.12622e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1196.03 | 4.41086 | 7.11602e+07 | 138774 | 9.87518e+06 | 1975.45 | 3.878 | 5.0224e+07 | 138774 | 6.96978e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 990.679 | 2.81636 | 8.46793e+07 | 138482 | 1.17266e+07 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1451.99 | 0.985926 | 6.63347e+07 | 69037 | 4.57955e+06 | 1990.23 | 1.771 | 4.87818e+07 | 69037 | 3.36775e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1089.81 | 4.6985 | 9.18224e+07 | 69037 | 6.33914e+06 | 1586.21 | 1.812 | 6.12322e+07 | 69037 | 4.22729e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 603.561 | 2.55083 | 1.62833e+08 | 68745 | 1.11939e+07 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 908.479 | 1.66824 | 3.60727e+07 | 6661897 | 2.40313e+08 | 1486.43 | 0.855 | 6.47119e+07 | 6661897 | 4.31104e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 852.408 | 1.65562 | 3.84406e+07 | 6661897 | 2.56087e+08 | 1522.11 | 2.51 | 6.4268e+07 | 6661897 | 4.28147e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 306.268 | 1.76304 | 1.07105e+08 | 6661897 | 7.13525e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1037.25 | 3.32127 | 9.51011e+07 | 2090234 | 1.98784e+08 | 575.831 | 0.6728 | 1.66739e+08 | 2090234 | 3.48523e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 941.091 | 1.72899 | 1.0312e+08 | 2090234 | 2.15545e+08 | 580.498 | 1.465 | 1.66729e+08 | 2090234 | 3.48502e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 287.344 | 2.42444 | 3.4014e+08 | 2090234 | 7.10972e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2697.16 | 1.33978 | 4.29996e+07 | 1439562 | 6.19006e+07 | 3257.13 | 2.357 | 2.99865e+07 | 1439562 | 4.31674e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2174.43 | 1.44603 | 5.33933e+07 | 1439584 | 7.68642e+07 | 2348.5 | 2.805 | 4.17799e+07 | 1439584 | 6.01456e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1442.11 | 1.24707 | 8.12562e+07 | 1423437 | 1.15663e+08 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1994.09 | 2.5118 | 4.90572e+07 | 500299 | 2.45433e+07 | 2359.45 | 3.615 | 4.19353e+07 | 500299 | 2.09802e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1502.07 | 2.52247 | 6.51338e+07 | 500299 | 3.25864e+07 | 2032.31 | 2.948 | 4.83509e+07 | 500299 | 2.41899e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 474.318 | 1.11876 | 2.06385e+08 | 492910 | 1.01729e+08 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2015.4 | 2.75667 | 4.27336e+07 | 719107 | 3.073e+07 | 3260.03 | 1.372 | 2.96604e+07 | 719107 | 2.1329e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1163.65 | 2.65399 | 7.39312e+07 | 719139 | 5.31668e+07 | 2544.86 | 3.308 | 3.87567e+07 | 719139 | 2.78715e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 978.039 | 2.42173 | 9.56695e+07 | 659630 | 6.31065e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1972.15 | 3.33826 | 4.88994e+07 | 477674 | 2.3358e+07 | 3056.96 | 2.117 | 3.18714e+07 | 477674 | 1.52241e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1152.15 | 2.38619 | 8.28795e+07 | 477706 | 3.9592e+07 | 2688.62 | 3.408 | 3.67222e+07 | 477706 | 1.75424e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 748.045 | 2.34678 | 1.43209e+08 | 425643 | 6.09558e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 830.494 | 1.303 | 1.99515e+08 | 69037 | 1.37739e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 738.957 | 4.671 | 1.35381e+08 | 69037 | 9.34629e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 685.678 | 2.653 | 1.42875e+08 | 69037 | 9.86369e+06 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2150.36 | 1.017 | 4.48053e+07 | 2149858 | 9.6325e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2015.11 | 1.907 | 4.82463e+07 | 2149858 | 1.03723e+08 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/Ubuntu-GNUCXX/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3500.8 | 4.31468 | 2.847e+07 | 118385 | 3.37042e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1637.22 | 1.12053 | 5.89099e+07 | 118385 | 6.97405e+06 | 