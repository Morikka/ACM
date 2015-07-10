#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int digit[10],dp[10][2],vis[10][2];
int dfs(int l,bool six,bool jud){
    if(l==0) return 1;
    if(!jud&&vis[l][six])return dp[l][six];
    int len = jud ? digit[l] : 9;
    int nes = 0;
    for(int i=0;i<=len;i++){
        if((i==4)||(six&&i==2)) continue;
    nes += dfs(l-1 , i==6 , jud&&(i==len));
    }
    if(!jud){
        vis[l][six]=true;
        dp[l][six]=nes;
    }
    return nes;
}
int f(int k){
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    int pos = 0;
    while(k){
        digit[++pos]=k%10;
        k=k/10;
    }
    int ans = dfs(pos,false,true);
    return ans;
}
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)&&(m+n)){
        cout<<f(n)-f(m-1)<<endl;
    }
return 0;
}
