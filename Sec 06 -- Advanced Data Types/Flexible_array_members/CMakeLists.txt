cmake_minimum_required(VERSION 3.5)

project(Flexible_array_members LANGUAGES C)

add_executable(Flexible_array_members main.c)

include(GNUInstallDirs)
install(TARGETS Flexible_array_members
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
