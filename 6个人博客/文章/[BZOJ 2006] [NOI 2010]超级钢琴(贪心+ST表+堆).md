## [BZOJ 2006] [NOI 2010]超级钢琴(贪心+ST表+堆)

### 题面

给出一个长度为n的序列,选k段长度在L到R之间的区间，一个区间的值等于区间内所有元素之的和，使得k个区间的值之和最大。区间可以相交或包含，但一个区间只能被选1次.

$n,k,L,R \leq 5 \times 10^5$

###　分析

先把区间和转化成前缀和.枚举左端点$i$,右端点的范围为$[i+L-1,\min(i+R-1,n)]$.在这个区间里面找一个前缀和最大的位置p,答案就是$sum[p]-sum[i-1]$.静态维护区间最大值位置可以用ST表做。

但是我们要求k个最大区间，只把每个左端点对应的最大答案求出来，可能不够k个。对于每个左端点暴力枚举所有区间，把所有的值加入堆，最后取出k个显然也会超时。

我们维护一个堆(实现上用STL优先队列),堆里面的每个元素都是一个三元组$(i,l,r)$.表示区间左端点在$i$,右端点在$[l,r]$内时能取到的最大值.设$f_m(l,r)$为$[L,R]$内的最大值位置，那么我们按照$sum[f_m(l,r)]-sum[i]$维护一个最大堆。初始时把$(i,i+L-1,min(i+R-1,n))$插入堆。每次取堆顶$(i,l,r),$累加堆顶的值。令$f_m(l,r)=p$，那次大值对应的区间右端点应该在$[l,p-1]$或$[p+1,r]$内。于是弹出堆顶，插入$(i,l,p-1),(i,p+1,r)$。这样做k次，就可以求出答案。

ST表查询是$O(1)$的，故总时间复杂度为$O((n+k)\log n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue> 
#define maxn 500000 
#define maxlogn 25
using namespace std;
typedef long long ll;
int n,k,L,R;
struct sparse_table{
	int log2[maxn+5];
	int st[maxn+5][maxlogn+5];
	void ini(ll *a,int n){
		log2[0]=-1;
		for(int i=1;i<=n;i++) log2[i]=log2[i>>1]+1;
		for(int i=1;i<=n;i++) st[i][0]=i;
		for(int j=1;j<=log2[n]+1;j++){
			for(int i=1;i+(1<<(j-1))<=n;i++){
				if(a[st[i][j-1]]>a[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1<<(j-1))][j-1];
			} 
		}
	}
	int query(ll *a,int l,int r){
		int k=log2[r-l+1];
		if(a[st[l][k]]>a[st[r-(1<<k)+1][k]]) return st[l][k];
		else return st[r-(1<<k)+1][k];
	}
}T;

int a[maxn+5];
ll sum[maxn+5];
struct node{
	int l;
	int r;
	int i;
	inline ll val(){
		return sum[T.query(sum,l,r)]-sum[i-1];
	}
	node(){
		
	} 
	node(int _i,int _l,int _r){
		i=_i;
		l=_l;
		r=_r;
	} 
	friend bool operator < (node p,node q){
		return p.val()<q.val();
	} 
};
priority_queue<node>q; 
int main(){
	scanf("%d %d %d %d",&n,&k,&L,&R);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	T.ini(sum,n);
	for(int i=1;i+L-1<=n;i++){
		q.push(node(i,i+L-1,min(i+R-1,n)));
	}
	ll ans=0;
	for(int i=1;i<=k;i++){
		node now=q.top();
		q.pop(); 
		ans+=now.val();
		int p=T.query(sum,now.l,now.r);
		if(p>now.l) q.push(node(now.i,now.l,p-1));
		if(p<now.r) q.push(node(now.i,p+1,now.r)); 
	}
	printf("%lld\n",ans); 
}

```



