cmake_minimum_required(VERSION 3.5)

project(Challenge_Server1 LANGUAGES C)

add_executable(Challenge_Server1 main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Server1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
