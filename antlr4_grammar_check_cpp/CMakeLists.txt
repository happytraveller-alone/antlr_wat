cmake_minimum_required(VERSION 3.12)
project(Grammar_check)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /usr/bin/clang-14)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-14)

# Include the ANTLR4 runtime library from your project directory
set(ANTLR4_ROOT ${CMAKE_SOURCE_DIR}/runtime)
include_directories(${ANTLR4_ROOT}/runtime/src)
# include_directories(${CMAKE_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
# add_executable(your_executable ${SOURCES})


# Add the generated lexer and parser files to your project
add_executable(Grammar_check
    Check.cpp
    ${SOURCES}
)

# Link against the ANTLR4 runtime library
target_link_libraries(Grammar_check ${ANTLR4_ROOT}/run/usr/local/lib/libantlr4-runtime.a)

# Add compile flags
target_compile_options(Grammar_check PRIVATE
    -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    # Add any additional flags here
)

# Specify any additional dependencies or flags here
