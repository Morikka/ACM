/*
题目：给S许多词语A每个赋许多关键词B，查询一堆词语A中共有的关键词B。
词语A丢到map中，然后每个词一个vector保存所有关键词。
枚举最后一个词语的关键词，检查该关键词是否在其他的词语中。
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <set>
const int mx = 105;
using namespace std;
vector<string> str[mx],str1;
vector<string>::iterator it,ito,itor;
set<string> words;
set<string>::iterator wor;
map<string,int> head;
string chr,c;
int t;
int gets(string s){
    if(!head.count(s))
        head[s]=++t;
    return head[s];
}
int main(){
    int n,p,q,pos;
    bool jud;

    while(~scanf("%d",&n)&&n){
        for(int i=0;i<mx;i++)
            str[i].clear();
        while(n--){
            cin>>c;
            cin.get();
            getline(cin,chr);
            pos=0;
            p=gets(c);
            for(; (pos = chr.find(' ')) != string::npos; ){
                int start = 0;
                string label = chr.substr(start, pos);
                str[p].push_back(label);
                string tmp = chr.substr(pos+1);
                chr = tmp;
            }
            str[p].push_back(chr);
        }
        scanf("%d",&n);
        cin.get();
        while(n--){
            getline(cin,chr);
            pos=0;
            str1.clear();
            words.clear();
            for(; (pos = chr.find(' ')) != string::npos; ){
                int start = 0;
                string label = chr.substr(start, pos);
                str1.push_back(label);
                string tmp = chr.substr(pos+1);
                chr = tmp;
            }
            p=gets(chr);
            for(it=str[p].begin();it!=str[p].end();it++){
               // cout<<*it<<endl;
                jud=true;
                for(itor=str1.begin();itor!=str1.end();itor++){
                    q=gets(*itor);
                    jud=false;
                    for(ito=str[q].begin();ito!=str[q].end();ito++){
                        if(*ito==*it)jud=true;
                        //cout<<*ito<<" ";
                    }
                   // cout<<endl;
                if(!jud)break;

                }
                if(jud)
                    words.insert(*it);
            }
            if(words.empty())
                printf("NO\n");
            else{
                wor=words.begin();
                cout<<*wor;
                wor++;
                for(;wor!=words.end();wor++){
                    cout<<" "<<*wor;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

