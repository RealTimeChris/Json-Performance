# Json-Performance
Here's a few benchmarks on a few common operating system/compiler platforms. Although feel free to try it out on more and let me know if you do/what scores you get! Cheers! (Click each of the badges below to be taken to the respective benchmarks). Also I will add some instructions for building below.
### The Libraries
- [Jsonifier](https://github.com/realtimechris/jsonifier)
- [Glaze](https://github.com/stephenberry/glaze)
- [SimdJson](https://github.com/simdjson/simdjson)
### By OS/Compiler:
----
#### Ubuntu Linux/CLANG:
----
[![CLANG/Linux](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=CLANG&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/main/Ubuntu-CLANG.md)
#### Microsoft Windows/MSVC:
----
[![MSVC/Windows](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=Microsoft&logoColor=green&label=MSVC&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/main/Windows-MSVC.md)
#### Ubuntu Linux/GNUCXX:
----
[![GNUCXX/Linux](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=GNUCXX&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/main/Ubuntu-GNUCXX.md)
#### MacOS/CLANG:
----
[![CLANG/MacOS](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=CLANG&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/main/MacOS-CLANG.md)
#### MacOS/GNUCXX:
----
[![GNUCXX/MacOS](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=GNUCXX&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/main/MacOS-GNUCXX.md)

### Pre-requisites:
---
1. CMake 3.28 or later.
2. A C++20 compliant compiler.
3. Python3 and Seaborn for generating the graphs.
### Build Instructions:
---
1. Clone the repo.
2. Cd into the repo's folder and enter `cmake -S . -B ./Build -DCMAKE_BUILD_TYPE=RELEASE_OR_DEBUG -DCMAKE_CXX_COMPILER=PATH_TO_COMPILER_EXECUTABLE` (NOTE: Optionally set a manual installation path by setting `-DCMAKE_INSTALL_PREFIX=CUSTOM_INSTALLATION_PATH`)
4. Then enter `cmake --build ./Build --config=RELEASE_OR_DEBUG`
5. Then enter `cmake --install ./Build`
6. Run the executable from wherever it was installed to!
