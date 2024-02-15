cmake_minimum_required(VERSION 3.5)

project(Bitwise_Operators-logical LANGUAGES C)

add_executable(Bitwise_Operators-logical main.c)

target_link_libraries(Bitwise_Operators-logical m)

include(GNUInstallDirs)
install(TARGETS Bitwise_Operators-logical
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
