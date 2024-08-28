# Json-Performance
Here's a few benchmarks on a few common operating system/compiler platforms. Although feel free to try it out on more and let me know if you do/what scores you get! Cheers! (Click each of the badges below to be taken to the respective benchmarks). Also I will add some instructions for building below.
### By OS/Compiler:
----
#### Ubuntu Linux/CLANG:
----
[![CLANG/Linux](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=CLANG&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/benchmarking/Ubuntu-CLANG.md)
#### Microsoft Windows/MSVC:
----
[![MSVC/Windows](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=Microsoft&logoColor=green&label=MSVC&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/benchmarking/Windows-MSVC.md)
#### Ubuntu Linux/GNUCXX:
----
[![GCC/Linux](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=linux&logoColor=green&label=GCC&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/benchmarking/Ubuntu-GCC.md)
#### MacOS/CLANG:
----
[![CLANG/MacOS](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=CLANG&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/benchmarking/MacOS-CLANG.md)
#### MacOS/GCC:
----
[![GCC/MacOS](https://img.shields.io/github/actions/workflow/status/RealTimeChris/Json-Performance/Benchmark.yml?style=plastic&logo=apple&logoColor=green&label=GCC&labelColor=pewter&color=blue&branch=benchmarking)](https://github.com/RealTimeChris/Json-Performance/blob/benchmarking/MacOS-GCC.md)

### Pre-requisites:
---
1. CMake 3.28 or later.
2. A C++20 compliant compiler.
### Build Instructions:
---
1. Clone the repo.
2. Cd into the repo's folder and enter `cmake -S . -B ./Build -DCMAKE_BUILD_TYPE=RELEASE_OR_DEBUG -DCMAKE_CXX_COMPILER=PATH_TO_COMPILER_EXECUTABLE` (NOTE: Optionally set a manual installation path by setting `-DCMAKE_INSTALL_PREFIX=CUSTOM_INSTALLATION_PATH`)
4. Then enter `cmake --build ./Build --config=RELEASE_OR_DEBUG`
5. Then enter `cmake --install ./Build`
6. Run the executable from wherever it was installed to!
