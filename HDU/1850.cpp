//nim博弈，求第一步想赢的话有多少种走法
#include<cstdio>
using namespace std;
int a[105];
int main()
{
    int i,m,ans,sum;
    while(~scanf("%d",&m)&&m)
    {
        sum=ans=0;
        for(i=0; i<m; i++){
            scanf("%d",&a[i]);
            ans=ans^a[i];
        }
        if(ans){
            for(i=0; i<m; i++){
                if(a[i]>(ans^a[i]))sum++;
            }
            printf("%d\n",sum);
        }
        else printf("0\n");
    }
}
