cmake_minimum_required(VERSION 3.16.3)

set(This ExecuteTests)

set(Headers
	MatrixTests.hpp
	PolyTests.hpp
)

set(Sources
	MatrixTests.cpp
	PolyTests.cpp
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
