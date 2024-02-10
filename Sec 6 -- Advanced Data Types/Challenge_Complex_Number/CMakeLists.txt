cmake_minimum_required(VERSION 3.5)

project(Challenge_Complex_Number LANGUAGES C)

add_executable(Challenge_Complex_Number main.c)

#link with math library
target_link_libraries(Challenge_Complex_Number m)

include(GNUInstallDirs)
install(TARGETS Challenge_Complex_Number
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
