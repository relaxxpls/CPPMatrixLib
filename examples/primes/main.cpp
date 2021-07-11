#include <iostream>
#include"primes_utility.h"
#include"prime_tests.h"
using namespace std;

int main()
{
	long long int x = 12;
	//phi of x reprsents number of numbers less than 12 such that gcd of that number with 12 is 1
	cout <<"phi of x is "<<  phi(x) << endl;
	//is_prime function detrmines wheather the number is prime or not
	if (is_prime(x))
	{
		cout << x << " is prime" << endl;
	}
	else
	{
		cout << x << " is not a prime number" << endl;
	}
	//is_primitive checks wheather a given root is primitive root or not
	if (is_primitive(x, 97)) 
	{
		cout << x << " is a primitive root of 97" << endl;
	}
	else
	{
		cout << x << " is not a primitive root of 97" << endl;
	}
	//primitive root function returns the smallest primitive root when we input a prime number
	cout << "smallest primitive root of x is " << primitive_root(x) << endl;
}










































































































