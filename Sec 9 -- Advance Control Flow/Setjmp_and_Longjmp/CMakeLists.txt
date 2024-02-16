cmake_minimum_required(VERSION 3.5)

project(Setjmp_and_Longjmp LANGUAGES C)

add_executable(Setjmp_and_Longjmp main.c)

include(GNUInstallDirs)
install(TARGETS Setjmp_and_Longjmp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
