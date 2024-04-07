cmake_minimum_required(VERSION 3.5)

project(Creating_Threads LANGUAGES C)

add_executable(Creating_Threads main.c)

target_link_libraries(Creating_Threads pthread)

include(GNUInstallDirs)
install(TARGETS Creating_Threads
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
