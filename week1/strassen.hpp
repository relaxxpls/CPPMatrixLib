#include "matrix.hpp"
#include "matrix_utility.hpp"

typedef std::pair< size_t, size_t > ss;

template<typename T>
matrix<T> strassenMultipy(matrix<T> a, matrix<T> b, int N) {
    if (N == 2) {
        matrix<T> ans = {{((a(0,0) * b(0,0)) + (a(0,1) * b(1,0))), ((a(0,0) * b(0,1)) + (a(0,1) * b(1,1)))},
                         {((a(1,0) * b(0,0)) + (a(1,1) * b(1,0))), ((a(1,0) * b(0,1)) + (a(1,1) * b(1,1)))}};
        return ans;
    }
    else {
        matrix<T> ans(N, N, 0), temp(N / 2, N / 2, 0);
        temp = strassenMultipy(a(span(0, (N / 2) - 1), span(0, (N / 2) - 1)), 
                               b(span(0, (N / 2) - 1), span(0, (N / 2) - 1)), N / 2) + 
               strassenMultipy(a(span(0, (N / 2) - 1), span(N / 2, N - 1)), 
                               b(span(N / 2, N - 1), span(0 , (N / 2) - 1)), N / 2);
        for (int i = 0 ; i < N / 2; i++)
            for (int j = 0 ; j < N / 2; j++)
                ans(i,j) = temp(i,j);
        temp = strassenMultipy(a(span(0, (N / 2) - 1), span(0, (N / 2) - 1)), 
                               b(span(0, (N / 2) - 1), span(N / 2, N - 1)), N / 2) +
               strassenMultipy(a(span(0, (N / 2) - 1), span(N / 2, N - 1)), 
                               b(span(N / 2, N - 1), span(N / 2, N - 1)), N / 2);
        for (int i = 0 ; i < N / 2; i++)
            for (int j = N / 2 ; j < N; j++)
                ans(i,j) = temp(i, j - (N / 2));
        temp = strassenMultipy(a(span(N / 2, N - 1), span(0, (N / 2) - 1)), 
                               b(span(0, (N / 2) - 1), span(0, (N / 2) - 1)), N / 2) +
               strassenMultipy(a(span(N / 2, N - 1), span(N / 2, N - 1)), 
                               b(span(N / 2, N - 1), span(0, (N / 2) - 1)), N / 2);
        for (int i = N / 2 ; i < N; i++)
            for (int j = 0 ; j < N / 2; j++)
                ans(i,j) = temp(i - (N / 2), j);
        temp = strassenMultipy(a(span(N / 2, N - 1), span(0, (N / 2) - 1)), 
                               b(span(0, (N / 2) - 1), span(N / 2, N - 1)), N/ 2) +
               strassenMultipy(a(span(N / 2, N - 1), span(N / 2, N - 1)), 
                               b(span(N / 2, N - 1), span(N / 2, N - 1)), N / 2);
        for (int i = N / 2 ; i < N; i++)
            for (int j = N / 2 ; j < N; j++)
                ans(i,j) = temp(i - (N / 2), j - (N / 2));
        return ans;
    }
}

namespace strassen {
    template<typename T>
    matrix<T> operator*(const matrix<T>& a, const matrix<T>& b) {
        ss a_s = a.size(), b_s = b.size();
        assert(a_s.second == b_s.first);
        int max = a_s.first > a_s.second ? a_s.first : a_s.second;
        max = max > b_s.second ? max : b_s.second;
        int p = 1;
        while (max > 1) {
            max /= 2;
            p++;
        }
        matrix<T> A(int(pow(2, p)),int(pow(2, p)), 0), 
                  B(int(pow(2, p)),int(pow(2, p)), 0);
        for (int i = 0; i < a_s.first; i++) 
            for (int j = 0; j < a_s.second; j++) 
                A(i,j) = a(i,j);
        for (int i = 0; i < b_s.first; i++) 
            for (int j = 0; j < b_s.second; j++) 
                B(i,j) = b(i,j);

        matrix<T> ma = strassenMultipy(A, B, int(pow(2, p)));
        matrix<T> ans(a_s.first, b_s.second, 0);
        for (int i = 0; i < a_s.first; i++) 
            for (int j = 0; j < b_s.second; j++) 
                ans(i,j) = ma(i,j); 
        return ans;
    } 
    
}