## [BZOJ5306] [HAOI2018]染色(容斥原理+NTT)

### 题面

一个长度为 n的序列, 每个位置都可以被染成 m种颜色中的某一种.

如果n个位置中恰好出现了 S次的颜色有 K种, 则小 C 会产生 $W_k$的愉悦度.

求对于所有可能的染色方案, 他能获得的愉悦度的和。答案对 1004535809 取模

### 分析

显然颜色数量不超过$tot=\min(m,\frac{n}{S})$

我们需要求出现了$S$次的颜色有$i$种的方案数。这个东西不太好求，考虑容斥，求出现了$S$次的颜色有**至少**$i$种的方案数,记为$t(i)$

我们先从$m$种颜色里选出$i$种颜色，方案数$C_m^i$

然后从$n$个位置里选出$S$个位置，涂上颜色1。从剩下$n-S$个位置里选出$S$个位置，涂上颜色2。从剩下$n-2S$个位置里选出$S$个位置，涂上颜色3......从从剩下$n-(i-1)S$个位置里选出$S$个位置，涂上颜色i. 方案数为:

$$\begin{aligned} &= C_n^S \cdot C_{n-S}^S \cdot C_{n-2S}^S \dots C_{n-(i-1)S}^S \\ &=\frac{n!}{S!(n-S)!} \cdot \frac{(n-S)!}{S!(n-2S)!} \cdot \frac{(n-2S)!}{S!(n-3S)!} \dots \frac{(n-(i-1)S)!}{S!(n-iS)!} \\ &=\frac{n!}{(S!)^i (n-iS)!} (上式左边的分母可以和右边的分子消掉)\end{aligned}$$

这样涂完色之后还有$n-iS$个位置没涂，剩下$m-i$种颜色没用，方案数为$(m-i)^{n-iS}$

因此，

$$t(i)=C_m^i \frac{n!}{(S!)^i (n-iS)!} (m-i)^{n-iS}$$

然后加上容斥,最终答案$ans(i)$为

$$\begin{aligned} ans(i)&=\sum_{j=i}^{tot} (-1)^{j-i} C_{j}^{i} t(j) \\ &=\sum_{j=i}^{tot} (-1)^{j-i} \frac{j!}{i!(j-i)!}t(j) \\ ans(i)i! &=\sum_{j=i}^{tot} \frac{(-1)^{j-i}}{(j-i)!} \cdot t(j)j! \end{aligned}$$

令$A(i)=t(i)i!,B(i)=\frac{(-1)^{j-i}}{(j-i)!}$

$$ans(i)i!=\sum_{j=i}^{tot} A(j) B(j-i)$$

由于$j+j-i$不是常数，不能直接卷积。类似[ [ZJOI2014]力 ](https://www.cnblogs.com/birchtree/p/11716251.html)，把B反转就能卷积了.

令$B'(j)=B(tot-j)$,则$B(j-i)=B'(tot-j+i)$

$$ans(i)i!=\sum_{j=i}^{tot} A(j) B'(tot-j+i)$$

由于$tot-j+i+j=tot+i$为一常数，符合卷积的特征。注意最后的$ans(i)i!$实际上是$A$和$B'$卷积得到的多项式第$tot+i$项。最后别忘了除以$i!$并乘上$W_i$

### 代码

```cpp
//https://www.luogu.org/problem/P4491 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 10000000
#define maxm 400000
#define G 3
#define mod 1004535809
#define invG 334845270
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
void NTT(ll *x,int n,int type){
	static int rev[maxm+5];
	int tn=1,k=0;
	while(tn<n){
		tn*=2;
		k++; 
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]); 
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		ll gn1=fast_pow((type==1?G:invG),(mod-1)/sz);
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			ll gnk=1;
			for(int i=l;i<=r;i++){
				ll tmp=x[i+len];
				x[i+len]=(x[i]-gnk*tmp%mod+mod)%mod;
				x[i]=(x[i]+gnk*tmp%mod)%mod;
				gnk=gnk*gn1%mod; 
			}
		}
	} 
	if(type==-1){
		ll invn=inv(n);
		for(int i=0;i<n;i++) x[i]=x[i]*invn%mod; 
	}
} 
void mul(ll *a,ll *b,ll *ans,int n){
	NTT(a,n,1);
	NTT(b,n,1);
	for(int i=0;i<n;i++) ans[i]=a[i]*b[i]%mod;
	NTT(ans,n,-1);
}

ll fact[maxn+5],invfact[maxn+5];
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
} 

int n,m,s;
ll w[maxm+5]; 
ll a[maxm+5],b[maxm+5],sum[maxm+5];
int main(){
//	printf("%lld\n",inv(3));
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<=m;i++) scanf("%lld",&w[i]);
	ini_fact(max(n,m)); 
	int lim=min(n/s,m);
	int dn=1;
	while(dn<=(lim+1)*2) dn*=2;
	for(int i=0;i<=lim;i++){
		a[i]=C(m,i)*fact[n]%mod*inv(fast_pow(fact[s],i))%mod*invfact[n-s*i]%mod*fast_pow(m-i,n-s*i)%mod*fact[i]%mod; 
		//f(x)=C(m,i)*(n!)/((s!)^i(n-si)!)*(m-i)^(n-si) 
		//A(x)=f(x)x!
	}
	for(int i=0;i<=lim;i++){
		b[i]=(fast_pow(-1,lim-i)*invfact[lim-i]%mod+mod)%mod;
		//B(x)=(-1)^x/x!
		//类似[ZJOI2014]力,要把B反转
	}
	mul(a,b,sum,dn);
	ll ans=0;
	for(int i=0;i<=lim;i++){
		ans=(ans+sum[i+lim]*invfact[i]%mod*w[i]%mod)%mod;
	}
	printf("%lld\n",ans); 
} 
```

