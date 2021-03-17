project(emperor C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
cmake_minimum_required(VERSION 3.6)
include(cmake/3rdparty.cmake)

find_package(Boost)
#add_subdirectory(3rdparty/websocketpp)
add_subdirectory(src/emperor)
