## [Codeforces 1295F]Good Contest(DP+组合数学)

### 题面

有一个长度为$n$的整数序列,第$i$个数的值在$[l_i,r_i]$中随机产生。问这个序列是一个不上升序列的概率(模$998244353$意义下)。

$n \leq 50,l_i,r_i \leq 998244351$

### 分析

和[[APIO2016]划艇](https://www.luogu.com.cn/problem/P3643)几乎一模一样。可惜比赛的时候时间不够。

首先把问题转化成求最长不上升序列的数量。

我们把这些区间离散化,分割成两两之间不互相覆盖的若干个区间，把这些分割后的区间从被拆分成编号在$[l_i,r_i)$的新区间。如原来的区间为$[1,4],[2,3],[4,5]$.那么拆分出来的新区间有$1:[1,1],2:[2,3],3:[4,4],4:[5,5]$.而新的$l_i,r_i$对应为$[1,3),[2,3),[3,5)$.下面的代码实现了该过程.

```cpp
void discrete(){
	dn=0;
	for(int i=1;i<=n;i++){
		tmp[++dn]=a[i].l;
		tmp[++dn]=a[i].r+1;//转成开区间 
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(tmp+1,tmp+1+dn,a[i].l)-tmp;
		a[i].r=lower_bound(tmp+1,tmp+1+dn,a[i].r+1)-tmp;
	}
}
```



设$dp[i][j]$表示前$i$个数,第$i$个数在第$j$个新区间或之后的新区间内的方案数。那么从前面转移过来时的区间编号一定$\geq j$. 于是可以写出转移方程:

$$dp[i][j]=\sum_{1 \leq k \leq i,j \in[l_k,r_k] } dp[k-1][j+1] \times C_{i-k+len(j)}^{i-k+1}$$

我们枚举最前面的与$i$在同一个新区间$j$的位置$k$, 那么 比$k$小的位置所在区间编号一定$>j$,所以乘上$dp[k-1][j+1]$. 而$len(j)$表示的是第$j$个新区间的实际长度,组合数表示的是从区间$j$里选出$i-k+1$个递增的数.即把$r-l+1$分为$i-k+1$份可以为0的数,从小到大排序,再加上左端点$l$就可以得到递增区间内的数。根据插板法公式,为$C_{len(j)+i-k+1-1}^{}$

注意到上面的转移方程只求出了第$i$个数恰好在区间$j$里的方案数。所以枚举完$j$后还要求一遍后缀和。

最终答案为$\frac{dp[n][1]}{\prod_{i=1}^n (r_i-l_i+1)}$

dp转移的复杂度为$O(n^3)$,但是由于$len(j)$比较大而$i-k+1$比较小.,求组合数需要$O(n)$的时间枚举。总复杂度为$O(n^4)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll fact[maxn+5],invfact[maxn+5],invx[maxn+5];
void ini_inv(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		invx[i]=invfact[i]*fact[i-1]%mod;
	}
}
inline ll C(ll n,ll m){
	ll ans=1;
	for(int i=n;i>=n-m+1;i--) ans=ans*i%mod;
	for(int i=1;i<=m;i++) ans=ans*invx[i]%mod;
	return ans;
}
int n;
struct seg{
	int l;
	int r;
}a[maxn+5];
int dn=0;
int tmp[maxn+5];//离散化用 
void discrete(){
	dn=0;
	for(int i=1;i<=n;i++){
		tmp[++dn]=a[i].l;
		tmp[++dn]=a[i].r+1;//转成开区间 
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(tmp+1,tmp+1+dn,a[i].l)-tmp;
		a[i].r=lower_bound(tmp+1,tmp+1+dn,a[i].r+1)-tmp;
	}
}

ll dp[maxn+5][maxn+5];//dp[i][j]表示前i个数,第i个数在j及之后区间内的方案数
					 //枚举放在第j个区间里的个数,dp[i][j]+=dp[k-1][j+1]*C 

ll sum[maxn+5];

int main(){
	ini_inv(maxn);
	scanf("%d",&n);
	ll all=1; 
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		all=all*(a[i].r-a[i].l+1)%mod;
	} 
	discrete();
	for(int j=1;j<=dn;j++) dp[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i].l;j<a[i].r;j++){
			for(int k=i;k>0;k--){
				if(j<a[k].l||j>=a[k].r) break;
				dp[i][j]+=dp[k-1][j+1]*C(i-k+tmp[j+1]-tmp[j],i-k+1)%mod;
				//插板法,把n个物品分成m份,允许有空,C(n+m-1,m)
				//也就是说把r-l+1分成i-k+1份,再加上l,就可以保证在[l,r]内 
				dp[i][j]%=mod;
			}
		}
		for(int j=dn-1;j>=1;j--){
			dp[i][j]+=dp[i][j+1];
			dp[i][j]%=mod;
		}
	}
	printf("%lld\n",dp[n][1]*inv(all)%mod);
}
```

