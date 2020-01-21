## [luogu5339] [TJOI2019]唱、跳、rap和篮球(容斥原理+组合数学)(不用NTT)

### 题面

略

###　分析

首先考虑容斥，求出有i堆人讨论的方案。

可以用捆绑法，把每堆4个人捆绑成一组，其他人每个人一组。这样一共有$n-3i$组(这些组可以被看成相同的点)。

我们从中选出n-4i个点，这些点展开成1个人，其他$i$个点展开成4个人。那么方案数就是$C_{n-3i}^{n-4i}$

由于$i$堆人的喜好已经确定，最终答案为$\sum_{i=0}^n (-1)^i  \times C_{n-3i}^{n-4i} \times (n-4i个单独的人的喜好方案数)$

那么我们就需要求n-4i个单独的人的喜好方案数。每种喜好的人各有$a-i,b-i,c-i,d-i$。假如这些人里每种喜好的人各有$x,y,z,w(x \leq a-i,y \leq b-i,z \leq c-i,w \leq d-i,x+y+z+w=n-4i)$个。这是一个有重复元素的排列问题。答案是$\frac{(n-4i)!}{x!y!z!w!}$

直接枚举的时间复杂度为$O(k^4)$,($k=\min(a,b,c,d)$),下同。显然会超时。我们可以用折半搜索的思想，先枚举前两个的个数$x,y$,把$\frac{1}{x!y!}$的和记录在$cnt[x+y]$中。然后枚举$z,w$,只要每次答案累加上$z!\times w! \times cnt[n-4i-(z+w)]$即可。时间复杂度$O(k^2)$

总时间复杂度$O(nk^2)$

### 代码

```cpp
//鸡你太美！
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define maxn 1000 
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
inline ll inv(ll x){
	return fast_pow(x,mod-2); 
}
int n,a,b,c,d;
ll fact[maxn+5],invfact[maxn+5];

void ini(){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
} 

inline ll C(ll n,ll m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod; 
} 

ll cnt[maxn+5];
int main(){
	scanf("%d",&n);
	scanf("%d %d %d %d",&a,&b,&c,&d);
	ini();
	int mx=min(min(a,b),min(c,d));
	ll ans=0;
	for(int i=0;i<=n/4&&i<=mx;i++){
		memset(cnt,0,sizeof(cnt));
		//可重排列((a+b+c+d)!)(a!b!c!d!)
		//类似中途相遇分两半求解 
		for(int j=0;j<=a-i;j++){
			for(int k=0;k<=b-i;k++){
				cnt[j+k]=(cnt[j+k]+invfact[j]*invfact[k]%mod)%mod;
			}
		}
		ll sum=0; 
		for(int j=0;j<=c-i;j++){
			for(int k=0;k<=d-i&&j+k<=n-4*i;k++){
				sum=(sum+cnt[n-4*i-(j+k)]*invfact[j]%mod*invfact[k]%mod)%mod;
			}
		}
		sum=sum*fact[n-4*i]%mod;
		
		
		//捆绑法，把4个一组的捆绑成1个,共n-3i个
		//再从中选出n-4i个单独1个的，其他展开
		//C(n-3i,n-4i) 
		ans+=fast_pow(-1,i)*C(n-3*i,n-4*i)*sum%mod;
		ans=(ans+mod)%mod; 
	} 
	printf("%lld\n",ans);
} 
```

