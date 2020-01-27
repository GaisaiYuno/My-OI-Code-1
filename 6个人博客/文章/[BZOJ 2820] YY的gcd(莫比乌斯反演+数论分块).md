### [BZOJ 2820] YY的gcd(莫比乌斯反演+数论分块)

### 题面

给定N, M,求$1\leq x\leq N, 1\leq y\leq M$且gcd(x, y)为质数的(x, y)有多少对。q组询问

### 分析

我们要求的是

$$\sum_{p \in P} \sum_{i=1}^n \sum_{j=1}^m [gcd(i,j)=p]$$(大写P表示质数集合)

根据$kgcd(i,j)=gcd(ki,kj)$,

$$原式=\sum_{p \in P} \sum_{i=1}^{\lfloor n/p \rfloor} \sum_{j=1}^{\lfloor m/p \rfloor} [gcd(i,j)=1]$$

又根据莫比乌斯反演里的一个常用结论(证明见[ BZOJ 2301](https://www.cnblogs.com/birchtree/p/11355045.html))$$\sum_{i=1}^n \sum_{j=1}^m [gcd(i,j)=1]= \sum_{d=1}^{min(n,m)} \mu(d ) \lfloor \frac{n}{d} \rfloor  \lfloor \frac{m}{d} \rfloor$$

$$原式=\sum_{p \in P} \sum_{d=1}^{min( \lfloor n/p \rfloor, \lfloor m/p \rfloor)} \mu(d) \lfloor \frac{n}{pd} \rfloor \lfloor \frac{m}{pd} \rfloor $$

令$T=pd$,则$d=\frac{T}{p}$

改变求和顺序，$$原式=\sum_{T=1}^{min(n,m)} \sum_{p|t \ \cap \ p \in P} \lfloor \frac{n}{T} \rfloor \lfloor \frac{m}{T} \rfloor \mu(\frac{T}{p})$$

$$=\sum_{T=1}^{min(n,m)}) \lfloor \frac{n}{T} \rfloor \lfloor \frac{m}{T} \rfloor  \sum_{p|t \ \cap \ p \in P}  \mu(\frac{T}{p})$$

令$g(n)=\sum_{p|n \ \cap \ p \in P } \mu(\frac{n}{p})$

$$原式=\sum_{T=1}^{min(n,m)}) \lfloor \frac{n}{T} \rfloor \lfloor \frac{m}{T} \rfloor g(T)$$

前面的部分可以数论分块求解，考虑如何快速求出$g(T)$

对于每个质数$p$,我们从1开始枚举$j$，并保证$jp \leq n$,然后用$\mu(j)$更新$\mu (jp)$的值。

由于$1/1+1/2+1/3+...+1/n=O(logn)$,每次更新的复杂度是均摊$O(\log n)$的，而1~n的质数约概有$\frac{n}{\ln n}$个，所以预处理g函数的总时间复杂度为$O(n)$

总时间复杂度$O(n+q\sqrt n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 10000000
using namespace std;
typedef long long ll;
int t,n,m;
int cnt;
int prime[maxn+5];
bool vis[maxn+5];
int mu[maxn+5];
ll g[maxn+5];
ll sumg[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i]=-1;
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j*prime[i]<=n;j++){
			g[prime[i]*j]+=mu[j];
		}
	}
	for(int i=1;i<=n;i++){
		sumg[i]=sumg[i-1]+g[i];
	}
} 

int cas;
ll calc(int n,int m){
	int nn=min(n,m);
	ll ans=0;
	for(int l=1,r;l<=nn;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sumg[r]-sumg[l-1])*(n/l)*(m/l);
	}
	return ans;
}
int main(){
	sieve(maxn);
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&n,&m);
		printf("%lld\n",calc(n,m));
	}
}
```

