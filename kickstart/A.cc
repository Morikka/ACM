#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int num[10050];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("t.out","w",stdout);
    int t,n;
    cin>>t;
    for(int Case = 1; Case<=t;Case++){
        cin>>n;
        int l=1,r=n,a1 = 0,a2 = n,tmp;
        for(int i=0;i<n;i++)
            cin>>num[i];
        bool jud = false;
        while(l!=r-1 && !jud){
            tmp = (a1+a2-1)/2;
            // cout<<a1<<" "<<a2<<" "<<tmp<<" "<<num[tmp]<<endl;
            if(num[tmp]==l){
                l++;
                a1+=1;
            }else if(num[tmp]==r){
                r--;
                a1+=1;
            }else{
                jud = true;
            }
        }
        cout<<"Case #"<<Case<<": ";
        if(jud)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}








