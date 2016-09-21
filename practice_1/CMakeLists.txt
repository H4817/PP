cmake_minimum_required(VERSION 3.3)
project(practice_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp ProcessMinors.cpp ProcessMinors.h ProcessMinorsWithThreads.cpp ProcessMinorsWithThreads.h)
add_executable(practice_1 ${SOURCE_FILES})