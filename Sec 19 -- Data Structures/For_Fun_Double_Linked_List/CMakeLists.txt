cmake_minimum_required(VERSION 3.5)

project(For_Fun_Double_Linked_List LANGUAGES C)

add_executable(For_Fun_Double_Linked_List main.c)

include(GNUInstallDirs)
install(TARGETS For_Fun_Double_Linked_List
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
