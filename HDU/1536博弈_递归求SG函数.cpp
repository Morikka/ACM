//只能通过递归+记忆化来求取SG值。
//800 KB 125 ms
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105];
int g[10005];
int k;
int sg(int n) {
    int has[101]={0};
    int i;
    for(i=0;i<k;i++){
        if(n<a[i])break;
        if(g[n-a[i]]==-1)g[n-a[i]]=sg(n-a[i]);
        has[g[n-a[i]]]=1;
    }
    for(i=0;;i++)
        if(has[i]==0)return i;
    }
int main() {
    int cnt,n,m,i,l;
    while(scanf("%d",&k)!=EOF&&k) {
        memset(g,-1,sizeof(g));
        for(i=0; i<k; i++)
            scanf("%d",&a[i]);
        sort(a,a+k);
        scanf("%d",&m);
        while(m--) {
            cnt=0;
            scanf("%d",&l);
            for(i=0; i<l; i++) {
                scanf("%d",&n);
                if(g[n]==-1)g[n]=sg(n);
                cnt^=g[n];
                }
                if(cnt)printf("W");
                else printf("L");
                if(m==0)printf("\n");
            }
        }
        return 0;
    }