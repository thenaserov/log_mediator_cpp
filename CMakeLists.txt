# CMakeList.txt : CMake project for Practice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
Project(LogMediatorCpp)
# Add source to this project's executable.
add_subdirectory(curl)
add_executable (LogMediatorCpp "main.cpp"							   
"FileOperator.h"							   
"FileOperator.cpp"							   
"Controller.h"							   
"Controller.cpp"							   
"LogGenerator.h"							   
"LogGenerator.cpp"							   
"HeartBeat.h"							   
"HeartBeat.cpp" "Structs.h")
# TODO: Add tests and install targets if needed.
target_link_libraries(LogMediatorCpp libcurl)
