cmake_minimum_required(VERSION 3.5)

project(Date_and_time LANGUAGES C)

add_executable(Date_and_time main.c)

include(GNUInstallDirs)
install(TARGETS Date_and_time
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
