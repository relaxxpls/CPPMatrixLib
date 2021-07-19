set(BINARY ${CMAKE_PROJECT_NAME})

set(HEADER_LIST 
    "${PROJECT_SOURCE_DIR}/include/matrix/matrix.hpp"
    "${PROJECT_SOURCE_DIR}/include/matrix/matrix_utility.hpp"
    "${PROJECT_SOURCE_DIR}/include/modint/modint.hpp"
    "${PROJECT_SOURCE_DIR}/include/modint/modint_utility.hpp"
    "${PROJECT_SOURCE_DIR}/include/polynomial/polynomial.hpp"
    "${PROJECT_SOURCE_DIR}/include/polynomial/polynomial_utility.hpp"
)

set(SOURCES
    ${HEADER_LIST}
    main.cpp
    main_modint.cpp
)

add_executable(${BINARY}_run ${HEADER_LIST} main.cpp)

add_executable(Modint_run ${HEADER_LIST} main_modint.cpp)

add_library(${BINARY}_lib ${SOURCES})

target_include_directories(${BINARY}_lib PUBLIC ../include)

target_link_libraries(${BINARY}_lib)

target_compile_features(${BINARY}_lib PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)
