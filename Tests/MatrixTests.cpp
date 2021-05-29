#include <gtest/gtest.h>
#include <iostream>
#include "../../matrix.hpp"
#include "../../matrix_utility.hpp"

TEST(MatirxTests, MatrixInitTests)
{
	matrix<int> a;
	EXPECT_EQ(true,a.empty()) << "Default constructor / empty()";
	EXPECT_EQ(std::make_pair((long unsigned int)0,(long unsigned int)0),a.size()) <<  "Default constructor / size()";
	a.resize(2,3);
	EXPECT_EQ(false,a.empty()) << "resize() / empty()";
	EXPECT_EQ(std::make_pair((long unsigned int)2,(long unsigned int)3),a.size()) << "resize() / size()";

	matrix<int> b= {{1,2,3},
					{4,5,6},
					{7,8,9}};
	EXPECT_EQ(false,b.empty()) << "List constructor / empty()";
	EXPECT_EQ(std::make_pair((long unsigned int)3,(long unsigned int)3),b.size()) << "List constructor / size()";
	b.resize(0,0);
	EXPECT_EQ(true,b.empty()) << "resize() / empty()";
	EXPECT_EQ(std::make_pair((long unsigned int)0,(long unsigned int)0),b.size()) << "resize() / size()";

	matrix<int> c(3,2);
	EXPECT_EQ(false,c.empty()) << "Size constructor / empty()";
	EXPECT_EQ(std::make_pair((long unsigned int)3,(long unsigned int)2),c.size()) << "Size constructor / size()";
	a.resize(3,2);
	EXPECT_TRUE(a==c) << "Size constructor / resize() / operator==";

	matrix<int> d(2,2,100);
	b.resize(2,2,100);
	c.resize(2,2,101);
	a.resize(3,3,100);
	EXPECT_TRUE(d==b) << "Size constructor / resize() / operator==";
	EXPECT_FALSE(d==c) << "Size constructor / resize() / operator==";
	EXPECT_FALSE(d==a) << "Size constructor / resize() / operator==";
} 

template<typename T>
class SampleTest 
{
public:
	int type;
	T A_val=0; size_t A_r=0; size_t A_c=0;
	T B_val=0; size_t B_r=0; size_t B_c=0;
	//T C_val=0; size_t C_r=0; size_t C_c=0;
	T fac=0;
	bool res=false;
	SampleTest(int t,T a,size_t ar,size_t ac,
		T b,size_t br,size_t bc) 
	{
		type= t;
		A_val= a; A_r= ar; A_c= ac;
		B_val= b; B_r= br; B_c= bc;
	}
	SampleTest(int t,T a,size_t ar,size_t ac,T f)
	{
		type= t;
		A_val= a; A_r= ar; A_c= ac;
		fac= f;
	}
	SampleTest(int t,T a,size_t ar,size_t ac,
		T b,size_t br,size_t bc,
		bool r) 
	{
		type= t;
		A_val= a; A_r= ar; A_c= ac;
		B_val= b; B_r= br; B_c= bc;
		res= r;
	}
};

class IntTests : public testing::TestWithParam<SampleTest<long long int>>
{
public:
	matrix<long long int> *A;
	matrix<long long int> *B;
	matrix<long long int> *C;
	IntTests()
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
				B= new matrix<long long int>(in.A_r,in.A_c,in.A_val*in.fac);
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
	~IntTests()
	{
		delete A;
		delete B;
		delete C;
	}
};

TEST_P(IntTests, MatirxTests)
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
				<< "Error with operator* for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;;
			(*A)*= (*B);
			EXPECT_TRUE((*C)==(*A))
				<< "Error with operator*= for \nA=\n" << *A << "B=\n" << *B << "C=\n" << *C;
			break;
		}
		case 4: {
			EXPECT_TRUE((*B)==(*A)*(in.fac)) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			EXPECT_TRUE((*A)*(-1)==-(*A)) 
				<< "Error with operator- for \nA=\n" << *A;
			EXPECT_TRUE((*B)==(in.fac)*(*A)) 
				<< "Error with operator* for \nfac=" << in.fac << "\nA=\n" << *A << "\nB=\n" << *B;
			*A*= in.fac;
			EXPECT_TRUE((*B)==(*A)) 
				<< "Error with operator* for \nA=\n" << *A << "fac=" << in.fac << "\nB=\n" << *B;
			break;
		}
		case 5: {
			EXPECT_EQ(in.res,(*B)==(*A)) 
				<< "Error with operator== for \nA=\n" << *A << "B=\n" << *B << "res= " << in.res << "\n";
			EXPECT_EQ(!(in.res),(*B)!=(*A))
				<< "Error with operator!= for \nA=\n" << *A << "B=\n" << *B << "res= " << in.res << "\n";
			break;
		}
	}
	
}

INSTANTIATE_TEST_CASE_P(AdditionTests, IntTests,
	testing::Values(
/*0*/	SampleTest<long long int>( 1, 0, 3, 3, 0, 3, 3),
/*1*/	SampleTest<long long int>( 1, 1, 3, 3, -1, 3, 3),
/*2*/	SampleTest<long long int>( 1, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleTest<long long int>( 1, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleTest<long long int>( 1, 100, 10, 20, -100, 10, 20),
/*5*/	SampleTest<long long int>( 1, 100, 300, 200, -100, 300, 200),
/*6*/	SampleTest<long long int>( 1, 100, 500, 750, -100, 500, 750),
/*7*/	SampleTest<long long int>( 1, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(SubtractionTests, IntTests,
	testing::Values(
/*0*/	SampleTest<long long int>( 2, 0, 3, 3, 0, 3, 3),
/*1*/	SampleTest<long long int>( 2, 1, 3, 3, -1, 3, 3),
/*2*/	SampleTest<long long int>( 2, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleTest<long long int>( 2, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleTest<long long int>( 2, 100, 10, 20, -100, 10, 20),
/*5*/	SampleTest<long long int>( 2, 100, 300, 200, -100, 300, 200),
/*6*/	SampleTest<long long int>( 2, 100, 500, 750, -100, 500, 750),
/*7*/	SampleTest<long long int>( 2, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(MatrixMultiplicationTests, IntTests,
	testing::Values(
/*0*/	SampleTest<long long int>( 3, 0, 3, 3, 0, 3, 3),
/*1*/	SampleTest<long long int>( 3, 1, 3, 3, -1, 3, 3),
/*2*/	SampleTest<long long int>( 3, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleTest<long long int>( 3, 100, 10, 10, -100, 10, 20),
/*4*/	SampleTest<long long int>( 3, -100, 200, 300, -100, 300, 200),
/*5*/	SampleTest<long long int>( 3, 100, 700, 500, 100, 500, 750),
/*6*/	SampleTest<long long int>( 3, -300, 1000, 1000, 500, 1000, 1000)
	));

INSTANTIATE_TEST_CASE_P(ScalarMultiplicationTests, IntTests,
	testing::Values(
/*0*/	SampleTest<long long int>( 4, 0, 3, 3, 10),
/*1*/	SampleTest<long long int>( 4, 1, 3, 3, -1),
/*2*/	SampleTest<long long int>( 4, -218'724'171, 3, 3, 313'458'291),
/*3*/	SampleTest<long long int>( 4, 100, 10, 10, -100),
/*4*/	SampleTest<long long int>( 4, -100, 200, 300, -100),
/*5*/	SampleTest<long long int>( 4, 100, 700, 500, 100),
/*6*/	SampleTest<long long int>( 4, -300, 1000, 1000, 500)
	));

INSTANTIATE_TEST_CASE_P(EqualityTests, IntTests,
	testing::Values(
/*0*/	SampleTest<long long int>( 5, 0, 3, 3, 0, 3, 3, true),
/*1*/	SampleTest<long long int>( 5, 1, 3, 3, -1, 3, 3, false),
/*2*/	SampleTest<long long int>( 5, 313'458'291, 3, 3, 313'458'291, 3, 3, true),
/*3*/	SampleTest<long long int>( 5, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3, false),
/*4*/	SampleTest<long long int>( 5, 100, 20, 20, -100, 10, 20, false),
/*5*/	SampleTest<long long int>( 5, 100, 300, 200, 100, 300, 200, true),
/*6*/	SampleTest<long long int>( 5, 100, 500, 750, -100, 500, 750, false),
/*7*/	SampleTest<long long int>( 5, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000, false)
	));