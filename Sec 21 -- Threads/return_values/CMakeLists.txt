cmake_minimum_required(VERSION 3.5)

project(return_values LANGUAGES C)

add_executable(return_values main.c)

target_link_libraries(return_values pthread)

include(GNUInstallDirs)
install(TARGETS return_values
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
