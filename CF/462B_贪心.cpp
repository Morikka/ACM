//15MS 100KB
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int mx = 1e5+5;
char chr[mx];
int word[26];
int main(){
int n,k,num=0,cnt=0,pos=25;
scanf("%d%d",&n,&k);
scanf("%s",chr);
memset(word,0,sizeof(word));
int l = strlen(chr);
long long ans=0;
for(int i=0;i<l;i++){
word[chr[i]-'A']++;
}
sort(word,word+26);
while(num<k){
    cnt=min(word[pos--],k-num);
    num+=cnt;
    ans+=(long long)cnt*(long long)cnt;
}
printf("%I64d",ans);
}
