cmake_minimum_required(VERSION 3.5)

project(Variable_Length_Array LANGUAGES C)

add_executable(Variable_Length_Array main.c)

include(GNUInstallDirs)
install(TARGETS Variable_Length_Array
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
