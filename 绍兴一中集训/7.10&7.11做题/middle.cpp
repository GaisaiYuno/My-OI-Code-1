//BZOJ 2653
/*
考虑判断一个数是否<=序列的中位数：把大于这个数的变为1，不大于它的变为-1，判断和是否大于等于0（不管相等）
对询问二分答案是全局第几大，
那么就要在把md按上述方法替换之后的序列找一个和最大的左端点在[a,b]，右端点在[c,d]的子序列，
线段树维护区间最大前/后缀即可([a,b]后缀+[b,c]区间和和+[c,d]前缀）.
如果能找到和>=0的子序列，那最大中位数>=b[mid]，l=mid+1,否则r=mid-1
二分md每次建显然不行，而md对md-1的变化只有一个，可持久化树维护就行了，每次查询就是查一个历史版本
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20000
#define maxlogn 20
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
struct num{
	int val;
	int pos;	
	friend bool operator < (num p,num q){
		return p.val<q.val;
	}
}a[maxn+5];
 
struct val{
	int sum;
	int lmax;
	int rmax;
	val(){
		
	}
	val(int v){
		sum=lmax=rmax=v;
	}
	friend val operator + (val lson,val rson){
		val ans;
		ans.sum=lson.sum+rson.sum;
		ans.lmax=max(lson.lmax,lson.sum+rson.lmax);
		ans.rmax=max(rson.rmax,rson.sum+lson.rmax);
		return ans;
	}
}; 
struct per_segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		//[l,r]存储原来序列中和，最大前缀，后缀和 
		int ls;
		int rs;
		val v;
	}tree[maxn*maxlogn+5];
	int root[maxn+5];
	int ptr;
	void push_up(int x){
		tree[x].v=tree[lson(x)].v+tree[rson(x)].v;
	}
	void build(int &x,int l,int r){
		x=++ptr;
		if(l==r){
		 	tree[x].v=val(1);
		 	return;
		}
		int mid=(l+r)>>1;
		build(tree[x].ls,l,mid);
		build(tree[x].rs,mid+1,r);
		push_up(x);
	}
	void insert(int &x,int last,int upos,int v,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].v=val(v);
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) insert(tree[x].ls,tree[last].ls,upos,v,l,mid);
		else insert(tree[x].rs,tree[last].rs,upos,v,mid+1,r);
		push_up(x);
	}
	val query(int x,int L,int R,int l,int r){
		if(L>R){
			return val(0);
		}
		if(L<=l&&R>=r){
			return tree[x].v;
		}
		int mid=(l+r)>>1;
//		val ans;
		if(L<=mid&&R>mid){
			return query(tree[x].ls,L,R,l,mid)+query(tree[x].rs,L,R,mid+1,r);
		}else if(L<=mid){
			return query(tree[x].ls,L,R,l,mid);
		}else if(R>mid){
			return query(tree[x].rs,L,R,mid+1,r);
		}
		return val(0);
	}
#undef lson
#undef rson
}T;

int check(int l1,int r1,int l2,int r2,int mid){
	int sum=T.query(T.root[mid],l1,r1,1,n).rmax+T.query(T.root[mid],r1+1,l2-1,1,n).sum+T.query(T.root[mid],l2,r2,1,n).lmax;
	if(sum>=0) return 1;
	else return 0;
}
int bin_search(int l1,int r1,int l2,int r2){
	int l=1,r=n;
	int mid;
	int ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(l1,r1,l2,r2,mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}

int q[4];
int main(){
	int last=0,ans=0;
	int l1,r1,l2,r2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].pos=i;
	}
	sort(a+1,a+1+n);//我们二分的是中位数是排序后的第几个，所以要sort 
	T.build(T.root[1],1,n);//一开始，所有数都大于b[mid],都为1 
	for(int i=2;i<=n;i++){
		T.insert(T.root[i],T.root[i-1],a[i-1].pos,-1,1,n);//预处理mid=i时的线段树 
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		q[0]=(l1+last)%n;
		q[1]=(r1+last)%n;
		q[2]=(l2+last)%n;
		q[3]=(r2+last)%n;
		sort(q,q+4);
		ans=a[bin_search(q[0]+1,q[1]+1,q[2]+1,q[3]+1)].val;
		printf("%d\n",ans);
		last=ans;
	} 
}
