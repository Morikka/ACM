#include <iostream>
#include <cstring>
#include <cstdio>
// #include <cmath>
// #include <algorithm>

using namespace std;
int num[1005],dp[1005];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("t.out","w",stdout);
    int t,e,n;
    cin>>t;
    for(int Case = 1; Case<=t;Case++){
        cin>>e>>n;
        for(int i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        int l=0,r=n-1,ans=0;
        while(l<r){
            if(e>num[l]){
                e-=num[l];
                ans++;
                l++;
            }else if(ans>0){
                e = e + num[r] - num[l];
                r--;
                l++;
            }else break;
        }
        if(l==r&&e>num[l]){
            ans++;
        }
    cout<<"Case #"<<Case<<": "<<ans<<endl;

    }
    return 0;
}