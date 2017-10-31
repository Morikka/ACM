#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dp[105][55];
bool vis[105];

struct Way{
	int w,c,p;
};

vector<Way> way[55];

int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);

	int T,n,m1,m2,l,a1,a2,a3;
	Way tmp;
	cin>>T;
	while(T--){
		cin>>n>>m1>>m2>>l;
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m1;i++){
			cin>>a1>>a2;
			tmp.w = a2;
			tmp.c = 1;
			tmp.p = 1;
			way[a1].push_back(tmp);
			tmp.w = a1;
			way[a2].push_back(tmp);
		}
		for(int i=0;i<m2;i++){
			cin>>a1>>a2>>a3;
			tmp.w = a2;
			tmp.c = a3;
			tmp.p = 2;
			way[a1].push_back(tmp);
			tmp.w = a1;
			way[a2].push_back(tmp);
		}
		dp[1][0] = 0;
		vis[1] = true;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int a = q.front();
			cout<<"a is "<<a<<endl;
			q.pop();
			for(int i=0;i<=m1;i++){
				if(dp[a][i]<0x3f3f3f3f){
					for(int j=0;j<way[a].size();j++){
						tmp = way[a][j];
						cout<<"tmp.w is "<<tmp.w<<endl;
						if(tmp.p==1){
							dp[tmp.w][i+1] = min(dp[tmp.w][i+1],dp[a][i]+1);
							if(tmp.w==3&&i==1)
								cout<<"fuck"<<endl;

						}else{
							dp[tmp.w][i] = min(dp[tmp.w][i],dp[a][i]+tmp.c);
							if(!vis[tmp.w]){
								q.push(tmp.w);
								vis[tmp.w] = true;
							}
						}
					}
				}
				else
					break;
			}
		}
		cout<<dp[3][2]<<endl;
		int ans = 0x3f3f3f3f;
		for(int i=0;i<=m1;i++)
			if((dp[n][i] - i)<=ans) ans = dp[n][i] - i;
		if(ans>l)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
		cout<<"  ----   "<<endl;
	}
	return 0;
}