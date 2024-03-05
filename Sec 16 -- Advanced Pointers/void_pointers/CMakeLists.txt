cmake_minimum_required(VERSION 3.5)

project(void_pointers LANGUAGES C)

add_executable(void_pointers main.c)

include(GNUInstallDirs)
install(TARGETS void_pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
