cmake_minimum_required(VERSION 3.5)

project(Challenge_Dynamic_Library LANGUAGES C)

add_executable(Challenge_Dynamic_Library main.c
    StringFunctions.h
    StringFunctions.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Dynamic_Library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
