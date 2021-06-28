#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include "../matrix/matrix.hpp"
#include "../matrix/matrix_utility.hpp"

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
        D = p.size()-1;
        P.resize(D+1, 1);
        auto k = p.begin();
        for(size_t i=0;i<D+1;i++) {
            P(i,0)+= *k;
            k++;
        }
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
    // 1 polynomial(p), 1 scalar(a): -p, p*a, a*p
    // 2 polynomial(p, q): p+q, p-q, p*q, p==q, p!=q
    polynomial operator-() const {
        return polynomial(D) - *this;
    }

    polynomial operator*=(const T &rhs) {
        P *= rhs;
        return *this;
    }
    polynomial operator*(const T &rhs) const {
        return polynomial(*this) *= rhs;
    }
    friend polynomial<T> operator*(const T &lhs,const polynomial<T> &rhs) {
        return rhs * lhs;
    }

    polynomial operator+=(const polynomial &rhs) {
        if(D<rhs.D)
        {
            matrix<T> temp(rhs.D+1,1);
            for(size_t i=0;i<D+1;i++) {
                temp(i,0)+= P(i,0);
            }
            D=rhs.D;
            P.resize(D+1,1);
            P+=temp;
        }
        for(size_t i=0;i<rhs.D+1;i++) {
            P(i,0)+= rhs[i];
        }
        return *this;
    }
    polynomial operator+(const polynomial &rhs) const {
        return polynomial(*this) += rhs;
    }
    polynomial operator-=(const polynomial &rhs) {
        if(D<rhs.D)
        {
            matrix<T> temp(rhs.D+1,1);
            for(size_t i=0;i<D+1;i++) {
                temp(i,0)+= P(i,0);
            }
            D=rhs.D;
            P.resize(D+1,1);
            P+=temp;
        }
        for(size_t i=0;i<rhs.D+1;i++) {
            P(i,0)-= rhs[i];
        }
        return *this;
    }
    polynomial operator-(const polynomial &rhs) const {
        return polynomial(*this) -= rhs;
    }
    polynomial operator*(const polynomial &rhs) const {
        polynomial res(D+rhs.D);
        for(size_t i=0;i<D+1;i++) {
            for(size_t j=0;j<rhs.D+1;j++) {
                res[i+j] += P(i,0)*rhs[j];
            }
        }
        return res;
    }
    polynomial operator*=(const polynomial &rhs) {
        (*this) = (*this)*rhs;
        return *this;
    }

    bool equality_floating_point(const polynomial &rhs) const {
        if( D<rhs.D ) {
            for(size_t i=D+1;i<=rhs.D;i++) {
                if( rhs[i]!=0 ) {
                    return false;
                }
            }
        }
        else if( rhs.D<D ) {
            for(size_t i=rhs.D+1;i<=D;i++) {
                if( P(i,0)!=0 ) {
                    return false;
                }
            }
        }
        double sum = 0;
        size_t min_deg = D<rhs.D ? D : rhs.D;
        for(size_t i=0;i<=min_deg;i++) {
            sum += (P(i,0) - rhs[i]) * (P(i,0) - rhs[i]);
        }
        sum /= min_deg+1;
        return sum < _MN_ERR;
    }
    bool equality_integral(const polynomial &rhs) const {
        if( D<rhs.D ) {
            for(size_t i=D+1;i<=rhs.D;i++) {
                if( rhs[i]!=0 ) {
                    return false;
                }
            }
        }
        else if( rhs.D<D ) {
            for(size_t i=rhs.D+1;i<=D;i++) {
                if( P(i,0)!=0 ) {
                    return false;
                }
            }
        }
        size_t min_deg = D<rhs.D ? D : rhs.D;
        for(size_t i=0;i<=min_deg;i++) {
            if( P(i,0)!=rhs[i] ) {
                return false;
            }
        }
        return true;
    }
    bool operator==(const polynomial &rhs) const {
        if (empty() || rhs.empty()) {
            return false;
        }
        if(std::is_floating_point<T>::value) {
            return this->equality_floating_point(rhs);
        }
        return this->equality_integral(rhs);
    }
    bool operator!=(const polynomial &rhs) const {
        return !((*this)==rhs);
    }

    // Element Numbering is based on power
    T& operator[](size_t i) {
        assert(0 <= i && i <= D);
        return P(i,0);
    }
    T operator[](size_t i) const {
        assert(0 <= i && i <= D);
        return P(i,0);
    }
    //Calculating value for given parameter
    T calculate(const T x) {
        assert(!empty());
        T res=0;
        T fac=1;
        for(size_t i=0;i<=D;i++) {
            res += fac * P(i,0);
            fac *= x;
        }
        return res;
    }

    //First order derivative
    polynomial derivative() {
        assert(!empty());
        if(D==0) {
            return polynomial(0);
        }
        matrix<T> derv_op(D,D+1);
        for(size_t i=0;i<D;i++) {
            derv_op(i,i+1)= i+1;
        }
        matrix<T> prod(derv_op*P);
        polynomial<T> res(D-1);
        for(size_t i=0;i<D;i++) {
            res[i]=prod[i];
        }
        return res;
    }

    // Display polynomial
    friend std::ostream& operator<<(std::ostream &cout, polynomial<T> p) {
        size_t d = p.degree();
        for(size_t i=0;i<d;i++) {
            cout<<"("<<p[i]<<")x^"<<i<<"+";
        }
        if( !p.empty() ) {
            cout<<"("<<p[d]<<")x^"<<d;
        }
        return cout;
    }
    
private:
    size_t D;
    matrix<T> P;
};

#endif 