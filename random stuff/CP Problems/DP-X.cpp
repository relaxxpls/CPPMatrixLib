#include <iostream>
#include <vector>
#include <fstream>
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
#include <unordered_map>
#include <random>
#include <bitset>

using namespace std;

typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<int64_t> vll;
typedef vector<string> vs;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int64_t>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<double>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<int64_t>>> vvvll;
typedef vector<vector<long double>> vvvld;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<vector<vector<char>>> vvvc;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef tuple<ll,ll,ll> tll;
typedef vector<tll> vtll;

#define pb push_back
#define pob pop_back()
#define sz size()
#define ff first
#define ss second
#define PI 3.14159265359
#define M1 ll(998244353)
#define M2 ll(1000000007)
#define INF 1500000000000000000
#define NINF -1500000000000000000
#define loop0(i,n) for(ll i=0;i<n;i++)
#define loop1(i,n) for(ll i=1;i<=n;i++)
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define time_start auto start = chrono::high_resolution_clock::now();
#define time_stop auto stop = chrono::high_resolution_clock::now();
#define time_duration duration = chrono::duration_cast<chrono::microseconds>(stop - start);
#define time_print cout << "Time: "<< duration.count() << " microseconds" << endl;
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define reach cout<<"Reached!";

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
    return os;
}

template <class T>
ostream& operator<<(ostream &os, set<T> a){

    //os<<"{ ";
    for(auto x:a){

        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os;
}
template <class T,class Q>
ostream& operator<<(ostream &os, pair<T,Q> a){

    os<<"| ";
    os<<a.ff<<", "<<a.ss<<" ";
    return os<<"|";
}

//------Start------


//------Global Variables------


void precomp(){

    

}

void solve(){

    ll n;
    cin>>n;

    vtll a(n+1);

    ll smax=0;

    loop1(i,n){

        ll d,b,c;

        cin>>d>>b>>c;

        a[i]={d+b,d,c};
        smax=max(smax,d+b);
    }

    sort(a.begin(),a.end());

    vll dp(smax+1,0);

    for(ll i=1;i<=n;i++){

        for(ll j=smax-get<1>(a[i]);j>=0;j--){

            if(j<=get<0>(a[i])-get<1>(a[i])){

                dp[j+get<1>(a[i])]=max(dp[j+get<1>(a[i])],dp[j]+get<2>(a[i]));
            } 
        }
    }

    ll ans=0;

    loop0(i,smax+1){

        ans=max(ans,dp[i]);
    }

    cout<<ans<<"\n";

    

    

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

