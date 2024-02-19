cmake_minimum_required(VERSION 3.5)

project(Challenge_Setting_and_Reading_bits LANGUAGES C)

add_executable(Challenge_Setting_and_Reading_bits main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Setting_and_Reading_bits
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
