cmake_minimum_required(VERSION 3.5)

project(Challenge_Client1 LANGUAGES C)

add_executable(Challenge_Client1 main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Client1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
