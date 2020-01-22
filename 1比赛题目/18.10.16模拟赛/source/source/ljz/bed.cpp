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
		Binary Search + Sparse Table
		Time Complexity : O(nlogn)
	*/
	
	const int N=300300;
	const int INF=0x3f3f3f3f;
	
	int n,k,ans=0;
	int d[N];
	int maxn[N][21],minn[N][21];
	
	inline void init () {
		memset(maxn,0,sizeof(maxn)),memset(minn,INF,sizeof(minn));
		for (register int i=1; i<=n; ++i) maxn[i][0]=minn[i][0]=d[i];
		for (register int j=1; (1<<j)<=n; ++j) {
			for (register int i=n; i>=1; --i) {
				if (i+(1<<j)>n) continue;
				maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
				minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
			}
		}
	}
	
	inline int query (int l,int r,int type) {
		int x=log2(r-l+1);
		if (type==1) {
			return max(maxn[l][x],maxn[r-(1<<x)+1][x]);
		}
		return min(minn[l][x],minn[r-(1<<x)+1][x]);
	}
	
	inline bool check (int left,int right) {
		if (query(left,right,1)-query(left,right,2)<=k) return true;
		return false;
	}

    inline void solve () {
		read(n),read(k);
		for (register int i=1; i<=n; ++i) {
			read(d[i]);
		}
		init();
		for (register int i=1; i<=n; ++i) {
			int le=i-1,ri=n+1,mi;
			while (le<ri-1) {
				mi=(le+ri)>>1;
				if (check(i,mi)) le=mi;
				else ri=mi;
			}
			ans=max(ans,(le-i+1));
		}
		write(ans);
    }
}

using namespace Solve;

int main () {
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
    solve();
}


