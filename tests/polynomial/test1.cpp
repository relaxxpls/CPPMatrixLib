#include "test1.hpp"

TEST(PolyTests, PolyInitTests)
{
	polynomial<double> a;
	EXPECT_EQ(true,a.empty()) << "Default constructor / empty()";
	EXPECT_EQ((long unsigned int)-1,a.degree()) <<  "Default constructor / degree()";
	a.resize(3);
	EXPECT_EQ(false,a.empty()) << "resize() / empty()";
	EXPECT_EQ((long unsigned int)3,a.degree()) << "resize() / degree()";

	polynomial<double> b= {1.333333,2.456789,3.987654};
	EXPECT_EQ(false,b.empty()) << "List constructor / empty()";
	EXPECT_EQ(2,b.degree()) << "List constructor / degree()";
    EXPECT_TRUE(abs(1.333333-b[0])<=_MN_ERR) << b << "\nList constructor / [] access operator";
    EXPECT_TRUE(abs(2.456789-b[1])<=_MN_ERR) << b << "\nList constructor / [] access operator";
    EXPECT_TRUE(abs(3.987654-b[2])<=_MN_ERR) << b << "\nList constructor / [] access operator";
	b.resize(0);
	EXPECT_EQ(false,b.empty()) << "resize() / empty()";
	EXPECT_EQ(0,b.degree()) << "resize() / degree()";

	polynomial<double> c(3);
	EXPECT_EQ(false,c.empty()) << "Size constructor / empty()";
	EXPECT_EQ(3,c.degree()) << "Size constructor / degree()";
	a.resize(3);
	EXPECT_TRUE(a==c) << "Size constructor / resize() / operator==";

	polynomial<double> d(10,1.55);
    EXPECT_TRUE(abs(1.55-d[0])<=_MN_ERR) << d << "\nSize constructor / [] access operator";
	b.resize(10,1.55);
	c.resize(10,1.50);
	a.resize(11,1.55);
	EXPECT_TRUE(d==b) << "Size constructor / resize() / operator==";
	EXPECT_FALSE(d==c) << "Size constructor / resize() / operator==";
	EXPECT_FALSE(d==a) << "Size constructor / resize() / operator==";

	polynomial<double> e={1.55,3.1,4.65,6.2,7.75,9.3,10.85,12.4,13.95,15.5};
	EXPECT_TRUE(e==d.derivative()) << "List constructor / derivative()\n" << d.derivative() <<"\n";
	polynomial<double> f={3.1,9.3,18.6,31,46.5,65.1,86.8,111.6,139.5};
	EXPECT_TRUE(f==higher_order_derivative(d,2)) << "List constructor / higher_order_derivative()\n" << higher_order_derivative(d,2) <<"\n";
}

INSTANTIATE_TEST_CASE_P(AdditionTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 1, 0.0182, 3, 0.0948, 3),
/*1*/	SamplePolyTest<double>( 1, 1.2839, 3, -1.2739, 3),
/*2*/	SamplePolyTest<double>( 1, -218'724.171, 5, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 1, 483.173'198'482'947, 5, -593.206'583'069'789, 3),
/*4*/	SamplePolyTest<double>( 1, 100.33, 20, -100.33, 10),
/*5*/	SamplePolyTest<double>( 1, 100.11, 300, -100.22, 200),
/*6*/	SamplePolyTest<double>( 1, 100.444, 750, -100.444, 500),
/*7*/	SamplePolyTest<double>( 1, -382'594'278.747'059'728, 3000, 587'208'068.278'698'358, 3000)
	));

INSTANTIATE_TEST_CASE_P(SubtractionTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 1, 0.0182, 3, 0.0948, 3),
/*1*/	SamplePolyTest<double>( 1, 1.2839, 3, -1.2739, 3),
/*2*/	SamplePolyTest<double>( 1, -218'724.171, 5, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 1, 483.173'198'482'947, 5, -593.206'583'069'789, 3),
/*4*/	SamplePolyTest<double>( 1, 100.33, 20, -100.33, 10),
/*5*/	SamplePolyTest<double>( 1, 100.11, 300, -100.22, 200),
/*6*/	SamplePolyTest<double>( 1, 100.444, 750, -100.444, 500),
/*7*/	SamplePolyTest<double>( 1, -382'594'278.747'059'728, 3000, 587'208'068.278'698'358, 3000)
	));

INSTANTIATE_TEST_CASE_P(PolyMultiplicationTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 3, 0.394, 3, 0.2883, 3),
/*1*/	SamplePolyTest<double>( 3, 1.2888, 5, -1.2844, 3),
/*2*/	SamplePolyTest<double>( 3, -218.724'171, 7, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 3, 100.44, 11, -100.44, 10),
/*4*/	SamplePolyTest<double>( 3, -100.222, 1100, -100.22, 1000),
/*5*/	SamplePolyTest<double>( 3, 100, 5100, 100, 5000),
/*6*/	SamplePolyTest<double>( 3, -300, 11000, 500, 10000)
/*7*/	//SamplePolyTest<double>( 3, -300, 51000, 500, 50000)
	));

INSTANTIATE_TEST_CASE_P(ScalarMultiplicationTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 1, 0.0182, 3, 0.0948, 3),
/*1*/	SamplePolyTest<double>( 1, 1.2839, 3, -1.2739, 3),
/*2*/	SamplePolyTest<double>( 1, -218'724.171, 5, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 1, 483.173'198'482'947, 5, -593.206'583'069'789, 3),
/*4*/	SamplePolyTest<double>( 1, 100.33, 20, -100.33, 10),
/*5*/	SamplePolyTest<double>( 1, 100.11, 300, -100.22, 200),
/*6*/	SamplePolyTest<double>( 1, 100.444, 750, -100.444, 500)
	));

INSTANTIATE_TEST_CASE_P(EqualityTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 5, 0.22222, 3, 0.22223, 3),
/*1*/	SamplePolyTest<double>( 5, 1.000001, 3, 0.9999999, 3),
/*2*/	SamplePolyTest<double>( 5, 313.458'291, 3, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 5, 483.173'198'482'947, 3, -593.206'583'069'789, 3),
/*4*/	SamplePolyTest<double>( 5, 100.22, 20, -100.22, 20),
/*5*/	SamplePolyTest<double>( 5, 100.3333, 300, 100.3333, 300),
/*6*/	SamplePolyTest<double>( 5, 100.22, 750, -100.11, 750),
/*7*/	SamplePolyTest<double>( 5, -382.594'278'747'059'728, 3000, 587.208'068'278'698'358, 3000)
	));

INSTANTIATE_TEST_CASE_P(KaratMultiplicationTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 6, 0.394, 3, 0.2883, 3),
/*1*/	SamplePolyTest<double>( 6, 1.2888, 5, -1.2844, 3),
/*2*/	SamplePolyTest<double>( 6, -218.724'171, 7, 313.458'291, 3),
/*3*/	SamplePolyTest<double>( 6, 100.44, 11, -100.44, 10),
/*4*/	SamplePolyTest<double>( 6, -100.222, 1100, -100.22, 1000),
/*5*/	SamplePolyTest<double>( 6, 100, 5100, 100, 5000),
/*6*/	SamplePolyTest<double>( 6, -300, 11000, 500, 10000)
/*7*/	//SamplePolyTest<double>( 6, -300, 51000, 500, 50000)
	));

INSTANTIATE_TEST_CASE_P(CalculateTests, FloatPolyTests,
	testing::Values(
/*0*/	SamplePolyTest<double>( 7, 0.0182, 3, 0.0948, 3),
/*1*/	SamplePolyTest<double>( 7, 1.2839, 3, -1.2739, 3),
/*2*/	SamplePolyTest<double>( 7, -218'724.171, 5, 0.313'458'291, 3),
/*3*/	SamplePolyTest<double>( 7, 483.173'198'482'947, 5, -0.593'206'583'069'789, 3),
/*4*/	SamplePolyTest<double>( 7, 100.33, 20, -100.33, 10)
	));