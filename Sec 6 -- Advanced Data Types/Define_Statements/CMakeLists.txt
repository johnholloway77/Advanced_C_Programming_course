cmake_minimum_required(VERSION 3.5)

project(Define_Statements LANGUAGES C)

add_executable(Define_Statements main.c)

include(GNUInstallDirs)
install(TARGETS Define_Statements
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
