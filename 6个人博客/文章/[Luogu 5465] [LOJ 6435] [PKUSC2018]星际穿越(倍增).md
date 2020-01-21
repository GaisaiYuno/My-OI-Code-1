## [Luogu 5465] [LOJ 6435] [PKUSC2018]星际穿越(倍增)

###　题面

n个点的图，点i和[l[i],i)的所有点连双向边。每次询问(l,r,x)表示x到[l,r]的所有点的最短路径长度和/(r-l+1)。

$n \leq 10^5,l_i<r_i<x_i$

### 分析

有(du)趣(liu)的倍增问题。

观察到$l_i<r_i<x_i$,也就是说我们要求往左走的最小距离。首先差分一下，设$sum(x,i)$表示$x$到$[i,x-1]$的最短距离和。那么答案就是$\frac{sum(x,l)-sum(x,r+1)}{r-l+1}$

然后我们不要直接考虑到x的最短路，而是反过来考虑走k步可以到达哪些节点。

我们从x开始走1步，可以走到哪里呢？。可以跳到的编号最小的点为$l_x$,而最大的点应该是$rb(x)=\max(k) (l_k \leq x)$,因为只要$l_k \leq x$, $x$与$k$之间就有一条边。因此第1步能到达的区间是$[l_x,rb(x)]$

第2步呢？。根据上面的分析，应该是$\min(l_i)(i \in [l_x,rb(x)])$.但是实际上可以简化为$\min(l_i)(i \in [l_x,n])$.因为在$[rb(x),n]$内的点，它们的$l$比x还大，自然也比$[l_x,rb(x)]$内的点的$l$还大，对最小值没有任何影响。

因此，设走$k(k>1)$步可以到达的编号最小的点为$a$,那么走$k+1$步能够到达的编号最小的点为$\min(l_i)（i\in [a,n])$.这样就可以倍增优化。

设$f[i][j]$表示$[i,n]$内节点走$2^j$步能够到达的编号最小的点。那么显然有:

$$f[i][0]=\min(l_k),k \in[i,n]$$

$$f[i][j]=f[f[i][j-1]][j-1]$$

为了求答案，我们再维护一个和，$g[i][j]$表示$i$到$[f[i][j],i-1]$内所有点的距离和。那么：

$g[i][0]=i-f[i][0]$ (到$[f[i][0],i-1]$中的每个点的距离都为1)

$$g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1]+2^{j-1}(f[i][j-1]-f[i][j])$$

这是因为:到$[f[i][j-1],i-1]$内的节点，距离和是$g[i][j-1]$。而到$[f[i][j],f[i][j-1]]$内的节点的距离由两部分组成，一部分是各节点到$f[i][j-1]$的距离$g[f[i][j-1]][j-1]$,另一部分是从$f[i][j-1]$到$i$的距离$2^{j-1}$.因为一共有$(f[i][j-1]-f[i][j])$个节点，所以要乘上$(f[i][j-1]-f[i][j])$

查询的话就倍增的跳即可，注意一些细节，还是直接上代码吧.

```cpp
int calc(int x,int l){ //sum(x,l),[l,x-1]内答案 
	if(a[x]<=l) return x-l;//只需走一次的情况，特判
	//第一次走的答案 
	int ans=x-a[x];//距离和
	int cnt=1;//走的次数
	x=a[x]; 
	for(int i=log2n;i>=0;i--){
		if(f[x][i]>=l){
			ans+=g[x][i]+cnt*(x-f[x][i]);//[f[x][i],x-1]跳到x还需cnt步,g[x][i]为当前这段的距离和 
			cnt+=(1<<i);
			x=f[x][i];
		}
	}
	if(x>l) ans+=x-l+cnt*(x-l);//如果最后一步没跳满，加上f[x][i] 
	return ans; 
} 
```


### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define maxlogn 25 
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int n,q;
int log2n;
int a[maxn+5]; 
int f[maxn+5][maxlogn+5];
int g[maxn+5][maxlogn+5];
int calc(int x,int l){ //[l,x-1]内答案 
	if(a[x]<=l) return x-l;
	//特判第一次跳 
	int ans=x-a[x];
	int cnt=1;
	x=a[x]; 
	for(int i=log2n;i>=0;i--){
		if(f[x][i]>=l){
			ans+=g[x][i]+cnt*(x-f[x][i]);//[f[x][i],x-1]跳到x还需cnt步 
			cnt+=(1<<i);
			x=f[x][i];
		}
	}
	if(x>l) ans+=x-l+cnt*(x-l);//如果最后一步没跳满，加上f[x][i] 
	return ans; 
} 
int main(){
	int l,r,x;
	scanf("%d",&n);
	log2n=log2(n)+1;
	a[1]=1;
	for(int i=2;i<=n;i++) scanf("%d",&a[i]);
	f[n][0]=a[n];
	for(int i=n-1;i>=1;i--){
		f[i][0]=min(f[i+1][0],a[i]);
		g[i][0]=i-f[i][0];
	}
	for(int j=1;j<=log2n;j++){
		for(int i=1;i<=n;i++){
			if(f[i][j-1]){
				f[i][j]=f[f[i][j-1]][j-1];
				g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1]+((f[i][j-1]-f[i][j])<<(j-1)); 
				//[f[i][j],f[i][j-1]-1]内的点跳到j还需2^{j-1}步 
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&l,&r,&x);
		int up=calc(x,l)-calc(x,r+1);
		int down=r-l+1;
		int g=gcd(up,down);
		up/=g;
		down/=g;
		printf("%d/%d\n",up,down);
	}
}

```

