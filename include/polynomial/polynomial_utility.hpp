#ifndef _POLYNOMIAL_UTILITY_H_
#define _POLYNOMIAL_UTILITY_H_
#include "polynomial.hpp"

// Constant polynomial
template<typename T>
polynomial<T> const_poly(T c) {
    return polynomial<T>(0,c);
}

// Returns x^n polynomial
template<typename T>
polynomial<T> power_poly(size_t n) {
    polynomial<T> res(n);
    res[n]+=1;
    return res;
}

//Karatsuba Multiplication
template<typename T>
polynomial<T> Karatsuba_Multiply(const polynomial<T> &lhs,const polynomial<T> &rhs) {
    size_t ld = lhs.degree();
    size_t rd = rhs.degree();
    if( ld==0 || rd==0 ) {
        polynomial<T> res(ld+rd);
        for(size_t i=0;i<ld+1;i++) {
            for(size_t j=0;j<rd+1;j++) {
                res[i+j] += lhs[i]*rhs[j];
            }
        }
        return res;
    }
    size_t n = ld>rd ? ld+1 : rd+1;
    polynomial<T> r_lhs(n/2-1);
    polynomial<T> r_rhs(n/2-1);
    polynomial<T> l_lhs(n-n/2-1);
    polynomial<T> l_rhs(n-n/2-1);
    for(size_t i=0;i<n-n/2;i++) {
        if( i<n/2 && i<ld+1 ) {
            (r_lhs)[i]=lhs[i];
        }
        if( i<n/2 && i<rd+1) {
            (r_rhs)[i]=rhs[i];
        }
        if( i+n/2<ld+1 ) {
            (l_lhs)[i]=lhs[i+n/2];
        }
        if( i+n/2<rd+1 ) {
            (l_rhs)[i]=rhs[i+n/2];
        }
    }
    polynomial<T> prod1(Karatsuba_Multiply(l_lhs,l_rhs));
    polynomial<T> prod2(Karatsuba_Multiply(r_lhs,r_rhs));
    (l_lhs)+=(r_lhs);
    (l_rhs)+=(r_rhs);
    polynomial<T> prod3(Karatsuba_Multiply(l_lhs,l_rhs));
    (prod3)-= (prod1);
    (prod3)-= (prod2);
    polynomial<T> fac1(2*(n/2) + prod1.degree());
    for(size_t i=0;i<=prod1.degree();i++) {
        (fac1)[i+2*(n/2)] = (prod1)[i];
    }
    polynomial<T> fac2(n/2 + prod3.degree());
    for(size_t i=0;i<=prod3.degree();i++) {
        (fac2)[i+n/2] = (prod3)[i];
    }
    polynomial<T> res(fac1 + fac2 + prod2);
    return res;
}

//nth order derivative
template<typename T>
polynomial<T> higher_order_derivative(polynomial<T> p,size_t n) {
    assert(n>=0);
    if(n==0){
        return p;
    }
    polynomial<T> res(p.derivative());
    for(size_t i=0;i<n-1;i++) {
        res = res.derivative();
    }
    return res;
}

//Nth power polynomial
template<typename T>
polynomial<T> power(polynomial<T> p,size_t n) {
    assert(n>=0);
    if(p.empty()) {
        return p;
    }
    size_t d = p.degree();
    polynomial<T> res(0);
    res[0]+=1;
    for (size_t i=n; i>0;i>>=1) {
        res = (i&1) ? res*p : res;
        p *= p;
    }
    return res;
}

#endif