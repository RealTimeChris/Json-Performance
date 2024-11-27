# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Darwin 23.6.0 using the AppleClang 15.0.0.15000309 compiler).  

Latest Results: (Dec 01, 2024)
#### Using the following commits:
----
| Jsonifier: [2da8dd0](https://github.com/RealTimeChris/Jsonifier/commit/2da8dd0)  
| Glaze: [87f457b](https://github.com/stephenberry/glaze/commit/87f457b)  
| Simdjson: [cab383e](https://github.com/simdjson/simdjson/commit/cab383e)  

 > 100 iterations on a (Apple M1 (Virtual)).


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2043.12 | 4.42707 | 2065961 | 1.009e+08 | 2887.35 | 1.524 | 2065961 | 6.92935e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1787.15 | 4.71889 | 2065961 | 1.15706e+08 | 2749.19 | 2.481 | 2065961 | 7.34897e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 943.966 | 1.10944 | 2065961 | 2.11062e+08 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1633.35 | 4.33873 | 1592586 | 9.7205e+07 | 2365.59 | 2.395 | 1592586 | 6.57792e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1601.56 | 3.86138 | 1592586 | 9.86423e+07 | 2547.98 | 0.7534 | 1592586 | 6.00609e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 760.608 | 2.48874 | 1592586 | 2.0478e+08 | 

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5428.94 | 1.17963 | 95408 | 3.67249e+07 | 3745.76 | 2.994 | 95408 | 2.50408e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4561.65 | 0.904466 | 95408 | 4.35859e+07 | 3206.63 | 1.282 | 95408 | 2.87434e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3632.92 | 2.3462 | 95408 | 5.55363e+07 | 

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 5336.96 | 1.4994 | 72399 | 2.88915e+07 | 3889.86 | 0.9945 | 72399 | 1.79283e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 4062.8 | 0.710002 | 72399 | 3.76506e+07 | 3236.39 | 2.244 | 72399 | 2.18238e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 3312.86 | 3.35152 | 72399 | 4.74357e+07 | 

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2051.28 | 2.75153 | 2065961 | 9.87676e+07 | 2870.35 | 1.662 | 2065961 | 6.98014e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1784.38 | 4.23741 | 2065961 | 1.15303e+08 | 2738.84 | 2.496 | 2065961 | 7.37789e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 504.38 | 1.61986 | 2065961 | 3.97061e+08 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/MacOS-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1622.59 | 4.57904 | 1592586 | 9.8096e+07 | 2326.78 | 2.668 | 1592586 | 6.7064e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1614.82 | 3.43247 | 1592586 | 9.73973e+07 | 2608.52 | 0.8564 | 1592586 | 5.8728e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 401.912 | 2.14852 | 1592586 | 3.86193e+08 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2544.24 | 1.6193 | 138774 | 4.51054e+06 | 3950.6 | 4.227 | 138774 | 3.49787e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1541.31 | 1.89513 | 138774 | 7.4665e+06 | 3368.25 | 0.7212 | 138774 | 3.95774e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1390.27 | 3.28838 | 138482 | 8.39692e+06 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1887.85 | 1.59416 | 69037 | 3.544e+06 | 4553.8 | 4.581 | 69037 | 1.51521e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1205.29 | 4.45852 | 69037 | 5.71741e+06 | 2942.52 | 1.762 | 69037 | 2.27763e+06 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 840.049 | 2.81432 | 68745 | 8.06446e+06 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1156.87 | 3.6239 | 6661897 | 1.92544e+08 | 2328.81 | 1.32 | 6661897 | 2.76463e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1116.27 | 4.88278 | 6661897 | 2.02189e+08 | 2258.81 | 1.966 | 6661897 | 2.86906e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 408.817 | 2.47295 | 6661897 | 5.38432e+08 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1365.54 | 2.41837 | 2090234 | 1.49597e+08 | 936.089 | 0.6821 | 2090234 | 2.14413e+08 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1276.87 | 4.9721 | 2090234 | 1.64285e+08 | 954.981 | 1.424 | 2090234 | 2.11754e+08 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 395.477 | 3.15882 | 2090234 | 5.20491e+08 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3952.86 | 3.02763 | 1439562 | 4.29718e+07 | 4512.94 | 1.021 | 1439562 | 3.07347e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2553.95 | 1.12 | 1439584 | 6.52263e+07 | 3997.26 | 2.748 | 1439584 | 3.53164e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 2123.01 | 3.13893 | 1423437 | 8.01018e+07 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 2608.41 | 3.60531 | 500299 | 1.89758e+07 | 3392.87 | 2.29 | 500299 | 1.43921e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 1417.72 | 4.14681 | 500299 | 3.511e+07 | 2279.7 | 1.201 | 500299 | 2.11837e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 780.834 | 1.52445 | 492910 | 6.20501e+07 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3409.82 | 0.850928 | 719139 | 1.78141e+07 | 5055.2 | 1.618 | 719139 | 1.37898e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2076.16 | 3.13278 | 719139 | 2.99465e+07 | 4250.99 | 2.948 | 719139 | 1.66234e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1406.05 | 3.99042 | 659630 | 4.46137e+07 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 3102.08 | 0.712659 | 477706 | 1.44571e+07 | 6044.13 | 1.921 | 477706 | 7.68516e+06 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2111.99 | 2.55903 | 477706 | 2.1637e+07 | 4536.89 | 2.572 | 477706 | 1.03067e+07 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 1085.71 | 2.50237 | 425643 | 4.20651e+07 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |   
| [simdjson](https://github.com/simdjson/simdjson/commit/cab383e) | 939.54 | 2.305 | 69037 | 1.23002e+07 | 
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 864.878 | 1.934 | 69037 | 7.76263e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 600.812 | 3.459 | 69037 | 1.13509e+07 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2267.59 | 1.19 | 2065961 | 8.79337e+07 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1720.43 | 3.998 | 2065961 | 1.19289e+08 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob//Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob//Graphs/MacOS-GNUCXX/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |   
| [glaze](https://github.com/stephenberry/glaze/commit/87f457b) | 2108.68 | 2.80146 | 118385 | 5.50842e+06 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/2da8dd0) | 1751.51 | 3.77348 | 118385 | 6.69867e+06 | 