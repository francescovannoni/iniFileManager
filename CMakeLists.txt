cmake_minimum_required(VERSION 3.12)
project(laboratorio)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES iniFileManager.cpp iniFileManager.h)
add_executable(laboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(laboratorio core)

