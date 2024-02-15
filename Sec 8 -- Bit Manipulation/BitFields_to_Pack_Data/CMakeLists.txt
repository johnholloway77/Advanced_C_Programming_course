cmake_minimum_required(VERSION 3.5)

project(BitFields_to_Pack_Data LANGUAGES C)

add_executable(BitFields_to_Pack_Data main.c)

include(GNUInstallDirs)
install(TARGETS BitFields_to_Pack_Data
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
