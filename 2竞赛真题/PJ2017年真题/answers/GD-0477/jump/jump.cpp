#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
using namespace std;
int a[5000010], x[5000010];
int dp[5000010];
int main()
{	//freopen("jump.in", "r", stdin);
	//freopen("jump.out", "w", stdout);
	int n, d, K;
	scanf("%d%d%d", &n, &d, &K);
	int sum = 0, Max = 0;
	for(int i=1; i<=n; i++)
	{	int num;
		scanf("%d%d", &x[i], &num);
		a[x[i]] = num;
		sum += a[x[i]];
		Max = max(Max, x[i]);
	}
	n = Max;
	for(int i=0; ; i++)
	{	int g = i;
		if(g < d)
		{	memset(dp, 0, sizeof(dp));
			for(int j=1; j<=n; j++)
			{	for(int k=d-g+1; k<= d+g; k++)
					if(j > k) dp[j] = max(dp[j], max(dp[j-k], a[j]+dp[j-k]));
			}
		}
		else
		{	memset(dp, 0, sizeof(dp));
			for(int j=1; j<=n; j++)
				for(int k=1; k<=d+g; k++)
					if(j > k) dp[j] = max(dp[j], max(dp[j-k], a[j]+dp[j-k]));
		}
		if(dp[n] >= K) { printf("%d\n", i); break; }
	}
	return 0;
}
