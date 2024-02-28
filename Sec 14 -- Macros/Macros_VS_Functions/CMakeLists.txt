cmake_minimum_required(VERSION 3.5)

project(Macros_VS_Functions LANGUAGES C)

add_executable(Macros_VS_Functions main.c)

include(GNUInstallDirs)
install(TARGETS Macros_VS_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
