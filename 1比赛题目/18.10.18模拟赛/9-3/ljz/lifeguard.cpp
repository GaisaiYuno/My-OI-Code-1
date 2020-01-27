#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

namespace StandardIO {

	template<typename T> inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}
	template<typename T> inline void write (T x) {
		if (x<0) putchar('-'),x=-x;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

namespace Solve {
	
	const int N=100100;
	
	int n,k,ans,limit=0;
	struct node {
		int l,r;
		inline bool operator < (const node &x) const {
			return (r-l)>(x.r-x.l);
		} 
	}a[N];
	struct tnode {
		int l,r,val,tag;
	}tree[N<<2];
	
	inline void pushup (int pos) {
		tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
	}
	inline void pushdown (int pos) {
		if (tree[pos].tag) {
			tree[pos<<1].tag+=tree[pos].tag,tree[pos<<1|1].tag+=tree[pos].tag;
			tree[pos<<1].val+=(tree[pos<<1].r-tree[pos<<1].l+1)*tree[pos].tag;
			tree[pos<<1|1].val+=(tree[pos<<1|1].r-tree[pos<<1|1].l+1)*tree[pos].tag;
			tree[pos].tag=0;
		}
	}
	void build (int l,int r,int pos) {
		tree[pos].l=l,tree[pos].r=r;
		if (l==r) {
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1),build(mid+1,r,pos<<1|1);	 
	}
	void update (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			tree[pos].val+=(tree[pos].r-tree[pos].l+1);
			return;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if (l<=mid) update(l,r,pos<<1);
		if (mid<r) update(l,r,pos<<1|1);
		pushup(pos);
	}
	int query (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			return tree[pos].val;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1,ans=0;
		if (l<=mid) ans+=query(l,r,pos<<1);
		if (mid<r) ans+=query(l,r,pos<<1|1);
		return ans;
	}

	inline void solve () {
		read(n),read(k);
		for (register int i=1; i<=n; ++i) {
			read(a[i].l),read(a[i].r);
			limit=max(limit,a[i].r);
		}
		sort(a+1,a+n+1); 
		build(1,limit-1,1);
		for (register int i=1; i<=n-k; ++i) {
			update(a[i].l,a[i].r-1,1);
		}
		cout<<query(1,limit-1,1);
	}

}

using namespace Solve;

int main () {
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout);
	solve();
}


