cmake_minimum_required(VERSION 3.5)

project(queues LANGUAGES C)

add_executable(queues main.c)

include(GNUInstallDirs)
install(TARGETS queues
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
