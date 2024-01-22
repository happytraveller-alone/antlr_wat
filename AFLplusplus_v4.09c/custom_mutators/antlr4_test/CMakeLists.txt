cmake_minimum_required(VERSION 3.15)
project(antlr_check)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# Specify the C and C++ compilers
set(CMAKE_C_COMPILER_ID "Clang")

# Set the build type to Release by default
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release." FORCE)
# Detect build type, fallback to release and throw a warning if use didn't specify any
if(NOT CMAKE_BUILD_TYPE)
  message(WARNING "Build type not set, falling back to Release mode.
 To specify build type use:
 -DCMAKE_BUILD_TYPE=<mode> where <mode> is Debug or Release.")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
       "Choose the type of build, options are: Debug Release."
       FORCE)
endif(NOT CMAKE_BUILD_TYPE)


# Set the default flags for the C and C++ compilers
set(WITH_STATIC_CRT "(Visual C++) Enable to statically link CRT, which avoids requiring users to install the redistribution package.To enable with: -DWITH_STATIC_CRT=On" OFF)
if(WITH_STATIC_CRT)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif(WITH_STATIC_CRT)


# Enable with_libcxx only if the compiler is clang++
# set(WITH_LIBCXX ON)
option(WITH_LIBCXX "Building with clang++ and libc++(in Linux). To enable with: -DWITH_LIBCXX=On" ON)
option(DISABLE_WARNINGS "Suppress compiler warnings for all built ANTLR targets" OFF)

# disable with_demo
set(WITH_DEMO False)
# generate with demo
if(NOT WITH_DEMO)
  message(STATUS "Building without demo. To enable demo build use: -DWITH_DEMO=True")
  set(WITH_DEMO False CACHE STRING
    "Chose to build with or without demo executable"
    FORCE)
endif(NOT WITH_DEMO)
if(WITH_DEMO)
 add_subdirectory(demo)
endif(WITH_DEMO)

# set compiler warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(MY_CXX_WARNING_FLAGS "  /W4")

  if(DISABLE_WARNINGS)
    set(MY_CXX_WARNING_FLAGS "  /w")
  endif()
else()
  set(MY_CXX_WARNING_FLAGS "  -Wall -pedantic -W")

  if(DISABLE_WARNINGS)
    set(MY_CXX_WARNING_FLAGS "  -w")
  endif()
endif()

# Set the C and C++ compile args for different build types
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi /MP ${MY_CXX_WARNING_FLAGS}")
  set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} /O1 /Oi /Ob2 /Gy /MP /DNDEBUG ${MY_CXX_WARNING_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Oi /Ob2 /Gy /MP /DNDEBUG ${MY_CXX_WARNING_FLGAS}")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /O2 /Oi /Ob2 /Gy /MP /Zi ${MY_CXX_WARNING_FLAGS}")
else()
  set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g ${MY_CXX_WARNING_FLAGS}")
  set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG ${MY_CXX_WARNING_FLAGS}")
  set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG ${MY_CXX_WARNING_FLGAS}")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g ${MY_CXX_WARNING_FLAGS}")
endif()

# Compiler-specific C++17 activation.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    # Just g++-5.0 and greater contain <codecvt> header. (test in ubuntu)
    if(NOT (GCC_VERSION VERSION_GREATER 5.0 OR GCC_VERSION VERSION_EQUAL 5.0))
        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 5.0 or greater.")
    endif ()
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND ANDROID)
	# Need -Os cflag and cxxflags here to work with exception handling on armeabi.
	# see  https://github.com/android-ndk/ndk/issues/573
	# and without -stdlib=libc++ cxxflags
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND ( CMAKE_SYSTEM_NAME MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "FreeBSD") )
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE CLANG_VERSION)
    if(NOT (CLANG_VERSION VERSION_GREATER 4.2.1 OR CLANG_VERSION VERSION_EQUAL 4.2.1))
        message(FATAL_ERROR "${PROJECT_NAME} requires clang 4.2.1 or greater.")
    endif()
    # You can use libc++ to compile this project when g++ is NOT greater than or equal to 5.0.
    if(WITH_LIBCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif()
elseif(MSVC_VERSION GREATER 1800 OR MSVC_VERSION EQUAL 1800)
  # Visual Studio 2012+ supports C++17 features
elseif(CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
else()
    message(FATAL_ERROR "Your C++ compiler does not support C++17.")
endif()

add_subdirectory(vlun)
add_subdirectory(antlr_parser)