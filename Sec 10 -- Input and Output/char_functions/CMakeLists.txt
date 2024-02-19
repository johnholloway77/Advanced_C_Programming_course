cmake_minimum_required(VERSION 3.5)

project(char_functions LANGUAGES C)

add_executable(char_functions main.c)

include(GNUInstallDirs)
install(TARGETS char_functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
