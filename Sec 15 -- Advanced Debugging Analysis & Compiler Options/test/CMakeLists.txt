cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES C)

add_executable(test main.c)

include(GNUInstallDirs)
install(TARGETS test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
