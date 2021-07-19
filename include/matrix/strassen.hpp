#include "matrix.hpp"
#include "matrix_utility.hpp"

template <typename T>
matrix<T> strassen_mult(const matrix<T> &m1, const matrix<T> &m2, int s) {
    if (s == 2) {
        matrix<T> ans = {{m1(0,0) * m2(0,0) + m1(0,1) * m2(1,0),
                          m1(0,0) * m2(0,1) + m1(0,1) * m2(1,1)},
                         {m1(1,0) * m2(0,0) + m1(1,1) * m2(1,0),
                          m1(1,0) * m2(0,1) + m1(1,1) * m2(1,1)}};
        return ans;
    }
    else {
        matrix<T> A1 = strassen_mult(m1(span(0, s / 2 - 1), span(0, s / 2 - 1)) , m2(span(0, s / 2 - 1),span(0, s / 2 - 1)), s / 2) + strassen_mult(m1(span(0, s / 2 - 1), span(s / 2, s - 1)) , m2(span(s / 2, s - 1), span(0, s / 2 - 1)), s / 2);
        matrix<T> A2 = strassen_mult(m1(span(0, s / 2 - 1), span(0, s / 2 - 1)) , m2(span(0, s / 2 - 1),span(s / 2, s - 1)), s / 2) + strassen_mult(m1(span(0, s / 2 - 1), span(s / 2, s - 1)) , m2(span(s / 2, s - 1), span(s / 2, s - 1)), s / 2);
        matrix<T> A3 = strassen_mult(m1(span(s / 2, s - 1), span(0, s / 2 - 1)) , m2(span(0, s / 2 - 1),span(0, s / 2 - 1)), s / 2) + strassen_mult(m1(span(s / 2, s - 1), span(s / 2, s - 1)) , m2(span(s / 2, s - 1), span(0, s / 2 - 1)), s / 2);
        matrix<T> A4 = strassen_mult(m1(span(s / 2, s - 1), span(0, s / 2 - 1)) , m2(span(0, s / 2 - 1),span(s / 2, s - 1)), s / 2) + strassen_mult(m1(span(s / 2, s - 1), span(s / 2, s - 1)) , m2(span(s / 2, s - 1), span(s / 2, s - 1)), s / 2);               
        matrix<T> ans(s, s , 0);
        for (int i = 0; i < s / 2; i++)
            for (int j = 0; j < s / 2; j++) {
                ans(i,j) = A1(i, j);
                ans(i, s / 2 + j) = A2(i, j);
                ans(s / 2 + i, j) = A3(i, j);
                ans(s / 2 + i, s / 2 + j) = A4(i, j);
            }
        return ans;
    }
    
}

namespace strassen {
    template<typename T>
    matrix<T> operator*(const matrix<T> &m1, const matrix<T> &m2) {
        std::pair<int, int> s1 = m1.size(), s2 = m2.size();
        assert(s1.second == s2.first);
        int a1 = (s1.first > s1.second)? s1.first : s1.second;
        int a2 = (s2.first > s2.second)? s2.first : s2.second;
        int c = (a1 > a2)? a1 : a2;
        int b = 1;
        while (c > 0) {
            c /= 2;
            b *= 2;
        }
        matrix<T> M1(b, b, 0), M2(b, b, 0);
        for (int i = 0; i < s1.first ; i++)
            for (int j = 0; j < s1.second; j++)
                M1(i,j) = m1(i,j);
        for (int i = 0; i < s2.first ; i++)
            for (int j = 0; j < s2.second; j++)
                M2(i,j) = m2(i,j);
        matrix<T> ans = strassen_mult(M1, M2, b);
        matrix<T> ans_f(s1.first, s2.second, 0);
        for (int i = 0 ; i < s1.first; i++)
            for (int j = 0; j < s2.second; j++)
                ans_f(i,j) = ans(i,j);
        return ans_f;
    }
}