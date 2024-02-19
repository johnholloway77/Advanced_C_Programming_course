cmake_minimum_required(VERSION 3.5)

project(Static LANGUAGES C)

add_executable(Static main.c
    foo.c)

include(GNUInstallDirs)
install(TARGETS Static
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
