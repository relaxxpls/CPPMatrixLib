#include "matrix.hpp"
#include "matrix_utility.hpp"

template <typename T>

matrix<T> tril(matrix<T> A){

    int n=A.size().first;

    matrix<T> B(n,n,0);

    for(int i=0;i<n;i++){

        for(int k=0;k<i;k++){

            B(i,k)=A(i,k);
        }
    }
    return B;
}

template <typename T>

matrix<T> triu(matrix<T> A){

    int n=A.size().first;

    matrix<T> B(n,n,0);

    for(int i=0;i<n;i++){

        for(int k=i;k<n;k++){

            B(i,k)=A(i,k);
        }
    }
    return B;
}

template <typename T>

std::pair<matrix<T>,matrix<T> > mylu (matrix<T> A){

    int n=A.size().first;

    std::pair<matrix<T>,matrix<T> > ans;
    
    for(int k=0;k<n;k++){

        if(A(k,k)==0){

            std::cout<<"LU factorization fails\n";
            ans.first = matrix<T>(0,0,0);
            ans.second = matrix<T>(0,0,0); 
            return ans;
        }
        for(int i=k+1;i<n;i++){

            for(int l=0;l<k;l++){

                A(i,k)-=A(i,l)*A(l,k);
            }
            A(i,k) = A(i,k)/A(k,k);
            for(int l=0;l<k;l++){

                A(k,i)-=A(k,l)*A(l,i);
            }
            A(i,i) = A(i,i)-(A(i,k)*A(k,i));
        }
    }

    ans.first=tril<T>(A)+eye<T>(n);
    ans.second=triu<T>(A);

    return ans;

}