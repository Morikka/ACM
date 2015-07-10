#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define LL long long
int dp[20][60000];
int digit[20];
LL pos[11];
void init(){
    pos[0]=1;
    for(int i=1;i<=10;i++)
        pos[i]=pos[i-1]*3;
}
bool judge(int s){
    for(int i=9;i>=0;i--){
        if(i%2==0 && s/pos[i]==2) return false;
        if(i%2==1 && s/pos[i]==1) return false;
        s%=pos[i];
    }
    return true;
}
LL dfs(int l,int s,bool zero,bool jud){
    if(l==0){
        if(judge(s))
            return 1;
        return 0;
    }
    if(!jud && dp[l][s]>=0)return dp[l][s];
    int nes = jud ? digit[l] : 9;
    LL ans = 0;
    for(int i=0;i<=nes;i++)
        ans += dfs(l-1 , zero&&i==0 ? 0 : ((s%pos[i+1])/pos[i]==2 ? s-pos[i] : s+pos[i]), zero&&i==0 , jud&&i==nes);
    return jud ? ans : dp[l][s] = ans;
}
LL f(LL num){
   int pos=0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    return dfs(pos,0,true,true);
}
int main(){
    init();
    int T;
    LL a,b;
    cin>>T;
    memset(dp,-1,sizeof(dp));
    while(T--){
        cin>>a>>b;
        cout<<f(b)-f(a-1)<<endl;
    }
    return 0;
}
