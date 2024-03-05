cmake_minimum_required(VERSION 3.5)

project(Function_Pointers LANGUAGES C)

add_executable(Function_Pointers main.c)

include(GNUInstallDirs)
install(TARGETS Function_Pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
