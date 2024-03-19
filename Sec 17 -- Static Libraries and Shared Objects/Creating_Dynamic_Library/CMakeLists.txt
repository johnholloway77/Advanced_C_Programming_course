cmake_minimum_required(VERSION 3.5)

project(Creating_Dynamic_Library LANGUAGES C)

add_executable(Creating_Dynamic_Library main.c
    myLib.h)

include(GNUInstallDirs)
install(TARGETS Creating_Dynamic_Library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
