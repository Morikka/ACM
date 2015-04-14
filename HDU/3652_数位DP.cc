#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int digit[11];
int dp[11][13][2][2];
int dfs(int l,int mod,bool iso,bool has,bool jud){
    if(l==0)return (has && !mod);
    if(!jud && dp[l][mod][iso][has])return dp[l][mod][iso][has];
    int nex = jud ? digit[l] : 9;
    int ans = 0;
    for(int i=0;i<=nex;i++){
        ans += dfs( l-1 , (mod*10+i)%13 , i==1 , has||(iso&&i==3) , jud && i==nex );
    }
    return jud ? ans : dp[l][mod][iso][has]=ans;
}
int f(int num){
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    return dfs(pos,0,false,false,true);
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",f(n));
    }
    return 0;
}