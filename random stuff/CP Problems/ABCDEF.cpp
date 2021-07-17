#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <unordered_set>

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

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    ll n;

    cin>>n;

    unordered_set<ll> sto;

    for(int i=0;i<n;i++){

        ll x;

        cin>>x;
        
        sto.insert(x);
    }

    map<ll,ll> m1;
    map<ll,ll> m2;

    for(auto i=sto.begin();i!=sto.end();i++){

        for(auto j=sto.begin();j!=sto.end();j++){

            for(auto k=sto.begin();k!=sto.end();k++){

                m1[(*i)*(*j)+(*k)]++;
            }
        }
    }
    for(auto i=sto.begin();i!=sto.end();i++){

        if((*i)==0){

            continue;
        }

        for(auto j=sto.begin();j!=sto.end();j++){

            for(auto k=sto.begin();k!=sto.end();k++){

                m2[(*i)*((*j)+(*k))]++;
            }
        }
    }

    ll ans=0;

    for(auto i=m1.begin();i!=m1.end();i++){

        ans+=(i->second)*(m2[i->first]);
    }

    cout<<ans<<"\n";

   
}

