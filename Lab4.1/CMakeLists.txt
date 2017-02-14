cmake_minimum_required(VERSION 3.5)
project(Lab4_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PiCalculator.cpp PiCalculator.h)
add_executable(Lab4_1 ${SOURCE_FILES})