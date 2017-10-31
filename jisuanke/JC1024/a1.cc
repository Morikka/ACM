#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int dp[105][105][55];
int node[55][55];
// bool vis[55];
int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	int T,n,m1,m2,l,a1,a2,a3;
	cin>>T;
	while(T--){
		cin>>n>>m1>>m2>>l;
		queue<int> q1[55];
		queue<int> q2[55];
		memset(dp,0x3f,sizeof(dp));
		memset(node,0x3f,sizeof(node));
		// memset(vis,0,sizeof(vis));
		for(int i=0;i<m1;i++){
			cin>>a1>>a2;
			q1[a1].push(a2);
			q1[a2].push(a1);
		}
		for(int i=0;i<m2;i++){
			cin>>a1>>a2>>a3;
			q2[a1].push(a2);
			q2[a2].push(a1);
			node[a1][a2] = node[a2][a1] = a3;
		}
		dp[1][0] = 0;

	}

	return 0;
}