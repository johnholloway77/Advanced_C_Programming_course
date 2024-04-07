cmake_minimum_required(VERSION 3.5)

project(Passing_Multiple_args LANGUAGES C)

add_executable(Passing_Multiple_args main.c)

target_link_libraries(Passing_Multiple_args pthread)

include(GNUInstallDirs)
install(TARGETS Passing_Multiple_args
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
