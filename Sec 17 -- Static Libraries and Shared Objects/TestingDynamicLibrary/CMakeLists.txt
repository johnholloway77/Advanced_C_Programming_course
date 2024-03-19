cmake_minimum_required(VERSION 3.5)

project(TestingDynamicLibrary LANGUAGES C)

add_executable(TestingDynamicLibrary main.c)

include(GNUInstallDirs)
install(TARGETS TestingDynamicLibrary
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
