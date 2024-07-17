cmake_minimum_required(VERSION 3.18)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/Install/")

project(
  "Json-Performance"
  VERSION "${PRODUCT_VERSION}"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
include(GetCommitHash.cmake)

FetchContent_Declare(
  jsonifier
  GIT_REPOSITORY https://github.com/realtimechris/jsonifier.git
  GIT_TAG dev
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(jsonifier)
getCommitHash("${jsonifier_SOURCE_DIR}" JSONIFIER_COMMIT_HASH)

FetchContent_Declare(
  glaze
  GIT_REPOSITORY https://github.com/stephenberry/glaze.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glaze)
getCommitHash("${glaze_SOURCE_DIR}" GLAZE_COMMIT_HASH)

set(JSONIFIER_LIBRARY "TRUE" CACHE STRING "To avoid circular dependency issues." FORCE)
FetchContent_Declare(
  BenchmarkSuite
  GIT_REPOSITORY https://github.com/RealTimeChris/BenchmarkSuite.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(BenchmarkSuite)

FetchContent_Declare(
  simdjson
  GIT_REPOSITORY https://github.com/RealTimeChris/simdjson.git
  GIT_TAG master
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(simdjson)
getCommitHash("${simdjson_SOURCE_DIR}" SIMDJSON_COMMIT_HASH)

add_executable(
  "Json-Performance" 
  "./Source/main.cpp"
)

target_link_libraries(
	"Json-Performance" PUBLIC 
	Jsonifier::Jsonifier glaze::glaze simdjson BenchmarkSuite::BenchmarkSuite
)

target_compile_options(
	"Json-Performance" PUBLIC
	"$<$<CXX_COMPILER_ID:CLANG>:-Wextra>"
	"$<$<CXX_COMPILER_ID:MSVC>:/bigobj>"
	"$<$<CXX_COMPILER_ID:CLANG>:-Wall>"
	"$<$<CXX_COMPILER_ID:GNU>:-Wextra>"
	"$<$<CXX_COMPILER_ID:MSVC>:/Wall>"
	"$<$<CXX_COMPILER_ID:MSVC>:/EHsc>"
	"$<$<CXX_COMPILER_ID:GNU>:-Wall>"
	"$<$<CXX_COMPILER_ID:MSVC>:/Zi>"
)

target_link_options(
	"Json-Performance" PUBLIC
	"$<$<CXX_COMPILER_ID:GNU>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:-fsanitize=address>>"
	"$<$<CXX_COMPILER_ID:MSVC>:/DEBUG>"
	"$<$<CXX_COMPILER_ID:MSVC>:/OPT:REF>"
)

if (WIN32)
	install(
		FILES 
		"$<TARGET_PDB_FILE:Json-Performance>"
		DESTINATION "$<IF:$<CONFIG:Debug>,bin,bin>"
		OPTIONAL
	)
endif()

target_compile_definitions(
	"Json-Performance" PUBLIC 
	"JSON_TEST_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/Source/ConformanceTests\""
	"JSON_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/Json\""
	"README_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.md\""
	"GRAPHS_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/Graphs\""
	"BASE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/\""
	"JSONIFIER_COMMIT=\"${JSONIFIER_COMMIT_HASH}\""
	"SIMDJSON_COMMIT=\"${SIMDJSON_COMMIT_HASH}\""
	"GLAZE_COMMIT=\"${GLAZE_COMMIT_HASH}\""
)

install(
	FILES 
	"$<TARGET_FILE:Json-Performance>"
	DESTINATION "$<IF:$<CONFIG:Debug>,bin,bin>"
	OPTIONAL
)
