#include<cstdio>
using namespace std;
int main(){
    int cnt,m,i,a;
    while(scanf("%d",&m)&&m){
    cnt=0;
    for(i=0;i<m;i++){
        scanf("%d",&a);
        cnt^=a;
    }
    if(cnt)printf("Rabbit Win!\n");
    else printf("Grass Win!\n");
    }
}
