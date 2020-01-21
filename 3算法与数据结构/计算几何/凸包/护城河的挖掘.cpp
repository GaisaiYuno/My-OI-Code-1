//http://119.29.55.79/contest/76/problem/1#submit_code 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-5
#define maxn 5000
using namespace std;
int n;
struct vector{
	double x;
	double y;
	vector(){
		
	}
	vector(double _x,double _y){
		x=_x;
		y=_y;
	}
	friend vector operator + (vector p,vector q){
		return vector(p.x+q.x,p.y+q.y);
	}
	friend vector operator - (vector p,vector q){
		return vector(p.x-q.x,p.y-q.y);
	}
	friend bool operator < (vector p,vector q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
};
typedef vector point;
inline double dot(vector p,vector q){
	return p.x*q.x+p.y*q.y;
}
inline double dist(point p,point q){
	return sqrt(dot(p-q,p-q));
}
inline double cross(vector p,vector q){
	return p.x*q.y-p.y*q.x;
}

point O;
int cmp(point P,point Q){
	double ang=cross(P-O,Q-O);
	if(fabs(ang)<eps) return dist(O,P)<dist(O,Q);
	else return ang>eps; 
} 

int top=0;
point a[maxn+5];
point s[maxn+5];
void Graham(){
    for(int i=1;i<=n;i++){
        if(a[i].x<a[1].x||(a[i].x==a[1].x&&a[i].y<=a[1].y)) swap(a[i],a[1]);
    }
    O=a[1];
    sort(a+2,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        while(top>1&&cross(s[top]-s[top-1],a[i]-s[top-1])<=eps) top--;//在逆时针方向，叉积<0 
        s[++top]=a[i];
    }
//#ifdef DEBUG
//	for(int i=1;i<=top;i++){
//		printf("(%.5f,%.5f)\n",s[i].x,s[i].y);
//	}
//#endif
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	Graham();
	double ans=0;
	for(int i=1;i<top;i++){
//		printf("(%.2f %.2f)\n",s[i].x,s[i].y);
		ans+=dist(s[i],s[i+1]);
	}
	ans+=dist(s[top],s[1]);
	printf("%.2f\n",ans);
}
