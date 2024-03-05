cmake_minimum_required(VERSION 3.5)

project(Challenge_Double_Pointers LANGUAGES C)

add_executable(Challenge_Double_Pointers main.c)

include(GNUInstallDirs)
install(TARGETS Challenge_Double_Pointers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
