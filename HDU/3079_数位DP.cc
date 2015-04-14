#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define LL long long
int digit[20];
LL dp[20][20][2000];
LL dfs(int l,int o,int pos,bool jud){
    if( l==0 ) return pos == 0;
    if( pos<0 ) return 0;
    if(!jud && dp[l][o][pos] >= 0)return dp[l][o][pos];
    int nex = jud ? digit[l] : 9;
    LL ans = 0;
    for(int i=0;i<=nex;i++)
        ans += dfs( l-1 , o , pos+i*(l-o) , jud && i==nex );
    return jud ? ans : dp[l][o][pos] = ans;
}
LL f(LL num){
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    LL ans = 0;
    for(int i=1;i<=pos;i++)
        ans += dfs(pos,i,0,true);
    ans = ans - pos + 1;
    return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    int T;
    LL m,n;
    cin>>T;
    while(T--){
        cin>>m>>n;
        cout<<f(n)-f(m-1)<<endl;
    }
    return 0;
}