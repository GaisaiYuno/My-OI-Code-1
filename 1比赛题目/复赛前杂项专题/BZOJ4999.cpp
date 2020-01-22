#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 300000
#define maxlogn 25
using namespace std;
int n,m;
int a[maxn+5],b[maxn+5];
int tmp[maxn+5];
struct oper{
	int type;
	int x;
	int y;
	int v;
}q[maxn+5]; 

struct segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
	}
	void update(int &x,int upos,int uval,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].val+=uval;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(lson(x),upos,uval,l,mid);
		else update(rson(x),upos,uval,mid+1,r);
		push_up(x);
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r){
			return tree[x].val;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(lson(x),L,R,l,mid);
		if(R>mid) ans+=query(rson(x),L,R,mid+1,r);
		return ans;
	}
}T;//对于每个值v,开一棵动态开点的线段树维护哪几个节点的值为v(下标为dfs序) 
//改权值就是在一棵线段树里删除,一棵线段树里插入 
int root[maxn+5];

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

int deep[maxn+5];
int fa[maxn+5],son[maxn+5];
int sz[maxn+5];
int top[maxn+5];
int tim=0;
int dfn[maxn+5]; 
void dfs1(int x,int f){
	deep[x]=deep[f]+1;
	fa[x]=f;
	sz[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
} 
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
void update(int x,int val){
	if(a[x]!=0) T.update(root[a[x]],dfn[x],-1,1,n);
	a[x]=val;
	T.update(root[a[x]],dfn[x],1,1,n);
}
int query(int x,int y,int val){
	int tx=top[x],ty=top[y];
	int ans=0;
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		ans+=T.query(root[val],dfn[tx],dfn[x],1,n);
		//查询当前重链上权值val的出现次数，即第val棵线段树上[dfn[tx],dfn[x]]的区间和 
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=T.query(root[val],dfn[x],dfn[y],1,n);
	return ans;
}

int main(){
	int u,v;
	char cmd[2];
	int dn=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		tmp[++dn]=b[i];
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		q[i].type=(cmd[0]=='C')?1:2;
		if(q[i].type==1){
			scanf("%d %d",&q[i].x,&q[i].v);
			tmp[++dn]=q[i].v;//离线，离散化权值 
		}else{
			scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].v);
			tmp[++dn]=q[i].v;
		}
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++){
		update(i,lower_bound(tmp+1,tmp+1+dn,b[i])-tmp);
	}
	for(int i=1;i<=m;i++){
		q[i].v=lower_bound(tmp+1,tmp+1+dn,q[i].v)-tmp;
	}
	for(int i=1;i<=m;i++){
		if(q[i].type==1) update(q[i].x,q[i].v);
		else printf("%d\n",query(q[i].x,q[i].y,q[i].v)); 
	}
}

