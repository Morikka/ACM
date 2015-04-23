#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool bmap[105][305];
bool bmaxk[305];
int nx,ny;
int cx[105],cy[305];
int findpath(int u){
    for(int i=1;i<=ny;i++){
        if(bmap[u][i]&&!bmaxk[i]){
            bmaxk[i]=1;
            if(cy[i]==-1||findpath(cy[i])){
                cy[i]=u;
                cx[u]=i;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(){
    int res = 0;
    for(int i=1;i<=nx;i++)
        cx[i] = -1;
    for(int i=1;i<=ny;i++)
        cy[i] = -1;
    for(int i=1;i<=nx;i++){
        if(cx[i]==-1){
            for(int j=1;j<=ny;j++)
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
    int T,p,n,k,a;
    scanf("%d",&T);
    while(T--){
        memset(bmap,0,sizeof(bmap));
        scanf("%d%d",&p,&n);
        nx=p,ny=n;
        for(int i=1;i<=p;i++){
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                scanf("%d",&a);
                bmap[i][a]=true;
            }
        }
        if(MaxMatch()==p)puts("YES");
        else puts("NO");
    }
return 0;
}
