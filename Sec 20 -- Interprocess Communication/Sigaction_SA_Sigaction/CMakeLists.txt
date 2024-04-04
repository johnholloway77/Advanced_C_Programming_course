cmake_minimum_required(VERSION 3.5)

project(Sigaction_SA_Sigaction LANGUAGES C)

add_executable(Sigaction_SA_Sigaction main.c)

include(GNUInstallDirs)
install(TARGETS Sigaction_SA_Sigaction
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
