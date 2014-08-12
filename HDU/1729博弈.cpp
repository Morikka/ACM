//由题意知，对于si，p*p+p<si,则p是必败态。则将si用p替换，寻找下一个必败态。
//240 KB	15 ms
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int cas;
int sg[1000005];//start b end a
int solve(int a,int b){
if(b==0||a==b)return 0;
int p=(sqrt(a*1.0));
while(p*p+p>=a)p--;
if(b>p)return a-b;
if(b==p)return 0;
return solve(p,b);
}
int main(){
int i,a,b,n,ans;
while(scanf("%d",&n)&&n){
    ans=0;
for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    ans^=solve(a,b);
    }
    printf("Case %d:\n",++cas);
    if(ans)printf("Yes\n");
    else printf("No\n");
}
}