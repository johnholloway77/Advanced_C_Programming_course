cmake_minimum_required(VERSION 3.5)

project(Challenge_Flexible_array_member LANGUAGES C)

add_executable(Challenge_Flexible_array_member main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Flexible_array_member
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
