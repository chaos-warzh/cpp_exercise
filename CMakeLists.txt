cmake_minimum_required(VERSION 3.26)
project(2023_cpp_exercise)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(1-sort)
add_subdirectory(2-linear-ds)
add_subdirectory(3-strings)
add_subdirectory(4-linear-ds-more)

add_subdirectory(alg01)

add_subdirectory(cpp01)
add_subdirectory(cpp02)
add_subdirectory(cpp03)
add_subdirectory(cpp04)

add_subdirectory(stl)
add_subdirectory(oo)


add_executable(main main.cpp
        cpp04/int_stream.cpp)
