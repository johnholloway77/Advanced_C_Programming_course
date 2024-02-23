cmake_minimum_required(VERSION 3.5)

project(pragma_and_error LANGUAGES C)

add_executable(pragma_and_error main.c)

include(GNUInstallDirs)
install(TARGETS pragma_and_error
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
