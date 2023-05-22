cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Json-Performance")

project(
  "${PROJECT_NAME}"
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Output")

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

target_link_libraries("${PROJECT_NAME}" PRIVATE Jsonifier::Jsonifier glaze::glaze simdjson::simdjson fmt::fmt)

target_compile_options(
    "${PROJECT_NAME}" 
    PUBLIC
    "$<$<CXX_COMPILER_ID:MSVC>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:-fsanitize=address>>"
	"$<$<CXX_COMPILER_ID:MSVC>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:/Zi>>"
    "$<$<CXX_COMPILER_ID:MSVC>:/O2>"
)

target_link_options(
	"${PROJECT_NAME}" PUBLIC
	"$<$<CXX_COMPILER_ID:GNU>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:-fsanitize=address>>"
    #"$<$<CXX_COMPILER_ID:MSVC>:/DEBUG>"
)

if (WIN32)
    install(
	    FILES 
	    "$<TARGET_PDB_FILE:${PROJECT_NAME}"
	    DESTINATION "$<IF:$<CONFIG:Debug>,bin,bin>"
	    OPTIONAL
    )
endif()
