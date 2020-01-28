#include <bits/stdc++.h>
#define Mem(a, v) memset(a, v, sizeof(a))
#define PII pair<int, int> 
#define Md(a, b, c) (node) {a, b, c}
using namespace std;
typedef long long ll;
typedef double lf;

int CheckMax(int& a, int b) {return a < b ? a = b, 1 : 0;}
int CheckMin(int& a, int b) {return a > b ? a = b, 1 : 0;}
int GetCh() {return getchar();}
int read() {
	int Value = 0,Base = 1;char Ch = getchar();
    for(; !isdigit(Ch); Ch = getchar())if(Ch == '-')Base = -1;
    for(; isdigit(Ch); Ch = getchar())Value = Value * 10 + (Ch ^ '0');
    return Value * Base;
}

const int mx = 1e7 + 50, nx = 1e5 + 50;
struct node {
	int l, r, id;
	bool operator <(const node& T) 
		const {
			return l == T.l ? r < T.r : l < T.l;
		}
} a[mx], q[mx];
int c[nx], n, m, tot, ans[mx];
int cmp(node a, node b) {return a.r > b.r;}

int Lowbit(int x) {
	return x & -x;
}

void Add(int x, int v) {
	for(; x <= n; x += Lowbit(x))
		c[x] += v;
}

int Query(int x) {
	int res = 0;
	for(; x; x -= Lowbit(x))
		res += c[x];
	return res;
}

void Build(int l, int r) {
	if(l == r) return ;
	a[++tot] = Md(l, r, 0);
	int mid = read();
	//cout << "mid:" << mid << endl;
	Build(l, mid); Build(mid + 1, r);
}

int main( ) {
	n = read(); m = read();
	Build(1, n);
	for(int i = 1; i <= m; i++) {
		int l = read(), r = read();
		q[i] = Md(l, r, i);
	}
	sort(q + 1, q + m + 1);
	sort(a + 1, a + tot + 1);
	int s = 1, t = 1;
	for(int i = 1; i <= n; i++) {
		for(; t <= m && q[t].l <= i; t++) ans[q[t].id] += Query(n) - Query(q[t].l - 1);
		for(; s <= tot && a[s].l <= i; s++) Add(a[s].r, 1);
//		printf("debug %d\n",q[t].id);
	}
	sort(q + 1, q + m + 1, cmp);
	sort(a + 1, a + tot + 1, cmp);
	Mem(c, 0); s = t = 1;
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	printf("\n");
	for(int i = n; i; i--) {
		for(; t <= m && q[t].r >= i; t++)
			ans[q[t].id] += Query(q[t].r) - Query(q[t].l - 1);
		for(; s <= tot && a[s].r >= i; s++) Add(a[s].l, 1);
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}



