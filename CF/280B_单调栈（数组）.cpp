//单调栈——数组和栈对比一下...
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
stack<int> s;
int main(){
    int n,i,x,p,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        while(!s.empty()){
            ans=max(ans,s.top()^x);
            if(s.top()<x)s.pop();
            else break;
        }
        s.push(x);
    }
    printf("%d\n",ans);
    return 0;
}

