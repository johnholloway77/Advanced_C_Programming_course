cmake_minimum_required(VERSION 3.5)

project(Creating_Macros LANGUAGES C)

add_executable(Creating_Macros main.c)

include(GNUInstallDirs)
install(TARGETS Creating_Macros
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
