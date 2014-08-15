////为同时有set和add

#define m ((l+r)>>1)
#define lo o<<1
#define ro o<<1|1
#define lc lo,l,m
#define rc ro,m+1,r

int node[mx<<2],sumv[mx<<2],minv[mx<<2],maxv[mx<<2],setv[mx<<2],addv[mx<<2];
int ql,qr;
void maintain(int o,int l,int r){
sumv[o]=minv[o]=maxv[o]=0;
if(l<r){
sumv[o]=sumv[lo]+sumv[ro];
minv[o]=min(sumv[lo],sumv[ro]);
maxv[o]=max(...);
}
sumv[o]+=addv[o]*(r-l+1);
minv[o]+=addv[o];
maxv[o]+=addv[o];
}
void pushdown(int o){
if(~setv[o])//memset set -1
{
setv[lc]=setv[rc]=setv[o];
setv[o]=-1;////addv[lc]=addv[rc]=0;
}////if(addv[o]{
////addv[lc]+=addv[o],addv[rc]+=addv[o];
////addv[o]=0;}
})
}
void U(int o=1,int l=1,int r=n){
if(ql<l&&r<=qr){
addv[o]+=val;//set[o]=v;
return;
}
//pushdown(o);
if(ql<=m)U(lc);
//else maintain(lc);
if(qr>m)U(rc);
//else maintain(rc);
maintain(o,l,r);
}
int _min=inf,_max=-inf,_sum=0;
void Q(int o=1,int l=1,int r=n;int add){
//if(~setv[o]){
_sum+=setv[o]*(min(r,qr)-max(l,ql)+1);
_min=min(_min,setv[o]);
_max=...
return;
}
if(ql<=l&&r<=qr){
_sum+=sumv[o]+add*(r-l+1)//_sum+=sumv[o];
_min=min(_min,minv[o]+add);//_min=min(_min,minv[o]);
_max=(..);
return;
}
if(ql<=m)Q(lc,add+addv[o]);
if(qr>m)Q(rc,add+addv[o]);
}