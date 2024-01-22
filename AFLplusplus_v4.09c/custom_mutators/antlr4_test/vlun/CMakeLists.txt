cmake_minimum_required(VERSION 3.12)
project(vlun_clang)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-clang)
set(CMAKE_CXX_COMPILER /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-clang++)

# Specify the C and C++ compile args
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORTIFY_SOURCE=2 -g -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -g -O3")
message("The cmake source path is: ${CMAKE_SOURCE_DIR}")
message("The cmake list path is: ${CMAKE_CURRENT_LIST_DIR}")
# ADD -fsanitize=address -fno-omit-frame-pointer -g -O1
# message("The path of the parent CMakeLists.txt is: ${CMAKE_CURRENT_LIST_DIR}")
# set(CMAKE_PARENT_DIR ${CMAKE_CURRENT_LIST_DIR}/../)
# message("The path of the parent CMakeLists.txt is: ${CMAKE_PARENT_DIR}")
# Add the generated lexer and parser files to your project
add_executable(vlun_clang  vlun.c)
# Add executable compile flags
target_compile_options(vlun_clang PRIVATE
    # -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    # -Wextra          # Enable extra warnings
    -std=c17       # cplusplus 17 standard
    # Add any additional flags here
)
