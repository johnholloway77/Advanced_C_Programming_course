cmake_minimum_required(VERSION 3.5)

project(Creating_Server_Socket LANGUAGES C)

add_executable(Creating_Server_Socket main.c)

include(GNUInstallDirs)
install(TARGETS Creating_Server_Socket
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
