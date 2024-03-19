cmake_minimum_required(VERSION 3.5)

project(Challenge_Dynamic_Loading LANGUAGES C)

add_executable(Challenge_Dynamic_Loading main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Dynamic_Loading
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
