cmake_minimum_required(VERSION 3.5)

project(Predefined_Macros LANGUAGES C)

add_executable(Predefined_Macros main.c)

include(GNUInstallDirs)
install(TARGETS Predefined_Macros
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
