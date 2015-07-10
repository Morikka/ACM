#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int digit[20];
LL dp[20][(1<<8)][2520];
LL dfs(int l,int cnt,int sum,bool jud){
    if(l==0){
        for(int i=2;i<=9;i++)
            if( (cnt&(1<<(i-2))) && (sum%i) ){
                return 0;
            }
        return 1;
    }
    if(!jud && dp[l][cnt][sum] != -1) return dp[l][cnt][sum];
    int nes = jud ? digit[l] : 9;
    LL pos = 0 ;
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
    memset(dp,-1,sizeof(dp));
    int t;
    LL m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cout<<f(n)-f(m-1)<<endl;
    }
return 0;
}
/*
2 0 0 1
1 0 0 0
0 0 0 0
0 0 1 0
0 1 2 0
0 2 3 0
0 4 4 0
0 8 5 0
0 16 6 0
0 32 7 0
0 64 8 0
0 128 9 0
1 0 1 1
0 0 10 0
0 0 11 1
2 0 0 1
1 0 0 0
1 0 1 1
0 0 10 0
0 0 11 0
0 1 12 0
0 2 13 0
0 4 14 0
0 8 15 1
14 12
*/
