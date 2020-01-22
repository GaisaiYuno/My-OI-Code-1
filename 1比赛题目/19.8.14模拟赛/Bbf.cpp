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
int cnt;
int top;
point a[maxn+5];
int cmp(point P,point Q){
	double ang=cross(P-a[1],Q-a[1]);
	if(fabs(ang)<eps) return dist(P,a[1])<dist(Q,a[1]);
	else return ang>0;
}

point s[maxn+5];
void Graham(){
	for(int i=1;i<=cnt;i++){
		if(a[i]<a[1]) swap(a[i],a[1]);
	}
	sort(a+2,a+1+cnt,cmp);
	top=0;
	for(int i=1;i<=cnt;i++){
		while(top>1&&cross(s[top]-s[top-1],a[i]-s[top-1])<=eps) top--;
		s[++top]=a[i];
	}
	cnt=top;
	for(int i=1;i<=top;i++) a[i]=s[i];
}
long long calc(){
	double ans=0;
	for(int i=2;i+1<=cnt;i++){
		ans+=area(a[1],a[i],a[i+1]);
	}
	return (long long)ans;
}

long long last;
int main(){
	int x,y;
	cnt=3;
	for(int i=1;i<=3;i++){
		qread(x);
		qread(y);
		a[i].x=x;
		a[i].y=y;
	} 
	qread(n);
	last=calc();
	int bsz=sqrt(n);
	for(int i=1;i<=n;i++){
		qread(x);
		qread(y);
		cnt++;
		a[cnt].x=x;
		a[cnt].y=y;
		Graham();
		last=calc();
		qprint(last);
		putchar('\n');
	}
}
