cmake_minimum_required(VERSION 3.10)
project(aima)

set(CMAKE_CXX_STANDARD 14)


# main include
include_directories(search search/commons utilities example)

# defines the search shared library
add_subdirectory(search)

####################
## Catch2 Test cases
####################
option(BUILD_TESTS "Create test targets for make" ON)
if (BUILD_TESTS)
    enable_testing()
    set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
    add_library(Catch INTERFACE)
    target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
    set(TEST_SOURCES
            test/main-test.cpp
            test/test-tree-search.cpp test/test-util-string_ops.cpp)
    add_executable(testAima ${TEST_SOURCES})
    add_test(NAME testAima COMMAND testAima)
endif(BUILD_TESTS)
