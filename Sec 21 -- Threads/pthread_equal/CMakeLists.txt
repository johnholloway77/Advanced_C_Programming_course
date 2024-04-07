cmake_minimum_required(VERSION 3.5)

project(pthread_equal LANGUAGES C)

add_executable(pthread_equal main.c)

include(GNUInstallDirs)
install(TARGETS pthread_equal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
