//https://codeforces.com/problemset/problem/1142/C 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<algorithm>
#define maxn 100000
#define eps 1e-6
using namespace std;
//y=x^2+bx+c
//=> y-x^2=bx+c
//把(x,y)变成(x,y-x^2) 
//那么一条抛物线变成了一条直线 
//然后就变成在新的点集里有多少条直线，满足不在直线上的其他点都在它的下方
//这是上凸壳的定义 
int n;
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
 

point a[maxn+5];
int cmp(point x,point y){
	double ang=cross(a[1]-x,a[1]-y);
	if(fabs(ang)<eps) return dist(a[1],x)<dist(a[1],y);
	else return ang<eps; 
} 

int top;
point s[maxn+5];
int main(){
	double x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x,&y);
		a[i].x=x;
		a[i].y=y;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[1]) swap(a[i],a[1]);
	}
	sort(a+2,a+1+n,cmp);
	top=0;
	for(int i=1;i<=n;i++){
		while(top>1&&cross(s[top-1]-s[top],s[top-1]-a[i])>=-eps) top--;
		s[++top]=a[i];
	}
	int ans=0;
	for(int i=1;i<=top;i++){
		int nex=i%top+1;//i+1; 
		if(s[i].x<s[nex].x) ans++;
	} 
	printf("%d\n",ans);

}
