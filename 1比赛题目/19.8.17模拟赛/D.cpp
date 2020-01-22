#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
#include<cmath>
#include<vector>
#define maxe 20000000
#define maxn 200000
#define maxm 200000
#define maxlogn 20 
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
int t,n,m,k;
struct input{
	int a;
	int b;
	int c;
	int d;
}p[maxn+5];
vector<int>in[maxn+5];
vector<int>out[maxn+5];

struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxe+5];
int sz=0;
int head[maxm+5];
int c[maxm+5];
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

vector<int>T[maxn+5];
int log2n;
int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	deep[x]=deep[fa]+1;
	for(int y : T[x]){
		if(y!=fa){
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
int lcp(int p,int q){
	return deep[lca(p,q)]-1;
} 


struct node{
	int id;
	ll dist;
	node(){
		
	}
	node(int _id,ll _dist){
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q){
		return p.dist>q.dist;
	}
};
priority_queue<node>q;
ll dist[maxm+5];
bool vis[maxn+5];
void dijkstra(int s){
	while(!q.empty()) q.pop();
	for(int i=0;i<=m;i++) dist[i]=INF;
	for(int i=0;i<=m;i++) vis[i]=0;
	dist[s]=0;
	q.push(node(s,c[s]));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len+c[y]){
				dist[y]=dist[x]+E[i].len+c[y];
				q.push(node(y,dist[y]));
			}
		}
	}
}

void ini(){
	sz=0;
	for(int i=0;i<=m;i++) head[i]=0;
	for(int i=1;i<=k;i++) T[i].clear();
	for(int i=1;i<=n;i++){
		in[i].clear();
		out[i].clear();
	}
	log2n=log2(k)+1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=log2n;j++) anc[i][j]=0;
	}
	
}
int main(){
	int u,v,w;
	qread(t);
	while(t--){
		qread(n);
		qread(m);
		qread(k);
		ini();
		for(int i=1;i<=m;i++){
			qread(p[i].a);
			qread(p[i].b);
			qread(p[i].c);
			qread(p[i].d);
//			scanf("%d %d %d %d",&p[i].a,&p[i].b,&p[i].c,&p[i].d);
			in[p[i].b].push_back(i);
			out[p[i].a].push_back(i); 
			c[i]=p[i].c;
		}
		
		for(int i=1;i<k;i++){
			qread(u);
			qread(v);
			qread(w);
			T[u].push_back(v);
			T[v].push_back(u);
		}
		dfs(1,0);
		
		for(int i=1;i<=n;i++){
			for(int u : in[i]){
				for(int v : out[i]){
					add_edge(u,v,lcp(p[u].d,p[v].d));
				}
			}
		}
		
		int s=0;
		c[0]=0;
		for(int u : out[1] ) add_edge(s,u,0);
		dijkstra(s);
		
		for(int i=2;i<=n;i++){
			ll ans=INF;
			for(int u : in[i]){
				ans=min(ans,dist[u]);
			}
			printf("%lld\n",ans);
		}
	}
	
	
}
