#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
struct node{
	int l;
	int r;
	int mark;
	int v;
	int len(){
		return r-l+1;
	}
	void debug(){
		printf("[%d,%d] %d %d\n",l,r,mark,v);
	}
};
int n,m;
node tree[maxn*4];
struct querys{
	int l;
	int r;
	int x;
	querys(){
		
	}
	querys(int a,int b,int c){
		l=a;
		r=b;
		x=c;
	}
}q[maxn];
void build(int l,int r,int pos){
	tree[pos].mark=-1;
	tree[pos].v=0;
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void push_down(int pos){
	if(tree[pos].mark!=-1){
		tree[pos<<1].v=tree[pos].mark;
		tree[pos<<1].mark=tree[pos].mark;
		tree[pos<<1|1].v=tree[pos].mark;
		tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos].mark=-1;
	}
}
void update(int L,int R,int v,int pos){
//	tree[pos].debug();
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		tree[pos].mark=v;
		tree[pos].v=v;
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
}
int query(int L,int R,int pos){
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) return query(L,R,pos<<1);
	if(R>mid) return query(L,R,pos<<1|1);
}
int main(){
	scanf("%d %d",&n,&m);
//	printf("%d\n",n);
	build(1,n,1);
	int l,r,x;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&l,&r,&x);
		q[i]=querys(l,r,x);
	}
	for(int i=m;i>=1;i--){
		l=q[i].l;
		r=q[i].r;
		x=q[i].x;
//		if(r==2){
//			r=2;
//		}
		if(x-1>=l) update(l,x-1,x,1);
		if(x+1<=r) update(x+1,r,x,1);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",query(i,i,1));
	}
	
}

