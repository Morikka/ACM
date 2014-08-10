int N,K,X[MAX_N],A[MAX_K];
int grundy[max_x];
void solve(){
grundy[0]=0;
int max_x=*max_element(X,X+N);//返回数组x中的最大值[貌似也可以不写直接init到最大值
for(int j=1;j<=max_x;j++){
set<int> s;
for(int i=0;i<K;i++)//A为合法操作
    if(A[i]<=j)s.insert(grundy[j-A[i]]);
}
int g=0;
while(s.count(g)!=0)g++;
grundy[j]=g;
}
}
