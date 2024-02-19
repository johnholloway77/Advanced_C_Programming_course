cmake_minimum_required(VERSION 3.5)

project(Designated_initializers LANGUAGES C)

add_executable(Designated_initializers main.c)

include(GNUInstallDirs)
install(TARGETS Designated_initializers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
