include(${CMAKE_DIR}/Applications.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    TreeComparisonDemo
)

target_link_libraries(
    TreeComparisonDemo
    PRIVATE
        TreeLibrary
)

target_sources(
    TreeComparisonDemo 
    PRIVATE
        Main.c
        ${CUSTOM_HEADER}
)

install(
    TARGETS TreeComparisonDemo
    EXPORT Applications-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})


