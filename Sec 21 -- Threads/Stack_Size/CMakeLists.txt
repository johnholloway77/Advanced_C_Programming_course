cmake_minimum_required(VERSION 3.5)

project(Stack_Size LANGUAGES C)

add_executable(Stack_Size main.c)

target_link_libraries(Stack_Size pthread)

include(GNUInstallDirs)
install(TARGETS Stack_Size
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
