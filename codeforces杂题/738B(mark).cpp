//若u能控制v，则u到v的路径上所有点都能控制v,考虑差分
//dist[v]-dist[u]<=a[v]
//对于每个v倍增求出离他最远的u
//然后差分即可 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
#define maxlog 32
using namespace std;
int n;
long long a[maxn];
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<2];
int ptr=0;
int head[maxn];
void add_edge(int u,int v,int w){
	ptr++;
	E[ptr].from=u;
	E[ptr].to=v;
	E[ptr].len=w;
	E[ptr].next=head[u];
	head[u]=ptr;
}

int anc[maxn][maxlog];
long long dis[maxn];
int sum[maxn]; 
void dfs1(int x,int fa){
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	int u=x;
	for(int i=20;i>=0;i--){
		if(dis[x]-dis[anc[u][i]]<=a[x]&&u>1){
			u=anc[u][i];
		}
	}
//	printf("%d %d\n",u,x);
	u=max(u,1);
	sum[anc[u][0]]--;
	sum[anc[x][0]]++;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dis[y]=dis[x]+E[i].len;
			dfs1(y,x);
		}
	}
} 

void dfs2(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
			sum[x]+=sum[y];
		}
	}
}
int main(){
	int v,w;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		scanf("%d %d",&v,&w);
		add_edge(i,v,w);
		add_edge(v,i,w);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%d ",sum[i]);
	} 
} 
