cmake_minimum_required(VERSION 3.5)
project(pp2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp Bank.h Bank.cpp BankClient.h BankClient.cpp definitions.h)
add_executable(pp2 ${SOURCE_FILES})

