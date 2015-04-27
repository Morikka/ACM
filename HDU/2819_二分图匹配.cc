#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mx = 105;
bool bmap[mx][mx];
bool bmask[mx];
int cx[mx],cy[mx],c[mx];
int n;
int findpath(int u){
    for(int i=1;i<=n;i++)
        if(bmap[u][i]&&!bmask[i]){
            bmask[i]=1;
            if(cy[i]==-1||findpath(cy[i])){
                cy[i]=u;
                cx[u]=i;
                return 1;
            }
        }
    return 0;
}
int MaxMatch(){
    int res = 0;
    for(int i=1;i<=n;i++){
        cy[i]=-1;
        cx[i]=-1;
    }
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
    int a,ans;
    while(~scanf("%d",&n)){
        ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&a);
                if(a==1)bmap[i][j]=true;
                else bmap[i][j]=false;
            }
        if(MaxMatch()==n){
            for(int i=1;i<=n;i++)
                c[i]=cx[i];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(c[j]==i&&j!=i){
                        ans++;
                        swap(c[i],c[j]);
                        break;
                    }
                }
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)
                c[i]=cx[i];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(c[j]==i&&j!=i){
                        printf("C %d %d\n",c[i],c[j]);
                        swap(c[i],c[j]);
                        break;
                    }
                }
            }
        }
        else puts("-1");
    }
    return 0;
}
