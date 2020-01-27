#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 50005
#define maxlog 32
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
int log2n;
int w[maxn],deep[maxn];
int anc[maxn][maxlog],maxv[maxn][maxlog],minv[maxn][maxlog],up[maxn][maxlog],down[maxn][maxlog];
void dfs(int x,int fa){
	anc[x][0]=fa;
	maxv[x][0]=max(w[x],w[fa]);
	minv[x][0]=min(w[x],w[fa]);
	up[x][0]=max(0,w[fa]-w[x]);
	down[x][0]=max(0,w[x]-w[fa]);
	deep[x]=deep[fa]+1;
	for(int i=1; i<=log2n; i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
		maxv[x][i]=max(maxv[x][i-1],maxv[anc[x][i-1]][i-1]);
		minv[x][i]=min(minv[x][i-1],minv[anc[x][i-1]][i-1]);
	    up[x][i]=max(up[x][i-1],up[anc[x][i-1]][i-1]);
	    up[x][i]=max(up[x][i],maxv[anc[x][i-1]][i-1]-minv[x][i-1]);
	    down[x][i]=max(down[x][i-1],down[anc[x][i-1]][i-1]);
	    down[x][i]=max(down[x][i],maxv[x][i-1]-minv[anc[x][i-1]][i-1]);
	}
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
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
void sell(int x,int y,int is_up,int &ans,int &tmp){
	tmp=w[x];
	int d=deep[x]-deep[y];
	for(int i=log2n;i>=0;i--){
		if(d>>i&1){
			if(is_up){
				ans=max(ans,maxv[x][i]-tmp);
				tmp=min(tmp,minv[x][i]);
				ans=max(ans,up[x][i]);
			}else{
				ans=max(ans,tmp-minv[x][i]);
				tmp=max(tmp,maxv[x][i]);
				ans=max(ans,down[x][i]);
			}
			x=anc[x][i];
		}
	}
}
int get_ans(int x,int y){
	int l=lca(x,y);
	int ans=0;
	int tmpx,tmpy;
	sell(x,l,1,ans,tmpx);
	sell(y,l,0,ans,tmpy);
	return max(ans,tmpy-tmpx);
}
void ini(){
	log2n=log2(n)+1;
	size=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	memset(w,0,sizeof(w)); 
	memset(maxv,0,sizeof(maxv));
	memset(minv,0,sizeof(minv));
	memset(up,0,sizeof(up));
	memset(down,0,sizeof(down));
	memset(deep,0,sizeof(deep));
	memset(anc,0,sizeof(anc));
}
int main(){
	while(scanf("%d",&n)!=EOF){
		ini(); 
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		int u,v;
		for(int i=1;i<=n-1;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,0);
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d %d",&u,&v);
			printf("%d\n",get_ans(u,v));
		}
	}
}
