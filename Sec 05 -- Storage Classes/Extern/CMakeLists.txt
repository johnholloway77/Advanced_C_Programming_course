cmake_minimum_required(VERSION 3.5)

project(Extern LANGUAGES C)

add_executable(Extern main.c
    foo.c)

include(GNUInstallDirs)
install(TARGETS Extern
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
