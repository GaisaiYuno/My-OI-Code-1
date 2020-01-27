#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#define maxn 10005
#define maxm 200005
#define INF 0x3f3f3f3f
using namespace std;
int n,m,ss,tt;
struct edge {
	int from;
	int to;
	int next;
	int vol;
	int rest;
} E[maxm<<1];
int sz=1;
int head[maxn];
void add_edge(int u,int v,int w) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].vol=w;
	E[sz].rest=w;
	E[sz].next=head[u];
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].vol=0;
	E[sz].rest=0;
	E[sz].next=head[v];
	head[v]=sz;
}

int deep[maxn];
bool bfs(int s,int t) {
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(E[i].rest) {
				if(!deep[y]) {
					deep[y]=deep[x]+1;
					q.push(y);
				}
			}
		}
	}
	return deep[t]!=0;
}
int dfs(int x,int t,int minf) {
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(E[i].rest&&deep[y]==deep[x]+1) {
			k=dfs(y,t,min(rest,E[i].rest));
			rest-=k;
			E[i].rest-=k;
			E[i^1].rest+=k;
			if(k==0) deep[y]=0;
			if(rest==0) break;
		}
	}
	return minf-rest;
}

int dinic(int s,int t) {
	int ans=0,now;
	while(bfs(s,t)) {
		while(now=dfs(s,t,INF)) ans+=now;
	}
	return ans;
}

int dfn[maxn],low[maxn],id[maxn],ins[maxn];
stack<int>s;
int tim;
int cnt;
void tarjan(int x) {
	s.push(x);
	ins[x]=1;
	low[x]=dfn[x]=++tim;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(E[i].rest>0) {//残量网络上的反向边也要考虑
		 
			if(!dfn[y]) {
				tarjan(y);
				low[x]=min(low[x],low[y]);
			} else if(ins[y]) {
				low[x]=min(low[x],dfn[y]);
			}
		}
	}
	if(dfn[x]==low[x]) {
		cnt++;
		int y;
		do {
			y=s.top();
			s.pop();
			ins[y]=0;
			id[y]=cnt;
		} while(y!=x);
	}
}

int main() {
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&ss,&tt);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	dinic(ss,tt);
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i=2; i<=sz; i+=2) {
		u=E[i].from;
		v=E[i].to;
		if(E[i].rest==0) {
			if(id[u]!=id[v]) printf("1 ");
			else printf("0 ");
			if(id[u]==id[ss]&&id[v]==id[tt]) printf("1\n");
			else printf("0\n");
		}else printf("0 0\n");
	}
}

