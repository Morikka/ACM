//fffffffuck...
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
const int mx = 1005;
int a[mx][mx],dp[mx][mx],ff[mx][mx];
int f[mx];
int main() {
    int i,j,m,n,ans,pos=i,s;
    while(scanf("%d%d",&n,&m)!=EOF){
    ans=INF;
    for(i=0; i<n; i++)
        for(j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
for(j=1;j<=m;j++)
    for(i=0;i<n;i++){
    int op[3]={i-1,i,i+1};
    if(i==0)op[0]=n-1;
    if(i==n-1)op[2]=0;
    sort(op,op+3);
    dp[i][j]=INF;
    for(int k=0;k<3;k++){
        int v=dp[op[k]][j-1]+a[i][j];
        if(v<dp[i][j]){
            dp[i][j]=v;
            ff[i][j]=op[k];
            }
        }
    }
    for(i=0;i<n;i++)
        if(dp[i][m]<ans){
        ans=dp[i][m];
        pos=i;
        }
    f[m]=pos;
    for(i=m-1;i>=1; i--){
        pos=ff[pos][i+1];
        f[i]=pos;
    }
    printf("%d",f[1]+1);
    for(i=2; i<=m; i++)
        printf(" %d",f[i]+1);
    printf("\n%d\n",ans);
}
return 0;
}
