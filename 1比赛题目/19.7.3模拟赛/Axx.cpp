#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 500009;
const int MOD = 1032992941;
 
struct edge {
	int to;
	edge* next;
} E[maxn << 1], *pt = E, *head[maxn];
 
void AddEdge(int u, int v) {
	pt->to = v; pt->next = head[u]; head[u] = pt++;
}
 
void upd0(ll &x, int t) {
	if((x += t) >= MOD) x -= MOD;
}
 
void upd1(ll &x, int t) {
	x = x * t % MOD;
}
 
int N;
ll dp[maxn][3], cnt[maxn][3];
 
void init() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		AddEdge(--u, --v);
		AddEdge(v, u);
	}
}
 
void dfs(int x, int fa) {
	
	dp[x][0] = 0; dp[x][1] = maxn; dp[x][2] = 1;
	cnt[x][0] = cnt[x][1] = cnt[x][2] = 1;
	
	ll Min, sum;
	for(edge* e = head[x]; e; e = e->next) if(e->to != fa) {
		
		dfs(e->to, x);
		
		Min = min(min(dp[e->to][0], dp[e->to][1]), dp[e->to][2]);
		sum = 0;
		dp[x][2] += Min;
		for(int i = 0; i < 3; i++)
			if(dp[e->to][i] == Min) upd0(sum, cnt[e->to][i]);
		upd1(cnt[x][2], sum);
		
		Min = min(dp[x][1] + min(dp[e->to][1], dp[e->to][2]), dp[x][0] + dp[e->to][2]);
		sum = 0;
		for(int i = 1; i < 3; i++) 
			if(dp[x][1] + dp[e->to][i] == Min) upd0(sum, cnt[e->to][i]);
		upd1(cnt[x][1], sum);
		if(dp[x][0] + dp[e->to][2] == Min)
			upd0(cnt[x][1], ll(cnt[x][0]) * cnt[e->to][2] % MOD);
		dp[x][1] = Min;
	
		dp[x][0] += dp[e->to][1];
		upd1(cnt[x][0], cnt[e->to][1]);
		
	}
#ifdef DEBUG
	printf("node %d: (%d,%d,%d)\n",x+1,dp[x][2],dp[x][1],dp[x][0]);
	
#endif
}
 
int main() {
	
	init();
	dfs(0, -1);
	
	ll ans = min(dp[0][1], dp[0][2]), sum = 0;
	for(int i = 1; i < 3; i++)
		if(dp[0][i] == ans) upd0(sum, cnt[0][i]);
	printf("%lld\n%lld\n", ans, sum);
	
	return 0;
}
