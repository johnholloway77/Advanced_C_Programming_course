cmake_minimum_required(VERSION 3.5)

project(AutoVariable LANGUAGES C)

add_executable(AutoVariable main.c)

include(GNUInstallDirs)
install(TARGETS AutoVariable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
