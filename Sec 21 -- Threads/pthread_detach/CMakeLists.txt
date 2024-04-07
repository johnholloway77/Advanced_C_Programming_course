cmake_minimum_required(VERSION 3.5)

project(pthread_detach LANGUAGES C)

add_executable(pthread_detach main.c)

target_link_libraries(pthread_detach pthread)exit

include(GNUInstallDirs)
install(TARGETS pthread_detach
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
