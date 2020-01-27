## [BZOJ 3944]sum(杜教筛)

### 题面

求$\mu$和$\varphi$的前缀和

### 分析

套路公式:

> 我们要求$f$的前缀和,构造两个函数$g,h$满足$h=f*g$, $F,G,H$为它们的前缀和
>
> $$g(1)F(n)=H(n)-\sum_{d=2}^n g(d) F(\frac{n}{d})$$

如果$f=\mu$,注意到$\mu*I=\varepsilon$,那么$g(n)=I(n)=1,h(n)=\varepsilon(n),H(n)=\varepsilon(1)=1$

代入得$F(n)=1-\sum_{d=2}^n F(\frac{n}{d})$



如果$f=\varphi$,注意到$\varphi * I=id$,那么$g(n)=I(n)=1,h(n)=n,H(n)=\sum_{i=1}^ni=\frac{n(n+1)}{2}$

代入得$F(n)=\frac{n(n+1)}{2}-\sum_{d=2}^n F(\frac{n}{d})$



然后记忆化搜索，用map记录答案,求和的部分用数论分块

注意两个前缀和最好一起筛，要不会TLE

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 2000000
using namespace std;
typedef long long ll;
int cnt;
bool vis[maxn+5];
int prime[maxn+5];
int phi[maxn+5];
int mu[maxn+5];
ll sum_phi[maxn+5]; 
ll sum_mu[maxn+5];
void sieve(int n){
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i]=-1;
			phi[i]=i-1;
			prime[++cnt]=i; 
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else{
				mu[i*prime[j]]=-mu[i];
				phi[i*prime[j]]=phi[i]*phi[prime[j]]; 
			}
		}
	}
	for(int i=1;i<=n;i++) sum_mu[i]=sum_mu[i-1]+mu[i];
	for(int i=1;i<=n;i++) sum_phi[i]=sum_phi[i-1]+phi[i]; 
}

int t;
ll n; 
map<ll,ll>ans_mu;
map<ll,ll>ans_phi;
struct node{
	ll phi;
	ll mu;
	node(){
		
	}
	node(ll _phi,ll _mu){
		phi=_phi;
		mu=_mu;
	}
};
node dujiao_sieve(ll n){
	if(n<=maxn) return node(sum_phi[n],sum_mu[n]);
	if(ans_phi.count(n)) return node(ans_phi[n],ans_mu[n]);
	ll ans1=n*(n+1)/2,ans2=1;
	node tmp;
	for(ll l=2,r;l<=n;l=r+1){
		r=n/(n/l);
		tmp=dujiao_sieve(n/l);
		ans1-=(r-l+1)*tmp.phi;
		ans2-=(r-l+1)*tmp.mu; 
	} 
	ans_phi[n]=ans1;
	ans_mu[n]=ans2;
	return node(ans1,ans2);
}
int main(){
	sieve(maxn+5);
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		node ans=dujiao_sieve(n);
		printf("%lld %lld\n",ans.phi,ans.mu);
	}
}
```

