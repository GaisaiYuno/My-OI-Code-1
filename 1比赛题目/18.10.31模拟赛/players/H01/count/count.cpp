#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

namespace StandardIO {

	template<typename T>
	inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}
	template<typename T>
	inline void write (T x) {
		if (x<0) putchar('-'),x=-x;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

namespace Fate {
	
	const int N=300300;
	
	int n,m,type,size;
	int a[N];
	int st[N][30];
	
	inline void init () {
		for (register int i=1; i<=n; ++i) st[i][0]=a[i];
		for (register int i=1; i<=size; ++i) {
			for (register int j=1; j<=n; ++j) {
				if (j+(1<<(i-1))>n) break;
				st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
	}
	inline int query (int l,int r) {
		if (l==r) return a[l];
		int x=log2(r-l+1); 
		return max(st[l][x-1],st[r-(1<<(x-1))][x-1]);
	}

	inline void Stay_Night() {
		read(n),read(m),read(type);
		for (register int i=1; i<=n; ++i) {
			read(a[i]);
		}
		size=log2(n);
		init();
		int last=0;
		while (m--) {
			int l,r;
			read(l),read(r);
			int ans=0; 
			if (type==1) {
				int u=(l+last-1)%n+1,v=(r+last-1)%n+1;
				l=min(u,v),r=max(u,v);
			}
			for (register int i=l; i<=r; ++i) {
				for (register int j=i+1; j<=r; ++j) {
					if (i==j-1||min(a[i],a[j])>query(i+1,j-1)) ++ans;
				}
			}
			write(ans),putchar('\n');
			last=ans; 
		} 
	}

}

int main () {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	Fate::Stay_Night();
}

