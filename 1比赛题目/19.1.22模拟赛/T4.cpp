#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000005
using namespace std;
int n,k;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

inline void qread(long long &x){
	x=0;
	long long sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		x=-x;
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

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
	if(l==r){
		tree[pos].maxv=tree[pos].minv=0;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}

void push_down(int pos){
	if(tree[pos].maxv<tree[pos<<1].minv) tree[pos<<1].minv=tree[pos<<1].maxv=tree[pos].maxv;
	else if(tree[pos].maxv<tree[pos<<1].maxv) tree[pos<<1].maxv=tree[pos].maxv;
	if(tree[pos].minv>tree[pos<<1].maxv) tree[pos<<1].minv=tree[pos<<1].maxv=tree[pos].minv;
	else if(tree[pos].minv>tree[pos<<1].minv) tree[pos<<1].minv=tree[pos].minv;
	
	if(tree[pos].maxv<tree[pos<<1|1].minv) tree[pos<<1|1].minv=tree[pos<<1|1].maxv=tree[pos].maxv;
	else if(tree[pos].maxv<tree[pos<<1|1].maxv) tree[pos<<1|1].maxv=tree[pos].maxv;
	if(tree[pos].minv>tree[pos<<1|1].maxv) tree[pos<<1|1].minv=tree[pos<<1|1].maxv=tree[pos].minv;
	else if(tree[pos].minv>tree[pos<<1|1].minv) tree[pos<<1|1].minv=tree[pos].minv;
}

void update_max(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].maxv=max(tree[pos].maxv,v);
		tree[pos].minv=max(tree[pos].minv,v);
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update_max(L,R,v,pos<<1);
	if(R>mid) update_max(L,R,v,pos<<1|1);
	push_up(pos);
}

void update_min(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].maxv=min(tree[pos].maxv,v);
		tree[pos].minv=min(tree[pos].minv,v);
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update_min(L,R,v,pos<<1);
	if(R>mid) update_min(L,R,v,pos<<1|1);
	push_up(pos);
}

void print_tree(int l,int r,int pos){
	if(l==r){
		qprint(tree[pos].maxv);
		putchar('\n');
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	print_tree(l,mid,pos<<1);
	print_tree(mid+1,r,pos<<1|1);
}

int main(){
	int op,l,r,h;
	qread(n);
	qread(k);
	build(1,n,1);
	for(int i=1;i<=k;i++){
		qread(op);
		qread(l);
		qread(r);
		qread(h);
		l++;
		r++;
		if(op==1){
			update_max(l,r,h,1);
		}else{
			update_min(l,r,h,1);
		}
//		push_down(3);
//		putchar('\n'); 
	}
	print_tree(1,n,1);
}


