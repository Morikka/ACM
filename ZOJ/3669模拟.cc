/*
题目：给你13张牌，加上一张牌如果能赢则输出那张牌。（一切可能都得输出
思路：
1. 枚举所有可能的牌，让它凑成十四张牌。
2. 枚举所有可能是两张的牌，在数组中减去两站，然后判断是否能组成4份三张牌，然后再加上这两张牌。
3. 对三张牌的判断，可以如果有三个一样的就先减掉它判断剩下的能不能组成k-1份三张牌，然后把这三张一样的加回去。
同理如果有三张连续的也先减掉它判断剩下的能不能组成k-1份三张牌，然后把这三张连续的加回去。
4. time是0呦。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char chr[30];
int a[4][9],ans[4][9];
void init(){
    int k1,k2;
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<26;i+=2){
        k1=chr[i]-'1';
        if(chr[i+1]=='m')k2=0;
        if(chr[i+1]=='p')k2=1;
        if(chr[i+1]=='s')k2=2;
        if(chr[i+1]=='z')k2=3;
    a[k2][k1]++;
    }
/*    for(int i=0;i<4;i++){
        for(int j=0;j<9;j++)
            printf("%d ",a[i][j]);
        puts("");
    }*/
}
bool find(int k){
    int ans = false;
    if(k==0)
        return true;
    for(int i=0;i<4;i++)
        for(int j=0;j<9;j++){
            if(i==3&&j>6)continue;
            if(a[i][j]==3){
                a[i][j]-=3;
                if(find(k-1))ans=true;
                a[i][j]+=3;
            }
        }
    for(int i=0;i<3;i++)
        for(int j=0;j<7;j++){
            if(a[i][j]>0&&a[i][j+1]>0&&a[i][j+2]>0){
                a[i][j]--;
                a[i][j+1]--;
                a[i][j+2]--;
                if(find(k-1))ans=true;
                a[i][j]++;
                a[i][j+1]++;
                a[i][j+2]++;
            }
        }
    return ans;
}
void cnt(int r1,int r2){
    for(int i=0;i<4;i++)
        for(int j=0;j<9;j++){
            if(i==3&&j>6)continue;
            if(a[i][j]<2)continue;
            a[i][j]-=2;
            if(find(4))
                ans[r1][r2]=1;
            a[i][j]+=2;
        }
}
void print(){
    int cnt=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<9;j++)
            if(ans[i][j]!=0)
                cnt++;
    if(cnt==0){
        puts("0");
        return;
    }
    printf("%d ",cnt);
    for(int i=0;i<4;i++)
        for(int j=0;j<9;j++)
            if(ans[i][j]!=0){
                printf("%d",j+1);
                if(i==0)printf("m");
                if(i==1)printf("p");
                if(i==2)printf("s");
                if(i==3)printf("z");
            }
    puts("");
}
int main(){
/*    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    while(scanf("%s",chr)!=EOF){
        init();
        for(int i=0;i<4;i++)
            for(int j=0;j<9;j++){
                if(i==3&&j>6)continue;
                if(a[i][j]==4)continue;
                a[i][j]++;
                cnt(i,j);
                a[i][j]--;
            }
        print();
    }
return 0;
}
