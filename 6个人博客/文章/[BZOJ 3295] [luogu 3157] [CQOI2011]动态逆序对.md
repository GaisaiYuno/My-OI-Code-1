## [BZOJ 3295] [luogu 3157] [CQOI2011]动态逆序对

###　题面

给出一个长度为n的排列，每次操作删除一个数，求每次操作前排列逆序对的个数

### 分析

每次都对整个序列求逆序对显然不行，考虑每次删除对逆序对个数的影响

假如删除的数为x，x在序列中的位置为pos[x]，那么包含x的逆序对个数为位置在[1,pos[x]-1]中大于x的数+位置在[pos[x]+1,n]中小于x的数，每次删除只要减去这些就可以了

那么这个问题其实就转化成查询位置在[L,R]内，且值域在[l,r]内的数的个数。本质上和带修区间第k大[BZOJ 1901 Dynamic Rankings](https://www.cnblogs.com/birchtree/p/10851759.html)是一样的，外层用树状数组维护位置，内层不用可持久化，直接用权值线段树即可

那么我们像树状数组那样维护n棵权值线段树，不同的是每棵权值线段树里保存的是，a[i-lowbit(i)+1]~a[i]有多少个值落在区间[l,r]内

对于查询[ql,qr]中有多少个值时的做差
我们要像树状数组求和那样，把root[i],root[i-lowbit(i)],....共O(logn)棵权值线段树的值加起来，才能得到a[1]~a[i]有多少个数落在1~qr里面，1~(ql-1)同理，维护两个临时数组x,y存储这O(logn)棵权值线段树的根即可

对于单点修改，我们像树状数组修改那样，往O(logn)棵权值线段树中插入即可

时间复杂度$O(m \log ^2 n)$,常数略大

注意答案一定要开long long!!!!

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxm 100000
#define maxnlogn 50000000
#define maxlogn 20 
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
struct segment_tree_val{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int v;
	}tree[maxnlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].v=tree[lson(x)].v+tree[rson(x)].v;
	}
	void update(int &x,int upos,int uval,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].v+=uval;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,upos,uval,l,mid);
		else update(tree[x].rs,upos,uval,mid+1,r);
		push_up(x);
	}
	int totx,toty;
	int x[maxn+5],y[maxn+5];
	int query_less(int k,int l,int r){//查询<k的数的个数 
		int cnt=0;
		while(l!=r){
			int mid=(l+r)>>1;
			if(k<=mid){
				for(int i=1;i<=totx;i++) x[i]=lson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=lson(y[i]);
				r=mid;
			}else{
				for(int i=1;i<=totx;i++) cnt-=tree[lson(x[i])].v;
				for(int i=1;i<=toty;i++) cnt+=tree[lson(y[i])].v;
				for(int i=1;i<=totx;i++) x[i]=rson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=rson(y[i]);
				l=mid+1;
			}
		}
		return cnt;
	}
	int query_more(int k,int l,int r){//查询>k的数的个数 
		int cnt=0;
		while(l!=r){
			int mid=(l+r)>>1;
			if(k<=mid){
				for(int i=1;i<=totx;i++) cnt-=tree[rson(x[i])].v;
				for(int i=1;i<=toty;i++) cnt+=tree[rson(y[i])].v;
				for(int i=1;i<=totx;i++) x[i]=lson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=lson(y[i]);
				r=mid;
			}else{
				for(int i=1;i<=totx;i++) x[i]=rson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=rson(y[i]);
				l=mid+1;
			}
		}
		return cnt;
	}
}T1;

struct fenwick_tree{
	inline int lowbit(int x){
		return x&(-x);
	} 
	int root[maxn+5];
	void update(int t2pos,int t1pos,int val){
		for(int i=t2pos;i<=n;i+=lowbit(i)){
			T1.update(root[i],t1pos,val,1,n);
		}
	}
	int query_less(int lpos,int rpos,int val){
		T1.totx=T1.toty=0;
		for(int i=lpos-1;i;i-=lowbit(i)) T1.x[++T1.totx]=root[i];
		for(int i=rpos;i;i-=lowbit(i)) T1.y[++T1.toty]=root[i]; 
		return T1.query_less(val,1,n);
	}
	int query_more(int lpos,int rpos,int val){
		T1.totx=T1.toty=0;
		for(int i=lpos-1;i;i-=lowbit(i)) T1.x[++T1.totx]=root[i];
		for(int i=rpos;i;i-=lowbit(i)) T1.y[++T1.toty]=root[i]; 
		return T1.query_more(val,1,n);
	}
}T2;

int pos[maxn+5];
long long ans=0;
int main(){
//	freopen("4.in","r",stdin);
//	freopen("4.out","w",stdout); 
//	freopen("1.txt","r",stdin);
	int x;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		pos[a[i]]=i;
		ans+=T2.query_more(1,i-1,a[i]);
		T2.update(i,a[i],1); 
	}
	qprint(ans);
	putchar('\n');
	for(int i=1;i<m;i++){
		qread(x);
		ans-=T2.query_more(1,pos[x]-1,x);
		ans-=T2.query_less(pos[x]+1,n,x);
		qprint(ans);
		putchar('\n');
		T2.update(pos[x],x,-1); 
	}
}
/*
5 4
1 5 3 4 2
5 
1
4
2

*/ 

```



