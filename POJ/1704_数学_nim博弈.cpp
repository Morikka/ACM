//需要分奇偶讨论，如果是奇数就和0组成一对。
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main(){
int n,t,i,ans,pos;
scanf("%d",&t);
while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    ans=pos=0;
    if(n&1){
        ans=a[pos]-1;
        pos=1;
    }
    else{
        ans=a[pos+1]-a[pos]-1;
        pos=2;
    }
    while(pos<n){
        ans=ans^(a[pos+1]-a[pos]-1);
        pos+=2;
    }
    if(ans == 0)
        printf("Bob will win\n");
    else
        printf("Georgia will win\n");
}
}
