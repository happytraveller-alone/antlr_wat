# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test

# Include any dependencies generated for this target.
include vlun/CMakeFiles/vlun_clang.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include vlun/CMakeFiles/vlun_clang.dir/compiler_depend.make

# Include the progress variables for this target.
include vlun/CMakeFiles/vlun_clang.dir/progress.make

# Include the compile flags for this target's objects.
include vlun/CMakeFiles/vlun_clang.dir/flags.make

vlun/CMakeFiles/vlun_clang.dir/vlun.c.o: vlun/CMakeFiles/vlun_clang.dir/flags.make
vlun/CMakeFiles/vlun_clang.dir/vlun.c.o: vlun/vlun.c
vlun/CMakeFiles/vlun_clang.dir/vlun.c.o: vlun/CMakeFiles/vlun_clang.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object vlun/CMakeFiles/vlun_clang.dir/vlun.c.o"
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun && /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-clang-fast $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vlun/CMakeFiles/vlun_clang.dir/vlun.c.o -MF CMakeFiles/vlun_clang.dir/vlun.c.o.d -o CMakeFiles/vlun_clang.dir/vlun.c.o -c /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun/vlun.c

vlun/CMakeFiles/vlun_clang.dir/vlun.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vlun_clang.dir/vlun.c.i"
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun && /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-clang-fast $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun/vlun.c > CMakeFiles/vlun_clang.dir/vlun.c.i

vlun/CMakeFiles/vlun_clang.dir/vlun.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vlun_clang.dir/vlun.c.s"
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun && /home/xyf/antlr_wat/AFLplusplus_v4.09c/afl-clang-fast $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun/vlun.c -o CMakeFiles/vlun_clang.dir/vlun.c.s

# Object files for target vlun_clang
vlun_clang_OBJECTS = \
"CMakeFiles/vlun_clang.dir/vlun.c.o"

# External object files for target vlun_clang
vlun_clang_EXTERNAL_OBJECTS =

vlun/vlun_clang: vlun/CMakeFiles/vlun_clang.dir/vlun.c.o
vlun/vlun_clang: vlun/CMakeFiles/vlun_clang.dir/build.make
vlun/vlun_clang: vlun/CMakeFiles/vlun_clang.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable vlun_clang"
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vlun_clang.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vlun/CMakeFiles/vlun_clang.dir/build: vlun/vlun_clang
.PHONY : vlun/CMakeFiles/vlun_clang.dir/build

vlun/CMakeFiles/vlun_clang.dir/clean:
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun && $(CMAKE_COMMAND) -P CMakeFiles/vlun_clang.dir/cmake_clean.cmake
.PHONY : vlun/CMakeFiles/vlun_clang.dir/clean

vlun/CMakeFiles/vlun_clang.dir/depend:
	cd /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/vlun/CMakeFiles/vlun_clang.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vlun/CMakeFiles/vlun_clang.dir/depend

