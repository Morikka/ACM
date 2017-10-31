#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int,int> p;
map<int,int> q;
map<int,int>::iterator it;
int main() {
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int n;
    int s;
    cin >> n >> s;

    for(int a0 = 0; a0 < s; a0++){
        int l;
        int r;
        cin >> l >> r;
        long long res;
        res = (r+l)*(r-l+1)/2;
        int l1 = l-1;
        int tmp;
        it = q.find(l1);
        tmp = l1;
        while(it!=q.end()){
          tmp = it->second;
          q.erase(it);
          it = p.find(tmp);
          p.erase(it);
          tmp--;
          it = q.find(tmp);
        }
        l1 = tmp;
        if(l1>=0) 
          res += l1;
        else
          l1 = 0;
        int r1 = r+1;
        tmp = r1;
        it = p.find(r1);
        while(it!=p.end()){
          tmp = it->second;
          p.erase(it);
          it = q.find(tmp);
          q.erase(it);
          tmp++;
          it = p.find(tmp);
        }
        r1 = tmp;
        if(r1<n)
          res += r1;
        else
          r1 = n;
     q[r1] = l1;
     p[l1] = r1;
      cout<<res<<endl;
    }
    return 0;
}
