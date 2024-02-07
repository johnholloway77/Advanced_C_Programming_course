cmake_minimum_required(VERSION 3.5)

project(Heap_and_Stack_Memory_Allocation LANGUAGES C)

add_executable(Heap_and_Stack_Memory_Allocation main.c
    heapExample.c)

include(GNUInstallDirs)
install(TARGETS Heap_and_Stack_Memory_Allocation
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
