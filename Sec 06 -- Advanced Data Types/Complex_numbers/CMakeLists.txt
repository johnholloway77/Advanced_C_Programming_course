cmake_minimum_required(VERSION 3.5)

project(Complex_numbers LANGUAGES C)

add_executable(Complex_numbers main.c)

include(GNUInstallDirs)
install(TARGETS Complex_numbers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
