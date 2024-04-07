cmake_minimum_required(VERSION 3.5)

project(Thread_Synchronization_Concepts LANGUAGES C)

add_executable(Thread_Synchronization_Concepts main.c)

include(GNUInstallDirs)
install(TARGETS Thread_Synchronization_Concepts
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
