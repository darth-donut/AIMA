cmake_minimum_required(VERSION 3.10)
project(aima)

set(CMAKE_CXX_STANDARD 14)


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
    add_executable(testAima
            test/main-test.cpp
            test/search/commons/test-tree-search.cpp
            test/utilities/test-util-string_ops.cpp
            example/romania.cpp
            utilities/string_ops.cpp
            test/search/commons/test-graph-search.cpp test/search/commons/test-bfs.cpp)
    target_include_directories(testAima PRIVATE search search/commons utilities example test)
    add_test(NAME testAima COMMAND testAima)
endif (BUILD_TESTS)
