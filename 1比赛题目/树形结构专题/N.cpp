#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m,qa;
struct node {
	int l;
	int r;
	int v;
	int mark;
	int len() {
		return r-l+1;
	}
} tree[maxn<<2];
int a[maxn];
struct sort_seg {
	int l;
	int r;
	int type;
} q[maxn];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos,int middle) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].mark=-1;
	if(l==r) {
		tree[pos].v=(a[l]>middle);
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	build(l,mid,pos<<1,middle);
	build(mid+1,r,pos<<1|1, middle);
	push_up(pos);
}
void push_down(int pos) {
	if(tree[pos].mark!=-1) {
		tree[pos<<1].mark=tree[pos].mark;
		tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].v=tree[pos].mark*tree[pos<<1].len();
		tree[pos<<1|1].v=tree[pos].mark*tree[pos<<1|1].len();
		tree[pos].mark=-1;
	}
}
void update(int L,int R,int v,int pos) {
	if(R<tree[pos].l||L>tree[pos].r) return;
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		tree[pos].v=v*tree[pos].len();
		tree[pos].mark=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos) {
	if(R<tree[pos].l||L>tree[pos].r) return 0;
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(L,R,pos<<1);
	if(R>mid) ans+=query(L,R,pos<<1|1);
	return ans;
}
int check(int x) {
	build(1,n,1,x);
	for(int i=1; i<=m; i++) {
		int sum=query(q[i].l,q[i].r,1);
		if(q[i].type==0) {
			update(q[i].l,q[i].r-sum,0,1);
			update(q[i].r-sum+1,q[i].r,1,1);
		} else {
			update(q[i].l,q[i].l+sum-1,1,1);
			update(q[i].l+sum,q[i].r,0,1);
		}
	}
	if(query(qa,qa,1)==1) return 0;
	else return 1;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&q[i].type,&q[i].l,&q[i].r);
	}
	int l=1,r=n;
	int ans=n+1;
	scanf("%d",&qa);
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			ans=min(ans,mid);
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	printf("%d\n",ans); 
}
