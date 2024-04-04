cmake_minimum_required(VERSION 3.5)

project(Intro_to_Interprocess_Communication LANGUAGES C)

add_executable(Intro_to_Interprocess_Communication main.c)

include(GNUInstallDirs)
install(TARGETS Intro_to_Interprocess_Communication
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
