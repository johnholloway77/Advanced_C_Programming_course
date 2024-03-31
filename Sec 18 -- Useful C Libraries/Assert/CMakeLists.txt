cmake_minimum_required(VERSION 3.5)

project(Assert LANGUAGES C)

add_executable(Assert main.c)

include(GNUInstallDirs)
install(TARGETS Assert
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
