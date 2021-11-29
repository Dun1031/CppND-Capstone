cmake_minimum_required(VERSION 3.7)

project(CarVendor)
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

file(GLOB project_SRCS src/*.cpp)


add_executable(CarVendor ${project_SRCS})
