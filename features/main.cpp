#include "../matrix.hpp"
#include "../matrix_utility.hpp"
#include "LU.hpp"

int main() {
	matrix<double> E = {{1, 1, 0},
                        {2, 1, 3},
                        {3, 1, 1}};

    std::tuple<matrix<double>, matrix<double>> lu_tuple = lu(E);
    matrix<double> l = std::get<0>(lu_tuple), u = std::get<1>(lu_tuple);

    std::cout << "\nmatrix l: \n" <<  l << std::endl;
    std::cout << "matrix u: \n" <<  u << std::endl;
    std::cout << "matrix l*u: \n" <<  l*u << std::endl;

    if (l*u == E) {
        std::cout << "LU Decomposition Works :)" << std::endl;
    }
}