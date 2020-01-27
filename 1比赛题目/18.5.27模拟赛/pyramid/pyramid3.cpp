#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5005
using namespace std;
int n,q;
int a[maxn];
int b[maxn<<1];
struct node {
	int l;
	int r;
	int v;
} tree[maxn<<3];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v^tree[pos<<1|1].v;
	tree[pos].v=max(tree[pos<<1].v,tree[pos].v);
	tree[pos].v=max(tree[pos<<1|1].v,tree[pos].v);
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r) {
		tree[pos].v=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}
int get_left(int x) {
	if(x!=1&&x!=n)return x*2-2;
	else if(x==1) return 1;
	else return n*2-2;
}
int get_right(int x) {
	if(x!=1&&x!=n)return x*2-1;
	else if(x==1) return 1;
	else return n*2-2;
}
int main() {
//	freopen("pyramid11.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	int l,r;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	int m=0;
	
		for(int i=1; i<=n; i++) {
			if(i==1||i==n) {
				m++;
				b[m]=a[i];
			} else {
				b[++m]=a[i];
				b[++m]=a[i];
			}
		}
		if(n!=1)m=2*n-2;
		else m=n;

	build(1,m,1);
	scanf("%d",&q);
	for(int i=1; i<=q; i++) {
		scanf("%d %d",&l,&r);
		printf("%d\n",query(get_left(l),get_right(r),1));
	}
}
