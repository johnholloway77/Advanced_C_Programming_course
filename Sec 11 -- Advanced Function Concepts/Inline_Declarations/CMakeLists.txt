cmake_minimum_required(VERSION 3.5)

project(Inline_Declarations LANGUAGES C)

add_executable(Inline_Declarations main.c)

include(GNUInstallDirs)
install(TARGETS Inline_Declarations
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
