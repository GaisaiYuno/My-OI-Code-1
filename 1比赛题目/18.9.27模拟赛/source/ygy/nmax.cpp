#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<deque>
#include<exception>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<list>
#include<map>
#include<new>
#include<queue>
#include<stack>
#include<vector>
#define FOR(i,s,t) for(int i=(s);i<=(t);i++)
#define REV(i,s,t) for(int i=(s);i>=(t);i--)
#define high(x) x/(int)floor(sqrt(v.u))
#define low(x) x%(int)floor(sqrt(v.u))
#define index(x,y) x*(int)floor(sqrt(v.u))+y
using namespace std;
inline char gc() {
	static char bb[10000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,10000000,stdin),s==t)?EOF:*s++;
}
inline int read() {
	register int x=0;
	register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=gc();
	return x;
}
int n,m,k;
void chkmin(int &x,int y) {
	x=min(x,y);
}
void chkmax(int &x,int y) {
	x=max(x,y);
}
int arr[500005];
int s[500005];
int tail;
double ans;
void out(int x) {
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
void fout(double x) {
	cerr<<x<<endl;
	if(x==0)return;
	x*=10;
	putchar(int(x)+'0');
	fout(x-(int)(x));
}
int main() {
	freopen("nmax.in","r",stdin);
	freopen("nmax.out","w",stdout);
	n=read();
	FOR(i,1,n) {
		int op=read();
		if(op-2) {
			arr[++tail]=read();
			s[tail]=s[tail-1]+arr[tail];
			int lb=1,rb=tail-1;
			double ta=0;
			if(tail==1) {
				ta=arr[tail];
			}
			if(tail==2) {
				ta=arr[tail]+arr[tail-1];
				ta/=2;
			}
			while(lb<rb) {
				int che1=(lb+rb)/2;
				int che2=che1+1;
				double a1=((double)s[che1]+(double)(arr[tail]))/(che1+1);
				double a2=(((double)s[che2]+(double)(arr[tail]))/(che2+1));
				if(a1>a2)lb=che1+1;
				else if(a1<a2)rb=che2-1;
				if(a1==a2)lb++;
				ta=min(a1,a2);
			}
			ans=arr[tail]-ta;
		} else {
//			cout<<fixed<<setprecision(10)<<ans<<endl;
			printf("%.10lf\n",ans);
		}
	}
}

