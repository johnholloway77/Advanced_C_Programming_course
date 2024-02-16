cmake_minimum_required(VERSION 3.5)

project(null_statement LANGUAGES C)

add_executable(null_statement main.c)

include(GNUInstallDirs)
install(TARGETS null_statement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
