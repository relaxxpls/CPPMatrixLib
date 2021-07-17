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
#include <unordered_map>

using namespace std;

typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<int64_t> vll;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<int64_t>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
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


void precomp(){

    

}

void solve(){

    ll n,m,temp,temp2;

    cin>>temp>>temp2;

    n=temp;
    m=temp2;

    ll fans=0;

    /*if(m==1){

        cout<<1<<"\n";
        return;
    }*/

    vvll a(2,vll(2,0));

    a[0][0]=(m-1)%M2;
    a[0][1]=(m-1)%M2;
    a[1][0]=1;

    m%=M2;

    //o2(a[0][0],a[0][1]);

    n-=2;

    vvll ans(2,vll(2,0));

    ans[0][0]=1;
    ans[1][1]=1;

    while(n>0){

        if(n&1){

            vvll c(2,vll(2,0));
            
            for(int i=0;i<2;i++){

                for(int j=0;j<2;j++){

                    c[i][j]=((ans[i][0]*a[0][j])%M2+(ans[i][1]*a[1][j])%M2)%M2;
                }
            }

            for(int i=0;i<2;i++){

                for(int j=0;j<2;j++){

                    ans[i][j]=c[i][j];
                }
            }
        }

        vvll c(2,vll(2,0));
            
        for(int i=0;i<2;i++){

            for(int j=0;j<2;j++){

                c[i][j]=((a[i][0]*a[0][j])%M2+(a[i][1]*a[1][j])%M2)%M2;
            }
        }

        for(int i=0;i<2;i++){

            for(int j=0;j<2;j++){

                a[i][j]=c[i][j];
            }
        }
        
        n>>=1;
    }

    fans+=((((m*m)%M2)*ans[0][0])%M2);

    fans+=((m*ans[0][1])%M2);

    //cout<<"temp: "<<ans[0][0]<<" "<<ans[0][1]<<" "<<m<<"\n";

    fans%=M2;

    if(temp==1){

        fans=m%M2;
    }

    cout<<fans<<"\n";

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;

    cin>>T;

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