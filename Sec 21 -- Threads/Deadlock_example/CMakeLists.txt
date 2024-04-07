cmake_minimum_required(VERSION 3.5)

project(Deadlock_example LANGUAGES C)

add_executable(Deadlock_example main.c)
target_link_libraries(Deadlock_example pthread)


include(GNUInstallDirs)
install(TARGETS Deadlock_example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
