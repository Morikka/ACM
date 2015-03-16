struct NODE{
    int cnt;
    NODE *next[MAX_N],*fail;
    NODE(){
        cnt=0;
        fail=NULL;
        memset(next,0,sizeof(next));
    }
}*head;
void Build_trie(char *s,NODE *head){
    int len = strlen(s);
    for(int i=0;i<len;i++){
        int k = s[i]-'a';
        if(head->next[k]==NULL)
            head->next[k] = new NODE();
        head = head->next[k];
    }
    head->cnt++;
}
queue<NODE*> q;
void Build_fail(NODE *head){
    head->fail=NULL;
    q.push(head);
    while(!q.empty()){
        NODE *now = q.front();
        q.pop();
        for(int i=0;i<MAX_N;i++)//¶þÊ®Áù¸ö×ÖÄ¸
            if(now->next[i]){
                NODE *p = now->fail;
            while(p){
                if(p->next[i]){
                    now->next[i]->fail = p->next[i];
                    break;
                }
                p=p->fail;
            }
            if(p==NULL)
                now->next[i]->fail = head;
            q.push(now->next[i]);
            }
    }
}
bool AC_find(NODE *head, char *s){
    int len = strlen(s),sum=0;
    NODE* p = head;
    for(int i=0;i<len;i++){
        int k = s[i]-'a';
        while(p->next[k]==NULL&&p!=head)
            p=p->fail;
        p = p->next[k]==NULL ? head : p->next[k];

    NODE *tmp = p;
    while(tmp!=head&&tmp->cnt != -1){
        sum+=tmp->cnt;
        tmp->cnt = -1;
        tmp=tmp->fail;
    }
    }
    return sum>0;
}