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
typedef vector<double> vd;
typedef vector<int64_t> vll;
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

ll dfs(vvll &edges,vi &visited, vvll &dp,ll root){

    ll ans=1;

    if(dp[root][visited[root]]!=0){

        return dp[root][visited[root]];
    }

    if(visited[root]==0){
        
        for(auto x:edges[root]){

            if(visited[x]!=-1){

                continue;
            }

            visited[x]=1;

            ans*=dfs(edges,visited,dp,x);
            ans%=M2;

            visited[x]=-1;
        }

        return dp[root][visited[root]]=ans;
        
    }else{

        //cout<<"Root: "<<root<<" "<<"Ans: "<<ans<<"\n";

        for(auto x:edges[root]){

            if(visited[x]!=-1){

                continue;
            }

            ll temp=0;
            
            visited[x]=1;

            temp+=dfs(edges,visited,dp,x);

            visited[x]=0;

            temp+=dfs(edges,visited,dp,x);
            temp%=M2;

            ans*=temp;
            ans%=M2;

            visited[x]=-1;
        }

        return dp[root][visited[root]]=ans;
    }
    
    /*(if(visited[root]==0){

        vll temp;
        
        for(auto x:edges[root]){

            if(visited[x]!=-1){

                continue;
            }

            visited[x]=1;

            ans+=dfs(edges,visited,x);

            temp.pb(x);

            ans%=M2;
        }

        for(auto x:temp){

            visited[x]=-1;
        }

    }else{

        vll temp;
        
        for(auto x:edges[root]){

            if(visited[x]!=-1){

                continue;
            }

            visited[x]=1;

            ans+=dfs(edges,visited,x);

            ans%=M2;
        }

        for(auto x:temp){

            visited[x]=0;

            ans+=dfs(edges,visited,x);

            ans%=M2;
        }

        for(auto x:temp){

            visited[x]=-1;
        }
    }
    
    return ans==0?1:ans;*/
}

void solve(){

    ll n;
    cin>>n;

    vi visited(n+1,-1);

    vvll edges(n+1);

    loop1(i,n-1){

        ll a,b;

        cin>>a>>b;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    vvll dp(n+1,vll(2,0));

    visited[1]=1;

    ll ans=0;

    ans+=dfs(edges,visited,dp,1);

    visited[1]=0;

    ans+=dfs(edges,visited,dp,1);

    ans%=M2;

    cout<<ans<<"\n";

    /*loop1(i,n){

        cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }*/

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