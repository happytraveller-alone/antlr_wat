cmake_minimum_required(VERSION 3.15)
project(Grammar_check)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
# Specify the C and C++ compilers
set(CMAKE_C_COMPILER /usr/bin/clang-14)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-14)
# Specify the C and C++ compile args
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORTIFY_SOURCE=2 -g -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -g -O0")
# ADD -fsanitize=address -fno-omit-frame-pointer -g -O1

# generate the libantlr4-runtime.a
add_subdirectory(runtime)

set(ANTLR_JAR_LOCATION /usr/local/lib/antlr-4.13.1-complete.jar)
set(ANTLR_GENERATED_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
# generate antlr4 files
# Execute the shell script
execute_process(
    COMMAND java -jar ${ANTLR_JAR_LOCATION} -listener -visitor -Dlanguage=Cpp -o ${ANTLR_GENERATED_SRC_DIR} StrLexer.g4 StrParser.g4
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
)
if(result EQUAL 0)
    message(STATUS "Shell script executed successfully. ANTLR4 files generated.")
else()
    message(FATAL_ERROR "Failed to execute shell script: ${output}")
endif()

# Include the ANTLR4 runtime library from your project directory
set(ANTLR4_ROOT ${CMAKE_CURRENT_LIST_DIR}/runtime)
include_directories(${ANTLR4_ROOT}/src)

# Include the AFL++ library from your project directory
set(AFL_ROOT "/home/xyf/antlr_wat/AFLplusplus_v4.09c")
include_directories(${AFL_ROOT}/include)
# Gather all the source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")


# libantlr4-runtime.a
set(ANTLR4_RUNTIME ${ANTLR4_ROOT}/libantlr4-runtime.a)
# Add the generated lexer and parser files to your project
add_executable(Grammar_check  ${SOURCES})
# Link against the ANTLR4 runtime library
target_link_libraries(Grammar_check ${ANTLR4_RUNTIME})
# Add executable compile flags
target_compile_options(Grammar_check PRIVATE
    # -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    # -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    # Add any additional flags here
)
add_dependencies(Grammar_check antlr4_static antlr4_shared)

# Add the shared library
add_library(Grammar_check_shared SHARED ${SOURCES})

target_link_libraries(Grammar_check_shared ${ANTLR4_RUNTIME})
# Add executable compile flags
target_compile_options(Grammar_check_shared PUBLIC
    -c
    # -shared
    # -Wall            # Enable all warnings
    # -Werror          # Treat warnings as errors
    # -Wextra          # Enable extra warnings
    -std=c++17       # cplusplus 17 standard
    -fPIC           # Position independent code
    # Add any additional flags here
)

add_dependencies(Grammar_check_shared antlr4_static antlr4_shared)
# Specify any additional dependencies or flags here