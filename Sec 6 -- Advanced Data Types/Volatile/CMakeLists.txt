cmake_minimum_required(VERSION 3.5)

project(Volatile LANGUAGES C)

add_executable(Volatile main.c)

include(GNUInstallDirs)
install(TARGETS Volatile
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
