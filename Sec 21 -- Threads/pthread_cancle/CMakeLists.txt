cmake_minimum_required(VERSION 3.5)

project(pthread_cancle LANGUAGES C)

add_executable(pthread_cancle main.c)

target_link_libraries(pthread_cancle pthread)

include(GNUInstallDirs)
install(TARGETS pthread_cancle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
