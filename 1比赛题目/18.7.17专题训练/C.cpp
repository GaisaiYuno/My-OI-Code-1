#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 50005 
#define maxlog 32
using namespace std;
int n;
struct edge {
	int from;
	int to;
	int len;
	int next;
} E[maxn*2];
int head[maxn];
int size=0;
void add_edge(int u,int v,int w) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
}

int deep[maxn],dist[maxn];
int anc[maxn][maxlog];
int t;
void ini(){
	size=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(dist,0,sizeof(dist));
	memset(anc,0,sizeof(anc));
}
void dfs(int x,int fa) {
	anc[x][0]=fa;
	for(int i=1; i<=t; i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			deep[y]=deep[x]+1;
			dist[y]=dist[x]+E[i].len;
			dfs(y,x);
		}
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
int get_dis(int x,int y) {
	return dist[x]+dist[y]-2*dist[lca(x,y)];
}
int q;
int main() {
	int a,b,l,x,y,z;
	int cnt=0;
	while(scanf("%d",&n)!=EOF) {
		cnt++;
		if(cnt!=1) printf("\n\n");
		ini();
		t=log2(n)+1;
		for(int i=1; i<=n-1; i++) {
			scanf("%d %d %d",&a,&b,&l);
			add_edge(a+1,b+1,l);
			add_edge(b+1,a+1,l);
		}
		dfs(1,0); 
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d %d %d",&x,&y,&z);
			x++;
			y++;
			z++;
			printf("%d",(get_dis(x,y)+get_dis(y,z)+get_dis(x,z))/2);
			if(i!=q) printf("\n");
		}
		
	}

}
