### 题面

给定一棵N个节点的树，每个点有一个权值，对于M个询问(u,v,k)，你需要回答u xor lastans和v这两个节点间第K小的点权。其中lastans是上一个询问的答案，初始为0，即第一个询问的u是明文。

### 分析

第i棵主席树存储dfs序(dfn)为i的节点到根的链上序列，按dfn更新

查询用dfn[x]+dfn[y]-dfn[lca(x,y)]-dfn[fa[lca(x,y)]]（指对应的主席树相减 )

不能直接减去dfn[lca(x,y)]*2,因为lca那个点也算，要少减一次 

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
#define maxlogn 20
using namespace std;
struct node{
#ifdef DEBUG
	int l;
	int r;
#endif
	int ls;
	int rs;
	int cnt;
}tree[maxn*maxlogn];
int root[maxn];
int ptr;
void push_up(int x){
	tree[x].cnt=tree[tree[x].ls].cnt+tree[tree[x].rs].cnt;
}
void update(int &x,int last,int upos,int l,int r){
	x=++ptr;
	tree[x]=tree[last];
#ifdef DEBUG
	tree[x].l=l;
	tree[x].r=r; 
#endif 
	if(l==r){
		tree[x].cnt++;
		return;
	}
	int mid=(l+r)>>1;
	if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
	else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
	push_up(x);
} 
int query(int x,int y,int lc,int lcfa,int k,int l,int r){
	if(l==r) return l;
	int mid=(l+r)>>1;
	int lcnt=tree[tree[x].ls].cnt+tree[tree[y].ls].cnt-tree[tree[lc].ls].cnt-tree[tree[lcfa].ls].cnt;
	if(k<=lcnt) return query(tree[x].ls,tree[y].ls,tree[lc].ls,tree[lcfa].ls,k,l,mid);
	else return query(tree[x].rs,tree[y].rs,tree[lc].rs,tree[lcfa].rs,k-lcnt,mid+1,r); 
}

struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int tim;
int logn;
int dfn[maxn];
int hash_dfn[maxn];
int anc[maxn][maxlogn];
int deep[maxn];
void dfs(int x,int fa){
	dfn[x]=++tim;
	hash_dfn[tim]=x;
	anc[x][0]=fa;
	deep[x]=deep[fa]+1;
	for(int i=1;i<=logn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=logn;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=logn;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

int n,m;
int dis_cnt;
int val[maxn];
int tmp[maxn];
int main(){
	int u,v,k;
	scanf("%d %d",&n,&m);
	int lastans=0;
	logn=log2(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		tmp[i]=val[i];
	}
	sort(tmp+1,tmp+1+n);
	dis_cnt=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) val[i]=lower_bound(tmp+1,tmp+1+dis_cnt,val[i])-tmp;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u); 
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		int x=hash_dfn[i],fa=anc[x][0];
		update(root[dfn[x]],root[dfn[fa]],val[x],1,dis_cnt);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&k);
		u^=lastans;
		int lc=lca(u,v);
		int lcfa=anc[lc][0];
		lastans=tmp[query(root[dfn[u]],root[dfn[v]],root[dfn[lc]],root[dfn[lcfa]],k,1,dis_cnt)];
		printf("%d\n",lastans);
	}
} 
```

