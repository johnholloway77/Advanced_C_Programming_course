cmake_minimum_required(VERSION 3.5)

project(StaticFiles LANGUAGES C)

add_executable(StaticFiles main.c
    variables.h
    variables.c)

include(GNUInstallDirs)
install(TARGETS StaticFiles
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
