//lrj��������4-2
//��Ȼ��������Ϸ����֮�󻹼�����������ĸ���³�������ǺÿӰ�...
//��Ȼ�Զ�������orz...
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
        cnt=0;//��¼��������
        jud=false;
        memset(num,false,sizeof(num));//ͳ���ַ��е���ĸ�Ƿ񱻲³���
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
