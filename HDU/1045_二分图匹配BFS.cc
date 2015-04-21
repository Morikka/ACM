#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char chr[5][5];
int row[5][5],col[5][5],maxr,maxc;
bool way[25][25];
int bmask[25];
int cx[25];
int cy[25];
int Queue[25];
int bprev[25];
int MaxMatch(){
    int res=0;
    int qs,qe;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    memset(bmask,-1,sizeof(bmask));
    for(int i=0;i<maxc;i++){
        if(cx[i]==-1){
            qs=qe=0;
            Queue[qe++]=i;
            bprev[i]=-1;
            bool flag = 0;
            while(qs<qe&&!flag){
                int u = Queue[qs];
                for(int v = 0;v<maxr&&!flag;v++){
                    if(way[u][v]&&bmask[v]!=i){
                        bmask[v]=i;
                        Queue[qe++]=cy[v];
                        if(cy[v]>=0){
                            bprev[cy[v]]=u;
                        }
                        else{
                            flag = 1;
                            int d = u,e = v;
                            while(d!=-1){
                                int t = cx[d];
                                cx[d] = e;
                                cy[e] = d;
                                d = bprev[d];
                                e = t;
                            }
                        }
                    }
                }
                qs++;
            }
            if(cx[i]!=-1)
                res++;
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
    printf("%d\n",MaxMatch());
    }
return 0;
}
