#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int mn = 210,mx = 1000500,INF = 0x1f1f1f1f;
int di[mn][mn];
struct Edge{
    int to,next,cap,flow,cost;
}edge[mx];
int head[mn],tol,N;
int pre[mn],dis[mn];
bool vis[mn];
void init(int n){
    N=n*2+3;
    tol = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u]=tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v]=tol++;
}
bool spfa(int s, int t){
    queue<int>q;
    for (int i = 0; i < N; i++){
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i].cost ){
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t] == -1)return false;
    else return true;
}
//返回的是最大流,cost存的是最小费用
int MinCostMaxFlow(int s, int t, int &cost){
    int flow = 0;
    cost = 0;
    while (spfa(s, t)){
        int Min = INF;
        for (int i = pre[t]; i != -1; i=pre[edge[i^1].to]){
            if (Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for (int i = pre[t]; i != -1; i=pre[edge[i^1].to]){
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int n,m,k,x,y,q,ans,s,t;
    while(~scanf("%d%d%d",&n,&m,&k)&&(n+m+k)){
        memset(di,0x3f,sizeof(di));
        while(m--){
            scanf("%d%d%d",&x,&y,&q);
            di[x][y]=di[y][x]=min(di[x][y],q);
        }
        for(int i=0;i<=n;i++)
            di[i][i]=0;
        for(int tt=0;tt<=n;tt++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    if(di[i][tt]+di[tt][j]<di[i][j])
                        di[i][j]=di[i][tt]+di[tt][j];
        init(n);
        s=2*n+1;
        t=2*n+2;
        addedge(s,0,k,0);
        addedge(0,t,k,0);
        for(int i=1;i<=n;i++){
            addedge(0,i,1,di[0][i]);
            addedge(i,i+n,1,-100000);
            addedge(i+n,t,1,di[0][i]);
        }
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                addedge(i+n,j,1,di[i][j]);
        int res = MinCostMaxFlow(n*2+1,n*2+2,ans);
      cout<<ans+100000*n<<endl;
        }
return 0;
}
