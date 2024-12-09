cmake_minimum_required(VERSION 3.29)
project(lab2)

set(CMAKE_CXX_STANDARD 17)



add_subdirectory(lib/field)

add_subdirectory(lib/modes/online_mode)
#add_subdirectory(gtest)

add_subdirectory(lib/file)


include_directories(lib/field/include lib/modes/online_mode/include lib/file/include)

add_executable(my_executable src/main.cpp)

target_link_libraries(my_executable field online_mode file)
