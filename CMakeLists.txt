cmake_minimum_required(VERSION 3.26)
project(2023_cpp_exercise)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(1-sort)

add_subdirectory(cpp01)

add_executable(main main.cpp)

add_executable(fat_main fat_main.cpp)
