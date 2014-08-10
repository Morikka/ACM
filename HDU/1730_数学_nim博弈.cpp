//黑棋有可能在白旗后面...
//亚达...好坑啊...害我想了半天...
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int i,m,n,a,b;
    int cnt;
    while(~scanf("%d%d",&n,&m)){
    cnt=0;
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        cnt^=(b-a-1);
    }
    if(cnt==0)printf("BAD LUCK!\n");
    else printf("I WIN!\n");
    }
}
