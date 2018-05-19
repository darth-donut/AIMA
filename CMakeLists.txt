cmake_minimum_required(VERSION 3.10)
project(aima)

set(CMAKE_CXX_STANDARD 14)

add_library(aima SHARED library.h)


add_executable(main main.cpp)
target_link_libraries(main aima)
