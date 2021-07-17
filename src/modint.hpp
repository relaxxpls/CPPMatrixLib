#ifndef _MODINT_H
#define _MODINT_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <cmath>
#include <climits>

#define _DEF_MOD_ int(1e9+7)

template <typename T>

class modint{

private:

    T value, modulus;
    
public: 

    //constructor with default case included
    modint(T v=0,T m=_DEF_MOD_){

        assert(m>0);

        if(v>=m){

            v%=m;
        }else if(v<0){

            v=m-(abs(v)%m);

            if(v==m){

                v=0;
            }
        }  

        value=v;
        modulus=m;
    }

    //constructor with initializer list
    modint(const std::initializer_list<T> lis) {
        
        assert(lis.size()==2);
        assert(*(lis.begin()+1)!=0);
        
        T v=*(lis.begin());

        T m=*(lis.begin()+1);

        assert(m>0);

        if(v>=m){

            v%=m;
        }else if(v<0){

            v=m-(abs(v)%m);

            if(v==m){

                v=0;
            }
        }  

        value=v;
        modulus=m;
    }

    //Algebraic Operations

    modint operator +=(const modint &b){

        assert(modulus==b.modulus);

        value+=b.value;

        if(value>=modulus){

            value-=modulus;
        }

        return *this;
    }

    modint operator -=(const modint &b){

        assert(modulus==b.modulus);

        value-=b.value;

        if(value<0){

            value+=modulus;
        }

        return *this;
    }

    modint operator *=(const modint &b){

        assert(modulus==b.modulus);

        value*=b.value;

        if(value>=modulus){

            value%=modulus;
        }

        return *this;
    }

    modint operator *=(const T &b){

        if(b>modulus){
            b%=modulus;
        }

        value*=b;

        if(value>=modulus){

            value%=modulus;
        }

        return *this;
    }

    modint operator *(const T &b){

        return modint(*this)*=b;
    }

    friend modint<T> operator*(const T &a, const modint<T> &b) {

        return a * b;
    }

    modint operator-() const {

        return modint(0,modulus)-*this;
    }

    //Division is tricky; implemented in modint_utility.hpp

    modint operator+ (const modint &b){

        return modint(*this)+=b;
    }
    modint operator- (const modint &b){

        return modint(*this)-=b;
    }
    modint operator* (const modint &b){

        return modint(*this)*=b;
    }

    //Boolean Operators

    bool operator> (const modint &b){

        assert(modulus==b.modulus);

        return value>b.value;
    }
    bool operator< (const modint &b){

        assert(modulus==b.modulus);

        return value<b.value;
    }
    bool operator>= (const modint &b){

        assert(modulus==b.modulus);

        return value>=b.value;
    }
    bool operator<= (const modint &b){

        assert(modulus==b.modulus);

        return value<=b.value;
    }
    bool operator== (const modint &b){

        return (value==b.value&&modulus==b.modulus);
    }
    bool operator!= (const modint &b){

        return !(*this==b);
    }

    //Access data operators

    //Cannot return by reference as that would allow users to change values at whim

    T operator[](size_t i){

        assert(i==0||i==1);

        if(i==0){

            return value;
        }else{

            return modulus;
        }
    }
    /*T& operator[](size_t i){

        assert(i==0||i==1);

        if(i==0){

            return value;
        }else{

            return modulus;
        }
    }*/

    //Direct Data Modifying Operators
    //Allowing users to change values

    modint operator()(size_t i, T a){

        assert(i==0||i==1);

        if(i==0){

            return *this=modint(a,modulus);
        }else{

            return *this=modint(value,a);
        }
    }

    //Printing Operators

    friend std::ostream& operator<<(std::ostream &cout, modint<T> m) {
        
        std::cout<<"{ " << m.value << " | " << m.modulus <<" }";
        return cout;
    }

};

#endif
