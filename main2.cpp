#include "modint.hpp"
#include "modint_utility.hpp"

using namespace std;

int main(){

    modint<int> p(246,19);
    modint<int> q(82,19);
    
    cout << p / q << "\n" << modinv(q) << endl;

    cout << powmod(p , 3) << endl;

    cout << factmod(27, 29) << endl;

    cout << combination(23, 4, 97) << endl;
}