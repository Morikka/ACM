#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mx = 505;
char chr[mx][mx],chr1[mx][mx];
int dp[mx][mx];
int solve(int n,int m){
    int l=1,ll,ans,pos,k1,k2;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            dp[i][j]=1;
            k1=i;
            k2=j;
            while((k1>0)&&(k2<m-1)){
                if(chr1[k1-1][j]==chr1[i][k2+1]){
                    dp[i][j]++;
                    k1--;
                    k2++;
                }
                else
                    break;
            }
        }
/*    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        puts("");
    }*/
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            pos = 1;
            ll = 0;
            k1 = i,k2 = j;
            while(k1<n&&k2>=0){
                if(dp[k1][k2]>=pos){
                    k1++;
                    k2--;
                    pos+=2;
                }
                else
                    break;
            }
            l = max(l,pos-2);
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            pos = 2;
            ll = 0;
            k1 = i,k2 = j;
            while(k1<n&&k2>=0){
                if(dp[k1][k2]>=pos){
                    k1++;
                    k2--;
                    pos+=2;
                }
                else
                    break;
            }
            l = max(l,pos-2);
        }
return l*(l+1)/2;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int T;
    int ans,n,m;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",chr[i]);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                chr1[i][j]=chr[i][j];
        ans = max(ans,solve(n,m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                chr1[i][j]=chr[i][m-j-1];
        ans = max(ans,solve(n,m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                chr1[i][j]=chr[n-i-1][j];
        ans = max(ans,solve(n,m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                chr1[i][j]=chr[n-i-1][m-j-1];
        ans = max(ans,solve(n,m));
        cout<<ans<<endl;
    }
    return 0;
}