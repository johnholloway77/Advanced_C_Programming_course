cmake_minimum_required(VERSION 3.5)

project(Challenge_Variable_Length_Arrays LANGUAGES C)

add_executable(Challenge_Variable_Length_Arrays main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Variable_Length_Arrays
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
