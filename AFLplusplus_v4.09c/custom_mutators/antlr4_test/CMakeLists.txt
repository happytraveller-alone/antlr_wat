cmake_minimum_required(VERSION 3.12)
project(Grammar_check)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /usr/bin/clang-14)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-14)

# Specify the C and C++ compile args
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORTIFY_SOURCE=2 -g -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -g -O3")
# ADD -fsanitize=address -fno-omit-frame-pointer -g -O1

# Include the ANTLR4 runtime library from your project directory
set(ANTLR4_ROOT ${CMAKE_SOURCE_DIR}/runtime)
include_directories(${ANTLR4_ROOT}/runtime/src)
# Include the AFL++ library from your project directory
set(AFL_ROOT "/home/xyf/antlr_wat/AFLplusplus_v4.09c")
include_directories(${AFL_ROOT}/include)
# Gather all the source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Add the generated lexer and parser files to your project
add_executable(Grammar_check  ${SOURCES})
# Link against the ANTLR4 runtime library
target_link_libraries(Grammar_check ${ANTLR4_ROOT}/dist/libantlr4-runtime.a)
# Add executable compile flags
target_compile_options(Grammar_check PRIVATE
    -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    # Add any additional flags here
)


# Add the shared library
add_library(Grammar_check_shared SHARED ${SOURCES} ${ANTLR4_ROOT}/dist/libantlr4-runtime.a)
# # Link against the ANTLR4 runtime library
# target_link_libraries(Grammar_check_shared )
# Set output shared library name
# Add executable compile flags
target_compile_options(Grammar_check_shared PRIVATE
    -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    -fPIC           # Position independent code
    # Add any additional flags here
)
# Specify any additional dependencies or flags here
