cmake_minimum_required(VERSION 3.5)

project(Core_files LANGUAGES C)

add_executable(Core_files main.c
)

include(GNUInstallDirs)
install(TARGETS Core_files
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
