add_subdirectory(TreeComparisonDemo)

install(
    EXPORT Applications-config
    NAMESPACE Application::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
