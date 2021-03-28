#include "matrix_array.hpp"
#include "matrix_utility_array.hpp"
#include "LU.hpp"

int main() {
	
    // Initialisation of a 3*3 matrix with base value 2
    matrix<int> B(3, 3, 2);

    std::cout<<B<<"\n";

    // Exponentiation
    matrix<int> M = pow(B, 3);

    std::cout<<M<<"\n";

    // edit single element
    M(1, 0) = 1;

    // M.t() = transpose of M (ie M')
    matrix<int> X = -2*M.t();
    // Print matrix
    std::cout << "matrix X: \n" << X << std::endl;

    // Span X(1:2, 0:2)
    // Implementation 1:
    matrix<int> y1 = X({1, 2}, {0, 2});
    std::cout << "matrix y1: \n" << y1 << std::endl;

    // Implementation 2:
    matrix<int> y2 = X(span(0, 1), span(2, 2));
    std::cout << "matrix y2: \n" << y2 << std::endl;

    matrix<double> D = {{65, 77, 69, 75, 69},
                        {61, 74, 70, 66, 68},
                        {81, 80, 71, 74, 79}};

    // Calculate norm
    std::cout << "L1 norm of D: " << norm(D, "L1") << std::endl;

    // Print the range of values (max - min) stored in either column (1) or row (2)
    // std::cout << range(D, 2) << std::endl;

    // Python like range functioning
    std::cout << "\nrange functions: \n"
              << range(0, -10, -1)
              << range(0, 10, 3)
              << std::endl;

    // Matrix rows
    matrix<double> c1 = D.column(4);
    std::cout << "matrix c1: \n" << c1 << std::endl;

    // Matrix columns
    matrix<double> r1 = D.row(3);
    std::cout << "matrix r1: \n" << r1 << std::endl;

    // Test QR decomposition:
    std::tuple<matrix<double>, matrix<double>> qr_tuple= qr(D);
    matrix<double> q = std::get<0>(qr_tuple), r = std::get<1>(qr_tuple);
    // Alternate Method:
    // matrix<int> q(3, 5), r(5, 5);
    // std::tie(q, r) = qr(D);

    std::cout << "matrix D: \n" << D << std::endl;
    std::cout << "matrix q*r: \n" << q*r << std::endl;
    if (q*r == D) {
        std::cout << "QR Decomposition Works :)" << std::endl;
    }
    else {
        std::cout << "QR Decomposition Failed :(" << std::endl;
    }
    
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