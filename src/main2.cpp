#include "modint.hpp"
#include "modint_utility.hpp"
#include <random>

#define random std::mt19937 rng(0);

using namespace std;

int main(){

    random
    
    modint<int> p(246,19);
    modint<int> q(82,19);
    
    cout<<p/q<<"\n"<<modinv(q)<<"\n";

    vector<long long int> mod={4,5,7,9};
    vector<long long int> rem={2,0,3,1};

    cout<<CRT(mod,rem)<<"\n";
    
}