cmake_minimum_required(VERSION 3.16.3)

set(This tests)

add_subdirectory(matrix_tests)
add_subdirectory(polynomial_tests)

set(Headers
	matrix_tests/matrix_tests.hpp
	polynomial_tests/polynomial_tests.hpp
)

set(Sources
	matrix_tests/matrix_tests.cpp
	polynomial_tests/polynomial_tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	src
)	
	
add_test(
	NAME ${This}
	COMMAND ${This}
)
