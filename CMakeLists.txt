cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Json-Performance")

project(
  "${PROJECT_NAME}"
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)

if(NOT "${CPM_LOCAL_PACKAGE_PATHS}" STREQUAL "")
   include("${CPM_LOCAL_PACKAGE_PATHS}")
endif()

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Output")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
   Jsonifier
   GIT_REPOSITORY https://github.com/RealTimeChris/Jsonifier.git
   GIT_TAG dev
)
FetchContent_MakeAvailable(Jsonifier)

FetchContent_Declare(
   glaze
   GIT_REPOSITORY https://github.com/stephenberry/glaze.git
   GIT_TAG main
)
FetchContent_MakeAvailable(glaze)

FetchContent_Declare(
  simdjson
  GIT_REPOSITORY https://github.com/RealTimeChris/simdjson.git
  GIT_TAG master
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(simdjson)

FetchContent_Declare(
        fmt
        SYSTEM TRUE
        GIT_TAG 9.1.0
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
)

FetchContent_MakeAvailable(fmt)

add_executable("${PROJECT_NAME}" "Source/main.cpp")
set_target_properties("${PROJECT_NAME}" PROPERTIES CXX_STANDARD 23)

target_link_libraries("${PROJECT_NAME}" PRIVATE Jsonifier::Jsonifier glaze::glaze simdjson::simdjson fmt::fmt)
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_23)
target_compile_options(
    "${PROJECT_NAME}" 
    PUBLIC
    "$<$<CXX_COMPILER_ID:MSVC>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:-fsanitize=address>>"
	"$<$<CXX_COMPILER_ID:MSVC>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:/Zi>>"
)
