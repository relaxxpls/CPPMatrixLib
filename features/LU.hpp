#ifndef _LU_H_
#define _LU_H_

#include "../matrix.hpp"
#include "../matrix_utility.hpp"
#include <tuple>

// LU decomposition on non singular square matrices
template<typename T>
std::tuple<matrix<T>, matrix<T>> lu(matrix<T> A) {
    size_t R = A.size().first, C = A.size().second;
    assert(R == C);

    for (size_t i = 0; i < R; i++) {
        if (A(i, i) == 0) {
            std::cerr << ("LU decomposition has failed");
            return std::make_tuple(zeros<T>(0, 0), zeros<T>(0, 0));
        }
        for (size_t j = i; j < R; j++) {
            A(j, i) /= A(i, i);
        }
        for (size_t j = i; j < R; j++) {
            A(j,j) -= A(j,i) * A(i,j);
        }
    }

    matrix<T> L = eye<T>(R), U = zeros<T>(R);
    std::cout << A << std::endl;
    for (size_t i = 0; i < R; i++) {
        for (size_t c = i; c < R; c++) {
            U(i, c) += A(i, c);
        }
    }
    for (size_t i = 0; i < R; i++) {
        for (size_t c = 0; c < i; c++) {
            L(i, c) += A(i, c);
        }
    }
    return std::make_tuple(L, U);
}

#endif