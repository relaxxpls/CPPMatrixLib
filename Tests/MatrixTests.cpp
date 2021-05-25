#include <gtest/gtest.h>
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

class BinaryOperatorFixture 
{
public:
	int lhs_val;
	int rhs_val;
	int add_res_val;
	int sub_res_val;
	int mul_res_val;
	bool eq_res;
	bool ineq_res;
	friend std::ostream& operator<<(std::ostream& os, const BinaryOperatorFixture& obj)
	{
		os << "lhs value: " << obj.lhs_val
		  << "rhs value: " << obj.rhs_val
		  << "add value: " << obj.add_res_val
		  << "sub value: " << obj.sub_res_val
		  << "mul value: " << obj.mul_res_val
		  << "eq result: " << obj.eq_res
		  << "ineq result: " << obj.ineq_res;
		return os;
	}
	BinaryOperatorFixture(int l,int r,int a,int s,int m,bool e,bool i) 
	{
		lhs_val= l;
		rhs_val= r;
		add_res_val= a;
		sub_res_val= s;
		mul_res_val= m;
		eq_res= e;
		ineq_res= i;
	}
};

//template <typename T>
class BinaryOperatorTests : public testing::TestWithParam<BinaryOperatorFixture>
{
public:
	matrix<int> *lhs;
	matrix<int> *rhs;
	matrix<int> *add_res;
	matrix<int> *mul_res;
	matrix<int> *sub_res;
	BinaryOperatorTests()
	{
		lhs= new matrix<int>(3,3,GetParam().lhs_val);
		rhs= new matrix<int>(3,3,GetParam().rhs_val);
		add_res= new matrix<int>(3,3,GetParam().add_res_val);
		sub_res= new matrix<int>(3,3,GetParam().sub_res_val);
		mul_res= new matrix<int>(3,3,GetParam().mul_res_val);
	}
	~BinaryOperatorTests()
	{
		delete lhs;
		delete rhs;
		delete add_res;
		delete sub_res;
		delete mul_res;
	}
};

TEST_P(BinaryOperatorTests, BO)
{
	EXPECT_FALSE((*add_res)==(*lhs)+(*rhs)) << "Addition error at parameter "<<GetParam().lhs_val<<","<<GetParam().rhs_val<<"\n";
	EXPECT_FALSE((*sub_res)==(*lhs)-(*rhs)) << "Subtraction error\n";
	EXPECT_FALSE((*mul_res)==(*lhs)*(*rhs)) << "Multiplication error\n";
	EXPECT_EQ(GetParam().ineq_res,((*lhs)==(*rhs))) << "Equality error\n";
	EXPECT_EQ(GetParam().eq_res,((*lhs)!=(*rhs))) << "Inequality error\n";
}

INSTANTIATE_TEST_CASE_P(IntegerTests, BinaryOperatorTests,
	testing::Values(
	BinaryOperatorFixture(1,1,2,0,3,true,false)
	));
