## [多校联考2019(Round 5)]青青草原的表彰大会(dp+组合数学)

### 题面

青青草原上有n 只羊，他们聚集在包包大人的家里，举办一年一度的表彰大会，在这次的表彰大会中，包包大人让羊们按自己的贡献从小到大排成一排，以便于发放奖金。每只羊都会得到数值在 1~m 的奖金，并且第 i 只羊的奖金应为第 i+1只羊的约数（即满足 ai|ai+1）。现在包包大人想知道一共有多少种不同的发放奖金的方式（两种发放奖金的方式不同是指在两种发放奖金的方式中存在某只羊拿到的奖金不同）

###　分析

我们发现，序列中不同的数最多只有$O(\log m)$个，因为后面的数至少是前面的数*2.

那么我们可以dp求出长度为$i$的每个数互不相同的序列个数。设$dp[i][j]$表示长度为$i$，结尾为$j$的本质不同序列个数 .那么可以用$dp[i][j]$去更新$dp[i+1][j*k] (jk \leq n,k \in \mathbb{N}，k \neq 1)$

```cpp
for(int i=1;i<log2m;i++){//a序列里本质不同的数只有O(logm)个,因此不用对n个数dp， 
		for(int j=1;j<=m;j++){
			for(int k=2;j*k<=m;k++){
				dp[i+1][j*k]+=dp[i][j];
				dp[i+1][j*k]%=mod;
			}
		}
	}
```

因为1~m的数的约数个数和为$O(m \log m)$,所以dp的复杂度是$O(m \log ^2m)$

然后考虑把序列扩展到长度为n。对于长度为$i$的每个数互不相同的序列，我们记它的方案数为$cnt[i]=\sum_{j=1}^m dp[i][j]$.我们把长度为n的序列分成$i$段,每段对应长度为$i$数列中的一个值。用插板法,从$n-1$个间隔中选$i-1$个插板,方案数是$C_{n-1}^{i-1}$

因此答案是$\sum_{i=1}^{\log_2m} C_{n-1}^{i-1}cnt[i]$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#define maxlogm 23
#define maxn 1000000
#define maxm 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fact[maxn+5],invfact[maxn+5];
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
ll inv(ll x){
	return fast_pow(x,mod-2);
}
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
} 
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int n,m;
int log2m;
ll dp[maxlogm+5][maxm+5];//长度为i，结尾为j的本质不同序列个数 
ll cnt[maxlogm+5];//长度为i的序列个数, 即sum(dp[i][j]) (1<=j<=m) 
int main(){
	scanf("%d %d",&m,&n);
	log2m=log2(m)+1;
	ini(max(n,log2m));
	for(int i=1;i<=m;i++) dp[1][i]=1;
	for(int i=1;i<log2m;i++){//a序列里本质不同的数只有O(logm)个,因此不用对n个数dp， 
		for(int j=1;j<=m;j++){
			for(int k=2;j*k<=m;k++){
				dp[i+1][j*k]+=dp[i][j];
				dp[i+1][j*k]%=mod;
			}
		}
	}
	for(int i=1;i<=log2m;i++){//a序列里本质不同的数只有O(logm)个,因此不用对n个数dp， 
		for(int j=1;j<=m;j++){
			cnt[i]+=dp[i][j];
			cnt[i]%=mod; 
		}
	}
	ll ans=0;
	for(int i=1;i<=log2m&&i<=n;i++){
		ans+=cnt[i]*C(n-1,i-1)%mod;//把n个数分成i段，每段对应序列中的一个数,插板法 
		ans%=mod;
	} 
	printf("%lld\n",ans);
}
```

