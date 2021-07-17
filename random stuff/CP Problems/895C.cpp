#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long int> vll;
typedef vector<bool> vb;

#define pb push_back
#define sz size()
#define ff first
#define ss second
#define pi 3.14159265359
#define M1 998244353
#define M2 1000000007

ll pow(ll x){

    ll ans=1,num=2;

    while(x>0){

        if(x&1){

            ans*=num;
            ans%=M2;
        }
        num*=num;
        num%=M2;
        x>>=1;
    }
    return ans;
}

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    ll n;

    cin>>n;

    vector<ll> mask(71,0);

    vll fre(71,0);

    int primes[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

    for(int i=0;i<n;i++){

        int x;

        cin>>x;

        fre[x]++;
    }

    for(int x=1;x<=70;x++){

        for(int j=0;j<19;j++){

            int co=0;

            int temp=x;
            
            while(temp%primes[j]==0){

                temp/=primes[j];
                co++;
            }
            if(co%2==1){

                mask[x]=mask[x]|(1<<j);
            }
        } 
    }

    vll odd(71,0);
    vll even(71,1);

    for(int i=1;i<=70;i++){

        if(!fre[i]){

            continue;
        }

        fre[i]=pow(fre[i]-1);
        even[i]=odd[i]=fre[i];
    }

    vector<vi> dp(71,vi(1<<19,0));

    dp[0][0]=1;

    for(int i=1;i<=70;i++){

        for(int j=0;j<(1<<19);j++){

            dp[i][j]=(dp[i-1][j]*1LL*even[i])%M2+(dp[i-1][j^mask[i]]*1LL*odd[i])%M2;
            dp[i][j]%=M2;   
        }
    }

    cout<<dp[70][0]-1<<"\n";
    
}

