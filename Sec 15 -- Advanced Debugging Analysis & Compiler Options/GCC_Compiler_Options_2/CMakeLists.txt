cmake_minimum_required(VERSION 3.5)

project(GCC_Comiler_Options_2 LANGUAGES C)

add_executable(GCC_Comiler_Options_2 main.c)

include(GNUInstallDirs)
install(TARGETS GCC_Comiler_Options_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
