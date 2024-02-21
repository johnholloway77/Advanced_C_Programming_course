cmake_minimum_required(VERSION 3.5)

project(Challenge_Recursion LANGUAGES C)

add_executable(Challenge_Recursion main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Recursion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
