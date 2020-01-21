## [BZOJ 2301] [HAOI 2011] Problem b (莫比乌斯反演)(有证明)

### 题面

T组询问，每次给出a,b,c,d,k,求$\sum _{i=a}^b\sum _{j=c}^d[gcd(i,j)=k]$

$T,a,b,c,d,k\le 5\times 10^4$

### 分析

$O(n^2)$暴力显然是不可行的，我们考虑优化。

首先易得$k\times gcd(i,j)=gcd(ki,kj)$,那么我们可以把a,b,c,d都除上k,问题就变成了$\sum _{i=a/k}^{b/k}\sum _{j=c/k}^{d/k}[gcd(i,j)=1]$(之后的除法若未说明，均为下去整)

差分一下，我们只要求出$\sum_{i=1}^n \sum_{j=1}^m [gcd(i,j)=1]$，然后二维前缀和相减一下就可以了



#### 1.运用狄利克雷卷积证明

以下为预备知识，掌握的可以跳过

>定义:
>
>单位函数$\varepsilon\left(i\right)=\left[i=1\right]$,
>
>常函数$I(i)=1$
>
>狄利克雷卷积$\left(g\ast f\right)\left(i\right)=F$表示$F\left(i\right)=\sum_{d|i}g\left(d\right)f\left(\frac id\right)$
>
>
>
>那么我们有以下结论$\left(\mu\ast I\right)=\varepsilon$,即$\varepsilon (n)= \sum _{d|n}  \mu(n)$.
>
>证明：
>
>$n=1$时显然成立
>
>$n >1$时，设n的质因数分解$\sum_{i=1}^{t} p_i^{k_i}$,d就是在这里面选择一些质因子乘起来的情况。只有选的质因子指数为1的时候才会对答案有1或-1的贡献，取决于。那么问题就转换成在t个数中选0,1,2,3...个数的方案数。答案为$C_{t}^0-C_{t}^1+C_{t}^2-C_{t}^3 \dots= \sum_{i=1}^t (-1)^{i-1}C_{t}^i=\sum_{i=0}^{t} (1)^{t-i}(-1)^i C_{t}^i=(1-1)^t=0$.倒数第二步用到了二项式定理。所以$ \sum _{d|n}  \mu(n)=0=\varepsilon (n)$

根据结论$\left(\mu\ast I\right)=\varepsilon$,即$\varepsilon (n)= \sum _{d|n}  \mu(n)$,我们可以化简问题式子

由定义知$\epsilon(x)=[x=1]$

$$\sum_{i=1}^n \sum_{j=1}^m [gcd(i,j)=1]=\sum_{i=1}^n \sum_{j=1}^m \varepsilon(gcd(i,j))=\sum_{i=1}^n \sum_{j=1}^m \sum_{d|gcd(i,j)} \mu(d)$$ 

变换求和顺序，先枚举$d|gcd(i,j)$,

$$\sum_{d=1}^n \mu(d) \sum_{i=1}^n [d|i] \sum_{j=1}^m [d|j]$$,

其中$[d|i]$表示i为d的倍数的时候i才会对答案有贡献

显然1~n中d的倍数有n/d个

最终答案为$$\sum_{d=1}^{min(n,m)} \mu(d) \lfloor \frac{n}{d} \rfloor \lfloor \frac{m}{d} \rfloor$$



#### 2.运用莫比乌斯反演的第二种形式证明

莫比乌斯反演的第二种形式是

若$F(n) =\sum _{n|d} f(d)$,那么$f(n)= \sum_{n|d} \mu(d) F(\lfloor \frac{d}{n} \rfloor)$

这里d表示n的倍数

既然要用到莫比乌斯反演，我们首先就要找到合适的F和f

设

$f(x)=\sum_{i}^x [gcd(x,i)=i]$,(gcd为x的(x,y)的对数)

$F(x)= \sum_{i} [x |gcd(x,i)]$, (gcd为x或x的倍数的(x,y)的对数)

虽然这看起来是无限求和，但我们实际上求到min(n,m)就可以了，因为gcd(i,j)(i<n,j<m)不可能超过i,j中的最小值。

显然$F(x)=\sum f(i) $(i是x的倍数)，因为gcd(x,i)能整除x，那i一定能整除x。

既然F，f满足上面的条件，我们就可以大力反演了

$$f(x)= \sum_{x|d} \mu(d) F(\lfloor \frac{d}{x} \rfloor)$$

注意到$F(x)= \sum_{i} [x |gcd(x,i)]= \lfloor \frac{n}{x} \rfloor \lfloor \frac{m}{x} \rfloor$,因为gcd(i,j)为x的倍数，那么i,j一定都被x整除，显然1~n中x的倍数有n/x个

我们求的答案实际上是f(1)

$$f(1)= \sum_{1|d} \mu(d) F(\lfloor \frac{d}{1} \rfloor)= \sum_{d=1}^{min(n,m)} \mu(d) F(d)= \sum_{d=1}^{min(n,m)} \mu(d)  \lfloor \frac{n}{d} \rfloor \lfloor \frac{m}{d} \rfloor$$



两种方法殊途同归，都求出了最终答案$$\sum_{d=1}^{min(n,m)} \mu(d)  \lfloor \frac{n}{d} \rfloor \lfloor \frac{m}{d} \rfloor$$

#### 数论分块优化

暴力枚举求解$$\sum_{d=1}^n \mu(d) \lfloor \frac{n}{d} \rfloor \lfloor \frac{m}{d} \rfloor$$的复杂度为$O(n)$,仍然较高，观察到d比较大的时候n/d的值变化不大，如n=6时n/4=n/5=n/6.

因此我们可以找出所有下取整值相同的区间[l,r],再用$\lfloor \frac{n}{l} \rfloor\sum_{i=l}^r \mu(d) $就可以求出答案，求和部分可以前缀和预处理。对于一个块，**假设它的起始位置的下标为l，那么可以得到的是，它的结束位置的下标为n/(n/l)**

这样的复杂度是$O(\sqrt n)$的,T次询问复杂度为$O(T\sqrt n)$,可以通过本题

```cpp
long long ans=0;
int l,r;
for(l=1;l<=m;l=r+1){
	r=min(n/(n/l),m/(m/l));
    ans+=(sum_mu[r]-sum_mu[l-1])*(n/l)*(m/l);
}
```



### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000
using namespace std;
typedef long long ll;
int cnt;
bool vis[maxn+5];
int prime[maxn+5];
int mu[maxn+5];
ll sum_mu[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;i++) sum_mu[i]=sum_mu[i-1]+mu[i];
}

int t;
int a,b,c,d,e;
ll solve(int n,int m){
	n/=e;
	m/=e;
	if(n<m) swap(n,m);
	ll ans=0;
	int l,r;
	for(l=1;l<=m;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sum_mu[r]-sum_mu[l-1])*(n/l)*(m/l);
	}
	return ans;
}

int main(){
	sieve(maxn);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		ll ans=solve(b,d)-solve(a-1,d)-solve(b,c-1)+solve(a-1,c-1);
		printf("%lld\n",ans);
	}
}
```

