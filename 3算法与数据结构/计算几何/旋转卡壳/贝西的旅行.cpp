//http://119.29.55.79/contest/76/problem/4
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
    double ang=cross(a[1]-x,a[1]-y);
    if(fabs(ang)<eps) return dist(a[1],x)<dist(a[1],y);
    else return ang>eps; 
} 

int top;
point s[maxn+5];

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
        while(top>1&&cross(s[top-1]-s[top],s[top-1]-a[i])<=eps) top--;//Ò»¶¨Òª>=0 
        s[++top]=a[i];
    }
    double ans=0;
    s[top+1]=s[1];
    int now=2;
    for(int i=1;i<=top;i++){
        while(fabs(cross(s[i+1]-s[i],s[now]-s[i]))<fabs(cross(s[i+1]-s[i],s[now+1]-s[i]))){
            now++;
            if(now==top+1) now=1;
        }
        ans=max(ans,dist2(s[now],s[i]));
    }
    printf("%.0f",ans);
}
