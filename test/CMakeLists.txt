cmake_minimum_required(VERSION 3.12)
project(test)

add_subdirectory(/home/frenk/CLionProjects/laboratorio/test/lib/googletest-master)
set(gtest_SOURCE_DIR, /home/frenk/CLionProjects/laboratorio/test/lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(SOURCE_FILES test.cpp)
add_executable(test ${SOURCE_FILES})
target_link_libraries(test ${GTEST_BOTH_LIBRARIES} core)