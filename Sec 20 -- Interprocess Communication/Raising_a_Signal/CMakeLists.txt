cmake_minimum_required(VERSION 3.5)

project(Raising_a_Signal LANGUAGES C)

add_executable(Raising_a_Signal main.c)

include(GNUInstallDirs)
install(TARGETS Raising_a_Signal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
