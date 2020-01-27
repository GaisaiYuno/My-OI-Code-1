### 题面

[传送门](https://codeforces.com/contest/1061/problem/C)

### 分析

考虑DP

设$dp[i][j]$表示前i个数选出的序列长度为j的方案数

状态转移方程为:

$$ dp[i][j]= \begin{cases}dp\left[ i-1\right] \left[ j-1\right] +dp\left[ i-1\right] \left[ j-1\right] ,j \equiv 0 (\mod i) \\ dp\left[ i-1\right] \left[ j-1\right],otherwise \end{cases} $$

如果二维DP，直接从1~n枚举i,j,显然会MLE

发现第一维状态i只和i-1有关，考虑用类似01背包的方法去掉一维

设dp[j]表示长度为j时的状态

第i-1次循环结束后，$dp[j]$存储的是原来$dp[i-1][j]$的值

然后我们类似01背包，倒序循环j (j为i的因数,若j不是i的因数，dp值不变，不必循环) dp[j]+=dp[j-1]

我们更新dp[j]时，dp[j-1]存的还是原来$dp[i-1][j-1]$的值，这样便不会重复更新



另外，因数个数怎么解决呢

我们用这样的筛法，可以在$O(n\log n)$的时间内筛出1~n的因数

```cpp
vector<int>d[maxA];
void sieve(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x/i;j++){
			d[i*j].push_back(i);
		}
	}
} 
```



所以总的时间复杂度为$O(n\log \max(a_i))$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<vector> 
#include<algorithm> 
#define maxn 100005
#define maxA 1000005
#define mod 1000000007
using namespace std;
int n;
int maxa;
int a[maxn];
int dp[maxA];
vector<int>d[maxA];
void sieve(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x/i;j++){
			d[i*j].push_back(i);
		}
	}
} 
int cmp(int x,int y){
	return x>y; 
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]); 
	} 
	dp[0]=1;
	sieve(maxa); 
	for(int i=1;i<=n;i++){ 
		for(int j=d[a[i]].size()-1;j>=0;j--){
			int x=d[a[i]][j];
			dp[x]+=dp[x-1];
			dp[x]%=mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
	}
	ans%=mod;
	cout<<ans;
} 
```





