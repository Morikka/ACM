#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long x[4],y[4],z[4];
int cas;
long long dis[6];
long long sl(int a,int b){
    return (x[b]-x[a])*(x[b]-x[a])+(y[b]-y[a])*(y[b]-y[a])+(z[b]-z[a])*(z[b]-z[a]);
}
int main(){
    #ifdef LOCAL
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int T;
    bool jud;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<4;i++)
            cin>>x[i]>>y[i]>>z[i];
        dis[0]=sl(0,1);
        dis[1]=sl(0,2);
        dis[2]=sl(0,3);
        dis[3]=sl(1,2);
        dis[4]=sl(1,3);
        dis[5]=sl(2,3);
        sort(dis,dis+6);
        if(dis[0]==dis[1]&&dis[0]==dis[2]&&dis[0]&&dis[3]&&dis[0]*2==dis[4]&&dis[0]*2==dis[5])
            jud = true;
        else
            jud = false;
        printf("Case #%d: ",++cas);
        if(jud)
            puts("Yes");
        else
            puts("No");
    }
return 0;
}
