# CPPMatrixLib - A Portable Matrix Library in C++
This is a simple matrix library, that is built to have a similar interface for matrices as compared to MATLAB or NumPy.

### Features: 
* lightweight
* dependency-free
* similar functioning to STL
* variety of operators, including matrix-matrix operators and matrix-number operators and a bunch of linear algebra functions

### Proficiency Test: (Deadline: 23rd March 5PM)
1.  Fork & clone [CPPMatrixLib](https://github.com/relaxxpls/CPPMatrixLib)
2.  Go through [main.cpp](https://github.com/relaxxpls/CPPMatrixLib/blob/main/main.cpp)
2.  Add a file called as `my_lu.cpp`.
3.  Inside your `my_lu.cpp` file, code a simple [LU Decomposition](https://www.geeksforgeeks.org/l-u-decomposition-system-linear-equations/), using the ‘matrix’ and ‘matrix_utility’ headers. [Sample code](https://www.tutorialspoint.com/cplusplus-program-to-perform-lu-decomposition-of-any-matrix). You can use the pseudocode provided below:
```
function mylu (matrix A) -> returns L and U
    R = rows of A
    for r = 0 to R-1:
        if A(r, r)==0:
            warning('LU factorization fails');
            L = []; U = []; 
            return L and U; 
        end
        
        for j in r to R-1:
            A(j,r) = A(j,r) / A(r,r);
        end
        
        for j in r to R-1:
            A(j,j) = A(j,j) - A(j,r)*A(r,j);
        end
    end
    L = tril(A,-1) + eye(R); U = triu(A)
    return L and U
```
Reference:
[triu](https://in.mathworks.com/help/matlab/ref/triu.html)  
[tril](https://in.mathworks.com/help/matlab/ref/tril.html)  
4. Finally add 2 lines at the end of main.cpp that shows L*U == A
5. Your good to go!  

Submission: Once you’ve finished the test, mail me the link to your fork containing the `my_lu.cpp` file.  
If you are unable to complete the test due to lack of time, submit whatever you’ve done!


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
