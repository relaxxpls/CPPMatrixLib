#include "gtest/gtest.h"
#include "matrix.hpp"
#include "matrix_utility.hpp"

TEST(additionTest, test1) {
    matrix<int> A(3, 3, 2);
    matrix<int> B(3, 3, 1);
    matrix<int> C(3, 3, 3);
    EXPECT_EQ (A+B,C);
}

TEST(transposeTest, test1) {
    matrix<int> A(3, 3, 2);
    matrix<int> B(3, 3, 2);
    EXPECT_EQ (A,B.t());
}

TEST(multiplyTest, test1) {
    matrix<int> A(3, 3, 3);
    matrix<int> B(3, 3, 1);
    matrix<int> P(3, 3, 9);
    EXPECT_EQ (A*B,P);
}

