#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair< int,pair<LL,LL> > PILL;//< count , < sum，square sum> >
#define F first
#define S second
#define MP make_pair
const int mod = 1e9+7, mx = 20;
int digit[mx];
LL pow10[20];
PILL dp[20][7][7];
bool vis[20][7][7];
//边界的答案不同
PILL dfs(int len,int sum,int remain,bool jud){
    if(!len)
        if(sum&&remain)
            return MP(1,MP(0LL,0LL));
        else
            return MP(0,MP(0LL,0LL));
    if(!jud&&vis[len][sum][remain])
            return dp[len][sum][remain];
    PILL res = MP(0,MP(0LL,0LL));
    int nex = jud ? digit[len] : 9;
    for(int i=0;i<=nex;i++){
        if(i==7) continue;
        PILL ans = dfs(len-1,(sum+i)%7,(remain*10+i)%7,jud&&i==nex);
        LL pref = i * pow10[len-1] % mod;
        res.F += ans.F;
        res.F %= mod;
        res.S.F += ans.S.F + pref * ans.F;
        res.S.F %= mod;
        res.S.S += ans.S.S + pref * pref % mod * ans.F + 2 * pref * ans.S.F;
        res.S.S %= mod;
    }
    if(!jud){
        vis[len][sum][remain]=true;
        dp[len][sum][remain]=res;
    }
    return res;
}
LL f(LL a){
    memset(vis,0,sizeof(vis));
    int len=0;
    while(a){
        digit[++len]=a%10;
        a=a/10;
    }
    return dfs(len,0,0,true).S.S;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    pow10[0]=1;
    for(int i=1;i<20;i++)
        pow10[i]=pow10[i-1]*10%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,b,ans;
        scanf("%lld%lld",&a,&b);
        ans = (f(b)-f(a-1)+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}