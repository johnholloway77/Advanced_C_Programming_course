cmake_minimum_required(VERSION 3.5)

project(restrict LANGUAGES C)

add_executable(restrict main.c)

include(GNUInstallDirs)
install(TARGETS restrict
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
