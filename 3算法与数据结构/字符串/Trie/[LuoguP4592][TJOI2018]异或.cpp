#include<iostream>
#include<cstdio>
#include<cstring>
#define maxlogv 32
#define maxn 100000
using namespace std;
int n,m;
int a[maxn+5];

struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int esz=1;
int head[maxn+5];
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
} 
int deep[maxn+5],fa[maxn+5],sz[maxn+5],son[maxn+5];
int top[maxn+5],dfn[maxn+5],m_dfn[maxn+5],hash_dfn[maxn+5];
void dfs1(int x,int f){
	fa[x]=f;
	sz[x]=1;
	deep[x]=deep[f]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
} 
int tim;
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++tim;
	hash_dfn[dfn[x]]=x;
	if(son[x]) dfs2(son[x],t);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,y);
		}
	}
	m_dfn[x]=tim;
}

struct persist_trie{
	int root[maxn+5];
	int ch[10000000+5][2];
	int sz[10000000+5];
	int ptr;
	void insert(int pos,int val){
		int now=root[pos]=++ptr;
		int last=root[pos-1];
		for(int i=maxlogv-1;i>=0;i--){
			int k=(val>>i)&1;
			ch[now][k]=++ptr;
			ch[now][k^1]=ch[last][k^1];
			now=ch[now][k];
			last=ch[last][k]; 
			sz[now]=sz[last]+1;	
		}
		
	}
	int query(int l,int r,int val){
		int now=root[r];
		int last=root[l-1];
		int ans=0;
		for(int i=maxlogv-1;i>=0;i--){
			int k=(val>>i)&1;
			int cnt=sz[ch[now][k^1]]-sz[ch[last][k^1]];
			if(cnt){
				now=ch[now][k^1];
				last=ch[last][k^1];
				ans=ans<<1|1;
			}else{
				now=ch[now][k];
				last=ch[last][k];
				ans=ans<<1;
			}
		}
		return ans;
	}
}T;

int query_tree(int x,int val){
	return T.query(dfn[x],m_dfn[x],val);
}
int query_route(int x,int y,int val){
	int tx=top[x],ty=top[y],ans=0;
	while(tx!=ty){
		if(deep[tx]<deep[ty]){
			swap(tx,ty);
			swap(x,y);
		}
		ans=max(ans,T.query(dfn[tx],dfn[x],val));
		x=fa[tx];
		tx=top[x];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans=max(ans,T.query(dfn[x],dfn[y],val));
	return ans;
}

int main(){
	int cmd,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++) T.insert(i,a[hash_dfn[i]]);
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d",&u,&v);
			printf("%d\n",query_tree(u,v));
		}else{
			scanf("%d %d %d",&u,&v,&w);
			printf("%d\n",query_route(u,v,w));
		}
	}
}
