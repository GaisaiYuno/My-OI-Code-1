## [BZOJ 3992] [SDOI 2015] 序列统计(DP+原根+NTT)

### 题面

 小C有一个集合S，里面的元素都是小于**质数**M的非负整数。他用程序编写了一个数列生成器，可以生成一个长度为N的数列，数列中的每个数都属于集合S。小C用这个生成器生成了许多这样的数列。但是小C有一个问题需要你的帮助：给定整数x，求所有可以生成出的，且满足数列中所有数的乘积mod M的值等于x的不同的数列的有多少个。小C认为，两个数列{Ai}和{Bi}不同，当且仅当至少存在一个整数i，满足Ai≠Bi。另外，小C认为这个问题的答案可能很大，因此他只需要你帮助他求出答案mod 1004535809的值就可以了。

### 分析

设$dp[i][j]$表示长度为i,所有数的乘积modM的值为j的序列个数,那么可以写出转移方程:

$$dp[2 \cdot i][j]=\sum_{ab=j(\mathrm{mod}\ m)} dp[i][a] \cdot dp[i][b]$$

发现乘法不好处理，如果没有模意义，直接取个对数$\ln a+ \ln b =\ln j$,就是卷积了

> **定理:** 假设g是奇素数p的一个原根，则$g^1,g^2 \cdot g^{p-1} $在模p意义下两两不同，且结果恰好为1~p-1 

那么我们可以把$a,b$用原根表示,$a=g^x,b=g^y,j=g^z$.这里的$x,y$实际上就是$a,b$的**离散对数**.关于离散对数的严格定义，这里不再赘述，只需要感性理解即可.

那么$g^x g^y \equiv g^z (\mathrm{mod}\ m)$

$\therefore g^{x+y} \equiv g^z (\mathrm{mod}\ m)$

因为$m$是质数，根据费马小定理$g^{m-1} \equiv 1 (\mathrm{mod}\ m)$

因此$g^{x+y} \equiv g^{(x+y) \mod (m-1)} (\mathrm{mod}\ m)$

因此$x+y \equiv z (\mathrm{mod}\ m-1)$

这样就可以把式子转化成卷积。注意到每一层的转移是一样的，可以用类似快速幂的方法，进行多项式快速幂.

```cpp
void poly_pow(ll *x,ll *ans,int k,int sz){
	ans[0]=1;
	while(k){
		if(k&1) mul(ans,x,ans,sz);
		mul(x,x,x,sz);
		k>>=1;
 	}
}
```



还要注意每次要把卷积结果中指数大于m-1的项移到前面

```cpp
NTT(tmpa,sz,1);
	NTT(tmpb,sz,1);
	for(int i=0;i<sz;i++) ans[i]=tmpa[i]*tmpb[i]%mod;
	NTT(ans,sz,-1);
	for(int i=sz-1;i>=m-1;i--){
		ans[i%(m-1)]+=ans[i];
		ans[i%(m-1)]%=mod;
		ans[i]=0;//注意指数取模m-1 
	}
```

-----

另外，由于原根一般很小，求一个数m的原根可以暴力枚举。

对$\varphi(n)$素因子分解,设$\varphi(n)=\Pi_{i=1}^{k}{p_i}^{a_i}, p为质数$

从小到大枚举$g$，若$\forall p_i,\ g^{\frac{\varphi(n)}{p_i}} \ne 1(mod \ n)$,则$g$就是$n$的原根

```cpp
inline int get_root(int x){
	static ll p[maxn+5];//分解质因数
	int cnt=0; 
	ll phi=x-1;
	for(int i=2;phi!=1;i++){
		if(phi%i==0) p[++cnt]=i;
		while(phi%i==0) phi/=i;
	}
	for(int i=2;;i++){
		bool flag=1;
		for(int j=1;j<=cnt;j++){
			if(fast_pow(i,(x-1)/p[j],x)==1){//注意是模m不是模mod 
				flag=0;
				break; 
			}	 
		}
		if(flag) return i;
	}
	return -1;
}
```

在代码实现中，需小心当前过程到底要取模哪个模数，本题里有3个模数.

- 乘积的时候模m
- 离散对数求和模m-1
- 方案数模1004535809

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define G 3
#define mod 1004535809
#define invG 334845270
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k,ll m){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%m;
		x=x*x%m;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x,ll m){
	return fast_pow(x,m-2,m); 
}

void NTT(ll *x,int n,int type){
	static int rev[maxn+5];
	int tn=1,k=0;
	while(tn<n){
		tn*=2;
		k++; 
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]); 
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		ll gn1=fast_pow((type==1?G:invG),(mod-1)/sz,mod);
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
		ll invn=inv(n,mod);
		for(int i=0;i<n;i++) x[i]=x[i]*invn%mod; 
	}
} 

int n,m,C,S,g;
int a[maxn+5];
int lg[maxn+5];
ll f[maxn+5],ans[maxn+5];
inline int get_root(int x){
	static ll p[maxn+5];//分解质因数
	int cnt=0; 
	ll phi=x-1;
	for(int i=2;phi!=1;i++){
		if(phi%i==0) p[++cnt]=i;
		while(phi%i==0) phi/=i;
	}
	for(int i=2;;i++){
		bool flag=1;
		for(int j=1;j<=cnt;j++){
			if(fast_pow(i,(x-1)/p[j],x)==1){//注意是模m不是模mod 
				flag=0;
				break; 
			}	 
		}
		if(flag) return i;
	}
	return -1;
}

void mul(ll *a,ll *b,ll *ans,int sz){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	for(int i=0;i<m;i++){
		tmpa[i]=a[i];
		tmpb[i]=b[i];
	}
	for(int i=m;i<sz;i++) tmpa[i]=tmpb[i]=0;
	NTT(tmpa,sz,1);
	NTT(tmpb,sz,1);
	for(int i=0;i<sz;i++) ans[i]=tmpa[i]*tmpb[i]%mod;
	NTT(ans,sz,-1);
	for(int i=sz-1;i>=m-1;i--){
		ans[i%(m-1)]+=ans[i];
		ans[i%(m-1)]%=mod;
		ans[i]=0;//注意指数取模m-1 
	}
}
void poly_pow(ll *x,ll *ans,int k,int sz){
	ans[0]=1;
	while(k){
		if(k&1) mul(ans,x,ans,sz);
		mul(x,x,x,sz);
		k>>=1;
 	}
}


int main(){
#ifdef LOCAL
	freopen("1.in","r",stdin); 
#endif
	scanf("%d %d %d %d",&n,&m,&C,&S);
	g=get_root(m);
	for(int i=0,x=1;i<m-1;i++){
		lg[x]=i;
		x=x*g%m;
	}
	for(int i=1;i<=S;i++){
		scanf("%d",&a[i]);
		a[i]%=m;
		if(a[i]!=0) f[lg[a[i]]]=1;
	}
	int dn=1;
	while(dn<=2*(m-1)) dn*=2;
	poly_pow(f,ans,n,dn);
	printf("%lld\n",ans[lg[C]]); 
}
```

