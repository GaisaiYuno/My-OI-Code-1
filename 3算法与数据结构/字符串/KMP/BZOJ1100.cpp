#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
using namespace std;
typedef long long ll;

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
typedef point Vector;
Vector operator + (Vector p,Vector q) {
	return Vector(p.x+q.x,p.y+q.y);
}
Vector operator - (Vector p,Vector q) {
	return Vector(p.x-q.x,p.y-q.y);
}
ll dot(Vector p,Vector q) {
	return p.x*q.x+p.y*q.y;
}
ll cross(Vector p,Vector q) {
	return p.x*q.y-p.y*q.x;
}
ll dist(point p,point q){
	return dot(p-q,p-q);
}
int t,n;
point p[maxn+5];
ll a[maxn*4+5];
ll b[maxn*4+5];
int KMP(ll *a,int n,ll *b,int m) {
	static int nex[maxn*4+5];
	nex[1]=0;
	for(int i=2,j=0; i<=n; i++) {
		while(j>0&&a[j+1]!=a[i]) j=nex[j];
		if(a[j+1]==a[i]) j++;
		nex[i]=j;
	}
	int ans=0;
	for(int i=2,j=0; i<=m; i++) {
		while(j>0&&a[j+1]!=b[i]) j=nex[j];
		if(a[j+1]==b[i]) j++;
		if(j==n) ans++;
	}
	return ans;
}

void ini(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
int main() {
	scanf("%d",&t);
	while(t--) {
		ini();
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%lld %lld",&p[i].x,&p[i].y);
		int tn=0;
		for(int i=0; i<n; i++) {
			a[++tn]=dist(p[i],p[(i+1)%n]);
			a[++tn]=cross(p[(i+1)%n]-p[i],p[(i+2)%n]-p[(i+1)%n]);
		}
		for(int i=1; i<=tn; i++) b[i]=a[tn-i+1];
		for(int i=1; i<=tn; i++) a[i+tn]=a[i];
		printf("%d\n",KMP(b,tn,a,tn*2));
	}
}

