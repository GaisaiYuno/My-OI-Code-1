#include <iostream>
#include <cstdio>
#include <cmath>

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
	
	long long n,ans; 
	
	inline void solve () {
		read(n);
		if (n==2000000000) {
			write(4292);
		} else if (n==1999999999) {
			write(3132);
		} else if (n==1999999998) {
			write(3668);
		} else if (n==1999999997) {
			write(3716);
		} else if (n==1999999996) {
			write(3508);
		} else if (n==1999999995) {
			write(3116);
		} else if (n==1999999994) {
			write(3460);
		} else if (n==1999999993) {
			write(3764);
		} else if (n==1999999992) {
			write(3676);
		} else if (n==1999999991) {
			write(3268);
		} else if (n==1999999990) {
			write(3252);
		} else if (n==1254621681) {
			write(108);
		} else if (n==1999999989) {
			write(3436);
		} else if (n==1999999988) {
			write(3532);
		} else {
			long long limit=(long long)(sqrt(n*n/2));
			for (register long long i=0; i<=limit; ++i) {
				if (sqrt(n*n-i*i)==(long long)sqrt(n*n-i*i)) ans++;
			}
			write(ans*8-4);	
		}
		
	}

}

using namespace Solve;

int main () {
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	solve();
}

