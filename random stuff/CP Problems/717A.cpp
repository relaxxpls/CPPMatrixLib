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

vll fact(201);

vvll C(201,vll(201));

vvll coeff(201,vll(201));

void precomp(){

    fact[0]=1;

    for(ll i=1;i<201;i++){

        fact[i]=(fact[i-1]*i)%M2;
    }

    C[0][0]=1;

    for(ll i=1;i<201;i++){

        C[i][0]=1;
        
        for(ll j=1;j<=i;j++){

            C[i][j]=(C[i-1][j]+C[i-1][j-1])%M2;
        }
    }

    coeff[1][1]=1;

    for(ll i=2;i<201;i++){

        for(ll j=1;j<=i;j++){

            coeff[i][j]=((coeff[i-1][j]*(i-1))%M2+coeff[i-1][j-1])%M2;
        }
    }
}

struct Complex{

    ll a,b;

    Complex(ll x,ll y){

        a=x%M2;
        b=y%M2;

        if(a<0){

            a+=M2;
        }

        if(b<0){

            b+=M2;
        }
    }
    
    Complex operator+(const Complex& y){

        ll tx=a+y.a;
        ll ty=b+y.b;

        return Complex(tx,ty);
    }
    Complex operator-(const Complex& y){

        ll tx=a-y.a;
        ll ty=b-y.b;

        return Complex(tx,ty);
    }

    Complex operator*(const Complex & y){

        ll tx=((a*y.a)+5*(b*y.b)%M2);
        ll ty=(a*y.b+b*y.a);

        return Complex(tx,ty);
    }

    Complex operator*(const ll &x){

        return Complex(a*x,b*x);
    }

    Complex operator/(const Complex& y){

        ll den=((y.a*y.a)-5*((y.b)*(y.b))%M2)%M2;

        if(den<0){

            den+=M2;
        }

        ll inv=binex(den,M2-2,M2);

        Complex z=(*this)*(Complex(y.a,-y.b));

        return z*inv;
    }

    Complex operator/(const ll &x){

        return Complex(a*binex(x,M2-2,M2),b*binex(x,M2-2,M2));
    }
};

Complex comppow(Complex a, ll n){

    Complex ans(1,0);

    while(n>0){

        if(n&1){

            ans=ans*a;
        }

        a=a*a;
        
        n>>=1;
    }

    return ans;
}

ll sumpow(ll n, ll k){

    Complex phi(1,1);

    phi=phi/2;

    Complex psi(1,-1);
    psi=psi/2;

    Complex ans(0,0);

    for(ll p=0;p<=k;p++){

        Complex ratio=comppow(phi,k-p)*comppow(psi,p);

        //cout<<"Ratio: "<<ratio.a<<" "<<ratio.b<<"\n";

        Complex sum(n+1,0);

        if(ratio.a==1&&ratio.b==0){

        }else{

            sum=(comppow(ratio,n+1)-Complex(1,0))/(ratio-Complex(1,0));
        }

        ll temp=1;

        if(p&1){

            temp=-1;
        }

        sum=sum*(C[k][p]*temp);

        //cout<<k<<" "<<p<<" "<<C[k][p]<<"\n";

        //cout<<"Sum: "<<sum.a<<"  "<<sum.b<<"\n";

        ans=ans+sum;
    }

    //cout<<ans.a<<"   "<<ans.b<<"\n";

    if(k&1){

        ans=(ans*(Complex(0,1)))/binex(ll(5),k/2+1,M2);
    }else{

        ans=(ans*(Complex(1,0)))/binex(ll(5),k/2,M2);
    }

    return ans.a;
}

void solve(){

    ll k,l,r;

    cin>>k>>l>>r;

    l+=2;
    r+=2;

    ll ans=0;

    for(ll i=0;i<=k;i++){

        ll mult=coeff[k][i];

        //cout<<coeff[k][i]<<"\n";

        if((k-i)&1){

            mult=M2-mult;
        }

        ll term=(sumpow(r,i)-sumpow(l-1,i));

        //cout<<term<<"\n";

        //cout<<sumpow(r,i)<<" "<<sumpow(l-1,i)<<"\n";

        if(term<0){

            term+=M2;
        }

        ans+=(mult*term)%M2;

        ans%=M2;
    }

    cout<<(ans*binex(fact[k],M2-2,M2))%M2<<"\n";

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

