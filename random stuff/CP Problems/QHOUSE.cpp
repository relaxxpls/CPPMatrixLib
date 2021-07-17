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

int heightfinder(int l,int u){

    if(u-l==1){

        return l;
    }
    
    int mid=(l+u)/2;

    string str;
    
    cout<<"? "<<0<<" "<<mid<<endl;
    fflush(stdout);
    cin>>str;

    if(str=="YES"){

        return heightfinder(mid,u);

    }else{

        return heightfinder(l,mid);
    }

}

int widthfinder(int l,int r, int w){

    if(r-l==1){

        return l;
    }
    
    int mid=(l+r)/2;

    string str;
    
    cout<<"? "<<mid<<" "<<w<<endl;
    fflush(stdout);
    cin>>str;

    if(str=="YES"){

        return widthfinder(mid,r,w);

    }else{

        return widthfinder(l,mid,w);
    }

}

int widthfinder(int l,int r){

    if(r-l==1){

        return l;
    }
    
    int mid=(l+r)/2;

    string str;
    
    cout<<"? "<<mid<<" "<<0<<endl;
    fflush(stdout);
    cin>>str;

    if(str=="YES"){

        return widthfinder(mid,r);

    }else{

        return widthfinder(l,mid);
    }

}

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

        string str;

        int h,w,b;
        
        h=heightfinder(0,1001);

        w=widthfinder(0,1001);

        b=widthfinder(0,1001,w*2);

        cout<<"! "<<4*w*w+b*(h-2*w)<<endl;
        fflush(stdout);


}

