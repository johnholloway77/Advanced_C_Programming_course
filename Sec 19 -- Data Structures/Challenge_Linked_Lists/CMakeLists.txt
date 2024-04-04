cmake_minimum_required(VERSION 3.5)

project(Challenge_Linked_Lists LANGUAGES C)

add_executable(Challenge_Linked_Lists main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Linked_Lists
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
