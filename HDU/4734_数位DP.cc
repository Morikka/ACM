#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int digit[10],dp[10][100005],CASE;
int dfs(int l,int sum,bool jud){
    if( l==0 ) return sum >= 0;
    if( sum<0 )return 0;
    if( !jud && dp[l][sum]>=0 ) return dp[l][sum];
    int nex = jud ? digit[l] : 9;
    int ans = 0;
    for(int i=0 ; i<=nex ; i++)
        ans += dfs( l-1 , sum-i*(1<<(l-1)) , jud&&i==nex );
    return jud ? ans : dp[l][sum] = ans;
}
inline int f(int num,int cas){
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    return dfs(pos,cas,true);
}
inline int count(int a){
    int pos = 0,ans = 0;
    while(a){
        ans+=(a%10)*(1<<pos++);
        a/=10;
    }
    return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    int T,a,b,cas;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        cas = count(a);
        //cout<<">"<<cas<<endl;
        printf("Case #%d: ",++CASE);
        printf("%d\n",f(b,cas));
    }
    return 0;
}