#include "matrix.hpp"
#include "matrix_utility.hpp"
#include "strassen.hpp"

#include <chrono>

int main() {
    matrix<int> A{{1,2,3},
                  {4,5,6},
                  {7,8,9}};
    matrix<int> B{{1,5,3},
                  {8,2,6},
                  {7,4,9}};
    
    std::cout << A * B << std::endl;
    std::cout << strassen::operator*(A,B);

    return 0;
}