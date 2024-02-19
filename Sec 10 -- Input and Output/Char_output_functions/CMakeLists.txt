cmake_minimum_required(VERSION 3.5)

project(Char_output_functions LANGUAGES C)

add_executable(Char_output_functions main.c
    test.txt)

include(GNUInstallDirs)
install(TARGETS Char_output_functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
