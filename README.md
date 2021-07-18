# `CPPMatrixLib` - A Portable Matrix and Primes Library in C++
This is a simple matrix and primes library, that is built to have a similar interface for matrices as compared to MATLAB or NumPy. This library can be used to detect wheather a given number(large number) is prime or not. This library includes many functions related to primes, like primitive roots function to find primitive root of a prime number, euler function to find the value phi of x and many other functions.  

## Timeline of the project:
From start till check point one, we gathered the ideas and features we wanted to add to the project and did a lot of brain storming about the same.
From check point one to check point two, we got familiar with the basics of DSA like divide and conquer approach, few important data Structures, graphs and mainly dynamic programming. In the process we also solved project Euler 258 using the concepts we have learned earlier. After that I started working on the matrix functions finding errors in them and trying to optimize the code to make it work faster. The files related to matrix functions can be directly found in this
repository itself named as matrix_utility.hpp and matrix.hpp.
After check point two I started working on primes library, to do this first I had to spend time on getting familiar with the related prime theory, after that I wrote many functions related to prime numbers, after doing this to test the library, I wrote google tests. All the files related to prime functions can be found in the include folder and the files related to google tests can be found in tests folder.
## Folder wise details:
1) inlude: This folder includes the header files related to prime library which contains all of it's functions.
2) examples/primes: This folder has the demonstration of all the important functions in the library.
3) test: This folder contains the tests written using the frame work of google tests to check the working of all the functions in the library.
4) src: This folder has all the source files at one place.
5) build: This folder has the necessary files which are required to support the use of google tests, basically gtest library and gtest related documents.
Yeah, that's it. 
Happy Coding!!



