cmake_minimum_required(VERSION 3.5)

project(Bit_Operators_to_Pack_Data LANGUAGES C)

add_executable(Bit_Operators_to_Pack_Data main.c)

include(GNUInstallDirs)
install(TARGETS Bit_Operators_to_Pack_Data
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
