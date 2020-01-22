#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1005;
int n, q, code[maxn];

int main () {
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	
	for (int i=1; i<=n; i++) scanf("%d", &code[i]);
	sort(code+1, code+n+1);
	
	for (int i=1; i<=q; i++) {
		int len, req;
		scanf("%d%d", &len, &req);
		
		int cut = 1;
		for (int j=1; j<=len; j++) cut = cut*10;
		
		bool flag = 0;
		for (int j=1; j<=n; j++) {
			if (code[j]%cut == req%cut) {
				flag = 1;
				printf("%d\n", code[j]);
				break;
			}
		}
		
		if (!flag) printf("-1\n");
		
	}
	
	return 0;
}
