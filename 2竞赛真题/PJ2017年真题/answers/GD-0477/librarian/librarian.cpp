#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
using namespace std;
char str[1010][110];
char tmp[110];
int l[1010], num[1010];
int r[1010];
bool cmp(int x, int y) { return num[x] < num[y]; }
int main()
{	int n, q;
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
	{	int len = 0;
		char c = getchar();
		int x = 0;
		while(c < '0' || c > '9') c = getchar();
		while(c >= '0' && c <= '9')
		{	str[i][++len] = c;
			x = x*10+c-'0';
			c = getchar();
		}
		num[i] = x;
		l[i] = len;
	}
	for(int i=1; i<=n; i++) r[i] = i;
	sort(r+1, r+1+n, cmp);
	for(int i=1; i<=q; i++)
	{	scanf("%*d");
		int len = 0;
		char c = getchar();
		while(c < '0' || c > '9') c = getchar();
		while(c >= '0' && c <= '9')
		{	tmp[++len] = c;
			c = getchar();
		}
		int ans = 0x7f7f7f7f;
		for(int j=1; j<=n; j++)
		{	if(len > l[r[j]]) continue;
			int cnt = 0, a = len;
			for(int k=l[r[j]]; k>=1; k--)
			{	if(cnt == len) break;
				if(str[r[j]][k] == tmp[a]) cnt++;
				else break;
				a--;
			}
			if(cnt == len) { ans = num[r[j]]; break; }
		}
		if(ans == 0x7f7f7f7f) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}
