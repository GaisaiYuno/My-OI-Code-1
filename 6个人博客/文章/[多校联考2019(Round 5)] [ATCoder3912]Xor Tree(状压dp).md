## [多校联考2019(Round 5)] [ATCoder3912]Xor Tree(状压dp)

###　题面

给出一棵n个点的树，每条边有边权v，每次操作选中两个点，将这两个点之间的路径上的边权全部异或某个值，求使得最终所有边权为0的最小操作次数。 

$v \leq 15,n \leq 10^5$

### 分析

首先把边权转化为点权。记一个点的点权为与它相连的所有边的边权和。当我们给一条路径上的边异或上某个值时，路径端点的点权被异或了1次，而路径上不是端点的点有两条边被异或了，相当于异或了2次，权值不变。因此，我们发现，**路径上的边权修改相当于对路径端点的点权修改**

因此问题变成了，树上有n个点，每个点有一个点权。每次操作可以选2个点，将它们同时异或上某值，求使得最终所有点权为0的最小操作次数。 

首先，我们将值相等的点两两异或上它们的值。最后还剩下值互不相同的一些点，这些点最多有15个(值为0的点不管)。

于是可以状压dp.状态为当前权值的出现情况。

转移的时候枚举当前状态里的两个值$i,j$,考虑操作1次其中一个异或成0，那另一个的权值就变为$p=i \ \mathrm{XOR} \ j$。那么```dp[s]=min(dp[s],dp[(s^(1<<i)^(1<<j)^(1<<p)]+1)```

但是有一种特殊情况，如果原来的状态里就存在$i\ \mathrm{XOR} \ j$,那么还可以再操作1次，把两个$i\ \mathrm{XOR} \ j$消掉

```dp[s]=min(dp[s],dp[s^(1<<i)^(1<<j)^(1<<p)]+2)```

dp用记忆化搜索实现更方便

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxv 15
#define maxb (1<<16)
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[maxn+5];
int cnt[maxv+5];

int sta;
int dp[maxb+5];
int get_dp(int s) {
	if(dp[s]!=INF) return dp[s];
	for(int i=0; i<=15; i++) {
		if(!(s&(1<<i))) continue;
		for(int j=0; j<=15; j++) {
			if(!(s&(1<<j))||i==j) continue;
			int p=i^j;
			int rest=s^(1<<i)^(1<<j)^(1<<p);
			if(!(rest&(1<<p))) dp[s]=min(dp[s],get_dp(rest)+2); //i,j异或之后出现i^j，和原来的i^j一起被消掉
			else dp[s]=min(dp[s],get_dp(rest)+1);
		}
	}
	return dp[s];
}
int main() {
//#ifdef LOCAL
//	freopen("1.in","r",stdin);
//#endif 
	int u,v,w;
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		scanf("%d %d %d",&u,&v,&w);
		u++;
		v++;
		a[u]^=w;
		a[v]^=w;
	}
	for(int i=1; i<=n; i++) {
		cnt[a[i]]++;
	}
	int ans=0;
	for(int i=1; i<=15; i++) {
		ans+=cnt[i]/2;
		if(cnt[i]%2==1) sta|=(1<<i);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	ans+=get_dp(sta);
	printf("%d\n",ans);
}
```



