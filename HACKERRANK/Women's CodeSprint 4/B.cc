#include <cstdio>
#include <cstring>
#include <iostream>
#define mx 120005
using namespace std;
int s[mx],fa[mx],rnk[mx];
int link[mx],cnt[mx],vis[mx];
int getfather(int v){
    if (fa[v]==v)
    	return v;
	fa[v]=getfather(fa[v]);
    return fa[v];
}
void unn(int a,int b){
	int fx = getfather(a);
	int fy = getfather(b);
	if(fx == fy)
		return;
	if(rnk[fy]>rnk[fx])
		fa[fx] = fy;
	else
		fa[fy] = fx;
	rnk[fx] += rnk[fy];
	rnk[fy] = rnk[fx];
}
int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	int t,n,a,b,jud;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		memset(rnk,0,sizeof(rnk));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			if(!s[i])jud++;
		}
		for(int i=1;i<=n;i++){
			fa[i] = i;
			rnk[i] = 1;
		}
		if(!jud%2){
			for(int i=1;i<=n;i++)
				cout<<n<<endl;
			return 0;
		}
		for(int i=1;i<n;i++){
			cin>>a>>b;
			cnt[a]++;
			cnt[b]++;
			if(s[a]&&s[b])unn(a,b);
		}
		for(int i=1;i<=n;i++)
			rnk[i] = rnk[getfather(i)];
		
		jud = 0;
		for(int i=1;i<=n;i++)
			cout<<i<<" "<<cnt[i]<<endl;
		for(int i=1;i<=n;i++){
			if(s[i]==0&&cnt[i]==1)
				jud++;
		}
		if(jud>=2)
			for(int i=1;i<=n;i++){
				cout<<n-1<<endl;
				return 0;
			}
		int pnt;
		if(jud==1){
			for(int i=1;i<=n;i++)
				if(s[i]==0&&cnt[i]==1)
					pnt = i;
			
		}


	}
	return 0;
}