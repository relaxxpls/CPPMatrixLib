#include "../matrix.hpp"
#include "../matrix_utility.hpp"

using namespace std;

struct rep{

    vector<long long int> sto;

    rep(){

        sto.resize(2000,0);
    }

    rep operator+(rep &b){

        rep c;
        
        for(int i=0;i<2000;i++){

            c.sto[i]=(sto[i]+b.sto[i])%20092010;
        }

        return c;
    }

    rep operator+=(rep &b){
        
        for(int i=0;i<2000;i++){

            sto[i]=(sto[i]+b.sto[i])%20092010;
        }
        return *this;
    }

    rep operator+=(rep b){
        
        for(int i=0;i<2000;i++){

            sto[i]=(sto[i]+b.sto[i])%20092010;
        }
        return *this;
    }

    rep operator*=(long long int m){

        for(int i=0;i<2000;i++){

            sto[i]=(sto[i]*m)%20092010;
        }
        return *this;
    }

    rep operator* (long long int m){

        rep c;

        return rep(*this)*=m;
    }

};

vector<rep> power(4000);

rep operator*(rep &a,rep &b){

    rep c;

    vector<long long int> temp(3999,0);

    for(int i=0;i<2000;i++){

        for(int j=0;j<2000;j++){

            temp[i+j]+=(a.sto[i]*b.sto[j])%20092010;

        }
    }

    for(int i=3998;i>=2000;i--){

        c+=power[i]*temp[i];
    }
    for(int i=1999;i>=0;i--){

        c.sto[i]=(c.sto[i]+temp[i])%20092010;
    }

    return c;
}

rep pow(long long int n){

    rep ans;

    ans.sto[0]=1;

    rep m;

    m.sto[1]=1;
    
    while(n>0){

        if(n&1){

            ans=ans*m;
        }

        m=m*m;

        n>>=1;
    }

    return ans;
}

int main(){

    vector<matrix<long long int>> mat(2000, matrix<long long int>(1,2000));

    mat[0](0,0)=1;

    mat[1](0,1998)=1;
    mat[1](0,1999)=1;

    for(int i=2;i<2000;i++){

        for(int k=0;k<1998;k++){

            mat[i](0,k)=mat[i-1](0,k+1);
        }

        mat[i](0,1998)=mat[i-1](0,0)+mat[i-1](0,1999);

        mat[i](0,1999)=mat[i-1](0,0);
    }

    power[2000].sto[0]=1;
    power[2000].sto[1]=1;

    for(int i=0;i<2000;i++){

        power[i].sto[i]=1;
    }

    for(int i=2001;i<3999;i++){

        for(int j=1999;j>=0;j--){

            power[i].sto[j]=mat[i-1999](0,1999-j);
        }
    }

    long long int n=1000000000000000000;

    rep temp=pow(n-1999);

    long long int ans=0;

    /*for(int i=0;i<2000;i++){

        cout<<temp.sto[i]<<" ";
    }
    cout<<"\n\n\n\n";*/

    for(int i=0;i<2000;i++){

        long long int s=0;

        for(int j=0;j<2000;j++){

            s+=mat[i](0,j);
        }

        //cout<<s<<"\n";

        ans+=s*(temp.sto[i]);

        ans%=20092010;
    }

    cout<<ans<<"\n";
}

