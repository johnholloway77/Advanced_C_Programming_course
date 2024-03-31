cmake_minimum_required(VERSION 3.5)

project(General_Utilities_1 LANGUAGES C)

add_executable(General_Utilities_1 main.c
)

include(GNUInstallDirs)
install(TARGETS General_Utilities_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
