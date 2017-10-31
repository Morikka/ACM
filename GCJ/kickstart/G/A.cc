#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a,n,p;
int cnt(int num,int k){
	int res = 1,cnt = num;
	while(k){
		if(k&1)
			res = res * cnt % p;
		k=k>>1;
		cnt=cnt*cnt%p;

	}
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int Cse,res;
	cin>>Cse;
	for(int cse=1;cse<=Cse;cse++){
		cout<<"Case #"<<cse<<": ";
		cin>>a>>n>>p;
		res = a%p;
		for(int i=2;i<=n;i++){
			res = cnt(res,i) % p;
		}
		cout<<res%p<<endl;
	}

	return 0;
}
