#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#define maxn 100005
using namespace std;
int t,n,m;
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

int deep[maxn],anc[maxn][32],siz[maxn];
int log2n;
void dfs(int x,int fa) {
	anc[x][0]=fa;
	for(int i=1; i<=log2n; i++) {
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
	for(int i=log2n; i>=0; i--) {
		if(deep[anc[x][i]]>=deep[y]) {
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=log2n; i>=0; i--) {
		if(anc[x][i]!=anc[y][i]) {
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
int dist(int x,int y){
	return deep[x]+deep[y]-2*deep[lca(x,y)];
}
map<string,int>index;
int cnt;
void ini(){
	size=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(anc,0,sizeof(anc));
	memset(siz,0,sizeof(siz));
	cnt=0;
	index.clear();
}
string a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		ini();
		scanf("%d %d",&n,&m);
		log2n=log2(n)+1;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			if(index[a]==0) index[a]=++cnt;
			if(index[b]==0) index[b]=++cnt;
			add_edge(index[a],index[b]);
			add_edge(index[b],index[a]);
			siz[index[a]]++;
//			printf("%d %d\n",index[a],index[b]);
		}
		for(int i=1;i<=n;i++){
			if(siz[i]==0){
				deep[i]=1;
				dfs(i,0);
				break;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			int lca_id=lca(index[a],index[b]);
//			printf("%d %d %d\n",lca_id,index[a],index[b]);
//			printf("%d %d %d\n",deep[lca_id],deep[index[a]],deep[index[b]]);
			if(index[b]==lca_id) printf("%d\n",dist(index[a],lca_id));
			else if(index[a]==lca_id) printf("1\n");
			else printf("%d\n",dist(index[a],lca_id)+1);
		}
	}
}
