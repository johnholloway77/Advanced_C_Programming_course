cmake_minimum_required(VERSION 3.5)

project(Challenge_1 LANGUAGES C)

add_executable(Challenge_1 main.c)

target_link_libraries(Challenge_1 pthread)

include(GNUInstallDirs)
install(TARGETS Challenge_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
