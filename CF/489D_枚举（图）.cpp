/*
ö�������յ���㾭��һ�������㵽���յ��·��
Ȼ���������1����һ��C��n��2��
*/
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 3010;
vector<int>g[maxn];
vector<int>rg[maxn];
int deg[maxn];
int main(){
int n,m;
scanf("%d%d",&n,&m);
int u,v;
for(int i=0;i<m;i++){
    scanf("%d%d",&u,&v);
    u--,v--;
    g[u].push_back(v);
    rg[v].push_back(u);
}
    long long ans = 0;
    for(int i=0;i<n;i++){
        memset(deg,0,sizeof(deg));
        for(int j=0;j<g[i].size();j++)deg[g[i][j]]=1;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            long long cnt = 0;
            for(int k=0;k<rg[j].size();k++){
                if(deg[rg[j][k]])cnt++;
            }
        ans+=(cnt-1)*cnt/2;
        }
    }
    printf("%I64d\n",ans);
}
