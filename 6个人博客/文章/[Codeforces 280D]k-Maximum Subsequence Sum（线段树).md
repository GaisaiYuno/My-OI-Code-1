## [Codeforces 280D]k-Maximum Subsequence Sum（线段树)

### 题面

给出一个序列，序列里面的数有正有负，有两种操作

1.单点修改

2.区间查询，在区间中选出至多k个不相交的子区间，使得这至多k个子区间中数的和最大

### 分析

极其毒瘤的线段树，要维护18个变量

首先考虑查询k=1的情况，是常见的线段树模型。维护区间最大连续和，区间最大前缀和，区间最大后缀和。合并的时候分类讨论一下即可，这里不再赘述。

如果k>1怎么办呢。实际上可以贪心，每次取1个最大子区间，然后把子区间内的值取反。再继续取最大子区间。如果此时最大子区间的和已经<0，就不取了。

正确性可以感性理解一下。假如我们的区间内的数为{7,-2,3,-10},k=2.第一次取出的序列为{7,-2,3},然后取反，变成了{-7,2,-3,10}。再取一次就得到了{2}.把这两个子区间加起来，我们发现和为7+(-2)+3+2=7+3,正好是和最大的两个序列{7}{3}.这里的取反操作，实际上起到了把一个区间断成多个的效果。

那么我们考虑具体实现，除了区间最大连续和，区间最大前缀和，区间最大后缀和，我们还要维护对应连续和的起点和终点。取反实际上比较简单，只要再维护区间最小连续和等变量，取反的时候交换最大最小值，并乘上-1即可。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxk 20
using namespace std;
 
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}
 
int n,m;
int a[maxn+5];
struct val{
	int sum;//区间和
	//最小值相关
	int lmin;//最小前缀和
	int lminp;//最小前缀和的位置为[l,lminp],线段树节点里已经记录了[l,r]
	int rmin;//最小后缀和
	int rminp;//最小后缀和的位置为[rminp,r]
	int minv;//最小连续和
	int minpl;//最小连续和的起点
	int minpr;//最小连续和的终点
	//最大值相关
	int lmax;
	int lmaxp;
	int rmax;
	int rmaxp;
	int maxv;
	int maxpl;
	int maxpr;
 
	friend val operator + (val lson,val rson){
		val ans;
		ans.sum=lson.sum+rson.sum;
		
		ans.lmin=lson.lmin;
		ans.lminp=lson.lminp;
		if(lson.sum+rson.lmin<ans.lmin){
			ans.lmin=lson.sum+rson.lmin;
			ans.lminp=rson.lminp;
		}
		
		ans.rmin=rson.rmin;
		ans.rminp=rson.rminp;
		if(rson.sum+lson.rmin<ans.rmin){
			ans.rmin=rson.sum+lson.rmin;
			ans.rminp=lson.rminp;
		}
		
		int minv=min(min(lson.minv,rson.minv),lson.rmin+rson.lmin);
		ans.minv=minv;
		if(lson.minv==minv){
			ans.minpl=lson.minpl;
			ans.minpr=lson.minpr;
		}else if(rson.minv==minv){
			ans.minpl=rson.minpl;
			ans.minpr=rson.minpr;
		}else{
			ans.minpl=lson.rminp;
			ans.minpr=rson.lminp;
		}
		
		
		ans.lmax=lson.lmax;
		ans.lmaxp=lson.lmaxp;
		if(lson.sum+rson.lmax>ans.lmax){
			ans.lmax=lson.sum+rson.lmax;
			ans.lmaxp=rson.lmaxp;
		}
		
		ans.rmax=rson.rmax;
		ans.rmaxp=rson.rmaxp;
		if(rson.sum+lson.rmax>ans.rmax){
			ans.rmax=rson.sum+lson.rmax;
			ans.rmaxp=lson.rmaxp;
		}
		
		int maxv=max(max(lson.maxv,rson.maxv),lson.rmax+rson.lmax);
		ans.maxv=maxv;
		if(lson.maxv==maxv){
			ans.maxpl=lson.maxpl;
			ans.maxpr=lson.maxpr;
		}else if(rson.maxv==maxv){
			ans.maxpl=rson.maxpl;
			ans.maxpr=rson.maxpr;
		}else{
			ans.maxpl=lson.rmaxp;
			ans.maxpr=rson.lmaxp;
		}
		
		return ans;
	}
	
	void reverse(){
		sum=-sum;
		lmin=-lmin;
		lmax=-lmax;
		swap(lmin,lmax);
		swap(lminp,lmaxp);
		rmin=-rmin;
		rmax=-rmax;
		swap(rmin,rmax);
		swap(rminp,rmaxp);
		minv=-minv;
		maxv=-maxv;
		swap(minv,maxv);
		swap(minpl,maxpl);
		swap(minpr,maxpr);
	}
	
	void set(int pos,int val){
		sum=lmin=lmax=rmin=rmax=minv=maxv=val;
		lminp=lmaxp=rminp=rmaxp=minpl=maxpl=minpr=maxpr=pos;
	}
	
	void print(){
		printf("val: maxv=%d lmax=%d rmax=%d\n",maxv,lmax,rmax);
	}
};
 
struct segment_tree{
	struct node{
		int l;
		int r;
		int sum;
		int mark;//区间-1（翻转max,min） 标记 
		val v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	} 
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].v.set(l,a[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
//		printf("[%d,%d]: ",l,r);
//		tree[pos].v.print();
	}
	void push_down(int pos){
		if(tree[pos].mark){
			tree[pos<<1].mark^=1;
			tree[pos<<1].v.reverse();
			tree[pos<<1|1].mark^=1;
			tree[pos<<1|1].v.reverse();
			tree[pos].mark=0;
		}
	}
	void update_segment(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark^=1;
			tree[pos].v.reverse();
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update_segment(L,R,pos<<1);
		if(R>mid) update_segment(L,R,pos<<1|1);
		push_up(pos);
	}
	void update_point(int upos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v.set(tree[pos].l,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update_point(upos,val,pos<<1);
		else update_point(upos,val,pos<<1|1);
		push_up(pos); 
	}
	val query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		val lans,rans;
		lans.set(0,0);
		rans.set(0,0);
		if(L<=mid){
			lans=query(L,R,pos<<1);
		}
		if(R>mid){
			rans=query(L,R,pos<<1|1);
		}
		if(lans.maxpl==0) return rans;
		else if(rans.maxpl==0) return lans;
		else return lans+rans;
	}
}T;
 
 
val tmp[maxk+5];
int solve(int l,int r,int k){
	int sz=0;
	int ans=0;
	for(int i=1;i<=k;i++){
		tmp[++sz]=T.query(l,r,1);
		if(tmp[sz].maxv<0){
			sz--;
			break;
		}
		ans+=tmp[sz].maxv;
		T.update_segment(tmp[sz].maxpl,tmp[sz].maxpr,1);
	}
	for(int i=sz;i>=1;i--){
		T.update_segment(tmp[i].maxpl,tmp[i].maxpr,1);
	}
	return ans;
}
 
int main(){
//#ifndef LOCAL
//	freopen("easy.in","r",stdin);
//	freopen("easy.out","w",stdout);
//#endif
	int op,x,val,l,r,k;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	T.build(1,n,1);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(op);
		if(op==0){
			qread(x);
			qread(val);
			T.update_point(x,val,1);
		}else{
			qread(l);
			qread(r);
			qread(k);
			qprint(solve(l,r,k));
			putchar('\n');
		} 
	}
}
```

