






add_library(search INTERFACE)
#target_sources(search INTERFACE ${CMAKE_SOURCE_DIR}/search/commons/graph_search.h)

target_include_directories(search
        INTERFACE
            ${CMAKE_SOURCE_DIR}/search/commons
            ${CMAKE_SOURCE_DIR}/search/uninformed_search
            ${CMAKE_SOURCE_DIR}/search/informed_search
            ${CMAKE_SOURCE_DIR}/dstruct)
