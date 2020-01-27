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
	const int INF=0x3f3f3f3f;
	
	int n;
	int m[N],sum[N];
	double ans=INF,now;
	
	inline bool check (int start,int end,double &limit) {
		if(end<start)return false;
		double tmp=((double)sum[n]-sum[end]+sum[start-1])/((double)n-end+start-1);
		if (tmp<limit) {
			limit=tmp;
			return true;
		}
		return false;
	}
	
	inline void solve () {
		read(n);
		for (register int i=1; i<=n; ++i) {
			read(m[i]);
			sum[i]=sum[i-1]+m[i];
		}
		for (register int i=2; i<=n-1; ++i) {
			int l=i-1,r=n,mid;
			now=INF;
			while (l<r-1) {
				mid=(l+r)>>1;
				if (check(i,mid,now)) l=mid;
				else r=mid;
			}
			ans=min(ans,now);
		}
		printf("%.3lf",ans);
	}
	
}

using namespace Solve;

int main () {
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	solve();
}
