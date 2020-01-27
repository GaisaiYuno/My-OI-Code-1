## [Codeforces 1214A]Optimal Currency Exchange(贪心)

### 题面

题面较长，略

### 分析

这个A题稍微有点思维难度，比赛的时候被孙了一下

贪心的思路是，我们换面值越小的货币越优。如有1,2,5,10,20,50，那么我们尽量用面值为1的。如果我们把原始货币换成面值为x的货币，设汇率为d,那么需要的原始货币为dx的倍数。显然dx越小，剩下的钱，即n取模dx会尽量小。

然后就可以枚举换某一种货币的数量，时间复杂$O(\frac{n}{d})$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int n,d,e;
int main(){
	scanf("%d %d %d",&n,&d,&e);
	e*=5;
	int ans=INF;
	for(int i=0;i*d<=n;i++){
		ans=min(ans,n-i*d-(n-i*d)/e*e);
	}
	printf("%d\n",ans);
}

```

