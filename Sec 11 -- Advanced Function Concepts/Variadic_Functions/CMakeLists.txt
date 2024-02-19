cmake_minimum_required(VERSION 3.5)

project(Variadic_Functions LANGUAGES C)

add_executable(Variadic_Functions main.c)

include(GNUInstallDirs)
install(TARGETS Variadic_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
