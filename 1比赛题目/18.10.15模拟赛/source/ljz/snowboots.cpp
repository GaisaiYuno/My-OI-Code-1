#include <bits/stdc++.h>

using namespace std;

namespace StandardIO {

	template<typename T>inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}

	template<typename T>inline void write (T x) {
		if (x<0) putchar('-'),x*=-1;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

namespace Solve {
	
	const int N=100100;
	const int INF=2147483647;
	
	struct node {
		int l,r,val;
	}tree[N<<2];
	int n,m;
	int f[N];
	
	inline void pushup (int pos) {
		tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
	}
	
	inline void build (int l,int r,int pos) {
		tree[pos].l=l,tree[pos].r=r;
		if (l==r) {
			tree[pos].val=f[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1),build(mid+1,r,pos<<1|1);
		pushup(pos);
	}
	
	inline int query (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			return tree[pos].val;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1,ans=INF;
		if (l<=mid) ans=min(ans,query(l,r,pos<<1));
		if (mid<r) ans=min(ans,query(l,r,pos<<1|1));
		return ans;
	}

	inline void solve () {
		read(n),read(m);
		for (register int i=1; i<=n; ++i) {
			read(f[i]);
		}
		build(1,n,1);
		for (register int i=1; i<=m; ++i) {
			int s,d,cur=1,flag=1;
			read(s),read(d);
			while (cur<n) {
//				cout<<query(2,6)<<endl;
				if (query(cur+1,min(n,cur+d),1)>s) {
					write(0),flag=0;
					break;
				}
//				cout<<cur<<' ';
				for (register int j=min(n,cur+d); j>=cur+1; --j) {
					if (f[j]<=s) {
						cur=j;
						break;
					}
				}
			}
			if (flag) {
				write(1);
			}
			putchar('\n');
		}
	}

}

using namespace Solve;

int main () {
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	solve();
}

