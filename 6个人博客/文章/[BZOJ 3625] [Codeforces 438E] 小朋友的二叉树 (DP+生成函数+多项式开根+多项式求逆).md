## [BZOJ 3625] [Codeforces 438E] 小朋友的二叉树 (DP+生成函数+多项式开根+多项式求逆)

### 题面

 一棵二叉树的所有点的点权都是给定的集合中的一个数。
让你求出1到m中所有权值为i的二叉树的个数。
两棵树不同当且仅当树的形态不一样或者是树的某个点的点权不一样 

###  分析

设$c(i)$表示数值i是否在集合中。$f(i)$表示权值为i的二叉树的个数。那么

$$f(n)=\sum_{i=1}^n c(i) \sum_{j=0}^{n-i} f(j)f(n-i-j)$$

其中$i$表示根节点的权值，那么左右子树的权值和为$n-i$,枚举左右子树分别的权值$j,n-i-j$，为$\sum_{j=0}^{n-i} f(j)f(n-i-j)$

我们把式子化成卷积的形式,设$F,C$为$f,c$的生成函数

$F(x)=F(x)^2C(x)+1$

解函数方程，得:

$$F(x)=\frac{1 \pm {\sqrt {1-4C(x)}} }{ 2C(x)}=\frac{2}{1 \mp \sqrt{1-4C(x)}}$$

如果符号取-，那么x=0时分母为0无意义。

因此$F(x)=\frac{2}{1+\sqrt{1-4C(x)}}$

 多项式开方和多项式求逆即可。 

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 400000
#define G 3
#define invG 332748118
#define inv2 499122177
#define mod 998244353
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

void get_inv(ll *a,ll *b,int n){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	b[0]=inv(a[0]);
	int len;
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++){
			tmpa[i]=a[i];
			tmpb[i]=b[i];
		}
		NTT(tmpa,sz,1);
		NTT(tmpb,sz,1);
		for(int i=0;i<sz;i++) b[i]=tmpb[i]*(2-tmpb[i]*tmpa[i]%mod+mod)%mod;
		NTT(b,sz,-1);
		for(int i=len;i<sz;i++) b[i]=0;
	}
	for(int i=0;i<len;i++) tmpa[i]=tmpb[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

void get_sqrt(ll *a,ll *b,int n){
	static ll tmpa[maxn+5],invb[maxn+5];
	b[0]=1;
	int len;
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++) tmpa[i]=a[i];
		get_inv(b,invb,len);
		mul(tmpa,invb,tmpa,sz);
		for(int i=0;i<len;i++) b[i]=inv2*(tmpa[i]+b[i])%mod;
		for(int i=len;i<sz;i++) b[i]=0;
	} 
	for(int i=0;i<len;i++) tmpa[i]=invb[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

int n,m;
ll c[maxn+5],sqtc[maxn+5],isqtc[maxn+5];
int main(){
	int x; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		c[x]++;
	}
	int dn=1;
	while(dn<=m) dn*=2; 
	for(int i=1;i<dn;i++) c[i]=((-4)*c[i]+mod)%mod;
	c[0]++;//sqrt(1-4C)
	get_sqrt(c,sqtc,dn);
	sqtc[0]++;//1+sqrt(1-4C)
	get_inv(sqtc,isqtc,dn);
	for(int i=0;i<=m;i++) isqtc[i]=isqtc[i]*2%mod;//2/(1+sqrt(1-4C)
	for(int i=1;i<=m;i++) printf("%lld\n",isqtc[i]);
} 
```

