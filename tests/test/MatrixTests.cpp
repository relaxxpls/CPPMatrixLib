#include <gtest/gtest.h>
#include "../../matrix.hpp"
#include "../../matrix_utility.hpp"

TEST(MATRIX,Addition){

    // Manual Checking of addition of two random matrices
    
    matrix<int> M1={{4, 2, 3},
                    {7, 9, 10},
                    {-4, -9, 2}};
    
    matrix<int> M2={{-10,-1,-2},
                    {4, 8, -3},
                    {-2, 7, 9}};

    matrix<int> add={{-6, 1, 1},
                     {11, 17, 7},
                     {-6, -2, 11}};

    ASSERT_EQ(add,M1+M2);

    std::pair<int,int> a={-32767,32767};

    // Checking that sum of additive inverse of matrices is indeed 0
    
    for(size_t i=1;i<=20;i++){

        M1.resize(i,i);
        M1=random_matrix<int>(i,i,a,i);

        M2.resize(i,i);

        add.resize(i,i);

        for(int j=0;j<i;j++){

            for(int k=0;k<i;k++){

                M2(j,k)=-M1(j,k);
            }
        }
        ASSERT_EQ(add,M1+M2);
    }
}

TEST (MATRIX,Multiplication){

    // Manual Checking of multiplication of two random matrices
    
    matrix<int> M1={{4, 2, 3},
                    {7, 9, 10},
                    {-4, -9, 2}};
    
    matrix<int> M2={{-10,-1,-2},
                    {4, 8, -3},
                    {-2, 7, 9}};

    matrix<int> multiply={{-38, 33, 13},
                          {-54, 135, 49},
                          {0, -54, 53}};

    EXPECT_EQ(multiply,M1*M2);

    std::pair<int,int> a={-32767,32767};

    //Checking any matrix multiplied with identity matrix return same matrix
    
    for(size_t i=1;i<=20;i++){

        for(size_t j=1;j<=20;j++){

            M1=random_matrix<int>(j,i,a,i);
            M2=eye<int>(i);
            ASSERT_EQ(M1,M1*M2);

            M2=eye<int>(j);
            ASSERT_EQ(M1,M2*M1);

        }
    }

    // Checking any matrix multiplied with zero matrix gives zero matrix

    for(size_t i=1;i<=20;i++){

        for(size_t j=1;j<=20;j++){

            matrix<int> M3(i,j);

            for(size_t k=1;k<=20;k++){

                M1=random_matrix<int>(i,k,a,i);
                M2=matrix<int>(k,j);
                ASSERT_EQ(M3,M1*M2);
            }
        }
    }
}

TEST(MATRIX_UTILITY, Power){

    std::vector<int> fibo(47,1);

    fibo[1]=1;

    //Checking Fibonacci Numbers through Matrices

    for(int i=1;i<=46;i++){

        if(i!=1){
            
            fibo[i]=fibo[i-1]+fibo[i-2];

        }
        matrix<int> M(2,2);

        M(0,0)=1;
        M(0,1)=1;
        M(1,1)=0;
        M(1,0)=1;

        M=pow(M,i);

        ASSERT_EQ(fibo[i],M(0,0));
    }

    //Random Matrices
    
    for(int i=1;i<=20;i++){

        matrix<int> M=random_matrix<int>(i,i,{-32767,32767},i);

        matrix<int> manual=eye<int>(i);

        for(int j=1;j<=i;j++){

            manual=manual*M;
        }

        M=pow(M,i);

        ASSERT_EQ(manual,M);
    }
}

TEST(MATRIX_UTILITY, LU){

    for(int i=0;i<100;i++){

        matrix<double> A=random_matrix<double>(100,100,{0,10000000},i);

        std::tuple<matrix<double>,matrix<double>> lu_tuple=lu(A);

        matrix<double> B=std::get<0>(lu_tuple);
        matrix<double> C=std::get<1>(lu_tuple);

        ASSERT_EQ(B*C,A);

        for(int j=0;j<100;j++){

            for(int k=0;k<j;k++){

                ASSERT_EQ(C(j,k),0);
            }

            ASSERT_EQ(B(j,j),1);

            for(int k=j+1;k<100;k++){

                ASSERT_EQ(B(j,k),0);
            }
        }
    }
}

