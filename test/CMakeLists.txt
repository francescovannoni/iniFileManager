cmake_minimum_required(VERSION 3.12)
project(test)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(/home/frenk/CLionProjects/laboratorio/test/lib/googletest)
set(gtest_SOURCE_DIR, /home/frenk/CLionProjects/laboratorio/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(SOURCE_FILES test.cpp)
add_executable(test runAllTest.cpp ${SOURCE_FILES})
target_link_libraries(test gtest gtest_main core)