#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 1000000;
bool bad[N];
int sf[N + 1], n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	f(i, 0, m){
		int t;
		scanf("%d", &t);
		bad[t] = true;
	}
	if (bad[0]) { printf("-1\n"); return 0; }
	int mx = 0;
	f(i, 0, n)if (bad[i])sf[i] = sf[i - 1], mx = max(mx, i - sf[i] + 1);
	else sf[i] = i;
	
	if (mx > k) { printf("-1\n"); return 0; }
	ll an = 1e18;
	f(i, 1, k + 1){
		int c;
		scanf("%d", &c);
		if (i < mx)continue;
		int z = 0, j = 0;
		while (true){
			++z;
			j += i;
			if (j >= n)break;
			j = sf[j];
		}
		an = min(an, (ll)c * z);
	}
	printf("%lld\n", an);
}
