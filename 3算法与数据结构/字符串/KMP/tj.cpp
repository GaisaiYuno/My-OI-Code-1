#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
namespace remoon {
#define ri register int
#define rep(iu, st, ed) for(ri iu = st; iu <= ed; iu ++)
#define drep(iu, ed, st) for(ri iu = ed; iu >= st; iu --)
#define gc getchar
	inline int read() {
		int p = 0, w = 1;
		char c = gc();
		while(c > '9' || c < '0') {
			if(c == '-') w = -1;
			c = gc();
		}
		while(c >= '0' && c <= '9') p = p * 10 + c - '0', c = gc();
		return p * w;
	}
}
using namespace std;
using namespace remoon;

const int sid = 1005000;

int n, m, cm, tot;
int ans[sid], nxt[sid], pre[sid];
int t[sid], p[sid], h[sid], T[sid];

inline void upd(int o, int v) {
	for(ri i = o; i <= m; i += i & (-i))
		t[i] += v;
}

inline int qry(int o) {
	int ret = 0;
	for(ri i = o; i; i -= i & (-i))
		ret += t[i];
	return ret;
}

void Solve() {
	rep(i, 1, n)
	pre[i] = qry(p[i]), upd(p[i], 1);
	pre[n + 1] = -1;

	rep(i, 1, m) t[i] = 0;
	for(ri i = 2, j = 0; i <= n; i ++) {
		while(j && qry(p[i]) != pre[j + 1]) {
			for(ri k = i - j; k < i - nxt[j]; k ++)
				upd(p[k], -1);
			j = nxt[j];
		}
		if(qry(p[i]) == pre[j + 1]) j ++, upd(p[i], 1);
		nxt[i] = j;
	}

	rep(i, 1, m) t[i] = 0;
	for(ri i = 1, j = 0; i <= m; i ++) {
		while(j && qry(h[i]) != pre[j + 1]) {
			for(ri k = i - j; k < i - nxt[j]; k ++)
				upd(h[k], -1);
			j = nxt[j];
		}
		if(qry(h[i]) == pre[j + 1]) j ++, upd(h[i], 1);
		if(j == n) ans[++ tot] = i - n + 1;
	}
}

int main() {

	n = read();
	m = read();
	rep(i, 1, n) p[read()] = i;
	rep(i, 1, m) T[i] = h[i] = read();

	sort(T + 1, T + m + 1);
	cm = unique(T + 1, T + m + 1) - T - 1;
	rep(i, 1, m) h[i] = lower_bound(T + 1, T + cm + 1, h[i]) - T;

	Solve();
	printf("%d\n", tot);
	rep(i, 1, tot) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
