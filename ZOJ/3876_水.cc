#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int jud(int d){
    if(d%400==0)
        return 1;
    if(d%4==0&&d%100!=0)
        return 1;
    return 0;
}
int main(){
    #ifdef LOCAL
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    #endif
    int T,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&d);
        int j = (d-1)+(d-1)/4-(d-1)/100+(d-1)/400+121+jud(d);
        j = j % 7;
        if(j==0)puts("6");
        if(j==1)puts("9");
        if(j==2)puts("6");
        if(j==3)puts("5");
        if(j==4)puts("5");
        if(j==5)puts("5");
        if(j==6)puts("5");
    }
    return 0;
}