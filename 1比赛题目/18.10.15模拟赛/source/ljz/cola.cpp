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

#define int long long
namespace Solve {
	
	const int T=1000001;
	const int N=31;
	const int MOD=2017;
	const int INF=2147483647;
	
	int n,m,t,ans;
	int dp[T][N][2],size[N],is_clear[N][N];
	vector<int>graph[N];

	inline void solve () {
		read(n),read(m);
		for (register int i=1; i<=m; ++i) {
			int x,y;
			read(x),read(y);
			graph[x].push_back(y);
			graph[y].push_back(x);
			++size[x],++size[y];
			is_clear[x][y]=is_clear[y][x]=1;
		}
		read(t);
		dp[1][1][0]=dp[1][1][1]=1;
		for (register int city=2; city<=n; ++city) {
			if (is_clear[city][1]) {
				dp[1][city][0]=1;
			}
		}
		for (register int i=2; i<=t; ++i) {
			for (register int city=1; city<=n; ++city) {
				for (register int j=0; j<graph[city].size(); ++j) {
					int to=graph[city][j];
					dp[i][city][0]+=dp[i-1][to][0];
				}
				dp[i][city][0]+=dp[i-1][city][0];
				dp[i][city][0]%=MOD;
				dp[i][city][1]=dp[i-1][city][0];
			}
		}
		for (register int i=1; i<=t; ++i) {
			for (register int city=1; city<=n; ++city) {
				ans+=dp[i][city][1];
				ans%=MOD;
			}
		}
		for (register int city=1; city<=n; ++city) {
			ans+=dp[t][city][0];
			ans%=MOD;
		}
		write(ans);
	}

}
#undef int

using namespace Solve;

int main () {
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	solve();
}

