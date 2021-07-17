The main branch contains the code that we were given as a starting point by our mentor.

All the changes and extra code written lies in the develop branch.

We first spent some time analysing the code and understanding how it functions.

My first task for WEEK 1 was to add the LU Decomposition function to the matrix_utility.hpp
file, which is present at the end of the file.

For WEEK 2, we had to create a function that uses strassen's algorithm to compute the product of huge matrices in O(n^2.80). We also calculated the time improvement but it came out to be -200 (i.e. Strassen was taking longer than the naive method) as its constant factor was really large. Due to this, this idea was scrapped and is no  longer included in the final version.

We took a break of a few weeks for our exams.

WEEK 5 - I modified the original code which stored the matrix as a 2D array, so that it is now stored as a 1D array, to improve the efficiency of the code. Modifications were made throughout matrix.hpp and matrix_utility.hpp. 

WEEK 6 - As the modules were getting a bit convoluted, we spent some time learning about workflow and how to resolve merge conflicts. At the same time, we started learning about how to use GoogleTest to test our matrix library. We were also given competitive programming problems on Codeforces, Codechef and Atcoder to practice our skills. This included problems on Gaussian XORs, Matrix Exponentiation, DP and Graph Algorithms.

WEEk 7 - GoogleTest was proving to be a bit difficult to implement for me, so I took some time here. I spent time solving Competitive Programming Problems that were given in the previous week.

WEEK 8 - I was finally able to make a test file for Matrix for common functions like addition, multiplication and power. It was fun to come up with ways to check the functions in all possible ways. During this, I came across some errors in the original code that we had been given, in the implementation of the multiplication and power functions. I also corrected these errors.

WEEK 9 - We were given a problem to solve on Project Euler (PE258) and wrote code to solve the problem. In addition to this, I also solved problems on Matrix Exponentiation,DP and Graphs. (The solutions to these problems can be found in random stuff/CP Problems).

WEEK 10 - I was assigned the task of building up the Modint library along with a peer. We divided the work among ourselves and started to work.

WEEK 11 - I was able complete the basic code for the implementation of the modint library including the constructors, boolean operators, data access operators, and operators for addition, multiplication and subtraction.

WEEK 12 - I implemented functions for division, and also to find the modular inverse, which has use in division.

WEEK 13 - I implemented the Chinese Remainder Theorem in the modint class using Garner's Algorithm after studying it online.

Again we took a break due to our exams.

WEEK 15 - The final task was to implement tests for the modint class. GoogleTest was again giving issues due to which this took some time.

WEEK 16 - I was finally able to complete the tests for the modint library. I tried to make the tests as brutal as possible with all possible variations. Making the tests for the Chinese Remainder Theorem were most challenging as it required the numbers to be coprime to each other. So, I used the Eratosthenes Sieve to compute the primes, and then used them to test the Chinese Remainder Theorem function. I also came across many errors in my code while testing and rectified all of them. I also added tests for LU decomposition, the code for which I had added much earlier.

P.S. - There might be many test files, the ones created by me are - tests/test/MatrixTests.cpp,ModintTest.cpp, both of which have around 200 -300 lines.

WEEK 17 - 18 - We spent some time resolving merge conflicts, looking through other people's code and making minor improvements.

WEEK 19 - present - We started learning about FFT, NTT, Primitive Roots, Point Evaluation of a Polynomial, from Unacademy lectures and CF Blog Posts and are working on that to create a new polynomial library for huge calculations. Work for this is currently underway. 
