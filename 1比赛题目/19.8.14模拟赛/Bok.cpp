#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define eps 1e-6
#define maxn 100000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign; 
}
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
struct Vector{
	long long x;
	long long y;
	Vector(){
		
	}
	Vector(long long _x,long long _y){
		x=_x;
		y=_y;
	}
	friend Vector operator + (Vector p,Vector q){
		return Vector(p.x+q.x,p.y+q.y);
	}
	friend Vector operator - (Vector p,Vector q){
		return Vector(p.x-q.x,p.y-q.y);
	}
};
typedef Vector point;
long long cross(Vector p,Vector q){
	return p.x*q.y-p.y*q.x;
}
long long dot(Vector p,Vector q){
	return p.x*q.x+p.y*q.y;
}
long long dist2(point P,point Q){
	return dot(P-Q,P-Q);
}
long long area(point A,point B,point C){
	return abs(cross(B-A,C-A));
}

int n;
point a[4]; 
long long ans=0;
set<point>S;
point O; 
bool operator < (point P,point Q){
	long long ang=cross(P-O,Q-O);
	if(abs(ang)<=eps) return dist2(O,P)<dist2(O,Q);
	else return ang>=eps;
}
inline point pre(point x){
	if(S.count(x)) return x;
	set<point>::iterator it=S.lower_bound(x);
	if(it==S.begin()) it=S.end();
	return *(--it);
}
inline point nex(point x){
	set<point>::iterator it=S.upper_bound(x);
	if(it==S.end()) return *S.begin();
	else return *it;	
}
void add(point x){
	if(S.size()<=2){
		S.insert(x);
		return;
	}
	point l=pre(x),r=nex(x);
	if(cross(r-l,x-l)>=-eps) return;
	ans+=area(l,r,x);
	while(1){
		point t=pre(x);
		S.erase(t);
		l=pre(x);
		if(cross(x-l,t-l)<=eps){
			S.insert(t);
			break;
		}
		ans+=area(x,l,t);
	}
	while(1){
		point t=nex(x);
		S.erase(t);
		r=nex(x);
		if(cross(x-r,t-r)>=eps){
			S.insert(t);
			break;
		}
		ans+=area(x,r,t);
	}
	S.insert(x);
}

int main(){
	int x,y;
	for(int i=1;i<=3;i++){
		qread(x);
		qread(y);
		a[i]=point(x,y); 
		if(a[i].x<a[1].x||(a[i].x==a[1].x&&a[i].y<=a[1].y)) swap(a[i],a[1]);
	} 
	O=a[1];
	for(int i=1;i<=3;i++) add(a[i]);
	ans=area(a[1],a[2],a[3]); 
	qread(n);
	for(int i=1;i<=n;i++){
		qread(x);
		qread(y);
		add(point(x,y));
		qprint((long long)ans);
		putchar('\n');
	}
}
