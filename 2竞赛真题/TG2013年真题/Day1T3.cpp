#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10005
#define maxlog 32
#define INF 0x7f7f7f7f
using namespace std;
int n,m,q;
struct edge{
	int from;
	int to;
	int len;
	edge(){
		
	}
	edge(int u,int v,int w){
		from=u;
		to=v;
		len=w;
	}
	friend bool operator <(edge x,edge y){
		return x.len>y.len;
	}
};
vector<edge>G;
vector<edge>T[maxn];

int fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void kruskal(){
	int u,v,fu,fv;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(G.begin(),G.end());
	for(int i=0;i<m;i++){
		u=G[i].from;
		v=G[i].to;
		fu=find(u);
		fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			T[u].push_back(edge(u,v,G[i].len));
			T[v].push_back(edge(v,u,G[i].len));
//			printf("%d %d\n",u,v);
		}
	}
}

int deep[maxn];
int anc[maxn][maxlog];
int minv[maxn][maxlog];
void dfs(int x,int fa,int len){
	int sz;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	minv[x][0]=len;
	for(int i=1;i<=20;i++){
		minv[x][i]=min(minv[x][i-1],minv[anc[x][i-1]][i-1]);
	}
	sz=T[x].size();
	for(int i=0;i<sz;i++){
		int y=T[x][i].to;
		if(y!=fa){
			dfs(y,x,T[x][i].len);
		}
	}
}

int query(int x,int y){
	int ans=INF;
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			ans=min(ans,minv[x][i]);
			x=anc[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=20;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			ans=min(ans,minv[x][i]);
			ans=min(ans,minv[y][i]);
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	ans=min(ans,minv[x][0]);
	ans=min(ans,minv[y][0]);
	return ans;
}

int main(){
	int u,v,w;
	int ans;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		G.push_back(edge(u,v,w));
	}
	kruskal();
	memset(minv,0x7f,sizeof(minv));
	for(int i=1;i<=n;i++){
		if(!deep[i]) dfs(i,0,INF);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		if(find(u)!=find(v)) ans=-1;
		else ans=query(u,v);
		printf("%d\n",ans); 
	}
}
