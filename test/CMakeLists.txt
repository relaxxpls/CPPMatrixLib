set(This ${CMAKE_PROJECT_NAME}_tests)

add_subdirectory(matrix)
add_subdirectory(polynomial)

set(Headers
	matrix/test1.hpp
	polynomial/test1.hpp
)

set(Sources
	matrix/MatrixTests.cpp
    modint/ModintTests.cpp
	polynomial/polynomial_test.cpp
    main.cpp
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