cmake_minimum_required(VERSION 3.9.2)

project(enum)

FILE(GLOB CPP_SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

set(MY_CMAKE_CXX_FLAGS "-std=c++11 -g -save-temps \
${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS ${MY_CMAKE_CXX_FLAGS})

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

