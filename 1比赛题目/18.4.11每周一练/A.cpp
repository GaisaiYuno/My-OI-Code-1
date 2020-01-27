#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005
using namespace std;
struct node {
	int l;
	int r;
	int mark;
	int lsum;
	int rsum;
	int tsum;
	int len() {
		return r-l+1;
	}
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].lsum=tree[pos<<1].lsum;
	tree[pos].rsum=tree[pos<<1|1].rsum;
	tree[pos].tsum=max(max(tree[pos<<1].tsum,tree[pos<<1|1].tsum),tree[pos<<1].rsum+tree[pos<<1|1].lsum);
	if(tree[pos].lsum==tree[pos<<1].len()) tree[pos].lsum+=tree[pos<<1|1].lsum;
	if(tree[pos].rsum==tree[pos<<1|1].len()) tree[pos].rsum+=tree[pos<<1].rsum;
	return;
}
void push_down(int pos) {
	if(tree[pos].mark!=-1) {
		tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].lsum=tree[pos<<1].rsum=tree[pos<<1].tsum=tree[pos].mark*tree[pos<<1].len();
		tree[pos<<1|1].lsum=tree[pos<<1|1].rsum=tree[pos<<1|1].tsum=tree[pos].mark*tree[pos<<1|1].len();
		tree[pos].mark=-1;
	}
	return;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=-1;
	tree[pos].lsum=tree[pos].rsum=tree[pos].tsum=tree[pos].len();
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	return;
}
void update(int L,int R,int v,int l,int r,int pos) {
	if(L<=l&&R>=r) {
		tree[pos].mark=v;
		tree[pos].lsum=tree[pos].rsum=tree[pos].tsum=v*tree[pos].len();
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,l,mid,pos<<1);
	if(R>mid) update(L,R,v,mid+1,r,pos<<1|1);
	push_up(pos);
}
int query_pos(int l,int r,int pos,int len) {
	if(l==r) return l;
	push_down(pos);
	int mid=(l+r)>>1;
	if(tree[pos<<1].tsum>=len) return query_pos(l,mid,pos<<1,len);
	else if(tree[pos<<1].rsum+tree[pos<<1|1].lsum>=len) return mid-tree[pos*2].rsum+1;
	else return query_pos(mid+1,r,pos<<1|1,len);
}
int query_sum(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].tsum;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	int ans=0; 
	if(L<=mid) ans+=query_sum(L,R,l,mid,pos<<1);
	if(R>mid) ans+=query_sum(L,R,mid+1,r,pos<<1|1);
	return ans;
}
int n,m;
int main() {
	int cmd,x,d,r;
	while(scanf("%d %d",&n,&m)!=EOF) {
		build(1,n,1);
		while(m--) {
			scanf("%d",&cmd);
			if(cmd==1) {
				scanf("%d",&d);
				if(tree[1].tsum<d){
				   printf("0\n");
				   continue; 
				} 
				else r=query_pos(1,n,1,d);
				printf("%d\n",r);
				//printf("[%d,%d]=%d  ",r,r+d-1,query_sum(r,r+d-1,1,n,1));
				update(r,r+d-1,0,1,n,1);
			//	printf("[%d,%d]=%d\n",r,r+d-1,query_sum(r,r+d-1,1,n,1));
			}
			else if(cmd==2){
				scanf("%d %d",&x,&d);
				update(x,x+d-1,1,1,n,1); 
			}
			//printf("tot=%d\n",tree[1].tsum);
		}
	}
}
