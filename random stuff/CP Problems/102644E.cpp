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
typedef uint32_t ll;
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
#define M2 ll(4294967296)
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


void mult(vvll &a, vvll &b){

    vvll c(a.sz,vll(a.sz,0));

    for(ll i=0;i<a.sz;i++){

        for(ll j=0;j<a.sz;j++){

            for(ll k=0;k<a.sz;k++){

                c[i][j]+=(a[i][k]*b[k][j]);//%M2;
                //c[i][j]%=M2;
            }
        }
    }

    for(ll i=0;i<a.sz;i++){

        for(ll j=0;j<a.sz;j++){

            a[i][j]=c[i][j];
        }
    }
}

vvll mult2(vvll a, vvll b){

    vvll c(a.sz,vll(a.sz,0));

    for(ll i=0;i<a.sz;i++){

        for(ll j=0;j<a.sz;j++){

            for(ll k=0;k<a.sz;k++){

                c[i][j]+=(a[i][k]*b[k][j]);//%M2;
                //c[i][j]%=M2;
            }
        }
    }

    return c;
}

vvll power(vvll mat,ll n){

    vvll ans(64,vll(64,0));

    for(ll i=0;i<mat.sz;i++){

        ans[i][i]=1;
    }

    while(n>0){

        if(n&1){

            mult(ans,mat);
        }
        mult(mat,mat);
        n>>=1;
    }

    /*for(ll i=0;i<64;i++){

        cout<<ans[i]<<"\n";
    }*/
    //cout<<endl<<endl;

    return ans;
}



vvll operator+(vvll a,vvll b){

    vvll c(a.sz,vll(a.sz,0));
    
    for(ll i=0;i<a.sz;i++){

        for(ll j=0;j<a.sz;j++){

            c[i][j]=(a[i][j]+b[i][j]);//%M2;
        }
    }

    return c;
}

vvll power_sum(vvll mat,ll k,vvll &eye){

    if(k==0){

        return eye; 
    }

    if(k==1){

        return mat+eye;
    }

    if(k&1){

        return mult2((eye+mat),(power_sum(mult2(mat,mat),(k-1)/2,eye)));
    }else{

        return mult2((eye+mat),(power_sum(mult2(mat,mat),(k-1)/2,eye)))+power(mat,k);
    }
}

void solve(){

    ll n;
    cin>>n;

    vvll mat(64,vll(64,0));

    for(ll i=0;i<8;i++){

        for(ll j=0;j<8;j++){

            if(i>=ll(2)&&j+1<ll(8)){

                mat[8*i+j][8*(i-2)+j+1]=1;
            }
            if(i>=ll(2)&&j>=ll(1)){

                mat[8*i+j][8*(i-2)+j-1]=1;
            }
            if(i+1<ll(8)&&j>=ll(2)){

                mat[8*i+j][8*(i+1)+j-2]=1;
            }
            if(i>=ll(1)&&j>=ll(2)){

                mat[8*i+j][8*(i-1)+j-2]=1;
            }
            if(i+1<ll(8)&&j+2<ll(8)){

                mat[8*i+j][8*(i+1)+j+2]=1;
            }
            if(i>=ll(1)&&j+2<ll(8)){

                mat[8*i+j][8*(i-1)+j+2]=1;
            }
            if(i+2<ll(8)&&j+1<ll(8)){

                mat[8*i+j][8*(i+2)+j+1]=1;
            }
            if(i+2<ll(8)&&j>=ll(1)){

                mat[8*i+j][8*(i+2)+j-1]=1;
            }
        }
    }

    vvll eye(mat.sz,vll(mat.sz,0));

    loop0(i,mat.sz){

        eye[i][i]=1;
    }

    vvll fin=power_sum(mat,n,eye);

    ll ans=0;

    for(ll i=0;i<mat.sz;i++){

        ans+=fin[i][0];
        //ans%=M2;
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

