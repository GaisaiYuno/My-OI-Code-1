## [BZOJ4569] [Luogu 3295] [SCOI2016]萌萌哒(并查集+倍增)

###　题面

有一个n位的十进制数a(无前导0),给出m条限制，每条限制$(l_1,r_1,l_2,r_2)(保证r_1-l_1=r_2-l_2)$表示这个数的第$[l_1,r_1]$位与$[l_2,r_2]$位相同。问有多少个这样的数满足条件，答案取模$10^9+7$,

$n \leq 10^5$

### 分析

约定:我们把十进制数a的每一位从高到低称为第1位，第2位...,记为$a_i$

首先很妙的一点是，把区间限制转化成元素相等，即$a_{l_1+k}=a_{r_1+k}(k \in [0,r_1-l_1+1])$。然后把所有相等的元素看作一个联通块，对于每条限制暴力合并，最后我们就会得到$cnt$个联通块。对于每个联通块，我们要给它的所有元素赋一个相同的值。包含$a_1$的联通块里的元素只能在$[1,9]$内取值(因为第一位不能是0)，其他联通块的元素可以在$[0,9]$内取值。根据乘法原理，答案就是$9 \times 10^{cnt-1}$

那么问题就是如何快速维护连通性。直接做是$O(n^2\alpha(n))$的。注意到我们一个个合并$[l_1,r_1]$内的所有元素，很浪费时间，可以用倍增优化。

我们将并查集的1维改成2维，$f[i][j]$表示区间$[j,j+2^i-1]$的代表元。合并的时候我们只需要把$r_1-l_1+1$二进制拆分，如13拆成$2^3+2^2+2^0$.对于每一位$j$，合并$f[j]$上对应的一段长度为$2^j$的区间。

```cpp
		int len=r1-l1+1;
		for(int j=log2n;j>=0;j--){//二进制拆分 
			if(len&(1<<j)){
				S.merge(j,l1,l2);
				l1+=(1<<j);
				l2+=(1<<j);
			} 
		}
```

![](http://stevenmhy.tk/images/link.png)

[图片来自mhy博客]

如下图,3的二进制拆分为$2^1+2^0$先合并长度为$2^1$的区间，再合并长度为$2^0$的区间

但是我们查询的时候需要查询的是每个点的信息，即$f[0][i]$,所以我们要下推合并。合并长度为$2^j$，起点分别为$x,y$的区间时，我们把区间断成两半，合并$f[j-1][x+2^{j-1}],f[j-1][y+2^{j-1}]$，还要合并$f[j-1][x],f[j-1][y]$这样做$O(\log n)$次,就可以得到$f[0][i]$

```cpp
	for(int j=log2n;j>=1;j--){
		for(int i=1;i+(1<<j)-1<=n;i++){//下推关系，长度为2^j的推到2^(j-1) 
			int f=S.find(j,i);
			S.merge(j-1,i,f);
			S.merge(j-1,i+(1<<(j-1)),f+(1<<(j-1))); 
		}
	}
```

时间复杂度为$O(n \alpha(n)\log n )$,但是这里我偷了个懒，只写了路径压缩的并查集，时间复杂度$O(n \log^2 n)$,由于常数很小，可以通过。

###　代码

```cpp

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100000
#define maxlogn 21
#define mod 1000000007
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

struct disjoint_set{
	int fa[maxlogn+5][maxn+5];//f[i][j]表示[j,j+2^i-1]的代表元
	void ini(int n){
		int k=log2(n)+1;
		for(int j=0;j<=k;j++){
			for(int i=1;i<=n;i++){
				fa[j][i]=i;
			}	
		}
	} 
	int find(int b,int x){
		if(fa[b][x]==x) return x;
		else return fa[b][x]=find(b,fa[b][x]);
	}
	void merge(int b,int x,int y){
		int fx=find(b,x);
		int fy=find(b,y);
		if(fx!=fy) fa[b][fx]=fy;
	}
}S;

int log2n;
int n,m;
int main(){
	int l1,l2,r1,r2;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		int len=r1-l1+1;
		for(int j=log2n;j>=0;j--){//二进制拆分 
			if(len&(1<<j)){
				S.merge(j,l1,l2);
				l1+=(1<<j);
				l2+=(1<<j);
			} 
		}
	}
	for(int j=log2n;j>=1;j--){
		for(int i=1;i+(1<<j)-1<=n;i++){//下推关系，长度为2^j的推到2^(j-1) 
			int f=S.find(j,i);
			S.merge(j-1,i,f);
			S.merge(j-1,i+(1<<(j-1)),f+(1<<(j-1))); 
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(S.find(0,i)==i) cnt++;
	}
	printf("%lld\n",9*fast_pow(10,cnt-1)%mod);
}

```



