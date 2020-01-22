#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1010;

int n, m;

int a[maxn], t[10] = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000};

int main() {
	
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+n+1);
	
	for (int i=1, x, y; i<=m; i++) {
		
		scanf("%d %d", &x, &y);
		
		if(x<1 || x>8) {
			printf("-1\n");
			continue;
		}
		
		int fl = 0;
		
		for (int j=1; j<=n; j++) {
			if(a[j]%t[x+1]==y) {
				printf("%d\n", a[j]);
				fl = 1;
				break;
			}
		}
		if(fl == 0) printf("-1\n");
	}
	
	return 0;
}
