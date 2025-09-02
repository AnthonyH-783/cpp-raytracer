# Minimum CMake version required
cmake_minimum_required(VERSION 4.1.1)

# Project name
project(CppRaytracer)

# Set C++ standard
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )


# Defining source files
set ( SOURCES
    src/main.cpp
    include/vec3.h

)

# Including Directories
include_directories( ${PROJECT_SOURCE_DIR}/include )
include_directories( ${PROJECT_SOURCE_DIR}/src)

# Adding Executables
add_executable( CppRaytracer ${SOURCES} )