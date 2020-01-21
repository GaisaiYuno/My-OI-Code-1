//https://www.luogu.org/problemnew/show/P3320
#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
#define INF 0x3f3f3f3f
#define maxn 100005
#define maxlogn 20
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}
int logn;
int cnt=0;
int dfn[maxn];
int hash_dfn[maxn];
int anc[maxn][maxlogn];
int deep[maxn];
long long dist[maxn];
void dfs(int x,int fa){
	dfn[x]=++cnt;
	hash_dfn[dfn[x]]=x;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=logn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dist[y]=dist[x]+E[i].len;
			dfs(y,x);
		}
	} 
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=logn;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	} 
	if(x==y) return x;
	for(int i=logn;i>=0;i--){
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

set<int>seq; 
long long sum=0,ans;
int main(){
	int u,v,w,x;
	scanf("%d %d",&n,&m);
	logn=log2(n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0);
	seq.insert(INF);
	seq.insert(-INF);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(!seq.count(dfn[x])){
			int l=*(--seq.lower_bound(dfn[x]));
			int r=*seq.upper_bound(dfn[x]);
			if(l!=-INF) sum+=get_dist(hash_dfn[l],x);
			if(r!=INF) sum+=get_dist(hash_dfn[r],x);
			if(l!=-INF&&r!=INF) sum-=get_dist(hash_dfn[l],hash_dfn[r]);
			seq.insert(dfn[x]);
		}else{
			int l=*(--seq.lower_bound(dfn[x]));
			int r=*seq.upper_bound(dfn[x]);
			if(l!=-INF) sum-=get_dist(hash_dfn[l],x);
			if(r!=INF) sum-=get_dist(hash_dfn[r],x);
			if(l!=-INF&&r!=INF) sum+=get_dist(hash_dfn[l],hash_dfn[r]);
			seq.erase(seq.lower_bound(dfn[x]));
		}
		ans=sum;
		if(seq.size()-2>=2) ans+=get_dist(hash_dfn[*(++seq.lower_bound(-INF))],hash_dfn[*(--seq.lower_bound(INF))]);
		printf("%lld\n",ans);
	}
}

