#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005
#define maxk 100005
#define maxlog 32
using namespace std;
int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int deep[maxn],anc[maxn][maxlog],sum[maxn];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
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

void chafen(int u,int v){
	sum[u]++;
	sum[v]++;
	sum[lca(u,v)]-=2;
}

void get_sum(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			get_sum(y,x);
			sum[x]+=sum[y];
		}
	}
}

struct route{
	int x;
	int y;
}a[maxk];
int main(){
//	freopen("maxflow.in","r",stdin);
//	freopen("maxflow.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		chafen(a[i].x,a[i].y);
	}
	get_sum(1,0);
	for(int i=1;i<=k;i++){
		sum[lca(a[i].x,a[i].y)]++;
	}
	int ans=0;
	int maxv=0;
	for(int i=1;i<=n;i++){
		if(sum[i]>maxv){
			maxv=sum[i];
			ans=i;
		}
	}
	printf("%d\n",maxv);
}
