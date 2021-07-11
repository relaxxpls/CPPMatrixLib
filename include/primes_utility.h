#pragma once
#ifndef prime_functions
#define prime_functions
#include"prime_tests.h"
#include <iostream>
using namespace std;
using u64 = uint64_t;


long long int phi(long long int n)

{
    long long int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

bool is_primitive(int g, long long int p, vector<int> factors)
{
    for (int i = 0; i < factors.size(); i++)
    {
        if (binpower(g, (p - 1) / factors[i], p) == 1)
        {
            return false;
        }
    }
    return true;
}

bool is_primitive(int g, long long int p)
{
    bool a = true;
    for (int i = 1; i < p - 1; i++)
    {
        if (binpower(g, i, p) == 1)
        {
            a = !a;
            break;
        }
    }
    return a;
}
int primitive_root(long long int x)
{
    if (!is_prime(x))
    {
        return -1;
    }
    else
    {
        long long int y = x - 1;
        vector<int> factors;
        for (int i = 2; i * i <= x; ++i)
        {
            if (y % i == 0)
            {
                factors.push_back(i);
            }
            while (y % i == 0)
            {
                y /= i;
            }
        }
        if (y > 1)
        {
            factors.push_back(y);
        }
        int i = 2;
        while (!is_primitive(i, x, factors))
        {
            i++;
        }
        return i;
    }
}


//This function is to find the power of a prime in n factorial
int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i - 1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n / p) % 2)
            res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}


// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, * y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
#endif