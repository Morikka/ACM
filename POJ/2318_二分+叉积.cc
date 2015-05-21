#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int mx = 5005;
int set[mx],x,y,cnt,y11,y2;
int tans[mx];
struct node{
    int x1,x2;
    bool operator < (const node &a)const{
        if(x1==a.x1)
            return x2<a.x2;
        return x1<a.x1;
    }
}Node[mx];
bool jud(int k){
    long long j1 = (Node[k].x1-x)*(y2-y);
    long long j2 = (Node[k].x2-x)*(y11-y);
    return j1>j2;
}
int solve(int l,int r){
    int m;
    while(l+1<r){
        //cout<<" > "<<m<<endl;
        m = (l+r)/2;
        jud(m) ? l = m : r = m;
    }
    return l;
}
int main(){
    int n,m,x1,x2;
    #ifndef ONLINE_JUDGE
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    while(scanf("%d",&n)&&n){
        memset(tans,0,sizeof(tans));
        scanf("%d%d%d%d%d",&m,&x1,&y11,&x2,&y2);
        Node[0].x1=x1;
        Node[0].x2=x1;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&Node[i].x1,&Node[i].x2);
        Node[n+1].x1=x2;
        Node[n+1].x2=x2;
        sort(Node,Node+n+2);
        while(m--){
            scanf("%d%d",&x,&y);
            int k = solve(0,n+2);
            tans[k]++;
        }
        for(int i=0;i<=n;i++){
            printf("%d: %d\n",i,tans[i]);
        }
        puts("");
    }
    return 0;
}
