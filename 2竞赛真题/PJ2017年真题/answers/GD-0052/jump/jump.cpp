#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, d, k, a, b, maxn = 0, maxnn = 0;
int x[500001], s[500001], dp[500001];


bool check(int ch);

int main()
{
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	scanf("%d %d %d", &n, &d, &k);
	x[0] = s[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		x[i] = a;
		s[i] = b;
	}
	int l = 0;
	int r = x[n] - d;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			r = mid;
		} 
		else
		{
			l = mid + 1;
		}
	}
	int ans = -1;
	if(l == x[n] - d)
	printf("%d", ans);
	else
	printf("%d", l);
	return 0;
}

bool check(int ch)
{
	int t1 = d - ch;
	int t2 = d + ch;
	if(d - ch < 0)
	t1 = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
	{
		maxn = -2139062140;
		for(int j = i - 1; j >= 0; j--)
		{
			if(x[i] - x[j] >= t1 && x[i] - x[j] <= t2)
			{
				maxn = max(maxn, dp[j]);
			}
			if(x[i] - x[j] > t2)
			break;
		}
		dp[i] = s[i] + maxn;
	}
	maxnn = 0;
	for(int i = 0; i <= n; i++)
	{
		maxnn = max(maxnn, dp[i]);
	}
	if(maxnn >= k)
	return true;
	else
	return false;
}
