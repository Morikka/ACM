#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int mx = 305,INF = 0x3f3f3f3f;
int dis[mx][mx],dist[mx];
int que[mx];
bool vis[mx];
int n;
void spfa(int start){
    queue<int> q;
    for(int v=1;v<=n;v++){
        if(v==start){
            dist[v]=INF;
            vis[v]=false;
        }
        else{
            dist[v]=dis[start][v];
            q.push(v);
            vis[v]=true;
        }
    }
    while(!q.empty()){
        int u=q.front();
//        cout<<" > "<<u<<endl;
        for(int v=1;v<=n;v++){
            if(dist[v]>(dist[u]+dis[u][v])){
                dist[v]=dist[u]+dis[u][v];
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        q.pop();
        vis[u]=false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int kk;
    memset(dis,0x3f,sizeof(dis));
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&dis[i][j]);
    spfa(1);
    int ans = dist[n];
    int loop1 = dist[1];
    spfa(n);
    int loopn = dist[n];
    ans = min(ans,loop1+loopn);
    printf("%d\n",ans);
    }
    return 0;
}
