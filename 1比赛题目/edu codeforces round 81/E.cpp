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

