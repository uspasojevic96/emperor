project(emperor CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
cmake_minimum_required(VERSION 3.6)

add_subdirectory(3rdparty/json)
add_subdirectory(src/discord)
add_subdirectory(src/emperor)
