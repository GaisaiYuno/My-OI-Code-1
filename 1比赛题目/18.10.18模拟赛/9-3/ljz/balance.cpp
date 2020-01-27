#include <bits/stdc++.h>

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
	const int COLONY=101;
	const int INF=2147483647;
	const int DIRE[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	
	int n,limitx,limity;
	int x[N],y[N];
	struct node {
		int x,y,val;
	}mass[COLONY];
	
	inline int calc (int xl,int yl) {
		int ans1=0,ans2=0,ans3=0,ans4=0;
		for (register int i=1; i<=n; ++i) {
			if (x[i]<xl&&y[i]<yl) ans1++;
			else if (x[i]<xl&&y[i]>yl) ans2++;
			else if (x[i]>xl&&y[i]<yl) ans3++;
			else ans4++;
		}
		return max(max(max(ans1,ans2),ans3),ans4);
	}
	inline void gen () {
		srand((unsigned)time(NULL));
		for (register int i=1; i<COLONY; ++i) {
			mass[i].x=rand()%(limitx/2+1)*2,mass[i].y=rand()%(limity/2+1)*2;
			mass[i].val=calc(mass[i].x,mass[i].y);
		} 
	} 
	inline pair<int,int> best_two () {
		int fir=INF,sec=INF,firi,seci;
		for (register int i=1; i<COLONY; ++i) {
			if (mass[i].val<fir) {
				sec=fir,seci=firi;
				fir=mass[i].val,firi=i;
			}
		}
		return make_pair(firi,seci);
	}
	inline pair<int,int> worst_two () {
		int fir=0,sec=0,firi,seci;
		for (register int i=1; i<COLONY; ++i) {
			if (mass[i].val>fir) {
				sec=fir,seci=firi;
				fir=mass[i].val,firi=i;
			}
		}
		return make_pair(firi,seci);
	}
	inline void breed (int index) {
		while (1) {
			int choice=rand()%4;
			int xd=DIRE[choice][0]+mass[index].x;
			int yd=DIRE[choice][1]+mass[index].y;
			if (xd>=1&&xd<=limitx&&yd>=1&&yd<=limity) {
				mass[index].x=xd,mass[index].y=yd;
				mass[index].val=calc(xd,yd);
				return;
			}
		}
	}
	inline void mutant (int index) {
		mass[index].x=rand()%(limitx/2+1)*2,mass[index].y=rand()%(limity/2+1)*2;
		mass[index].val=calc(mass[index].x,mass[index].y);
	}
	inline void darwin () {
		gen();
		for (register int i=1; i<=100; ++i) {
			pair<int,int>bt=best_two();
			pair<int,int>wt=worst_two();
			mass[wt.first]=mass[bt.first],mass[wt.second]=mass[bt.second];
			int pos=rand()%100+1;
			if (pos>10) breed(bt.first),breed(bt.second);
			else mutant(bt.first),mutant(bt.second);
		}
		write(mass[best_two().first].val);
	}

	inline void solve () {
		read(n);
		for (register int i=1; i<=n; ++i) {
			read(x[i]),read(y[i]);
			limitx=max(limitx,x[i]),limity=max(limity,y[i]);
		}
		darwin();
	}

}

using namespace Solve;

int main () {
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	solve();
}


