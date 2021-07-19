set(This polynomial)

set(Headers
polynomial_test.hpp
)

set(Sources
	polynomial_test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	${CMAKE_PROJECT_NAME}_lib
)	
	
add_test(
	NAME ${This}
	COMMAND ${This}
)