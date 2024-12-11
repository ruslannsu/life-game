cmake_minimum_required(VERSION 3.29)
project(game)

set(CMAKE_CXX_STANDARD 17)

include_directories(include ../field/include ../file/include)

add_library(game src/game.cpp)
