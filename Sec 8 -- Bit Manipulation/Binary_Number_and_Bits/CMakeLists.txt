cmake_minimum_required(VERSION 3.5)

project(Binary_Number_and_Bits LANGUAGES C)

add_executable(Binary_Number_and_Bits main.c)

include(GNUInstallDirs)
install(TARGETS Binary_Number_and_Bits
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
