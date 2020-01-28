#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
#define mod 1000000007
using namespace std;
int id,n,q;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn<<1];
int size=0;
int head[maxn];
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
}
/*
3
5 3
1 3
1 4
2 2
2 1
2 7
3 3
4 2
*/
int top[maxn];
int dfn[maxn];
int deep[maxn];
int son[maxn]; 
int fa[maxn]; 
int sz[maxn];
int anc[maxn][32];
void dfs(int x,int father){
    deep[x]=deep[father]+1;
    son[x]=0;
    fa[x]=father;
    sz[x]=1;
    anc[x][0]=father;
	for(int i=head[x];i;i=E[i].next){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=father){
            dfs(y,x);
            sz[x]+=sz[y];
            if(sz[y]>sz[son[x]]||son[x]==0) son[x]=y;
        }	
    }
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
int cnt=0;
void dfs2(int x,int from){
    dfn[x]=++cnt;
    top[x]=from;
    if(son[x]) dfs2(son[x],from);
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(y!=fa[x]&&y!=son[x]){
            dfs2(y,y);
        }
    }
}

struct node {
    int l;
    int r;
    long long mark;
    long long v;
    int len(){
        return r-l+1;
    }
} tree[maxn<<2];
void push_up(int pos) {
    tree[pos].v=(tree[pos<<1].v+tree[pos<<1|1].v)%mod;
}
void build(int l,int r,int pos) {
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].v=tree[pos].mark=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
}
void push_down(int pos){
    if(tree[pos].mark){
        tree[pos<<1].mark+=tree[pos].mark;
        tree[pos<<1].mark%=mod;
        tree[pos<<1|1].mark+=tree[pos].mark;
        tree[pos<<1|1].mark%=mod;
        tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
        tree[pos<<1].v%=mod;
        tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
        tree[pos<<1|1].v%=mod;
        tree[pos].mark=0; 
    }
}
void update(int L,int R,int v,int pos){
    if(L<=tree[pos].l&&R>=tree[pos].r){
        tree[pos].v+=(long long)v*tree[pos].len();
        tree[pos].v%=mod;
        tree[pos].mark+=v;
        tree[pos].mark%=mod;
        return;
    }
    push_down(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(L<=mid) update(L,R,v,pos<<1);
    if(R>mid) update(L,R,v,pos<<1|1);
    push_up(pos);
}
long long query(int L,int R,int pos){
    if(L<=tree[pos].l&&R>=tree[pos].r){
        return tree[pos].v;
    }
    push_down(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=0; 
    if(L<=mid) ans+=query(L,R,pos<<1);
    if(R>mid) ans+=query(L,R,pos<<1|1);
    return ans%mod;
}

long long val[maxn];
long long get_sum(int x,int y){
    long long ans=0;
    int tx=top[x],ty=top[y];
    while(tx!=ty){
        if(deep[tx]<deep[ty]){
            swap(tx,ty);
            swap(x,y);
        }
        ans+=query(dfn[tx],dfn[x],1);
        ans%=mod;
        x=fa[tx];
        tx=top[x];
    }
    if(deep[x]>deep[y]) swap(x,y);
    ans+=query(dfn[x],dfn[y],1);
    ans%=mod;
    return ans;
}

long long get_route(int x,int y){
	int l=lca(x,y);
//	if(x==2&&y==4){
//		printf("debug %d\n",l);
//	}
//	l=lca(x,y);
	long long ans=get_sum(x,y);
	if(l!=1) ans-=val[l];
	if(ans<0) ans+=mod;
	return ans%mod;
}
long long answer(){
	long long ans=0;
	long long t=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			t=get_route(i,j);
//			printf("%d->%d=%d\n",i,j,t);
			ans+=t*t%mod;
			ans%=mod;
			printf("%lld\n",ans);
		}
	}
	puts("mhy");
	return ans%mod;
}
int main(){
	freopen("revive.in","r",stdin);
	freopen("revive.out","w",stdout);
	int f,w,u;
	scanf("%d",&id);
	scanf("%d %d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d %d",&f,&w);
		add_edge(i,f,w);
		add_edge(f,i,w);
		val[i]=w;
	}
//	printf("ok\n");
	deep[1]=1;
	dfs(1,0);
//	printf("ok\n");
	dfs2(1,1);
//	printf("ok\n");
	build(1,n,1);
//	printf("ok\n");
	for(int i=1;i<=n;i++){
		update(dfn[i],dfn[i],val[i],1);
	}
	printf("%lld\n",answer());
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&w);
		update(dfn[u],dfn[u],w,1);
		val[u]+=(long long )w;
		printf("%lld\n",answer());
	}
}
/*

*/
 
  
  
