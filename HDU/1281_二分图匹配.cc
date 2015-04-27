#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mx = 105;
bool bmap[mx][mx];
int m,n,cas;
bool bmaxk[mx];
int cx[mx],cy[mx],c1[mx],c2[mx];
int findpath(int u){
    for(int i=1;i<=m;i++)
        if(bmap[u][i]&&!bmaxk[i]){
            bmaxk[i]=1;
            if(cy[i]==-1||findpath(cy[i])){
                cy[i]=u;
                cx[u]=i;
                return 1;
            }
        }
    return 0;
}
int MaxMatch1(){
    int res = 0;
    for(int i=1;i<=n;i++){
        if(cx[i]==-1){
            for(int j=1;j<=m;j++)
                bmaxk[j]=0;
            res+=findpath(i);
        }
    }
    return res;
}
int MaxMatch(){
    int res = 0;
    for(int i=1;i<=n;i++)
        cx[i]=-1;
    for(int i=1;i<=m;i++)
        cy[i]=-1;
    for(int i=0;i<=n;i++){
        if(cx[i]==-1){
            for(int j=1;j<=m;j++)
                bmaxk[j]=0;
            res+=findpath(i);
        }
    }
    return res;
}

int main(){
    #ifdef LOCAL
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int k,a,b,mx,ans,t1;
    while(~scanf("%d%d%d",&n,&m,&k)){
        memset(bmap,0,sizeof(bmap));
        while(k--){
            ans=0;
            scanf("%d%d",&a,&b);
            bmap[a][b]=true;
        }
        mx = MaxMatch();
        for(int i=1;i<=n;i++)
            c1[i]=cx[i];
        for(int i=1;i<=m;i++)
            c2[i]=cy[i];
        for(int i=1;i<=n;i++)
            if(cx[i]!=-1){
                t1=cx[i];
                cy[t1]=-1;
                cx[i]=-1;
                bmap[i][t1]=false;
                if(!MaxMatch1())
                    ans++;
                bmap[i][t1]=true;
            for(int j=1;j<=n;j++)
                cx[j]=c1[j];
            for(int j=1;j<=m;j++)
                cy[j]=c2[j];
            }
        printf("Board %d have %d important blanks for %d chessmen.\n",++cas,ans,mx);
    }
return 0;
}
