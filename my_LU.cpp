#include "matrix.hpp"
#include "matrix_utility.hpp"

template <typename T>

matrix<T> tril(matrix<T> A){

    int n=A.size().first;

    matrix<T> B(n,n,0);

    for(int i=1;i<=n;i++){

        for(int k=1;k<i;k++){

            B(i,k)=A(i,k);
        }
    }
    return B;
}

template <typename T>

matrix<T> triu(matrix<T> A){

    int n=A.size().first;

    matrix<T> B(n,n,0);

    for(int i=1;i<=n;i++){

        for(int k=i;k<=n;k++){

            B(i,k)=A(i,k);
        }
    }
    return B;
}

template <typename T>

std::pair<matrix<T>,matrix<T> > mylu (matrix<T> A){

    int n=A.size().first;

    std::pair<matrix<T>,matrix<T> > ans;
    
    for(int k=1;k<=n;k++){

        if(A(k,k)==0){

            std::cout<<"LU factorization fails\n";
            ans.first = matrix<T>(0,0,0);
            ans.second = matrix<T>(0,0,0); 
            return;
        }
        for(int i=k+1;k<=n;k++){

            A(i,k) = A(i,k)/A(k,k);
            A(i,i) = A(i,i)-A(i,k)*A(k,i);
        }
    }

    ans.first=tril<T>(A,-1)+eye<T>(n);
    ans.second=triu<T>(A);

    return ans;

}