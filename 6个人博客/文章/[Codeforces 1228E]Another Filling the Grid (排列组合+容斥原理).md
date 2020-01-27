## [Codeforces 1228E]Another Filling the Grid (排列组合+容斥原理)

### 题面

一个$n \times n$的格子,每个格子里可以填$[1,k]$内的整数。要保证每行每列的格子上的数最小值为1，有多少种方案

$n \leq 250,k \leq 10^9$

### 分析

这题有$O(n^3)$的dp做法，但个人感觉不如$O(n^2 \log n)$直接用数学方法求更好理解。

考虑容斥原理，枚举有$i$行最小值>1,有$j$行最小值>1,那答案就是$\sum_{i=0}^n \sum_{j=0}^n (-1)^{i+j} C_n^i C_n^j (有i行最小值>1,有j行最小值>1的方案数)$。其中$C_n^i,C_n^j$表示从n行中选出i行，n列中选出j列。容斥是因为i行j列的情况可能包含行数<i,列数<j的情况。

然后某一行的最小值>1,那这行里的所有数都>1。因此只要求出哪些格子里的数>1即可。显然i行j列包含的格子数为$ni+nj-ij$.这些格子的填法有${(k-1)}^{ni+nj-ij}$种(不能填1)，其余格子的填法为$k^{n^2-ni-nj+ij}$

因此答案为

$$\sum_{i=0}^n \sum_{j=0}^n (-1)^{i+j} C_n^i C_n^j {(k-1)}^{ni+nj-ij} k^{n^2-ni-nj+ij}$$

枚举i,j,然后快速幂求逆元，时间复杂度为$O(n^2 \log n)$。可以通过。

注意到第二个sigma类似二项式定理，分离出质数$j$和$n-j$

${(k-1)}^{ni+nj-ij} k^{n^2-ni-nj+ij}=k^{(n-j)(n-i)}(k-1)^{(n-j)i}(k-1)^{j \times n}=[k^{n-i}(k-1)^i]^{n-j}(k-1)^j$

$$\sum_{i=0}^{n} (-1)^i \cdot C_n^i \cdot (k^{n-i} \cdot (k-1)^{i} - (k-1)^{n})^n$$

###　代码

$x^k y^{n-k} $

```cpp
//O(n^2logn)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 250
#define mod 1000000007
using namespace std;
typedef long long ll; 
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
ll fact[maxn+5],invfact[maxn+5];
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
}
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int n,k;
int main(){
	scanf("%d %d",&n,&k);
	ini(n);
	ll ans=0;
	for(int i=0;i<=n;i++){//共i行不符合条件 
		for(int j=0;j<=n;j++){//共j列不符合条件 
			ll cnt=i*n+j*n-i*j;//不符合条件行和列的格子，这些格子的值>1 
			ans+=fast_pow(-1,i+j)*C(n,i)%mod*C(n,j)%mod*fast_pow(k-1,cnt)%mod*fast_pow(k,n*n-cnt)%mod;
			ans=(ans+mod)%mod;
		}
	}
	printf("%I64d\n",ans);
}

```

