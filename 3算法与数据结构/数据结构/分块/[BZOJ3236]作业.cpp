#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000000
#define maxm 1000000 
#define maxlogn 20
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
struct persist_segment_tree{
#define lson(x) tree[x].ls
#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int sum;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].sum=tree[lson(x)].sum+tree[rson(x)].sum;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=++ptr;
		tree[x]=tree[last];
		if(l==r){
			tree[x].sum++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x);
	}
	int query(int xl,int xr,int L,int R,int l,int r){
		if(L<=l&&R>=r){
			return tree[xr].sum-tree[xl].sum;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(tree[xl].ls,tree[xr].ls,L,R,l,mid);
		if(R>mid) ans+=query(tree[xl].rs,tree[xr].rs,L,R,mid+1,r);
		return ans;
	} 
}T1;
int root[maxn+5];

struct fenwick_tree{
	inline int lowbit(int x){
		return x&(-x);
	}
	int c[maxn+5];
	void update(int pos,int val){
		for(int i=pos;i<=n;i+=lowbit(i)) c[i]+=val;
	}
	int sum(int pos){
		int ans=0;
		for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
}T2;

int bsz;
int belong[maxn+5];
struct query{
	int l;
	int r;
	int a;
	int b;
	int id;
	friend bool operator < (query a,query b){
		return belong[a.l]<belong[b.l]||(belong[a.l]==belong[b.l]&&((belong[a.l]&1)?a.r<b.r:a.r>b.r));
	}
}q[maxm+5];

int cnt[maxn+5];
void add(int val){
	if(!cnt[val]) T2.update(val,1);
	cnt[val]++;
} 
void del(int val){
	cnt[val]--;
	if(!cnt[val]) T2.update(val,-1);
}
int ans1[maxm+5];
int ans2[maxm+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		T1.update(root[i],root[i-1],a[i],1,n);
	}
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		qread(q[i].a);
		qread(q[i].b);
		q[i].id=i;
	}
	bsz=n/sqrt(m);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	sort(q+1,q+1+m);
	register int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]); 
		ans1[q[i].id]=T1.query(root[q[i].l-1],root[q[i].r],q[i].a,q[i].b,1,n);
		ans2[q[i].id]=T2.query(q[i].a,q[i].b);
	}
	for(int i=1;i<=m;i++){
		qprint(ans1[i]);
		putchar(' ');
		qprint(ans2[i]);
		putchar('\n');
	}
}
