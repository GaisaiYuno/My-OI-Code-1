#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
#include<cmath>
#define maxm 10005
#define maxlog 32
using namespace std;
int n,m,qu;
struct edge {
	int from;
	int to;
	long long len;
	int next;
} E[maxm*2];
int head[maxn];
int size=0;
void add_edge(int u,int v,long long w) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
}


//int fset[maxn];
//int find(int x) {
//	if(fset[x]==x) return x;
//	else {
//		fset[x]=find(fset[x]);
//		return fset[x];
//	}
//}
//void merge(int x,int y) {
//	int fx=find(x);
//	int fy=find(y);
//	fset[fx]=fy;
//}

int cnt=0;
int mark[maxn];
int deep[maxn];
int anc[maxn][maxlog];
long long dist[maxn];
int t;
void dfs(int x,int pre) {
	mark[x]=cnt;
	anc[x][0]=pre;
	for(int i=1; i<=t; i++) {//一定要从1开始！！！！！！ 
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y==pre) continue;
		deep[y]=deep[x]+1;
		dist[y]=dist[x]+E[i].len;
		dfs(y,x);
	}
}
int lca(int x,int y) {
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=t; i>=0; i--) {
		if(deep[anc[x][i]]>=deep[y]) {
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=t; i>=0; i--) {
		if(anc[x][i]!=anc[y][i]) {
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
void ini(){
	t=log(n)/log(2)+1;
    memset(mark,0,sizeof(mark));
	memset(anc,0,sizeof(anc));
	memset(deep,0,sizeof(deep));
	memset(dist,0,sizeof(dist));
	size=0;
	cnt=0;
	memset(head,0,sizeof(head));
	memset(E,0,sizeof(E));
}
int main() {
	int u,v;
	long long k;
	while(scanf("%d %d %d",&n,&m,&qu)!=EOF) {
		ini();
		for(int i=1; i<=m; i++) {
			scanf("%d %d %I64d",&u,&v,&k);
			add_edge(u,v,k);
			add_edge(v,u,k);
		}
		for(int i=1; i<=n; i++) {
			if(mark[i]==0) {
				deep[i]=1;
				cnt++;
				dfs(i,i);
			}
		}
		for(int i=1; i<=qu; i++) {
			scanf("%d %d",&u,&v);
			if(mark[u]!=mark[v]) printf("Not connected\n");
			else {
				printf("%I64d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
			}
		}
	}

}
/*
5 3 2
1 3 2
2 4 3
5 2 3
1 4
2 5
8 6 3
1 2 10
1 3 2
3 4 5
3 5 1
6 7 3
6 8 3
2 5
1 8
6 7
*/
