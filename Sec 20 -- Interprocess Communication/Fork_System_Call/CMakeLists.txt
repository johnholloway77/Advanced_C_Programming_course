cmake_minimum_required(VERSION 3.5)

project(Fork_System_Call LANGUAGES C)

add_executable(Fork_System_Call main.c)

include(GNUInstallDirs)
install(TARGETS Fork_System_Call
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
