## [Codeforces 1295E]Permutation Separation(线段树+贪心)

### 题面

给出一个排列$p_1,p_2,...p_n$.初始时你需要选择一个位置把排列分成左右两个。然后在两个序列间移动元素使得左边序列的所有元素都比右边的所有元素小。给出每个元素$p_i$从一个序列移动到另一个序列的代价$a_i$.

### 分析

显然最后得到的序列是小的数在一边，大的数在另一边。设从**值为$i$的元素处分开**之后移动代价为$ans_i$. 一开始假设所有数都移到右边序列,那么$ans_i$就是值$\leq i$的元素的代价之和。然后从1~n枚举分割点$i$。对于$p_i$,它放到左边之后$ans[p_i+1,n]$都需要去掉代价(因为$p_i$一开始就在左边,不需要移动)$a_i$.而$ans[0,p_i-1]$需要增加代价$a_i$.当前答案就是所有ans的最小值. 

用线段树维护ans数组,时间复杂度为$O(n\log n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f3f3f3f3f
#define maxn 200000
using namespace std;
typedef long long ll;
struct segment_tree{
	struct node{
		int l;
		int r;
		ll val;
		ll mark;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void add_tag(int pos,ll mark){
		tree[pos].val+=mark;
		tree[pos].mark+=mark;
	}
	void push_down(int pos){
		if(tree[pos].mark){
			add_tag(pos<<1,tree[pos].mark);
			add_tag(pos<<1|1,tree[pos].mark);
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			add_tag(pos,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	inline ll get_min(){
		return tree[1].val;
	}
}T;

int n;
int p[maxn+5],a[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	} 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	T.build(0,n,1);//线段树的区间[i,i]表示开始在值i位置分开的答案ans[i]
	for(int i=1;i<=n;i++){//一开始假设所有数都移到右边,那么ans[i]就是p的前缀和sum[i] 
		T.update(p[i],n,a[i],1); 
	}
	ll ans=INF;
	for(int i=1;i<n;i++){//贪心，把小的数放到左边，枚举哪些数要放 
		T.update(p[i],n,-a[i],1);//去掉p[i]从右到左的代价
		T.update(0,p[i]-1,a[i],1); 
		ans=min(ans,T.get_min());
	} 
	printf("%I64d\n",ans);
}

```

