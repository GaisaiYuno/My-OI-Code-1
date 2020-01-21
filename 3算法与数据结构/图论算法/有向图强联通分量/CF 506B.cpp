#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#define maxn 200005
#define maxm 100005
using namespace std;
int n,m;
int cost[maxn];
struct edge {
	int from;
	int to;
	int next;
} E[maxm];
int head[maxn];
int sz=0;
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

stack<int>s;
int ins[maxn];
int dfn[maxn];
int low[maxn];
int id[maxn];
int cntv[maxn];
int num=0;
int scc_cnt=0;
void tarjan(int x) {
	ins[x]=1;
	s.push(x);
	low[x]=dfn[x]=++num;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(ins[y]) {
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]) {
		scc_cnt++;
		int y;
		do {
			y=s.top();
			ins[y]=0;
			s.pop();
			id[y]=scc_cnt;
			cntv[scc_cnt]++;
		} while(y!=x);
	}
}
int mark[maxn];
int fa[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main() {
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v);
	}

	for(int i=1; i<=n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1; i<=scc_cnt; i++) {
		if(cntv[i]!=1) mark[i]=1;
	}
	for(int i=1; i<=scc_cnt; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		u=E[i].from;
		v=E[i].to;
		int p=find(id[u]);
		int q=find(id[v]);
		if(p!=q) {
			fa[q]=p;
			cntv[p]+=cntv[q];
			mark[p]|=mark[q];
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(fa[i]==i) {
			if(mark[i]) ans+=cntv[i];
			else ans+=cntv[i]-1;
		}
	}
	printf("%d\n",ans);
}
