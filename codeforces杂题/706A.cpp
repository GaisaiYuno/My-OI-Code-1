#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1005
#define INF 999999999
using namespace std;
struct point{
	double x;
	double y; 
	double v;
}car[maxn];
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n;
int main(){
	point peo;
	scanf("%lf %lf",&peo.x,&peo.y);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf %lf %lf",&car[i].x,&car[i].y,&car[i].v);
	double dis=INF;
	for(int i=1;i<=n;i++){
		double l=dist(car[i],peo)/car[i].v;
		dis=min(dis,l);
	}
	printf("%lf\n",dis);
}
