cmake_minimum_required(VERSION 3.5)

project(comma_operator LANGUAGES C)

add_executable(comma_operator main.c)

include(GNUInstallDirs)
install(TARGETS comma_operator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
