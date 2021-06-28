#ifndef _MATRIX_TESTS_H_
#define _MATRIX_TESTS_H_
#include <gtest/gtest.h>
#include "../../include/matrix/matrix.hpp"
#include "../../include/matrix/matrix_utility.hpp"

template<typename T>
class SampleMatrixTest 
{
public:
	int type;
	T A_val; size_t A_r; size_t A_c;
	T B_val; size_t B_r; size_t B_c;
	T fac;
	bool res;
	SampleMatrixTest(int t,T a,size_t ar,size_t ac,
		T b,size_t br,size_t bc) 
	{
		type= t;
		A_val= a; A_r= ar; A_c= ac;
		B_val= b; B_r= br; B_c= bc;
        fac= b;
        res= (a==b);
	}
};

class IntMatrixTests : public testing::TestWithParam<SampleMatrixTest<long long int>>
{
public:
	matrix<long long int> *A;
	matrix<long long int> *B;
	matrix<long long int> *C;
	IntMatrixTests()
	{
		auto in= GetParam();
		switch(in.type)
		{
			case 1: {
				A= new matrix<long long int>(in.A_r,in.A_c,in.A_val);
				B= new matrix<long long int>(in.B_r,in.B_c,in.B_val);
				C= new matrix<long long int>(in.A_r,in.A_c,in.A_val+in.B_val);
				break;
			}
			case 2: {
				A= new matrix<long long int>(in.A_r,in.A_c,in.A_val);
				B= new matrix<long long int>(in.B_r,in.B_c,in.B_val);
				C= new matrix<long long int>(in.A_r,in.A_c,in.A_val-in.B_val);
				break;
			}
			case 3: {
				A= new matrix<long long int>(in.A_r,in.A_c,in.A_val);
				B= new matrix<long long int>(in.B_r,in.B_c,in.B_val);
				C= new matrix<long long int>(in.A_r,in.B_c,in.A_val*in.B_val*in.A_c);
				break;
			}
			case 4: {
				A= new matrix<long long int>(in.A_r,in.A_c,in.A_val);
				B= new matrix<long long int>(in.A_r,in.A_c,in.A_val*in.B_val);
				C= new matrix<long long int>();
				break;
			}
			case 5: {
				A= new matrix<long long int>(in.A_r,in.A_c,in.A_val);
				B= new matrix<long long int>(in.B_r,in.B_c,in.B_val);
				C= new matrix<long long int>();
				break;
			}
		}
	}
	~IntMatrixTests()
	{
		delete A;
		delete B;
		delete C;
	}
};

TEST_P(IntMatrixTests, IntTests)
{
	auto in= GetParam();
	switch(in.type)
	{
		case 1: {
			EXPECT_TRUE((*C)==(*A)+(*B)) 
				<< "Error with operator+ for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			*A+= *B;
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator+= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 2: {
			EXPECT_TRUE((*C)==(*A)-(*B)) 
				<< "Error with operator- for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			*A-= *B;
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator-= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 3: {
			EXPECT_TRUE((*C)==(*A)*(*B)) 
				<< "Error with operator* for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			(*A)*= (*B);
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator*= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 4: {
			EXPECT_TRUE((*B)==(*A)*in.fac) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			EXPECT_TRUE((*A)*(-1)==-(*A)) 
				<< "Error with operator- for \nA=\n" << *A;
            EXPECT_TRUE((*A)==A->t()) 
				<< "Error with t() for \nA=\n" << *A;
			EXPECT_TRUE((*B)==in.fac*(*A)) 
				<< "Error with operator* for \nfac=" << in.fac << "\nA=\n" << *A << "\nB=\n" << *B;
			*A*= in.fac;
			EXPECT_TRUE((*B)==(*A)) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			break;
		}
		case 5: {
			EXPECT_EQ(in.res,(*B)==(*A))
				<< "Error with operator== for \nA=\n" << *A << "B=\n" << *B << "res= " << "\n";
			EXPECT_EQ(!(in.res),(*B)!=(*A))
				<< "Error with operator!= for \nA=\n" << *A << "B=\n" << *B << "res= " << "\n";
			break;
		}
	}
}

class FloatMatrixTests : public testing::TestWithParam<SampleMatrixTest<double>>
{
public:
	matrix<double> *A;
	matrix<double> *B;
	matrix<double> *C;
	FloatMatrixTests()
	{
		auto in= GetParam();
		switch(in.type)
		{
			case 1: {
				A= new matrix<double>(in.A_r,in.A_c,in.A_val);
				B= new matrix<double>(in.B_r,in.B_c,in.B_val);
				C= new matrix<double>(in.A_r,in.A_c,in.A_val+in.B_val);
				break;
			}
			case 2: {
				A= new matrix<double>(in.A_r,in.A_c,in.A_val);
				B= new matrix<double>(in.B_r,in.B_c,in.B_val);
				C= new matrix<double>(in.A_r,in.A_c,in.A_val-in.B_val);
				break;
			}
			case 3: {
				A= new matrix<double>(in.A_r,in.A_c,in.A_val);
				B= new matrix<double>(in.B_r,in.B_c,in.B_val);
				C= new matrix<double>(in.A_r,in.B_c,in.A_val*in.B_val*in.A_c);
				break;
			}
			case 4: {
				A= new matrix<double>(in.A_r,in.A_c,in.A_val);
				B= new matrix<double>(in.A_r,in.A_c,in.A_val*in.B_val);
				C= new matrix<double>();
				break;
			}
			case 5: {
				A= new matrix<double>(in.A_r,in.A_c,in.A_val);
				B= new matrix<double>(in.B_r,in.B_c,in.B_val);
				C= new matrix<double>();
				break;
			}
		}
	}
	~FloatMatrixTests()
	{
		delete A;
		delete B;
		delete C;
	}
};

TEST_P(FloatMatrixTests, FloatTests)
{
	auto in= GetParam();
	switch(in.type)
	{
		case 1: {
			EXPECT_TRUE((*C)==(*A)+(*B)) 
				<< "Error with operator+ for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			*A+= *B;
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator+= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 2: {
			EXPECT_TRUE((*C)==(*A)-(*B)) 
				<< "Error with operator- for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			*A-= *B;
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator-= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 3: {
			EXPECT_TRUE((*C)==(*A)*(*B)) 
				<< "Error with operator* for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			(*A)*= (*B);
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator*= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 4: {
			EXPECT_TRUE((*B)==(*A)*in.fac) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			EXPECT_TRUE((*A)*(-1)==-(*A)) 
				<< "Error with operator- for \nA=\n" << *A;
			EXPECT_TRUE((*B)==in.fac*(*A)) 
				<< "Error with operator* for \nfac=" << in.fac << "\nA=\n" << *A << "\nB=\n" << *B;
			*A*= in.fac;
			EXPECT_TRUE((*B)==(*A)) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			break;
		}
		case 5: {
			EXPECT_EQ(in.res,(*B)==(*A))
				<< "Error with operator== for \nA=\n" << *A << "B=\n" << *B << "res= " << "\n";
			EXPECT_EQ(!(in.res),(*B)!=(*A))
				<< "Error with operator!= for \nA=\n" << *A << "B=\n" << *B << "res= " << "\n";
			break;
		}
	}
}

#endif