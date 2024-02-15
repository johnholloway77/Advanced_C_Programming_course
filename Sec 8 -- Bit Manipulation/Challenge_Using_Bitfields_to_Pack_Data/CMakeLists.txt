cmake_minimum_required(VERSION 3.5)

project(Challenge_Using_Bitfields_to_Pack_Data LANGUAGES C)

add_executable(Challenge_Using_Bitfields_to_Pack_Data main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Using_Bitfields_to_Pack_Data
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
