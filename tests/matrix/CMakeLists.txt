cmake_minimum_required(VERSION 3.16.3)

set(This matrix)

set(Headers
	test1.hpp
)

set(Sources
	test1.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	CPPMatrixLib
)	
	
add_test(
	NAME ${This}
	COMMAND ${This}
)