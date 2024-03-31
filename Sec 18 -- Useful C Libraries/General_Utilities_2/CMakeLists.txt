cmake_minimum_required(VERSION 3.5)

project(General_Utilities_2 LANGUAGES C)

add_executable(General_Utilities_2 main.c)

include(GNUInstallDirs)
install(TARGETS General_Utilities_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
