cmake_minimum_required(VERSION 2.8.11)

project(Complex)



include_directories(
    /home/ari/.codelite/ELEN3009/Complex/
    /home/ari/.codelite/ELEN3009/Complex/

)

# Linker options
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS}  ")

# Library path
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -L\".\" ")

# Define the CXX sources
set ( CXX_SRCS
    ../../../development/elen3009/complex.cpp
    ../../../development/elen3009/quadratic.cpp
)

set_source_files_properties(
    ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
    " -g -O0 -Wall")

add_executable(Complex ${CXX_SRCS} ${C_SRCS})

