#include <gtest/gtest.h>
#include "../../matrix.hpp"
#include "../../matrix_utility.hpp"

TEST(MatirxTests, SingleMatrixTests)
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