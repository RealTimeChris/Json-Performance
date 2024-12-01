/*
	MIT License

	Copyright (c) 2024 RealTimeChris

	Permission is hereby granted, free of charge, to any person obtaining a copy of this
	software and associated documentation files (the "Software"), to deal in the Software
	without restriction, including without limitation the rights to use, copy, modify, merge,
	publish, distribute, sublicense, and/or sell copies of the Software, and to permit
	persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or
	substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
	PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
	FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
	OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
	DEALINGS IN THE SOFTWARE.
*/
/// https://github.com/RealTimeChris/jsonifier
#include "Conformance.hpp"
#include "Jsonifier.hpp"
#include "Simdjson.hpp"
#include "String.hpp"
#include "Float.hpp"
#include "Glaze.hpp"
#include "Uint.hpp"
#include "Int.hpp"
#include <unordered_set>
#include "RoundTrip.hpp"
#include <unordered_map>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#if !defined(GIT_BRANCH)
static constexpr jsonifier_internal::string_literal gitBranch{ "main" };
#else
static constexpr jsonifier_internal::string_literal gitBranch{ GIT_BRANCH };
#endif

constexpr jsonifier_internal::string_literal jsonifierLibraryName{ "jsonifier" };
constexpr jsonifier_internal::string_literal jsonifierCommitUrlBase{ "https://github.com/realtimechris/jsonifier/commit/" };
constexpr jsonifier_internal::string_literal simdjsonLibraryName{ "simdjson" };
constexpr jsonifier_internal::string_literal simdjsonCommitUrlBase{ "https://github.com/simdjson/simdjson/commit/" };
constexpr jsonifier_internal::string_literal glazeLibraryName{ "glaze" };
constexpr jsonifier_internal::string_literal glazeCommitUrlBase{ "https://github.com/stephenberry/glaze/commit/" };
constexpr jsonifier_internal::string_literal jsonifierCommitUrl{ jsonifierCommitUrlBase + JSONIFIER_COMMIT };
constexpr jsonifier_internal::string_literal simdjsonCommitUrl{ simdjsonCommitUrlBase + SIMDJSON_COMMIT };
constexpr jsonifier_internal::string_literal glazeCommitUrl{ glazeCommitUrlBase + GLAZE_COMMIT };

constexpr auto getCurrentOperatingSystem() {
	constexpr jsonifier_internal::string_literal osName{ OPERATING_SYSTEM_NAME };
	constexpr auto osNameNew = jsonifier_internal::toLower(osName);
	if constexpr (osNameNew.view().operator std::string_view().contains("linux")) {
		return jsonifier_internal::string_literal{ "Ubuntu" };
	} else if constexpr (osNameNew.view().operator std::string_view().contains("windows")) {
		return jsonifier_internal::string_literal{ "Windows" };
	} else if constexpr (osNameNew.view().operator std::string_view().contains("darwin")) {
		return jsonifier_internal::string_literal{ "MacOS" };
	} else {
		return jsonifier_internal::string_literal{ "" };
	}
}

constexpr auto getCurrentCompilerId() {
	constexpr jsonifier_internal::string_literal compilerId{ COMPILER_ID };
	constexpr auto osCompilerIdNew = jsonifier_internal::toLower(compilerId);
	if constexpr (osCompilerIdNew.view().operator std::string_view().contains("gnu") || osCompilerIdNew.view().operator std::string_view().contains("gcc") ||
		osCompilerIdNew.view().operator std::string_view().contains("g++") || osCompilerIdNew.view().operator std::string_view().contains("apple")) {
		return jsonifier_internal::string_literal{ "GNUCXX" };
	} else if constexpr (osCompilerIdNew.view().operator std::string_view().contains("clang")) {
		return jsonifier_internal::string_literal{ "CLANG" };
	} else if constexpr (osCompilerIdNew.view().operator std::string_view().contains("msvc")) {
		return jsonifier_internal::string_literal{ "MSVC" };
	} else {
		return jsonifier_internal::string_literal{ "" };
	}
}

constexpr auto getCurrentPathImpl() {
	return getCurrentOperatingSystem() + "-" + getCurrentCompilerId();
}

enum class test_type {
	parse_and_serialize = 0,
	minify				= 1,
	prettify			= 2,
	validate			= 3,
};

enum class json_library {
	jsonifier = 0,
	glaze	  = 1,
	simdjson  = 2,
};

static constexpr jsonifier_internal::string_literal basePath{ jsonifier_internal::string_literal{ JSON_PATH } + jsonifier_internal::string_literal{ "/" } + getCurrentPathImpl() };

static std::string jsonPath{ JSON_PATH };

template<json_library lib, test_type type, typename test_data_type, bool minified, size_t iterations, const jsonifier_internal::string_literal testName> struct json_test_helper {};

template<json_library lib, test_type type, typename test_data_type, bool minified, size_t iterations, const jsonifier_internal::string_literal testName> struct json_test_helper;

template<typename test_data_type, bool minified, size_t iterations, const jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::jsonifier, test_type::parse_and_serialize, test_data_type, minified, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		static constexpr bool partialRead{ std::is_same_v<test_data_type, partial_test<test_struct>> };
		static constexpr bool knownOrder{ !std::is_same_v<test_data_type, abc_test<test_struct>> };
		results_data r{ jsonifierLibraryName, testName, jsonifierCommitUrl, iterations };
		jsonifier::jsonifier_core parser{};
		test_data_type testData{};
		if constexpr (partialRead) {
			parser.parseJson(testData, newBuffer);
		}
		auto readResult = bnch_swt::benchmark_stage<testName + "-Read">::template runBenchmark<testName, jsonifierLibraryName, "teal">([&]() mutable {
			parser.parseJson<jsonifier::parse_options{ .partialRead = partialRead, .knownOrder = knownOrder, .minified = minified }>(testData, newBuffer);
			bnch_swt::doNotOptimizeAway(testData);
			return newBuffer.size();
		});
		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		std::string_view newerBuffer{};
		auto writeResult = bnch_swt::benchmark_stage<testName + "-Write">::template runBenchmark<testName, jsonifierLibraryName, "steelblue">([&]() mutable {
			newerBuffer = parser.serializeJson<jsonifier::serialize_options{ .prettify = !minified }>(testData);
			bnch_swt::doNotOptimizeAway(newerBuffer);
			return newerBuffer.size();
		});

		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}

		auto readSize	 = newerBuffer.size();
		auto writtenSize = newerBuffer.size();
		r.readResult	 = result<result_type::read>{ "teal", readSize, readResult };
		r.writeResult	 = result<result_type::write>{ "steelblue", writtenSize, writeResult };
		bnch_swt::file_loader::saveFile(static_cast<std::string>(newerBuffer), basePath + "/" + testName + "-jsonifier.json");
		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::jsonifier, test_type::prettify, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		results_data r{ jsonifierLibraryName, testName, jsonifierCommitUrl, iterations };
		jsonifier::jsonifier_core parser{};
		std::string newerBuffer{};
		auto writeResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, jsonifierLibraryName, "steelblue">([&]() {
			parser.prettifyJson(newBuffer, newerBuffer);
			bnch_swt::doNotOptimizeAway(newerBuffer);
			return newerBuffer.size();
		});

		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-jsonifier.json");
		r.writeResult = result<result_type::write>{ "steelblue", newerBuffer.size(), writeResult };
		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::jsonifier, test_type::minify, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		std::string newerBuffer{};
		results_data r{ jsonifierLibraryName, testName, jsonifierCommitUrl, iterations };
		jsonifier::jsonifier_core parser{};
		auto writeResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, jsonifierLibraryName, "steelblue">([&]() {
			parser.minifyJson(newBuffer, newerBuffer);
			bnch_swt::doNotOptimizeAway(newerBuffer);
			return newerBuffer.size();
		});
		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-jsonifier.json");
		r.writeResult = result<result_type::write>{ "steelblue", newerBuffer.size(), writeResult };
		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::jsonifier, test_type::validate, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		results_data r{ jsonifierLibraryName, testName, jsonifierCommitUrl, iterations };
		jsonifier::jsonifier_core parser{};
		auto readResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, jsonifierLibraryName, "steelblue">([&]() {
			bnch_swt::doNotOptimizeAway(parser.validateJson(newBuffer));
			return newBuffer.size();
		});

		for (auto& value: parser.getErrors()) {
			std::cout << "Jsonifier Error: " << value << std::endl;
		}
		bnch_swt::file_loader::saveFile(newBuffer, basePath + "/" + testName + "-jsonifier.json");
		r.readResult = result<result_type::read>{ "teal", newBuffer.size(), readResult };
		return r;
	}
};

template<typename test_data_type, bool minified, size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::glaze, test_type::parse_and_serialize, test_data_type, minified, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		static constexpr bool partialRead{ std::is_same_v<test_data_type, partial_test<test_struct>> };
		results_data r{ glazeLibraryName, testName, glazeCommitUrl, iterations };
		test_data_type testData{};
		if constexpr (partialRead) {
			if (auto error =
					glz::read<glz::opts{ .error_on_unknown_keys = !partialRead, .skip_null_members = false, .prettify = !minified, .minified = minified }>(testData, newBuffer);
				error) {
				std::cout << "Glaze Error: " << glz::format_error(error, newBuffer) << std::endl;
			}
		}
		auto readResult = bnch_swt::benchmark_stage<testName + "-Read">::template runBenchmark<testName, glazeLibraryName, "dodgerblue">([&]() {
			if (auto error = glz::read<glz::opts{ .error_on_unknown_keys = !partialRead,
					.skip_null_members									 = false,
					.prettify											 = !minified,
					.minified											 = minified,
					.partial_read										 = partialRead,
					.partial_read_nested								 = partialRead }>(testData, newBuffer);
				error) {
				std::cout << "Glaze Error: " << glz::format_error(error, newBuffer) << std::endl;
			}
			bnch_swt::doNotOptimizeAway(testData);
			return newBuffer.size();
		});
		std::string newerBuffer{};
		auto writeResult = bnch_swt::benchmark_stage<testName + "-Write">::template runBenchmark<testName, glazeLibraryName, "steelblue">([&]() {
			auto newResult = glz::write<glz::opts{ .skip_null_members = false, .prettify = !minified, .minified = minified }>(testData, newerBuffer);
			bnch_swt::doNotOptimizeAway(newResult);
			return newerBuffer.size();
		});

		auto readSize	 = newerBuffer.size();
		auto writtenSize = newerBuffer.size();
		r.readResult	 = result<result_type::read>{ "dodgerblue", readSize, readResult };
		r.writeResult	 = result<result_type::write>{ "skyblue", writtenSize, writeResult };
		bnch_swt::file_loader::saveFile(static_cast<std::string>(newerBuffer), basePath + "/" + testName + "-glaze.json");

		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::glaze, test_type::prettify, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };

		results_data r{ glazeLibraryName, testName, glazeCommitUrl, iterations };
		std::string newerBuffer{};

		auto writeResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, glazeLibraryName, "steelblue">([&]() {
			glz::prettify_json(newBuffer, newerBuffer);
			bnch_swt::doNotOptimizeAway(newerBuffer);
			return newerBuffer.size();
		});

		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-glaze.json");
		r.writeResult = result<result_type::write>{ "skyblue", newerBuffer.size(), writeResult };

		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::glaze, test_type::minify, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };

		std::string newestBuffer{ newBuffer };
		std::string newerBuffer{};

		results_data r{ glazeLibraryName, testName, glazeCommitUrl, iterations };
		auto writeResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, glazeLibraryName, "steelblue">([&]() {
			glz::minify_json(newestBuffer, newerBuffer);
			bnch_swt::doNotOptimizeAway(newerBuffer);
			return newerBuffer.size();
		});

		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-glaze.json");
		r.writeResult = result<result_type::write>{ "skyblue", newerBuffer.size(), writeResult };

		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::glaze, test_type::validate, std::string, false, iterations, testNameNew> {
	static auto run(std::string& newBuffer) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		results_data r{ glazeLibraryName, testName, glazeCommitUrl, iterations };
		auto readResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, glazeLibraryName, "skyblue">([&]() {
			bnch_swt::doNotOptimizeAway(glz::validate_json(newBuffer));
			return newBuffer.size();
		});

		bnch_swt::file_loader::saveFile(newBuffer, basePath + "/" + testName + "-glaze.json");
		r.readResult = result<result_type::read>{ "skyblue", newBuffer.size(), readResult };

		return r;
	}
};

template<typename test_data_type, bool minified, size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::simdjson, test_type::parse_and_serialize, test_data_type, minified, iterations, testNameNew> {
	static auto run(std::string& newestBuffer) {
		std::string newBuffer{ newestBuffer };
		newBuffer.reserve(newBuffer.size() + 256);
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		results_data r{ simdjsonLibraryName, testName, simdjsonCommitUrl, iterations };
		simdjson::ondemand::parser parser{};
		test_data_type testData{};
		auto readSize	= newBuffer.size();
		auto readResult = bnch_swt::benchmark_stage<testName + "-Read">::template runBenchmark<testName, simdjsonLibraryName, "cadetblue">([&]() {
			try {
				getValue(testData, parser.iterate(newBuffer).value());
				bnch_swt::doNotOptimizeAway(testData);
				return newBuffer.size();
			} catch (std::exception& error) {
				std::cout << "Simdjson Error: " << error.what() << std::endl;
				return newBuffer.size();
			}
		});
		std::string newerBuffer{};
		auto resultNew = glz::write<glz::opts{ .skip_null_members = false, .prettify = !minified, .minified = minified }>(testData, newerBuffer);
		( void )resultNew;
		readSize = newerBuffer.size();

		r.readResult = result<result_type::read>{ "cadetblue", readSize, readResult };
		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-simdjson.json");
		return r;
	}
};

template<size_t iterations, jsonifier_internal::string_literal testNameNew>
struct json_test_helper<json_library::simdjson, test_type::minify, std::string, false, iterations, testNameNew> {
	static constexpr jsonifier_internal::string_literal testName{ testNameNew };
	static auto run(std::string& newBuffer) {
		results_data r{ simdjsonLibraryName, testName, simdjsonCommitUrl, iterations };

		simdjson::dom::parser parser{};
		std::string newerBuffer{};

		auto writeResult = bnch_swt::benchmark_stage<testName>::template runBenchmark<testName, simdjsonLibraryName, "cornflowerblue">([&]() {
			try {
				newerBuffer = simdjson::minify(parser.parse(newBuffer));
				bnch_swt::doNotOptimizeAway(newerBuffer);
				return newBuffer.size();
			} catch (std::exception& error) {
				std::cout << "Simdjson Error: " << error.what() << std::endl;
				return newBuffer.size();
			}
		});

		bnch_swt::file_loader::saveFile(newerBuffer, basePath + "/" + testName + "-simdjson.json");
		r.writeResult = result<result_type::write>{ "cornflowerblue", newerBuffer.size(), writeResult };


		return r;
	}
};

#if defined(JSONIFIER_MAC)
constexpr jsonifier_internal::string_literal table_header = jsonifier_internal::string_literal{ R"(
| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- | ------------ | ---------------------- | -------------------- | ----------------|  )" };

constexpr jsonifier_internal::string_literal read_table_header = jsonifier_internal::string_literal{ R"(
| Library | Read (MB/S) | Read Variation (+/-%) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ------------------- | -------------- |   )" };

constexpr jsonifier_internal::string_literal write_table_header = jsonifier_internal::string_literal{
	R"(
| Library | Write (MB/S) | Write Variation (+/-%) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | -------------------- | --------------- |   )"
};
#else
constexpr jsonifier_internal::string_literal table_header = jsonifier_internal::string_literal{
	R"(
| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ----------- | --------------------- | -----------------| ------------------- | -------------- | ------------ | ---------------------- | ------------------| -------------------- | --------------- |  )"
};

constexpr jsonifier_internal::string_literal read_table_header = jsonifier_internal::string_literal{ R"(
| Library | Read (MB/S) | Read Variation (+/-%) | Read (Cycles/MB) | Read Length (Bytes) | Read Time (ns) |
| ------- | ----------- | --------------------- | ---------------- | ------------------- | -------------- |   )" };

constexpr jsonifier_internal::string_literal write_table_header = jsonifier_internal::string_literal{
	R"(
| Library | Write (MB/S) | Write Variation (+/-%) | Write (Cycles/MB) | Write Length (Bytes) | Write Time (ns) |
| ------- | ------------ | ---------------------- | ----------------- | -------------------- | --------------- |  )"
};
#endif

std::string getCPUInfo() {
	char brand[49] = { 0 };
	uint32_t regs[12]{};
	size_t length{};
#if defined(__x86_64__) || defined(_M_AMD64)
	static constexpr auto cpuid = [](uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx) {
	#if defined(_MSC_VER)
		uint32_t cpuInfo[4];
		__cpuidex(cpuInfo, *eax, *ecx);
		*eax = cpuInfo[0];
		*ebx = cpuInfo[1];
		*ecx = cpuInfo[2];
		*edx = cpuInfo[3];
	#elif defined(HAVE_GCC_GET_CPUID) && defined(USE_GCC_GET_CPUID)
		uint32_t level = *eax;
		__get_cpuid(level, eax, ebx, ecx, edx);
	#else
		uint32_t a = *eax, b, c = *ecx, d;
		asm volatile("cpuid" : "=a"(a), "=b"(b), "=c"(c), "=d"(d) : "a"(a), "c"(c));
		*eax = a;
		*ebx = b;
		*ecx = c;
		*edx = d;
	#endif
	};
	regs[0] = 0x80000000;
	cpuid(regs, regs + 1, regs + 2, regs + 3);
	if (regs[0] < 0x80000004ll) {
		return {};
	}
	regs[0] = 0x80000002;
	cpuid(regs, regs + 1, regs + 2, regs + 3);
	regs[4] = 0x80000003;
	cpuid(regs + 4, regs + 5, regs + 6, regs + 7);
	regs[8] = 0x80000004;
	cpuid(regs + 8, regs + 9, regs + 10, regs + 11);
	memcpy(brand, regs, sizeof(regs));
	length = std::strlen(brand) > 0 ? std::strlen(brand) - 1 : 0;
	std::string returnValues{};
	returnValues.resize(length - 1);
	std::copy(brand, brand + length, returnValues.data());
	return returnValues.substr(0, returnValues.find_last_of("abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ") + 1);
#else
	char newBuffer[256];
	size_t bufferSize = sizeof(newBuffer);
	if (sysctlbyname("machdep.cpu.brand_string", &newBuffer, &bufferSize, nullptr, 0) == 0) {
		return std::string(newBuffer);
	} else {
		return std::string{ "Unknown CPU" };
	}
#endif
}

static std::string section001{ R"(
 > )" +
	jsonifier::toString(100) + R"( iterations on a ()" + getCPUInfo() + R"().
)" };

constexpr jsonifier_internal::string_literal section002{ jsonifier_internal::string_literal{ R"(#### Using the following commits:
----
| Jsonifier: [)" } +
	JSONIFIER_COMMIT + R"(](https://github.com/RealTimeChris/Jsonifier/commit/)" + JSONIFIER_COMMIT + ")  \n" + R"(| Glaze: [)" + GLAZE_COMMIT +
	R"(](https://github.com/stephenberry/glaze/commit/)" + GLAZE_COMMIT + ")  \n" + R"(| Simdjson: [)" + SIMDJSON_COMMIT + R"(](https://github.com/simdjson/simdjson/commit/)" +
	SIMDJSON_COMMIT + ")  \n" };

constexpr jsonifier_internal::string_literal section00{ R"(# Json-Performance
Performance profiling of JSON libraries (Compiled and run on )" +
	jsonifier_internal::string_literal{ OPERATING_SYSTEM_NAME } + " " + OPERATING_SYSTEM_VERSION + R"( using the )" + COMPILER_ID + " " + COMPILER_VERSION +
	" compiler).  \n\nLatest Results: (" };

constexpr jsonifier_internal::string_literal section01{
	R"(

### Json Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Json%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Json%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Json%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Json%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section02{
	R"(

### Json Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Json%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Json%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Json%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Json%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section03{
	R"(

### Partial Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Partial%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Partial%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Partial%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Partial%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section04{
	R"(

### Partial Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Partial%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Partial%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Partial%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Partial%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section05{
	R"(

### Abc Test (Out of Sequence Performance - Prettified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Abc%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Abc%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Abc%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Abc%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.
)"
};

constexpr jsonifier_internal::string_literal section06{ R"(

### ABC Test (Out of Sequence Performance - Minified) [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/)" + getCurrentPathImpl() + R"(/JsonData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Abc%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Abc%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Abc%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Abc%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section07{ R"(

### Discord Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Discord%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Discord%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Discord%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Discord%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section08{ R"(

### Discord Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Discord%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Discord%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Discord%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Discord%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section09{ R"(

### Canada Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/CanadaData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Canada%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Canada%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Canada%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Canada%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section10{ R"(

### Canada Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/CanadaData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Canada%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Canada%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Canada%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Canada%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section11{ R"(

### CitmCatalog Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/CitmCatalogData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section12{ R"(

### CitmCatalog Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/CitmCatalogData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/CitmCatalog%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section13{ R"(

### Twitter Test (Prettified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/TwitterData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Prettified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Prettified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Prettified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section14{ R"(

### Twitter Test (Minified) Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/TwitterData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Minified)_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Minified)_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Minified)_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Twitter%20Test%20(Minified)_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)" };

constexpr jsonifier_internal::string_literal section15{
	R"(

### Minify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() + R"(/Minify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Minify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Minify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Minify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section16{
	R"(

### Prettify Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/DiscordData-Minified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() + R"(/Prettify%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Prettify%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Prettify%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Prettify%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

constexpr jsonifier_internal::string_literal section17{
	R"(

### Validation Test Results [(View the data used in the following test)](https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Json/DiscordData-Prettified.json):

----
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() + R"(/Validate%20Test_Results.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Validate%20Test_Results.png?raw=true" 
alt="" width="400"/></p>
<p align="left"><a href="https://github.com/RealTimeChris/Json-Performance/blob/)" +
	gitBranch + R"(/Graphs/)" + getCurrentPathImpl() +
	R"(/Validate%20Test_Cumulative_Speedup.png" target="_blank"><img src="https://github.com/RealTimeChris/Json-Performance/blob/)" + gitBranch + R"(/Graphs/)" +
	getCurrentPathImpl() +
	R"(/Validate%20Test_Cumulative_Speedup.png?raw=true" 
alt="" width="400"/></p>

)"
};

std::string getCurrentWorkingDirectory() {
	try {
		return std::filesystem::current_path().string();
	} catch (const std::filesystem::filesystem_error& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return "";
	}
}

void executePythonScript(const std::string& scriptPath, const std::string& argument01, const std::string& argument02) {
#if defined(JSONIFIER_WIN)
	static std::string pythonName{ "python " };
#else
	static std::string pythonName{ "python3 " };
#endif
	std::string command = pythonName + scriptPath + " " + argument01 + " " + argument02;
	int32_t result		= system(command.data());
	if (result != 0) {
		std::cout << "Error: Failed to execute Python script. Command exited with code " << result << std::endl;
	}
}

template<test_type type, typename test_data_type, bool minified, uint64_t iterations, jsonifier_internal::string_literal testName> struct json_tests_helper;

template<test_type type, typename test_data_type, bool minified, uint64_t iterations, jsonifier_internal::string_literal testNameNew> struct json_tests_helper {
	static test_results run(std::string& jsonDataNew) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		test_results jsonResults{};
		jsonResults.testName = static_cast<std::string>(testName);
		results_data jsonifierResults{};
		results_data simdjsonResults{};
		results_data glazeResults{};

#if !defined(ASAN_ENABLED)
		simdjsonResults = json_test_helper<json_library::simdjson, type, test_data_type, minified, iterations, testName>::run(jsonDataNew);
		glazeResults	= json_test_helper<json_library::glaze, type, test_data_type, minified, iterations, testName>::run(jsonDataNew);
#endif
		jsonifierResults = json_test_helper<json_library::jsonifier, type, test_data_type, minified, iterations, testName>::run(jsonDataNew);
#if !defined(ASAN_ENABLED)
		jsonResults.results.emplace_back(simdjsonResults);
		jsonResults.results.emplace_back(glazeResults);
#endif
		jsonResults.results.emplace_back(jsonifierResults);
		jsonResults.markdownResults += table_header + "\n";
		std::sort(jsonResults.results.begin(), jsonResults.results.end(), std::greater<results_data>());
		for (auto iter = jsonResults.results.begin(); iter != jsonResults.results.end();) {
			if (iter->readResult.jsonSpeed.has_value() && iter->readResult.jsonSpeed.value() < (jsonResults.results[0].readResult.jsonSpeed.value() / 30)) {
				iter = jsonResults.results.erase(iter);
			} else {
				jsonResults.markdownResults += iter->jsonStats();
				if (static_cast<size_t>(iter - jsonResults.results.begin()) != jsonResults.results.size() - 1) {
					jsonResults.markdownResults += "\n";
				}
				++iter;
			}
		}
		bnch_swt::benchmark_stage<testNameNew + "-Read">::printResults();
		bnch_swt::benchmark_stage<testNameNew + "-Write">::printResults();
		return jsonResults;
	}
};

template<uint64_t iterations, jsonifier_internal::string_literal testNameNew> struct json_tests_helper<test_type::prettify, std::string, false, iterations, testNameNew> {
	static test_results run(std::string& jsonDataNew) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		test_results jsonResults{};
		jsonResults.testName = static_cast<std::string>(testName);
		results_data jsonifierResults{};
		results_data glazeResults{};
#if !defined(ASAN_ENABLED)
		glazeResults = json_test_helper<json_library::glaze, test_type::prettify, std::string, false, iterations, testName>::run(jsonDataNew);
#endif
		jsonifierResults = json_test_helper<json_library::jsonifier, test_type::prettify, std::string, false, iterations, testName>::run(jsonDataNew);
#if !defined(ASAN_ENABLED)
		jsonResults.results.emplace_back(glazeResults);
#endif
		jsonResults.results.emplace_back(jsonifierResults);
		jsonResults.markdownResults += write_table_header + "\n";
		std::sort(jsonResults.results.begin(), jsonResults.results.end(), std::greater<results_data>());
		for (auto iter = jsonResults.results.begin(); iter != jsonResults.results.end();) {
			if (iter->readResult.jsonSpeed.has_value() && iter->readResult.jsonSpeed.value() < (jsonResults.results[0].readResult.jsonSpeed.value() / 30)) {
				iter = jsonResults.results.erase(iter);
			} else {
				jsonResults.markdownResults += iter->jsonStats();
				if (static_cast<size_t>(iter - jsonResults.results.begin()) != jsonResults.results.size() - 1) {
					jsonResults.markdownResults += "\n";
				}
				++iter;
			}
		}
		bnch_swt::benchmark_stage<testNameNew>::printResults();
		return jsonResults;
	}
};

template<uint64_t iterations, jsonifier_internal::string_literal testNameNew> struct json_tests_helper<test_type::minify, std::string, false, iterations, testNameNew> {
	static test_results run(std::string& jsonDataNew) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		test_results jsonResults{};
		jsonResults.testName = static_cast<std::string>(testName);
		results_data jsonifierResults{};
		results_data simdjsonResults{};
		results_data glazeResults{};
#if !defined(ASAN_ENABLED)
		simdjsonResults = json_test_helper<json_library::simdjson, test_type::minify, std::string, false, iterations, testName>::run(jsonDataNew);
		glazeResults	= json_test_helper<json_library::glaze, test_type::minify, std::string, false, iterations, testName>::run(jsonDataNew);
#endif
		jsonifierResults = json_test_helper<json_library::jsonifier, test_type::minify, std::string, false, iterations, testName>::run(jsonDataNew);
#if !defined(ASAN_ENABLED)
		jsonResults.results.emplace_back(simdjsonResults);
		jsonResults.results.emplace_back(glazeResults);
#endif
		jsonResults.results.emplace_back(jsonifierResults);
		jsonResults.markdownResults += write_table_header + "\n";
		std::sort(jsonResults.results.begin(), jsonResults.results.end(), std::greater<results_data>());
		for (auto iter = jsonResults.results.begin(); iter != jsonResults.results.end();) {
			if (iter->readResult.jsonSpeed.has_value() && iter->readResult.jsonSpeed.value() < (jsonResults.results[0].readResult.jsonSpeed.value() / 30)) {
				iter = jsonResults.results.erase(iter);
			} else {
				jsonResults.markdownResults += iter->jsonStats();
				if (static_cast<size_t>(iter - jsonResults.results.begin()) != jsonResults.results.size() - 1) {
					jsonResults.markdownResults += "\n";
				}
				++iter;
			}
		}
		bnch_swt::benchmark_stage<testNameNew>::printResults();
		return jsonResults;
	}
};

template<uint64_t iterations, jsonifier_internal::string_literal testNameNew> struct json_tests_helper<test_type::validate, std::string, false, iterations, testNameNew> {
	static test_results run(std::string& jsonDataNew) {
		static constexpr jsonifier_internal::string_literal testName{ testNameNew };
		test_results jsonResults{};
		jsonResults.testName = static_cast<std::string>(testName);
		results_data jsonifierResults{};
		results_data glazeResults{};
#if !defined(ASAN_ENABLED)
		glazeResults = json_test_helper<json_library::glaze, test_type::validate, std::string, false, iterations, testName>::run(jsonDataNew);
#endif
		jsonifierResults = json_test_helper<json_library::jsonifier, test_type::validate, std::string, false, iterations, testName>::run(jsonDataNew);
		jsonResults.results.emplace_back(jsonifierResults);
#if !defined(ASAN_ENABLED)
		jsonResults.results.emplace_back(glazeResults);
#endif
		jsonResults.markdownResults += read_table_header + "\n";
		std::sort(jsonResults.results.begin(), jsonResults.results.end(), std::greater<results_data>());
		for (auto iter = jsonResults.results.begin(); iter != jsonResults.results.end();) {
			if (iter->readResult.jsonSpeed.value() < (jsonResults.results[0].readResult.jsonSpeed.value() / 30)) {
				iter = jsonResults.results.erase(iter);
			} else {
				jsonResults.markdownResults += iter->jsonStats();
				if (static_cast<size_t>(iter - jsonResults.results.begin()) != jsonResults.results.size() - 1) {
					jsonResults.markdownResults += "\n";
				}
				++iter;
			}
		}
		bnch_swt::benchmark_stage<testNameNew>::printResults();
		return jsonResults;
	}
};

static constexpr auto totalIterationCountCap{ 1000 };

void testFunction() {
	conformance_tests::conformanceTests();
	round_trip_tests::roundTripTests();
	string_validation_tests::stringTests();
	float_validation_tests::floatTests();
	uint_validation_tests::uintTests();
	int_validation_tests::intTests();
	test_generator<test_struct> testJsonData{};
	std::string jsonDataNew{};
	jsonifier::jsonifier_core parser{};
	parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(testJsonData, jsonDataNew);
	bnch_swt::file_loader::saveFile(jsonDataNew, basePath + "/JsonData-Prettified.json");
	std::string jsonMinifiedData{ glz::minify_json(jsonDataNew) };
	bnch_swt::file_loader::saveFile(jsonMinifiedData, std::string{ static_cast<std::string>(basePath) + "/JsonData-Minified.json" });
	std::string discordData{ bnch_swt::file_loader::loadFile(jsonPath + "/DiscordData-Prettified.json") };
	std::string discordMinifiedData{ bnch_swt::file_loader::loadFile(jsonPath + "/DiscordData-Minified.json") };
	std::string canadaData{ bnch_swt::file_loader::loadFile(jsonPath + "/CanadaData-Prettified.json") };
	std::string canadaMinifiedData{ bnch_swt::file_loader::loadFile(jsonPath + "/CanadaData-Minified.json") };
	std::string citmCatalogData{ bnch_swt::file_loader::loadFile(jsonPath + "/CitmCatalogData-Prettified.json") };
	std::string citmCatalogMinifiedData{ bnch_swt::file_loader::loadFile(jsonPath + "/CitmCatalogData-Minified.json") };
	std::string twitterData{ bnch_swt::file_loader::loadFile(jsonPath + "/TwitterData-Prettified.json") };
	std::string twitterMinifiedData{ bnch_swt::file_loader::loadFile(jsonPath + "/TwitterData-Minified.json") };
	std::string newTimeString{};
	newTimeString.resize(1024);
	std::tm resultTwo{};
	std::time_t result = std::time(nullptr);
	resultTwo		   = *localtime(&result);
	std::vector<test_results> benchmark_data{};
	newTimeString.resize(strftime(newTimeString.data(), 1024, "%b %d, %Y", &resultTwo));
	std::string newerString{ static_cast<std::string>(section00) + newTimeString + ")\n" + static_cast<std::string>(section002) + section001 +
		static_cast<std::string>(section01) };
	test_results testResults{ json_tests_helper<test_type::parse_and_serialize, test<test_struct>, false, totalIterationCountCap, "Json Test (Prettified)">::run(jsonDataNew) };
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, test<test_struct>, true, totalIterationCountCap, "Json Test (Minified)">::run(jsonMinifiedData);
	newerString += section02;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, partial_test<test_struct>, false, totalIterationCountCap, "Partial Test (Prettified)">::run(jsonDataNew);
	newerString += section03;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, partial_test<test_struct>, true, totalIterationCountCap, "Partial Test (Minified)">::run(jsonMinifiedData);
	newerString += section04;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, abc_test<test_struct>, false, totalIterationCountCap, "Abc Test (Prettified)">::run(jsonDataNew);
	newerString += section05;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, abc_test<test_struct>, true, totalIterationCountCap, "Abc Test (Minified)">::run(jsonMinifiedData);
	newerString += section06;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, discord_message, false, totalIterationCountCap, "Discord Test (Prettified)">::run(discordData);
	newerString += section07;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, discord_message, true, totalIterationCountCap, "Discord Test (Minified)">::run(discordMinifiedData);
	newerString += section08;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, canada_message, false, totalIterationCountCap, "Canada Test (Prettified)">::run(canadaData);
	newerString += section09;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, canada_message, true, totalIterationCountCap, "Canada Test (Minified)">::run(canadaMinifiedData);
	newerString += section10;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, citm_catalog_message, false, totalIterationCountCap, "CitmCatalog Test (Prettified)">::run(citmCatalogData);
	newerString += section11;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults =
		json_tests_helper<test_type::parse_and_serialize, citm_catalog_message, true, totalIterationCountCap, "CitmCatalog Test (Minified)">::run(citmCatalogMinifiedData);
	newerString += section12;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, twitter_message, false, totalIterationCountCap, "Twitter Test (Prettified)">::run(twitterData);
	newerString += section13;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::parse_and_serialize, twitter_message, true, totalIterationCountCap, "Twitter Test (Minified)">::run(twitterMinifiedData);
	newerString += section14;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::minify, std::string, false, totalIterationCountCap, "Minify Test">::run(discordData);
	newerString += section15;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::prettify, std::string, false, totalIterationCountCap, "Prettify Test">::run(jsonMinifiedData);
	newerString += section16;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	testResults = json_tests_helper<test_type::validate, std::string, false, totalIterationCountCap, "Validate Test">::run(discordData);
	newerString += section17;
	newerString += testResults.markdownResults;
	benchmark_data.emplace_back(testResults);
	std::string resultsStringJson{};
	test_results_final resultsData{};
	for (auto& value: benchmark_data) {
		test_elements_final testElement{};
		testElement.testName = value.testName;
		for (auto& valueNew: value.results) {
			test_element_final resultFinal{};
			if (valueNew.readResult.jsonSpeed.has_value()) {
				resultFinal.libraryName = valueNew.name;
				resultFinal.color		= valueNew.readResult.color;
				resultFinal.resultSpeed = valueNew.readResult.jsonSpeed.value();
				resultFinal.resultType	= "Read";
				testElement.results.emplace_back(resultFinal);
			}
			if (valueNew.writeResult.jsonSpeed.has_value()) {
				resultFinal.libraryName = valueNew.name;
				resultFinal.color		= valueNew.writeResult.color;
				resultFinal.resultSpeed = valueNew.writeResult.jsonSpeed.value();
				resultFinal.resultType	= "Write";
				testElement.results.emplace_back(resultFinal);
			}
		}
		resultsData.emplace_back(testElement);
	}
	parser.serializeJson<jsonifier::serialize_options{ .prettify = true }>(resultsData, resultsStringJson);
	std::cout << "Json Data: " << resultsStringJson << std::endl;
	bnch_swt::file_loader::saveFile(resultsStringJson, basePath + "/Results.json");
	bnch_swt::file_loader::saveFile(static_cast<std::string>(newerString), README_PATH + getCurrentPathImpl() + ".md");
	std::cout << "Md Data: " << newerString << std::endl;
	executePythonScript(std::string{ BASE_PATH } + "/GenerateGraphs.py", std::string{ basePath } + "/Results.json",
		std::string{ GRAPHS_PATH } + "/" + std::string{ getCurrentPathImpl() } + "/");
#if !defined(NDEBUG)
	for (auto& value: jsonifier_internal::types) {
		std::cout << "TYPE: " << value.first << ", HASH-TYPE: " << value.second << std::endl;
	}
#endif
};

int32_t main() {
	try {
		testFunction();

	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
};