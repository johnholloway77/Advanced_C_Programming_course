cmake_minimum_required(VERSION 3.5)

project(Linked_List LANGUAGES C)

add_executable(Linked_List main.c)

include(GNUInstallDirs)
install(TARGETS Linked_List
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
