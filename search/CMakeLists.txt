####################################
## setup util as a "header-only-lib"
####################################
# set(UTIL_SRC ../utilities)
# add_library(util INTERFACE)
# target_include_directories(util INTERFACE ${UTIL_SRC})


add_library(search SHARED
        commons/tree_search.h
        commons/problem.h
        commons/tree_search.cpp
        commons/graph_search.cpp
        commons/graph_search.h
        )

target_include_directories(search PRIVATE utilities)
