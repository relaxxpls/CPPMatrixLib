### LU Decomposition
Based on the following MATLAB code:
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