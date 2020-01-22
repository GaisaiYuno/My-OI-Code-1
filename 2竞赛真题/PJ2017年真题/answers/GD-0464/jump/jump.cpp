#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 500010;

int n, d, k;

struct rp {
	int x, s;
}a[maxn];

long long f[maxn];

bool Check1(int g) {
	
	memset(f, 0, sizeof(f));
	
	long long ll = d-g, rr = d+g;
	
	int t;
	for (t=1; t<=n; t++) {
		if(a[t].x >= ll && a[t].x <= rr) break;
	}
	
	f[t] = a[t].s;
	
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if(a[j].x-a[i].x >= ll && a[j].x-a[i].x <= rr) {
				f[j] = max(f[i]+a[j].s, f[j]);
				if(f[j] >= k) return true;
			}	
		}	
	}
	return false;
}
bool Check2(int g) {
	
	memset(f, 0, sizeof(f));
	
	long long ll = 1, rr = d+g;
	
	if(a[1].x>rr) return false;
	f[1] = a[1].s;
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if(a[j].x-a[i].x >= ll && a[j].x-a[i].x <= rr) {
				f[j] = max(f[i]+a[j].s, f[j]);
				if(f[j] >= k) return true;
			}	
		}	
	}
	
	return false;
}
long long sum = 0;
int main() {
	
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	
	scanf("%d %d %d", &n, &d, &k);
	
	for (int i=1; i<=n; i++) {
		scanf("%d %d", &a[i].x, &a[i].s);
		if(a[i].s>0) sum += a[i].s;
	}
	if(sum < k) {
		printf("-1");
		return 0;
	}
	
	int l, r;
	if(a[1].x > d) l=a[1].x-d-1, r=d;
	else l=0, r=d;	
	
	while(l+1 < r) {
		int mid = (l+r)/2;
		if(Check1(mid)) r = mid;
		else 		    l = mid;
	}
	
	if(r != d) {
		printf("%d\n", r);
		return 0;
	}
	else {
		l = d-1, r = a[n].x-d+1;
		while(l+1 < r) {
			int mid = (l+r)/2;
			if(Check2(mid)) r = mid;
			else 		    l = mid;
		}
		if(r != a[n].x-d+1) {
			printf("%d\n", r);
			return 0;
		}
		else printf("-1\n");
	}
	return 0;
}
