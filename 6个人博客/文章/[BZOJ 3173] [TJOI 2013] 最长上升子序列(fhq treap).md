## [BZOJ 3173] [TJOI 2013] 最长上升子序列(fhq treap)

### 题面

给定一个序列，初始为空。现在我们将1到N的数字插入到序列中，每次将一个数字插入到一个特定的位置。每插入一个数字，我们都想知道此时最长上升子序列长度是多少？

### 分析

这题有几个重要性质：

第一个性质是，**插入的数的大小是递增的**。我们插入第i个数后的答案，为以当前序列中的数为结尾的LIS长度的最大值，而根据当前序列中的数都在[1,i]内，们可以维护以值v为结尾的LIS长度len[i],那么第i次插入后的答案就是$max(len[j]) (j \in [1,i])$

第二个性质是，**后插入的数不会影响以前面插入的数为结尾的LIS长度**。这句话有点抽象，我们来举一个例子。插入完两个数后的序列是{1,2},以2结尾的LIS长度为2。然后我们在2前面插入3，序列变成了{1,3,2},因为3>2,它不会影响以2结尾的LIS长度，因此以2结尾的LIS长度仍为2。如果插入在2后面，显然新的LIS结尾不可能是2，对以2结尾的LIS长度没有影响。

因此，我们只要用一个数据结构处理出插入n次后的最终序列，对这个序列跑一次LIS，求出以v结尾的序列长度，然后前缀max一下求出答案。这里我选择了fhq treap来维护序列，然后用模板的$O(n \log n)$求LIS算法。

### 代码

```cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 100000 
using namespace std;
struct fhq_treap{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int val;
		int sz;
		int dat;
	}tree[maxn+5];
	int root;
	int ptr;
	int New(int val){
		ptr++;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].sz=1;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
	} 
	int merge(int x,int y){
		if(!x||!y) return x+y;
		if(tree[x].dat<tree[y].dat){
			tree[y].ls=merge(x,tree[y].ls);
			push_up(y);
			return y;
		}else{
			tree[x].rs=merge(tree[x].rs,y);
			push_up(x);
			return x;
		} 
	}
	void split(int now,int k,int &x,int &y){
		if(now==0){
			x=y=0;
			return;
		}
		if(k<=tree[lson(now)].sz){
			y=now;
			split(tree[now].ls,k,x,tree[y].ls);
		}else{
			x=now;
			split(tree[now].rs,k-tree[lson(now)].sz-1,tree[x].rs,y); 
		}
		push_up(now);
	}
	void insert(int val,int pos){
		int x,y;
		split(root,pos-1,x,y);
		root=merge(merge(x,New(val)),y);
	}
	void print(int x,int *out,int &sz){
		if(x==0) return;
		print(lson(x),out,sz);
		out[++sz]=tree[x].val;
		print(rson(x),out,sz);
	}
}T;

int n;
int sz=0;
int a[maxn+5];

int top=0;
int s[maxn+5];
int len[maxn+5];//以值i为结尾的LIS长度 
void get_lis(){
	for(int i=1;i<=n;i++){
		if(a[i]>s[top]){
			s[++top]=a[i];
			len[a[i]]=top;
		}else{
			int tmp=lower_bound(s+1,s+1+top,a[i])-s;
			s[tmp]=a[i];
			len[a[i]]=tmp;
		} 
	}
} 
int main(){
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		x++;
		T.insert(i,x);
	}
	T.print(T.root,a,sz);
//	for(int i=1;i<=sz;i++) printf("%d ",a[i]);
	get_lis();
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,len[i]);
		printf("%d\n",ans);
		//第i个数插入的时候，序列里只有1~i的数，把以它们为结尾的lis长度取max即可 
	} 
}

```

