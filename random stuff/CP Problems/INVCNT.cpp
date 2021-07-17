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

void mergesort(ll a[],ll b[], ll c[], ll n,ll &count){

    ll cob=0,coc=0;
    
    for(int i=0;i<n;i++){

        if(cob==n/2){

            while(i<n){

                a[i]=c[coc];
                coc++;
                i++;
            }
            break;
        }
        if(coc==n-n/2){

            while(i<n){

                a[i]=b[cob];
                cob++;
                i++;
            }
            break;
        }
        if(b[cob]<c[coc]){

            a[i]=b[cob];
            cob++;
        }else{

            a[i]=c[coc];
            coc++;
            count+=(n/2-cob);
        }
    }
}


void counter(ll a[],ll &count, ll n){

    if(n==1){

        return;
    }
    
    ll b[n/2];
    ll c[n-n/2];

    for(ll i=0;i<n/2;i++){

        b[i]=a[i];
    }
    for(ll i=0;i<n-n/2;i++){

        c[i]=a[i+n/2];
    }

    counter(b,count,n/2);
    counter(c,count,n-n/2);

    mergesort(a,b,c,n,count);
}



int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    ll T;

    cin>>T;

    while(T-->0){

        ll n;

        cin>>n;

        ll a[n];

        for(int i=0;i<n;i++){

            cin>>a[i];
        }

        ll ans=0;

        counter(a,ans,n);

        cout<<ans<<"\n";


    }
}

