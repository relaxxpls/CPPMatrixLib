#include "pch.h"
#include "prime_tests.h"
#include "primes_utility.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;
    

TEST(primetest, test1) 
{
    srand((unsigned)time(0));
    long long int x = (rand() % 1000000) + 1;
    bool a = is_prime(x);
    bool b = true;
    for(int i=2;i*i<=x;i++)
    {
        if (x % i == 0)
        {
            b = !b;
            break;
        }
    }
    EXPECT_EQ(a, b);
}

TEST(primitiveroot_test, test1) 
{
    srand((unsigned)time(0));
    long long int x = (rand() % 1000000) + 1;
    int g = primitive_root(x);
    if (g != -1)
    {
        EXPECT_EQ(true, is_primitive(g, x));
    }
}

TEST(eulerfunction_test, test1) 
{
    srand((unsigned)time(0));
    long long int x = (rand() % 1000000) + 1;
    long long int counter = 1;
    for (int i = 2; i < x; i++) 
    {
        if (gcd(i, x) == 1)
        {
            counter++;
        }
    }
    EXPECT_EQ(phi(x), counter);
}
