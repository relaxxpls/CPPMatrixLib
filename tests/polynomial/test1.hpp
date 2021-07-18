#ifndef _POLYTESTS_H_
#define _POLYTESTS_H_
#include <gtest/gtest.h>
#include "../../include/polynomial/polynomial.hpp"
#include "../../include/polynomial/polynomial_utility.hpp"

template<typename T>
class SamplePolyTest 
{
public:
	int type;
	T p_val; size_t p_d;
	T q_val; size_t q_d;
	T fac;
	bool res;
	SamplePolyTest(int t,T p,size_t pd,
		T q,size_t qd) 
	{
		type= t;
		p_val= p; p_d= pd;
		q_val= q; q_d= qd;
        fac= q;
        res= (p==q);
	}
};

class FloatPolyTests : public testing::TestWithParam<SamplePolyTest<double>>
{
public:
	polynomial<double> *P;
	polynomial<double> *Q;
	polynomial<double> *R;
	FloatPolyTests()
	{
		auto in= GetParam();
		switch(in.type)
		{
			case 1: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.q_d,in.q_val);
				R= new polynomial<double>(in.p_d,in.p_val);
                for(size_t i=0;i<in.q_d+1;i++)
                {
                    (*R)[i]+= in.q_val;
                }
				break;
			}
			case 2: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.q_d,in.q_val);
				R= new polynomial<double>(in.p_d,in.p_val);
                for(size_t i=0;i<in.q_d+1;i++)
                {
                    (*R)[i]-= in.q_val;
                }
				break;
			}
			case 3: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.q_d,in.q_val);
				R= new polynomial<double>(in.p_d+in.q_d,in.p_val*in.q_val);
                for(size_t i=0;i<in.p_d+in.q_d+1;i++)
                {
                    if( i<in.q_d+1 )
                    {
                        (*R)[i]*= i+1;
                    }
                    else if( i<in.p_d+1 )
                    {
                        (*R)[i]*= in.q_d+1;
                    }
                    else
                    {
                        (*R)[i]*= in.p_d+in.q_d-i+1;
                    }
                }
				break;
			}
			case 4: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.p_d,in.p_val*in.q_val);
				R= new polynomial<double>();
				break;
			}
			case 5: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.q_d,in.q_val);
				R= new polynomial<double>();
				break;
			}
            case 6: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>(in.q_d,in.q_val);
				R= new polynomial<double>(in.p_d+in.q_d,in.p_val*in.q_val);
                for(size_t i=0;i<in.p_d+in.q_d+1;i++)
                {
                    if( i<in.q_d+1 )
                    {
                        (*R)[i]*= i+1;
                    }
                    else if( i<in.p_d+1 )
                    {
                        (*R)[i]*= in.q_d+1;
                    }
                    else
                    {
                        (*R)[i]*= in.p_d+in.q_d-i+1;
                    }
                }
				break;
			}
			case 7: {
				P= new polynomial<double>(in.p_d,in.p_val);
				Q= new polynomial<double>();
				R= new polynomial<double>();
				break;
			}
		}
	}
	~FloatPolyTests()
	{
		delete P;
		delete Q;
		delete R;
	}
};

TEST_P(FloatPolyTests, FloatTests)
{
	auto in= GetParam();
	switch(in.type)
	{
		case 1: {
			EXPECT_TRUE((*R)==(*P)+(*Q))
				<< "Error with operator+ for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			*P+= *Q;
			EXPECT_TRUE((*R)==(*P))
				<< "Error with operator+= for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			break;
		}
		case 2: {
			EXPECT_TRUE((*R)==(*P)-(*Q))
				<< "Error with operator- for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			*P-= *Q;
			EXPECT_TRUE((*R)==(*P))
				<< "Error with operator-= for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			break;
		}
		case 3: {
			EXPECT_TRUE((*R)==(*P)*(*Q))
				<< "Error with operator* for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			(*P)*= (*Q);
			EXPECT_TRUE((*R)==(*P))
				<< "Error with operator*= for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			break;
		}
		case 4: {
			EXPECT_TRUE((*Q)==(*P)*in.fac)
				<< "Error with operator* for \nP=\n" << *P << "fac=" << in.fac << "\nQ=\n" << *Q;
			EXPECT_TRUE((*P)*(-1)==-(*P))
				<< "Error with operator- for \nP=\n" << *P;
			EXPECT_TRUE((*Q)==in.fac*(*P)) 
				<< "Error with operator* for \nfac=" << in.fac << "\nP=\n" << *P << "\nQ=\n" << *Q;
			*P*= in.fac;
			EXPECT_TRUE((*Q)==(*P))
				<< "Error with operator* for \nP=\n" << *P << "fac=" << in.fac << "\nQ=\n" << *Q;
			break;
		}
		case 5: {
			EXPECT_EQ(in.res,(*Q)==(*P))
				<< "Error with operator== for \nP=\n" << *P << "\nQ=\n" << *Q << "\nres= " << "\n";
			EXPECT_EQ(!(in.res),(*Q)!=(*P))
				<< "Error with operator!= for \nP=\n" << *P << "\nQ=\n" << *Q << "\nres= " << "\n";
			break;
		}
		case 6: {
			EXPECT_TRUE((*R)==Karatsuba_Multiply(*P,*Q))
				<< "Error with operator* for \nP=\n" << *P << "\nQ=\n" << *Q << "\nR=\n" << *R;
			break;
		}
		case 7: {
			double ans = in.p_val*(pow(in.fac,in.p_d+1)-1)/(in.fac-1);
			EXPECT_TRUE(abs(ans-P->calculate(in.fac))<=10e-4)
				<< "Error with calculate() for \nP(q)= " << P->calculate(in.fac) << "\nans= " << ans;
			break;
		}
	}
}

#endif