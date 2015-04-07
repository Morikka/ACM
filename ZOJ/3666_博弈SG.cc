/*
解法：预处理的时候求出每个点的SG值。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
const int mx = 10005;
using namespace std;
vector<int> q[mx];
vector<int>::iterator it;
int sg[mx],cnt[mx],cas;
int getsg(int x){
    memset(cnt,0,sizeof(cnt));
    for(it=q[x].begin();it!=q[x].end();it++){
        cnt[sg[*it]]=1;
    }
    for(int i=0;i<mx;i++){
        if(cnt[i]==0)return i;
    }
    return 0;
}
int main(){
//    freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
    int n,m,a,t,ans;
    while(~scanf("%d",&n)){
        printf("Case %d:\n",++cas);
        for(int i=1;i<n;i++){
            q[i].clear();
        }
        for(int i=1;i<n;i++){
            scanf("%d",&m);
            while(m--){
                scanf("%d",&a);
                q[i].push_back(a);
            }
        }
        sg[n]=0;
        for(int i=n-1;i;i--){
            sg[i]=getsg(i);
            //cout<<i<<" and sg i is "<<sg[i]<<endl;
        }
        scanf("%d",&t);
        while(t--){
            ans=0;
            scanf("%d",&m);
            while(m--){
                scanf("%d",&a);
                ans=ans^sg[a];
            }
            //printf("%d\n",ans);
            if(ans)
                puts("Alice");
            else
                puts("Bob");
        }
    }
    return 0;
}
