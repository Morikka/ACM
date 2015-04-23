#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mx = 205;
vector<int> node[mx];
int col[mx],n;
bool vis[mx];
bool b1map[mx][mx],bmap[mx][mx];
bool bmask[mx];
int cx[mx],cy[mx];
bool dfs(int i){
    queue<int> q;
    q.push(i);
    col[i]=1;
    vis[i]=true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0;i<node[temp].size();i++){
            int num = node[temp][i];
            int cc = col[temp] == 1 ? 2 : 1;
            if(col[num]==col[temp])return false;
            col[num]=cc;
            if(!vis[num]){
                q.push(num);
                vis[num]=true;
            }
        }
    }
    return true;
}
int findpath(int u){
    for(int i=1;i<=n;i++){
        if(bmap[u][i]&&!bmask[i]){
            bmask[i]=1;
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
    for(int i=1;i<=n;i++)
        cx[i]=-1;
    for(int i=1;i<=n;i++)
        cy[i]=-1;
    for(int i=1;i<=n;i++){
        if(cx[i]==-1){
            for(int j=1;j<=n;j++)
                bmask[j]=0;
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
    int m,x,y;
    bool jud,judd;
    while(~scanf("%d%d",&n,&m)){
        jud=judd=true;
        memset(col,0,sizeof(col));
        memset(vis,0,sizeof(vis));
        memset(bmap,0,sizeof(bmap));
        memset(b1map,0,sizeof(b1map));
        while(m--){
            scanf("%d%d",&x,&y);
            node[x].push_back(y);
            node[y].push_back(x);
            b1map[x][y]=b1map[y][x]=1;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i])
                jud = dfs(i);
            if(!jud)judd=false;
        }
        if(judd){
            //puts("Yes");
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(b1map[i][j]&&col[i]==1&&col[j]==2)
                    //if(b1map[i][j])
                        bmap[i][j]=true;
            printf("%d\n",MaxMatch());
        }
        else
            puts("No");
        for(int i=1;i<=n;i++)
            node[i].clear();
    }
return 0;
}
