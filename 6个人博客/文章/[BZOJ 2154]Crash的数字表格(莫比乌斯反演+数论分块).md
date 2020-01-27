## [BZOJ 2154]Crash的数字表格(莫比乌斯反演+数论分块)

### 题面

求

$$\sum_{i=1}^{n} \sum_{j=1}^{m} \mathrm{lcm}(i,j)$$

### 分析

$$\sum_{i=1}^{n} \sum_{j=1}^{m} \mathrm{lcm}(i,j)$$

$$=\sum_{i=1}^{n} \sum_{j=1}^{m} \frac{i j}{\mathrm{gcd}(i, j)}$$

$$=\sum_{g=1}^{n} \sum_{i=1}^{n/g} \sum_{j=1}^{m/g} \frac{ig \times jg}{g}[\gcd(i,j)=1] \ \ \ (改变求和顺序，先枚举g,i相当于之前的i/g,j相当于j/g,所以gcd(i,j)=1)$$

$$=\sum_{g=1}^{n}g\sum_{i=1}^{n/g} \sum_{j=1}^{m/g} i j[gcd(i,j)=1]\ \ \ (把g提到外面)$$



令$$f(x)=\sum_{i=1}^{n/g} \sum_{j=1}^{m/g} ij[gcd(i,j)=x]$$

莫比乌斯反演的套路,$$F(x)=\sum_{i=1}^{n/g} \sum_{j=1}^{m/g} ij[x|gcd(i,j)]$$

$\because x|gcd(i,j),\therefore i|x,j|x$

$$\therefore F(x)=\sum_{i|x}^{n/g} \sum_{j|x}^{m/g}ij=x^2\sum_{i=1}^{\frac{n}{gx}} \sum_{j=1}^{\frac{m}{gx}} ij=x^2\sum_{i=1}^{\frac{n}{gx}} i\sum_{j=1}^{\frac{m}{gx}} j$$

用等差数列求和公式可以$O(1)$求出，这里为了形式美观先不展开

显然$F,f$满足莫比乌斯反演的倍数形式,$F(n)=\sum_{n|d}f(d)$

因此$f(n)=\sum_{n|d} F(d)\mu(\frac{d}{n})$

我们要求的是$f(1)$

$$f(1)=\sum_{1|d}F(d) \mu(d)=\sum_{d=1}^{n/g} F(d) \mu(d)=\sum_{d=1}^n \mu(d) d^2 \sum_{i=1}^{\frac{n}{gd}} i\sum_{j=1}^{\frac{m}{gd}} j$$

$$ \therefore 原式=\sum_{g=1}^{n} g \sum_{d=1}^{n} \mu(d) d^{2} \sum_{i=1}^{\frac{n}{gd}} i \sum_{j=1}^{\frac{m}{gd}}  j$$

$$=\sum_{g=1}^{n} g \sum_{d=1}^{n/g} \mu(d) d^{2} \frac{\frac{n}{gd}\left(\frac{gn}{d}+1\right)}{2} \cdot \frac{\frac{m}{gd}\left(\frac{m}{gd}+1\right)}{2} \ \ \ (等差数列求和公式)$$



看起来时间复杂度是$O(n^2)$的，但我们只要线性筛出$\mu(d)d^2$,两层求和其实都可以数论分块求解，时间复杂度$O(\sqrt{n}\times \sqrt{n})=O(n)$



###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10000000
#define mod 20101009//不是1e9+7!!! 
using namespace std;
typedef long long ll;
int cnt;
bool vis[maxn+5];
int prime[maxn+5];
int mu[maxn+5];
ll sumg[maxn+5];//g(n)=n*n*mu(n)
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
	for(int i=1;i<=n;i++) sumg[i]=(sumg[i-1]+(ll)i*i%mod*mu[i]%mod)%mod;
}
 
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

ll n,m;
ll inv2;
inline ll S(ll n){
	return n*(n+1)%mod*inv2%mod;
}
ll calc(int n,int m){//其实就是f(x)
	ll ans=0;
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sumg[r]-sumg[l-1])*S(n/l)%mod*S(m/l)%mod;
		ans=(ans+mod)%mod;//注意mu可能为负数 
	}
	return ans;
}

int main(){
	sieve(maxn);
	inv2=inv(2);
	scanf("%lld %lld",&n,&m);
	if(n>m) swap(n,m);
	ll ans=0;
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(ll)(l+r)*(r-l+1)%mod*inv2%mod*calc(n/l,m/l)%mod;
		ans=(ans+mod)%mod;
	} 
	printf("%lld\n",ans);
}
```



