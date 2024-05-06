cmake_minimum_required(VERSION 3.12)
project(JavaScript_Grammar_Check)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# Include the ANTLR4 runtime library from your project directory
set(ANTLR4_ROOT ${CMAKE_SOURCE_DIR}/runtime)
include_directories(${ANTLR4_ROOT}/runtime/src)
include_directories(${CMAKE_SOURCE_DIR}/include)
# include_directories(${CMAKE_SOURCE_DIR}/common)
file(GLOB_RECURSE SOURCES_COMMON "common/*.cpp" "common/*.h")
file(GLOB_RECURSE SOURCES_INCLUDE "include/*.cpp" "include/*.h")
# file(GLOB_RECURSE SOURCES_INCLUDE "include/*.h")

set(SOURCE_ENTRY src/main.cpp)
# Add the generated lexer and parser files to your project
add_executable(JavaScript_Grammar_Check
    ${SOURCE_ENTRY}
    ${SOURCES_COMMON}
    ${SOURCES_INCLUDE}
)

# Link against the ANTLR4 runtime library
target_link_libraries(JavaScript_Grammar_Check ${ANTLR4_ROOT}/run/usr/local/lib/libantlr4-runtime.a)

# Add compile flags
target_compile_options(JavaScript_Grammar_Check PRIVATE
    # -Wall            # Enable all warnings
    -Wno-unused-parameter # Disable unused parameter warning
    # -Werror          # Treat warnings as errors
    # -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    # Add any additional flags here
)

# Specify any additional dependencies or flags here
