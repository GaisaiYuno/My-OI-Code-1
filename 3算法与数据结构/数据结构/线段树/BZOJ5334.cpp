//https://www.luogu.org/problem/P4588 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
typedef long long ll; 
ll mod;
struct segment_tree{
	struct node{
		int l;
		int r;
		ll val;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=tree[pos<<1].val*tree[pos<<1|1].val%mod;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].val=1;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int upos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].val=val;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,val,pos<<1);
		else update(upos,val,pos<<1|1);
		push_up(pos);
	}
}T;
int t,q;
int main(){
	int cmd,x;
	scanf("%d",&t);
	while(t--){
//		int cnt=0;
		scanf("%d %lld",&q,&mod);
		T.build(1,q,1);
		for(int i=1;i<=q;i++){
			scanf("%d %d",&cmd,&x);
			if(cmd==1){
				T.update(i,x,1);
			}
			else{
				T.update(x,1,1);
			}
			printf("%lld\n",T.tree[1].val);
		}
	}
}

