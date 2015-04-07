/*
题目：
第一个是要算最少要给多少个点软件，才能使所有点都可以收到副本
第二个是要算最少加多少条边，才可以只给一个点软件使得所有点收到副本，即使得图变成强连通
思路：
1：tarjan求强连通，然后缩点，计算入度为0的强连通分量
2：设现在有a个入度为0的点，b个出度为0的点（缩完点后的点），最合理的加边方法肯定是从出度为0的点向入度为0的点添加有向边，
如果a > b, 添加a条边，所有点的入度都大于0，所有点的出度也大于0，问题解决，答案是a
如果 a <= b，添加a条边，所有点入度大于0，但是还有b-a个点，它们的出度是0，所以还要再加b-a条边，所以答案是b
综合两种情况，答案是max（a,b）
当然如果图原来就是强连通的话，输出就是1和0。
【参考自：http://blog.csdn.net/guard_mine/article/details/43021981
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int mx = 105;
bool nod[mx][mx];
int n,Dindex,Bcnt=0,Stop,DFN[mx],LOW[mx],instack[mx],Stap[mx],Belong[mx];
int In[mx],Out[mx];
void tarjan(int i){
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for(j=1;j<=n;j++){
        if(!nod[i][j])continue;
        if(!DFN[j]){
            tarjan(j);
            if(LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if(DFN[i]==LOW[i]){
        Bcnt++;
        do{
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
        }
        while (j!=i);
    }
}
void init(){
    memset(nod,0,sizeof(nod));
    memset(DFN,0,sizeof(DFN));
    memset(LOW,0,sizeof(LOW));
    memset(instack,0,sizeof(instack));
    memset(Stap,0,sizeof(Stap));
    memset(Belong,0,sizeof(Belong));
    memset(In,0,sizeof(In));
    memset(Out,0,sizeof(Out));
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        while(a){
            nod[i][a]=1;
            scanf("%d",&a);
        }
    }
    for(int i=1;i<=n;i++){
        if(!DFN[i])
            tarjan(i);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(nod[i][j] && Belong[i]!=Belong[j]){
                Out[Belong[i]]++;
                In[Belong[j]]++;
            }
    int t1=0,t2=0;
    for(int i=1;i<=Bcnt;i++){
        if(In[i]==0)
            t1++;
        if(Out[i]==0)
            t2++;
    }
    //cout<<t1<<" "<<t2<<endl;
    if(Bcnt==1)
        printf("1\n0\n");
    else
        printf("%d\n%d\n",t1,max(t1,t2));
    return 0;
}
