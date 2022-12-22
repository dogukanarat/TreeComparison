add_subdirectory(TreeLibrary)

include_directories(${CMAKE_CURRENT_LIST_DIR})

install(
    EXPORT Libraries-config
    NAMESPACE Libraries::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
