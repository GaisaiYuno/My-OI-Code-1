//http://119.29.55.79/contest/76/problem/3 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set> 
#include<cmath>
#include<algorithm>
#define eps 1e-6 
#define maxn 100000
#define maxq 200000
using namespace std;
struct Vector{
	double x;
	double y;
	Vector(){
		
	}
	Vector(double _x,double _y){
		x=_x;
		y=_y;
	}
	friend Vector operator + (Vector p,Vector q){
		return Vector(p.x+q.x,p.y+q.y);
	}
	friend Vector operator - (Vector p,Vector q){
		return Vector(p.x-q.x,p.y-q.y);
	}
	friend bool operator < (Vector p,Vector q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
};
typedef Vector point;
inline double dot(Vector p,Vector q){
	return p.x*q.x+p.y*q.y;
}
inline double dist(point p,point q){
	return sqrt(dot(p-q,p-q));
}
inline double cross(Vector p,Vector q){
	return p.x*q.y-p.y*q.x;
}


int n,m,q;
double xx,yy;
double ans=0;
set<point>S;

void add(point x){
	set<point>::iterator nex=S.lower_bound(x);
	set<point>::iterator pre=nex;
	pre--; 
	set<point>::iterator now;
	if(cross(*nex-*pre,x-*pre)<0) return;
	ans-=dist(*pre,*nex);
	while(1){
		now=nex;
		nex++;
		if(nex==S.end()) break;
		if(cross(x-*now,x-*nex)<0) break;
		ans-=dist(*now,*nex);
		S.erase(*now);
	}
	while(1){
		now=pre;
		if(pre==S.begin()) break;
		pre--;
		if(cross(x-*pre,x-*now)<0) break;
		ans-=dist(*now,*pre);
		S.erase(*now);
	}
	S.insert(x);
	pre=nex=S.lower_bound(x);
	pre--;
	nex++;
	ans+=dist(x,*pre)+dist(x,*nex);
}


struct oper_type{
	int op;
	int pos;	
}oper[maxq+5];
point city[maxn+5];
int mark[maxn+5];
double res[maxq+5];


int cnt;
point O;
point a[maxn+5];
int top=0;
point s[maxn+5];
int cmp(point x,point y){
	double ang=cross(a[1]-x,a[1]-y);
	if(fabs(ang)<eps) return dist(a[1],x)<dist(a[1],y);
	else return ang>eps; 
} 

void ini_convex_hull(){
	cnt=0;
	a[++cnt]=point(0,0);
	a[++cnt]=point(n,0);
	a[++cnt]=point(xx,yy);
	for(int i=1;i<=m;i++){
		if(!mark[i]) a[++cnt]=city[i];
	}
	sort(a+2,a+1+cnt,cmp);
	top=0;
	for(int i=1;i<=cnt;i++){
		while(top>1&&cross(s[top-1]-s[top],s[top-1]-a[i])<=-eps) top--;
		s[++top]=a[i];
	}
	for(int i=1;i<top;i++){
		 ans+=dist(s[i],s[i+1]);
		 S.insert(s[i]);
	} 
	ans+=dist(s[top],s[1]);
	S.insert(s[top]);
	ans-=n;
}

int main(){
//#ifdef LOCAL
//	freopen("10.in","r",stdin);
//	freopen("10.ans","w",stdout);
//#endif
	int qcnt=0;
	scanf("%d %lf %lf",&n,&xx,&yy);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%lf %lf",&city[i].x,&city[i].y);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&oper[i].op);
		if(oper[i].op==1){
			 scanf("%d",&oper[i].pos);
			 mark[oper[i].pos]=1;
		}else{
			oper[i].pos=++qcnt;
		}
	}
		
	ini_convex_hull();
		
	for(int i=q;i>=1;i--){
		if(oper[i].op==2){
			res[oper[i].pos]=ans;
		}else{
			add(city[oper[i].pos]);
		}
	}

	for(int i=1;i<=qcnt;i++) printf("%.2f\n",res[i]);
}

