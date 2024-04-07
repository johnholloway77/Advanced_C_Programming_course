cmake_minimum_required(VERSION 3.5)

project(Passing_Arguments_and_Returning_Values LANGUAGES C)

add_executable(Passing_Arguments_and_Returning_Values main.c)

target_link_libraries(Passing_Arguments_and_Returning_Values pthread)

include(GNUInstallDirs)
install(TARGETS Passing_Arguments_and_Returning_Values
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
