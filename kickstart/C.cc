#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int dis[105][105];
int main(){
    freopen("C-large.in","r",stdin);
    // freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int t,n,m,p,u,v,w;
    cin>>t;
    for(int Case = 1; Case<=t;Case++){
        cin>>n>>m>>p;
        memset(dis,0x3f,sizeof(dis));
        while(m--){
            cin>>u>>v>>w;
            dis[u][v] = dis[v][u] = w;
        }
        for(int i=0;i<=n;i++)
            dis[i][i]=0;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

        double ans = 0.0,ans1 = 1.0,ans2 = 0.0,ans3=(n-1),tmp=0.0;
        double dis1 = 0.0,dis2 = 0.0,dis3 = 0.0;
        for(int i=1;i<=n;i++)
            dis1+=dis[1][i];
        for(int i=2;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis2+=dis[i][j];

        for(int i=1;i<=p;i++){
            ans += (ans1 * dis1 + ans2 * dis2)/ (n-1);
            tmp = ans1;
            ans1 = ans2;
            ans2 = (tmp + (n-2)*ans2)/(n-1);
        }
        // cout<<ans1<<" "<<ans2<<endl;
        // ans = ans1*dis2 + ans2*dis1;
        printf("Case #%d: %.6f\n",Case,ans);
    }
    return 0;
}