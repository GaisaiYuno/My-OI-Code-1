//https://www.luogu.org/problem/P3332 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000
#define maxm 50000
#define maxlogn 60
using namespace std;
typedef long long ll;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
struct segment_tree_pos{
//内层维护位置的线段树，维护外层权值线段树区间[L,R]内的数的出现情况
//叶子节点存储第i个位置的集合里有多少个在[L,R]内的数，区间求和 
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		ll v;
		ll mark;
	}tree[maxn*4*maxlogn+5];
	int ptr=0;
	void push_up(int x){
		tree[x].v=tree[lson(x)].v+tree[rson(x)].v;
	}
	void push_down(int x,int l,int r){
		int mid=(l+r)>>1;
		if(tree[x].mark){
			if(!lson(x)) tree[x].ls=++ptr;
			if(!rson(x)) tree[x].rs=++ptr;
			tree[lson(x)].mark+=tree[x].mark;
			tree[lson(x)].v+=tree[x].mark*(mid-l+1);
			tree[rson(x)].mark+=tree[x].mark;
			tree[rson(x)].v+=tree[x].mark*(r-mid);
			tree[x].mark=0;
		}
	}
	void update(int &x,int val,int L,int R,int l,int r){
		if(!x) x=++ptr;
		if(L<=l&&R>=r){
			tree[x].mark+=val;
			tree[x].v+=val*(r-l+1);
			return;
		}
		push_down(x,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) update(tree[x].ls,val,L,R,l,mid);
		if(R>mid) update(tree[x].rs,val,L,R,mid+1,r);
		push_up(x);
	} 
	ll query(int x,int L,int R,int l,int r){
		if(!x) return 0;
		if(L<=l&&R>=r){
			return tree[x].v;
		} 
		push_down(x,l,r); 
		int mid=(l+r)>>1;
		ll ans=0;
		if(L<=mid) ans+=query(tree[x].ls,L,R,l,mid);
		if(R>mid) ans+=query(tree[x].rs,L,R,mid+1,r);
		return ans;
	} 
#undef lson
#undef rson
}T1;

struct segment_tree_val{//外层权值线段树 
	struct node{
		int l;
		int r;
		int root;
	}tree[maxn*4+5];
	void build(int x,int l,int r){
		tree[x].l=l;
		tree[x].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
	}
	void update(int x,int val,int L,int R){ //找到包含val的权值区间，在权值区间对应的内层线段树上区间修改 
		T1.update(tree[x].root,1,L,R,1,n);
		if(tree[x].l==tree[x].r) return;
		int mid=(tree[x].l+tree[x].r)>>1;
		if(val<=mid) update(x<<1,val,L,R);
		else update(x<<1|1,val,L,R); 
	}
	int query(int x,int k,int L,int R){
		if(tree[x].l==tree[x].r) return tree[x].l; 
		//注意是查询第k大 
		ll cnt=T1.query(tree[x<<1|1].root,L,R,1,n);//查询右子结点权值区间[l,mid]中,位置落在[L,R]内的有多少个 
		if(k<=cnt) return query(x<<1|1,k,L,R);
		else return query(x<<1,k-cnt,L,R); 
	}
}T2;

struct oper{
	int type;
	int a;
	int b;
	int c;
}q[maxm+5];
int dn;
int tmp[maxm+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(q[i].type);
		qread(q[i].a);
		qread(q[i].b);
		qread(q[i].c);
		if(q[i].type==1) tmp[++dn]=q[i].c;
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=m;i++){
		if(q[i].type==1) q[i].c=lower_bound(tmp+1,tmp+1+dn,q[i].c)-tmp;
	} 
	T2.build(1,1,dn);
	for(int i=1;i<=m;i++){
		if(q[i].type==1){
			T2.update(1,q[i].c,q[i].a,q[i].b);
		}else{
			qprint(tmp[T2.query(1,q[i].c,q[i].a,q[i].b)]);//由于离散化过，tmp[x]才是真实的值 
			putchar('\n'); 
		}
	}
}

