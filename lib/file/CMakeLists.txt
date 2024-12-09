cmake_minimum_required(VERSION 3.29)
project(file)

set(CMAKE_CXX_STANDARD 17)

include_directories(include ../field/include)

add_library(file src/file.cpp)

#add_subdirectory(test)

#add_subdirectory(../../gtest)