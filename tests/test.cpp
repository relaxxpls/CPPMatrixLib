#include "pch.h"
#include "primes_lib.h"

TEST(primetest, test1) {
    long long int x = 97;
    EXPECT_EQ(is_prime(x), true);
}

TEST(primitiveroot_test, test1) {
    long long int x = 761;
    EXPECT_EQ(primitive_root(x), 6);
}

TEST(eulerfunction_test, test1) {
    long long int x = 7685665;
    EXPECT_EQ(phi(x), 5642496);
}

TEST(binpower, test1) {
    long long int x = 7685665;
    long long int y = 23456;
    long long int p = 761;
    EXPECT_EQ(phi(x), 5642496);
}