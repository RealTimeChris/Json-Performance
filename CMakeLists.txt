cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Json-Performance")

project(
  "${PROJECT_NAME}"
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Install/")

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

add_executable("${PROJECT_NAME}"  "./Source/ConformanceTests.hpp" "Source/main.cpp")

target_link_libraries("${PROJECT_NAME}" PRIVATE Jsonifier::Jsonifier glaze::glaze simdjson::simdjson)

target_compile_options(
	"${PROJECT_NAME}" PUBLIC
	"$<$<CXX_COMPILER_ID:MSVC>:/Zi>"
)

target_link_options(
	"${PROJECT_NAME}" PUBLIC
	"$<$<CXX_COMPILER_ID:GNU>:$<$<STREQUAL:${ASAN_ENABLED},TRUE>:-fsanitize=address>>"
	"$<$<CXX_COMPILER_ID:MSVC>:/DEBUG>"
	"$<$<CXX_COMPILER_ID:MSVC>:/OPT:REF>"
	"$<$<CXX_COMPILER_ID:MSVC>:/OPT:ICF>"
)

target_compile_definitions(
	"Json-Performance" PUBLIC 
	"JSON_PATH=\"${CMAKE_SOURCE_DIR}/Source/ConformanceTests\""
)

if (WIN32)
	install(
		FILES 
		"$<TARGET_PDB_FILE:${PROJECT_NAME}>"
		DESTINATION "$<IF:$<CONFIG:Debug>,bin,bin>"
		OPTIONAL
	)
endif()

install(
	FILES 
	"$<TARGET_FILE:${PROJECT_NAME}>"
	DESTINATION "$<IF:$<CONFIG:Debug>,bin,bin>"
	OPTIONAL
)