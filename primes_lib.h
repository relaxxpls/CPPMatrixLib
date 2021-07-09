#pragma once
#ifndef primes_lib
#define primes_lib
#include <iostream>
using namespace std;
using u64 = uint64_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u64)result * base % mod;
        base = (u64)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u64)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool is_prime(long long int n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}



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




#endif