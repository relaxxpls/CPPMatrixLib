#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long int> vll;
typedef vector<bool> vb;

#define pb push_back
#define sz size()
#define ff first
#define ss second
#define pi 3.14159265359
#define M1 998244353
#define M2 1000000007
#define INF 10000000000000

#define V_SUM_MAX 1000
#define N_MAX 100
#define W_MAX 1000000000
  
// To store the states of DP
int dp[V_SUM_MAX + 1][N_MAX];
bool v[V_SUM_MAX + 1][N_MAX];
  
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,w;

    cin>>n>>w;

    vll wt(n),val(n);
    ll sum=0;

    for(int i=0;i<n;i++){

        cin>>wt[i]>>val[i];
        sum+=val[i];
    }

    vll minwt(sum+1);

    for(int i=0;i<n;i++){

        for(int j=sum;j>=0;j--){

            if(i==0){

                if(j==0){

                    minwt[j]=0;

                }else if(j<=val[i]){

                    minwt[j]=wt[i];
                }else{

                    minwt[j]=INF;
                }
                continue;
            }
            if(j>=val[i]){

                minwt[j]=min(minwt[j],minwt[j-val[i]]+wt[i]);
            }else{

                minwt[j]=min(minwt[j],wt[i]);
            }
        }
    }

    for(ll i=sum;i>=0;i--){
        
        if(minwt[i]<=w){

            cout<<i<<"\n";
            break;
        }
    }
}

