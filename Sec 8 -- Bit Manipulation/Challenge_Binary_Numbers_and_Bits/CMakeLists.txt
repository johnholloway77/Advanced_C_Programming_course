cmake_minimum_required(VERSION 3.5)

project(Challenge_Binary_Numbers_and_Bits LANGUAGES C)

add_executable(Challenge_Binary_Numbers_and_Bits main.c)

target_link_libraries(Challenge_Binary_Numbers_and_Bits m)

include(GNUInstallDirs)
install(TARGETS Challenge_Binary_Numbers_and_Bits
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
