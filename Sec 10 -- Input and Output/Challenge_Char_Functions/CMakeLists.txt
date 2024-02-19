cmake_minimum_required(VERSION 3.5)

project(Challenge_Char_Functions LANGUAGES C)

add_executable(Challenge_Char_Functions main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Char_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
