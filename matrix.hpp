#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <cmath>
#include <climits>

/**
 *  Operations:
 *  1 Matrix(A), 1 Scalar(b): A+I*b, A-I*b, A*b
 *  2 Matrices(A, B): A+B, A-B, A*B
 */

struct range {
    size_t l, r, len;
    range(size_t l, size_t r) : l(l), r(r), len(r-l+1) {
        assert(0<=l && l<=r);
    }
};

template <typename T>
class matrix {
public:
    matrix(size_t r, size_t c, T x) : R(r), C(c) {
        M.assign(R, std::vector<T>(C, x));
    }
    matrix(const std::initializer_list<std::vector<T>> m) : M(m) {
        R = M.size(), C = R > 0 ? M[0].size() : 0;
    }

    bool empty() const {
        return R*C == 0;
    }
    std::pair<size_t, size_t> size() {
        return std::make_pair(R, C);
    }
    matrix t() {
        matrix res(C, R, 0);
        for(size_t r=0; r<R; r++) {
            for(size_t c=0; c<C; c++) {
                res(c, r) += M[r][c];
            }
        }
        return res;
    }

    matrix operator+=(const matrix &rhs) {
        assert(R == rhs.R && C == rhs.C);
        for(size_t r=0; r<R; r++) {
            for(size_t c=0; c<C; c++) {
                M[r][c] += rhs(r, c);
            }
        }
        return *this;
    }
    matrix operator-=(const matrix &rhs) {
        assert(R == rhs.R && C == rhs.C);
        for(size_t r=0; r<R; r++) {
            for(size_t c=0; c<C; c++) {
                M[r][c] -= rhs(r, c);
            }
        }
        return *this;
    }
    matrix operator*=(const matrix &rhs) {
        assert(C == rhs.R);
        matrix res(R, rhs.C, 0);
        for(size_t r=0; r<res.R; r++) {
            for(size_t c=0; c<res.C; c++) {
                for(size_t i=0; i<C; i++) {
                    res(r, c) += M[r][i] * rhs(i, c);
                }
            }
        }
        return res;
    }
    matrix operator+(const matrix &rhs) const {
        return matrix(*this) += rhs;
    }
    matrix operator-(const matrix &rhs) const {
        return matrix(*this) -= rhs;
    }
    matrix operator*(const matrix &rhs) const {
        return matrix(*this) *= rhs;
    }
    matrix operator*=(const T &rhs) {
        for(size_t r=0; r<R; r++) {
            for(size_t c=0; c<C; c++) {
                M[r][c] *= rhs;
            }
        }
        return *this;
    }
    matrix operator*(const T &rhs) const {
        return matrix(*this) *= rhs;
    }
    matrix operator-() const {
        return matrix(R, C, 0) - *this;
    }

    bool operator==(const matrix &rhs) const {
        if(R != rhs.R || C != rhs.C) return false;
        for(size_t r=0; r<R; r++) {
            for(size_t c=0; c<C; c++) {
                if(M[r][c] != rhs(r, c)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const matrix &rhs) const {
        return !(*this == rhs);
    }

    matrix operator+=(const T &rhs);
    matrix operator-=(const T &rhs);
    matrix operator+(const T &rhs) const;
    matrix operator-(const T &rhs) const;

    // Element Numbering (0 based, Column  Major):
    //    C 0  1  2   3
    //  R
    //  0   0  3  6   9
    //  1   1  4  7  10
    //  2   2  5  8  11
    T& operator[](size_t i) {
        return M[i % R][i / R];
    }
    T& operator()(size_t r, size_t c) {
        assert(0 <= r && r < R && 0 <= c && c < C);
        return M[r][c];
    }
    T operator()(size_t r, size_t c) const {
        assert(0 <= r && r < R && 0 <= c && c < C);
        return M[r][c];
    }
    matrix operator()(const range &row_range, const range &col_range) const {
        assert(row_range.r < R && col_range.r < C);
        matrix<T> res(row_range.len, col_range.len, 0);
        for (size_t r = 0; r < row_range.len; r++) {
            for (size_t c = 0; c < col_range.len; c++)
                res(r, c) = M[row_range.l + r][col_range.l + c];
        }
        return res;
    }

    template <typename U>
    friend matrix<U> pow(matrix<U> m, int n);

    // To permit: 5*M, without this only M*5 is permitted
    template <typename U>
    friend matrix<U> operator*(const U &lhs, const matrix<U> &rhs);

private:
    size_t R, C;
    std::vector<std::vector<T>> M;
};

template <typename U>
matrix<U> operator*(const U &lhs, const matrix<U> &rhs) {
    return rhs * lhs;
}

template <typename T>
std::ostream& operator<<(std::ostream &cout, matrix<T> m) {
    size_t R = m.size().first, C = m.size().second;
    for(size_t r = 0; r < R; r++) {
        std::cout << "[";
        for(size_t c = 0; c < C; c++) {
            cout << m(r, c);
            if (c+1 != C) {
                cout << " ";
            }
            else {
                cout << "]" << std::endl;
            }
        }
    }
    return cout;
}

// Zero/null matrix of size r*c
template <typename T>
matrix<T> zeros(size_t r, size_t c) {
    return matrix<T>(r, c, 0);
}

// Identity matrix of size r*r
template<typename T>
matrix<T> eye(size_t r) {
    matrix<T> res(r, r, 0);
    for(size_t i=0; i<r; i++) {
        res(i, i) = 1;
    }
    return res;
}

template<typename T>
matrix<T> pow(matrix<T> m, int n) {
    assert(m.R == m.C && n >= 0);
    if(n == 0) {
        return eye<T>(m.R);
    }
    matrix<T> res = m;
    for(int i=n; i>0; i>>=1) {
        res = (i&1) ? res*m : res;
        m *= m;
    }
    return res;
}

// Norm of matrix m
// Options available:
// L1: Manhatten Norm
// L2: Eucledian Norm (under development)
// LF: Frobenius Norm
// Linf: Maximum Norm
template<typename T>
double norm(matrix<T> m, std::string NORM = "LF") {
    double res = 0;
    size_t R = m.size().first, C = m.size().second;
    if (NORM == "L1") {
        for(size_t c = 0; c < C; c++) {
            double cur = 0;
            for(size_t r = 0; r < R; r++) {
                cur += abs(m(r, c));
            }
            res = std::max(res, cur);
        }
    }
    else if (NORM == "LF"){
        for(size_t r = 0; r < R; r++) {
            for(size_t c = 0; c < C; c++) {
                res += m(r, c) * m(r, c);
            }
        }
        res = sqrt(res);
    }
    else if (NORM == "Linf") {
        for(size_t r = 0; r < R; r++) {
            double cur = 0;
            for(size_t c = 0; c < C; c++) {
                cur += abs(m(r, c));
            }
            res = std::max(res, cur);
        }
    }
    else {
        assert(false);
    }
    return res;
}

// MaxVal - MinVal over axis
// axis 1: range of each column
// axis 2: range of each row
template<typename T>
std::vector<T> range(matrix<T> m, int axis = 1) {
    assert(axis == 1 || axis == 2);
    size_t R = m.size().first, C = m.size().second;
    std::vector<T> res(axis == 1 ? C : R);

    if(axis == 1) {
        for(size_t c = 0; c < C; c++) {
            T mnVal = std::numeric_limits<T>::max();
            T mxVal = std::numeric_limits<T>::lowest();
            for(size_t r = 0; r < R; r++) {
                mnVal = std::min(mnVal, m(r, c));
                mxVal = std::max(mxVal, m(r, c));
            }
            res[c] = mxVal - mnVal;
        }
    }
    else {
        for(size_t r = 0; r < R; r++) {
            T mnVal = std::numeric_limits<T>::max();
            T mxVal = std::numeric_limits<T>::lowest();
            for(size_t c = 0; c < C; c++) {
                mnVal = std::min(mnVal, m(r, c));
                mxVal = std::max(mxVal, m(r, c));
            }
            res[r] = mxVal - mnVal;
        }
    }
    return res;
}

#endif