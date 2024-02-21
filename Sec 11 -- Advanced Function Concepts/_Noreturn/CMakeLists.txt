cmake_minimum_required(VERSION 3.5)

project(_Noreturn LANGUAGES C)

add_executable(_Noreturn main.c)

include(GNUInstallDirs)
install(TARGETS _Noreturn
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
