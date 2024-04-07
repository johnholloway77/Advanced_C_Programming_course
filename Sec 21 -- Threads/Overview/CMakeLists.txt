cmake_minimum_required(VERSION 3.5)

project(Overview LANGUAGES C)

add_executable(Overview main.c)

include(GNUInstallDirs)
install(TARGETS Overview
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
