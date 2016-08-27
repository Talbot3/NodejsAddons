cmake_minimum_required(VERSION 3.5)
project(NodeCHello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Hello.cpp)
add_executable(NodeCHello ${SOURCE_FILES})