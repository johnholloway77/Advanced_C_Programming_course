cmake_minimum_required(VERSION 3.5)

project(fork2 LANGUAGES C)

add_executable(fork2 main.c)

include(GNUInstallDirs)
install(TARGETS fork2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
