/*

题目：在m*n的格子内，从S点走到D点，每个点只能走一次，并且X点不能走。
DFS修改状态后一定要再改回去OJZ，就算不用全局变量也要改回去OJZ
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
char chr[10][10];
bool vis[10][10];
int n,m,t;

bool dfs(int x,int y,int k){

//cout<<x<<" "<<y<<" "<<k<<" "<<vis[x][y]<<endl;

    if(chr[x][y]=='D')
        if(k==t)return true;
        else return false;
    if(k>=t)return false;
    if(vis[x][y])return false;

    k++;
    vis[x][y]=true;

    if( x         && (chr[x-1][y]=='.'||chr[x-1][y]=='D') && dfs(x-1,y,k) ) return true;
    if( (x<(n-1)) && (chr[x+1][y]=='.'||chr[x+1][y]=='D') && dfs(x+1,y,k) ) return true;
    if( y         && (chr[x][y-1]=='.'||chr[x][y-1]=='D') && dfs(x,y-1,k) ) return true;
    if( (y<(m-1)) && (chr[x][y+1]=='.'||chr[x][y+1]=='D') && dfs(x,y+1,k) ) return true;

    vis[x][y]=false;//remember this!!!

return false;
}

int main(){

int ex,ey,sx,sy,cnt;

    while(~scanf("%d%d%d",&n,&m,&t)&&(n+m+t)){

        memset(vis,false,sizeof(vis));

        for(int i=0;i<n;i++)
            scanf("%s",chr[i]);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(chr[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                else if(chr[i][j]=='D'){
                    ex=i;
                    ey=j;
                }
            }
        cnt=(abs(ey-sy)+abs(ex-sx)+t)%2;
        if(cnt==1)
            puts("NO");
        else if(dfs(sx,sy,0))
            puts("YES");
        else puts("NO");
    }
return 0;
}
