#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 50005, MAXM = 100005, MAXV = 300005, B = 10005;
vector<int> dx[MAXN], edge[MAXV];
int opt[MAXM], tim[MAXM], fr[MAXM], to[MAXM], T, n, m;
int beg[MAXN], ed[MAXN], que[MAXV], du[MAXV], res[MAXN];
bitset<B> bt[MAXV];
int main() {
	scanf("%d%d%d", &T, &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", opt + i, tim + i, fr + i, to + i);
		dx[fr[i]].push_back(tim[i]);
	}
	for (int i = 1; i <= n; i++)
		dx[i].push_back(T + 1);
	for (int i = 1; i <= n; i++) {
		sort(dx[i].begin(), dx[i].end());
		dx[i].resize(unique(dx[i].begin(), dx[i].end()) - dx[i].begin());
		beg[i] = ed[i - 1] + 1;
		ed[i] = beg[i] + dx[i].size() - 1;
		res[i] = n - 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < (int)dx[i].size(); j++) {
			int a = beg[i] + j - 1, b = a + 1;
			edge[a + ed[n]].push_back(b + ed[n]);
			edge[b].push_back(a);
			++du[b + ed[n]], ++du[a];
		}
	}
	for (int i = 1; i <= m; i++) {
		int a = lower_bound(dx[fr[i]].begin(), dx[fr[i]].end(), tim[i])
			- dx[fr[i]].begin() + beg[fr[i]];
		int b = lower_bound(dx[to[i]].begin(), dx[to[i]].end(), opt[i] ? tim[i] : tim[i] + 1)
			- dx[to[i]].begin() + beg[to[i]];
		if (opt[i]) {
			edge[a].push_back(b + ed[n]);
			edge[b].push_back(a + ed[n]);
			++du[b + ed[n]], ++du[a + ed[n]];
		} else {
			edge[a + ed[n]].push_back(b + ed[n]);
			edge[b].push_back(a);
			++du[b + ed[n]], ++du[a];
		}
	}
//	for(int i=1;i<=ed[n]*2;i++){
//		for(int x : edge[i]){
//			printf("db: %d %d\n",i,x);
//		}
//	}
	int nn = ed[n] * 2, he = 1, ta = 0;
	for (int i = 1; i <= nn; i++) if (!du[i]) que[++ta] = i;
	while (he <= ta) {
		int u = que[he++];
		for (int v : edge[u])
			if (!(--du[v])) que[++ta] = v;
	}
	assert(ta == nn);
	for (int i = 1; i <= n; i += 10000) {
		int ii = min(i + 9999, n);
		memset(bt, 0, sizeof(bt));
		for (int j = i; j <= ii; j++)
			bt[ed[j] + ed[n]].set(j - i);
		for (int j = ta; j > 0; j--)
		for (int v : edge[que[j]])
			bt[que[j]] |= bt[v];
		bitset<B> tmp;
		for (int j = i; j <= ii; j++)
			if (bt[ed[j]].test(j - i)) res[j] = 0, tmp.set(j - i);
		for (int j = 1; j <= n; j++) if (res[j])
			res[j] -= (bt[ed[j]] | tmp).count();
	}
	for (int i = 1; i <= n; i++) printf("%d ", res[i]);
	return 0;
}

