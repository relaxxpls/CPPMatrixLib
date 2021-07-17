#ifndef _MODINT_UTILITY_H
#define _MODINT_UTILITY_H

#include "modint.hpp"
#include <algorithm>

#include <cstring>

template<typename T>

T gcd(T a, T b){
    
    T c = a % b;
    
    while(c != 0){

        a = b;
        b = c;
        c = a % b;

    }

    return b;
}

template<typename T>

modint<T> modinv(modint<T> &a){

    assert(a[0] != 0);
    assert(gcd(a[0],a[1])==1);

    T r0=a[0],s0=1,r1=a[1],s1=0;

    T r2,s2;

    while(r1!=0){

        T q=r0/r1;

        r2=r0-q*r1;
        r0=r1;
        r1=r2;

        s2=s0-q*s1;
        s0=s1;
        s1=s2;

    }

    return modint<T>(s0,a[1]);

} 

/*template <typename T>

T modinv(modint<T> &a) {
    T x = a[0], m = a[1];
    return 1 < x ? m - modinv(*new modint<T>(m % x, x)) * m / x : 1;
}*/


template <typename T>

modint<T> operator/=(modint<T> &a, modint<T> &b){

    assert(b[0]!=0);
    
    return a*=modinv(b);
}

template <typename T>

modint<T> operator/(modint<T> &a, modint<T> &b){

    assert(b[0]!=0);
    
    return a/=b;
}

template <typename T>
modint<T> powmod(modint<T> a, T b) {
    if (b == 0) return modint<T>(1, a[1]);
    else if (b % 2 == 0) {
        modint<T> x = powmod(a, b / 2);
        return x * x;
    }
    else {
        modint<T> x = powmod(a, b - 1);
        return x * a;
    }
}

//calculatin n! in mod m
template<typename T>
T largestPower(T n, T p)
{
    int x = 0;
 
    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n) {
        n /= p;
        x += n;
    }
    return x;
}
template<typename T>
modint<T> factmod(T n, T m) {
    if (n > m) return 0;
    // Use Sieve of Eratosthenes to find all primes
    // smaller than n
    bool isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
    modint<T> res(1, m);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            // Find the largest power of prime 'i' that divides n!
            T k = largestPower(n, i);
            modint<T> p(i, m);
            // Multiply result with (i^k) % p
            res *= powmod(p, k);
        }
    }
    return res;
}

// Returns n! % p using Wilson's Theorem (assuming p is prime)
template<typename T>
modint<T> modFact(T n, T p) {
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;
 
    // Initialize result as (p-1)! which is -1 or (p-1)
    modint<T> res(p - 1, p);
 
    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (int i = n + 1; i < p; i++){
        modint<T> k(i, p);

        res *= modinv<T> (k);
    }
    return res;
}

//functuin to calculate nCr in mod m (m must be prime)
template<typename T>
modint<T> combination(T n, T r, T m) {
    if (n < r) return 0;
    else if (n == r) return 1;
    else {
        modint<T> num = modFact(n, m), denom = modFact(n - r, m) * modFact(r, m); 
        modint<T> res = num / denom; 
        return res;
    }

}
#endif