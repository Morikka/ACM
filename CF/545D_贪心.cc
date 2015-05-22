#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int mx = 1e5+5;
int a[mx],n,t,cnt;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
            if(t<=a[i]){
                t+=a[i];
                cnt++;
            }
        printf("%d\n",cnt);
    }
    return 0;
}
