#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
int n,m;
int a[maxn];
inline int qread() {
	int x=0,sign=1;
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
int gcd(int a,int b) {
	if(a==0) return b;
	else if(b==0) return a;
	int tmp=a%b;
	while(tmp!=0) {
		a=b;
		b=tmp;
		tmp=a%b;
	}
	return b;
}
inline int abs(int a) {
	return a>0?a:-a;
}
struct value {
	int lv;
	int rv;
	int gc;
	int maxv;
	int minv;
	friend value operator +(value x,value y) {
		value z;
		z.lv=x.lv;
		z.rv=y.rv;
		z.gc=gcd(gcd(x.gc,y.gc),abs(y.lv-x.rv));
		z.maxv=max(x.maxv,y.maxv);
		z.minv=min(x.minv,y.minv);
		return z;
	}
};
struct node {
	int l;
	int r;
	value val;
	int len() {
		return r-l+1;
	}
	void debug() {
		printf("[%d,%d] a[%d]=%d a[%d]=%d gcd=%d maxv=%d minv=%d\n",l,r,l,val.lv,r,val.rv,val.gc,val.maxv,val.minv);
	}
} tree[2400005];
void push_up(int pos) {
	tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r) {
		tree[pos].val.maxv=a[l];
		tree[pos].val.minv=a[l];
		tree[pos].val.lv=a[l];
		tree[pos].val.rv=a[l];
//		tree[pos].gc=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void update(int tpos,int v,int pos) {
	if(tree[pos].l==tree[pos].r) {
		tree[pos].val.maxv=v;
		tree[pos].val.minv=v;
		tree[pos].val.lv=v;
		tree[pos].val.rv=v;
//		tree[pos].gc=v;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) update(tpos,v,pos<<1);
	else update(tpos,v,pos<<1|1);
	push_up(pos);
}
value query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].val;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(R<=mid) return query(L,R,pos<<1);
	else if(L>mid) return query(L,R,pos<<1|1);
	else return query(L,R,pos<<1)+query(L,R,pos<<1|1);
}
int main() {
	n=qread();
	m=qread();
	for(int i=1; i<=n; i++) a[i]=qread();
	int last_ans=0;
	build(1,n,1);
	int cmd,l,r,k;
	for(int i=1; i<=m; i++) {
		cmd=qread();
		if(cmd==1) {
			l=qread();
			r=qread();
			l^=last_ans;
			r^=last_ans;
			update(l,r,1);
		} else {
			l=qread();
			r=qread();
			k=qread();
			l^=last_ans;
			r^=last_ans;
			k^=last_ans;
			value now=query(l,r,1);
//			now.debug();
			if((now.gc==k&&now.maxv-now.minv==k*(r-l))||l==r) {
				printf("Yes\n");
				last_ans++;
			} else printf("No\n");
		}
	}
}
