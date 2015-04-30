#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int mx = 410,inf=1<<28;
int map[mx][mx];
int node;
int p[mx];
bool EK_Bfs(int start,int end){
    queue<int> que;
    bool flag[mx];
    memset(flag,0,sizeof(flag));
    memset(p,-1,sizeof(p));
    que.push(start);
    flag[start]=true;
    while(!que.empty()){
        int e = que.front();
        if(e==end)
            return true;
        que.pop();
        for(int i=1;i<=node;i++){
            if(map[e][i]&&!flag[i]){
                flag[i]=true;
                p[i]=e;
                que.push(i);
            }
        }
    }
    return false;
}
int EK_Max_Flow(int start,int end){
    int u,flow_ans=0,mn;
    while(EK_Bfs(start,end)){
        mn=inf;
        u=end;
        while(p[u]!=-1){
            mn=min(mn,map[p[u]][u]);
            u=p[u];
        }
        flow_ans+=mn;
        u=end;
        while(p[u]!=-1){
            map[p[u]][u]-=mn;
            map[u][p[u]]+=mn;
            u=p[u];
        }
    }
    return flow_ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int n,f,d,nf,nd,a,l;
    scanf("%d%d%d",&n,&f,&d);
    memset(map,0,sizeof(map));
    l=2*n+f+d+1;
    for(int i=1;i<=n;i++){
        map[i][n+i]=1;
        scanf("%d%d",&nf,&nd);
        for(int j=0;j<nf;j++){
            scanf("%d",&a);
            map[0][2*n+a]=1;
            map[2*n+a][i]=1;
        }
        for(int j=0;j<nd;j++){
            scanf("%d",&a);
            map[2*n+f+a][l]=1;
            map[i+n][2*n+f+a]=1;
        }
    }
    node=l;
    printf("%d\n",EK_Max_Flow(0,l));
    return 0;
}