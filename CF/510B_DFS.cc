/*
需要判断不能走循环路。
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char chr[55][55];
bool jud[55][55];
int m,n;
bool dfs(int x,int y,int j){
    if(jud[x][y])return true;
    jud[x][y]=true;
    bool rt=false;
    if(j!=0&&x>0&&chr[x][y]==chr[x-1][y])if(dfs(x-1,y,1))rt=true;
    if(j!=1&&x+1<n&&chr[x][y]==chr[x+1][y])if(dfs(x+1,y,0))rt=true;
    if(j!=2&&y>0&&chr[x][y]==chr[x][y-1])if(dfs(x,y-1,3))rt=true;
    if(j!=3&&y+1<m&&chr[x][y]==chr[x][y+1])if(dfs(x,y+1,2))rt=true;
return rt;
}
int main(){
bool ans = false;
scanf("%d%d",&n,&m);
memset(jud,0,sizeof(jud));
for(int i=0;i<n;i++)
    scanf("%s",chr[i]);
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(!jud[i][j]&&dfs(i,j,-1)){
            ans=true;
        }
    }
if(ans)
    puts("Yes");
else
    puts("No");
return 0;
}
