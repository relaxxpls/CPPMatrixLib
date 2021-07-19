cmake_minimum_required(VERSION 3.10)
set(This Matrix)

project(${This} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

enable_testing()

include_directories(include/matrix)
include_directories(include/modint)
include_directories(include/polynomial)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(extern/googletest)