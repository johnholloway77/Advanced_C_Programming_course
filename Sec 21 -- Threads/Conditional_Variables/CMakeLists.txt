cmake_minimum_required(VERSION 3.5)

project(Conditional_Variables LANGUAGES C)

add_executable(Conditional_Variables main.c)
target_link_libraries(Conditional_Variables pthread)

include(GNUInstallDirs)
install(TARGETS Conditional_Variables
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
