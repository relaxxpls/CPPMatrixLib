#include "test1.hpp"

TEST(MatrixTests, MatrixInitTests)
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

INSTANTIATE_TEST_CASE_P(AdditionTests, IntMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<long long int>( 1, 0, 3, 3, 0, 3, 3),
/*1*/	SampleMatrixTest<long long int>( 1, 1, 3, 3, -1, 3, 3),
/*2*/	SampleMatrixTest<long long int>( 1, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleMatrixTest<long long int>( 1, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<long long int>( 1, 100, 10, 20, -100, 10, 20),
/*5*/	SampleMatrixTest<long long int>( 1, 100, 300, 200, -100, 300, 200),
/*6*/	SampleMatrixTest<long long int>( 1, 100, 500, 750, -100, 500, 750),
/*7*/	SampleMatrixTest<long long int>( 1, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(SubtractionTests, IntMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<long long int>( 2, 0, 3, 3, 0, 3, 3),
/*1*/	SampleMatrixTest<long long int>( 2, 1, 3, 3, -1, 3, 3),
/*2*/	SampleMatrixTest<long long int>( 2, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleMatrixTest<long long int>( 2, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<long long int>( 2, 100, 10, 20, -100, 10, 20),
/*5*/	SampleMatrixTest<long long int>( 2, 100, 300, 200, -100, 300, 200),
/*6*/	SampleMatrixTest<long long int>( 2, 100, 500, 750, -100, 500, 750),
/*7*/	SampleMatrixTest<long long int>( 2, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(MatrixMultiplicationTests, IntMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<long long int>( 3, 0, 3, 3, 0, 3, 3),
/*1*/	SampleMatrixTest<long long int>( 3, 1, 3, 3, -1, 3, 3),
/*2*/	SampleMatrixTest<long long int>( 3, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleMatrixTest<long long int>( 3, 100, 10, 10, -100, 10, 20),
/*4*/	SampleMatrixTest<long long int>( 3, -100, 200, 300, -100, 300, 200),
/*5*/	SampleMatrixTest<long long int>( 3, 100, 700, 500, 100, 500, 750),
/*6*/	SampleMatrixTest<long long int>( 3, -300, 1000, 1000, 500, 1000, 1000)
	));

INSTANTIATE_TEST_CASE_P(ScalarMultiplicationTests, IntMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<long long int>( 2, 0, 3, 3, 0, 3, 3),
/*1*/	SampleMatrixTest<long long int>( 2, 1, 3, 3, -1, 3, 3),
/*2*/	SampleMatrixTest<long long int>( 2, -218'724'171, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleMatrixTest<long long int>( 2, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<long long int>( 2, 100, 10, 20, -100, 10, 20),
/*5*/	SampleMatrixTest<long long int>( 2, 100, 300, 200, -100, 300, 200),
/*6*/	SampleMatrixTest<long long int>( 2, 100, 500, 750, -100, 500, 750)
	));

INSTANTIATE_TEST_CASE_P(EqualityTests, IntMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<long long int>( 5, 0, 3, 3, 0, 3, 3),
/*1*/	SampleMatrixTest<long long int>( 5, 1, 3, 3, -1, 3, 3),
/*2*/	SampleMatrixTest<long long int>( 5, 313'458'291, 3, 3, 313'458'291, 3, 3),
/*3*/	SampleMatrixTest<long long int>( 5, 483'173'198'482'947, 3, 3, -593'206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<long long int>( 5, 100, 20, 20, -100, 10, 20),
/*5*/	SampleMatrixTest<long long int>( 5, 100, 300, 200, 100, 300, 200),
/*6*/	SampleMatrixTest<long long int>( 5, 100, 500, 750, -100, 500, 750),
/*7*/	SampleMatrixTest<long long int>( 5, -382'594'278'747'059'728, 1000, 3000, 587'208'068'278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(AdditionTests, FloatMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<double>( 1, 0.0182, 3, 3, 0.0948, 3, 3),
/*1*/	SampleMatrixTest<double>( 1, 1.2839, 3, 3, -1.2739, 3, 3),
/*2*/	SampleMatrixTest<double>( 1, -218'724.171, 3, 3, 313.458'291, 3, 3),
/*3*/	SampleMatrixTest<double>( 1, 483.173'198'482'947, 3, 3, -593.206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<double>( 1, 100.33, 10, 20, -100.33, 10, 20),
/*5*/	SampleMatrixTest<double>( 1, 100.11, 300, 200, -100.22, 300, 200),
/*6*/	SampleMatrixTest<double>( 1, 100.444, 500, 750, -100.444, 500, 750),
/*7*/	SampleMatrixTest<double>( 1, -382'594'278.747'059'728, 1000, 3000, 587'208'068.278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(SubtractionTests, FloatMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<double>( 2, 0.0182, 3, 3, 0.0948, 3, 3),
/*1*/	SampleMatrixTest<double>( 2, 1.2839, 3, 3, -1.2739, 3, 3),
/*2*/	SampleMatrixTest<double>( 2, -218'724.171, 3, 3, 313.458'291, 3, 3),
/*3*/	SampleMatrixTest<double>( 2, 483.173'198'482'947, 3, 3, -593.206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<double>( 2, 100.33, 10, 20, -100.33, 10, 20),
/*5*/	SampleMatrixTest<double>( 2, 100.11, 300, 200, -100.22, 300, 200),
/*6*/	SampleMatrixTest<double>( 2, 100.444, 500, 750, -100.444, 500, 750),
/*7*/	SampleMatrixTest<double>( 2, -382'594'278.747'059'728, 1000, 3000, 587'208'068.278'698'358, 1000, 3000)
	));

INSTANTIATE_TEST_CASE_P(MatrixMultiplicationTests, FloatMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<double>( 3, 0.394, 3, 3, 0.2883, 3, 3),
/*1*/	SampleMatrixTest<double>( 3, 1.2888, 3, 3, -1.2844, 3, 3),
/*2*/	SampleMatrixTest<double>( 3, -218.724'171, 3, 3, 313.458'291, 3, 3),
/*3*/	SampleMatrixTest<double>( 3, 100.44, 10, 10, -100.44, 10, 20),
/*4*/	SampleMatrixTest<double>( 3, -100.222, 200, 300, -100.22, 300, 200),
/*5*/	SampleMatrixTest<double>( 3, 100, 700, 500, 100, 500, 750),
/*6*/	SampleMatrixTest<double>( 3, -300, 1000, 1000, 500, 1000, 1000)
	));

INSTANTIATE_TEST_CASE_P(ScalarMultiplicationTests, FloatMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<double>( 4, 0.0182, 3, 3, 0.0948, 3, 3),
/*1*/	SampleMatrixTest<double>( 4, 1.2839, 3, 3, -1.2739, 3, 3),
/*2*/	SampleMatrixTest<double>( 4, -218'724.171, 3, 3, 313.458'291, 3, 3),
/*3*/	SampleMatrixTest<double>( 4, 483.173'198'482'947, 3, 3, -593.206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<double>( 4, 100.33, 10, 20, -100.33, 10, 20),
/*5*/	SampleMatrixTest<double>( 4, 100.11, 300, 200, -100.22, 300, 200),
/*6*/	SampleMatrixTest<double>( 4, 100.444, 500, 750, -100.444, 500, 750)
	));

INSTANTIATE_TEST_CASE_P(EqualityTests, FloatMatrixTests,
	testing::Values(
/*0*/	SampleMatrixTest<double>( 5, 0.22222, 3, 3, 0.22223, 3, 3),
/*1*/	SampleMatrixTest<double>( 5, 1.000001, 3, 3, 0.9999999, 3, 3),
/*2*/	SampleMatrixTest<double>( 5, 313.458'292, 3, 3, 313.458'292, 3, 3),
/*3*/	SampleMatrixTest<double>( 5, 483.173'198'482'947, 3, 3, -593.206'583'069'789, 3, 3),
/*4*/	SampleMatrixTest<double>( 5, 100.22, 20, 20, -100.22, 10, 20),
/*5*/	SampleMatrixTest<double>( 5, 100.3333, 300, 200, 100.3333, 300, 200),
/*6*/	SampleMatrixTest<double>( 5, 100.22, 500, 750, -100.11, 500, 750),
/*7*/	SampleMatrixTest<double>( 5, -382.594'278'747'059'728, 1000, 3000, 587.208'068'278'698'358, 1000, 3000)
	));