#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int mx = 3005,inf = 1<<28;
bool bmap[mx][mx];
int x1[mx],y1[mx],x2[mx],y2[mx],s[mx];
bool bmask[mx];
int cx[mx],cy[mx],nx,ny,cas;
int dx[mx];
int dy[mx];
int dis;
bool searchpath(){
    queue<int> Q;
    dis=inf;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<nx;i++){
        if(cx[i]==-1){
            Q.push(i);
            dx[i]=0;
        }
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis) break;
        for(int v=0;v<ny;v++){
            if(bmap[u][v]&&dy[v]==-1){
                dy[v]=dx[u]+1;
                if(cy[v]==-1) dis=dy[v];
                else{
                    dx[cy[v]]=dy[v]+1;
                    Q.push(cy[v]);
                }
            }
        }
    }
    return dis!=inf;
}
int findpath(int u){
    for(int v=0;v<ny;v++){
        if(!bmask[v]&&bmap[u][v]&&dy[v]==dx[u]+1){
            bmask[v]=1;
            if(cy[v]!=-1&&dy[v]==dis)
                continue;
            if(cy[v]==-1||findpath(cy[v])){
                cy[v]=u;cx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(){
    int res=0;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    while(searchpath()){
        memset(bmask,0,sizeof(bmask));
        for(int i=0;i<nx;i++){
            if(cx[i]==-1)
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
    int T,t,m,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&t,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&x1[i],&y1[i],&s[i]);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&x2[i],&y2[i]);
        memset(bmap,0,sizeof(bmap));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if((x1[i]-x2[j])*(x1[i]-x2[j])+(y1[i]-y2[j])*(y1[i]-y2[j])<=(s[i]*t)*(s[i]*t))
                    bmap[i][j]=true;
            }
            nx = m,ny = n;
        printf("Scenario #%d:\n%d\n\n",++cas,MaxMatch());
    }
    return 0;
}
