# LU Decomposition
Split our matrix A into 2 matrices L & U, where L is a lower triangular matrix with diagonal entries as 1, and U is an upper triangular matrix.  
We will use the [Doolittle Algorithm](https://www.geeksforgeeks.org/doolittle-algorithm-lu-decomposition/) for factoring our matrix into L and U.

Eg:
```
A = [1   1   0]  
    [2   1   3]  
    [3   1   1] 
```
gets transformed into:
```                 
L = [1   0   0]   and   U = [1   1   0]
    [2   1   0]             [1   1   0]
    [3   2   1]             [0   0  -5]

with L*U =  [1   1   0]  = A
            [2   1   3]
            [3   1   1]
```

Based on the following MATLAB code (Square Matrix):
```
function [L, U] = lu(A)
    n = size(A, 1);
    for i = 1 : n
        if A(i, i) == 0
            warning('LU factorization fails');
            L = []; U = []; return; 
        end
        j = i+1 : n;
        A(j, i) = A(j, i) / A(i, i);
        A(j, j) = A(j, j) - A(j, i)*A(i, j);
    end
    L = tril(A, -1) + eye(n);
    U = triu(A);
end
```
MATLAB references: [tril](https://in.mathworks.com/help/matlab/ref/tril.html), [triu](https://in.mathworks.com/help/matlab/ref/triu.html)

### Known Issues: [#1](https://github.com/relaxxpls/CPPMatrixLib/issues/1)
