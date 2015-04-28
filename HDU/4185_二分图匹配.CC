#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int mx = 605,inf = 1<<28;
bool bmap[mx][mx];
char chr[mx][mx];
int num[mx][mx];
int nx,ny;
int cas;
int cx[mx],cy[mx],dx[mx],dy[mx];
bool bmask[mx];
int dis;
bool searchpath(){
    queue<int> Q;
    dis = inf;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<nx;i++){
        if(cx[i]==-1){
            Q.push(i);
            dx[i]=0;
        }
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(dx[u]>dis)break;
        for(int v=0;v<ny;v++){
            if(bmap[u][v]&&dy[v]==-1){
                dy[v]=dx[u]+1;
                if(cy[v]==-1)dis = dy[v];
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
                cy[v]=u;
                cx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(){
    int res = 0;
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
    int T,n;
    scanf("%d",&T);
    while(T--){
        memset(bmap,0,sizeof(bmap));
        nx = ny = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",chr[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(chr[i][j]=='#'){
                    if((i+j)%2)
                        num[i][j]=nx++;
                    else
                        num[i][j]=ny++;
                }
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chr[i][j]=='#'&&(i+j)%2){
                    if(i>0&&chr[i-1][j]=='#')
                        bmap[num[i][j]][num[i-1][j]]=1;
                    if(j>0&&chr[i][j-1]=='#')
                        bmap[num[i][j]][num[i][j-1]]=1;
                    if(i<n-1&&chr[i+1][j]=='#')
                        bmap[num[i][j]][num[i+1][j]]=1;
                    if(j<n-1&&chr[i][j+1]=='#')
                        bmap[num[i][j]][num[i][j+1]]=1;
                }
            }
        }
        printf("Case %d: %d\n",++cas,MaxMatch());
    }
    return 0;
}
