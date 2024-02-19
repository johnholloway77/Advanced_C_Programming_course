cmake_minimum_required(VERSION 3.5)

project(Const LANGUAGES C)

add_executable(Const main.c)

include(GNUInstallDirs)
install(TARGETS Const
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
