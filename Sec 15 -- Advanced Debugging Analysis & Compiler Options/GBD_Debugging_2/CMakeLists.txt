cmake_minimum_required(VERSION 3.5)

project(GBD_Debugging_2 LANGUAGES C)

add_executable(GBD_Debugging_2 main.c)

include(GNUInstallDirs)
install(TARGETS GBD_Debugging_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
