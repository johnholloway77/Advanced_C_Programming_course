cmake_minimum_required(VERSION 3.5)

project(Challenge_2 LANGUAGES C)

add_executable(Challenge_2 main.c)
target_link_libraries(Challenge_2 pthread)

include(GNUInstallDirs)
install(TARGETS Challenge_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
