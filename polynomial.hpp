#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include "matrix.hpp"
#include "matrix_utility.hpp"

template<typename T>
class polynomial {

public:
    // constructor with memory allocation
    polynomial(size_t d,T x=0) : D(d) {
        P.resize(d+1, 1, x);
    }

    // default constructor
    polynomial() : D(-1) {}

    // constructor from initializer list
    polynomial(const std::initializer_list<T> p) {
        D = p.size();
        P.resize(D+1, 1);
        P = matrix({p});
    }

    // check if empty
    bool empty() const {
        return D == -1;
    }
    // access degree
    size_t degree() const {
        return D;
    }
    // resize polynomial
    void resize(size_t d,T x=0) {
        D = d;
        P.resize(d+1, 1, x);
    }

    // Algebraic Operations:
    // 1 polynomial(p), 1 scalar(a): p+a, a+p, p-a, -p, a-p, p*a
    // 2 polynomial(p, q): p+q, p-q, p*q, p==q, p!=q
    polynomial operator+=(const T &rhs) {
        if( D==-1 )
        {
            D=0;
            P.resize(D+1,1);
        }
        P(0,0) += rhs;
        return *this;
    }
    polynomial operator+(const T &rhs) const {
        return polynomial(*this) += rhs;
    }
    friend polynomial<T> operator+(const T &lhs,const polynomial<T> &rhs) const {
        return rhs + lhs;
    }

    polynomial operator-=(const T &rhs) {
        if( D==-1 )
        {
            D=0;
            P.resize(D+1,1);
        }
        P(0,0) -= rhs;
        return *this
    }
    polynomial operator-(const T &rhs) const {
        return polynomial(*this) -= rhs;
    }
    polynomial operator-() const {
        return polynomial(D) - *this;
    }
    friend polynomial<T> operator-(const T &lhs,const polynomial<T> &rhs) const {
        return (-rhs) + lhs;
    }

    polynomial operator*=(const T &rhs) {
        P *= rhs;
        return *this;
    }
    polynomial operator*(const T &rhs) const {
        return polynomial(*this) *= rhs;
    }
    friend polynomial<T> operator*(const T &lhs,const polynomial<T> &rhs) const {
        return rhs * lhs;
    }

    polynomial operator+=(const polynomial &rhs) {
        if(D<rhs.D)
        {
            matrix<T> temp(rhs.D+1,1);
            for(size_t i=0;i<D+1;i++) {
                temp(i,1)+= P(i,1);
            }
            D=rhs.D;
            P.resize(D+1,1);
            P+=temp;
        }
        for(size_t i=0;i<rhs.D+1;i++) {
            P(i,1)+= rhs[i];
        }
        return *this;
    }
    polynomial operator+(const polynomial &rhs) const {
        return polynomial(*this) += rhs;
    }
    polynomial operator-=(const polynomial &rhs) {
        return (*this) += -rhs;
    }
    polynomial operator-(const polynomial &rhs) const {
        return polynomial(*this) -= rhs;
    }
    polynomial operator*(const polynomial &rhs) const {
        polynomial res(D+rhs.D+1);
        for(size_t i=0;i<D+1;i++) {
            for(size_t j=0;j<rhs.D+1;j++) {
                res[i+j] += P(i,1)*rhs[j];
            }
        }
        return res;
    }
    polynomial operator*=(const polynomial &rhs) {
        (*this) = (*this)*rhs;
        return *this;
    }
    bool operator==(const polynomial &rhs) const {
        return P==rhs.P;
    }
    bool operator!=(const polynomial &rhs) const {
        return P!=rhs.P;
    }

    // Element Numbering is based on power
    T& operator[](size_t i) {
        assert(0 <= i && i <= D)
        return P(i,1);
    }
    T operator[](size_t i) const {
        assert(0 <= i && i <= D)
        return P(i,1);
    }

    // Display polynomial
    friend std::ostream& operator<<(std::ostream &cout, polynomial<T> p) {
        size_t d = p.degree();
        for(size_t i=0;i<d;i++) {
            cout<<p[i]<<"*x^"<<i<<"+";
        }
        if( d!=-1 ) {
            cout<<p[d]<<"*x^"<<d;
        }
        return cout;
    }
    
private:
    size_t D;
    matrix<T> P();
};

#endif 