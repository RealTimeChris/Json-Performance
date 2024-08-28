# Json-Performance
Performance profiling of JSON libraries (Compiled and run on Linux 6.5.0-1025-azure using the GNU 12.3.0 compiler).  

Latest Results: (Oct 20, 2024)
#### Using the following commits:
----
| Jsonifier: [74b35c0](https://github.com/RealTimeChris/Jsonifier/commit/74b35c0)  
| Glaze: [df960ee](https://github.com/stephenberry/glaze/commit/df960ee)  
| Simdjson: [3c0d032](https://github.com/simdjson/simdjson/commit/3c0d032)  

 > At least 30 iterations on a (AMD EPYC 7763 64-Core Processor), until coefficient of variance is at or below 1%.


### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1678.98 | 1.4565e+06 | 925997 | 1.34871e+06 | 99 | 1646.82 | 1.48494e+06 | 925997 | 1.37505e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1145.22 | 2.13533e+06 | 925871 | 1.97704e+06 | 99 | 1648.15 | 1.48374e+06 | 925871 | 1.37375e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 755.832 | 3.23542e+06 | 925871 | 2.99558e+06 | 285 | 

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1258.11 | 1.94373e+06 | 620255 | 1.20561e+06 | 98 | 1312.58 | 1.86307e+06 | 620255 | 1.15558e+06 | 161 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 939.824 | 2.60201e+06 | 620129 | 1.61358e+06 | 96 | 1324.76 | 1.84595e+06 | 620129 | 1.14473e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 523.728 | 4.66928e+06 | 620129 | 2.89556e+06 | 159 | 

### ABC Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1681.18 | 1.45459e+06 | 925997 | 1.34695e+06 | 99 | 1637.3 | 1.49358e+06 | 925997 | 1.38305e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1201.54 | 2.14101e+06 | 925871 | 1.9823e+06 | 98 | 1727.25 | 1.48936e+06 | 925871 | 1.37896e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 337.828 | 7.23868e+06 | 925871 | 6.70208e+06 | 97 | 

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/Ubuntu-GNUCXX/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1252.31 | 1.95274e+06 | 620255 | 1.21119e+06 | 159 | 1312.05 | 1.86382e+06 | 620255 | 1.15604e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 934.468 | 2.61692e+06 | 620129 | 1.62283e+06 | 98 | 1309.18 | 1.86791e+06 | 620129 | 1.15835e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 229.135 | 1.06725e+07 | 620129 | 6.61831e+06 | 98 | 

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1926.5 | 1.26937e+06 | 138774 | 176155 | 97 | 2385.73 | 1.02503e+06 | 138774 | 142247 | 161 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1630.26 | 1.50002e+06 | 138774 | 208164 | 98 | 2071.1 | 1.18074e+06 | 138774 | 163856 | 157 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 428.599 | 5.70565e+06 | 47820 | 272844 | 97 | 

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1596.92 | 1.65783e+06 | 69037 | 114452 | 99 | 1895.33 | 1.39681e+06 | 69037 | 96431.5 | 170 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1199.34 | 2.03898e+06 | 69037 | 140765 | 98 | 1645.17 | 1.48643e+06 | 69037 | 102618 | 99 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 217.202 | 1.12588e+07 | 23197 | 261170 | 98 | 

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2624.64 | 931722 | 6661897 | 6.20704e+06 | 288 | 1565.42 | 1.56215e+06 | 6661897 | 1.04069e+07 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2400.91 | 1.01855e+06 | 6661897 | 6.78545e+06 | 97 | 1597.7 | 1.53059e+06 | 6661897 | 1.01966e+07 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1189.85 | 2.72633e+06 | 6661897 | 1.81625e+07 | 98 | 

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 882.577 | 2.77079e+06 | 2090234 | 5.79159e+06 | 98 | 572.797 | 4.26928e+06 | 2090234 | 8.92379e+06 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 868.491 | 2.81573e+06 | 2090234 | 5.88552e+06 | 97 | 576.501 | 4.24185e+06 | 2090234 | 8.86646e+06 | 97 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 342.453 | 8.57293e+06 | 2090234 | 1.79194e+07 | 99 | 

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2774.69 | 881336 | 1439556 | 1.26873e+06 | 98 | 2883.78 | 847995 | 1439556 | 1.22074e+06 | 98 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2499.15 | 978505 | 1439584 | 1.40864e+06 | 98 | 2392.02 | 1.02233e+06 | 1439584 | 1.47173e+06 | 98 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1414.62 | 1.8329e+06 | 1423437 | 2.60902e+06 | 98 | 

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1622.9 | 1.50683e+06 | 500299 | 753866 | 96 | 2108.1 | 1.16002e+06 | 500299 | 580356 | 161 | 
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1559.6 | 1.56799e+06 | 500293 | 784454 | 97 | 2088.24 | 1.17105e+06 | 500293 | 585868 | 167 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 491.971 | 4.97068e+06 | 492910 | 2.4501e+06 | 99 | 

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2370.01 | 1.03182e+06 | 719230 | 742117 | 97 | 2559.69 | 955364 | 719230 | 687126 | 156 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1907.39 | 1.38315e+06 | 719139 | 994676 | 99 | 2864.68 | 920940 | 719139 | 662284 | 165 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 1035.16 | 2.36238e+06 | 651630 | 1.5394e+06 | 161 | 

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- | ------------ | ------------------| -------------------- | ----------------| --------------------- |  
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 2132.38 | 1.14681e+06 | 477797 | 547942 | 97 | 2345.59 | 1.04256e+06 | 477797 | 498134 | 178 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1565.23 | 1.56235e+06 | 477706 | 746344 | 97 | 2814.23 | 868952 | 477706 | 415104 | 165 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 682.383 | 3.58367e+06 | 416843 | 1.49383e+06 | 158 | 

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 789.054 | 3.09919e+06 | 69037 | 213959 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 717.16 | 3.40988e+06 | 69037 | 235408 | 216 | 
| [simdjson](https://github.com/simdjson/simdjson/commit/3c0d032) | 476.957 | 5.12716e+06 | 69037 | 353964 | 96 | 

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Write (MB/S) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) | Write Iteration Count |
| ------- | ------------ | ------------------| -------------------- | --------------- | --------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 1945.52 | 1.33578e+06 | 925997 | 1.23693e+06 | 97 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 1593.34 | 1.53479e+06 | 925997 | 1.42121e+06 | 99 | 

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/main/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/main/Graphs/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>


| Library | Read (MB/S) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Read Iteration Count |
| ------- | ----------- | -----------------| ------------------- | -------------- | -------------------- |   
| [jsonifier](https://github.com/realtimechris/jsonifier/commit/74b35c0) | 4504.72 | 661317 | 118385 | 78290 | 99 | 
| [glaze](https://github.com/stephenberry/glaze/commit/df960ee) | 2009.3 | 1.29293e+06 | 118385 | 153064 | 99 | 