#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1]; 
int size=0;
int head[maxn];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int w[maxn],c[maxn];
int sz[maxn],deep[maxn],son[maxn],top[maxn],dfn[maxn],fa[maxn];
void dfs(int x,int father){
	sz[x]=1;
	son[x]=0;
	fa[x]=father;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=father){
			deep[y]=deep[x]+1;
			dfs(y,x);
			sz[x]+=sz[y];
			if(!son[x]||sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}
int cnt=0;
void dfs2(int x,int to){
	dfn[x]=++cnt;
	top[x]=to;
	if(son[x]) dfs2(son[x],to);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
}

int rt[maxn];
int node_cnt;
struct node{
	int sum;
	int maxv;
	int lson;
	int rson;
}tree[5000005];
void push_up(int pos){
	tree[pos].sum=tree[tree[pos].lson].sum+tree[tree[pos].rson].sum;
	tree[pos].maxv=max(tree[tree[pos].lson].maxv,tree[tree[pos].rson].maxv);
	
}
//动态开点线段树中不用存区间，存了可能会TLE 
void update(int &pos,int tpos,int v,int l,int r){
	if(!pos){
		pos=++node_cnt;
	}
	if(l==r){
		tree[pos].maxv=tree[pos].sum=v;
		return;
	}
	int mid=(l+r)>>1;
	if(tpos<=mid) update(tree[pos].lson,tpos,v,l,mid);
	else update(tree[pos].rson,tpos,v,mid+1,r);
	push_up(pos); 
}
int query_sum(int pos,int L,int R,int l,int r){
	if(L<=l&&R>=r){
		return tree[pos].sum;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans+=query_sum(tree[pos].lson,L,R,l,mid);
	if(R>mid) ans+=query_sum(tree[pos].rson,L,R,mid+1,r);
	return ans;
}
int query_max(int pos,int L,int R,int l,int r){
	if(L<=l&&R>=r){
		return tree[pos].maxv;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans=max(ans,query_max(tree[pos].lson,L,R,l,mid));
	if(R>mid) ans=max(ans,query_max(tree[pos].rson,L,R,mid+1,r));
	return ans;
} 
int walk(int x,int y,int color,int type){
	int tx=top[x],ty=top[y];
	int ans=0;
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		if(type==1) ans+=query_sum(rt[color],dfn[tx],dfn[x],1,n);
		else ans=max(ans,query_max(rt[color],dfn[tx],dfn[x],1,n));
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	if(type==1) ans+=query_sum(rt[color],dfn[x],dfn[y],1,n);
	else ans=max(ans,query_max(rt[color],dfn[x],dfn[y],1,n));
	return ans; 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&w[i],&c[i]);
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		update(rt[c[i]],dfn[i],w[i],1,n);
	} 
	char cmd[5];
	int x,y;
//	printf("ok");
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='C'&&cmd[1]=='C'){
			scanf("%d %d",&x,&y);
			update(rt[c[x]],dfn[x],0,1,n);//设为0,相当于删除 
			c[x]=y;
			update(rt[c[x]],dfn[x],w[x],1,n);
		}else if(cmd[0]=='C'&&cmd[1]=='W'){
			scanf("%d %d",&x,&y);
			w[x]=y;//注意要更新w[x],CC操作中用到 
			update(rt[c[x]],dfn[x],y,1,n);
		}else if(cmd[0]=='Q'&&cmd[1]=='S'){
			scanf("%d %d",&x,&y);
			printf("%d\n",walk(x,y,c[x],1));
		}else{
			scanf("%d %d",&x,&y);
			printf("%d\n",walk(x,y,c[x],2));
		}
	}
} 

