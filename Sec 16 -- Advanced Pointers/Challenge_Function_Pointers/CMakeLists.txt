cmake_minimum_required(VERSION 3.5)

project(Challenge_Function_Pointers LANGUAGES C)

add_executable(Challenge_Function_Pointers main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Function_Pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
