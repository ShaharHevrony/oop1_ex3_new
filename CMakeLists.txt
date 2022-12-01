cmake_minimum_required(VERSION 3.23)
project(oop1_ex03_new)

set(CMAKE_CXX_STANDARD 14)
set (MY_AUTHORS "Shahar Hevrony")
include (cmake/CompilerSettings.cmake)

add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory (include)
add_subdirectory (src)

#add_subdirectory (test)
#add_subdirectory (external/catch2/src)


#oop1_ex03_new src/main.cpp src/zi.cpp src/vector.cpp include/vector.h include/zi.h
#test/vectorTests.cpp test/ziTests.cpp