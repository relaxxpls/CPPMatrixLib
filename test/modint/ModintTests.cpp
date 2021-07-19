#include "gtest/gtest.h"
#include "modint.hpp"
#include "modint_utility.hpp"

TEST(MODINT, initialisation) {
    for (int i = 0; i < 10; i++) {
        modint<int> a(i, 2);
        ASSERT_EQ(a[0], i%2);
    }
}

TEST(MODINT, addition) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            modint<int> a(i, 2), b(j, 2);
            modint<int> c = a + b;
            ASSERT_EQ(c[0], (i + j) % 2);
        }
    }
}

TEST(MODINT, multiplication) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            modint<int> a(i, 2), b(j, 2);
            modint<int> c = a * b;
            ASSERT_EQ(c[0], (i * j) % 2);
        }
    }
}

TEST(MODINT, inverse) {
        modint<int> a(53, 2);
        modint<int> b = modinv(a);
        modint<int> c = a * b;
        ASSERT_EQ(c[0], 1);
}

TEST(MODINT, factorial) {
    modint<int> a = modFact<int>(0, 7);
    ASSERT_EQ(a[0], 1);
    a = modFact<int> (3, 7);
    ASSERT_EQ(a[0], 6);
    a = modFact<int> (4, 7);
    ASSERT_EQ(a[0], 3);

}