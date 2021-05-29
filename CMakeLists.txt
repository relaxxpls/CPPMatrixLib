cmake_minimum_required(VERSION 3.16.3)

set(This src)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
	matrix.hpp
	matrix_utility.hpp
)
set(Sources
	main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(Tests)
