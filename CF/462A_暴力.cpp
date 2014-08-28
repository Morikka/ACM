//15ms 0kb
#include<cstdio>
using namespace std;
char chr[105][105];
int main(){
bool jud=true;
int cnt=0,n;
    scanf("%d",&n);
    for(int i=0;i<n+2;i++)
        chr[0][i]=chr[n+1][i]='x';
    for(int i=1;i<=n;i++){
        chr[i][0]=chr[i][n+1]='x';
        scanf("%s",chr[i]+1);
    }
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
            cnt=0;
            if(chr[i-1][j]=='o')cnt++;
            if(chr[i+1][j]=='o')cnt++;
            if(chr[i][j-1]=='o')cnt++;
            if(chr[i][j+1]=='o')cnt++;
        if(cnt%2)jud=false;
}
if(jud)printf("YES");
else printf("NO");
}