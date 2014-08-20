//枚举+贪心，只贪心是错误的
//因为有可能出现下一个top出来的行和列是相等的的情况。
//15700 KB	373 ms
#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
const int mx1=1e3+5;
const int mx2=1e6+5;
priority_queue <ll> r,c;
ll row[mx1],col[mx1];
ll d1[mx2],d2[mx2];
int main(){
int m,n,k,i,j;
ll d,p,temp;
scanf("%d%d%d%I64d",&n,&m,&k,&p);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        scanf("%I64d",&d);
        row[i]+=d;
        col[j]+=d;
    }
d1[0]=d2[0]=0;
for(i=1;i<=n;i++){
    r.push(row[i]);
}
for(i=1;i<=k;i++){
    d1[i]=d1[i-1]+r.top();
    temp=r.top();
    r.pop();
    r.push(temp-p*m);
}
for(i=1;i<=m;i++){
    c.push(col[i]);
}
for(i=1;i<=k;i++){
    d2[i]=d2[i-1]+c.top();
    temp=c.top();
    c.pop();
    c.push(temp-p*n);
}
ll ans = (ll)-1e17;
for(i=0;i<=k;i++){
    ans=max(ans,d1[i]+d2[k-i]-(ll)(k-i)*i*p);
}
printf("%I64d",ans);
}