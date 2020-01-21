//http://119.29.55.79/contest/76/problem/5 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<algorithm>
#define maxn 50000
#define eps 1e-6
using namespace std;

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
inline double dist2(point p,point q){
    return dot(p-q,p-q);
}
inline double cross(Vector p,Vector q){
    return p.x*q.y-p.y*q.x;
}


point a[maxn+5];
int cmp(point x,point y){
    double ang=cross(x-a[1],y-a[1]);
    if(fabs(ang)<eps) return dist(a[1],x)<dist(a[1],y);
    else return ang<eps; 
} 

int top;
point s[maxn+5];

inline int nex(int x){
	return x%n+1;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++){
        if(a[i]<a[1]) swap(a[i],a[1]);
    }
    sort(a+2,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        while(top>1&&cross(s[top]-s[top-1],a[i]-s[top-1])>=-eps) top--;//一定要>=0 
        s[++top]=a[i];
    }
    s[top+1]=s[top];
    double ans=0;
    for(int i=1;i<=top;i++){
    	int p=nex(i),q=nex(nex(p));
    	for(int j=nex(nex(i));j<=top;j++){
    		while(nex(p)!=j&&fabs(cross(s[j]-s[i],s[p+1]-s[i]))>fabs(cross(s[j]-s[i],s[p]-s[i]))) p=nex(p);
    		while(nex(q)!=i&&fabs(cross(s[q+1]-s[i],s[j]-s[i]))>fabs(cross(s[q]-s[i],s[j]-s[i]))) q=nex(q);
    		//交换顺序是因为p,q在直线i->j两侧，让差积符号为正 
    		//其实可以不用fabs 
    		ans=max(ans,fabs(cross(s[j]-s[i],s[p]-s[i]))+fabs(cross(s[q]-s[i],s[j]-s[i])));
		}
	}
	printf("%.3f\n",ans/2);
} 
