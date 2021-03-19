# CPPMatrixLib - A Portable Matrix Library in C++
This is a simple matrix library, that is built to have a similar interface for matrices as compared to MATLAB or NumPy.

### Features: 
* lightweight
* dependency-free
* similar functioning to STL
* variety of operators, including matrix-matrix operators and matrix-number operators and a bunch of linear algebra functions

### Updates:  
V1.5 Added QR Decomposition and a few usage examples in [main.cpp](https://github.com/relaxxpls/CPPMatrixLib/blob/main/main.cpp)

### Motivation:
I like Linear Algebra, but the scripting nature of MATLAB makes working a pain. Plus it's paid :(  
C++ dosent natively support Linear Algebra, and using heavy packages can make running your code on a different device a pain. What if you could just copy paste a few KBs and get most of MATLABS Linear Algebra functionality?

The Big Picture:
- Aim to build a light weight math library.
- Currently work is under way, and a raw polynomial library is ready. It supports FFT and multimod NTT. Once it's style is improved, it will be added here.
- Work is also underway for a primes library, supporting prime tests and factorisation

### Changes Proposed:
* Add iterators (row and column wise) so as to increase compatibility with STL algorithms (search & sort)
* Add a function to calculate the Eigen values and Eigen vectors of a matrix
* Add LU & SVD functions that can help calculate the inverse of a matrix
* Add functionality to solve Linear Equations (A*X = B)
* Add documentation
* Depict its use in solving Linear Recurrences as an example solve [Project Euler 258](https://projecteuler.net/problem=258)
