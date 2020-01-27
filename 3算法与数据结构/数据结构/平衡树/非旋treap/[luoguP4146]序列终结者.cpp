#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define maxn 100000
using namespace std;
typedef long long ll;
struct fhq_treap{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int sz;
		int dat;
		ll val;
		ll maxv;
		int revm;
		ll addm;
	}tree[maxn+5];
	int ptr;
	int root;
	int New(ll val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].sz=1;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].maxv=val;
		tree[ptr].revm=tree[ptr].addm=0;
		return ptr;
	}	
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		tree[x].maxv=tree[x].val;
		if(lson(x)) tree[x].maxv=max(tree[x].maxv,tree[lson(x)].maxv);
		if(rson(x)) tree[x].maxv=max(tree[x].maxv,tree[rson(x)].maxv);
	}
	void reverse(int x){
		swap(lson(x),rson(x));
		tree[x].revm^=1;
	}
	void add(int x,ll val){
		tree[x].val+=val;
		tree[x].maxv+=val;
		tree[x].addm+=val;
	}
	void push_down(int x){
		if(tree[x].revm){
			if(lson(x)) reverse(lson(x));
			if(rson(x)) reverse(rson(x));
			tree[x].revm=0;
		}
		if(tree[x].addm){
			if(lson(x)) add(lson(x),tree[x].addm);
			if(rson(x)) add(rson(x),tree[x].addm);
			tree[x].addm=0;
		}
	}
	int merge(int x,int y){
		push_down(x);
		push_down(y);
		if(!x||!y) return x+y;
		if(tree[x].dat<tree[y].dat){
			tree[x].rs=merge(tree[x].rs,y);
			push_up(x);
			return x;
		}else{
			tree[y].ls=merge(x,tree[y].ls);
			push_up(y);
			return y;
		}
	}
	void split(int now,int k,int &x,int &y){
		if(now==0){
			x=y=0;
			return;
		}
		push_down(now);
		if(k<=tree[lson(now)].sz){
			y=now;
			split(lson(now),k,x,tree[y].ls);	
		}else{
			x=now;
			split(rson(now),k-tree[lson(now)].sz-1,tree[x].rs,y);
		}
		push_up(now);
	}
	void push_back(ll val){
		root=merge(root,New(val));
	}
	void update_add(int l,int r,ll val){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		add(y,val);
		root=merge(merge(x,y),z);
	}
	void update_rev(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		reverse(y);
		root=merge(merge(x,y),z);
	}
	ll query(int l,int r){
		int x,y,z;
		split(root,r,y,z);
		split(y,l-1,x,y);
		ll ans=tree[y].maxv;
		root=merge(merge(x,y),z);
		return ans;
	}
}T;

int n,m;
int main(){
	int cmd,l,r,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) T.push_back(0);
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d %d",&l,&r,&v);
			T.update_add(l,r,v);
		}else if(cmd==2){
			scanf("%d %d",&l,&r);
			T.update_rev(l,r);
		}else{
			scanf("%d %d",&l,&r);
			printf("%lld\n",T.query(l,r));
		}
//		printf("debug: %lld\n",T.query(2,4));
	}
}
