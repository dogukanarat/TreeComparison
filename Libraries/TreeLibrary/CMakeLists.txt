include(${CMAKE_DIR}/Libraries.cmake)

add_library(
    TreeLibrary
)

target_sources(
    TreeLibrary
    PRIVATE
        Common.c
        AvlTree.c
        SplayTree.c
)

target_include_directories(
    TreeLibrary 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS TreeLibrary
    EXPORT Libraries-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/TreeLibrary
    FILES_MATCHING PATTERN "*.h"
)
