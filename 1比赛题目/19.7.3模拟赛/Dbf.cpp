
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
#define maxn 50000
#define maxlogn 20
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

int log2n;
int tim=0;
int dfn[maxn+5];
int id[maxn+5];
int deep[maxn+5];
long long dis[maxn+5];
int anc[maxn+5][maxlogn+1];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	dfn[x]=++tim;
	anc[x][0]=fa;
	id[dfn[x]]=x;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dis[y]=dis[x]+E[i].len;
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
inline long long dist(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}

int mark[maxn];
void add(int x){
	mark[x]=1;
}
void del(int x){
	mark[x]=0;
}

int seq[maxn];
long long cal(){
	int sz=0;
	for(int i=1;i<=n;i++){
		if(mark[id[i]]) seq[++sz]=id[i];
	}
	long long ans=0;
	for(int i=1;i<sz;i++){
		ans+=dist(seq[i],seq[i+1]);
	}
	ans+=dist(seq[sz],seq[1]);
	return ans;
}
int main(){
	char cmd[2];
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w); 
	} 
	log2n=log2(n)+1; 
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='+'){
			scanf("%d",&u);
			add(u); 
		}else if(cmd[0]=='-'){
			scanf("%d",&u);
			del(u);
		}else{
			printf("%lld\n",cal()/2);
		}
	}
}
