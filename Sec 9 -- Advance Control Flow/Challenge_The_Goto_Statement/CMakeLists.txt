cmake_minimum_required(VERSION 3.5)

project(Challenge_The_Goto_Statement LANGUAGES C)

add_executable(Challenge_The_Goto_Statement main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_The_Goto_Statement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
