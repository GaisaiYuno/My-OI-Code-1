#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int maxl[maxn+5];
int son[maxn+5];
void dfs1(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs1(y,x);
			if(maxl[y]>maxl[son[x]]) son[x]=y;
		}
	}
	maxl[x]=maxl[son[x]]+1;
}

ll ans=0;
ll ini[maxn*4+5];
ll *id=ini; 
ll *f[maxn+5],*g[maxn*2+5];
void dfs2(int x,int fa){
	if(son[x]){
		f[son[x]]=f[x]+1;
		g[son[x]]=g[x]-1;
		dfs2(son[x],x);
	}
	f[x][0]=1;
	ans+=g[x][0];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&y!=son[x]){
			f[y]=id;
			id+=maxl[y]*2;
			g[y]=id;
			id+=maxl[y]*2;
			dfs2(y,x);
			for(int j=0;j<maxl[y];j++){
				if(j>0) ans+=f[x][j-1]*g[y][j];
				ans+=g[x][j+1]*f[y][j];
			} 
			for(int j=0;j<maxl[y];j++){
				g[x][j+1]+=f[x][j+1]*f[y][j];
				if(j>0) g[x][j-1]+=g[y][j];
				f[x][j+1]+=f[y][j];
			}
		}
	}
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	f[1]=id;
	id+=maxl[1]*2;
	g[1]=id;
	id+=maxl[1]*2;
	dfs2(1,0);
	printf("%lld\n",ans);
}

