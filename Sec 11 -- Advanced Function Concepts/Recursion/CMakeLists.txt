cmake_minimum_required(VERSION 3.5)

project(Recursion LANGUAGES C)

add_executable(Recursion main.c)

include(GNUInstallDirs)
install(TARGETS Recursion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
