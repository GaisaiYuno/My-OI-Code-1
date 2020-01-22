#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define eps 1e-6
using namespace std;
int n;
double d;
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
};
typedef Vector point;
double cross(Vector p,Vector q){
	return p.x*q.y-p.y*q.x;
}
double slope(point p,point q){
	return (p.y-q.y)/(p.x-q.x);
}

double a[maxn+5],x[maxn+5]; 
double suma[maxn+5];
point s[maxn+5];

int bin_search(int l,int r,point k){
	int ans=1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(cross(s[mid+1]-s[mid],k-s[mid])<=eps){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	scanf("%d %lf",&n,&d);
	for(int i=1;i<=n;i++){
		 scanf("%lf %lf",&a[i],&x[i]);
		 suma[i]=suma[i-1]+a[i];
	}
	int top=0;
	double ans=0;
	s[++top]=point(d,0); //((0+1)*d,suma[0]) 
	for(int i=1;i<=n;i++){
		int best=bin_search(1,top,point(x[i]+i*d,suma[i]));//找到斜率最大的点
		double val=slope(point(x[i]+i*d,suma[i]),s[best]); 
		ans+=val;
		point newp=point((i+1)*d,suma[i]);//插入新的可行点
		while(top>1&&cross(s[top]-s[top-1],newp-s[top-1])<=eps) top--;
		s[++top]=newp;
	}
	printf("%.0f\n",ans);
}

