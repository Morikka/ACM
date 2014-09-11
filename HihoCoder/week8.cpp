#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,l;
int a[1<<10],w[1010];
int dp[1010][1024];
int cnt(int i) {
    int res=0;
    while(i) {
        if(i%2)res++;
        i=i/2;
    }
    return res;
}
void init() {
    for(int i=1; i<l; i++) {
        a[i]=cnt(i);
    }
//for(int i=1;i<l;i++)
//    printf("%d %d\n",i,a[i]);
}
int main() {
    int i,j,k,q,ll,p,ans=0;
    scanf("%d%d%d",&n,&m,&q);
    memset(dp,0,sizeof(dp));
    l=(1<<m);
    ll=(1<<(m-1));
        //cout<<l<<" "<<ll<<endl;
    init();
    for(i=0; i<n; i++)scanf("%d",&w[i]);
    for(i=1; i<=m; i++)
        for(j=0; j<(1<<i); j++) {
            //cout<<i<<" "<<j<<endl;
            if(a[j]>q)continue;
            for(k=0; k<=i; k++)
                if(j&(1<<k)){dp[i][j]+=w[k];
                        //cout<<">"<<i<<" "<<j<<" "<<dp[i][j]<<endl;}
            }
        }
    for(i=m;i<n;i++)
    for(j=0;j<l;j++){
        if(a[j]<q){
            dp[i+1][j>>1]=max(dp[i+1][j>>1],dp[i][j]);
            dp[i+1][j>>1|ll]=max(dp[i+1][j>>1|ll],dp[i][j]+w[i]);
        }
        else if(a[j]==q){
            if(j&1){
            dp[i+1][j>>1]=max(dp[i+1][j>>1],dp[i][j]);
            dp[i+1][j>>1|ll]=max(dp[i+1][j>>1|ll],dp[i][j]+w[i]);
            }
            else{
                dp[i+1][j>>1]=max(dp[i+1][j>>1],dp[i][j]);
            }
        }
    }
    for(i=0;i<l;i++)ans=max(ans,dp[n][i]);
//for(i=1;i<=n;i++){
//    for(j=0;j<l;j++)
//        printf("%d ",dp[i][j]);
//    printf("\n");
//}
printf("%d\n",ans);
return 0;
}
