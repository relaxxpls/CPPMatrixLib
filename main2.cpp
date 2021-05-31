#include "modint.hpp"
#include "modint_utility.hpp"

using namespace std;

int main(){

    modint<int> p(246,19);
    modint<int> q(82,19);
    
    cout<<p/q<<"\n"<<modinv(q);
}