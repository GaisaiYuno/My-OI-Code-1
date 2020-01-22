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
double cross(Vector p,Vector q){
	return p.x*q.y-p.y*q.x;
}
double dot(Vector p,Vector q){
	return p.x*q.x+p.y*q.y;
}
double dist(point P,point Q){
	return sqrt(dot(P-Q,P-Q));
}
double area(point A,point B,point C){
	return fabs(cross(B-A,C-A));
}

int n;
point a[4]; 
double ans=0;
set<point>S;
void add(point x){
//#ifdef DEBUG
//	for(point p : S){
//		printf("%.1f %.1f\n",p.x,p.y);	
//	}
//#endif
	set<point>::iterator r=S.lower_bound(x);
	set<point>::iterator l=r;
	set<point>::iterator t;
	point pre=*l,nex=*r;
	if(r!=S.begin()) pre=*(l--);
	if(r!=S.end()&&cross(*l-x,*r-x)<=-eps) return;
	if(r!=S.end()){
		while(1){
			t=r;
			r++;
			if(r==S.end()) break;
			if(cross(*r-x,*t-x)<=-eps) break;
			ans-=area(pre,*t,*r);//不是pre,应该是原点 
			S.erase(t);
		}
	} 
	if(r!=S.begin()){ 
//		l--;
		while(l!=S.begin()){
			t=l;
			l--;
			if(cross(*l-x,*t-x)>=-eps) break;
			ans-=area(*l,*t,nex);
			S.erase(t);
		}
	} 
	S.insert(x);
	l=r=S.lower_bound(x);
	l--;
	r++;
	ans+=area(*l,x,*r);
}
//int cmp(point P,point Q){
//	double ang=cross(P-a[1],Q-a[1]);
//	if(fabs(ang)<eps) return dist(P,a[1])<dist(Q,a[1]);
//	else return ang>0;
//}
//
//point s[maxn+5];
//void Graham(){
//	for(int i=1;i<=cnt;i++){
//		if(a[i]<a[1]) swap(a[i],a[1]);
//	}
//	sort(a+2,a+1+cnt,cmp);
//	top=0;
//	for(int i=1;i<=cnt;i++){
//		while(top>1&&cross(s[top]-s[top-1],a[i]-s[top-1])<=eps) top--;
//		s[++top]=a[i];
//	}
//	cnt=top;
//	for(int i=1;i<=top;i++) a[i]=s[i];
//}

int main(){
	int x,y;
	for(int i=1;i<=3;i++){
		qread(x);
		qread(y);
		a[i]=point(x,y); 
		S.insert(a[i]);
	} 
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
