cmake_minimum_required(VERSION 3.15)

project(wasm-fuzz LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_CXX_FLAGS "-O3 -fsanitize=fuzzer,address -DV8_COMPRESS_POINTERS")
    set(CMAKE_C_FLAGS "-O3 -fsanitize=fuzzer,address -DV8_COMPRESS_POINTERS")
elseif (CMAKE_BUILD_TYPE MATCHES "ONLYDebug")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -g")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -g")
elseif (CMAKE_BUILD_TYPE MATCHES "DebugMEM")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -DDEBUG_MEM -g -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -DDEBUG_MEM -g -fsanitize=address -fno-omit-frame-pointer")
elseif (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "-O0 -DDEBUG -g -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_C_FLAGS "-O0 -DDEBUG -g -fsanitize=address -fno-omit-frame-pointer")
endif()

link_directories(V8 JavaScriptCore)

add_executable(fuzzer_v8 fuzzer_v8.cpp)
add_executable(fuzzer_jsc fuzzer_jsc.cpp)

include_directories(V8/include V8 JavaScriptCore)

target_link_libraries(fuzzer_v8 PUBLIC v8_monolith)
target_link_libraries(fuzzer_jsc PUBLIC JavaScriptCore)
