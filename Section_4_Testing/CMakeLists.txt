cmake_minimum_required(VERSION 3.5)

project(Testing LANGUAGES C)

add_executable(Testing main.c
    other.h
    other.c)

include(GNUInstallDirs)
install(TARGETS Testing
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
