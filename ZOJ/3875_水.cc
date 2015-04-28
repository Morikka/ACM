#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int mx = 105;
struct food{
    char chr[55];
    int spd;
    bool operator < (const food &a)const{
        return spd < a.spd;
    }
}f1[mx],f2[mx],f3[mx];
int main(){
    #ifdef LOCAL
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int T,a1,a2,a3;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a1,&a2,&a3);
        for(int i=0;i<a1;i++){
            scanf("%s%d",f1[i].chr,&f1[i].spd);
        }
        for(int i=0;i<a2;i++){
            scanf("%s%d",f2[i].chr,&f2[i].spd);
        }
        for(int i=0;i<a3;i++){
            scanf("%s%d",f3[i].chr,&f3[i].spd);
        }
        sort(f1,f1+a1);
        sort(f2,f2+a2);
        sort(f3,f3+a3);
        int spe = f1[a1/2].spd + f2[a2/2].spd + f3[a3/2].spd;
        printf("%d ",spe);
        printf("%s ",f1[a1/2].chr);
        printf("%s ",f2[a2/2].chr);
        printf("%s\n",f3[a3/2].chr);
    }
    return 0;
}
