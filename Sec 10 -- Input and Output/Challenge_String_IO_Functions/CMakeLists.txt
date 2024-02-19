cmake_minimum_required(VERSION 3.5)

project(Challenge_String_IO_Functions LANGUAGES C)

add_executable(Challenge_String_IO_Functions main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_String_IO_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
