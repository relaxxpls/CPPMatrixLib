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

int find(int a, ll x[],int st,int end){

    if(x[end]<a){

        return -1;
    }

    if(end-st==1){

        return end;
    }

    int mid=(st+end)/2;

    if(x[mid]>=a){

        return find(a,x,st,mid);

    }else{

        return find(a,x,mid,end);
    }

}


bool check(int n,int c,ll x[],int min){

    ll ans[c];

    ans[0]=x[0];
    
    for(int i=1;i<c;i++){

        int in=find(ans[i-1]+min,x,i-1,n-1);

        ans[i]=x[in];

        if(in==-1){

            return false;
        }
        
        if(x[n-1]-x[in]<(c-i-1)*min){

            return false;
        }
    }

    return true;

}


int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    ll T;

    cin>>T;

    while(T-->0){

        ll n,c;

        cin>>n>>c;

        ll x[n];

        for(ll i=0;i<n;i++){

            cin>>x[i];
        }
        
        sort(x,x+n);

        ll minu=(x[n-1]-x[0])/(c-1)+1,minl=1;
        
        while(minu-minl!=1){

            int mid=(minu+minl)/2;

            bool wh=check(n,c,x,mid);

            if(wh){

                minl=mid;

            }else{

                minu=mid;
            }
        }

        cout<<minl<<"\n";

    }
}

