cmake_minimum_required(VERSION 3.5)

project(Bitmasks LANGUAGES C)

add_executable(Bitmasks main.c)

include(GNUInstallDirs)
install(TARGETS Bitmasks
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
