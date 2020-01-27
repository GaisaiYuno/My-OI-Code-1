#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define maxn 300005
#define maxlog 21
using namespace std;
int n,q;
struct edge {
	int from;
	int to;
	int next;
} E[maxn*2];
int head[maxn];
int size=0;
void add_edge(int u,int v) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
} 

int cnt=0;
int pos[maxn*2];
int anc[maxn][maxlog];
int deep[maxn];
int st_min[maxn][maxlog],st_max[maxn][maxlog];
void dfs(int x,int fa) {
	pos[x]=++cnt;
	anc[x][0]=fa;
	for(int i=1; i<=20; i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			deep[y]=deep[x]+1;
			dfs(y,x);
		}
	}
}
int lca(int x,int y) {
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20; i>=0; i--) {
		if(deep[anc[x][i]]>=deep[y]) {
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20; i>=0; i--) {
		if(anc[x][i]!=anc[y][i]) {
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
void st_init(){
	for(int i=1;i<=n;i++){
		st_max[i][0]=st_min[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			if(pos[st_min[i][j-1]]<pos[st_min[i+(1<<(j-1))][j-1]]) st_min[i][j]=st_min[i][j-1];
			else st_min[i][j]=st_min[i+(1<<(j-1))][j-1];
			if(pos[st_max[i][j-1]]>=pos[st_max[i+(1<<(j-1))][j-1]]) st_max[i][j]=st_max[i][j-1];
			else st_max[i][j]=st_max[i+(1<<(j-1))][j-1];
		}
	}
}
int st_query_min(int l,int r){
	int k=log2(r-l+1);
	if(pos[st_min[l][k]]<pos[st_min[r-(1<<k)+1][k]]) return st_min[l][k];
	else return st_min[r-(1<<k)+1][k];
}
int st_query_max(int l,int r){
	int k=log2(r-l+1);
	if(pos[st_max[l][k]]>=pos[st_max[r-(1<<k)+1][k]]) return st_max[l][k];
	else return st_max[r-(1<<k)+1][k];
}
int main(){
	int u,v,l,r; 
	while(scanf("%d",&n)!=EOF){
		size=0;
		memset(E,0,sizeof(E));
		memset(head,0,sizeof(head));
		memset(deep,0,sizeof(deep));
		memset(anc,0,sizeof(anc));
		cnt=0;
		memset(pos,0,sizeof(pos));
		memset(st_max,0,sizeof(st_max));
		memset(st_min,0,sizeof(st_min));
		for(int i=1;i<=n-1;i++){
			scanf("%d %d",&u,&v); 
			add_edge(u,v);
			add_edge(v,u);
		}
		deep[1]=1;
		dfs(1,0);
//		printf("ok\n"); 
//		for(int i=1;i<=n;i++) printf("%d\n",pos[i]);
		st_init();
		scanf("%d",&q);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&l,&r);
			int t1=st_query_max(l,r);
			int t2=st_query_min(l,r);
			printf("%d\n",lca(t1,t2)); 
		} 
	}
}
