//����ջ
//62 ms	11700 KB
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx = 1e6+5;
int p[mx],s[mx],f[mx];
int main(){
int i,n,t,top=0;
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&p[i]);
for(i=n-1;i>=0;i--){
    int t=0;
    while(top&&p[s[top-1]]<p[i])
        f[i]=t=max(t+1,f[s[--top]]);
    s[top++]=i;
}
printf("%d",*max_element(f,f+n));
return 0;
}