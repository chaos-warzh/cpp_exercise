cmake_minimum_required(VERSION 3.26)
project(2023_cpp_exercise)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(1-sort)
add_subdirectory(2-linear-ds)

add_subdirectory(cpp01)
add_subdirectory(cpp02)

add_subdirectory(stl)


add_executable(main main.cpp)
