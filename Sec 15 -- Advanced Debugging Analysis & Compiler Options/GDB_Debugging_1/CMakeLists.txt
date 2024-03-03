cmake_minimum_required(VERSION 3.5)

project(GDB_Debugging_1 LANGUAGES C)

add_executable(GDB_Debugging_1 main.c)

include(GNUInstallDirs)
install(TARGETS GDB_Debugging_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
