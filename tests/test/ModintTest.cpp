#include <gtest/gtest.h>
#include "../../modint.hpp"
#include "../../modint_utility.hpp"
#include <random>

#define random std::mt19937 rng(0);

TEST(MODINT,ChangeMod){

    random
    
    modint<int> a(50,100);

    a(1,20);

    ASSERT_EQ(a[0],10);
    ASSERT_EQ(a[1],20);

    for(int i=0;i<10000;i++){

        int t=rng()>>1;

        if(t==0){

            continue;
        }

        int prev=a[0];

        a(1,t);

        ASSERT_EQ(a[0],prev%t);

        a(0,rng()>>1);
    }
}

TEST(MODINT, Addition){

    random
    
    modint<int> a(-45,20);
    modint<int> b(103,20);

    modint<int> c=a+b;

    ASSERT_EQ(c[1],20);
    ASSERT_EQ(c[0],18);

    for(int i=0;i<100000;i++){

        int t1=rng()>>1;
        int t2=rng()>>1;
        int t3=rng()>>1;

        if(t3==0){

            continue;
        }

        if(rng()&1){

            t2*=-1;
        }

        if(rng()&1){

            t1*=-1;
        }
        
        a={t1,t3};

        b={t2,t3};

        c=a+b;

        int ans=(t1+t2)%t3;

        if(ans<0){

            ans+=t3;
        }

        ASSERT_EQ(c[1],t3);
        ASSERT_EQ(c[0],ans);
    }
}

TEST(MODINT,Subtraction){

    random
    
    modint<int> a(45,7);
    modint<int> b(32,7);

    modint<int> c=a-b;

    ASSERT_EQ(c[0],6);
    ASSERT_EQ(c[1],7);

    for(int i=0;i<100000;i++){

        int t1=rng()>>1;
        int t2=rng()>>1;
        int t3=rng()>>1;

        if(t3==0){

            continue;
        }

        a={t1,t3};
        b={t2,t3};

        int ans=(t1-t2)%t3;

        if(ans<0){

            ans+=t3;
        }

        c=a-b;

        modint<int> d=-c;

        int ans2=(c[0]==0?0:t3-c[0]);

        ASSERT_EQ(c[0],ans);
        ASSERT_EQ(c[1],t3);

        ASSERT_EQ(d[0],ans2);
        ASSERT_EQ(d[1],t3);
    }
}

TEST(MODINT,Multiplication){

    random
    
    modint<int> a(20,15);
    modint<int> b(140,15);

    modint<int> c=a*b;

    ASSERT_EQ(c[0],10);
    ASSERT_EQ(c[1],15);

    for(int i=0;i<100000;i++){

        int t1=rng()>>1;
        int t2=rng()>>1;
        int t3=rng()>>1;

        if(rng()&1){

            t2*=-1;
        }

        if(rng()&1){

            t1*=-1;
        }

        if(t3==0){

            continue;
        }

        a={t1,t3};

        b={t2,t3};

        c=a*b;

        int ans=(t1*t2)%t3;

        if(ans<0){

            ans+=t3;
        }

        ASSERT_EQ(c[1],t3);
        ASSERT_EQ(c[0],ans);

    }
}

TEST(MODINT_UTILITY,Division){

    random
    
    modint<long long int> a(254,50);

    modint<long long int> b(127,50);

    modint<long long int> c=a/b;

    ASSERT_EQ(c[0],2);
    ASSERT_EQ(c[1],50);

    long long int t3=1000000007;

    a(1,t3);
    b(1,t3);

    for(int i=0;i<100000;i++){

        long long int t2=rng();

        if(t2==0){

            continue;
        }

        long long int ans=rng();
        long long int t1=t2*ans;

        a(0,t1);
        b(0,t2);

        c=a/b;

        ASSERT_EQ(c[0],ans%t3);
        ASSERT_EQ(c[1],t3);
    }

    t3=998244353;

    a(1,t3);
    b(1,t3);

    for(int i=0;i<100000;i++){

        long long int t2=rng();

        if(t2==0){

            continue;
        }

        long long int ans=rng();
        long long int t1=t2*ans;

        a(0,t1);
        b(0,t2);

        c=a/b;

        ASSERT_EQ(c[0],ans%t3);
        ASSERT_EQ(c[1],t3);
    }
}

TEST(MODINT_UTILITY,ChineseRemainderTheorem){

    random
    
    std::vector<long long int> rem={2,0,3,1};
    std::vector<long long int> mod={4,5,7,9};

    long long int a=CRT(mod,rem);

    ASSERT_EQ(a,10);

    std::vector<int> primes;

    std::vector<bool> is_prime(1000005,true);

    for(int i=2;i<1000005;i++){

        if(is_prime[i]){

            primes.push_back(i);

            int j=2*i;

            while(j<1000005){

                is_prime[j]=false;      
                j+=i;
            }
        }
    }

    //For larger numbers and smaller array size

    for(int i=0;i<100000;i++){

        rem.resize(0);
        mod.resize(0);

        long long int ans=rng();

        long long int curr=1;

        while(true){
            
            int p=primes[rng()%primes.size()];

            int val=0;

            for(int i=0;i<mod.size();i++){

                if(p==mod[i]){

                    val=1;
                    break;
                }
            }

            if(val){

                continue;
            }

            if(curr<(1e12)/p){
                
                mod.push_back(p);
                rem.push_back(ans%p);

                curr*=p;
            }else{

                break;
            }   
        }

        long long int a=CRT(mod,rem);

        for(int i=0;i<mod.size();i++){

            ASSERT_EQ(a%mod[i],rem[i]);
        }
    }

    //For smaller numbers and larger array size

    mod.resize(8);
    rem.resize(8);

    for(int i=0;i<100000;i++){

        long long int ans=rng();

        long long int curr=1;

        for(int i=0;i<8;i++){

            int p=primes[rng()%25];

            int val=0;

            for(int j=0;j<i;j++){

                if(p==mod[j]){

                    val=1;
                    break;
                }
            }

            if(val){

                i--;
                continue;
            }

            mod[i]=(p);
            rem[i]=(ans%p);
        }

        long long int a=CRT(mod,rem);

        for(int i=0;i<mod.size();i++){

            ASSERT_EQ(a%mod[i],rem[i]);
        } 
    }
}