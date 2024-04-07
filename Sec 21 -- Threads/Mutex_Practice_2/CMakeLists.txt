cmake_minimum_required(VERSION 3.5)

project(Mutex_Practice_2 LANGUAGES C)

add_executable(Mutex_Practice_2 main.c)

target_link_libraries(Mutex_Practice_2 pthread)

include(GNUInstallDirs)
install(TARGETS Mutex_Practice_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
