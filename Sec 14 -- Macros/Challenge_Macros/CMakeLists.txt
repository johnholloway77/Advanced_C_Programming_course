cmake_minimum_required(VERSION 3.5)

project(Challenge_Macros LANGUAGES C)

add_executable(Challenge_Macros main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Macros
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
