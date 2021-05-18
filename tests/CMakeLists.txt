cmake_minimum_required(VERSION 3.14)
set(This Matrix)

project(${This} C CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

enable_testing()

add_subdirectory(googletest)

set(Headers

    ../matrix.hpp
    ../matrix_utility.hpp
)

add_library(${This} STATIC ${Headers})

add_subdirectory(test)

set_target_properties(${This} PROPERTIES LINKER_LANGUAGE CXX)