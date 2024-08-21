cmake_minimum_required(VERSION 3.9.2)

project(enum)

set(MY_CMAKE_CXX_FLAGS "-std=c++11\
${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS ${MY_CMAKE_CXX_FLAGS})

add_executable(${PROJECT_NAME} main.cpp)

