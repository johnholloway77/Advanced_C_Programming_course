cmake_minimum_required(VERSION 3.5)

project(Queues_Array LANGUAGES C)

add_executable(Queues_Array main.c)

include(GNUInstallDirs)
install(TARGETS Queues_Array
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
