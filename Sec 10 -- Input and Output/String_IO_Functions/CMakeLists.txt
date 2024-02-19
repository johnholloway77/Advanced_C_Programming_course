cmake_minimum_required(VERSION 3.5)

project(String_IO_Functions LANGUAGES C)

add_executable(String_IO_Functions main.c)

include(GNUInstallDirs)
install(TARGETS String_IO_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
