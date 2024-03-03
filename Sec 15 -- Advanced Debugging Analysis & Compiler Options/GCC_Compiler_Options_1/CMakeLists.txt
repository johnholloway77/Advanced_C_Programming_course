cmake_minimum_required(VERSION 3.5)

project(GCC_Compiler_Options_1 LANGUAGES C)

add_executable(GCC_Compiler_Options_1 main.c)

include(GNUInstallDirs)
install(TARGETS GCC_Compiler_Options_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
