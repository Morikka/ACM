#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int num[101],dp[10010];
int main(){
    // freopen("t.in","r",stdin);
    freopen("D-large.in","r",stdin);
    freopen("t.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<101;i++){
        num[i]=i*i;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<10010;i++)
        for(int j=1;j<101;j++){
            int pos = i+num[j];
            if(pos<10010)
                dp[pos]=min(dp[pos],dp[i]+1);
        }
    // for(int i=0;i<50;i++)
    //     cout<<i<<" "<<dp[i]<<endl;
    for(int Case = 1; Case<=t;Case++){
        cin>>n;
        // int r = sqrt(n+1)+1,ans = 0;
        // while(n>0){
        //     cout<<n<<endl;
        //     while(n>=num[r]){
        //         n-=num[r];
        //         ans++;
        //     }
        //     r--;
        // }
    cout<<"Case #"<<Case<<": "<<dp[n]<<endl;
    }
    return 0;
}