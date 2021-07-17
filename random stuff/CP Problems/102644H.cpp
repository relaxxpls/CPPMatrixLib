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
#include <sstream>

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
#define reach cout<<"Reached!"<<endl;

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

vvll mult(vvll &a,vvll &b){

    vvll c(2,vll(2,0));
    
    for(ll i=0;i<2;i++){

        for(ll j=0;j<2;j++){

            for(ll k=0;k<2;k++){

                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=M2;
            }
        }
    }

    return c;
}

void form(vvvll &segtree, ll root){

    if(2*root+1>=segtree.sz){

        return;
    }

    form(segtree,2*root);
    form(segtree,2*root+1);

    segtree[root]=mult(segtree[2*root],segtree[2*root+1]);
}

void update(vvvll &segtree,ll ind, char c){

    ll s=((segtree.sz)>>1);

    if(c=='H'){

        segtree[s+ind][0][0]=1;
        segtree[s+ind][1][0]=1;
        segtree[s+ind][0][1]=0;
        segtree[s+ind][1][1]=0;

    }else if(c=='S'||c=='D'){

        segtree[s+ind][0][1]=1;
        segtree[s+ind][1][1]=1;
        segtree[s+ind][0][0]=0;
        segtree[s+ind][1][0]=0;

    }else if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){

        segtree[s+ind][0][0]=0;
        segtree[s+ind][0][1]=1;
        segtree[s+ind][1][0]=1;
        segtree[s+ind][1][1]=0;

    }else if(c=='?'){

        segtree[s+ind][0][0]=19;
        segtree[s+ind][0][1]=7;
        segtree[s+ind][1][0]=6;
        segtree[s+ind][1][1]=20;

    }else{

        segtree[s+ind][0][0]=1;
        segtree[s+ind][0][1]=0;
        segtree[s+ind][1][0]=0;
        segtree[s+ind][1][1]=1;
    }

    ind+=s;

    while(ind>0){

        if(ind&1){

            segtree[ind>>1]=mult(segtree[ind-1],segtree[ind]);
        }else{

            segtree[ind>>1]=mult(segtree[ind],segtree[ind+1]);
        }

        ind>>=1;
    }
}

void solve(){

    ll n,q;
    cin>>n>>q;

    string str;
    cin>>str;

    ll s=1;

    while(s<n){

        s<<=1;
    }

    vvll eye(2,vll(2,0));

    eye[0][0]=1;
    eye[1][1]=1;

    vvvll segtree(s<<1,eye);

    loop0(i,n){

        if(str[i]=='H'){

            segtree[s+i][0][0]=1;
            segtree[s+i][1][0]=1;
            segtree[s+i][0][1]=0;
            segtree[s+i][1][1]=0;

        }else if(str[i]=='S'||str[i]=='D'){

            segtree[s+i][0][1]=1;
            segtree[s+i][1][1]=1;
            segtree[s+i][0][0]=0;
            segtree[s+i][1][0]=0;

        }else if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){

            segtree[s+i][0][0]=0;
            segtree[s+i][0][1]=1;
            segtree[s+i][1][0]=1;
            segtree[s+i][1][1]=0;

        }else if(str[i]=='?'){

            segtree[s+i][0][0]=19;
            segtree[s+i][0][1]=7;
            segtree[s+i][1][0]=6;
            segtree[s+i][1][1]=20;
        }
    }

    form(segtree,1);

    cout<<segtree[1][0][0]<<"\n";

    loop0(i,q){

        ll ind;
        char c;

        cin>>ind>>c;

        ind--;

        update(segtree,ind,c);

        cout<<segtree[1][0][0]<<"\n";
    }    

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

