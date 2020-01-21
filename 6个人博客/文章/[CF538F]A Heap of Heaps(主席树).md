###	题面

题意：给你一个数组a[n],对于数组每次建立一个完全k叉树，对于每个节点，如果父节点的值比这个节点的值大，那么就是一个违规点，统计出1~n-1完全叉树下的违规点的各自的个数。

### 分析

注意到完全k叉树的一个性质，v节点的儿子是k*(v-1)+2...kv+1，v节点的父亲为(v+k-2)/k

那我们可以暴力枚举k，然后枚举每个点i,但是我们没必要枚举叶子节点，也就是说i的范围是0到最后一个叶子节点n的父亲，即[0,(v+n-2)/k]

然后对于每个点i，在对应的子节点区间里查询值在[0,a[i]-1]里的节点个数。由于主席树维护的就是1~i中有多少个节点的值落在[l,r]内，直接区间求和然后相减就可以了

由于n个节点的k叉树最多有$\frac{n}{k}​$个叶子节点

时间复杂度为$\sum_{k=1}^{n-1} \frac{n}{k}=O(n\log n)$

### 代码

```cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxlogn 20
using namespace std;
struct node{
#ifdef DEBUG
	int l;
	int r;
#endif
	int ls;
	int rs;
	int cnt; 
}tree[maxn*maxlogn];
int ptr;
inline void push_up(int x){
	tree[x].cnt=tree[tree[x].ls].cnt+tree[tree[x].rs].cnt;
}
void update(int &x,int last,int upos,int l,int r){
	x=++ptr;
	tree[x]=tree[last];
#ifdef DEBUG
	tree[x].l=l;
	tree[x].r=r;
#endif
	if(l==r){
		tree[x].cnt++;
		return;
	}
	int mid=(l+r)>>1;
	if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
	else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
	push_up(x);
}
int get_sum(int L,int R,int l,int r,int x){
	if(L<=l&&R>=r){
		return tree[x].cnt;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans+=get_sum(L,R,l,mid,tree[x].ls);
	if(R>mid) ans+=get_sum(L,R,mid+1,r,tree[x].rs);
	return ans;
}

int n;
int root[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	int m=n;
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	}
	for(int i=1;i<=n;i++){
		update(root[i],root[i-1],a[i],1,m);
	}
	
	for(int k=1;k<=n-1;k++){
		int lim=(n+k-2)/k;
		for(int i=1;i<=lim;i++){
			int l=k*(i-1)+2;
			int r=min(k*i+1,n);
			int cnt=0;
			if(a[i]-1<1) cnt=0; 
			else cnt=get_sum(1,a[i]-1,1,m,root[r])-get_sum(1,a[i]-1,1,m,root[l-1]);
			ans[k]+=cnt;
		}
	}
	for(int i=1;i<=n-1;i++){
		printf("%d ",ans[i]);
	}
}

```





