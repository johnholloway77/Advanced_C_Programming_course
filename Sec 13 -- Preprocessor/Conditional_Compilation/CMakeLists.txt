cmake_minimum_required(VERSION 3.5)

project(Conditional_Compilation LANGUAGES C)

add_executable(Conditional_Compilation main.c)

include(GNUInstallDirs)
install(TARGETS Conditional_Compilation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
