#include <cstring>
#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
int digit[25];
LL dp[25][2];
LL dfs(int l,bool num,bool jud){
    if(l==0) return 1;
    if(!jud && dp[l][num]!=-1) return dp[l][num];
    LL ans=0;
    int nex = jud ? digit[l] : 9;
    for(int i=0;i<=nex;i++){
        if(num&&i==9)continue;
        ans += dfs(l-1,i==4,jud&&i==nex);
    }
    if(!jud) dp[l][num]=ans;
    return ans;
}
LL f(LL num){
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    return dfs(pos,false,true);
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int T;
    LL n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&T);
    while(T--){
        cin>>n;
        cout<<n-f(n)+1<<endl;
    }
    return 0;
}
