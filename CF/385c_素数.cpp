//brute force
//筛素数的同时计算素数的倍数有多少
//623 ms	88100 KB
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mx=1e7+5;
int num[mx],cnt[mx];
bool jud[mx];
void init() {
    int i,j;
    int c=0;
    jud[0]=jud[1]=false;
    for(i=2; i<=mx; i++) {
        c=0;
        if(jud[i]) {
                c+=num[i];
            for(j=2; i*j<=mx; j++) {
                c+=num[i*j];
                jud[i*j]=false;
                }
            }
        cnt[i]=c+cnt[i-1];
        //cout<<">> "<<i<<" "<<cnt[i]<<endl;
        }
    }
int main() {
    memset(jud,true,sizeof(jud));
    int i,n,m,a,l,r;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d",&a);
        num[a]++;
        }
    init();
    scanf("%d",&m);
    while(m--){
    scanf("%d%d",&l,&r);
    if(l>mx)l=mx;
    if(r>mx)r=mx;
    printf("%d\n",cnt[r]-cnt[l-1]);
    }
}
