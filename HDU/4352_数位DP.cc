#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int digit[20],siz[1<<10],nex[1<<10][10];
LL dp[66][(1<<10)][11];
int Cas,k;
LL dfs(int l,int sta,bool zero,bool jud){
    if(l==0) return siz[sta]==k;
    if(!jud&&dp[l][sta][k]!=-1)return dp[l][sta][k];
    int nes = jud ? digit[l] : 9;
    LL ans = 0;
    for(int i=0;i<=nes;i++)
        ans+= dfs(l-1, (zero&&i==0) ? 0 : nex[sta][i] , zero&&i==0 , jud&&i==nes);
    if(!jud)dp[l][sta][k]=ans;
    return ans;
}
LL f(LL num){
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num/=10;
    }
    return dfs(pos,0,true,true);
}
int find_nex(int status,int num){
    for(int i=num;i<10;i++)
        if (status&(1<<i)) return (status^(1<<i)|(1<<num));
    return status|(1<<num);
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<(1<<10);i++){
        siz[i]=0;
        for(int j=0;j<10;j++){
            if(i&(1<<j))siz[i]++;
            nex[i][j]=find_nex(i,j);
        }
    }
    int t;
    LL m,n;
    cin>>t;
    while(t--){
        cin>>m>>n>>k;
        cout<<"Case #"<<++Cas<<": ";
        cout<<f(n)-f(m-1)<<endl;
    }
return 0;
}
