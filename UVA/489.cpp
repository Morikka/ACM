//lrj紫书例题4-2
//居然可以在游戏输了之后还继续让所有字母都猜出来真的是好坑啊...
//果然脑洞不够大orz...
//0 KB	85 ms
#include<cstdio>
#include<cstring>
using namespace std;
char chr[105];
char chr2[105];
bool num[30],jud;
int main(){
    int n,l1,l2,i,cnt;
    while(scanf("%d",&n)&&(n!=-1)){
        cnt=0;//记录死亡次数
        jud=false;
        memset(num,false,sizeof(num));//统计字符中的字母是否被猜出来
        scanf("%s",chr);
        scanf("%s",chr2);
        l1=strlen(chr);
        l2=strlen(chr2);
        for(i=0; i<l1; i++){
            num[chr[i]-'a']=true;
        }
        for(i=0; i<l2; i++){
            if(cnt>=7)break;
            if(num[chr2[i]-'a'])num[chr2[i]-'a']=false;
            else cnt++;
        }
        for(i=0; i<30; i++)if(num[i])
                jud=true;
        //printf("%d",cnt);
        printf("Round %d\n",n);
        if(jud){
            if(cnt>=7)printf("You lose.\n");
            else printf("You chickened out.\n");
        }
        else printf("You win.\n");
    }
    return 0;
}
