cmake_minimum_required(VERSION 3.5)

project(va_copy LANGUAGES C)

add_executable(va_copy main.c)

include(GNUInstallDirs)
install(TARGETS va_copy
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
