#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int digit[20];
LL dp[20][(1<<8)][2520];
LL dfs(int l,int cnt,int sum,bool jud){
    //cout<<l<<" "<<cnt<<" "<<sum<<" "<<jud<<endl;
    if(l==0){
        for(int i=2;i<=9;i++)
            if( (cnt&(1<<(i-2))) && (sum%i) ){
                //cout<<cnt<<" "<<i<<endl;
                return 0;
            }
        return 1;
    }
    if(!jud && dp[l][cnt][sum] != -1) return dp[l][cnt][sum];
    int nes = jud ? digit[l] : 9;
    LL pos = 0 ;
    //pos += dfs(l-1 , cnt , ((sum*10))%2520 , jud&&(0==digit[l]));//i=0
    //pos += dfs(l-1 , cnt , ((sum*10)+1)%2520 , jud&&(1==digit[l]));//i=1
    for(int i=0;i<=nes;i++){
        pos += dfs(l-1 , i<2 ? cnt : (cnt|(1<<(i-2))) , ((sum*10)+i)%2520 , jud&&(i==digit[l]));
    }
    if(!jud)
        dp[l][cnt][sum]=pos;
    return pos;
}
LL f(LL k){
    LL ans;
    int pos = 0;
    while(k){
        digit[++pos]=k%10;
        k=k/10;
    }
    ans = dfs(pos,0,0,true);
    return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    int t;
    LL m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        //cout<<endl;
        //cout<<">"<<f(n)<<" "<<f(m-1)<<endl;
        cout<<f(n)-f(m-1)<<endl;
    }
return 0;
}
