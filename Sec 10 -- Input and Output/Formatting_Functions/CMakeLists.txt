cmake_minimum_required(VERSION 3.5)

project(Formatting_Functions LANGUAGES C)

add_executable(Formatting_Functions main.c)

include(GNUInstallDirs)
install(TARGETS Formatting_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
