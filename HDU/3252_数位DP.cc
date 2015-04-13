#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int digit[35],dp[35][35][35][2],pos;
int dfs(int l,int cnt1,int cnt2,bool zero,bool jud){
    if(l==0) return cnt1>=cnt2;
    if(!jud&&dp[l][cnt1][cnt2][zero]!=-1)return dp[l][cnt1][cnt2][zero];
    int nex = jud ? digit[l] : 1;
    int ans = 0;
    for(int i=0;i <= nex;i++){
        ans += dfs( l-1 , zero ? 0 : cnt1+(i==0) ,cnt2+(i==1) , zero&&(i==0) , jud&&i==nex );
    }
    if(!jud)dp[l][cnt1][cnt2][zero]=ans;
    return ans;
}
int f(int num){
    pos = 0;
    while(num){
        digit[++pos]=num%2;
        num>>=1;
    }
    return dfs(pos,0,0,true,true);
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    int m,n;
    cin>>m>>n;
    //cout<<f(n)<<" "<<f(m-1)<<endl;
    cout<<f(n)-f(m-1)<<endl;
    return 0;
}
