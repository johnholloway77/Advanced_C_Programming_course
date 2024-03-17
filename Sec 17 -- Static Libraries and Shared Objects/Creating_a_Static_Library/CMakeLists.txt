cmake_minimum_required(VERSION 3.5)

project(Creating_a_Static_Library LANGUAGES C)

add_executable(Creating_a_Static_Library main.c)

target_link_libraries(libmyLib ../libmyLib.so)

include(GNUInstallDirs)
install(TARGETS Creating_a_Static_Library
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
