cmake_minimum_required(VERSION 3.29)
project(online_mode)

set(CMAKE_CXX_STANDARD 17)

include_directories(include ../../field/include ../../file/include)

add_library(online_mode src/online_mode.cpp)

#add_subdirectory(test)

#add_subdirectory(../../gtest)