cmake_minimum_required(VERSION 3.5)

project(Preprocessor_Operations LANGUAGES C)

add_executable(Preprocessor_Operations main.c)

include(GNUInstallDirs)
install(TARGETS Preprocessor_Operations
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
