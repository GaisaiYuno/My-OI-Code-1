## Codeforces 1178D (思维+数学)

### 题面

给出正整数n（不一定是质数），构造一个边数为质数的无向连通图（无自环重边），且图的每个节点的度数为质数

### 分析



我们先构造一个环,每个点的度数都是2。但由于n不一定是质数，我们还需要再加k条边。然后对于$i \in [1,k]$,我们加边(i,i+n/2)。当$k\leq \frac{n}{2}$的时候，只会把一些点的度数由2变成3,否则会出现重边问题。假设新图的边数为m,那$m \in [n,n+\frac{n}{2}]$，如果在这个区间内能找到一个质数m，那问题就一定有解。

这里有一个定理

>对于$\forall n \geq 3$,区间$[n,\frac{3n}{2}]$中一定存在一个质数

所以这个问题一定有解。我们筛出$[1,\frac{3n}{2}]$内的质数，然后二分查找出第一个大于等于n的质数m,按照上述方法构造就可以了

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;
int n,m;
int cnt=0;
bool vis[maxn+5];
int prime[maxn+5];
void sieve(int n){
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	scanf("%d",&n);
	sieve(n*3/2+1);
	int m=prime[lower_bound(prime+1,prime+1+cnt,n)-prime];
	printf("%d\n",m);
	for(int i=1;i<n;i++){
		printf("%d %d\n",i,i+1);
	}
	printf("%d %d\n",n,1);
	for(int i=1;i<=m-n;i++){
		printf("%d %d\n",i,i+n/2);
	}
}

```

