cmake_minimum_required(VERSION 3.5)

project(Register LANGUAGES C)

add_executable(Register main.c
    foo.c)

include(GNUInstallDirs)
install(TARGETS Register
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
