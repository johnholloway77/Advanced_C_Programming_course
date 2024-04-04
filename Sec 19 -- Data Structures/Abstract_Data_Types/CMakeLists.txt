cmake_minimum_required(VERSION 3.5)

project(Abstract_Data_Types LANGUAGES C)

add_executable(Abstract_Data_Types main.c)

include(GNUInstallDirs)
install(TARGETS Abstract_Data_Types
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
