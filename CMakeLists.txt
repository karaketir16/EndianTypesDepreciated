cmake_minimum_required(VERSION 3.22)
project(EndianTypes)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(EndianTypes
        endian.hpp
        example.cpp)
