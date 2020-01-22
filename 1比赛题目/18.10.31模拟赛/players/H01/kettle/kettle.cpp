#include <iostream>
#include <cstdio>
#include <cstring>

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

	const int N=2020;
	const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	
	int h,w,p,q,ans;
	int x[N],y[N],city[N][N],vis[N][N];
	char mp[N][N];

	void dfs (int nowx,int nowy,int destx,int desty,int step,int maxn) {
		if (maxn>ans) return;
		if (nowx==destx&&nowy==desty) {
			ans=min(ans,maxn);
			return;
		}
		for (register int i=0; i<4; ++i) {
			int tmpx=nowx+d[i][0],tmpy=nowy+d[i][1];
			if (mp[tmpx][tmpy]=='#') continue;
			if (tmpx<1||tmpx>h||tmpy<1||tmpy>w) continue;
			if (vis[tmpx][tmpy]) continue;
			if (city[tmpx][tmpy]) step=-1;
			vis[tmpx][tmpy]=1;
			dfs(tmpx,tmpy,destx,desty,step+1,max(maxn,step+1));
			vis[tmpx][tmpy]=0;
		}
	}

	inline void Stay_Night() {
		read(h),read(w),read(p),read(q);
		for (register int i=1; i<=h; ++i) {
			for (register int j=1; j<=w; ++j) {
				cin>>mp[i][j];
			}
		}
		for (register int i=1; i<=p; ++i) {
			read(x[i]),read(y[i]);
			city[x[i]][y[i]]=1;
		}
		for (register int i=1; i<=q; ++i) {
			int s,t;
			read(s),read(t);
			memset(vis,0,sizeof(vis));
			ans=2147483647;
			vis[x[s]][y[s]]=1;
			dfs(x[s],y[s],x[t],y[t],0,0);
			write(ans),putchar('\n');
		}
	}

}

int main () {
	freopen("kettle1.in","r",stdin);
	freopen("kettle.out","w",stdout);
	Fate::Stay_Night();
}

