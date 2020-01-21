#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#define maxn 50000
#define maxm 50000
using namespace std;
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
int a[maxn+5];
int bsz;
int belong[maxn+5];
struct query{
	int l;
	int bel;//减少数组寻址次数 
	int r;
	int id;
	friend bool operator < (query p,query q){
		return p.bel<q.bel||(p.bel==q.bel&&((p.r<q.r)^(p.bel&1)));
	}
}q[maxm+5]; 

struct segment_tree{
	struct node{
		int l;
		int r;
		int len;
		int lmax;
		int rmax;
		int vmax;
	}tree[maxn*4+5];
	int id[maxn+5];
	inline void push_up(register int pos){
		tree[pos].vmax=max(max(tree[pos<<1].vmax,tree[pos<<1|1].vmax),tree[pos<<1].rmax+tree[pos<<1|1].lmax);
		tree[pos].lmax=tree[pos<<1].lmax+(tree[pos<<1].lmax==tree[pos<<1].len)*tree[pos<<1|1].lmax;//把if换成乘法，卡常 
		tree[pos].rmax=tree[pos<<1|1].rmax+(tree[pos<<1|1].rmax==tree[pos<<1|1].len)*tree[pos<<1].rmax;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].len=r-l+1;
		if(l==r){
			id[l]=pos;//记录位置对应的线段树下标，方便快速修改 
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int val){
		register int x=id[val];
		tree[x].lmax^=1;
		tree[x].rmax^=1;
		tree[x].vmax^=1;//有数的时候是删除，没有数的时候是插入
		while(x!=1){
			x>>=1;
			push_up(x);
		} 
	}
	inline int query(){
		return tree[1].vmax;
	} 
}T;

int ans[maxn+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	bsz=n/sqrt(m);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		q[i].id=i;
		q[i].bel=belong[q[i].l];
	}
	sort(q+1,q+1+m);
	int l=1,r=0;
	T.build(1,n,1);
	for(int i=1;i<=m;i++){
		while(l>q[i].l) T.update(a[--l]);
		while(r<q[i].r) T.update(a[++r]);
		while(l<q[i].l) T.update(a[l++]);
		while(r>q[i].r) T.update(a[r--]);
		ans[q[i].id]=T.query(); 
	}
	for(int i=1;i<=m;i++){
		qprint(ans[i]);
		putchar('\n');
	}
}

