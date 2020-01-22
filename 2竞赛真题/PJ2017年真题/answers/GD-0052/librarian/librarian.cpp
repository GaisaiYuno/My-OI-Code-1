#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, tmp, key; 
int ned[10000001];

int main()
{
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);
	memset(ned, -1, sizeof(ned));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		int tmpp = tmp;
		int cnt = int(log(double(tmp)) / log(10.0));
		while(cnt != -1)
		{
			ned[tmpp] = (ned[tmpp] + 1) ? min(ned[tmpp], tmp) : tmp;
			tmpp %= int(pow(10.0, double(cnt)));
			cnt--;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d", &tmp, &key);
		printf("%d\n", ned[key]);
	}
	return 0;
} 
