#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define N 50004
#define ls(a) (a<<1)
#define rs(a) (a<<1^1)
 
using namespace std;
inline int read(){
    int ret=0;char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while ('0'<=ch && ch<='9'){
        ret=ret*10-48+ch;
        ch=getchar();
    }
    return ret;
}
 
struct query{
    int x,y,key,id;
} q[N];
inline bool operator <(const query &a,const query &b){
    return (a.key<b.key||a.key==b.key&&((a.y<b.y)^(a.key&1)));
}
 
struct STnode{
    int len;
    int maxs,maxl,maxr;
} t[N*4];
int pos[N];
inline void PushUp(int x){
    t[x].maxs=max(t[ls(x)].maxr+t[rs(x)].maxl,max(t[ls(x)].maxs,t[rs(x)].maxs));
    t[x].maxl=t[ls(x)].maxl+(t[ls(x)].maxl==t[ls(x)].len)*t[rs(x)].maxl;
    t[x].maxr=t[rs(x)].maxr+(t[rs(x)].maxr==t[rs(x)].len)*t[ls(x)].maxr;
}
void build(int x,int l,int r){
    t[x].maxs=t[x].maxl=t[x].maxr=0;
    t[x].len=r-l+1;
    if (t[x].len==1){pos[l]=x;return;}
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1^1,mid+1,r);
}
void update(int p){
    int x=pos[p];
    t[x].maxl=t[x].maxr=(t[x].maxs^=1);
    while (x!=1) PushUp(x=x>>1);
}
int getans(){
    return t[1].maxs;
}
 
int a[N],n;
int l,r;
void move(int L,int R){
    for (;l>L;--l) update(a[l-1]);
    for (;r<R;++r) update(a[r+1]);
    for (;l<L;++l) update(a[l]);
    for (;r>R;--r) update(a[r]);
}
 
int ans[N];
 
int main(){
    n=read();int Q=read();
    for (int i=1;i<=n;++i) a[i]=read();
    for (int i=1;i<=Q;++i){
        q[i].x=read();q[i].y=read();
        q[i].key=sqrt(q[i].x);
        q[i].id=i;
    }
    sort(q+1,q+Q+1);
    l=1;r=0;
    build(1,1,n);
    for (int i=1;i<=Q;++i){
        if (q[i].x>q[i].y){ans[q[i].id]=0;continue;}
        move(q[i].x,q[i].y);
        ans[q[i].id]=getans();
    }
    for (int i=1;i<=Q;++i) printf("%d\n",ans[i]);
    return 0;
}
