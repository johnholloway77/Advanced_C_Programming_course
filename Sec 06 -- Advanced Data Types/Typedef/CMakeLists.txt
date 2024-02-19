cmake_minimum_required(VERSION 3.5)

project(Typedef LANGUAGES C)

add_executable(Typedef main.c)

include(GNUInstallDirs)
install(TARGETS Typedef
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
