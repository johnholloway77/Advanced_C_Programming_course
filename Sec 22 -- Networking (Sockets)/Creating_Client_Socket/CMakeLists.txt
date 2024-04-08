cmake_minimum_required(VERSION 3.5)

project(Creating_Client_Socket LANGUAGES C)

add_executable(Creating_Client_Socket main.c)

include(GNUInstallDirs)
install(TARGETS Creating_Client_Socket
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
