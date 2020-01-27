#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define maxlog 32
#define maxn 400005
#define INF 0x7fffffff
using namespace std;
int n,k;
struct edge {
	int from;
	int to;
	int next;
	int len;
} E[maxn*2];
int sz=1;
int head[maxn];
void add_edge(int u,int v,int w) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

namespace k_1 {
	struct node {
		int x;
		int t;
		node() {

		}
		node(int u,int dis) {
			x=u;
			t=dis;
		}
	};
	int vis[maxn];
	node bfs(int s) {
		node now,ans;
		queue<node>q;
		q.push(node(s,0));
		memset(vis,0,sizeof(vis));
		ans.t=-INF;
		while(!q.empty()) {
			now=q.front();
			q.pop();
			int x=now.x;
			vis[x]=1;
			if(now.t>ans.t) {
				ans.t=now.t;
				ans.x=now.x;
			}
			for(int i=head[x]; i; i=E[i].next) {
				int y=E[i].to;
				if(!vis[y]) {
					q.push(node(y,now.t+1));
				}
			}
		}
		return ans;
	}

	void solve() {
		node p=bfs(1);
		node q=bfs(p.x);
		printf("%d\n",2*(n-1)-q.t+1);
	}
}

namespace k_2 {
	int log2n;
	int mark[maxn];
	int d[maxn];
	int len=0;
	void dp(int x,int fa){
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(y!=fa){
				dp(y,x);
				len=max(len,d[x]+d[y]+E[i].len);
				d[x]=max(d[x],d[y]+E[i].len);
			}
		}
	}
	
	int anc[maxn][maxlog];
	int deep[maxn];
	void dfs1(int x,int fa) {
		deep[x]=deep[fa]+1;
		anc[x][0]=fa;
		for(int i=1; i<=log2n; i++) {
			anc[x][i]=anc[anc[x][i-1]][i-1];
		}
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(y!=fa) {
				dfs1(y,x);
			}
		}
	}

	void dfs2(int x,int fa) {
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(y!=fa) {
				dfs2(y,x);
				mark[x]+=mark[y];
			}
		}
	}

	int lca(int x,int y) {
		if(deep[x]<deep[y]) swap(x,y);
		for(int i=log2n; i>=0; i--) {
			if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
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

	void solve() {
		int u,v;
		int ans=2*(n-1);
		len=0;
		dp(1,0);
		ans=ans-len+1;

		memset(mark,0,sizeof(mark));
		mark[p.x]++;
		mark[q.x]++;
		mark[lca(p.x,q.x)]-=2;
		dfs2(1,0);

		memset(head,0,sizeof(head));
		memset(E,0,sizeof(E));
		sz=1;
		for(int i=2; i<=n; i++) {
			add_edge(i,anc[i][0],mark[i]==1?-1:1);
			add_edge(anc[i][0],i,mark[i]==1?-1:1);
		}

		len=0;
		dp(1,0);
		ans=ans-len+1;
		printf("%d\n",ans);
	}
}
int main() {
	int u,v;
	scanf("%d %d",&n,&k);
	sz=1;
	for(int i=1; i<n; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	if(k==1) k_1::solve();
	else k_2::solve();
}
