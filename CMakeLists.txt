cmake_minimum_required(VERSION 3.16.3)

set(This CPPMatrixLib)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(Headers
	include/matrix/matrix.hpp
	include/matrix/matrix_utility.hpp
	include/polynomial/polynomial.hpp
	include/polynomial/polynomial_utility.hpp
)
set(Sources
	include/matrix/matrix_main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)
add_subdirectory(lib/googletest)