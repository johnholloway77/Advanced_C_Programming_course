cmake_minimum_required(VERSION 3.5)

project(Common_Thread_Functions LANGUAGES C)

add_executable(Common_Thread_Functions main.c)
target_link_libraries(Common_Thread_Functions pthread)


include(GNUInstallDirs)
install(TARGETS Common_Thread_Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
