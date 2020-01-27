## [Codeforces 1199C]MP3(离散化+二分答案)

### 题面

给出一个长度为n的序列$a_i$和常数I,定义一次操作[l,r]可以把序列中<l的数全部变成l,>r的数全部变成r。每次操作的代价为改变数的个数。问:要让操作后序列里不同数的个数$k$满足$n \lceil  \log _2 k\rceil \leq 8I $,操作的最小代价

### 分析

首先把a离散化，这样[l,r]都在$10^5$的级别。枚举l，发现r显然有单调性。操作后不同数的个数随r的增大而减小（考虑极端情况l=r,操作后所有数相同。若$r_1$满足条件，那$r_2<r_1$也一定满足条件。而操作的最小代价随r增大而减小。所以我们只需要对于每个l找到最大的满足条件的r即可。

考虑判定：我们把a排序，记$cnt(l,r)$表示满足$a_i \in [l,r]$的$i$的个数，m为离散化后的最大值。那么操作的代价为$cnt(1,l-1)+cnt(r+1,m)$,不同数的个数为$r-l+1$(操作完之后最小值变成l,最大值变成r,由于我们离散化过，[l,r]内的数一定是连续的，所有个数为[r-l+1])

那么我们只要预处理前缀和$sum(v)$表示整个序列值<=v的个数，离散化后可以$O(n)$预处理，$cnt(l,r)=sum(r)-sum(l-1)$

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define INF 0x3f3f3f3f
#define maxn 800000
using namespace std;
int n,m,I;
int a[maxn+5];
int b[maxn+5];
int sum1[maxn+5];
 
inline int cnt(int l,int r){
	return sum1[r]-sum1[l-1];
}
int check(int lb,int rb){
	int ans1=cnt(1,lb-1);
	int ans2=cnt(rb+1,m);
	int k=rb-lb+1;
//	int cnt=2+sum1[lb+1]+sum1[rb-1];
	if(ceil(log2(k))*n<=I*8) return ans1+ans2;
	else return -1;
}
int bin_search(int t){
 
	int l=t,r=m;
	int ans=INF;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		int val=check(t,mid);
		if(val!=-1){
			ans=val;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
 
int mark[maxn+5];
int main(){
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d",&I);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	for(int i=1;i<=n;i++){
		sum1[a[i]]++;
	}
	for(int i=1;i<=m;i++) sum1[i]+=sum1[i-1];
//	printf("%d\n",m);
	int ans=INF;
	for(int l=1;l<=m;l++){
		int tmp=bin_search(l);
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}
```

