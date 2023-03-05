cmake_minimum_required(VERSION 3.24)
project(EndianTypes)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(EndianTypes
        bigEndInt.hpp
        endian.hpp
        example.cpp)
