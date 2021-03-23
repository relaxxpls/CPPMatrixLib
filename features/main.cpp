#include "../matrix.hpp"
#include "../matrix_utility.hpp"
#include "LU.hpp"

int main() {
	matrix<double> E = {{36, 42, 0, 64},
                        {78, 90, 21, 12},
                        {11, 32, 45, 8},
                        {69, 21, 29, 97}};

    std::tuple<matrix<double>, matrix<double>> lu_tuple = lu(E);
    matrix<double> l = std::get<0>(lu_tuple), u = std::get<1>(lu_tuple);

    std::cout << "matrix l: \n" <<  l << std::endl;
    std::cout << "matrix u: \n" <<  u << std::endl;
    std::cout << "matrix l*u: \n" <<  l*u << std::endl;

    if (l*u == E) {
        std::cout << "LU Decomposition Works :)" << std::endl;
    }
}