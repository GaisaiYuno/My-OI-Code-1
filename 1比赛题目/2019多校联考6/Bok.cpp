//https://codeforces.com/contest/1137/problem/E
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300000 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
inline void qread(int& x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

struct point {
	ll x;
	ll y;
	point() {

	}
	point(ll _x,ll _y) {
		x=_x;
		y=_y;
	}
};
db slope(point p,point q) {
	return (db)(p.y-q.y)/(p.x-q.x);
}
int top;
point st[maxn+5];

int n,m;
ll sums[maxn+5],sumb[maxn+5];
inline ll calc(point p,int i) {
	return (p.x-1)*sums[i]+p.y+sumb[i];
}

int main() {
	int cmd,k,b,s;
	qread(n);
	qread(m);
	top=0;
	st[++top]=point(1,0); 
	for(int i=1; i<=m; i++) {
		qread(cmd);
		sums[i]=sums[i-1];
		sumb[i]=sumb[i-1];
		if(cmd==1) {
			qread(k);
			top=0;
			st[++top]=point(1,0); 
			sums[i]=0;
			sumb[i]=0;
			n+=k;
		} else if(cmd==2) {
			qread(k);
			point x=point(n+1,-calc(point(n+1,0),i));
			while(top>1&&slope(st[top],st[top-1])>=slope(x,st[top-1])) top--;
			st[++top]=x;
			n+=k;
		} else {
			qread(b);
			qread(s);
			sums[i]+=s;
			sumb[i]+=b;
		}
		while(top>1&&calc(st[top],i)>=calc(st[top-1],i)) top--;
		printf("%lld %lld\n",st[top].x,calc(st[top],i));
	}
}
