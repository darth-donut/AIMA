cmake_minimum_required(VERSION 3.9)
project(aima)

set(CMAKE_CXX_STANDARD 14)


# include the aima::search library
add_subdirectory(search)

# make 'utilities' a shared lib
add_library(util SHARED ${CMAKE_SOURCE_DIR}/utilities/string_ops.cpp)
target_include_directories(util PRIVATE ${CMAKE_SOURCE_DIR}/utilities)


# make 'dstruct' an interface library
add_library(data_structure INTERFACE)
#target_sources(data_structure INTERFACE ${CMAKE_SOURCE_DIR}/dstruct/priority_queue.h)
target_include_directories(data_structure INTERFACE ${CMAKE_SOURCE_DIR}/dstruct)


# make 'example' a shared library
add_library(example SHARED ${CMAKE_SOURCE_DIR}/example/romania.cpp)
target_include_directories(example
        PRIVATE
            ${CMAKE_SOURCE_DIR}/utilities
        INTERFACE
            ${CMAKE_SOURCE_DIR}/search/commons
        PUBLIC
            ${CMAKE_SOURCE_DIR}/example)
target_link_libraries(example util search)


#####################
### Catch2 Test cases
#####################
option(BUILD_TESTS "Create test targets" ON)
if (BUILD_TESTS)

    ### setup testing playground

    include(CTest)
    add_library(Catch INTERFACE)
    target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/test)
    ### end of: setup testing playground


    ### setup util tests
    add_executable(utilTest test/main-test.cpp test/utilities/test-util-string_ops.cpp)
    target_link_libraries(utilTest Catch util)
    target_include_directories(utilTest PRIVATE utilities test)
    ### end of: setup util tests


    ### setup search tests
    add_executable(searchTest
            test/main-test.cpp
            test/search/commons/test-tree-search.cpp
            test/search/commons/test-graph-search.cpp
            test/search/commons/test-bfs.cpp
            test/search/uninformed_search/test-uniform_search.cpp
            test/search/uninformed_search/test-greedy_best_first.cpp
            test/search/uninformed_search/test-A_star_search.cpp)

    target_link_libraries(searchTest Catch example search)
    target_include_directories(searchTest
            PRIVATE
                search
                search/commons
                utilities
                search/uninformed_search
                example
                test
    )
    ### end of: setup search tests


    ### setup data structure tests
    add_executable(dataStructureTest
            test/main-test.cpp
            test/dstruct/test-priority_queue.cpp)
    target_link_libraries(dataStructureTest data_structure Catch)
    target_include_directories(dataStructureTest
            PRIVATE
                dstruct
                test
    )
    ### end of: setup data structure tests


    # manually add all tests here
    add_test(NAME search_test COMMAND searchTest)
    add_test(NAME util_test COMMAND utilTest)
    add_test(NAME data_structure_test COMMAND dataStructureTest)

endif (BUILD_TESTS)
