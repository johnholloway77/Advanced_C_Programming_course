cmake_minimum_required(VERSION 3.5)

project(Challenge LANGUAGES C)

add_executable(Challenge main.c)

include(GNUInstallDirs)
install(TARGETS Challenge
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
