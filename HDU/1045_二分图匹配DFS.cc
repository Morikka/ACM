#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char chr[5][5];
int row[5][5],col[5][5],maxr,maxc;
bool way[25][25];
bool bmask[25];
int cx[25];
int cy[25];
int findpath(int u){
    for(int i=0;i<maxr;i++){
        if(way[u][i]&&!bmask[i]){
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
    int res=0;
    for(int i=0;i<maxc;i++)
        cx[i]=-1;
    for(int i=0;i<maxr;i++)
        cy[i]=-1;
    for(int i=0;i<maxc;i++){
        if(cx[i]==-1){
            for(int j=0;j<maxr;j++)
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
    int n;
    while(scanf("%d",&n)&&n){
        maxr=maxc=0;
        memset(row,-1,sizeof(row));
        memset(col,-1,sizeof(col));
        memset(way,0,sizeof(way));
        for(int i=0;i<n;i++)
            scanf("%s",chr[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(chr[i][j]=='.'&&col[i][j]==-1){
                    for(int k=j;k<n&&chr[i][k]=='.';k++)
                        col[i][k]=maxc;
                    maxc++;
                }
                if(chr[j][i]=='.'&&row[j][i]==-1){
                    for(int k=j;k<n&&chr[k][i]=='.';k++)
                        row[k][i]=maxr;
                    maxr++;
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(chr[i][j]=='.')
                    way[col[i][j]][row[i][j]]=true;

/*for(int i=0;i<maxc;i++){
    for(int j=0;j<maxr;j++)
        cout<<way[i][j]<<" ";
    puts("");
}*/
    printf("%d\n",MaxMatch());
    }
return 0;
}