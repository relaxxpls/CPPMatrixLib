#ifndef _MODINT_UTILITY_H
#define _MODINT_UTILITY_H

#include "modint.hpp"
#include <algorithm>

template<typename T>

T gcd(T a, T b){

    T c=a%b;
    
    while(c!=0){

        a=b;
        b=c;
        c=a%b;

    }

    return b;

}

template<typename T>

modint<T> modinv(modint<T> a){

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

template <typename T>

modint<T> operator/=(modint<T> &a, modint<T> &b){

    assert(b[0]!=0);
    
    return a*=modinv(b);
}

template <typename T>

modint<T> operator/(modint<T> &a, modint<T> &b){

    assert(b[0]!=0);
    
    return modint<T>(a)*=modinv(b);
}

template <typename T>

T CRT(std::vector<T> &mod, std::vector<T> &rem){

    assert(mod.size()==rem.size());

    std::vector<T> x(mod.size());

    std::vector<std::vector<T>> inverse(rem.size(),std::vector<T>(rem.size()));

    for(int i=0;i<rem.size();i++){

        for(int j=0;j<i;j++){

            inverse[j][i]=modinv(modint<T>(mod[j],mod[i]))[0];
        }
    }

    T ans=0; T pref=1;

    for(int i=0;i<rem.size();i++){

        x[i]=rem[i];

        for(int j=0;j<i;j++){

            x[i]=inverse[j][i]*(x[i]-x[j]);

            x[i]=x[i]%mod[i];

            if(x[i]<0){

                x[i]+=mod[i];
            }
        }

        ans+=x[i]*pref;
        
        pref*=mod[i];
    }

    return ans;
}


#endif