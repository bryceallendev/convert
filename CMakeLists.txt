# @file CMakeLists.txt
# 
# CMake files for the convert example

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.10)

# project info
project(convert)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Source files for the main program srcFacts
set(SOURCE convert.cpp)

# convert application
add_executable(convert ${SOURCE})

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()
