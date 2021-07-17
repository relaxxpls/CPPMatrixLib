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
typedef vector<long long int> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvll;
typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef vector<vector<long double>> vvld;
typedef vector<long double> vld;

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

//a goes to a-bk

void rowop(vvld &mat, vld &ans, ll a , ll b, ld k){

    loop0(i,mat.sz){

        mat[a][i]=mat[a][i]-mat[b][i]*k;
    }
    ans[a]=ans[a]-ans[b]*k;
}

void solve(){

    ll n,st,end;
    cin>>n>>st>>end;

    vll sum(n+1,0);

    vvld prob(n+1,vld(n+1,0));

    loop0(i,n-1){

        ll u,v,c;
        
        cin>>u>>v>>c;

        prob[u][v]=c;
        prob[v][u]=c;
        sum[u]+=c;
        sum[v]+=c;
    }

    loop1(i,n){

        loop1(j,n){

            prob[i][j]/=sum[i];
        }
    }

    vvld mat(n,vld(n));

    ll coi=1, coj=1;

    loop1(i,n-1){

        if(coi==end){

            i--;
            coi++;
            continue;
        }

        coj=1;

        loop1(j,n-1){

            if(coj==end){
                
                j--;
                coj++;
                continue;
            }

            mat[i][j]=-prob[coi][coj];

            if(i==j){

                mat[i][j]++;
            }
            coj++;
        }
        coi++;
    }

    vld ans(n,1);
    vld values(n,-1);

    loop1(i,n-1){

        for(ll j=i+1;j<n;j++){

            ld k=mat[j][i]/mat[i][i];

            rowop(mat,ans,j,i,k);
        }
    }

    values[n-1]=ans[n-1]/mat[n-1][n-1];

    for(ll i=n-2;i>=1;i--){

        for(ll j=n-1;j>i;j--){

            ans[i]=ans[i]-mat[i][j]*values[j];
        }
        values[i]=ans[i]/mat[i][i];
    }

    if(st<end){

        cout<<setprecision(5)<<fixed<<values[st]<<"\n";
    }else if(st>end){

        cout<<setprecision(5)<<fixed<<values[st-1]<<"\n";
    }else{

        cout<<setprecision(5)<<fixed<<0<<"\n";
    }
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