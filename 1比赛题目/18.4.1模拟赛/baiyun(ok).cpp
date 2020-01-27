#include<stdio.h>
#include<cstring>
#include<algorithm>
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int gcd(int a,int b) {
	if(a%b==0)	return b;
	return gcd(b,a%b);
}
const int Size=1000013;
int n,k,a[Size];
bool flag;
struct node {
	int l,r;
	int val;		//维护gcd
} tree[Size<<1];
inline void Pushup(int rt) {
	tree[rt].val=gcd(tree[lc].val,tree[rc].val);
}
void Build(int l,int r,int rt) {
	tree[rt].l=l;
	tree[rt].r=r;
	tree[rt].val=0;
	if(l==r) {
		tree[rt].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	Build(l,mid,lc);
	Build(mid+1,r,rc);
	Pushup(rt);
}
void Update(int pos,int rt,int v) {
	if(tree[rt].l==tree[rt].r) {
		tree[rt].val=v;
		return;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(pos<=mid) {
		Update(pos,lc,v);
	} else {
		Update(pos,rc,v);
	}
	Pushup(rt);
}
bool Query(int l,int r,int rt,int v) {
	if(l<=tree[rt].l && tree[rt].r<=r) {
		if(tree[rt].val%v==0) {
			return true;
		} else {
			if(flag) {
				return false;
			} else {
				if(!(tree[rt].r-tree[rt].l)) {
					//如果是叶子节点才返回真！ 
					//不是叶子节点就继续递归查找 
					flag=true;
					return true;
				}
			}
		}
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	bool ans=true;
	if(l<=mid)	ans=ans&&Query(l,r,lc,v);
	if(r>mid)	ans=ans&&Query(l,r,rc,v);
	return ans;
}
inline void init() {
	n=read();
	for(int i=1; i<=n; i++)
		a[i]=read();
	Build(1,n,1);
	k=read();
}
int main() {
//	freopen("baiyun.in","r",stdin);
//	freopen("baiyun.out","w",stdout);
	init();
	int dir;
	while(k--) {
		flag=false;
		dir=read();
		if(dir==1) {
			int q=read();
			int z=read();
			int y=read();
			if(Query(q,z,1,y)) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			int p=read();
			int q=read();
			Update(p,1,q);
		}
	}
	return 0;
}
/*
6
11 33 34 26 17 16
12
1 6 6 1
2 2 20
1 1 4 2
1 4 6 1
2 1 11
2 1 42
1 1 5 9
1 4 5 6
2 6 40
2 1 49
1 1 4 10
2 3 13
*/
