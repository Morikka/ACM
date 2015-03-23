/*
题目比较难理解，理解了题目就是水题了。
就是给两个数组a和b，数组a可以做减法，每当在ai上减去X时i之前的数字也要减去和为X的数字。
就是要求不存在ai-bi，差值超过总差值。
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mx = 10005;
long long a1[mx],a2[mx],a3[mx],sum;
int main(){
    int l;
    bool jud;
    while(scanf("%d",&l)!=EOF){
        jud=true;
        sum=0;
        for(int i=0;i<l;i++)
            scanf("%I64d%I64d",&a1[i],&a2[i]);
        for(int i=0;i<l;i++){
            a3[i]=a1[i]-a2[i];
            sum+=a3[i];
            if(a3[i]<0)
                jud=false;
        }
        if(sum%2)jud=false;
        //if(sum==0)jud=false;
        sum=sum/2;
        for(int i=0;i<l;i++){
            if(a3[i]>sum)jud=false;
        }
        if(jud)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
