#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
struct node{
	int l;
	int r;
	double v;
	int len;	
}tree[maxn<<2];
int query(double maxv,int pos){
	if(tree[pos].l==tree[pos].r){
		if(tree[pos].v>maxv) return 1;
		else return 0;	
	}
	if(tree[pos<<1].v<=maxv) return query(maxv,pos<<1|1);
	else return query(maxv,pos<<1)+tree[pos].len-tree[pos<<1].len; 
	
}
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
	tree[pos].len=tree[pos<<1].len+query(tree[pos<<1].v,pos<<1|1);	
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].len=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);	
}
void update(int tpos,double v,int pos){
	if(tree[pos].l==tree[pos].r){
		tree[pos].v=v;
		tree[pos].len=1;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) update(tpos,v,pos<<1);
	else update(tpos,v,pos<<1|1);
	push_up(pos);
}
int n,m;
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		update(x,(double)y/x,1);
		printf("%d\n",tree[1].len);
	}
}



