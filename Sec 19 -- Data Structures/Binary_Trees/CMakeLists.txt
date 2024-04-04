cmake_minimum_required(VERSION 3.5)

project(Binary_Trees LANGUAGES C)

add_executable(Binary_Trees main.c)

include(GNUInstallDirs)
install(TARGETS Binary_Trees
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
