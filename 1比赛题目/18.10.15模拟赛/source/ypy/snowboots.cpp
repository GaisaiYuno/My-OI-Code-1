//强制离线
//对于每个询问将小于s的位置插进去
//统计最大差距
//用线段树，初始0，插入的位置标记为1，求最长连续0长度，距离即为长度+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,b;
inline long long qread() {
	long long x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

int a[maxn];

struct snow{
	int d;
	int i;
	friend bool operator <(snow a,snow b){
		return a.d<b.d;
	}
}t[maxn];

struct shoe {
	int s;
	int d;
	int id;
	friend bool operator < (shoe a,shoe b) {
		if(a.s==b.s) return a.d<b.d;
		else return a.s<b.s;
	}
} q[maxn];

struct segment_tree {
	struct node {
		int l;
		int r;
		int lmax;
		int rmax;
		int maxv;
		int mark;
		int len() {
			return r-l+1;
		}
	} tree[maxn<<2];
	void push_up(int pos) {
		tree[pos].lmax=tree[pos<<1].lmax;
		if(tree[pos<<1].lmax==tree[pos<<1].len()) tree[pos].lmax=tree[pos<<1].len()+tree[pos<<1|1].lmax;
		tree[pos].rmax=tree[pos<<1|1].rmax;
		if(tree[pos<<1|1].rmax==tree[pos<<1|1].len()) tree[pos].rmax=tree[pos<<1|1].len()+tree[pos<<1].rmax;
		tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv);
		tree[pos].maxv=max(tree[pos<<1].rmax+tree[pos<<1|1].lmax,tree[pos].maxv);
	}
	void build(int l,int r,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].mark=0;
		if(l==r) {
			tree[pos].lmax=tree[pos].rmax=tree[pos].maxv=1;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void update(int tpos,int v,int pos) {
		if(tree[pos].l==tree[pos].r) {
			tree[pos].lmax=tree[pos].rmax=tree[pos].maxv=0;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) update(tpos,v,pos<<1);
		else update(tpos,v,pos<<1|1);
		push_up(pos);
	}
}T;

int ans[maxn];
int main() {
//	freopen("snowboots.in","r",stdin);
//	freopen("snowboots.out","w",stdout);
	n=qread();
	b=qread();
	for(int i=1; i<=n; i++) {
		a[i]=qread();
		t[i].d=a[i];
		t[i].i=i;
	}
	for(int i=1; i<=b; i++) {
		q[i].s=qread();
		q[i].d=qread();
		q[i].id=i;
	}
	sort(q+1,q+1+b);
	sort(t+1,t+1+n);
	T.build(1,n,1);
	int j=1;
	for(int i=1;i<=b;i++){
		while(t[j].d<=q[i].s&&j<=n){
			T.update(t[j].i,0,1);
			j++;
		}
		ans[q[i].id]=T.tree[1].maxv+1<=q[i].d?1:0;
	}
	for(int i=1;i<=b;i++){
		if(ans[i]==1) putchar('1');
		else putchar('0');
		putchar('\n');
	}
}
