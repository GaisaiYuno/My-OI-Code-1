//可以挨个枚举一条线上的点，三分出另一条线上离他最近的点进行连边。

//注意N、M可能为0
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 50010
//#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
//const double pi = acos(-1.0);
//const double inf = ~0u>>2;
struct point {
	double x,y;
	int id;
	point(double x=0,double y = 0):x(x),y(y) {}
} p[N],q[N];
struct node {
	int u,v;
	double w;
} ed[N<<4];
int fa[N],g;
double t1[N],t2[N];
point a,b,c,d;
//typedef point pointt;
point operator -(point a,point b) {
	return point(a.x-b.x,a.y-b.y);
}
int dcmp(double x) {
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}

double dis(point a) {
	return sqrt(a.x*a.x+a.y*a.y);
}
bool cmmp(node ta,node tb) {
	return ta.w<tb.w;
}
int findx(int x) {
	if(x!=fa[x])
		fa[x] = findx(fa[x]);
	return fa[x];
}
void add(point ta,point tb) {
	ed[++g].u = ta.id;
	ed[g].v = tb.id;
	ed[g].w = dis(ta-tb);
}
int main() {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int t,i,n,m;
	int kk = 0;
	cin>>t;
	while(t--) {
		scanf("%d%d",&n,&m);
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
		for(i = 0; i <= n+m ; i++)
			fa[i] = i;
		for(i = 0; i < n; i++) {
			scanf("%lf",&t1[i]);

			// cout<<p[i].x<<" "<<p[i].y<<endl;
		}
		for(i = 0; i< m; i++) {
			scanf("%lf",&t2[i]);

		}
		sort(t1,t1+n);
		sort(t2,t2+m);
		int h=0;
		for(i=0;i<n;i++)
		    if(i==n-1||t1[i]!=t1[i+1])
		        t1[h++]=t1[i];
		n=h;
		h=0;
		for(i=0;i<m;i++)
		    if(i==m-1||t2[i]!=t2[i+1])
		        t2[h++]=t2[i];
		m=h;
		for(i = 0; i < n; i++) {
			p[i] = point(a.x*t1[i]+b.x*(1-t1[i]),a.y*t1[i]+b.y*(1-t1[i]));
			p[i].id = i+1;
		}
		for(i = 0 ; i < m ; i++) {
			q[i] = point(c.x*t2[i]+d.x*(1-t2[i]),c.y*t2[i]+d.y*(1-t2[i]));
			q[i].id = i+n+1;
		}
		g = 0;
		double sum1 = 0,sum2 = 0;
		for(i = 0 ; i < n-1 ; i++) {
			add(p[i],p[i+1]);
			sum1+=dis(p[i]-p[i+1]);
		}
		for(i = 0 ; i < m-1 ; i++) {
			add(q[i],q[i+1]);
			sum2+=dis(q[i]-q[i+1]);
		}
		if(n==0||m==0) {

			printf("Case #%d: %.3lf\n",++kk,sum1+sum2);
			continue;
		}
		for(i = 0; i < n; i++) {
//            point pp ;
//            if(dcmp(c.x-d.x)==0)
//            pp = point(c.x,p[i].y);
//            else
//            pp = dispoint(c,d,p[i]);
//            if(dcmp(pp.x-min(c.x,d.x))<=0||dcmp(pp.x-max(c.x,d.x))>=0)
//            {
//                add(i,n+1);
//                if(n+2<n+m)
//                add(i,n+2);
//                if(n+m-1>n+1)
//                add(i,n+m-1);
//                add(i,n+m);
//                continue;
//            }
//            int k = find(n+1,n+m,c,dis(pp-c));
			// cout<<p[k].id<<" "<<pp.x<<" "<<pp.y<<endl;
//            add(i,k);
//            if(k!=n+1)
//            add(i,k-1);
//            if(k!=n+m)
//            add(i,k+1);
			int l, r;
			l = 0;
			r = m-1;
			while (r - l > 1) {
				int mid1 = (r + l) >> 1;
				int mid2 = (mid1 + r) >> 1;
				if (dis(p[i]-q[mid1]) > dis(p[i]-q[mid2]))
					l = mid1;
				else
					r = mid2;
			}
//            int k = find(1,n,a,dis(pp-a));
			add(p[i],q[l]);
			add(p[i],q[r]);
			if(l-1>=0)
				add(p[i],q[l-1]);
			if(r+1<=m-1)
				add(p[i],q[r+1]);
		}
		sort(ed+1,ed+g+1,cmmp);
		int num = 0;
		double sum = 0;
		for(i = 1; i <= g; i++) {
			int tx = findx(ed[i].u);
			int ty = findx(ed[i].v);
			if(tx!=ty) {
				fa[tx] = ty;
				num++;
				sum+=ed[i].w;
			}
		}
		printf("Case #%d: %.3f\n",++kk,sum);
	}
	return 0;
}
