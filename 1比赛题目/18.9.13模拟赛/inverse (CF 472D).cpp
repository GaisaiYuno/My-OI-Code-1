#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxlog 32 
#define maxn 2005
using namespace std;
int n;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int a[maxn][maxn];
struct edge{
	int from;
	int to;
	int next;
	int len;
	edge(){
		
	}
	edge(int u,int v,int w,int h){
		from=u;
		to=v;
		next=h;
		len=w;
	}
	friend bool operator <(edge a,edge b){
		return a.len<b.len;
	} 
};
edge G[maxn*maxn];
edge T[maxn<<1];
int head_g[maxn];
int head_t[maxn];
int sz_g=0;
int sz_t=0;
void add_edge(edge *E,int *head,int &sz,int u,int v,int w){
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	head[u]=sz;
}

int fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

long long kruskal(){
	long long ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(G+1,G+1+sz_g);
	int fu,fv,u,v;
	for(int i=1;i<=sz_g;i++){
		u=G[i].from;
		v=G[i].to;
		fu=find(u);
		fv=find(v);
		if(fu!=fv){
//			printf("%d %d\n",u,v);
			fa[fu]=fv;
			add_edge(T,head_t,sz_t,u,v,G[i].len);
			add_edge(T,head_t,sz_t,v,u,G[i].len);
			ans+=G[i].len;
		}
	}
	return ans;
}

int deep[maxn];
long long dist[maxn];
int anc[maxn][maxlog]; 
int log2n;
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head_t[x];i;i=T[i].next){
		int y=T[i].to;
		if(y!=fa){
			dist[y]=dist[x]+T[i].len;
			dfs(y,x);
		}
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	} 
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

long long get_dist(int x,int y){
	return dist[x]+dist[y]-2*dist[lca(x,y)];
}

int is_valid_graph(){
	for(int i=1;i<=n;i++){
		if(a[i][i]!=0) return 0;
		for(int j=1;j<=n;j++){
			if(a[i][j]!=a[j][i]) return 0;
		}
	}
	return 1;
} 

int is_same_dist(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<j) add_edge(G,head_g,sz_g,i,j,a[i][j]);
		}
	}
	if(kruskal()==0&&n!=1) return 0;
	log2n=log2(n)+1;
	dfs(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i][j]!=get_dist(i,j)) return 0;
		}
	}
	return 1;
}
int main(){
	n=qread();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=qread();
		}
	}
	if(is_valid_graph()){
		if(is_same_dist()) printf("YES\n");
		else printf("NO\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
