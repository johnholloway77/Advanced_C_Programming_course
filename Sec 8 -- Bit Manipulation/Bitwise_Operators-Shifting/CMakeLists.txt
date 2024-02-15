cmake_minimum_required(VERSION 3.5)

project(Bitwise_Operators-Shifting LANGUAGES C)

add_executable(Bitwise_Operators-Shifting main.c)

target_link_libraries(Bitwise_Operators-Shifting m)

include(GNUInstallDirs)
install(TARGETS Bitwise_Operators-Shifting
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
