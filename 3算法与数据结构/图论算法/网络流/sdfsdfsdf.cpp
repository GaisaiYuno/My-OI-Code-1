#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <set>
#define MAXN 100000
#define MOD 
#define INF (1<<20)
#define LLINF (1LL<<50)
#define ri register int
#define il inline
#define fir first
#define sec second
#define pb push_back
using namespace std;
typedef long long LL;
typedef long double LD;
int n, m, k, cnt, s, t, q[MAXN<<2], level[MAXN<<2];
struct node {
	int v; LL c;
	node *next, *rev;
}pool[MAXN<<3], *h[MAXN<<2], *cur[MAXN<<2];
il void adde(int u, int v, LL c) {
	printf("%d %d %lld\n",u,v,c);
	node *p = &pool[cnt++], *q = &pool[cnt++];
	*p = node {v, c, h[u], q}, h[u] = p;
	*q = node {u, 0, h[v], p}, h[v] = q;
}
il int Hash(int x, int y) {
	return (x-1)*m+y;
}
bool bfs() {
	int front = 0, rear = 1;
	memset(level, 0, sizeof(level));
	q[rear++] = s;
	level[s] = 1;
	while(front < rear) {
		int u = q[front++];
		for(node *p = h[u]; p; p = p->next) {
			if(p->c && !level[p->v]) {
				level[p->v] = level[u]+1, q[rear++] = p->v;
				if(p->v == t) return 1;
			}
		}
	}
	return 0;
}
LL dfs(int u, LL f) {
	if(u == t) return f;
	LL flow = 0, F;
	for(node *&p = cur[u]; p; p = p->next) {
		if(p->c && level[p->v] == level[u]+1) {
			F = dfs(p->v, min(f-flow, p->c));
			flow += F, p->c -= F, p->rev->c += F;
			if(flow == f) return flow; 
		}
	}
	return flow;
}
LL Dinic() {
	int ret = 0;
	while(bfs()) {
		for(ri i = s; i <= t; ++i) cur[i] = h[i];
		ret += dfs(s, INF);
	}
	return ret;
}
int main()
{
	int w, u, v, fw;
	scanf("%d%d%d", &n, &m, &k);
	t = n*m+1;
	for(ri i = 1; i <= n; ++i) {
		adde(s, Hash(i, 1), INF);
		for(ri j = 1; j < m; ++j) {
			scanf("%d", &w);
			if(w == -1) fw = INF; else fw = 100-w;
			adde(Hash(i, j), Hash(i, j+1), fw);
		}
		scanf("%d", &w);
		if(w == -1) fw = INF; else fw = 100-w;
		adde(Hash(i, m), t, fw);
	}
	while(k--) {
		scanf("%d%d", &u, &v);
		for(ri i = 1; i < m; ++i) adde(Hash(u, i), Hash(v, i+1), INF);
		adde(Hash(u, m), t, INF);
	}
	int sum = 100*n-Dinic();
	printf("%.2lf", 1.0*sum/n);
	return 0;
}

