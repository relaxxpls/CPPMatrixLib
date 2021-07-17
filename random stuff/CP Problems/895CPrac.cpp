#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <chrono>
#include <unordered_set>

using namespace std;

typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<int64_t> vll;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;

#define pb push_back
#define pob pop_back()
#define sz size()
#define ff first
#define ss second
#define PI 3.14159265359
#define M1 ll(998244353)
#define M2 ll(1000000007)
#define INF 2000000000000000000
#define NINF -2000000000000000000
#define loop0(i,n) for(ll i=0;i<n;i++)
#define loop1(i,n) for(ll i=1;i<=n;i++)
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"

//------Standard Functions------
template<typename T>
T max3(T a,T b,T c){

    return max(a,max(b,c));
}

template<typename T>
T max4(T a,T b,T c,T d){

    return max(max(a,d),max(b,c));
}
template<typename T>
T min3(T a,T b,T c){

    return min(a,min(b,c));
}

template<typename T>
T min4(T a,T b,T c,T d){

    return min(min(a,d),min(b,c));
}
template <typename T>
T binex(T a, T b, T mod){

    T ans=1;
    a%=mod;

    while(b>0){

        if(b&1){

            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}

template <class T>
ostream& operator<<(ostream &os, vector<T> a){

    //os<<"[ ";
    for(auto x:a){

        os<<x<<" ";
    }
    //return os<<"]"<<"\n";
    return os<<"\n";
}

template <class T>
ostream& operator<<(ostream &os, set<T> a){

    //os<<"{ ";
    for(auto x:a){

        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os<<"\n";
}

//------Start------


//------Global Variables------

vll num(71,0);

vll primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

void precomp(){

    num[1]=0;
    
    for(ll i=2;i<=70;i++){

        ll temp=i;

        for(ll j=0;j<primes.sz;j++){

            ll co=0;

            ll x=primes[j];

            while(temp%x==0){

                co++;
                temp/=x;
            }
            co=co%2;
            if(co){

                num[i]=num[i]|(1<<j);
            }
        }
    }

}

void solve(){

    ll n;
    cin>>n;

    vll a(n);

    vll fre(71,0);

    loop0(i,n){

        cin>>a[i];

        fre[a[i]]++;
    }

    vvi dp(71,vi(1<<19,0));

    vvi pos(71,vi(2));

    for(ll i=1;i<=70;i++){

        if(fre[i]==0){

            pos[i][0]=1;
            pos[i][1]=0;
            continue;
        }
        
        pos[i][0]=pos[i][1]=binex(ll(2),fre[i]-1,M2);
    }

    dp[0][0]=1;

    //cout<<"Reacher"<<endl;

    //cout<<num;

    for(ll i=1;i<=70;i++){

        //cout<<"TEst: "<<i<<endl;

        for(ll j=0;j<(1<<19);j++){

            dp[i][j]=((dp[i-1][j]*1LL*pos[i][0])%M2+(dp[i-1][j^num[i]]*1LL*pos[i][1])%M2)%M2;
        }
    }
    
    cout<<(dp[70][0]+M2-1)%M2<<"\n";

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;

    T=1;

    precomp();

    loop1(I,T){

        solve();
        //cout<<"Case #"<<I<<": "<<ans<<"\n";

    }
}


//auto start = chrono::high_resolution_clock::now();
//auto stop = chrono::high_resolution_clock::now();
//auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//cout << "Time: "<< duration.count() << " microseconds" << endl;