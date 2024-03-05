cmake_minimum_required(VERSION 3.5)

project(Double_Pointers_Part_1 LANGUAGES C)

add_executable(Double_Pointers_Part_1 main.c)

include(GNUInstallDirs)
install(TARGETS Double_Pointers_Part_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
