cmake_minimum_required(VERSION 3.16.3)

set(This polynomial_tests)

set(Headers
	polynomial_tests.hpp
)

set(Sources
	polynomial_tests.cpp
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