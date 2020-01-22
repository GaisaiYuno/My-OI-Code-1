#include<bits/stdc++.h>

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
	
	/*
		Brute Force DFS.
		Time Complexity : O(nk)~O(n^2k)
	*/
	
	const unsigned int N=100005;

	unsigned int n,k,ans;
	vector<unsigned int>graph[N];
	unsigned int c[N];
	
	void dfs (unsigned int now,unsigned int father,unsigned int time) {
		ans+=c[now];
		if (time==k) return;
		for (register unsigned int i=0; i<graph[now].size(); ++i) {
			unsigned int to=graph[now][i];
			if (to==father) continue;
			dfs(to,now,time+1);
		}
	}

	inline void solve () {
    	read(n),read(k);
    	for (register unsigned int i=1; i<=n-1; ++i) {
    		unsigned int x,y;
    		read(x),read(y);
    		graph[x].push_back(y),graph[y].push_back(x);
		}
		for (register unsigned int i=1; i<=n; ++i) {
			read(c[i]);
		}
		for (register unsigned int i=1; i<=n; ++i) {
			ans=0,dfs(i,i,0);
			write(ans),putchar('\n');
		}
    }
}

using namespace Solve;

int main () {
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
    solve();
}

