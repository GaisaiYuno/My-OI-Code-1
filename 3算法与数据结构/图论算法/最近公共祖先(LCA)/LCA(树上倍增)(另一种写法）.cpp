#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
#define maxm 10005
#define maxlog 32
using namespace std;
int n,m,q;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm*2];
int head[maxn];
int size=0;
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size; 
}
int vis[maxn];
int deep[maxn];
int anc[maxn][maxlog];
long long dist[maxn];
void dfs(int x,int pre){
	anc[x][0]=pre;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	vis[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			deep[y]=deep[x]+1;
			dist[y]=dist[x]+E[i].len;
			dfs(y,x);
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
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	char no_use;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %c",&u,&v,&w,&no_use);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0); 
	scanf("%d",&q);
    for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		printf("%I64d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
    }
} 
/*
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6
1 4
2 6
*/ 
