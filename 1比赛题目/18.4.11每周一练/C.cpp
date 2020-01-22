#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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

struct block {
	int l;
	int r;
	block(){
		l=r=0;
	}
	block(int L,int R) {
		l=L;
		r=R;
	}
	friend bool operator < (block a,block b) {
		return a.l<b.l;
	}
};
/*int cmp(block a,block b){
	return a.l<b.l;
}*/
int n,m;
int main() {
	char cmd[7];
	int x,a,b;
	vector<block>v;
	vector<block>::iterator it;
	block now;
	while(scanf("%d %d",&n,&m)!=EOF) {
		build(1,n,1);
		v.clear();
		while(m--) {
			scanf("%s",cmd);
			if(strcmp(cmd,"Reset")==0) {
				update(1,n,1,1,n,1);
				v.clear();
				printf("Reset Now\n");
			} else if(strcmp(cmd,"New")==0) {
				scanf("%d",&x);
				if(tree[1].tsum<x) {
					printf("Reject New\n");
				} else {
					a=query_pos(1,n,1,x);
					b=a+x-1;
					update(a,b,0,1,n,1);
					printf("New at %d\n",a);
					now=block(a,b);
					it=upper_bound(v.begin(),v.end(),now);
					v.insert(it,now);
				}
			}else if(strcmp(cmd,"Free")==0){ 
                scanf("%d",&x); 
                now=block(x,x);
                it=upper_bound(v.begin(),v.end(),now);
                if(it==v.begin()){
                	printf("Reject Free\n");
				}else{
					it--;
					if(it->r<x) printf("Reject Free\n");
					else{
						update(it->l,it->r,1,1,n,1);
						printf("Free from %d to %d\n",it->l,it->r);
						v.erase(it); 
					}
				}
			}else if(strcmp(cmd,"Get")==0){
				scanf("%d",&x);
				if(x>v.size()) printf("Reject Get\n");
				else{
					printf("Get at %d\n",v[x-1].l);
				}
			}
		} 
		printf("\n");
	}
}


