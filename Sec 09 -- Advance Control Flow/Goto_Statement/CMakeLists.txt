cmake_minimum_required(VERSION 3.5)

project(Goto_Statement LANGUAGES C)

add_executable(Goto_Statement main.c)

include(GNUInstallDirs)
install(TARGETS Goto_Statement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
