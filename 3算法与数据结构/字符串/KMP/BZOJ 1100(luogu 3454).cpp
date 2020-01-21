#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;
inline void qread(int &x) {
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

int n;
int T;
struct point {//点 
	long long x;
	long long y;
	point() {

	}
	point(long long xx,long long yy) {
		x=xx;
		y=yy;
	}
	friend point operator +(point a,point b) {
		return point(a.x+b.x,a.y+b.y);
	}
	friend point operator -(point a,point b) {
		return point(a.x-b.x,a.y-b.y);
	}
} a[maxn];
typedef point vector;//在程序实现上，点和向量没有区别 
long long dot(vector a,vector b) {//点积 
	return a.x*b.x+a.y*b.y;
}
long long cross(vector a,vector b) {//叉积 
	return a.x*b.y-a.y*b.x;
}

long long dist(point a,point b) {//计算两点间距离 
	vector v=a-b;
	return dot(v,v);
}

long long work_edge(int x) {//逐一处理多边形的边，注意编号为n的点下一个点是1 
	int y=x+1;
	if(y>n) y=1;
	return dist(a[x],a[y]);
}
long long work_ang(int x) {//处理角，同样注意编号为n的点下一个点是1 
	int y=x+1,z=x+2;
	if(y>n) y=y%n;
	if(z>n) z=z%n;
	return cross(a[y]-a[x],a[z]-a[y]);
}
long long edge[maxn];
long long ang[maxn];
long long tmp[maxn];
int s[maxn*4];
int t[maxn*2];

int next[maxn*4];
int f[maxn*4];
int KMP(int *a,int n,int *b,int m) {//KMP模板 
	next[1]=0;
	for(int i=2,j=0; i<=n; i++) {
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
	for(int i=2,j=0; i<=m; i++) {
		while(j>0&&b[i]!=a[j+1]) j=next[j];
		if(b[i]==a[j+1]) j++;
		f[i]=j;
	}
	int cnt=0;
	for(int i=1; i<=m; i++) {
		if(f[i]==n) cnt++;
	}
	return cnt;
}
int main() {
	int x,y;
	qread(T);
	while(T--) {
		qread(n);
		for(int i=1; i<=n; i++) {
			qread(x);
			qread(y);
			a[i].x=x;
			a[i].y=y;
		}
		for(int i=1; i<=n; i++) {
			edge[i]=work_edge(i);
			ang[i]=work_ang(i);
		}
		int newn=0;
		int newm=0;
		for(int i=1; i<=n; i++) {//由于计算的角是第i与i+1条边之间的夹角，所以先加入边，再加入角 
			s[++newn]=edge[i];
			s[++newn]=ang[i];
		}
		for(int i=1; i<=n; i++) {
			s[++newn]=edge[i];
			s[++newn]=ang[i];
		}
		for(int i=n*2; i>=1; i--) {
			t[++newm]=s[i];
		}
		printf("%d\n",KMP(t,newm,s,newn));
	}
}
