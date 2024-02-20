cmake_minimum_required(VERSION 3.5)

project(log_mediator_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(log_mediator_cpp main.cpp
    fileoperator.h fileoperator.cpp)

include(GNUInstallDirs)
install(TARGETS log_mediator_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

