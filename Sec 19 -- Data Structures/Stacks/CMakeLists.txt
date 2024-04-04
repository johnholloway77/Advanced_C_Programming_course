cmake_minimum_required(VERSION 3.5)

project(Stacks LANGUAGES C)

add_executable(Stacks main.c)

include(GNUInstallDirs)
install(TARGETS Stacks
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
