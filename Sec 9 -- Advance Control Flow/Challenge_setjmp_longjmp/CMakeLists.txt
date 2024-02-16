cmake_minimum_required(VERSION 3.5)

project(Challenge_setjmp_longjmp LANGUAGES C)

add_executable(Challenge_setjmp_longjmp main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_setjmp_longjmp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
