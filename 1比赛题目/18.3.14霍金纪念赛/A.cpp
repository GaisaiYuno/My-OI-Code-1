#include<iostream>
#include<cmath>
#include<cstdio>
#define maxn 1005
using namespace std;
struct point{
	double x;
	double y;
	point(){
		x=0;
		y=0;
	}
	point(double xx,double yy){
		x=xx;
		y=yy;
	}
	typedef point vector;
	friend vector operator + (vector a,vector b){
		return vector(a.x+b.x,a.y+b.y);
	}
	friend vector operator - (vector a,vector b){
		return vector(a.x+b.x,a.y+b.y);
	}
	friend vector operator * (vector a,double p){
		return vector(a.x*p,a.y*p);
	}
	friend vector operator / (vector a,double p){
		return vector(a.x/p,a.y/p);
	}
	friend bool operator <(point a,point b){
		return a.x<b.x||(a.x==b.x&&a.y<b.y);
	}
	double len(){
		return sqrt(x*x+y*y);
	}
};
typedef point vector;
double dot(vector a,vector b){//µã»ý 
	return a.x*b.x+a.y*b.y;
}
double cross(vector a,vector b){//²æ»ý 
	return a.x*b.y-a.y*b.x;
}
double get_area(point *p,int n){
	double area=0;
	for(int i=2;i<=n-1;i++){
		area+=cross(p[i]-p[1],p[i+1]-p[1]);
	}
	return area/2;
} 
int n;
point a[maxn];
int main(){
	int cas=0;
	while(cin>>n&&n!=0){
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
		double s=get_area(a,n);
		printf("Figure %d: ",++cas);
		if(s==0) printf("Impossible\n");
		else printf("%.2f\n",abs(s));
	}
} 
