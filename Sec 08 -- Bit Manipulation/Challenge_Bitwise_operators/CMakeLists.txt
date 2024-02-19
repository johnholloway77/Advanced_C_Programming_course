cmake_minimum_required(VERSION 3.5)

project(Challenge_Bitwise_operators LANGUAGES C)

add_executable(Challenge_Bitwise_operators main.c)

find_package(Curses REQUIRED)
target_link_libraries(Challenge_Bitwise_operators PRIVATE ${CURSES_LIBRARIES} m)

include(GNUInstallDirs)
install(TARGETS Challenge_Bitwise_operators
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
