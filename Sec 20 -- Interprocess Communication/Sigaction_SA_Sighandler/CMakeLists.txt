cmake_minimum_required(VERSION 3.5)

project(Sigaction LANGUAGES C)

add_executable(Sigaction main.c)

include(GNUInstallDirs)
install(TARGETS Sigaction
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
