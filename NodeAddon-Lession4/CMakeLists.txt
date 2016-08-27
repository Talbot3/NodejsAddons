cmake_minimum_required(VERSION 3.5)
project(NodeAddone_Lession4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES object_factory.cpp function_factory.cpp function_return.cpp.cpp oop_demo/CustomObject.cpp oop_demo/CustomObject.h oop_demo/object_bind.cpp oop_demo_factory/addon.cpp oop_demo_factory/myobject.h oop_demo_factory/myobject.cpp oop_demo_factory/Add.cpp oop_demo_factory/Add.h oop_demo_factory/add_bind.cpp oop_demo_passing_wrap/AddObj.cpp oop_demo_passing_wrap/AddObj.h oop_demo_passing_wrap/bind_add_obj.cpp add_function_async.cpp json_handle.cpp)
add_executable(NodeAddone_Lession4 ${SOURCE_FILES})