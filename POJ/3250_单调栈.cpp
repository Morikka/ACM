//单调栈水题,一开始可以在栈里面放INF减少空栈的判断
//1312K	188MS
#include<cstdio>
#include<cstring>
#include<stack>
#include<iostream>
using namespace std;
stack<long long>s;
int main(){
long long sum,ans,num;
int n,i;
while(scanf("%d",&n)!=EOF){
    ans=0;
    s.push(1000000005);
    for(i=0;i<n;i++){
        scanf("%lld",&num);
        while(s.top()<=num){
            s.pop();
        }
        ans+=s.size()-1;
        s.push(num);
        }
    printf("%lld\n",ans);
    while(!s.empty())s.pop();
}
return 0;
}
