cmake_minimum_required(VERSION 3.5)

project(Challenge_3 LANGUAGES C)

add_executable(Challenge_3 main.c)

target_link_libraries(Challenge_3 pthread)

include(GNUInstallDirs)
install(TARGETS Challenge_3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
