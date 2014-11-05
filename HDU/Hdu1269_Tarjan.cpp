#include<cstdio>
#include<cstring>
using namespace std;
const int mx = 1e5+5;
int stk[mx],tot_s,index_s,ans;
int instack[mx];
int DFN[mx],LOW[mx];
int tot,head[mx];
struct Eage {
    int from,to;
    int next;
} eage[mx*10];
void Add(int a,int b) {
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].next=head[a];
    head[a]=tot++;
}
void Tarjan(int k) {
    int j,v;
    if(ans)return;
    stk[tot_s++]=k;
    instack[k]=1;
    DFN[k]=LOW[k]=index_s++;
    for(j=head[k];j!=-1; j=eage[j].next){
        v=eage[j].to;
        if(instack[v])LOW[k]=LOW[k]>DFN[v]?DFN[v]:LOW[k];
        else {
            Tarjan(v);
            if(ans)return;
            LOW[k]=LOW[k]>LOW[v]?LOW[v]:LOW[k];
        }
        if(DFN[k]==LOW[k]) {
            do {
                ans++;
                instack[stk[--tot_s]]=0;
            } while(stk[tot_s]!=k);
        }
    }
}
int main() {
    int n,m,i,a,b;
    while(scanf("%d%d",&n,&m)&&n+m) {
        tot=0;
        memset(head,-1,sizeof(head));
        while(m--) {
            scanf("%d%d",&a,&b);
            Add(a,b);
        }
        if(n<=1) {
            printf("Yes\n"); continue;
        }
        if(m==0) {
            printf("No\n"); continue;
        }
        tot_s=0;
        index_s=1;
        memset(instack,0,sizeof(instack));
        memset(DFN,-1,sizeof(DFN));
        memset(LOW,-1,sizeof(LOW));
        ans=0;
        Tarjan(1);
        if(ans==n)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
