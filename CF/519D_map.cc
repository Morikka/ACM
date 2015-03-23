/*
题目：求一个字符串开始和结尾的字母是相同并且字母喜欢度的和为0。
可以转换为求相同字母的相等前缀值。
eg：ehifaejira，如果f和第二个a的前缀和相等，那么aegira一定为0。
放入map中搞一下。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int mx = 1e5+10;
int cnt[26],l;
long long sum[mx],res=0;
char chr[mx];
map<long long,int> mp[26];
int main(){
for(int i=0;i<26;i++)
    scanf("%d",&cnt[i]);
scanf("%s",chr);
l = strlen(chr);
sum[0]=cnt[chr[0]-'a'];
for(int i=1;i<l;i++){
    sum[i]=cnt[chr[i]-'a'];
    sum[i]+=sum[i-1];
//    cout<<sum[i]<<endl;
}
for (int i = 0; i < l; i++) {
        int index = chr[i] - 'a';
        res += mp[index][sum[i - 1]];
        mp[index][sum[i]]++;
    }
cout<<res<<endl;
return 0;
}
