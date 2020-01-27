## [BZOJ 3456]城市规划(cdq分治+FFT)

### 题面

求有标号n个点无向连通图数目.

### 分析

设$f(i)$表示$i$个点组成的无向连通图数量,$g(i)$表示$i$个点的图的数量。

显然$g(i)=2^{C_i^2}$种，但是我们要把不联通的去掉。

枚举1号点所在联通块大小$j$.从剩下$i-1$个点里选$j-1$个点和1号点构成联通块，有$C_{i-1}^{j-1}$种选法.1号点所在联通块的连边方案有$f(i)$种，剩下$i-j$个点随便连边，有$g(i-j)$种

那么$$f(i)=g(i)-\sum_{j=1}^{i-1} C_{i-1}^{j-1} f(j)g(i-j)$$

把式子展开:

$$\begin{aligned} f(i) &= g(i)-\sum_{j=1}^{i-1} \frac{(i-1)!}{(i-j)!(j-1)!} f(j)g(i-j) \\ \frac{f(i)}{(i-1)!}&=\frac{g(i)}{(i-1)!}-\sum_{j=1}^{i-1} \frac{f(j)}{(j-1)!} \cdot \frac{g(i-j)}{(i-j)!}\end{aligned}$$

令$A(i)=\frac{f(i)}{(i-1)!},B(i)=\frac{g(i)}{i!},C(i)=\frac{g(i)}{(i-1)!}$

那么$$A(i)=C(i)-\sum_{j=1}^{i-1} A(j) B(i-j)$$

右边可以分治FFT。

----

#### 分治FFT的思路:

> 分治FFT的一般形式:
>
> 已知多项式$g$,且有$f(i)=\sum_{j=1}^if(i-j)g(j),f(0)=1 $,求$f$

 但是这里卷积内有一个f，f是未知的，就不能用常规的多项式乘法了。

我们可以引入cdq分治。假设我们在分治求$f[l...r]$,已经求出了$f[l...mid]$,只需要计算区间$[l,mid]$对区间$[mid+1,r]$的贡献.

考虑$x \in [mid+1,r]$,$f(x) = \sum _{i = 1} ^ {x} f(i) * g(x -  i)$

注意到$[1,l]$部分的贡献在之前的分治过程里已经计算过，不管。$f[mid+1,r]$还没有计算，暂且设为0.那左半边区间的贡献就是

$$\begin{aligned}
f(x) 
&= \sum _ {i = L} ^ {x} f(i)g(x - i) \\
&= \sum _ {i = 0} ^ {x - L} f(i + L)  g(x - L - i)
\end{aligned}$$

 那么我们可以把f的[l,mid]项拿出来，其他项置0，在把这个和g的[0,r−l]卷起来就可以得到贡献，然后加到f上就好了。 

```cpp
void cdq_divide(ll *f,ll *g,int l,int r){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	if(l==r) return; 
	int mid=(l+r)>>1;
	cdq_divide(f,g,l,mid);
	int tn=1,k=0;
	while(tn<r-l){
		k++;
		tn*=2; 
	}
	for(int i=0;i<tn;i++) tmpa[i]=tmpb[i]=0; 
	for(int i=l;i<=mid;i++) tmpa[i-l]=f[i];
	for(int i=1;i<=r-l;i++) tmpb[i-1]=g[i];
	mul(tmpa,tmpb,tmpa,tn);
	for(int i=mid+1;i<=r;i++) f[i]=(f[i]+tmpa[i-l-1])%mod;//注意第x项实际上是第x-l-1项
	cdq_divide(f,g,mid+1,r);
}
```



###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define G 3
#define invG 334845270
#define inv2 499122177
#define mod 1004535809
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
	static int rev[maxn+5];
	int tn=1;
	int k=0;
	while(tn<n){
		tn*=2;
		k++;
	}
	for(int i=0;i<tn;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	} 
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
		int invsz=inv(n);
		for(int i=0;i<n;i++) x[i]=x[i]*invsz%mod; 
	}
}
void mul(ll *a,ll *b,ll *ans,int sz){
	NTT(a,sz,1);
	NTT(b,sz,1);
	for(int i=0;i<sz;i++) ans[i]=a[i]*b[i]%mod;
	NTT(ans,sz,-1);
} 


void cdq_divide(ll *f,ll *g,int l,int r){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	if(l==r) return; 
	int mid=(l+r)>>1;
	cdq_divide(f,g,l,mid);
	int tn=1,k=0;
	while(tn<r-l){
		k++;
		tn*=2; 
	}
	for(int i=0;i<tn;i++) tmpa[i]=tmpb[i]=0; 
	for(int i=l;i<=mid;i++) tmpa[i-l]=f[i];
	for(int i=1;i<=r-l;i++) tmpb[i-1]=g[i];
	mul(tmpa,tmpb,tmpa,tn);
	for(int i=mid+1;i<=r;i++) f[i]=(f[i]-tmpa[i-l-1]+mod)%mod;
	cdq_divide(f,g,mid+1,r);
}

int n;
ll f[maxn+5],g[maxn+5];
ll fact[maxn+5]; 
ll invfact[maxn+5];
ll get_g(ll n){
	return fast_pow(2,n*(n-1)/2);
}
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
int main(){
//	printf("%lld\n",inv(3));
	scanf("%d",&n);
	ini(n); 
	int tn=1; 
	for(int i=1;i<=n;i++) f[i]=get_g(i)*invfact[i-1]%mod; //初始值C(i)
	for(int i=1;i<=n;i++) g[i]=get_g(i)*invfact[i]%mod;
	while(tn<=n) tn*=2;
	cdq_divide(f,g,0,tn-1);
//	for(int i=0;i<n;i++) printf("%lld ",f[i]); 
	printf("%lld\n",f[n]*fact[n-1]%mod); 
} 
```

