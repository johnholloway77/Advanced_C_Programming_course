cmake_minimum_required(VERSION 3.5)

project(Debugging_With_Preprocessor LANGUAGES C)

add_executable(Debugging_With_Preprocessor main.c)

include(GNUInstallDirs)
install(TARGETS Debugging_With_Preprocessor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
