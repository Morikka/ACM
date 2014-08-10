#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<iostream>
using namespace std;
char chr[105];
int dp[105][55][2];
const int INF = 0x3f3f3f3f;
const int INF2 = -100000000;
int main(){
    int n,l,mx=0,mn=0,i,j,pos;
    scanf("%s",chr+1);
    scanf("%d",&n);
    l=strlen(chr+1);
    for(i=0;i<=l;i++)
        for(j=0;j<=n;j++)
            dp[i][j][0]=dp[i][j][1]=INF2;
    dp[0][0][0]=0;
    for(i=1; i<=l; i++){
        for(j=0; j<=n; j++){
            if(chr[i]=='F'){
                 if(dp[i-1][j][0]!=INF2)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]+1);
                 if(dp[i-1][j][1]!=INF2)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]-1);
                 if(dp[i-1][j][1]!=INF2)dp[i][j+1][0]=max(dp[i][j+1][0],dp[i-1][j][1]);
                 if(dp[i-1][j][0]!=INF2)dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][0]);
            }
            else{
                 if(dp[i-1][j][1]!=INF2)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]);
                 if(dp[i-1][j][0]!=INF2)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]);
                 if(dp[i-1][j][0]!=INF2)dp[i][j+1][0]=max(dp[i][j+1][0],dp[i-1][j][0]+1);
                 if(dp[i-1][j][1]!=INF2)dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][1]-1);
            }
        }
    }
    if(n%2)pos=1;
    else pos=0;
    while(pos<=n){
    mx=max(mx,max(dp[l][pos][0],dp[l][pos][1]));
    pos+=2;
    }
    //cout<<"mx "<<mx<<endl;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(i=1; i<=l; i++){
        for(j=0; j<=n; j++){
            if(chr[i]=='F'){
                 if(dp[i-1][j][1]!=INF)dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][1]);
                 if(dp[i-1][j][0]!=INF)dp[i][j+1][1]=min(dp[i][j+1][1],dp[i-1][j][0]);
                 if(dp[i-1][j][0]!=INF)dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+1);
                 if(dp[i-1][j][1]!=INF)dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]-1);
            }
            else{
                 if(dp[i-1][j][1]!=INF)dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]);
                 if(dp[i-1][j][0]!=INF)dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]);
                 if(dp[i-1][j][0]!=INF)dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][0]+1);
                 if(dp[i-1][j][1]!=INF)dp[i][j+1][1]=min(dp[i][j+1][1],dp[i-1][j][1]-1);
            }
        }
    }
    if(n%2)pos=1;
    else pos=0;
    while(pos<=n){
    mn=min(mn,min(dp[l][pos][0],dp[l][pos][1]));
    pos+=2;
    }
    mn=min(dp[l][n][0],dp[l][n][1]);
    //cout<<"mn "<<mn<<endl;
    mx=max(mx,-mn);
    printf("%d\n",mx);
}