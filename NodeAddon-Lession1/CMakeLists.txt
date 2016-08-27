cmake_minimum_required(VERSION 3.5)
project(NodeAddone_Lession1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(NodeAddone_Lession1 ${SOURCE_FILES})