#include<iostream>
#define mid ((lb+rb)>>1)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std;
namespace fio {
	streambuf* in = cin.rdbuf();
	char bb[1000000], * s = bb, * t = bb;
#define gc() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000),s==t)?EOF:*s++)
	inline int read() {
		int x = 0;
		char ch = getchar();
		while (ch < 48)ch = getchar();
		while (ch >= 48)x = x * 10 + ch - 48, ch = getchar();
		return x;
	}
}using fio::read;
int n, m, root; long long ans;
int ch[200005][2];
int siz[200005], son[200005], fa[200005], dep[200005];
int dfn[200005], las[200005], top[200005], cnt, id[200005];
void dfs(int x) {
	siz[x] = 1, dep[x] = dep[fa[x]] + 1;
	if (ch[x][0])dfs(ch[x][0]), son[x] = ch[x][0], siz[x] += siz[ch[x][0]];
	if (ch[x][1])dfs(ch[x][1]), son[x] = siz[ch[x][1]] > siz[son[x]] ? ch[x][1] : son[x], siz[x] += siz[ch[x][1]];
	ans += son[x];
}
void dfs2(int x, int t) {
	top[x] = t, id[dfn[x] = ++cnt] = x;
	if (son[x])dfs2(son[x], t);
	if (ch[x][0] != son[x] && ch[x][0])dfs2(ch[x][0], ch[x][0]);
	else if (ch[x][1] != son[x] && ch[x][1])dfs2(ch[x][1], ch[x][1]);
	las[x] = cnt;
}
int jump(int x, int k) {
	int tar = dep[x] - k;
	while (dep[top[x]] > tar)x = fa[top[x]];
	return id[dfn[x] + tar - dep[x]];
}
void w(long long x) { if (x >= 10)w(x / 10); putchar(x % 10 + 48); }
int tree[200005];
void add(int x, int v) { while (x <= n)tree[x] += v, x += x & -x; }
int query(int x) { int ans = 0; while (x)ans += tree[x], x -= x & -x; return ans; }
int nsize(int x) { return x ? query(las[x]) - query(dfn[x] - 1) : 0; }
void upd(int x) {
	if (x) {
		ans -= son[x];
		int maxn = max(nsize(ch[x][0]), nsize(ch[x][1]));
		if (!maxn)son[x] = 0;
		else if (maxn != nsize(son[x]))son[x] = nsize(ch[x][0]) == maxn ? ch[x][0] : ch[x][1];
		ans += son[x];
	}
}
void del(int x) {
	int ptr = dep[x];
	add(dfn[x], -1);
	while (ptr) {
		int lb = 1, rb = ptr, ff = 0, tar = nsize(jump(x, ptr));
		while (lb <= rb)if (nsize(jump(x, mid)) * 2 <= tar)ff = mid, lb = mid + 1; else rb = mid - 1;
		upd(jump(x, ff + 1));
		if (ptr)ptr = ff;
		else return w(ans), putchar('\n'), void();
	}
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++)fa[ch[i][0] = read()] = i, fa[ch[i][1] = read()] = i;
	fa[0] = 0, dep[0] = -1;
	dfs(1), dfs2(1, 1);
	w(ans), putchar('\n');
	m = read();
	for (int i = 1; i <= n; i++)add(i, 1);
	for(int i=1;i<=n;i++){
		printf("db: %d\n",nsize(i)); 
	} 
	while (m--)del(read()), w(ans), putchar('\n');
}
