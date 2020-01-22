#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 500010;

int n, d, k;
int dp[MAXN];

struct Tnode {
	int dis, a;
} a[MAXN];

bool _cmp(Tnode a, Tnode b) {
	return a.dis < b.dis;
}

bool check(int s) {
	int l = max(1, d - s);
	int r = d + s;
	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i < n; ++i) {
		if(l <= a[i].dis && a[i].dis <= r) {
			dp[i] = (dp[i] == 0x3f3f3f3f ? a[i].a : max(a[i].a, dp[i]));
		}
		if(dp[i] == 0x3f3f3f3f) {
			continue;
		}
		for(int j = i + 1; j < n; ++j) {
			if(l <= a[j].dis - a[i].dis && a[j].dis - a[i].dis <= r) {
				dp[j] = dp[j] != 0x3f3f3f3f ? max(dp[j], dp[i] + a[j].a) : dp[i] + a[j].a;
				if(dp[j] != 0x3f3f3f3f && dp[j] >= k) {
					return 1;
				}
			}
			if(a[j].dis - a[i].dis > r) {
				break;
			}
		}
	}
	return 0;
}

int main(void) {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	
	scanf("%d%d%d", &n, &d, &k);
	int range = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].dis, &a[i].a);
		range = max(range, a[i].dis);
	}
	if(!check(range)) {
		printf("-1\n");
		return 0;
	}
	int l = 0, r = range;
	while(l + 1 < r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%d\n", r); 
	return 0;
}
