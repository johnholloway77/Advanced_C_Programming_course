cmake_minimum_required(VERSION 3.5)

project(Challenge_Unions LANGUAGES C)

add_executable(Challenge_Unions main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Unions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
