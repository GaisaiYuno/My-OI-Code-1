#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 50010
inline char gc(){
    static char buf[1<<16],*S,*T;
    if(S==T){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x*f;
}
int n,m,h[N],num=1,fa[N],dep[N],pos[N],dfn=0,top[N],sz[N],son[N],id[N];
struct edge{
    int to,next;
}data[N<<1];
struct node{
    int mn;
}tr[N<<2];
void dfs1(int x){
    sz[x]=1;son[x]=0;
    for(int i=h[x];i;i=data[i].next){
        int y=data[i].to;if(y==fa[x]) continue;
        fa[y]=x;dep[y]=dep[x]+1;id[i>>1]=y;dfs1(y);sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x,int tp){
    pos[x]=++dfn;top[x]=tp;
    if(son[x]) dfs2(son[x],tp);
    for(int i=h[x];i;i=data[i].next){
        int y=data[i].to;if(y==fa[x]||y==son[x]) continue;dfs2(y,y);
    }
}
inline void build(int p,int l,int r){
    tr[p].mn=inf;if(l==r) return;int mid=l+r>>1;
    build(p<<1,l,mid);build(p<<1|1,mid+1,r);
}
inline void pushdown(int p){
    if(tr[p].mn==inf) return;
    tr[p<<1].mn=min(tr[p<<1].mn,tr[p].mn);
    tr[p<<1|1].mn=min(tr[p<<1|1].mn,tr[p].mn);tr[p].mn=inf;
}
inline int ask(int p,int l,int r,int x){
    if(l==r) return tr[p].mn;
    int mid=l+r>>1;pushdown(p);
    if(x<=mid) return ask(p<<1,l,mid,x);
    else return ask(p<<1|1,mid+1,r,x);
}
inline void cov(int p,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y){tr[p].mn=min(tr[p].mn,val);return;}
    int mid=l+r>>1;pushdown(p);
    if(x<=mid) cov(p<<1,l,mid,x,y,val);
    if(y>mid) cov(p<<1|1,mid+1,r,x,y,val);
}
inline void docov(int x,int y,int val){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        cov(1,1,n,pos[top[x]],pos[x],val);x=fa[top[x]];
    }if(pos[x]>pos[y]) swap(x,y);if(pos[x]==pos[y]) return;
    cov(1,1,n,pos[x]+1,pos[y],val);
}
int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<n;++i){
        int x=read(),y=read();
        data[++num].to=y;data[num].next=h[x];h[x]=num;
        data[++num].to=x;data[num].next=h[y];h[y]=num;
    }dfs1(1);dfs2(1,1);build(1,1,n);
    while(m--){
        int x=read(),y=read();docov(x,y,read());
    }for(int i=1;i<n;++i){
        int x=ask(1,1,n,pos[id[i]]);if(x==inf) puts("-1");
        else printf("%d\n",x);
    }return 0;
}
