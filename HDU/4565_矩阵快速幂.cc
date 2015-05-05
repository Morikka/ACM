#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mx = 105;
#define LL long long
LL A,B,n,mod;
LL A1,A2,A3;
struct matrix{
    LL m[3][3];
};
matrix multiple(matrix a,matrix b){
    matrix ans;
    LL res;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            ans.m[i][j]=0;
            res=0;
            for(int k=0;k<3;k++){
                res+=(a.m[i][k]*b.m[k][j])%mod;
            }
            ans.m[i][j]=res;
        }
    return ans;
}
LL solve(){
    matrix a,b;
    a.m[0][0]=a.m[1][1]=a.m[2][2]=1;
    a.m[0][1]=a.m[0][2]=a.m[1][0]=a.m[1][2]=a.m[2][0]=a.m[2][2]=0;
    b.m[0][0]=0;
    b.m[0][1]=1;
    b.m[0][2]=0;
    b.m[1][0]=0;
    b.m[1][1]=0;
    b.m[1][2]=1;
    b.m[2][0]=0;
    b.m[2][1]=B-A*A;
    b.m[2][2]=2*A;
    n--;
    while(n){
        if(n%2)
            a=multiple(a,b);
        b=multiple(b,b);
        n/=2;
    }
    return (a.m[0][0]*A1+a.m[0][1]*A2+a.m[0][2]*A3)%mod;
}
int main(){
    while(~scanf("%lld%lld%lld%lld",&A,&B,&n,&mod)){
        A%=mod;
        B%=mod;
        A1=2*A;
        A2=(A*A+B)*2;
        A3=6*A*B+2*A*A*A;
        cout<<(solve()+mod)%mod<<endl;
    }
    return 0;
}
