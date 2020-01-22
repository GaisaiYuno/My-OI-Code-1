#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
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
void update(int tpos,int v,int l,int r,int pos) {
	if(l==r) {
		tree[pos].mark=v;
		tree[pos].lsum=tree[pos].rsum=tree[pos].tsum=v*tree[pos].len();
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(tpos<=mid) update(tpos,v,l,mid,pos<<1);
	else update(tpos,v,mid+1,r,pos<<1|1);
	push_up(pos);
}
int query_sum(int l,int r,int pos,int x) {
	if(l==r||tree[pos].tsum==r-l+1||tree[pos].tsum==0) {
        return tree[pos].tsum;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
    	if(x>=mid-tree[pos<<1].rsum+1) return tree[pos<<1].rsum+tree[pos<<1|1].lsum;
    	else return query_sum(l,mid,pos<<1,x);
	}else{
		if(x<=mid+1+tree[pos<<1|1].lsum) return tree[pos<<1].rsum+tree[pos<<1|1].lsum;
		else return query_sum(mid+1,r,pos<<1|1,x); 
	}
}
int n,m;
int is_d[maxn];
int main() {
	char cmd;
	int x;
	while(scanf("%d %d",&n,&m)!=EOF) {
		build(1,n,1);
	    stack<int>s; 
	    memset(is_d,0,sizeof(is_d));
		while(m--) {
			getchar();//∂¡»Î∂‡”‡ªª–– 
			scanf("%c",&cmd);
			if(cmd=='D') {
				scanf("%d",&x);
                if(!is_d[x])update(x,0,1,n,1);
                s.push(x);
                is_d[x]=1;
			}
			else if(cmd=='Q'){
				scanf("%d",&x);
				if(!is_d[x])printf("%d\n",query_sum(1,n,1,x));
				else printf("0\n");
			}
			else if(cmd=='R'){
			    x=s.top();
				s.pop();
				if(is_d[x]) update(x,1,1,n,1); 
				is_d[x]=0;
			} 
		}
	}
}
