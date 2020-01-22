#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define SIZE 3
#define mod 1000000007
#define maxn 100005
using namespace std;
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
inline void qprint(long long x) {
	char ch[32];
	int k=0;
	if(x==0) {
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0) {
		putchar('-');
		x=-x;
	}
	while(x>0) {
		ch[k++]='0'+x%10;
		x/=10;
	}
	for(int i=k-1; i>=0; i--) putchar(ch[i]);
	putchar('\n');
}
struct matrix {
	int n;
	int m;
	long long a[SIZE][SIZE];
	matrix() {
		n=2;
		m=2;
		memset(a,0,sizeof(a));
	}
	matrix(int x,int y) {
		n=x;
		m=y;
		memset(a,0,sizeof(a));
	}
	void print() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	void setv(int x) {
		if(x==0) {
			memset(a,0,sizeof(a));
		}
		if(x==1) {
			memset(a,0,sizeof(a));
			for(int i=1; i<=n; i++) a[i][i]=1;
		}
	}
	friend matrix operator +(matrix x,matrix y) {
		matrix tmp=matrix(x.m,y.m);
		for(int i=1; i<=x.n; i++) {
			for(int j=1; j<=y.m; j++) {
				tmp.a[i][j]=x.a[i][j]+y.a[i][j];
				tmp.a[i][j]%=mod;
			}
		}
		return tmp;
	}
	friend matrix operator *(matrix x,matrix y) {
		matrix tmp=matrix(x.m,y.m);
		for(int i=1; i<=x.n; i++) {
			for(int j=1; j<=y.m; j++) {
				tmp.a[i][j]=0;
				for(int k=1; k<=y.n; k++) {
					tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
//					tmp.a[i][j]%=mod; 取模次数太多会TLE！ 
				}
				tmp.a[i][j]%=mod;
			}
		}
		return tmp;
	}
};
matrix fast_pow(matrix x,int k) {
	matrix ans=matrix(2,2);
	ans=x;
	if(k==0) {
		ans.setv(1);
		return ans;
	}
	k--;
	while(k>0) {
		if(k&1) {
			ans=ans*x;
		}
		k>>=1;
		x=x*x;
	}
	//ans.print();
	return ans;  
}
matrix Fibo_mat=matrix(2,2);
long long get_Fibo(matrix r) {
	return r.a[1][1];
}

struct tree_node {
	int l;
	int r;
	int is_mark;
	matrix mark;
	matrix v;
	int len() {
		return r-l+1;
	}
} tree[maxn<<2];
int a[maxn];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].is_mark=0;
	tree[pos].mark.setv(1);
	if(l==r) {
		tree[pos].v=fast_pow(Fibo_mat,a[l]-1);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos) {
	if(tree[pos].is_mark) {
		tree[pos<<1].is_mark=1;
		tree[pos<<1].mark=tree[pos<<1].mark*tree[pos].mark;
		tree[pos<<1].v=tree[pos<<1].v*tree[pos].mark;
		tree[pos<<1|1].is_mark=1;
		tree[pos<<1|1].mark=tree[pos<<1|1].mark*tree[pos].mark;
		tree[pos<<1|1].v=tree[pos<<1|1].v*tree[pos].mark;
		tree[pos].is_mark=0;
		tree[pos].mark.setv(1);
	}
}
void update(int L,int R,matrix k,int l,int r,int pos) {
	if(L<=l&&R>=r) {
		tree[pos].is_mark=1;
		tree[pos].mark=tree[pos].mark*k;
		tree[pos].v=tree[pos].v*k;
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,k,l,mid,pos<<1);
	if(R>mid) update(L,R,k,mid+1,r,pos<<1|1);
	push_up(pos);
}
long long query(int L,int R,int l,int r,int pos) {
	if(L<=l&&R>=r) {
		return tree[pos].v.a[1][1];
	}
	push_down(pos);
	long long ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans=ans+query(L,R,l,mid,pos<<1)%mod;
	if(R>mid)  ans=ans+query(L,R,mid+1,r,pos<<1|1)%mod;
	return ans;
}
int n,m;
int main() {
//	freopen("segtree.in","r",stdin);
//	freopen("segtree.out","w",stdout);
	Fibo_mat.a[1][1]=1;
	Fibo_mat.a[1][2]=1;
	Fibo_mat.a[2][1]=1;
	Fibo_mat.a[2][2]=0;
//	fastpow(Fibo_mat,2).print();
//	cout<<get_Fibo(fastpow(Fibo_mat,))<<endl;
	int cmd,l,r,x;
	n=qread();
	m=qread();
	for(int i=1; i<=n; i++) a[i]=qread();
	build(1,n,1);
	while(m--) {
		cmd=qread();
		l=qread();
		r=qread();
		if(cmd==1) {
			x=qread();
			update(l,r,fast_pow(Fibo_mat,x),1,n,1);
		} else if(cmd==2) {
			qprint(query(l,r,1,n,1)%mod);
		}
	}
}

