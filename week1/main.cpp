#include "matrix.hpp"
#include "matrix_utility.hpp"
#include "strassen.hpp"

#include <chrono>

int main() {
    //matrix<int> C(3, 3);
    matrix<int> D(3, 3, {0, 10});
    std::cout << D << std::endl;

    matrix<int> A(300,300, {0, RAND_MAX}), B(300,300, {0, RAND_MAX});
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    matrix<int> normalMultiply = A * B;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time_normal = end - start;

    start = std::chrono::system_clock::now();
    matrix<int> strassMultiply = strassen::operator*(A,B);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time_strassen = end - start;

    double improvement = double(time_normal.count() - time_strassen.count()) / double(time_normal.count());
    std::cout << "Time taken in normal Multiplication:" << time_normal.count() << std::endl;
    std::cout << "Time taken in strassen Multiplication:" << time_strassen.count() << std::endl;
    std::cout << "Improvement with strassen :" << improvement * 100;

    return 0;
}