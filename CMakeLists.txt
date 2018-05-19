cmake_minimum_required(VERSION 3.10)
project(aima)

set(CMAKE_CXX_STANDARD 14)


# main include
include_directories(search search/commons utilities)

# defines the search shared library
add_subdirectory(search)

# exe
add_executable(main main.cpp)
# linking SOs
target_link_libraries(main search)
