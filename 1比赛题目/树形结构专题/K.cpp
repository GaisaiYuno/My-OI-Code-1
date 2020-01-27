#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000005
using namespace std;
int n,k;
struct node{
	int l;
	int r;
	int maxv;
	int minv;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv);
	tree[pos].minv=min(tree[pos<<1].minv,tree[pos<<1|1].minv);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].maxv=0;
	tree[pos].minv=0;
	if(l==r){
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void push_down(int pos){
	if(tree[pos].maxv<tree[pos<<1].minv) tree[pos<<1].maxv=tree[pos<<1].minv=tree[pos].maxv;
	else if(tree[pos].maxv<tree[pos<<1].maxv) tree[pos<<1].maxv=tree[pos].maxv;
	if(tree[pos].maxv<tree[pos<<1|1].minv) tree[pos<<1|1].maxv=tree[pos<<1|1].minv=tree[pos].maxv;
	else if(tree[pos].maxv<tree[pos<<1|1].maxv) tree[pos<<1|1].maxv=tree[pos].maxv;
	if(tree[pos].minv>tree[pos<<1].maxv) tree[pos<<1].maxv=tree[pos<<1].minv=tree[pos].minv;
	else if(tree[pos].minv>tree[pos<<1].minv) tree[pos<<1].minv=tree[pos].minv;
	if(tree[pos].minv>tree[pos<<1|1].maxv) tree[pos<<1|1].maxv=tree[pos<<1|1].minv=tree[pos].minv;
	else if(tree[pos].minv>tree[pos<<1|1].minv) tree[pos<<1|1].minv=tree[pos].minv;
	 
}
void update(int L,int R,int v,int type,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		if(type==1){
			tree[pos].maxv=max(tree[pos].maxv,v);
			tree[pos].minv=max(tree[pos].minv,v);
		}else{
			tree[pos].maxv=min(tree[pos].maxv,v);
			tree[pos].minv=min(tree[pos].minv,v);
		}
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,type,pos<<1);
	if(R>mid) update(L,R,v,type,pos<<1|1);
	push_up(pos);
}
int query(int d,int pos){
	if(tree[pos].l==tree[pos].r){
		return tree[pos].maxv;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(d<=mid) return query(d,pos<<1);
	else return query(d,pos<<1|1);
}
int main(){
	scanf("%d %d",&n,&k);
	int op,l,r,h;
	build(1,n,1);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&op,&l,&r,&h);
		l++;
		r++;
		update(l,r,h,op,1);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",query(i,1));
	}
}
