#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M = 10005,MOD=1000000009;
#define LL long long
int idx;
char str[25];
int bcd[2005][10];
LL dp[205][2005];
int digit[205],len,n;
struct Trie{
    Trie *next[2];
    Trie *fail;
    int isword,kind;
};
Trie *que[M],s[M];
Trie *NewNode(){
    Trie *tmp=&s[idx];
    tmp->next[0]=tmp->next[1]=NULL;
    tmp->isword=0;
    tmp->fail=NULL;
    tmp->kind=idx++;
    return tmp;
}
void Insert(Trie *root,char *s,int l){
    Trie *p=root;
    for(int i=0; i<l; i++){
        if(p->next[s[i]-'0']==NULL) p->next[s[i]-'0']=NewNode();
        p=p->next[s[i]-'0'];
    }
    p->isword=1;
}
void Bulid_fail(Trie *root){
    int head=0,tail=0;
    que[tail++]=root;
    root->fail=NULL;
    while(head<tail){
        Trie *tmp=que[head++];
        for(int i=0; i<2; i++){
            if(tmp->next[i]){
                if(tmp==root) tmp->next[i]->fail=root;
                else{
                    Trie *p=tmp->fail;
                    while(p!=NULL){
                        if(p->next[i]){
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) tmp->next[i]->fail=root;
                }
                if(tmp->next[i]->fail->isword)
                    tmp->next[i]->isword=tmp->next[i]->fail->isword;
                que[tail++]=tmp->next[i];
            }
            else if(tmp==root) tmp->next[i]=root;
            else tmp->next[i]=tmp->fail->next[i];
        }
    }
}
//状态当前在状态pre,经过一个数字num之后到达哪个状态
//如果不合法，返回-1
int BCD(int pre,int num){
    if(s[pre].isword) return -1;
    int cur=pre;
    for(int i=3;i>=0;i--){
        int k=(num>>i)&1;
        if(s[cur].next[k]->isword) return -1;
        else cur=s[cur].next[k]->kind;
    }
    return cur;
}
void Get_next(){
    for(int i=0;i<idx;i++){
        for(int j=0;j<10;j++){
            bcd[i][j]=BCD(i,j);
        }
    }
}
LL dfs(int l,int pos,bool zero,bool jud){
    if(pos<0) return 0;
    if(l==0)return 1;
    if(!jud&&dp[l][pos]>=0)return dp[l][pos];
    LL ans = 0;
    int nex = jud ? digit[l] : 9;
    for(int i=0;i<=nex;i++)
        ans += dfs( l-1 , zero&&i==0&&l>1 ? pos : bcd[pos][i] , zero&&i==0 , jud&&i==nex );
    ans%=MOD;
    return jud ? ans : dp[l][pos]=ans;
}
LL cal(char *s,int l){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=l;i++) digit[l-i+1]=s[i-1]-'0';
    dfs(l,0,true,true);
}
char A[205],B[205];
void sub(char *s,int len){
    for(int i=len-1;i>=0;i--){
        if(s[i]=='0') s[i]='9';
        else{
            s[i]--;
            break;
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        idx=0;
        Trie *root=NewNode();
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%s",str);
            Insert(root,str,strlen(str));
        }
        Bulid_fail(root);
        Get_next();
        scanf("%s",A);
        sub(A,strlen(A));
        scanf("%s",B);
        cout<<((cal(B,strlen(B))-cal(A,strlen(A)))%MOD+MOD)%MOD<<endl;
    }
    return 0;
}
