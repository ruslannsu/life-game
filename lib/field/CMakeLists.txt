cmake_minimum_required(VERSION 3.29)
project(field)

set(CMAKE_CXX_STANDARD 17)

include_directories(include ../file/include)

add_library(field src/field.cpp)

#add_subdirectory(test)

#add_subdirectory(../../gtest)