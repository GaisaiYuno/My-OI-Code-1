#include<stdio.h>
#include<cstring>
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
typedef long long ll;
const int Size=100003;
const int mod=1e9+7;
struct matrix {
    ll a[3][3];
    matrix() {	memset(a,0,sizeof(a));	}
} k,res,STD;
matrix plus(matrix x,matrix y) {
	matrix res;
	for(int i=1; i<=2; i++) {
		for(int j=1; j<=2; j++) {
			res.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
		}
	}
	return res;
}
matrix multi(matrix x,matrix y) {
    matrix res;
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=2; j++) {
        	for(int k=1; k<=2; k++) {
        		res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
        }
    }
    return res;
}
matrix fastpow(matrix c,ll p) {
    matrix res;
    res.a[1][1]=res.a[2][2]=1;
    while(p) {
        if(p&1)	res=multi(res,c);
        c=multi(c,c);
        p=p/2;
    }
    return res;
}
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
int n,m;
struct node {
	int l,r;
	matrix v,lazy;
    inline int len() {
    	return r-l+1;
	}
} tree[Size<<2];
inline void Pushup(int rt) {
	tree[rt].v=plus(tree[lc].v,tree[rc].v);
}
void Pushdown(int rt) {
	tree[lc].lazy=multi(tree[rt].lazy,tree[lc].lazy);
	tree[rc].lazy=multi(tree[rt].lazy,tree[rc].lazy);
	tree[lc].v=multi(tree[lc].v,tree[rt].lazy);
	tree[rc].v=multi(tree[rc].v,tree[rt].lazy);
	tree[rt].lazy=fastpow(STD,0);
}
void Build(int l,int r,int rt) {
	tree[rt].l=l;
	tree[rt].r=r;
	tree[rt].v=tree[rt].lazy=fastpow(STD,0);
	if(l==r) {
		tree[rt].v=fastpow(STD,read()-1);
		return;
	}
	int mid=(l+r)>>1;
	Build(l,mid,lc);
	Build(mid+1,r,rc);
	Pushup(rt);
}
void Update(int l,int r,int rt,matrix v) {
	if(l<=tree[rt].l && tree[rt].r<=r) {
		tree[rt].v=multi(tree[rt].v,v);
		tree[rt].lazy=multi(tree[rt].lazy,v);
		return;
	}
	Pushdown(rt);
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(l<=mid)	Update(l,r,lc,v);
	if(r>mid)	Update(l,r,rc,v);
	Pushup(rt);
}
ll Query(int l,int r,int rt) {
	if(l<=tree[rt].l && tree[rt].r<=r)
		return tree[rt].v.a[1][1];
	Pushdown(rt);
	ll mid=(tree[rt].l+tree[rt].r)>>1,ans=0;
	if(l<=mid)	ans=(ans+Query(l,r,lc))%mod;
	if(r>mid)	ans=(ans+Query(l,r,rc))%mod;
	return ans;
}
void init() {
	STD.a[1][1]=STD.a[1][2]=STD.a[2][1]=1;
	n=read();
	m=read();
	Build(1,n,1);
}
int main() {
	init();
	int dir,l,r,x;
	while(m--) {
		dir=read();
		l=read();
		r=read();
		if(dir==1) {
			x=read();
			matrix c=fastpow(STD,x);
			Update(l,r,1,c);
		} else {
			printf("%I64d\n",Query(l,r,1)%mod);
		}
	}
	return 0;
}
