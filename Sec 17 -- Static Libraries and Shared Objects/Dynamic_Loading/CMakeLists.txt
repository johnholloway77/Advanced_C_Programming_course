cmake_minimum_required(VERSION 3.5)

project(Dynamic_Loading LANGUAGES C)

add_executable(Dynamic_Loading main.c)

include(GNUInstallDirs)
install(TARGETS Dynamic_Loading
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
