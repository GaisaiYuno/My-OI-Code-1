## [BZOJ3626] [LNOI2014]LCA(树链剖分)

### 题面

给出一棵N个点的树，要求支持Q次询问，每次询问一个点z与编号为区间[l,r]内的点分别求最近公共祖先得到的最近公共祖先深度和。N, Q≤50000


###　分析

对于一个点i，我们把i到根节点的路径全部标记+1，然后从z往上找，第一个碰到的标记不为0的节点就是lca(z,i)。而i的深度恰好就是z到根节点路径上的标记和。显然这样的标记是可以叠加的，对于区间[l,r]，我们把编号在[l,r]内的节点到根的路径都标记+1，那么答案就在z到根路径上的标记和。

但是这样直接做还是$O(n^2)$的，考虑离线。注意到标记是可减的,那么询问query(l,r,z)就相当于query(1,r,z)-query(1,l-1,z)。

那么我们分两部分维护答案，记query(1,r,z)=ansr,query(1,l-1,z)=ansl，真正的答案就是ansr-ansl.我们对于每个点，保存左端点l-1在此的询问编号，右端点同理。我们从1~n遍历每个节点i，把i到根的路径标记+1。然后看看有没有左端点在i的询问，如果有，就更新ansl，右端点同理

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 50000
#define mod 201314
using namespace std;
int n,m; 
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5]; 
int esz=0;
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}

int dfn[maxn+5];
int fa[maxn+5];
int son[maxn+5];
int sz[maxn+5];
int deep[maxn+5];
int top[maxn+5];
void dfs1(int x,int f){
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[son[x]]<sz[y]) son[x]=y;
		}
	}
}
int tim=0;
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++tim;
	if(son[x]) dfs2(son[x],t);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
}

struct segment_tree{
	struct node{
		int l;
		int r;
		long long mark;
		long long v;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void push_down(int pos){
		if(tree[pos].mark){
			tree[pos<<1].mark+=tree[pos].mark;
			tree[pos<<1|1].mark+=tree[pos].mark;
			tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
			tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len(); 
			tree[pos].mark=0;
		}
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	} 
	void update(int L,int R,long long val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark+=val;
			tree[pos].v+=val*tree[pos].len();
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
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
		return ans;
	}
}T;

void update_route(int x,int y,int val){
	int tx=top[x],ty=top[y];
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(x,y);
			swap(tx,ty);
		} 
		T.update(dfn[tx],dfn[x],val,1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	T.update(dfn[x],dfn[y],val,1);
}
long long query_route(int x,int y){
	int tx=top[x],ty=top[y];
	long long ans=0;
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(x,y);
			swap(tx,ty);
		} 
		ans+=T.query(dfn[tx],dfn[x],1);
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T.query(dfn[x],dfn[y],1);
	return ans; 
}

struct query{
	int l;
	int r;
	int z;
	int id;
	long long ansl;
	long long ansr; 
}q[maxn+5];
vector<int>lb[maxn+5];
vector<int>rb[maxn+5];
int main(){
	int p;
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		p++;
		add_edge(i,p);
		add_edge(p,i);
	}
	dfs1(1,0);
	dfs2(1,1);
	T.build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].z);
		q[i].l++;
		q[i].r++;
		q[i].z++;
		q[i].id=i;
		lb[q[i].l-1].push_back(i);
		rb[q[i].r].push_back(i);
	}
	for(int i=1;i<=n;i++){
		update_route(i,1,1);
		for(int j=0;j<lb[i].size();j++){
			int u=lb[i][j];
			q[u].ansl=query_route(q[u].z,1);
		}
		for(int j=0;j<rb[i].size();j++){
			int u=rb[i][j];
			q[u].ansr=query_route(q[u].z,1);
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld\n",(q[i].ansr-q[i].ansl)%mod);
	}
}

```

