cmake_minimum_required(VERSION 3.5)

project(Mutex_Practice LANGUAGES C)

add_executable(Mutex_Practice main.c)
target_link_libraries(Mutex_Practice pthread)

include(GNUInstallDirs)
install(TARGETS Mutex_Practice
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
