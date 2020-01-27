#include<bits/stdc++.h>
typedef long long ll;
const ll maxn = 1e3 + 10;
const ll mod = 1e9 + 7;
using namespace std;

struct P {
	ll from, to, w;
	P() {}
	P(ll f, ll t, ll w) : from(f), to(t), w(w) {}
	bool operator < (P p) const {
		return w < p.w;
	}
};

ll n, m, pre[maxn], is[maxn * 2];
vector<P> edge, G[maxn];
ll anc[maxn][12], deep[maxn];
ll cost[maxn][12], c[maxn], x;

ll findset(ll x) {
	return x == pre[x] ? x : pre[x] = findset(pre[x]);
}

void dfs(ll x, ll fa, ll d, ll ws) {//最小生成树上dfs
	deep[x] = d;
	pre[x] = fa;
	c[x] = ws;
	for(ll i = 0; i < G[x].size(); i++) {
		P e = G[x][i];
		ll to = e.to, w = e.w;
		if(to == fa) continue;
		dfs(to, x, d + 1, w);
	}
}

void preprocess() {//倍增预处理路径上最大值和lca
	memset(anc, -1, sizeof anc);
	memset(cost, -1, sizeof cost);
	for(ll i = 1; i <= n; i++) {
		cost[i][0] = c[i];
		anc[i][0] = pre[i];
	}
	for(ll j = 1; (1 << j) <= n; j++) {
		for(ll i = 1; i <= n; i++) {
			ll t = anc[i][j - 1];
			if(t == -1) continue;
			cost[i][j] = max(cost[i][j - 1], cost[t][j - 1]);
			anc[i][j] = anc[t][j - 1];
		}
	}
}

ll query(ll x, ll y) {//类似lca查询最大值
	if(deep[x] > deep[y]) swap(x, y);
	ll lg = 0;
	while((1 << lg) <= deep[y]) lg++;
	lg--;
	ll ans = 0;
	for(ll i = lg; i >= 0; i--) {
		if(deep[y] - deep[x] >= (1 << i)) {
			ans = max(ans, cost[y][i]);
			y = anc[y][i];
		}
	}
	if(x == y) return ans;
	for(ll i = lg; i >= 0; i--) {
		if(anc[x][i] == anc[y][i]) continue;
		ans = max(ans, cost[x][i]);
		ans = max(ans, cost[y][i]);
		x = anc[x][i];
		y = anc[y][i];
	}
	ans = max(ans, max(c[x], c[y]));
	return ans;
}

ll qmod(ll x, ll n, ll mod) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}

int main() {
//	freopen("t12.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m,&x);
	memset(is, 0, sizeof is);
	for(ll i = 0; i < maxn; i++) {
		G[i].clear();
		pre[i] = i;
	}
	edge.clear();
	for(ll i = 0; i < m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		edge.push_back(P(u, v, w));
	}
	sort(edge.begin(), edge.end());
	ll tot_wight = 0, ed = 0;
	for(ll i = 0; i < edge.size(); i++) {//Kruskal求最小生成树
		P e = edge[i];
		ll u = e.from, v = e.to, w = e.w;
		ll nu = findset(u), nv = findset(v);
		if(nu == nv) continue;
		is[i] = 1;//is_i表示边i在最小生成树内
		ed++;
		tot_wight += w;
		pre[nu] = nv;
		G[u].push_back(P(u, v, w));
		G[v].push_back(P(v, u, w));
	}
	dfs(1, 0, 1, 0);
	preprocess();
	for(ll i = 0; i < edge.size(); i++) {
		if(is[i]) continue;
		ll from = edge[i].from, to = edge[i].to;
		ll max_w = query(from, to);
		if(max_w == edge[i].w) {//处理边权相同的情况，最小生成树会有多种，故i也算生成树中的边
			is[i] = 1;
			ed++;
		}
	}
	//把上下看做两种颜色A,B
	ll ans;
//	printf("d=%lld\n",tot_wight);
	if(tot_wight > x) ans = 0;
	else if(tot_wight == x) {
		ans = qmod(2, m - ed, mod);//最小生成树内外边随意排
		ans = ans * (qmod(2, ed, mod) - 2) % mod; //最小生成树内的边除了全A，全B均可
		if(ans < 0) ans = ans + mod;
	} else {
		ll dx = 0;
		for(ll i = 0; i < edge.size(); i++) {
			if(is[i]) continue;
			ll max_w = query(edge[i].from, edge[i].to);
			if(tot_wight - max_w + edge[i].w == x){
//				printf("debug%d %d\n",edge[i].from,edge[i].to); 
//				cout<<edge[i].from<<' '<<edge[i].to;
				dx++;//去掉生成树的大小变小或不变的情况
			}
			else if(tot_wight - max_w + edge[i].w < x) ed++;
		}
		//设cnt=为
		//最小生成树一定同种颜色，因为假若不同颜色，那么这颗生成树一定满足题意， 这与最小值为x矛盾
		//先假定最小生成树为一种颜色A，则小于的边一定和最小生成树同色，同上可证，这样才不会与最小值为x矛盾
		//一定有一种等于的情况,故所有等于的边中至少有一条为颜色B,答案2^(cnt(=))-1 (1为全A的情况
		//由于A,B可以交换，故还要再成2
		// 大于的边可任意选颜色，2^(cnt(>))
//		printf("%d %d %lld\n",ed,m-ed-dx,dx);
//		cout<<ed<<' '<<m-ed-dx<<' '<<dx<<endl;
		ans = qmod(2, m - ed - dx, mod);//大于的边可任意选颜色
		ll col = 2 * (qmod(2, dx, mod) - 1) % mod;
		ans = ans * col % mod;
		if(ans < 0) ans = ans + mod;
	}
	cout << ans << endl;
return 0;
}

