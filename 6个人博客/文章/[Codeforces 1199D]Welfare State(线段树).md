###　[Codeforces 1199D]Welfare State(线段树)

### 题面

给出一个长度为n的序列，有q次操作，操作有2种

1.单点修改，把$a_x$修改成y

2.区间修改，把序列中值<v的数全部修改成v

问q次操作后的序列

### 分析

主要考虑如何实现操作2，可以通过有条件的下推标记来实现。线段树的叶子节点存储序列的值，上推的时候维护区间最小值。如果给某个节点下推标记的时候发现该节点对于的区间最小值>v,则不下推（最小值>v,即所有数都>v，不用会产生修改），否则把区间中的最小值和v取max.

单点修改的时候先下推标记，然后跟普通线段树一样修改即可。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#define maxn 200000
using namespace std;
int n;
int a[maxn+5];
int q;
struct segment_tree{
	struct node{
		int l;
		int r;
		int mark;
		int v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=min(tree[pos<<1].v,tree[pos<<1|1].v);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].mark=-1;
		if(l==r){
			tree[pos].v=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void push_down(int pos){
		if(tree[pos].mark!=-1){
            //只有当前值比它大才下推
			if(tree[pos].mark>tree[pos<<1].mark||tree[pos<<1].mark==-1) tree[pos<<1].mark=tree[pos].mark;
			if(tree[pos].mark>tree[pos<<1].v) tree[pos<<1].v=tree[pos].mark;
			if(tree[pos].mark>tree[pos<<1|1].mark||tree[pos<<1|1].mark==-1) tree[pos<<1|1].mark=tree[pos].mark;
			if(tree[pos].mark>tree[pos<<1|1].v) tree[pos<<1|1].v=tree[pos].mark;
			tree[pos].mark=-1;
		}
	}
	void update_segment(int L,int R,int pt,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			if(tree[pos].v<=pt){
				tree[pos].v=pt;
				tree[pos].mark=pt;
			}
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update_segment(L,R,pt,pos<<1);
		if(R>mid) update_segment(L,R,pt,pos<<1|1);
		push_up(pos);
	}
	void update_point(int tpos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=val;
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) update_point(tpos,val,pos<<1);
		else update_point(tpos,val,pos<<1|1);
		push_up(pos); 
	}
	int query(int tpos,int pos){
		if(tree[pos].l==tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) return query(tpos,pos<<1);
		else return query(tpos,pos<<1|1);
	}
}T;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	int cmd,x,v;
	T.build(1,n,1);
	for(int i=1;i<=q;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d",&x,&v);
			T.update_point(x,v,1);
		}else{
			scanf("%d",&v);
			T.update_segment(1,n,v,1);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",T.query(i,1));
	}
}

```

