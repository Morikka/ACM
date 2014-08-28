//78 ms	1200 KB
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int mx = 3e5+5;
int a[mx];
int main(){
int n;
long long ans=0;
scanf("%d",&n);
for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
if(n==1)
    printf("%d",a[0]);
else if(n==2)printf("%d",a[0]+a[0]+a[1]+a[1]);
else{
    sort(a,a+n);
    for(int i=0;i<n;i++)
        ans+=(long long)(i+2)*(long long)a[i];
    ans-=a[n-1];
printf("%I64d",ans);
}
}
