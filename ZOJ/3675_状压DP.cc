/*
题意：用一个长度为n的带有许多缺口的指甲刀剪长度为m的指甲，问最少需要几下。
思路：将指甲刀的所有能剪出来的可能性处理出来，丢到set中。
      然后循环最多m次。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int inf = 0x3f3f3f3f;
set<int> cc;
char chr[11];
int dp[1050000];
int main(){
    int m,n,ans;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%d",&n)&&n){
        scanf("%s%d",chr,&m);
        cc.clear();
        int cnt=0,l=(1<<m);
        for(int i=0;i<strlen(chr);i++){
            cnt<<=1;
            if(chr[i]=='*')
                cnt+=1;
        }
        if(m>n)
            cnt=(cnt<<(m-n));
        while(cnt){
            if(cnt<l)
                cc.insert(cnt);
            cnt>>=1;
        }
        cnt=0;
        for(int i=strlen(chr)-1;i>=0;i--){
            cnt<<=1;
            if(chr[i]=='*')
                cnt+=1;
        }
        if(m>n)
            cnt=(cnt<<(m-n));
        while(cnt){
            if(cnt<l)
                cc.insert(cnt);
            cnt>>=1;
        }
/*        for(set<int>::iterator it=cc.begin();it!=cc.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;*/
        if(cc.empty())
            puts("-1");
        else{
            ans=0x3f3f3f3f;
            memset(dp,0x3f,sizeof(dp));
            dp[l-1]=0;
            while(m--){
                for(int j=l-1;j>=0;j--){
                    if(dp[j]==inf)continue;
                    for(set<int>::iterator it=cc.begin();it!=cc.end();it++){
                        int swap=((j^*it)&j);
                        if(swap<0)break;
                        dp[swap]=min(dp[swap],dp[j]+1);
                    }
                }
                if(dp[0]<inf)break;
            }
            printf("%d\n",dp[0]);
        }
    }
    return 0;
}
